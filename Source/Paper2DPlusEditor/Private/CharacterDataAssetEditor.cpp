#include "CharacterDataAssetEditor.h"
#include "CharacterDataJsonImporter.h"
#include "DimensionManagementPanel.h"
#include "SpriteExtractorWindow.h"
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Layout/SExpandableArea.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Docking/SDockTab.h"
#include "PaperFlipbook.h"
#include "PaperSprite.h"
#include "Engine/Texture2D.h"
#include "PropertyCustomizationHelpers.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "ScopedTransaction.h"
#include "Framework/Commands/UICommandList.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "DesktopPlatformModule.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "UnrealClient.h"
#include "SceneView.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "Engine/Engine.h"

#define LOCTEXT_NAMESPACE "CharacterDataAssetEditor"

// ==========================================
// SCharacterDataEditorCanvas Implementation
// ==========================================

void SCharacterDataEditorCanvas::Construct(const FArguments& InArgs)
{
	Asset = InArgs._Asset;
	SelectedAnimationIndex = InArgs._SelectedAnimationIndex;
	SelectedFrameIndex = InArgs._SelectedFrameIndex;
	CurrentTool = InArgs._CurrentTool;
	ShowGrid = InArgs._ShowGrid;
	Zoom = InArgs._Zoom;
}

FVector2D SCharacterDataEditorCanvas::ComputeDesiredSize(float) const
{
	return FVector2D(600, 500);
}

FVector2D SCharacterDataEditorCanvas::GetSpriteDimensions() const
{
	UPaperSprite* Sprite = nullptr;
	FVector2D Dimensions(128.0f, 128.0f);
	GetCurrentSpriteInfo(Sprite, Dimensions);
	return Dimensions;
}

FVector2D SCharacterDataEditorCanvas::GetCanvasOffset(const FGeometry& Geom) const
{
	FVector2D SpriteDims = GetSpriteDimensions();
	FVector2D WidgetSize = Geom.GetLocalSize();
	float EffectiveZoom = GetEffectiveZoom(Geom);

	return FVector2D(
		(WidgetSize.X - SpriteDims.X * EffectiveZoom) * 0.5f,
		(WidgetSize.Y - SpriteDims.Y * EffectiveZoom) * 0.5f
	);
}

float SCharacterDataEditorCanvas::GetEffectiveZoom(const FGeometry& Geom) const
{
	FVector2D SpriteDims = GetSpriteDimensions();
	FVector2D WidgetSize = Geom.GetLocalSize();

	float BaseScale = FMath::Min(
		WidgetSize.X / SpriteDims.X,
		WidgetSize.Y / SpriteDims.Y
	) * 0.9f;

	return BaseScale * Zoom.Get();
}

FVector2D SCharacterDataEditorCanvas::ScreenToCanvas(const FGeometry& Geom, const FVector2D& ScreenPos) const
{
	FVector2D LocalPos = Geom.AbsoluteToLocal(ScreenPos);
	FVector2D Offset = GetCanvasOffset(Geom);
	float EffectiveZoom = GetEffectiveZoom(Geom);

	return (LocalPos - Offset) / EffectiveZoom;
}

FVector2D SCharacterDataEditorCanvas::CanvasToScreen(const FGeometry& Geom, const FVector2D& CanvasPos) const
{
	FVector2D Offset = GetCanvasOffset(Geom);
	float EffectiveZoom = GetEffectiveZoom(Geom);

	return Offset + CanvasPos * EffectiveZoom;
}

int32 SCharacterDataEditorCanvas::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const FVector2D LocalSize = AllottedGeometry.GetLocalSize();
	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId,
		AllottedGeometry.ToPaintGeometry(FVector2f(LocalSize), FSlateLayoutTransform()),
		FAppStyle::GetBrush("WhiteBrush"),
		ESlateDrawEffect::None,
		FLinearColor(0.08f, 0.08f, 0.08f, 1.0f)
	);

	if (ShowGrid.Get())
	{
		DrawGrid(AllottedGeometry, OutDrawElements, LayerId + 1);
	}

	const FFrameHitboxData* Frame = GetCurrentFrame();

	UPaperSprite* Sprite = nullptr;
	FVector2D SpriteDimensions(128.0f, 128.0f);
	bool bHasSprite = GetCurrentSpriteInfo(Sprite, SpriteDimensions);

	float EffectiveZoom = GetEffectiveZoom(AllottedGeometry);
	FVector2D Offset = GetCanvasOffset(AllottedGeometry);

	if (bHasSprite && Sprite)
	{
		UTexture2D* SpriteTexture = Sprite->GetBakedTexture();
		if (!SpriteTexture)
		{
			SpriteTexture = Cast<UTexture2D>(Sprite->GetSourceTexture());
		}

		if (SpriteTexture)
		{
			FSlateBrush SpriteBrush;
			SpriteBrush.SetResourceObject(SpriteTexture);
			SpriteBrush.ImageSize = FVector2D(SpriteTexture->GetSizeX(), SpriteTexture->GetSizeY());
			SpriteBrush.DrawAs = ESlateBrushDrawType::Image;
			SpriteBrush.Tiling = ESlateBrushTileType::NoTile;

			// Set UV region to display only this sprite's portion of the texture
			FVector2D SourceUV = Sprite->GetSourceUV();
			FVector2D SourceSize = Sprite->GetSourceSize();
			FVector2D TextureSize(SpriteTexture->GetSizeX(), SpriteTexture->GetSizeY());
			if (TextureSize.X > 0 && TextureSize.Y > 0)
			{
				FBox2D UVRegion(
					FVector2D(SourceUV.X / TextureSize.X, SourceUV.Y / TextureSize.Y),
					FVector2D((SourceUV.X + SourceSize.X) / TextureSize.X, (SourceUV.Y + SourceSize.Y) / TextureSize.Y)
				);
				SpriteBrush.SetUVRegion(UVRegion);
			}

			FVector2D SpriteDrawSize = SpriteDimensions * EffectiveZoom;

			FSlateDrawElement::MakeBox(
				OutDrawElements,
				LayerId + 2,
				AllottedGeometry.ToPaintGeometry(FVector2f(SpriteDrawSize), FSlateLayoutTransform(FVector2f(Offset))),
				&SpriteBrush,
				ESlateDrawEffect::None,
				FLinearColor::White
			);
		}
	}

	{
		FVector2D BoundarySize = SpriteDimensions * EffectiveZoom;
		FSlateDrawElement::MakeBox(
			OutDrawElements,
			LayerId + 3,
			AllottedGeometry.ToPaintGeometry(FVector2f(BoundarySize), FSlateLayoutTransform(FVector2f(Offset))),
			FAppStyle::GetBrush("Border"),
			ESlateDrawEffect::None,
			bHasSprite ? FLinearColor(0.3f, 0.3f, 0.3f, 0.5f) : FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)
		);
	}

	if (Frame)
	{
		for (int32 i = 0; i < Frame->Hitboxes.Num(); i++)
		{
			bool bSelected = (SelectionType == EHitboxSelectionType::Hitbox && SelectedIndex == i);
			DrawHitbox(AllottedGeometry, OutDrawElements, LayerId + 4, Frame->Hitboxes[i], bSelected);
		}

		if (SelectionType == EHitboxSelectionType::Hitbox &&
			Frame->Hitboxes.IsValidIndex(SelectedIndex) &&
			CurrentTool.Get() == EHitboxEditorTool::Edit)
		{
			DrawResizeHandles(AllottedGeometry, OutDrawElements, LayerId + 6, Frame->Hitboxes[SelectedIndex]);
		}

		for (int32 i = 0; i < Frame->Sockets.Num(); i++)
		{
			bool bSelected = (SelectionType == EHitboxSelectionType::Socket && SelectedIndex == i);
			DrawSocket(AllottedGeometry, OutDrawElements, LayerId + 5, Frame->Sockets[i], bSelected);
		}
	}

	if (DragMode == EHitboxDragMode::Creating)
	{
		DrawCreatingRect(AllottedGeometry, OutDrawElements, LayerId + 7);
	}

	return LayerId + 8;
}

void SCharacterDataEditorCanvas::DrawGrid(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	float EffectiveZoom = GetEffectiveZoom(Geom);
	FVector2D Offset = GetCanvasOffset(Geom);
	FVector2D SpriteDims = GetSpriteDimensions();

	for (float X = 0; X <= SpriteDims.X; X += GridSize)
	{
		float ScreenX = Offset.X + X * EffectiveZoom;
		TArray<FVector2D> Line = {
			FVector2D(ScreenX, Offset.Y),
			FVector2D(ScreenX, Offset.Y + SpriteDims.Y * EffectiveZoom)
		};
		FSlateDrawElement::MakeLines(
			OutDrawElements, LayerId, Geom.ToPaintGeometry(),
			Line, ESlateDrawEffect::None,
			FLinearColor(0.2f, 0.2f, 0.2f, 0.5f), true, 1.0f
		);
	}

	for (float Y = 0; Y <= SpriteDims.Y; Y += GridSize)
	{
		float ScreenY = Offset.Y + Y * EffectiveZoom;
		TArray<FVector2D> Line = {
			FVector2D(Offset.X, ScreenY),
			FVector2D(Offset.X + SpriteDims.X * EffectiveZoom, ScreenY)
		};
		FSlateDrawElement::MakeLines(
			OutDrawElements, LayerId, Geom.ToPaintGeometry(),
			Line, ESlateDrawEffect::None,
			FLinearColor(0.2f, 0.2f, 0.2f, 0.5f), true, 1.0f
		);
	}
}

void SCharacterDataEditorCanvas::DrawHitbox(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements,
	int32 LayerId, const FHitboxData& HB, bool bSelected) const
{
	float EffectiveZoom = GetEffectiveZoom(Geom);
	FVector2D Offset = GetCanvasOffset(Geom);

	FLinearColor Color = GetHitboxColor(HB.Type);
	FVector2D Pos = Offset + FVector2D(HB.X, HB.Y) * EffectiveZoom;
	FVector2D BoxSize(HB.Width * EffectiveZoom, HB.Height * EffectiveZoom);

	float FillAlpha = bSelected ? 0.5f : 0.3f;
	FSlateDrawElement::MakeBox(
		OutDrawElements, LayerId,
		Geom.ToPaintGeometry(FVector2f(BoxSize), FSlateLayoutTransform(FVector2f(Pos))),
		FAppStyle::GetBrush("WhiteBrush"),
		ESlateDrawEffect::None,
		Color * FLinearColor(1, 1, 1, FillAlpha)
	);

	float BorderThickness = bSelected ? 3.0f : 2.0f;
	TArray<FVector2D> BorderPoints = {
		Pos,
		FVector2D(Pos.X + BoxSize.X, Pos.Y),
		Pos + BoxSize,
		FVector2D(Pos.X, Pos.Y + BoxSize.Y),
		Pos
	};
	FSlateDrawElement::MakeLines(
		OutDrawElements, LayerId + 1, Geom.ToPaintGeometry(),
		BorderPoints, ESlateDrawEffect::None,
		bSelected ? FLinearColor::White : Color, true, BorderThickness
	);
}

void SCharacterDataEditorCanvas::DrawSocket(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements,
	int32 LayerId, const FSocketData& Sock, bool bSelected) const
{
	float EffectiveZoom = GetEffectiveZoom(Geom);
	FVector2D Offset = GetCanvasOffset(Geom);

	FVector2D Pos = Offset + FVector2D(Sock.X, Sock.Y) * EffectiveZoom;
	float CrossSize = bSelected ? 12.0f : 8.0f;
	float Thickness = bSelected ? 3.0f : 2.0f;
	FLinearColor Color = bSelected ? FLinearColor::White : FLinearColor::Yellow;

	TArray<FVector2D> HLine = { FVector2D(Pos.X - CrossSize, Pos.Y), FVector2D(Pos.X + CrossSize, Pos.Y) };
	TArray<FVector2D> VLine = { FVector2D(Pos.X, Pos.Y - CrossSize), FVector2D(Pos.X, Pos.Y + CrossSize) };

	FSlateDrawElement::MakeLines(OutDrawElements, LayerId, Geom.ToPaintGeometry(),
		HLine, ESlateDrawEffect::None, Color, true, Thickness);
	FSlateDrawElement::MakeLines(OutDrawElements, LayerId, Geom.ToPaintGeometry(),
		VLine, ESlateDrawEffect::None, Color, true, Thickness);

	if (bSelected)
	{
		const int32 NumSegments = 16;
		TArray<FVector2D> Circle;
		for (int32 i = 0; i <= NumSegments; i++)
		{
			float Angle = 2.0f * PI * i / NumSegments;
			Circle.Add(Pos + FVector2D(FMath::Cos(Angle), FMath::Sin(Angle)) * CrossSize);
		}
		FSlateDrawElement::MakeLines(OutDrawElements, LayerId, Geom.ToPaintGeometry(),
			Circle, ESlateDrawEffect::None, Color, true, 1.0f);
	}
}

void SCharacterDataEditorCanvas::DrawResizeHandles(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements,
	int32 LayerId, const FHitboxData& HB) const
{
	float EffectiveZoom = GetEffectiveZoom(Geom);
	FVector2D Offset = GetCanvasOffset(Geom);

	FVector2D TopLeft = Offset + FVector2D(HB.X, HB.Y) * EffectiveZoom;
	FVector2D BottomRight = Offset + FVector2D(HB.X + HB.Width, HB.Y + HB.Height) * EffectiveZoom;
	FVector2D Center = (TopLeft + BottomRight) * 0.5f;

	TArray<FVector2D> HandlePositions = {
		TopLeft,
		FVector2D(Center.X, TopLeft.Y),
		FVector2D(BottomRight.X, TopLeft.Y),
		FVector2D(TopLeft.X, Center.Y),
		FVector2D(BottomRight.X, Center.Y),
		FVector2D(TopLeft.X, BottomRight.Y),
		FVector2D(Center.X, BottomRight.Y),
		BottomRight
	};

	for (const FVector2D& HandlePos : HandlePositions)
	{
		FVector2D HandleTopLeft = HandlePos - FVector2D(HandleSize * 0.5f, HandleSize * 0.5f);
		FSlateDrawElement::MakeBox(
			OutDrawElements, LayerId,
			Geom.ToPaintGeometry(FVector2f(HandleSize, HandleSize), FSlateLayoutTransform(FVector2f(HandleTopLeft))),
			FAppStyle::GetBrush("WhiteBrush"),
			ESlateDrawEffect::None,
			FLinearColor::White
		);
	}
}

void SCharacterDataEditorCanvas::DrawCreatingRect(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	float EffectiveZoom = GetEffectiveZoom(Geom);
	FVector2D Offset = GetCanvasOffset(Geom);

	FVector2D Pos = Offset + FVector2D(CreatingRect.Min.X, CreatingRect.Min.Y) * EffectiveZoom;
	FVector2D Size = FVector2D(CreatingRect.Width(), CreatingRect.Height()) * EffectiveZoom;

	FSlateDrawElement::MakeBox(
		OutDrawElements, LayerId,
		Geom.ToPaintGeometry(FVector2f(Size), FSlateLayoutTransform(FVector2f(Pos))),
		FAppStyle::GetBrush("WhiteBrush"),
		ESlateDrawEffect::None,
		FLinearColor(1.0f, 1.0f, 1.0f, 0.2f)
	);

	TArray<FVector2D> BorderPoints = {
		Pos,
		FVector2D(Pos.X + Size.X, Pos.Y),
		Pos + Size,
		FVector2D(Pos.X, Pos.Y + Size.Y),
		Pos
	};
	FSlateDrawElement::MakeLines(
		OutDrawElements, LayerId + 1, Geom.ToPaintGeometry(),
		BorderPoints, ESlateDrawEffect::None,
		FLinearColor::White, true, 2.0f
	);
}

FLinearColor SCharacterDataEditorCanvas::GetHitboxColor(EHitboxType Type) const
{
	switch (Type)
	{
		case EHitboxType::Attack: return FLinearColor::Red;
		case EHitboxType::Hurtbox: return FLinearColor::Green;
		case EHitboxType::Collision: return FLinearColor::Blue;
		default: return FLinearColor::White;
	}
}

const FFrameHitboxData* SCharacterDataEditorCanvas::GetCurrentFrame() const
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim) return nullptr;

	int32 FrameIndex = SelectedFrameIndex.Get();
	if (!Anim->Frames.IsValidIndex(FrameIndex)) return nullptr;

	return &Anim->Frames[FrameIndex];
}

FFrameHitboxData* SCharacterDataEditorCanvas::GetCurrentFrameMutable() const
{
	if (!Asset.IsValid()) return nullptr;

	int32 AnimIndex = SelectedAnimationIndex.Get();
	if (!Asset->Animations.IsValidIndex(AnimIndex)) return nullptr;

	int32 FrameIndex = SelectedFrameIndex.Get();
	if (!Asset->Animations[AnimIndex].Frames.IsValidIndex(FrameIndex)) return nullptr;

	return &Asset->Animations[AnimIndex].Frames[FrameIndex];
}

const FAnimationHitboxData* SCharacterDataEditorCanvas::GetCurrentAnimation() const
{
	if (!Asset.IsValid()) return nullptr;

	int32 AnimIndex = SelectedAnimationIndex.Get();
	if (!Asset->Animations.IsValidIndex(AnimIndex)) return nullptr;

	return &Asset->Animations[AnimIndex];
}

bool SCharacterDataEditorCanvas::GetCurrentSpriteInfo(UPaperSprite*& OutSprite, FVector2D& OutDimensions) const
{
	OutSprite = nullptr;
	OutDimensions = FVector2D(128.0f, 128.0f);

	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim) return false;

	if (Anim->Flipbook.IsNull()) return false;

	UPaperFlipbook* Flipbook = Anim->Flipbook.LoadSynchronous();
	if (!Flipbook) return false;

	int32 FrameIndex = SelectedFrameIndex.Get();
	int32 NumKeyFrames = Flipbook->GetNumKeyFrames();

	if (NumKeyFrames == 0) return false;

	FrameIndex = FMath::Clamp(FrameIndex, 0, NumKeyFrames - 1);

	const FPaperFlipbookKeyFrame& KeyFrame = Flipbook->GetKeyFrameChecked(FrameIndex);
	OutSprite = KeyFrame.Sprite;
	if (!OutSprite) return false;

	OutDimensions = OutSprite->GetSourceSize();

	if (OutDimensions.X <= 0 || OutDimensions.Y <= 0)
	{
		UTexture2D* Texture = Cast<UTexture2D>(OutSprite->GetSourceTexture());
		if (Texture)
		{
			OutDimensions = FVector2D(Texture->GetSizeX(), Texture->GetSizeY());
		}
	}

	return OutDimensions.X > 0 && OutDimensions.Y > 0;
}

int32 SCharacterDataEditorCanvas::HitTestHitbox(const FVector2D& CanvasPos) const
{
	const FFrameHitboxData* Frame = GetCurrentFrame();
	if (!Frame) return -1;

	for (int32 i = Frame->Hitboxes.Num() - 1; i >= 0; i--)
	{
		const FHitboxData& HB = Frame->Hitboxes[i];
		if (CanvasPos.X >= HB.X && CanvasPos.X <= HB.X + HB.Width &&
			CanvasPos.Y >= HB.Y && CanvasPos.Y <= HB.Y + HB.Height)
		{
			return i;
		}
	}
	return -1;
}

int32 SCharacterDataEditorCanvas::HitTestSocket(const FVector2D& CanvasPos) const
{
	const FFrameHitboxData* Frame = GetCurrentFrame();
	if (!Frame) return -1;

	for (int32 i = Frame->Sockets.Num() - 1; i >= 0; i--)
	{
		const FSocketData& Sock = Frame->Sockets[i];
		float Dist = FVector2D::Distance(CanvasPos, FVector2D(Sock.X, Sock.Y));
		if (Dist <= SocketHitRadius)
		{
			return i;
		}
	}
	return -1;
}

EResizeHandle SCharacterDataEditorCanvas::HitTestHandle(const FVector2D& CanvasPos, const FHitboxData& Hitbox) const
{
	float HitSize = HandleSize / GetEffectiveZoom(GetCachedGeometry()) * 1.5f;

	FVector2D TopLeft(Hitbox.X, Hitbox.Y);
	FVector2D BottomRight(Hitbox.X + Hitbox.Width, Hitbox.Y + Hitbox.Height);
	FVector2D Center = (TopLeft + BottomRight) * 0.5f;

	auto TestHandle = [&](const FVector2D& HandlePos) -> bool
	{
		return FMath::Abs(CanvasPos.X - HandlePos.X) <= HitSize &&
			   FMath::Abs(CanvasPos.Y - HandlePos.Y) <= HitSize;
	};

	if (TestHandle(TopLeft)) return EResizeHandle::TopLeft;
	if (TestHandle(FVector2D(Center.X, TopLeft.Y))) return EResizeHandle::Top;
	if (TestHandle(FVector2D(BottomRight.X, TopLeft.Y))) return EResizeHandle::TopRight;
	if (TestHandle(FVector2D(TopLeft.X, Center.Y))) return EResizeHandle::Left;
	if (TestHandle(FVector2D(BottomRight.X, Center.Y))) return EResizeHandle::Right;
	if (TestHandle(FVector2D(TopLeft.X, BottomRight.Y))) return EResizeHandle::BottomLeft;
	if (TestHandle(FVector2D(Center.X, BottomRight.Y))) return EResizeHandle::Bottom;
	if (TestHandle(BottomRight)) return EResizeHandle::BottomRight;

	return EResizeHandle::None;
}

int32 SCharacterDataEditorCanvas::SnapToGrid(int32 Value) const
{
	if (!ShowGrid.Get()) return Value;
	return FMath::RoundToInt((float)Value / GridSize) * GridSize;
}

FReply SCharacterDataEditorCanvas::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		FVector2D CanvasPos = ScreenToCanvas(MyGeometry, MouseEvent.GetScreenSpacePosition());
		EHitboxEditorTool Tool = CurrentTool.Get();

		if (Tool == EHitboxEditorTool::Draw)
		{
			int32 SnappedX = SnapToGrid(FMath::RoundToInt(CanvasPos.X));
			int32 SnappedY = SnapToGrid(FMath::RoundToInt(CanvasPos.Y));

			CreatingRect = FIntRect(SnappedX, SnappedY, SnappedX, SnappedY);
			DragMode = EHitboxDragMode::Creating;
			DragStart = CanvasPos;

			return FReply::Handled().CaptureMouse(SharedThis(const_cast<SCharacterDataEditorCanvas*>(this)));
		}
		else if (Tool == EHitboxEditorTool::Edit)
		{
			if (SelectionType == EHitboxSelectionType::Hitbox)
			{
				const FFrameHitboxData* Frame = GetCurrentFrame();
				if (Frame && Frame->Hitboxes.IsValidIndex(SelectedIndex))
				{
					EResizeHandle Handle = HitTestHandle(CanvasPos, Frame->Hitboxes[SelectedIndex]);
					if (Handle != EResizeHandle::None)
					{
						ActiveHandle = Handle;
						DragMode = EHitboxDragMode::Resizing;
						DragStart = CanvasPos;
						OnRequestUndo.ExecuteIfBound();
						return FReply::Handled().CaptureMouse(SharedThis(const_cast<SCharacterDataEditorCanvas*>(this)));
					}
				}
			}

			int32 HitHitbox = HitTestHitbox(CanvasPos);
			if (HitHitbox >= 0)
			{
				SetSelection(EHitboxSelectionType::Hitbox, HitHitbox);
				DragMode = EHitboxDragMode::Moving;
				DragStart = CanvasPos;
				OnRequestUndo.ExecuteIfBound();
				return FReply::Handled().CaptureMouse(SharedThis(const_cast<SCharacterDataEditorCanvas*>(this)));
			}

			int32 HitSocket = HitTestSocket(CanvasPos);
			if (HitSocket >= 0)
			{
				SetSelection(EHitboxSelectionType::Socket, HitSocket);
				DragMode = EHitboxDragMode::Moving;
				DragStart = CanvasPos;
				OnRequestUndo.ExecuteIfBound();
				return FReply::Handled().CaptureMouse(SharedThis(const_cast<SCharacterDataEditorCanvas*>(this)));
			}

			ClearSelection();
		}
		else if (Tool == EHitboxEditorTool::Socket)
		{
			FFrameHitboxData* Frame = GetCurrentFrameMutable();
			if (Frame)
			{
				OnRequestUndo.ExecuteIfBound();

				FSocketData NewSocket;
				NewSocket.Name = FString::Printf(TEXT("Socket%d"), Frame->Sockets.Num());
				NewSocket.X = SnapToGrid(FMath::RoundToInt(CanvasPos.X));
				NewSocket.Y = SnapToGrid(FMath::RoundToInt(CanvasPos.Y));

				int32 NewIndex = Frame->Sockets.Add(NewSocket);
				SetSelection(EHitboxSelectionType::Socket, NewIndex);
				OnHitboxDataModified.ExecuteIfBound();

				DragMode = EHitboxDragMode::Moving;
				DragStart = CanvasPos;
				return FReply::Handled().CaptureMouse(SharedThis(const_cast<SCharacterDataEditorCanvas*>(this)));
			}
		}

		return FReply::Handled().SetUserFocus(SharedThis(const_cast<SCharacterDataEditorCanvas*>(this)), EFocusCause::Mouse);
	}

	return FReply::Unhandled();
}

FReply SCharacterDataEditorCanvas::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && HasMouseCapture())
	{
		if (DragMode == EHitboxDragMode::Creating)
		{
			if (CreatingRect.Width() > 0 && CreatingRect.Height() > 0)
			{
				FFrameHitboxData* Frame = GetCurrentFrameMutable();
				if (Frame)
				{
					OnRequestUndo.ExecuteIfBound();

					FHitboxData NewHitbox;
					NewHitbox.Type = EHitboxType::Hurtbox;
					NewHitbox.X = CreatingRect.Min.X;
					NewHitbox.Y = CreatingRect.Min.Y;
					NewHitbox.Width = CreatingRect.Width();
					NewHitbox.Height = CreatingRect.Height();
					NewHitbox.Damage = 0;
					NewHitbox.Knockback = 0;

					int32 NewIndex = Frame->Hitboxes.Add(NewHitbox);
					SetSelection(EHitboxSelectionType::Hitbox, NewIndex);
					OnHitboxDataModified.ExecuteIfBound();
					OnEndTransaction.ExecuteIfBound();
				}
			}
			CreatingRect = FIntRect();
		}
		else if (DragMode == EHitboxDragMode::Moving || DragMode == EHitboxDragMode::Resizing)
		{
			OnEndTransaction.ExecuteIfBound();
		}

		DragMode = EHitboxDragMode::None;
		ActiveHandle = EResizeHandle::None;

		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

FReply SCharacterDataEditorCanvas::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!HasMouseCapture())
	{
		return FReply::Unhandled();
	}

	FVector2D CanvasPos = ScreenToCanvas(MyGeometry, MouseEvent.GetScreenSpacePosition());
	DragCurrent = CanvasPos;

	if (DragMode == EHitboxDragMode::Creating)
	{
		int32 SnappedX = SnapToGrid(FMath::RoundToInt(CanvasPos.X));
		int32 SnappedY = SnapToGrid(FMath::RoundToInt(CanvasPos.Y));

		int32 StartX = SnapToGrid(FMath::RoundToInt(DragStart.X));
		int32 StartY = SnapToGrid(FMath::RoundToInt(DragStart.Y));

		CreatingRect = FIntRect(
			FMath::Min(StartX, SnappedX),
			FMath::Min(StartY, SnappedY),
			FMath::Max(StartX, SnappedX),
			FMath::Max(StartY, SnappedY)
		);
	}
	else if (DragMode == EHitboxDragMode::Moving)
	{
		FVector2D Delta = CanvasPos - DragStart;
		int32 DeltaX = SnapToGrid(FMath::RoundToInt(Delta.X));
		int32 DeltaY = SnapToGrid(FMath::RoundToInt(Delta.Y));

		if (DeltaX != 0 || DeltaY != 0)
		{
			FFrameHitboxData* Frame = GetCurrentFrameMutable();
			if (Frame)
			{
				if (SelectionType == EHitboxSelectionType::Hitbox && Frame->Hitboxes.IsValidIndex(SelectedIndex))
				{
					Frame->Hitboxes[SelectedIndex].X += DeltaX;
					Frame->Hitboxes[SelectedIndex].Y += DeltaY;
					OnHitboxDataModified.ExecuteIfBound();
				}
				else if (SelectionType == EHitboxSelectionType::Socket && Frame->Sockets.IsValidIndex(SelectedIndex))
				{
					Frame->Sockets[SelectedIndex].X += DeltaX;
					Frame->Sockets[SelectedIndex].Y += DeltaY;
					OnHitboxDataModified.ExecuteIfBound();
				}
			}

			DragStart.X += DeltaX;
			DragStart.Y += DeltaY;
		}
	}
	else if (DragMode == EHitboxDragMode::Resizing)
	{
		FFrameHitboxData* Frame = GetCurrentFrameMutable();
		if (Frame && SelectionType == EHitboxSelectionType::Hitbox && Frame->Hitboxes.IsValidIndex(SelectedIndex))
		{
			FHitboxData& HB = Frame->Hitboxes[SelectedIndex];

			int32 NewX = SnapToGrid(FMath::RoundToInt(CanvasPos.X));
			int32 NewY = SnapToGrid(FMath::RoundToInt(CanvasPos.Y));

			int32 Left = HB.X;
			int32 Top = HB.Y;
			int32 Right = HB.X + HB.Width;
			int32 Bottom = HB.Y + HB.Height;

			switch (ActiveHandle)
			{
				case EResizeHandle::TopLeft:
					Left = NewX; Top = NewY; break;
				case EResizeHandle::Top:
					Top = NewY; break;
				case EResizeHandle::TopRight:
					Right = NewX; Top = NewY; break;
				case EResizeHandle::Left:
					Left = NewX; break;
				case EResizeHandle::Right:
					Right = NewX; break;
				case EResizeHandle::BottomLeft:
					Left = NewX; Bottom = NewY; break;
				case EResizeHandle::Bottom:
					Bottom = NewY; break;
				case EResizeHandle::BottomRight:
					Right = NewX; Bottom = NewY; break;
				default: break;
			}

			const int32 MinSize = 1;
			if (Right - Left >= MinSize && Bottom - Top >= MinSize)
			{
				HB.X = FMath::Min(Left, Right);
				HB.Y = FMath::Min(Top, Bottom);
				HB.Width = FMath::Abs(Right - Left);
				HB.Height = FMath::Abs(Bottom - Top);
				OnHitboxDataModified.ExecuteIfBound();
			}
		}
	}

	return FReply::Handled();
}

FReply SCharacterDataEditorCanvas::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Delete || InKeyEvent.GetKey() == EKeys::BackSpace)
	{
		DeleteSelection();
		return FReply::Handled();
	}

	int32 NudgeAmount = ShowGrid.Get() ? GridSize : 1;
	if (InKeyEvent.IsShiftDown()) NudgeAmount *= 4;

	if (InKeyEvent.GetKey() == EKeys::Left)
	{
		NudgeSelection(-NudgeAmount, 0);
		return FReply::Handled();
	}
	if (InKeyEvent.GetKey() == EKeys::Right)
	{
		NudgeSelection(NudgeAmount, 0);
		return FReply::Handled();
	}
	if (InKeyEvent.GetKey() == EKeys::Up)
	{
		NudgeSelection(0, -NudgeAmount);
		return FReply::Handled();
	}
	if (InKeyEvent.GetKey() == EKeys::Down)
	{
		NudgeSelection(0, NudgeAmount);
		return FReply::Handled();
	}

	return FReply::Unhandled();
}

void SCharacterDataEditorCanvas::SetSelection(EHitboxSelectionType Type, int32 Index)
{
	if (SelectionType != Type || SelectedIndex != Index)
	{
		SelectionType = Type;
		SelectedIndex = Index;
		OnSelectionChanged.ExecuteIfBound(SelectionType, SelectedIndex);
	}
}

void SCharacterDataEditorCanvas::ClearSelection()
{
	SetSelection(EHitboxSelectionType::None, -1);
}

void SCharacterDataEditorCanvas::NudgeSelection(int32 DeltaX, int32 DeltaY)
{
	FFrameHitboxData* Frame = GetCurrentFrameMutable();
	if (!Frame) return;

	if (SelectionType == EHitboxSelectionType::Hitbox && Frame->Hitboxes.IsValidIndex(SelectedIndex))
	{
		OnRequestUndo.ExecuteIfBound();
		Frame->Hitboxes[SelectedIndex].X += DeltaX;
		Frame->Hitboxes[SelectedIndex].Y += DeltaY;
		OnHitboxDataModified.ExecuteIfBound();
		OnEndTransaction.ExecuteIfBound();
	}
	else if (SelectionType == EHitboxSelectionType::Socket && Frame->Sockets.IsValidIndex(SelectedIndex))
	{
		OnRequestUndo.ExecuteIfBound();
		Frame->Sockets[SelectedIndex].X += DeltaX;
		Frame->Sockets[SelectedIndex].Y += DeltaY;
		OnHitboxDataModified.ExecuteIfBound();
		OnEndTransaction.ExecuteIfBound();
	}
}

void SCharacterDataEditorCanvas::DeleteSelection()
{
	FFrameHitboxData* Frame = GetCurrentFrameMutable();
	if (!Frame) return;

	if (SelectionType == EHitboxSelectionType::Hitbox && Frame->Hitboxes.IsValidIndex(SelectedIndex))
	{
		OnRequestUndo.ExecuteIfBound();
		Frame->Hitboxes.RemoveAt(SelectedIndex);
		ClearSelection();
		OnHitboxDataModified.ExecuteIfBound();
		OnEndTransaction.ExecuteIfBound();
	}
	else if (SelectionType == EHitboxSelectionType::Socket && Frame->Sockets.IsValidIndex(SelectedIndex))
	{
		OnRequestUndo.ExecuteIfBound();
		Frame->Sockets.RemoveAt(SelectedIndex);
		ClearSelection();
		OnHitboxDataModified.ExecuteIfBound();
		OnEndTransaction.ExecuteIfBound();
	}
}

// ==========================================
// FHitbox3DViewportClient Implementation
// ==========================================

FHitbox3DViewportClient::FHitbox3DViewportClient(FPreviewScene* InPreviewScene, const TSharedRef<SHitbox3DViewport>& InViewport)
	: FEditorViewportClient(nullptr, InPreviewScene, StaticCastSharedRef<SEditorViewport>(InViewport))
{
	// Set up the viewport camera
	SetViewLocation(FVector(-300, 200, 200));
	SetViewRotation(FRotator(-25, -30, 0));

	// Set viewport type to perspective
	SetViewportType(LVT_Perspective);

	// Enable orbit camera mode for easier navigation
	bUsingOrbitCamera = true;

	// Show grid and other helpers
	EngineShowFlags.SetGrid(true);

	// Disable real-time by default to save performance
	SetRealtime(false);
}

FHitbox3DViewportClient::~FHitbox3DViewportClient()
{
}

void FHitbox3DViewportClient::SetHitboxData(const FFrameHitboxData* InFrameData)
{
	FrameData = InFrameData;
	Invalidate();
}

FLinearColor FHitbox3DViewportClient::GetHitboxColor(EHitboxType Type) const
{
	switch (Type)
	{
		case EHitboxType::Attack: return FLinearColor(1.0f, 0.2f, 0.2f);
		case EHitboxType::Hurtbox: return FLinearColor(0.2f, 0.9f, 0.2f);
		case EHitboxType::Collision: return FLinearColor(0.3f, 0.5f, 1.0f);
		default: return FLinearColor::White;
	}
}

void FHitbox3DViewportClient::Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	FEditorViewportClient::Draw(View, PDI);

	if (!FrameData) return;

	// Draw hitboxes as 3D wireframe boxes
	for (int32 i = 0; i < FrameData->Hitboxes.Num(); i++)
	{
		const FHitboxData& HB = FrameData->Hitboxes[i];
		FLinearColor Color = GetHitboxColor(HB.Type);

		// Selected hitbox gets brighter color and thicker lines
		bool bSelected = (i == SelectedHitboxIndex);
		if (bSelected)
		{
			Color = Color * 1.5f;
			Color.A = 1.0f;
		}

		// Convert hitbox coords to 3D world space
		// X stays X, Y becomes Z (height), Z (depth offset) becomes Y (depth into scene)
		float EffectiveDepth = (HB.Depth > 0) ? static_cast<float>(HB.Depth) : 20.0f;

		FVector Min(HB.X, HB.Z, HB.Y);
		FVector Max(HB.X + HB.Width, HB.Z + EffectiveDepth, HB.Y + HB.Height);

		// Draw the box
		float Thickness = bSelected ? 3.0f : 1.5f;
		DrawWireBox(PDI, FBox(Min, Max), Color, SDPG_Foreground, Thickness);

		// Draw a solid semi-transparent face on the front for better visibility
		if (bSelected)
		{
			// Draw corner markers for selected box
			float MarkerSize = 5.0f;
			PDI->DrawPoint(Min, Color, MarkerSize, SDPG_Foreground);
			PDI->DrawPoint(Max, Color, MarkerSize, SDPG_Foreground);
			PDI->DrawPoint(FVector(Min.X, Min.Y, Max.Z), Color, MarkerSize, SDPG_Foreground);
			PDI->DrawPoint(FVector(Max.X, Max.Y, Min.Z), Color, MarkerSize, SDPG_Foreground);
		}
	}

	// Draw sockets as 3D crosses
	for (int32 i = 0; i < FrameData->Sockets.Num(); i++)
	{
		const FSocketData& Sock = FrameData->Sockets[i];

		bool bSelected = (i == SelectedSocketIndex);
		FLinearColor SocketColor = bSelected ? FLinearColor::White : FLinearColor::Yellow;
		float CrossSize = 15.0f;
		float Thickness = bSelected ? 3.0f : 2.0f;

		// Socket position in 3D space (Y becomes Z height, socket has no depth so Y=0)
		FVector Pos(Sock.X, 0, Sock.Y);

		// Draw 3D cross
		PDI->DrawLine(Pos - FVector(CrossSize, 0, 0), Pos + FVector(CrossSize, 0, 0), SocketColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(Pos - FVector(0, CrossSize, 0), Pos + FVector(0, CrossSize, 0), SocketColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(Pos - FVector(0, 0, CrossSize), Pos + FVector(0, 0, CrossSize), SocketColor, SDPG_Foreground, Thickness);

		// Draw a point at center
		PDI->DrawPoint(Pos, SocketColor, 8.0f, SDPG_Foreground);
	}

	// Draw reference axes at origin
	float AxisLength = 50.0f;
	PDI->DrawLine(FVector::ZeroVector, FVector(AxisLength, 0, 0), FLinearColor::Red, SDPG_Foreground, 2.0f);
	PDI->DrawLine(FVector::ZeroVector, FVector(0, AxisLength, 0), FLinearColor::Green, SDPG_Foreground, 2.0f);
	PDI->DrawLine(FVector::ZeroVector, FVector(0, 0, AxisLength), FLinearColor::Blue, SDPG_Foreground, 2.0f);

	// Draw ground plane grid
	FLinearColor GridColor(0.3f, 0.3f, 0.3f, 0.5f);
	float GridSize = 200.0f;
	float GridSpacing = 25.0f;
	int32 GridLines = static_cast<int32>(GridSize / GridSpacing);

	for (int32 i = -GridLines; i <= GridLines; i++)
	{
		float Pos = i * GridSpacing;
		PDI->DrawLine(FVector(-GridSize, Pos, 0), FVector(GridSize, Pos, 0), GridColor, SDPG_World, 1.0f);
		PDI->DrawLine(FVector(Pos, -GridSize, 0), FVector(Pos, GridSize, 0), GridColor, SDPG_World, 1.0f);
	}
}

void FHitbox3DViewportClient::DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas)
{
	FEditorViewportClient::DrawCanvas(InViewport, View, Canvas);

	// Draw help text
	FString HelpText = TEXT("RMB + Drag: Rotate | MMB + Drag: Pan | Scroll: Zoom | F: Focus");
	int32 XPos = 10;
	int32 YPos = InViewport.GetSizeXY().Y - 25;

	Canvas.DrawShadowedString(XPos, YPos, *HelpText, GEngine->GetSmallFont(), FLinearColor(0.7f, 0.7f, 0.7f));
}

void FHitbox3DViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	// Keep viewport updated
	Invalidate();
}

bool FHitbox3DViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	// Handle 'F' key to focus on hitboxes
	if (EventArgs.Event == IE_Pressed && EventArgs.Key == EKeys::F)
	{
		FocusOnHitboxes();
		return true;
	}

	return FEditorViewportClient::InputKey(EventArgs);
}

void FHitbox3DViewportClient::FocusOnHitboxes()
{
	if (!FrameData || FrameData->Hitboxes.Num() == 0) return;

	// Calculate bounding box of all hitboxes
	FBox Bounds(EForceInit::ForceInit);
	for (const FHitboxData& HB : FrameData->Hitboxes)
	{
		float EffectiveDepth = (HB.Depth > 0) ? static_cast<float>(HB.Depth) : 20.0f;
		FVector Min(HB.X, HB.Z, HB.Y);
		FVector Max(HB.X + HB.Width, HB.Z + EffectiveDepth, HB.Y + HB.Height);
		Bounds += Min;
		Bounds += Max;
	}

	// Focus the camera on the bounding box
	FVector Center = Bounds.GetCenter();
	float Radius = Bounds.GetExtent().GetMax() * 2.0f;

	SetViewLocation(Center + FVector(-Radius, Radius * 0.5f, Radius * 0.5f));
	SetLookAtLocation(Center);
}

// ==========================================
// SHitbox3DViewport Implementation
// ==========================================

void SHitbox3DViewport::Construct(const FArguments& InArgs)
{
	Asset = InArgs._Asset;

	// Create preview scene
	PreviewScene = MakeShared<FPreviewScene>(FPreviewScene::ConstructionValues());

	// Call parent construct which will call MakeEditorViewportClient
	SEditorViewport::Construct(SEditorViewport::FArguments());
}

SHitbox3DViewport::~SHitbox3DViewport()
{
	if (ViewportClient.IsValid())
	{
		ViewportClient->Viewport = nullptr;
	}
}

TSharedRef<FEditorViewportClient> SHitbox3DViewport::MakeEditorViewportClient()
{
	ViewportClient = MakeShareable(new FHitbox3DViewportClient(PreviewScene.Get(), SharedThis(this)));
	return ViewportClient.ToSharedRef();
}

void SHitbox3DViewport::SetFrameData(const FFrameHitboxData* InFrameData)
{
	if (ViewportClient.IsValid())
	{
		ViewportClient->SetHitboxData(InFrameData);
	}
}

void SHitbox3DViewport::SetSelectedHitbox(int32 Index)
{
	if (ViewportClient.IsValid())
	{
		ViewportClient->SetSelectedHitbox(Index);
	}
}

void SHitbox3DViewport::SetSelectedSocket(int32 Index)
{
	if (ViewportClient.IsValid())
	{
		ViewportClient->SetSelectedSocket(Index);
	}
}

void SHitbox3DViewport::RefreshViewport()
{
	if (ViewportClient.IsValid())
	{
		ViewportClient->Invalidate();
	}
}

// ==========================================
// FCharacterDataAssetEditorToolkit Implementation
// ==========================================

const FName FCharacterDataAssetEditorToolkit::CharacterDataEditorTabId(TEXT("CharacterDataEditorTab"));

FCharacterDataAssetEditorToolkit::~FCharacterDataAssetEditorToolkit()
{
}

void FCharacterDataAssetEditorToolkit::OpenEditor(UPaper2DPlusCharacterDataAsset* Asset)
{
	if (!Asset)
	{
		return;
	}

	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString(FString::Printf(TEXT("Character Data Editor - %s"), *Asset->DisplayName)))
		.ClientSize(FVector2D(1200, 800))
		.SupportsMinimize(true)
		.SupportsMaximize(true)
		[
			SNew(SCharacterDataAssetEditor)
			.Asset(Asset)
		];

	FSlateApplication::Get().AddWindow(Window);
	Window->BringToFront();
}

void FCharacterDataAssetEditorToolkit::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UPaper2DPlusCharacterDataAsset* InAsset)
{
	EditedAsset = InAsset;

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_CharacterDataAssetEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->AddTab(CharacterDataEditorTabId, ETabState::OpenedTab)
				->SetHideTabWell(true)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = false;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		TEXT("CharacterDataAssetEditorApp"),
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		InAsset
	);

	InvokeTab(CharacterDataEditorTabId);
}

void FCharacterDataAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_CharacterDataEditor", "Character Data Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(CharacterDataEditorTabId, FOnSpawnTab::CreateSP(this, &FCharacterDataAssetEditorToolkit::SpawnEditorTab))
		.SetDisplayName(LOCTEXT("EditorTab", "Character Data Editor"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FCharacterDataAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner(CharacterDataEditorTabId);
}

TSharedRef<SDockTab> FCharacterDataAssetEditorToolkit::SpawnEditorTab(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab)
		.Label(FText::FromString(EditedAsset ? EditedAsset->DisplayName : TEXT("Character Data Editor")))
		[
			SNew(SCharacterDataAssetEditor)
			.Asset(EditedAsset)
		];
}

FName FCharacterDataAssetEditorToolkit::GetToolkitFName() const
{
	return FName("CharacterDataAssetEditor");
}

FText FCharacterDataAssetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("ToolkitName", "Paper2D+ Character Data Editor");
}

FString FCharacterDataAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "CharacterData ").ToString();
}

FLinearColor FCharacterDataAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 1.0f);
}

// ==========================================
// SCharacterDataAssetEditor Implementation
// ==========================================

void SCharacterDataAssetEditor::Construct(const FArguments& InArgs)
{
	Asset = InArgs._Asset;

	if (Asset.IsValid())
	{
		Asset->SetFlags(RF_Transactional);
	}

	// Create thumbnail pool for asset previews - large pool for overview with many thumbnails
	ThumbnailPool = MakeShared<FAssetThumbnailPool>(256);

	ChildSlot
	[
		SNew(SVerticalBox)

		// Tab bar at top
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			BuildTabBar()
		]

		// Tab content switcher
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SAssignNew(TabSwitcher, SWidgetSwitcher)
			.WidgetIndex_Lambda([this]() { return ActiveTabIndex; })

			// Tab 0: Overview
			+ SWidgetSwitcher::Slot()
			[
				BuildOverviewTab()
			]

			// Tab 1: Hitbox Editor
			+ SWidgetSwitcher::Slot()
			[
				BuildHitboxEditorTab()
			]

			// Tab 2: Alignment Editor
			+ SWidgetSwitcher::Slot()
			[
				BuildAlignmentEditorTab()
			]
		]
	];

	// Populate the overview tab on initial load
	RefreshOverviewAnimationList();
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildTabBar()
{
	return SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(FMargin(8, 4))
		[
			SNew(SHorizontalBox)

			// Overview tab button
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 4, 0)
			[
				SNew(SCheckBox)
				.Style(FAppStyle::Get(), "ToggleButtonCheckbox")
				.IsChecked_Lambda([this]() { return ActiveTabIndex == 0 ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState) { SwitchToTab(0); })
				.Padding(FMargin(8, 4))
				[
					SNew(STextBlock)
					.Text(LOCTEXT("OverviewTab", "Overview"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
				]
			]

			// Hitbox Editor tab button
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 4, 0)
			[
				SNew(SCheckBox)
				.Style(FAppStyle::Get(), "ToggleButtonCheckbox")
				.IsChecked_Lambda([this]() { return ActiveTabIndex == 1 ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState) { SwitchToTab(1); })
				.Padding(FMargin(8, 4))
				[
					SNew(STextBlock)
					.Text(LOCTEXT("HitboxEditorTab", "Hitbox Editor"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
				]
			]

			// Alignment Editor tab button
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 16, 0)
			[
				SNew(SCheckBox)
				.Style(FAppStyle::Get(), "ToggleButtonCheckbox")
				.IsChecked_Lambda([this]() { return ActiveTabIndex == 2 ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState) { SwitchToTab(2); })
				.Padding(FMargin(8, 4))
				[
					SNew(STextBlock)
					.Text(LOCTEXT("AlignmentEditorTab", "Alignment Editor"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
				]
			]

			// Spacer
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNullWidget::NullWidget
			]

			// Import JSON button (available on all tabs)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.Text(LOCTEXT("ImportJSON", "Import JSON"))
				.OnClicked_Lambda([this]() { OnImportJsonClicked(); return FReply::Handled(); })
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildOverviewTab()
{
	return SNew(SScrollBox)
		+ SScrollBox::Slot()
		.Padding(8)
		[
			SNew(SVerticalBox)

			// Character Info Section
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 0, 0, 8)
			[
				SNew(SBorder)
				.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
				.Padding(8)
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(LOCTEXT("CharacterInfo", "CHARACTER INFO"))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(0, 8, 0, 0)
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(0, 0, 8, 0)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("DisplayName", "Display Name:"))
						]

						+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						[
							SNew(SEditableTextBox)
							.Text_Lambda([this]() { return Asset.IsValid() ? FText::FromString(Asset->DisplayName) : FText::GetEmpty(); })
							.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type) {
								if (Asset.IsValid())
								{
									Asset->Modify();
									Asset->DisplayName = Text.ToString();
								}
							})
						]
					]
				]
			]

			// Uniform Dimensions Section
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 0, 0, 8)
			[
				SNew(SBorder)
				.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
				.Padding(8)
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(LOCTEXT("UniformDimensions", "UNIFORM DIMENSIONS"))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(0, 8, 0, 0)
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(0, 0, 8, 0)
						[
							SNew(STextBlock).Text(LOCTEXT("Width", "Width:"))
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SBox)
							.WidthOverride(60)
							[
								SNew(SSpinBox<int32>)
								.MinValue(1)
								.MaxValue(4096)
								.Value_Lambda([this]() { return Asset.IsValid() ? Asset->UniformDimensions.X : 64; })
								.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) {
									if (Asset.IsValid())
									{
										Asset->Modify();
										Asset->UniformDimensions.X = Value;
									}
								})
							]
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(16, 0, 8, 0)
						[
							SNew(STextBlock).Text(LOCTEXT("Height", "Height:"))
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SBox)
							.WidthOverride(60)
							[
								SNew(SSpinBox<int32>)
								.MinValue(1)
								.MaxValue(4096)
								.Value_Lambda([this]() { return Asset.IsValid() ? Asset->UniformDimensions.Y : 64; })
								.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) {
									if (Asset.IsValid())
									{
										Asset->Modify();
										Asset->UniformDimensions.Y = Value;
									}
								})
							]
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(16, 0, 0, 0)
						[
							SNew(SCheckBox)
							.IsChecked_Lambda([this]() { return Asset.IsValid() && Asset->bUseUniformDimensions ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
							.OnCheckStateChanged_Lambda([this](ECheckBoxState State) {
								if (Asset.IsValid())
								{
									Asset->Modify();
									Asset->bUseUniformDimensions = (State == ECheckBoxState::Checked);
								}
							})
							[
								SNew(STextBlock).Text(LOCTEXT("UseUniform", "Use Uniform"))
							]
						]
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(0, 8, 0, 0)
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(0, 0, 8, 0)
						[
							SNew(SButton)
							.Text(LOCTEXT("CalculateLargest", "Calculate Largest"))
							.OnClicked_Lambda([this]() {
								if (Asset.IsValid())
								{
									Asset->Modify();
									Asset->SetUniformToLargest();
								}
								return FReply::Handled();
							})
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SButton)
							.Text(LOCTEXT("ReExtractMismatched", "Re-Extract All Mismatched"))
							.IsEnabled_Lambda([this]() { return Asset.IsValid() && Asset->GetMismatchedAnimations().Num() > 0; })
							.OnClicked_Lambda([this]() {
								// TODO: Implement re-extraction
								return FReply::Handled();
							})
						]
					]
				]
			]

			// Flipbooks Section
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBorder)
				.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
				.Padding(8)
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Flipbooks", "FLIPBOOKS"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(STextBlock)
							.Text_Lambda([this]() {
								if (!Asset.IsValid()) return FText::GetEmpty();
								int32 Matching = 0;
								int32 Total = Asset->Animations.Num();
								for (const auto& Anim : Asset->Animations)
								{
									if (Anim.SpriteDimensions == Asset->UniformDimensions)
										Matching++;
								}
								return FText::Format(LOCTEXT("MatchingStatus", "Status: {0}/{1} matching"), FText::AsNumber(Matching), FText::AsNumber(Total));
							})
							.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
						]
					]

					// Flipbook grid
					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(0, 8, 0, 0)
					[
						BuildAnimationGrid()
					]

					// Action buttons
					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(0, 8, 0, 0)
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(0, 0, 8, 0)
						[
							SNew(SButton)
							.Text(LOCTEXT("AddFlipbook", "+ Add Flipbook"))
							.OnClicked_Lambda([this]() { AddNewAnimation(); RefreshOverviewAnimationList(); return FReply::Handled(); })
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(0, 0, 8, 0)
						[
							SNew(SButton)
							.Text(LOCTEXT("RemoveFlipbook", "- Remove Selected"))
							.IsEnabled_Lambda([this]() { return Asset.IsValid() && Asset->Animations.IsValidIndex(SelectedAnimationIndex); })
							.OnClicked_Lambda([this]() { RemoveSelectedAnimation(); RefreshOverviewAnimationList(); return FReply::Handled(); })
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SButton)
							.Text(LOCTEXT("ExtractFromTexture", "Extract from Texture..."))
							.OnClicked_Lambda([this]() {
								FSpriteExtractorActions::OpenSpriteExtractor();
								return FReply::Handled();
							})
						]
					]
				]
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAnimationGrid()
{
	return SAssignNew(OverviewAnimationListBox, SVerticalBox);
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildHitboxEditorTab()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			BuildToolbar()
		]

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(4)
		[
			SNew(SSplitter)
			.Orientation(Orient_Horizontal)

			+ SSplitter::Slot()
			.Value(0.2f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					BuildToolPanel()
				]

				+ SVerticalBox::Slot()
				.FillHeight(0.4f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildAnimationList()
					]
				]

				+ SVerticalBox::Slot()
				.FillHeight(0.6f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildFrameList()
					]
				]
			]

			+ SSplitter::Slot()
			.Value(0.55f)
			[
				SNew(SVerticalBox)

				// Canvas Area
				+ SVerticalBox::Slot()
				.FillHeight(1.0f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildCanvasArea()
					]
				]

				// Dimension Management (Collapsible)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					BuildDimensionManagementSection()
				]
			]

			+ SSplitter::Slot()
			.Value(0.25f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.FillHeight(0.5f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildHitboxList()
					]
				]

				+ SVerticalBox::Slot()
				.FillHeight(0.3f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildPropertiesPanel()
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildCopyOperationsPanel()
					]
				]
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAlignmentEditorTab()
{
	return SNew(SVerticalBox)

		// Unified toolbar
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			BuildAlignmentToolbar()
		]

		// Main content area
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(4)
		[
			SNew(SSplitter)
			.Orientation(Orient_Horizontal)

			// Left panel: Animation and Frame lists
			+ SSplitter::Slot()
			.Value(0.2f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.FillHeight(0.5f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildAlignmentAnimationList()
					]
				]

				+ SVerticalBox::Slot()
				.FillHeight(0.5f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4)
					[
						BuildAlignmentFrameList()
					]
				]
			]

			// Center: Canvas
			+ SSplitter::Slot()
			.Value(0.6f)
			[
				BuildAlignmentCanvasArea()
			]

			// Right panel: Offset controls
			+ SSplitter::Slot()
			.Value(0.2f)
			[
				SNew(SBorder)
				.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
				.Padding(4)
				[
					BuildOffsetControlsPanel()
				]
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAlignmentToolbar()
{
	return SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(FMargin(8, 4))
		[
			SNew(SHorizontalBox)

			// === SECTION 1: Flipbook Name ===
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock)
				.Text_Lambda([this]() {
					const FAnimationHitboxData* Anim = GetCurrentAnimation();
					return Anim ? FText::FromString(Anim->AnimationName) : LOCTEXT("NoFlipbook", "None");
				})
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
			]

			// Separator
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			// === SECTION 2: Frame Navigation ===
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 2, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
				.ToolTipText(LOCTEXT("PrevFrameTooltip", "Previous Frame (Left Arrow or ,)"))
				.OnClicked_Lambda([this]() {
					OnPrevFrameClicked();
					RefreshAlignmentFrameList();
					return FReply::Handled();
				})
				[
					SNew(STextBlock)
					.Text(LOCTEXT("PrevFrame", "<"))
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4, 0)
			[
				SNew(STextBlock)
				.Text_Lambda([this]() {
					int32 FrameCount = GetCurrentFrameCount();
					return FText::Format(LOCTEXT("FrameCounter", "{0}/{1}"),
						FText::AsNumber(SelectedFrameIndex + 1),
						FText::AsNumber(FrameCount));
				})
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 8, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
				.ToolTipText(LOCTEXT("NextFrameTooltip", "Next Frame (Right Arrow or .)"))
				.OnClicked_Lambda([this]() {
					OnNextFrameClicked();
					RefreshAlignmentFrameList();
					return FReply::Handled();
				})
				[
					SNew(STextBlock)
					.Text(LOCTEXT("NextFrame", ">"))
				]
			]

			// Separator
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			// === SECTION 3: Playback Controls ===
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 8, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
				.ToolTipText(LOCTEXT("PlayPauseTooltip", "Play/Pause (Space)"))
				.OnClicked_Lambda([this]() {
					TogglePlayback();
					return FReply::Handled();
				})
				[
					SNew(STextBlock)
					.Text_Lambda([this]() { return bIsPlaying ? LOCTEXT("Pause", "Pause") : LOCTEXT("Play", "Play"); })
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 4, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("FPSLabel", "FPS:"))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 8, 0)
			[
				SNew(SBox)
				.WidthOverride(50)
				[
					SNew(SSpinBox<float>)
					.MinValue(1.0f)
					.MaxValue(60.0f)
					.Value_Lambda([this]() { return PlaybackFPS; })
					.OnValueChanged_Lambda([this](float NewValue) { OnPlaybackFPSChanged(NewValue); })
				]
			]

			// Separator
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			// === SECTION 4: Zoom ===
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 4, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ZoomLabel", "Zoom:"))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 4, 0)
			[
				SNew(SBox)
				.WidthOverride(80)
				[
					SNew(SSlider)
					.MinValue(0.5f)
					.MaxValue(4.0f)
					.Value_Lambda([this]() { return AlignmentZoomLevel; })
					.OnValueChanged_Lambda([this](float NewValue) { AlignmentZoomLevel = NewValue; })
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock)
				.Text_Lambda([this]() {
					return FText::Format(LOCTEXT("ZoomPercent", "{0}%"), FText::AsNumber(FMath::RoundToInt(AlignmentZoomLevel * 100)));
				})
			]

			// Separator
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			// === SECTION 5: View Options ===
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 12, 0)
			[
				SNew(SCheckBox)
				.ToolTipText(LOCTEXT("GridTooltip", "Toggle Grid (G)"))
				.IsChecked_Lambda([this]() { return bShowAlignmentGrid ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { bShowAlignmentGrid = (State == ECheckBoxState::Checked); })
				[
					SNew(STextBlock)
					.Text(LOCTEXT("ShowGridG", "Grid (G)"))
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 8, 0)
			[
				SNew(SCheckBox)
				.ToolTipText(LOCTEXT("OnionTooltip", "Toggle Onion Skin (O)"))
				.IsChecked_Lambda([this]() { return bShowOnionSkin ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { bShowOnionSkin = (State == ECheckBoxState::Checked); })
				[
					SNew(STextBlock)
					.Text(LOCTEXT("OnionSkinO", "Onion (O)"))
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 4, 0)
			[
				SNew(SBox)
				.WidthOverride(40)
				[
					SNew(SSpinBox<int32>)
					.ToolTipText(LOCTEXT("OnionFramesTooltip", "Number of onion skin frames"))
					.MinValue(1)
					.MaxValue(3)
					.Value_Lambda([this]() { return OnionSkinFrames; })
					.OnValueChanged_Lambda([this](int32 NewValue) { OnionSkinFrames = NewValue; })
					.IsEnabled_Lambda([this]() { return bShowOnionSkin; })
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 8, 0)
			[
				SNew(SBox)
				.WidthOverride(60)
				[
					SNew(SSlider)
					.ToolTipText(LOCTEXT("OnionOpacityTooltip", "Onion skin opacity"))
					.MinValue(0.1f)
					.MaxValue(0.8f)
					.Value_Lambda([this]() { return OnionSkinOpacity; })
					.OnValueChanged_Lambda([this](float NewValue) { OnionSkinOpacity = NewValue; })
					.IsEnabled_Lambda([this]() { return bShowOnionSkin; })
				]
			]

			// Separator
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			// === SECTION 6: Anchor ===
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 4, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("AnchorLabel", "Anchor:"))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 0, 0)
			[
				SNew(SBox)
				.WidthOverride(100)
				[
					SNew(SComboButton)
					.OnGetMenuContent_Lambda([this]() -> TSharedRef<SWidget> {
						FMenuBuilder MenuBuilder(true, nullptr);

						auto AddAnchorOption = [this, &MenuBuilder](ESpriteAnchor Anchor, const FText& Label) {
							MenuBuilder.AddMenuEntry(
								Label,
								FText::GetEmpty(),
								FSlateIcon(),
								FUIAction(
									FExecuteAction::CreateLambda([this, Anchor]() { AlignmentReticleAnchor = Anchor; }),
									FCanExecuteAction(),
									FIsActionChecked::CreateLambda([this, Anchor]() { return AlignmentReticleAnchor == Anchor; })
								),
								NAME_None,
								EUserInterfaceActionType::RadioButton
							);
						};

						AddAnchorOption(ESpriteAnchor::TopLeft, LOCTEXT("TopLeft", "Top Left"));
						AddAnchorOption(ESpriteAnchor::TopCenter, LOCTEXT("TopCenter", "Top Center"));
						AddAnchorOption(ESpriteAnchor::TopRight, LOCTEXT("TopRight", "Top Right"));
						MenuBuilder.AddSeparator();
						AddAnchorOption(ESpriteAnchor::CenterLeft, LOCTEXT("CenterLeft", "Center Left"));
						AddAnchorOption(ESpriteAnchor::Center, LOCTEXT("Center", "Center"));
						AddAnchorOption(ESpriteAnchor::CenterRight, LOCTEXT("CenterRight", "Center Right"));
						MenuBuilder.AddSeparator();
						AddAnchorOption(ESpriteAnchor::BottomLeft, LOCTEXT("BottomLeft", "Bottom Left"));
						AddAnchorOption(ESpriteAnchor::BottomCenter, LOCTEXT("BottomCenter", "Bottom Center"));
						AddAnchorOption(ESpriteAnchor::BottomRight, LOCTEXT("BottomRight", "Bottom Right"));

						return MenuBuilder.MakeWidget();
					})
					.ButtonContent()
					[
						SNew(STextBlock)
						.Text_Lambda([this]() {
							switch (AlignmentReticleAnchor)
							{
								case ESpriteAnchor::TopLeft:      return LOCTEXT("TL", "Top Left");
								case ESpriteAnchor::TopCenter:    return LOCTEXT("TC", "Top Center");
								case ESpriteAnchor::TopRight:     return LOCTEXT("TR", "Top Right");
								case ESpriteAnchor::CenterLeft:   return LOCTEXT("CL", "Center Left");
								case ESpriteAnchor::Center:       return LOCTEXT("C", "Center");
								case ESpriteAnchor::CenterRight:  return LOCTEXT("CR", "Center Right");
								case ESpriteAnchor::BottomLeft:   return LOCTEXT("BL", "Bottom Left");
								case ESpriteAnchor::BottomCenter: return LOCTEXT("BC", "Bottom Center");
								case ESpriteAnchor::BottomRight:  return LOCTEXT("BR", "Bottom Right");
								default: return LOCTEXT("Unknown", "Unknown");
							}
						})
					]
				]
			]

			// Spacer
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNullWidget::NullWidget
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAlignmentAnimationList()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("AlignFlipbooks", "FLIPBOOKS"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
		]

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
			[
				SAssignNew(AlignmentAnimationListBox, SVerticalBox)
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAlignmentFrameList()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("AlignFrames", "FRAMES"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
		]

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
			[
				SAssignNew(AlignmentFrameListBox, SVerticalBox)
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAlignmentCanvasArea()
{
	TSharedRef<SBorder> Border = SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(0)
		[
			SAssignNew(AlignmentCanvas, SSpriteAlignmentCanvas)
			.Asset(Asset.Get())
			.SelectedAnimationIndex_Lambda([this]() { return SelectedAnimationIndex; })
			.SelectedFrameIndex_Lambda([this]() { return SelectedFrameIndex; })
			.ShowGrid_Lambda([this]() { return bShowAlignmentGrid; })
			.Zoom_Lambda([this]() { return AlignmentZoomLevel; })
			.ShowOnionSkin_Lambda([this]() { return bShowOnionSkin; })
			.OnionSkinFrames_Lambda([this]() { return OnionSkinFrames; })
			.OnionSkinOpacity_Lambda([this]() { return OnionSkinOpacity; })
			.ReticleAnchor_Lambda([this]() { return AlignmentReticleAnchor; })
		];

	// Wire up canvas delegates
	if (AlignmentCanvas.IsValid())
	{
		AlignmentCanvas->OnOffsetChanged.BindSP(this, &SCharacterDataAssetEditor::OnAlignmentOffsetChanged);
		AlignmentCanvas->OnZoomChanged.BindLambda([this](float NewZoom) {
			AlignmentZoomLevel = NewZoom;
		});
	}

	return Border;
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildOffsetControlsPanel()
{
	return SNew(SVerticalBox)

		// === Section: Offset Values ===
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("OffsetControls", "OFFSET"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 12)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
			.Padding(8)
			[
				SNew(SVerticalBox)

				// X offset
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0, 0, 0, 4)
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(0, 0, 8, 0)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("OffsetX", "X:"))
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SNew(SSpinBox<int32>)
						.MinValue(-500)
						.MaxValue(500)
						.Value_Lambda([this]() {
							const FAnimationHitboxData* Anim = GetCurrentAnimation();
							if (Anim && Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex))
							{
								return Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset.X;
							}
							return 0;
						})
						.OnValueChanged_Lambda([this](int32 NewValue) { OnOffsetXChanged(NewValue); })
					]
				]

				// Y offset
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(0, 0, 8, 0)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("OffsetY", "Y:"))
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SNew(SSpinBox<int32>)
						.MinValue(-500)
						.MaxValue(500)
						.Value_Lambda([this]() {
							const FAnimationHitboxData* Anim = GetCurrentAnimation();
							if (Anim && Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex))
							{
								return Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset.Y;
							}
							return 0;
						})
						.OnValueChanged_Lambda([this](int32 NewValue) { OnOffsetYChanged(NewValue); })
					]
				]
			]
		]

		// === Section: Nudge Controls ===
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("NudgeControls", "NUDGE"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("NudgeHint", "WASD or Arrows (Shift = 10px)"))
			.Font(FCoreStyle::GetDefaultFontStyle("Regular", 8))
			.ColorAndOpacity(FSlateColor(FLinearColor(0.5f, 0.5f, 0.5f)))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 12)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
				.ToolTipText(LOCTEXT("NudgeUpTooltip", "Nudge Up (W or Up Arrow)"))
				.OnClicked_Lambda([this]() { NudgeOffset(0, -1); return FReply::Handled(); })
				[
					SNew(SBox)
					.WidthOverride(28)
					.HAlign(HAlign_Center)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("NudgeUp", "W"))
					]
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0, 0, 2, 0)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
					.ToolTipText(LOCTEXT("NudgeLeftTooltip", "Nudge Left (A)"))
					.OnClicked_Lambda([this]() { NudgeOffset(-1, 0); return FReply::Handled(); })
					[
						SNew(SBox)
						.WidthOverride(28)
						.HAlign(HAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NudgeLeft", "A"))
						]
					]
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0, 0, 2, 0)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
					.ToolTipText(LOCTEXT("NudgeDownTooltip", "Nudge Down (S or Down Arrow)"))
					.OnClicked_Lambda([this]() { NudgeOffset(0, 1); return FReply::Handled(); })
					[
						SNew(SBox)
						.WidthOverride(28)
						.HAlign(HAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NudgeDown", "S"))
						]
					]
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
					.ToolTipText(LOCTEXT("NudgeRightTooltip", "Nudge Right (D)"))
					.OnClicked_Lambda([this]() { NudgeOffset(1, 0); return FReply::Handled(); })
					[
						SNew(SBox)
						.WidthOverride(28)
						.HAlign(HAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NudgeRight", "D"))
						]
					]
				]
			]
		]

		// === Section: Clipboard ===
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Clipboard", "CLIPBOARD"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 12)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.Padding(0, 0, 2, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
				.HAlign(HAlign_Center)
				.OnClicked_Lambda([this]() { OnCopyOffset(); return FReply::Handled(); })
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Copy", "Copy"))
				]
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.Padding(2, 0, 0, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
				.HAlign(HAlign_Center)
				.IsEnabled_Lambda([this]() { return bHasCopiedOffset; })
				.OnClicked_Lambda([this]() { OnPasteOffset(); return FReply::Handled(); })
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Paste", "Paste"))
				]
			]
		]

		// === Section: Batch Operations ===
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("BatchOps", "BATCH"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
			.HAlign(HAlign_Center)
			.ToolTipText(LOCTEXT("ApplyToRemainingTooltip", "Apply current offset to all remaining frames"))
			.OnClicked_Lambda([this]() { OnApplyOffsetToRemaining(); return FReply::Handled(); })
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ApplyToRemaining", "Apply to Remaining"))
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 12)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
			.HAlign(HAlign_Center)
			.ToolTipText(LOCTEXT("ApplyToAllTooltip", "Apply current offset to all frames"))
			.OnClicked_Lambda([this]() { OnApplyOffsetToAll(); return FReply::Handled(); })
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ApplyToAll", "Apply to All"))
			]
		]

		// Spacer
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNullWidget::NullWidget
		]

		// === Reset at bottom ===
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "FlatButton.Default")
			.HAlign(HAlign_Center)
			.ToolTipText(LOCTEXT("ResetOffsetTooltip", "Reset offset to zero"))
			.OnClicked_Lambda([this]() { OnResetOffset(); return FReply::Handled(); })
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ResetOffset", "Reset Offset"))
			]
		];
}

void SCharacterDataAssetEditor::RefreshAlignmentAnimationList()
{
	if (!AlignmentAnimationListBox.IsValid() || !Asset.IsValid()) return;

	AlignmentAnimationListBox->ClearChildren();

	for (int32 i = 0; i < Asset->Animations.Num(); i++)
	{
		const FAnimationHitboxData& Anim = Asset->Animations[i];
		bool bSelected = (i == SelectedAnimationIndex);

		AlignmentAnimationListBox->AddSlot()
		.AutoHeight()
		.Padding(0, 0, 0, 2)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), bSelected ? "FlatButton.Primary" : "FlatButton.Default")
			.OnClicked_Lambda([this, i]() {
				OnAnimationSelected(i);
				RefreshAlignmentAnimationList();
				RefreshAlignmentFrameList();
				return FReply::Handled();
			})
			[
				SNew(STextBlock)
				.Text(FText::FromString(Anim.AnimationName))
			]
		];
	}
}

void SCharacterDataAssetEditor::RefreshAlignmentFrameList()
{
	if (!AlignmentFrameListBox.IsValid() || !Asset.IsValid()) return;

	AlignmentFrameListBox->ClearChildren();

	// Clear stored thumbnails - they need to persist for widgets to render
	AlignmentFrameThumbnails.Empty();

	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim) return;

	// Get the flipbook to extract frame sprites
	UPaperFlipbook* Flipbook = nullptr;
	if (!Anim->Flipbook.IsNull())
	{
		Flipbook = Anim->Flipbook.LoadSynchronous();
	}

	for (int32 i = 0; i < Anim->Frames.Num(); i++)
	{
		const FFrameHitboxData& Frame = Anim->Frames[i];
		bool bSelected = (i == SelectedFrameIndex);

		// Check if this frame has custom alignment
		bool bHasCustomAlign = false;
		if (Anim->FrameExtractionInfo.IsValidIndex(i))
		{
			bHasCustomAlign = Anim->FrameExtractionInfo[i].bHasCustomAlignment;
		}

		// Create thumbnail for this frame's sprite
		TSharedPtr<FAssetThumbnail> FrameThumbnail;
		if (Flipbook && i < Flipbook->GetNumKeyFrames())
		{
			UPaperSprite* FrameSprite = Flipbook->GetKeyFrameChecked(i).Sprite;
			if (FrameSprite)
			{
				FAssetData SpriteAssetData(FrameSprite);
				FrameThumbnail = MakeShared<FAssetThumbnail>(SpriteAssetData, 32, 32, ThumbnailPool);
				AlignmentFrameThumbnails.Add(FrameThumbnail);
			}
		}

		AlignmentFrameListBox->AddSlot()
		.AutoHeight()
		.Padding(0, 0, 0, 2)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), bSelected ? "FlatButton.Primary" : "FlatButton.Default")
			.OnClicked_Lambda([this, i]() {
				OnFrameSelected(i);
				RefreshAlignmentFrameList();
				return FReply::Handled();
			})
			[
				SNew(SHorizontalBox)

				// Sprite thumbnail
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0, 0, 4, 0)
				[
					SNew(SBox)
					.WidthOverride(32)
					.HeightOverride(32)
					[
						FrameThumbnail.IsValid()
							? FrameThumbnail->MakeThumbnailWidget()
							: SNew(SBorder)
								.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.Text(FText::AsNumber(i))
									.Font(FCoreStyle::GetDefaultFontStyle("Regular", 9))
								]
					]
				]

				// Frame name
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString(Frame.FrameName))
				]

				// Custom alignment indicator
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(bHasCustomAlign ? LOCTEXT("AlignedMark", "*") : FText::GetEmpty())
					.ColorAndOpacity(FLinearColor::Yellow)
				]
			]
		];
	}

	// Force thumbnails to render immediately
	if (ThumbnailPool.IsValid())
	{
		ThumbnailPool->Tick(0);
	}
}

void SCharacterDataAssetEditor::NudgeOffset(int32 DeltaX, int32 DeltaY)
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	BeginTransaction(LOCTEXT("NudgeOffset", "Nudge Sprite Offset"));
	Asset->Modify();

	Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset.X += DeltaX;
	Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset.Y += DeltaY;
	Anim->FrameExtractionInfo[SelectedFrameIndex].bHasCustomAlignment = true;

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnOffsetXChanged(int32 NewValue)
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	BeginTransaction(LOCTEXT("ChangeOffsetX", "Change Sprite Offset X"));
	Asset->Modify();

	Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset.X = NewValue;
	Anim->FrameExtractionInfo[SelectedFrameIndex].bHasCustomAlignment = true;

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnOffsetYChanged(int32 NewValue)
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	BeginTransaction(LOCTEXT("ChangeOffsetY", "Change Sprite Offset Y"));
	Asset->Modify();

	Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset.Y = NewValue;
	Anim->FrameExtractionInfo[SelectedFrameIndex].bHasCustomAlignment = true;

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnCopyOffset()
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	CopiedOffset = Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset;
	bHasCopiedOffset = true;
}

void SCharacterDataAssetEditor::OnPasteOffset()
{
	if (!bHasCopiedOffset) return;

	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	BeginTransaction(LOCTEXT("PasteOffset", "Paste Sprite Offset"));
	Asset->Modify();

	Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset = CopiedOffset;
	Anim->FrameExtractionInfo[SelectedFrameIndex].bHasCustomAlignment = true;

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnApplyOffsetToAll()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	FIntPoint CurrentOffset = Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset;

	BeginTransaction(LOCTEXT("ApplyOffsetAll", "Apply Offset to All Frames"));
	Asset->Modify();

	for (int32 i = 0; i < Anim->FrameExtractionInfo.Num(); i++)
	{
		Anim->FrameExtractionInfo[i].SpriteOffset = CurrentOffset;
		Anim->FrameExtractionInfo[i].bHasCustomAlignment = true;
	}

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnApplyOffsetToRemaining()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	FIntPoint CurrentOffset = Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset;

	BeginTransaction(LOCTEXT("ApplyOffsetRemaining", "Apply Offset to Remaining Frames"));
	Asset->Modify();

	for (int32 i = SelectedFrameIndex; i < Anim->FrameExtractionInfo.Num(); i++)
	{
		Anim->FrameExtractionInfo[i].SpriteOffset = CurrentOffset;
		Anim->FrameExtractionInfo[i].bHasCustomAlignment = true;
	}

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnResetOffset()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(SelectedFrameIndex)) return;

	BeginTransaction(LOCTEXT("ResetOffset", "Reset Sprite Offset"));
	Asset->Modify();

	Anim->FrameExtractionInfo[SelectedFrameIndex].SpriteOffset = FIntPoint::ZeroValue;
	Anim->FrameExtractionInfo[SelectedFrameIndex].bHasCustomAlignment = false;

	EndTransaction();
	RefreshAlignmentFrameList();
}

void SCharacterDataAssetEditor::OnAlignmentOffsetChanged(int32 DeltaX, int32 DeltaY)
{
	NudgeOffset(DeltaX, DeltaY);
}

void SCharacterDataAssetEditor::StartPlayback()
{
	if (bIsPlaying) return;

	bIsPlaying = true;
	float Interval = 1.0f / PlaybackFPS;

	PlaybackTickerHandle = FTSTicker::GetCoreTicker().AddTicker(
		FTickerDelegate::CreateSP(this, &SCharacterDataAssetEditor::OnPlaybackTick),
		Interval
	);
}

void SCharacterDataAssetEditor::StopPlayback()
{
	if (!bIsPlaying) return;

	bIsPlaying = false;
	if (PlaybackTickerHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(PlaybackTickerHandle);
		PlaybackTickerHandle.Reset();
	}
}

void SCharacterDataAssetEditor::TogglePlayback()
{
	if (bIsPlaying)
	{
		StopPlayback();
	}
	else
	{
		StartPlayback();
	}
}

bool SCharacterDataAssetEditor::OnPlaybackTick(float DeltaTime)
{
	int32 FrameCount = GetCurrentFrameCount();
	if (FrameCount > 0)
	{
		SelectedFrameIndex = (SelectedFrameIndex + 1) % FrameCount;
		RefreshAlignmentFrameList();
	}

	return true; // Continue ticking
}

void SCharacterDataAssetEditor::OnPlaybackFPSChanged(float NewFPS)
{
	PlaybackFPS = FMath::Clamp(NewFPS, 1.0f, 60.0f);

	// If playing, restart with new FPS
	if (bIsPlaying)
	{
		StopPlayback();
		StartPlayback();
	}
}

void SCharacterDataAssetEditor::OnEditAlignmentClicked(int32 AnimationIndex)
{
	SelectedAnimationIndex = AnimationIndex;
	SelectedFrameIndex = 0;
	SwitchToTab(2);
}

void SCharacterDataAssetEditor::SwitchToTab(int32 TabIndex)
{
	// Stop playback when switching away from alignment tab
	if (ActiveTabIndex == 2 && TabIndex != 2 && bIsPlaying)
	{
		StopPlayback();
	}

	ActiveTabIndex = TabIndex;
	if (TabSwitcher.IsValid())
	{
		TabSwitcher->SetActiveWidgetIndex(TabIndex);
	}

	// Refresh appropriate content
	if (TabIndex == 0)
	{
		RefreshOverviewAnimationList();
	}
	else if (TabIndex == 1)
	{
		RefreshAnimationList();
		RefreshFrameList();
		RefreshHitboxList();
	}
	else if (TabIndex == 2)
	{
		RefreshAlignmentAnimationList();
		RefreshAlignmentFrameList();
	}
}

void SCharacterDataAssetEditor::OnEditHitboxesClicked(int32 AnimationIndex)
{
	SelectedAnimationIndex = AnimationIndex;
	SelectedFrameIndex = 0;
	SwitchToTab(1);
}

void SCharacterDataAssetEditor::RefreshOverviewAnimationList()
{
	if (!OverviewAnimationListBox.IsValid() || !Asset.IsValid()) return;

	OverviewAnimationListBox->ClearChildren();

	// Clear stored thumbnails - they need to persist for widgets to render
	OverviewThumbnails.Empty();

	// Header row
	OverviewAnimationListBox->AddSlot()
	.AutoHeight()
	.Padding(0, 0, 0, 4)
	[
		SNew(SHorizontalBox)

		// Flipbook asset column header
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(4, 0)
		[
			SNew(SBox)
			.WidthOverride(68)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("FlipbookAsset", "Asset"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
			]
		]

		+ SHorizontalBox::Slot()
		.FillWidth(0.25f)
		.Padding(4, 0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("FlipbookName", "Name"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(0.12f)
		.Padding(4, 0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("FlipbookDimensions", "Size"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(0.12f)
		.Padding(4, 0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("FlipbookFrames", "Frames"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(0.12f)
		.Padding(4, 0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("FlipbookStatus", "Status"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(0.3f)
		.Padding(4, 0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("FlipbookActions", "Actions"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		]
	];

	// Flipbook rows
	for (int32 i = 0; i < Asset->Animations.Num(); i++)
	{
		const FAnimationHitboxData& Anim = Asset->Animations[i];
		bool bSelected = (i == SelectedAnimationIndex);
		bool bHasFlipbook = !Anim.Flipbook.IsNull();

		// Determine status
		EDimensionStatus Status = Asset->GetAnimationDimensionStatus(Anim.AnimationName);
		FText StatusText;
		FLinearColor StatusColor;
		switch (Status)
		{
		case EDimensionStatus::MatchesUniform:
			StatusText = LOCTEXT("StatusOK", "OK");
			StatusColor = FLinearColor::Green;
			break;
		case EDimensionStatus::SmallerThanUniform:
			StatusText = LOCTEXT("StatusSmall", "< Small");
			StatusColor = FLinearColor::Yellow;
			break;
		case EDimensionStatus::LargerThanUniform:
			StatusText = LOCTEXT("StatusLarge", "! Large");
			StatusColor = FLinearColor(1.0f, 0.5f, 0.0f);
			break;
		default:
			StatusText = LOCTEXT("StatusUnknown", "-");
			StatusColor = FLinearColor::Gray;
			break;
		}

		int32 AnimIndex = i; // Capture for lambda

		// Create thumbnail for this flipbook and store it persistently
		TSharedPtr<FAssetThumbnail> Thumbnail;
		if (bHasFlipbook)
		{
			FAssetData FlipbookAssetData(Anim.Flipbook.LoadSynchronous());
			Thumbnail = MakeShared<FAssetThumbnail>(FlipbookAssetData, 64, 64, ThumbnailPool);
			OverviewThumbnails.Add(Thumbnail);
		}

		// Build frame sprites widget for expandable area
		TSharedRef<SHorizontalBox> FrameSpritesBox = SNew(SHorizontalBox);
		if (bHasFlipbook)
		{
			UPaperFlipbook* LoadedFlipbook = Anim.Flipbook.LoadSynchronous();
			if (LoadedFlipbook)
			{
				const int32 NumKeyFrames = LoadedFlipbook->GetNumKeyFrames();
				for (int32 FrameIdx = 0; FrameIdx < NumKeyFrames; FrameIdx++)
				{
					UPaperSprite* FrameSprite = LoadedFlipbook->GetKeyFrameChecked(FrameIdx).Sprite;
					TSharedPtr<FAssetThumbnail> FrameThumbnail;
					if (FrameSprite)
					{
						FAssetData SpriteAssetData(FrameSprite);
						FrameThumbnail = MakeShared<FAssetThumbnail>(SpriteAssetData, 48, 48, ThumbnailPool);
						OverviewThumbnails.Add(FrameThumbnail);
					}

					// Capture sprite as weak pointer for the lambda
					TWeakObjectPtr<UPaperSprite> WeakSprite = FrameSprite;

					FrameSpritesBox->AddSlot()
					.AutoWidth()
					.Padding(2, 0)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.HAlign(HAlign_Center)
						[
							SNew(SBox)
							.WidthOverride(48)
							.HeightOverride(48)
							[
								SNew(SButton)
								.ButtonStyle(FAppStyle::Get(), "NoBorder")
								.IsEnabled(FrameSprite != nullptr)
								.ToolTipText(FrameSprite ? FText::Format(LOCTEXT("OpenSpriteEditor", "Open {0} in Sprite Editor"), FText::FromString(FrameSprite->GetName())) : LOCTEXT("NoSprite", "No sprite"))
								.OnClicked_Lambda([WeakSprite]()
								{
									if (UPaperSprite* Sprite = WeakSprite.Get())
									{
										GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(Sprite);
									}
									return FReply::Handled();
								})
								[
									FrameThumbnail.IsValid()
										? FrameThumbnail->MakeThumbnailWidget()
										: SNew(SBorder)
											.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
											.HAlign(HAlign_Center)
											.VAlign(VAlign_Center)
											[
												SNew(STextBlock)
												.Text(FText::AsNumber(FrameIdx))
												.Font(FCoreStyle::GetDefaultFontStyle("Regular", 8))
											]
								]
							]
						]
						+ SVerticalBox::Slot()
						.AutoHeight()
						.HAlign(HAlign_Center)
						.Padding(0, 2, 0, 0)
						[
							SNew(STextBlock)
							.Text(FText::AsNumber(FrameIdx))
							.Font(FCoreStyle::GetDefaultFontStyle("Regular", 8))
							.ColorAndOpacity(FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f)))
						]
					];
				}
			}
		}

		OverviewAnimationListBox->AddSlot()
		.AutoHeight()
		.Padding(0, 2)
		[
			SNew(SVerticalBox)

			// Main row (clickable to select)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "NoBorder")
				.OnClicked_Lambda([this, AnimIndex]()
				{
					SelectedAnimationIndex = AnimIndex;
					RefreshOverviewAnimationList();
					return FReply::Handled();
				})
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
					.BorderBackgroundColor(bSelected ? FLinearColor(0.2f, 0.4f, 0.8f, 0.3f) : FLinearColor(0.1f, 0.1f, 0.1f, 0.5f))
					.Padding(4)
					[
						SNew(SHorizontalBox)

						// Clickable flipbook thumbnail
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(4, 0)
						[
							SNew(SBox)
							.WidthOverride(64)
							.HeightOverride(64)
							[
								SNew(SButton)
								.ButtonStyle(FAppStyle::Get(), "NoBorder")
								.OnClicked_Lambda([this, AnimIndex]()
								{
									// Open asset picker for flipbooks
									FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

									FAssetPickerConfig PickerConfig;
									PickerConfig.Filter.ClassPaths.Add(UPaperFlipbook::StaticClass()->GetClassPathName());
									PickerConfig.bAllowNullSelection = true;
									PickerConfig.InitialAssetViewType = EAssetViewType::Tile;
									PickerConfig.OnAssetSelected = FOnAssetSelected::CreateLambda([this, AnimIndex](const FAssetData& AssetData)
									{
										if (!Asset.IsValid()) return;
										if (!Asset->Animations.IsValidIndex(AnimIndex)) return;

										BeginTransaction(LOCTEXT("ChangeFlipbookOverview", "Change Flipbook"));
										FAnimationHitboxData& AnimData = Asset->Animations[AnimIndex];
										if (AssetData.IsValid())
										{
											AnimData.Flipbook = TSoftObjectPtr<UPaperFlipbook>(AssetData.ToSoftObjectPath());
										}
										else
										{
											AnimData.Flipbook.Reset();
										}
										EndTransaction();

										// Close the picker menu
										FSlateApplication::Get().DismissAllMenus();
										RefreshOverviewAnimationList();
									});

									// Get current asset for initial selection
									if (Asset.IsValid() && Asset->Animations.IsValidIndex(AnimIndex))
									{
										const FAnimationHitboxData& AnimData = Asset->Animations[AnimIndex];
										if (!AnimData.Flipbook.IsNull())
										{
											PickerConfig.InitialAssetSelection = FAssetData(AnimData.Flipbook.LoadSynchronous());
										}
									}

									FMenuBuilder MenuBuilder(true, nullptr);
									MenuBuilder.BeginSection("FlipbookPicker", LOCTEXT("SelectFlipbook", "Select Flipbook"));
									{
										TSharedRef<SWidget> PickerWidget = ContentBrowserModule.Get().CreateAssetPicker(PickerConfig);
										MenuBuilder.AddWidget(
											SNew(SBox)
											.WidthOverride(400)
											.HeightOverride(500)
											[
												PickerWidget
											],
											FText::GetEmpty(),
											true
										);
									}
									MenuBuilder.EndSection();

									FSlateApplication::Get().PushMenu(
										AsShared(),
										FWidgetPath(),
										MenuBuilder.MakeWidget(),
										FSlateApplication::Get().GetCursorPos(),
										FPopupTransitionEffect::ContextMenu
									);

									return FReply::Handled();
								})
								.ToolTipText(LOCTEXT("ClickToChangeFlipbook", "Click to change flipbook"))
								[
									Thumbnail.IsValid()
										? Thumbnail->MakeThumbnailWidget()
										: SNew(SBorder)
											.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
											.HAlign(HAlign_Center)
											.VAlign(VAlign_Center)
											[
												SNew(STextBlock)
												.Text(LOCTEXT("NoFlipbookIcon", "?"))
												.Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
												.ColorAndOpacity(FSlateColor(FLinearColor(0.4f, 0.4f, 0.4f)))
											]
								]
							]
						]

						// Flipbook name
						+ SHorizontalBox::Slot()
						.FillWidth(0.25f)
						.VAlign(VAlign_Center)
						.Padding(4, 0)
						[
							SNew(STextBlock)
							.Text(FText::FromString(Anim.AnimationName))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
						]

						// Dimensions
						+ SHorizontalBox::Slot()
						.FillWidth(0.12f)
						.VAlign(VAlign_Center)
						.Padding(4, 0)
						[
							SNew(STextBlock)
							.Text(FText::Format(LOCTEXT("DimFormat", "{0}x{1}"),
								FText::AsNumber(Anim.SpriteDimensions.X),
								FText::AsNumber(Anim.SpriteDimensions.Y)))
						]

						// Frame count
						+ SHorizontalBox::Slot()
						.FillWidth(0.12f)
						.VAlign(VAlign_Center)
						.Padding(4, 0)
						[
							SNew(STextBlock)
							.Text(FText::AsNumber(Anim.Frames.Num()))
						]

						// Status
						+ SHorizontalBox::Slot()
						.FillWidth(0.12f)
						.VAlign(VAlign_Center)
						.Padding(4, 0)
						[
							SNew(STextBlock)
							.Text(StatusText)
							.ColorAndOpacity(StatusColor)
						]

						// Actions
						+ SHorizontalBox::Slot()
						.FillWidth(0.3f)
						.VAlign(VAlign_Center)
						.Padding(4, 0)
						[
							SNew(SHorizontalBox)

							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(0, 0, 4, 0)
							[
								SNew(SButton)
								.Text(LOCTEXT("EditHitboxes", "Edit Hitboxes"))
								.OnClicked_Lambda([this, AnimIndex]() {
									OnEditHitboxesClicked(AnimIndex);
									return FReply::Handled();
								})
							]

							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(0, 0, 4, 0)
							[
								SNew(SButton)
								.Text(LOCTEXT("EditAlignment", "Edit Alignment"))
								.OnClicked_Lambda([this, AnimIndex]() {
									OnEditAlignmentClicked(AnimIndex);
									return FReply::Handled();
								})
							]

							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SButton)
								.Text(LOCTEXT("RemoveFlipbookRow", "Remove"))
								.ToolTipText(LOCTEXT("RemoveFlipbookTooltipRow", "Remove this flipbook from the list"))
								.OnClicked_Lambda([this, AnimIndex]() {
									if (!Asset.IsValid()) return FReply::Handled();
									if (Asset->Animations.Num() <= 1)
									{
										FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("CannotRemoveLast", "Cannot remove the last flipbook."));
										return FReply::Handled();
									}

									EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgType::YesNo,
										FText::Format(LOCTEXT("ConfirmRemoveFlipbook", "Are you sure you want to remove '{0}'?"),
											FText::FromString(Asset->Animations[AnimIndex].AnimationName)));

									if (Result == EAppReturnType::Yes)
									{
										BeginTransaction(LOCTEXT("RemoveFlipbookTrans", "Remove Flipbook"));
										Asset->Animations.RemoveAt(AnimIndex);
										if (SelectedAnimationIndex >= Asset->Animations.Num())
										{
											SelectedAnimationIndex = FMath::Max(0, Asset->Animations.Num() - 1);
										}
										EndTransaction();
										RefreshOverviewAnimationList();
									}
									return FReply::Handled();
								})
							]
						]
					]
				]
			]

			// Expandable frame sprites section
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(68, 0, 0, 0) // Indent to align with content after thumbnail
			[
				SNew(SExpandableArea)
				.AreaTitle(LOCTEXT("FrameSpritesTitle", "Frame Sprites"))
				.InitiallyCollapsed(true)
				.BorderImage(FAppStyle::GetBrush("NoBorder"))
				.BodyBorderImage(FAppStyle::GetBrush("NoBorder"))
				.HeaderPadding(FMargin(2, 2))
				.Padding(FMargin(0, 4))
				.BodyContent()
				[
					SNew(SScrollBox)
					.Orientation(Orient_Horizontal)
					+ SScrollBox::Slot()
					[
						FrameSpritesBox
					]
				]
			]
		];
	}

	// Empty state
	if (Asset->Animations.Num() == 0)
	{
		OverviewAnimationListBox->AddSlot()
		.AutoHeight()
		.Padding(8)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("NoFlipbooks", "No flipbooks. Add a flipbook or extract sprites from a texture."))
			.ColorAndOpacity(FSlateColor(FLinearColor(0.5f, 0.5f, 0.5f)))
		];
	}

	// Force thumbnails to render - use deferred tick for initial load
	// The issue is that on first load, widgets aren't attached to a window yet,
	// so thumbnails can't render until the widget is visible.
	// We use a deferred callback to tick the pool on the next frame.
	if (ThumbnailPool.IsValid())
	{
		// Immediate tick for cases where UI is already visible
		ThumbnailPool->Tick(0.016f);
		ThumbnailPool->Tick(0.016f);
		ThumbnailPool->Tick(0.016f);

		// Also schedule a deferred tick for initial load
		TWeakPtr<FAssetThumbnailPool> WeakPool = ThumbnailPool;
		FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([WeakPool](float DeltaTime) -> bool
		{
			if (TSharedPtr<FAssetThumbnailPool> Pool = WeakPool.Pin())
			{
				Pool->Tick(0.016f);
				Pool->Tick(0.016f);
				Pool->Tick(0.016f);
			}
			return false; // Don't repeat
		}), 0.0f);
	}
}

FReply SCharacterDataAssetEditor::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	// Global shortcuts (all tabs)
	if (InKeyEvent.IsControlDown() && InKeyEvent.GetKey() == EKeys::Z)
	{
		GEditor->UndoTransaction();
		RefreshAll();
		return FReply::Handled();
	}

	if (InKeyEvent.IsControlDown() && InKeyEvent.GetKey() == EKeys::Y)
	{
		GEditor->RedoTransaction();
		RefreshAll();
		return FReply::Handled();
	}

	// Alignment Editor Tab shortcuts (ActiveTabIndex == 2)
	if (ActiveTabIndex == 2)
	{
		// Space - toggle playback
		if (InKeyEvent.GetKey() == EKeys::SpaceBar)
		{
			TogglePlayback();
			return FReply::Handled();
		}

		// Left Arrow / Comma - previous frame
		if (InKeyEvent.GetKey() == EKeys::Left || InKeyEvent.GetKey() == EKeys::Comma)
		{
			OnPrevFrameClicked();
			RefreshAlignmentFrameList();
			return FReply::Handled();
		}

		// Right Arrow / Period - next frame
		if (InKeyEvent.GetKey() == EKeys::Right || InKeyEvent.GetKey() == EKeys::Period)
		{
			OnNextFrameClicked();
			RefreshAlignmentFrameList();
			return FReply::Handled();
		}

		// G - toggle grid
		if (InKeyEvent.GetKey() == EKeys::G)
		{
			bShowAlignmentGrid = !bShowAlignmentGrid;
			return FReply::Handled();
		}

		// O - toggle onion skin
		if (InKeyEvent.GetKey() == EKeys::O)
		{
			bShowOnionSkin = !bShowOnionSkin;
			return FReply::Handled();
		}

		return FReply::Unhandled();
	}

	// Hitbox Editor Tab shortcuts (ActiveTabIndex == 1)
	if (ActiveTabIndex == 1)
	{
		if (InKeyEvent.GetKey() == EKeys::D)
		{
			OnToolSelected(EHitboxEditorTool::Draw);
			return FReply::Handled();
		}
		if (InKeyEvent.GetKey() == EKeys::E)
		{
			OnToolSelected(EHitboxEditorTool::Edit);
			return FReply::Handled();
		}
		if (InKeyEvent.GetKey() == EKeys::S && !InKeyEvent.IsControlDown())
		{
			OnToolSelected(EHitboxEditorTool::Socket);
			return FReply::Handled();
		}

		if (InKeyEvent.GetKey() == EKeys::G)
		{
			bShowGrid = !bShowGrid;
			return FReply::Handled();
		}

		if (InKeyEvent.GetKey() == EKeys::Comma)
		{
			OnPrevFrameClicked();
			return FReply::Handled();
		}
		if (InKeyEvent.GetKey() == EKeys::Period)
		{
			OnNextFrameClicked();
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildToolbar()
{
	return SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			[
				SNew(SButton)
				.Text(LOCTEXT("ImportJSON", "Import JSON"))
				.ToolTipText(LOCTEXT("ImportJSONTooltip", "Import character data from JSON, merging with existing flipbooks"))
				.OnClicked_Lambda([this]() { OnImportJsonClicked(); return FReply::Handled(); })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			[
				SNew(SButton)
				.Text(LOCTEXT("Reimport", "Reimport"))
				.ToolTipText(LOCTEXT("ReimportTooltip", "Reimport from previously imported JSON file"))
				.OnClicked_Lambda([this]() { OnReimportClicked(); return FReply::Handled(); })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			[
				SNew(SButton)
				.Text(LOCTEXT("Undo", "Undo"))
				.OnClicked_Lambda([this]()
				{
					GEditor->UndoTransaction();
					RefreshAll();
					return FReply::Handled();
				})
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			[
				SNew(SButton)
				.Text(LOCTEXT("Redo", "Redo"))
				.OnClicked_Lambda([this]()
				{
					GEditor->RedoTransaction();
					RefreshAll();
					return FReply::Handled();
				})
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0)
			[
				SNew(SSeparator)
				.Orientation(Orient_Vertical)
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			.VAlign(VAlign_Center)
			[
				SNew(SCheckBox)
				.IsChecked_Lambda([this]() { return bShowGrid ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState NewState) { bShowGrid = (NewState == ECheckBoxState::Checked); })
				[
					SNew(STextBlock)
					.Text(LOCTEXT("ShowGrid", "Grid (G)"))
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0, 2, 0)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ZoomLabel", "Zoom:"))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			[
				SNew(SBox)
				.WidthOverride(100)
				[
					SNew(SSlider)
					.MinValue(0.5f)
					.MaxValue(4.0f)
					.Value_Lambda([this]() { return ZoomLevel; })
					.OnValueChanged_Lambda([this](float NewValue) { OnZoomChanged(NewValue); })
				]
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text_Lambda([this]() { return FText::Format(LOCTEXT("ZoomPercent", "{0}%"), FText::AsNumber(FMath::RoundToInt(ZoomLevel * 100))); })
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.Padding(20, 0, 0, 0)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Right)
			[
				SNew(STextBlock)
				.Text_Lambda([this]() -> FText
				{
					if (Asset.IsValid() && !Asset->SourceFilePath.IsEmpty())
						return FText::Format(LOCTEXT("SourceInfo", "Source: {0}"), FText::FromString(FPaths::GetCleanFilename(Asset->SourceFilePath)));
					return LOCTEXT("NoSource", "No source file");
				})
				.ColorAndOpacity(FSlateColor(FLinearColor::Gray))
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildToolPanel()
{
	return SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(4)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(2, 2, 2, 6)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Tools", "Tools"))
				.Font(FAppStyle::GetFontStyle("BoldFont"))
			]

			// Tool buttons with icons and clear active states
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(2)
			[
				// Draw tool
				SNew(SBorder)
				.BorderImage_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Draw ? FAppStyle::GetBrush("ToolPanel.DarkGroupBorder") : FAppStyle::GetBrush("NoBorder"); })
				.BorderBackgroundColor_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Draw ? FLinearColor(0.2f, 0.6f, 0.2f, 0.5f) : FLinearColor::Transparent; })
				.Padding(2)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "NoBorder")
					.ToolTipText(LOCTEXT("DrawToolTooltip", "Draw Tool (D)\nClick and drag to create new hitboxes"))
					.OnClicked_Lambda([this]() { OnToolSelected(EHitboxEditorTool::Draw); return FReply::Handled(); })
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(4, 2)
						[
							SNew(SImage)
							.Image(FAppStyle::GetBrush("Icons.Edit"))
							.ColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Draw ? FLinearColor(0.3f, 1.0f, 0.3f) : FLinearColor(0.7f, 0.7f, 0.7f); })
						]
						+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						.VAlign(VAlign_Center)
						.Padding(4, 2)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("DrawToolShort", "Draw"))
							.ColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Draw ? FSlateColor(FLinearColor::White) : FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f)); })
						]
					]
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(2)
			[
				// Edit tool
				SNew(SBorder)
				.BorderImage_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Edit ? FAppStyle::GetBrush("ToolPanel.DarkGroupBorder") : FAppStyle::GetBrush("NoBorder"); })
				.BorderBackgroundColor_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Edit ? FLinearColor(0.2f, 0.4f, 0.8f, 0.5f) : FLinearColor::Transparent; })
				.Padding(2)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "NoBorder")
					.ToolTipText(LOCTEXT("EditToolTooltip", "Edit Tool (E)\nSelect and move existing hitboxes"))
					.OnClicked_Lambda([this]() { OnToolSelected(EHitboxEditorTool::Edit); return FReply::Handled(); })
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(4, 2)
						[
							SNew(SImage)
							.Image(FAppStyle::GetBrush("Icons.Transform"))
							.ColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Edit ? FLinearColor(0.4f, 0.6f, 1.0f) : FLinearColor(0.7f, 0.7f, 0.7f); })
						]
						+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						.VAlign(VAlign_Center)
						.Padding(4, 2)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("EditToolShort", "Edit"))
							.ColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Edit ? FSlateColor(FLinearColor::White) : FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f)); })
						]
					]
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(2)
			[
				// Socket tool
				SNew(SBorder)
				.BorderImage_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Socket ? FAppStyle::GetBrush("ToolPanel.DarkGroupBorder") : FAppStyle::GetBrush("NoBorder"); })
				.BorderBackgroundColor_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Socket ? FLinearColor(0.8f, 0.6f, 0.2f, 0.5f) : FLinearColor::Transparent; })
				.Padding(2)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "NoBorder")
					.ToolTipText(LOCTEXT("SocketToolTooltip", "Socket Tool (S)\nClick to place attachment points"))
					.OnClicked_Lambda([this]() { OnToolSelected(EHitboxEditorTool::Socket); return FReply::Handled(); })
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.Padding(4, 2)
						[
							SNew(SImage)
							.Image(FAppStyle::GetBrush("Icons.Plus"))
							.ColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Socket ? FLinearColor(1.0f, 0.8f, 0.3f) : FLinearColor(0.7f, 0.7f, 0.7f); })
						]
						+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						.VAlign(VAlign_Center)
						.Padding(4, 2)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("SocketToolShort", "Socket"))
							.ColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Socket ? FSlateColor(FLinearColor::White) : FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f)); })
						]
					]
				]
			]
		];
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildAnimationList()
{
	SAssignNew(AnimationListBox, SVerticalBox);

	AnimationListBox->AddSlot()
	.AutoHeight()
	.Padding(4)
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("FlipbooksHeader", "Flipbooks"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("AddFlipbookBtn", "+"))
			.ToolTipText(LOCTEXT("AddFlipbookTooltip", "Add new flipbook"))
			.OnClicked_Lambda([this]() { AddNewAnimation(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("RemoveFlipbookBtn", "-"))
			.ToolTipText(LOCTEXT("RemoveFlipbookTooltip", "Remove selected flipbook"))
			.OnClicked_Lambda([this]() { RemoveSelectedAnimation(); return FReply::Handled(); })
		]
	];

	RefreshAnimationList();

	return SNew(SScrollBox) + SScrollBox::Slot()[AnimationListBox.ToSharedRef()];
}

void SCharacterDataAssetEditor::RefreshAnimationList()
{
	if (!AnimationListBox.IsValid()) return;

	while (AnimationListBox->NumSlots() > 1)
	{
		AnimationListBox->RemoveSlot(AnimationListBox->GetSlot(1).GetWidget());
	}

	if (Asset.IsValid())
	{
		for (int32 i = 0; i < Asset->Animations.Num(); i++)
		{
			const FAnimationHitboxData& Anim = Asset->Animations[i];
			bool bIsSelected = (i == SelectedAnimationIndex);
			bool bHasFlipbook = !Anim.Flipbook.IsNull();

			AnimationListBox->AddSlot()
			.AutoHeight()
			.Padding(2)
			[
				SNew(SButton)
				.ButtonColorAndOpacity(bIsSelected ? FLinearColor(0.2f, 0.4f, 0.8f) : FLinearColor(0.15f, 0.15f, 0.15f))
				.OnClicked_Lambda([this, i]() { OnAnimationSelected(i); return FReply::Handled(); })
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(FText::Format(LOCTEXT("FlipbookListItem", "{0} ({1} frames)"),
							FText::FromString(Anim.AnimationName),
							FText::AsNumber(Anim.Frames.Num())))
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(FText::FromString(bHasFlipbook ? Anim.Flipbook.GetAssetName() : TEXT("No Flipbook Assigned")))
						.Font(FAppStyle::GetFontStyle("SmallFont"))
						.ColorAndOpacity(bHasFlipbook ? FLinearColor(0.4f, 0.8f, 0.4f) : FLinearColor(0.6f, 0.4f, 0.4f))
					]
				]
			];
		}
	}
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildFrameList()
{
	SAssignNew(FrameListBox, SVerticalBox);

	FrameListBox->AddSlot()
	.AutoHeight()
	.Padding(4)
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Frames", "Frames"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("AddFrame", "+"))
			.ToolTipText(LOCTEXT("AddFrameTooltip", "Add new frame"))
			.OnClicked_Lambda([this]() { AddNewFrame(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("RemoveFrame", "-"))
			.ToolTipText(LOCTEXT("RemoveFrameTooltip", "Remove selected frame"))
			.OnClicked_Lambda([this]() { RemoveSelectedFrame(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(4, 0, 0, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("PrevFrame", "<"))
			.ToolTipText(LOCTEXT("PrevFrameTooltip", "Previous frame"))
			.OnClicked_Lambda([this]() { OnPrevFrameClicked(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SButton)
			.Text(LOCTEXT("NextFrame", ">"))
			.ToolTipText(LOCTEXT("NextFrameTooltip", "Next frame"))
			.OnClicked_Lambda([this]() { OnNextFrameClicked(); return FReply::Handled(); })
		]
	];

	RefreshFrameList();

	return SNew(SScrollBox) + SScrollBox::Slot()[FrameListBox.ToSharedRef()];
}

void SCharacterDataAssetEditor::RefreshFrameList()
{
	if (!FrameListBox.IsValid()) return;

	while (FrameListBox->NumSlots() > 1)
	{
		FrameListBox->RemoveSlot(FrameListBox->GetSlot(1).GetWidget());
	}

	// Clear stored thumbnails - they need to persist for widgets to render
	FrameListThumbnails.Empty();

	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (Anim)
	{
		// Get the flipbook to extract frame sprites
		UPaperFlipbook* Flipbook = nullptr;
		if (!Anim->Flipbook.IsNull())
		{
			Flipbook = Anim->Flipbook.LoadSynchronous();
		}

		for (int32 i = 0; i < Anim->Frames.Num(); i++)
		{
			const FFrameHitboxData& Frame = Anim->Frames[i];
			bool bIsSelected = (i == SelectedFrameIndex);

			int32 AttackCount = 0, HurtCount = 0, ColCount = 0;
			for (const FHitboxData& HB : Frame.Hitboxes)
			{
				if (HB.Type == EHitboxType::Attack) AttackCount++;
				else if (HB.Type == EHitboxType::Hurtbox) HurtCount++;
				else ColCount++;
			}

			// Create thumbnail for this frame's sprite and store it persistently
			TSharedPtr<FAssetThumbnail> FrameThumbnail;
			if (Flipbook && i < Flipbook->GetNumKeyFrames())
			{
				UPaperSprite* FrameSprite = Flipbook->GetKeyFrameChecked(i).Sprite;
				if (FrameSprite)
				{
					FAssetData SpriteAssetData(FrameSprite);
					FrameThumbnail = MakeShared<FAssetThumbnail>(SpriteAssetData, 32, 32, ThumbnailPool);
					FrameListThumbnails.Add(FrameThumbnail);
				}
			}

			FrameListBox->AddSlot()
			.AutoHeight()
			.Padding(1)
			[
				SNew(SButton)
				.ButtonColorAndOpacity(bIsSelected ? FLinearColor(0.2f, 0.6f, 0.3f) : FLinearColor(0.12f, 0.12f, 0.12f))
				.OnClicked_Lambda([this, i]() { OnFrameSelected(i); return FReply::Handled(); })
				[
					SNew(SHorizontalBox)
					// Sprite thumbnail
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(2)
					[
						SNew(SBox)
						.WidthOverride(32)
						.HeightOverride(32)
						[
							FrameThumbnail.IsValid()
								? FrameThumbnail->MakeThumbnailWidget()
								: SNew(SBorder)
									.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									[
										SNew(STextBlock)
										.Text(FText::AsNumber(i))
										.Font(FCoreStyle::GetDefaultFontStyle("Regular", 9))
									]
						]
					]
					// Frame number
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(4, 0, 8, 0)
					[
						SNew(STextBlock)
						.Text(FText::AsNumber(i))
						.Font(FAppStyle::GetFontStyle("BoldFont"))
					]
					// Hitbox indicators with colored dots
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					.VAlign(VAlign_Center)
					[
						SNew(SHorizontalBox)
						// Attack count (red dot)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(0, 0, 6, 0)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							[
								SNew(SBox)
								.WidthOverride(8)
								.HeightOverride(8)
								[
									SNew(SImage)
									.Image(FAppStyle::GetBrush("Icons.FilledCircle"))
									.ColorAndOpacity(FLinearColor(0.9f, 0.2f, 0.2f))
								]
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							.Padding(2, 0, 0, 0)
							[
								SNew(STextBlock)
								.Text(FText::AsNumber(AttackCount))
								.Font(FAppStyle::GetFontStyle("SmallFont"))
								.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
							]
						]
						// Hurtbox count (green dot)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(0, 0, 6, 0)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							[
								SNew(SBox)
								.WidthOverride(8)
								.HeightOverride(8)
								[
									SNew(SImage)
									.Image(FAppStyle::GetBrush("Icons.FilledCircle"))
									.ColorAndOpacity(FLinearColor(0.2f, 0.8f, 0.2f))
								]
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							.Padding(2, 0, 0, 0)
							[
								SNew(STextBlock)
								.Text(FText::AsNumber(HurtCount))
								.Font(FAppStyle::GetFontStyle("SmallFont"))
								.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
							]
						]
						// Collision count (blue dot)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(0, 0, 6, 0)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							[
								SNew(SBox)
								.WidthOverride(8)
								.HeightOverride(8)
								[
									SNew(SImage)
									.Image(FAppStyle::GetBrush("Icons.FilledCircle"))
									.ColorAndOpacity(FLinearColor(0.3f, 0.5f, 0.9f))
								]
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							.Padding(2, 0, 0, 0)
							[
								SNew(STextBlock)
								.Text(FText::AsNumber(ColCount))
								.Font(FAppStyle::GetFontStyle("SmallFont"))
								.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
							]
						]
						// Socket count (yellow dot)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							[
								SNew(SBox)
								.WidthOverride(8)
								.HeightOverride(8)
								[
									SNew(SImage)
									.Image(FAppStyle::GetBrush("Icons.FilledCircle"))
									.ColorAndOpacity(FLinearColor(0.9f, 0.8f, 0.2f))
								]
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							.Padding(2, 0, 0, 0)
							[
								SNew(STextBlock)
								.Text(FText::AsNumber(Frame.Sockets.Num()))
								.Font(FAppStyle::GetFontStyle("SmallFont"))
								.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
							]
						]
					]
				]
			];
		}

		// Force thumbnails to render immediately
		if (ThumbnailPool.IsValid())
		{
			ThumbnailPool->Tick(0);
		}
	}
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildCanvasArea()
{
	TSharedRef<SVerticalBox> CanvasArea = SNew(SVerticalBox)
		// Current flipbook header
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(4, 4, 4, 0)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
			.Padding(FMargin(8, 4))
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("EditingFlipbook", "EDITING:"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
					.ColorAndOpacity(FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f)))
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(8, 0, 0, 0)
				[
					SNew(STextBlock)
					.Text_Lambda([this]() {
						const FAnimationHitboxData* Anim = GetCurrentAnimation();
						return Anim ? FText::FromString(Anim->AnimationName) : LOCTEXT("NoFlipbookSelected", "No Flipbook Selected");
					})
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
					.ColorAndOpacity_Lambda([this]() {
						const FAnimationHitboxData* Anim = GetCurrentAnimation();
						return FSlateColor(Anim && !Anim->Flipbook.IsNull() ? FLinearColor::White : FLinearColor(0.8f, 0.4f, 0.4f));
					})
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(12, 0, 0, 0)
				[
					SNew(STextBlock)
					.Text_Lambda([this]() {
						const FAnimationHitboxData* Anim = GetCurrentAnimation();
						if (Anim && Anim->Frames.Num() > 0)
						{
							return FText::Format(LOCTEXT("FrameInfo", "Frame {0} of {1}"),
								FText::AsNumber(SelectedFrameIndex + 1),
								FText::AsNumber(Anim->Frames.Num()));
						}
						return LOCTEXT("NoFrames", "No Frames");
					})
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 10))
					.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
				]

				// Spacer to push 2D/3D toggle to the right
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNullWidget::NullWidget
				]

				// 2D/3D View Toggle
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(8, 0, 0, 0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SCheckBox)
						.Style(FAppStyle::Get(), "ToggleButtonCheckbox")
						.IsChecked_Lambda([this]() { return bShow3DView ? ECheckBoxState::Unchecked : ECheckBoxState::Checked; })
						.OnCheckStateChanged_Lambda([this](ECheckBoxState NewState)
						{
							bShow3DView = false;
							if (CanvasViewSwitcher.IsValid())
							{
								CanvasViewSwitcher->SetActiveWidgetIndex(0);
							}
						})
						.ToolTipText(LOCTEXT("View2DTooltip", "2D View\nStandard top-down view for editing hitboxes"))
						[
							SNew(STextBlock)
							.Text(LOCTEXT("View2D", "2D"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						]
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(2, 0, 0, 0)
					[
						SNew(SCheckBox)
						.Style(FAppStyle::Get(), "ToggleButtonCheckbox")
						.IsChecked_Lambda([this]() { return bShow3DView ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
						.OnCheckStateChanged_Lambda([this](ECheckBoxState NewState)
						{
							bShow3DView = true;
							if (CanvasViewSwitcher.IsValid())
							{
								CanvasViewSwitcher->SetActiveWidgetIndex(1);
							}
						})
						.ToolTipText(LOCTEXT("View3DTooltip", "3D View\nPerspective view to visualize hitbox depth (Z and Depth values)\nDrag to rotate, scroll to zoom"))
						[
							SNew(STextBlock)
							.Text(LOCTEXT("View3D", "3D"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						]
					]
				]
			]
		]

		// Flipbook selector
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(4)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("FlipbookAssetLabel", "Flipbook Asset:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SObjectPropertyEntryBox)
				.AllowedClass(UPaperFlipbook::StaticClass())
				.ObjectPath_Lambda([this]() -> FString
				{
					const FAnimationHitboxData* Anim = GetCurrentAnimation();
					if (Anim && !Anim->Flipbook.IsNull())
					{
						return Anim->Flipbook.ToSoftObjectPath().ToString();
					}
					return FString();
				})
				.OnObjectChanged_Lambda([this](const FAssetData& AssetData)
				{
					if (!Asset.IsValid()) return;
					if (!Asset->Animations.IsValidIndex(SelectedAnimationIndex)) return;

					BeginTransaction(LOCTEXT("ChangeFlipbook", "Change Flipbook"));
					FAnimationHitboxData& Anim = Asset->Animations[SelectedAnimationIndex];
					if (AssetData.IsValid())
					{
						Anim.Flipbook = TSoftObjectPtr<UPaperFlipbook>(AssetData.ToSoftObjectPath());
					}
					else
					{
						Anim.Flipbook.Reset();
					}
					EndTransaction();
					RefreshAnimationList();
				})
				.DisplayThumbnail(true)
			]
		]

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(4)
		[
			SAssignNew(CanvasViewSwitcher, SWidgetSwitcher)
			.WidgetIndex_Lambda([this]() { return bShow3DView ? 1 : 0; })

			// Slot 0: 2D Canvas (default)
			+ SWidgetSwitcher::Slot()
			[
				SAssignNew(EditorCanvas, SCharacterDataEditorCanvas)
				.Asset(Asset)
				.SelectedAnimationIndex_Lambda([this]() { return SelectedAnimationIndex; })
				.SelectedFrameIndex_Lambda([this]() { return SelectedFrameIndex; })
				.CurrentTool_Lambda([this]() { return CurrentTool; })
				.ShowGrid_Lambda([this]() { return bShowGrid; })
				.Zoom_Lambda([this]() { return ZoomLevel; })
			]

			// Slot 1: 3D Viewport (Unreal's built-in viewport system)
			+ SWidgetSwitcher::Slot()
			[
				SAssignNew(Viewport3D, SHitbox3DViewport)
				.Asset(Asset)
			]
		];

	// Update 3D viewport with initial frame data
	if (Viewport3D.IsValid())
	{
		const FFrameHitboxData* Frame = GetCurrentFrame();
		Viewport3D->SetFrameData(Frame);
	}

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->OnSelectionChanged.BindLambda([this](EHitboxSelectionType Type, int32 Index)
		{
			OnSelectionChanged(Type, Index);
		});

		EditorCanvas->OnHitboxDataModified.BindLambda([this]()
		{
			OnHitboxDataModified();
		});

		EditorCanvas->OnRequestUndo.BindLambda([this]()
		{
			BeginTransaction(LOCTEXT("ModifyHitbox", "Modify Hitbox"));
		});

		EditorCanvas->OnEndTransaction.BindLambda([this]()
		{
			EndTransaction();
		});
	}

	return CanvasArea;
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildHitboxList()
{
	SAssignNew(HitboxListBox, SVerticalBox);

	HitboxListBox->AddSlot()
	.AutoHeight()
	.Padding(4)
	[
		SNew(SVerticalBox)

		// Header row with title
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("HitboxesSockets", "Hitboxes & Sockets"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]

		// Action buttons row
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)

			// Add Hitbox button
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 4, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.ToolTipText(LOCTEXT("AddHitboxTooltip", "Add Hitbox\nCreate a new hitbox on this frame"))
				.OnClicked_Lambda([this]() { AddNewHitbox(); return FReply::Handled(); })
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("Icons.PlusCircle"))
						.ColorAndOpacity(FLinearColor(0.3f, 0.8f, 0.3f))
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(4, 0, 0, 0)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("HitboxLabel", "Hitbox"))
						.Font(FAppStyle::GetFontStyle("SmallFont"))
					]
				]
			]

			// Add Socket button
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 4, 0)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.ToolTipText(LOCTEXT("AddSocketTooltip", "Add Socket\nCreate a new attachment point on this frame"))
				.OnClicked_Lambda([this]() { AddNewSocket(); return FReply::Handled(); })
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("Icons.Plus"))
						.ColorAndOpacity(FLinearColor(0.8f, 0.6f, 0.2f))
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(4, 0, 0, 0)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("SocketLabel", "Socket"))
						.Font(FAppStyle::GetFontStyle("SmallFont"))
					]
				]
			]

			// Spacer
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNullWidget::NullWidget
			]

			// Delete button
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.ToolTipText(LOCTEXT("DeleteSelectedTooltip", "Delete Selected\nRemove the selected hitbox or socket"))
				.OnClicked_Lambda([this]() { DeleteSelected(); return FReply::Handled(); })
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.Delete"))
					.ColorAndOpacity(FLinearColor(0.8f, 0.3f, 0.3f))
				]
			]
		]
	];

	RefreshHitboxList();

	return SNew(SScrollBox) + SScrollBox::Slot()[HitboxListBox.ToSharedRef()];
}

void SCharacterDataAssetEditor::RefreshHitboxList()
{
	if (!HitboxListBox.IsValid()) return;

	while (HitboxListBox->NumSlots() > 1)
	{
		HitboxListBox->RemoveSlot(HitboxListBox->GetSlot(1).GetWidget());
	}

	const FFrameHitboxData* Frame = GetCurrentFrame();
	if (!Frame) return;

	for (int32 i = 0; i < Frame->Hitboxes.Num(); i++)
	{
		const FHitboxData& HB = Frame->Hitboxes[i];
		bool bIsSelected = EditorCanvas.IsValid() &&
			EditorCanvas->GetSelectionType() == EHitboxSelectionType::Hitbox &&
			EditorCanvas->GetSelectedIndex() == i;

		FString TypeStr = HB.Type == EHitboxType::Attack ? TEXT("ATK") :
						  HB.Type == EHitboxType::Hurtbox ? TEXT("HRT") : TEXT("COL");
		FLinearColor TypeColor = HB.Type == EHitboxType::Attack ? FLinearColor::Red :
								 HB.Type == EHitboxType::Hurtbox ? FLinearColor::Green : FLinearColor::Blue;

		HitboxListBox->AddSlot()
		.AutoHeight()
		.Padding(1)
		[
			SNew(SButton)
			.ButtonColorAndOpacity(bIsSelected ? TypeColor * 0.5f : FLinearColor(0.1f, 0.1f, 0.1f))
			.OnClicked_Lambda([this, i]()
			{
				if (EditorCanvas.IsValid())
				{
					EditorCanvas->SetSelection(EHitboxSelectionType::Hitbox, i);
				}
				return FReply::Handled();
			})
			[
				SNew(STextBlock)
				.Text(FText::Format(LOCTEXT("HitboxListItem", "[{0}] {1} ({2},{3}) {4}x{5}"),
					FText::AsNumber(i),
					FText::FromString(TypeStr),
					FText::AsNumber(HB.X),
					FText::AsNumber(HB.Y),
					FText::AsNumber(HB.Width),
					FText::AsNumber(HB.Height)))
				.ColorAndOpacity(FSlateColor(TypeColor))
				.Font(FAppStyle::GetFontStyle("SmallFont"))
			]
		];
	}

	for (int32 i = 0; i < Frame->Sockets.Num(); i++)
	{
		const FSocketData& Sock = Frame->Sockets[i];
		bool bIsSelected = EditorCanvas.IsValid() &&
			EditorCanvas->GetSelectionType() == EHitboxSelectionType::Socket &&
			EditorCanvas->GetSelectedIndex() == i;

		HitboxListBox->AddSlot()
		.AutoHeight()
		.Padding(1)
		[
			SNew(SButton)
			.ButtonColorAndOpacity(bIsSelected ? FLinearColor(0.4f, 0.4f, 0.0f) : FLinearColor(0.1f, 0.1f, 0.1f))
			.OnClicked_Lambda([this, i]()
			{
				if (EditorCanvas.IsValid())
				{
					EditorCanvas->SetSelection(EHitboxSelectionType::Socket, i);
				}
				return FReply::Handled();
			})
			[
				SNew(STextBlock)
				.Text(FText::Format(LOCTEXT("SocketListItem", "[S] {0} ({1},{2})"),
					FText::FromString(Sock.Name),
					FText::AsNumber(Sock.X),
					FText::AsNumber(Sock.Y)))
				.ColorAndOpacity(FSlateColor(FLinearColor::Yellow))
				.Font(FAppStyle::GetFontStyle("SmallFont"))
			]
		];
	}
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildPropertiesPanel()
{
	SAssignNew(PropertiesBox, SVerticalBox);

	PropertiesBox->AddSlot()
	.AutoHeight()
	.Padding(4)
	[
		SNew(STextBlock)
		.Text(LOCTEXT("Properties", "Properties"))
		.Font(FAppStyle::GetFontStyle("BoldFont"))
	];

	RefreshPropertiesPanel();

	return SNew(SScrollBox) + SScrollBox::Slot()[PropertiesBox.ToSharedRef()];
}

void SCharacterDataAssetEditor::RefreshPropertiesPanel()
{
	if (!PropertiesBox.IsValid()) return;

	while (PropertiesBox->NumSlots() > 1)
	{
		PropertiesBox->RemoveSlot(PropertiesBox->GetSlot(1).GetWidget());
	}

	if (!EditorCanvas.IsValid()) return;

	EHitboxSelectionType SelType = EditorCanvas->GetSelectionType();
	int32 SelIndex = EditorCanvas->GetSelectedIndex();

	if (SelType == EHitboxSelectionType::None)
	{
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("NoSelection", "No selection"))
			.ColorAndOpacity(FSlateColor(FLinearColor::Gray))
		];
		return;
	}

	FFrameHitboxData* Frame = GetCurrentFrameMutable();
	if (!Frame) return;

	if (SelType == EHitboxSelectionType::Hitbox && Frame->Hitboxes.IsValidIndex(SelIndex))
	{
		// Type selector
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("TypeLabel", "Type:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SButton)
					.Text(LOCTEXT("AttackType", "Attack"))
					.ButtonColorAndOpacity_Lambda([this, SelIndex]()
					{
						FFrameHitboxData* F = GetCurrentFrameMutable();
						return (F && F->Hitboxes.IsValidIndex(SelIndex) && F->Hitboxes[SelIndex].Type == EHitboxType::Attack)
							? FLinearColor::Red * 0.5f : FLinearColor(0.15f, 0.15f, 0.15f);
					})
					.OnClicked_Lambda([this, SelIndex]()
					{
						if (FFrameHitboxData* F = GetCurrentFrameMutable())
						{
							if (F->Hitboxes.IsValidIndex(SelIndex))
							{
								BeginTransaction(LOCTEXT("ChangeType", "Change Hitbox Type"));
								F->Hitboxes[SelIndex].Type = EHitboxType::Attack;
								EndTransaction();
								RefreshHitboxList();
							}
						}
						return FReply::Handled();
					})
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SButton)
					.Text(LOCTEXT("HurtboxType", "Hurtbox"))
					.ButtonColorAndOpacity_Lambda([this, SelIndex]()
					{
						FFrameHitboxData* F = GetCurrentFrameMutable();
						return (F && F->Hitboxes.IsValidIndex(SelIndex) && F->Hitboxes[SelIndex].Type == EHitboxType::Hurtbox)
							? FLinearColor::Green * 0.5f : FLinearColor(0.15f, 0.15f, 0.15f);
					})
					.OnClicked_Lambda([this, SelIndex]()
					{
						if (FFrameHitboxData* F = GetCurrentFrameMutable())
						{
							if (F->Hitboxes.IsValidIndex(SelIndex))
							{
								BeginTransaction(LOCTEXT("ChangeType", "Change Hitbox Type"));
								F->Hitboxes[SelIndex].Type = EHitboxType::Hurtbox;
								EndTransaction();
								RefreshHitboxList();
							}
						}
						return FReply::Handled();
					})
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SButton)
					.Text(LOCTEXT("CollisionType", "Collision"))
					.ButtonColorAndOpacity_Lambda([this, SelIndex]()
					{
						FFrameHitboxData* F = GetCurrentFrameMutable();
						return (F && F->Hitboxes.IsValidIndex(SelIndex) && F->Hitboxes[SelIndex].Type == EHitboxType::Collision)
							? FLinearColor::Blue * 0.5f : FLinearColor(0.15f, 0.15f, 0.15f);
					})
					.OnClicked_Lambda([this, SelIndex]()
					{
						if (FFrameHitboxData* F = GetCurrentFrameMutable())
						{
							if (F->Hitboxes.IsValidIndex(SelIndex))
							{
								BeginTransaction(LOCTEXT("ChangeType", "Change Hitbox Type"));
								F->Hitboxes[SelIndex].Type = EHitboxType::Collision;
								EndTransaction();
								RefreshHitboxList();
							}
						}
						return FReply::Handled();
					})
				]
			]
		];

		// Position
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("PosLabel", "Pos:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(-9999).MaxValue(9999)
				.MinSliderValue(-500).MaxSliderValue(500)
				.Delta(1)
				.SliderExponent(1.0f)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].X : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("MoveHitbox", "Move Hitbox"));
							F->Hitboxes[SelIndex].X = Val;
							EndTransaction();
						}
					}
				})
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(-9999).MaxValue(9999)
				.MinSliderValue(-500).MaxSliderValue(500)
				.Delta(1)
				.SliderExponent(1.0f)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Y : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("MoveHitbox", "Move Hitbox"));
							F->Hitboxes[SelIndex].Y = Val;
							EndTransaction();
						}
					}
				})
			]
		];

		// Size
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("SizeLabel", "Size:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(1).MaxValue(9999)
				.MinSliderValue(1).MaxSliderValue(500)
				.Delta(1)
				.SliderExponent(1.0f)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Width : 16;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("ResizeHitbox", "Resize Hitbox"));
							F->Hitboxes[SelIndex].Width = Val;
							EndTransaction();
						}
					}
				})
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(1).MaxValue(9999)
				.MinSliderValue(1).MaxSliderValue(500)
				.Delta(1)
				.SliderExponent(1.0f)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Height : 16;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("ResizeHitbox", "Resize Hitbox"));
							F->Hitboxes[SelIndex].Height = Val;
							EndTransaction();
						}
					}
				})
			]
		];

		// Z Position (Depth offset)
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("ZPosLabel", "Z Pos:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(-9999).MaxValue(9999)
				.MinSliderValue(-200).MaxSliderValue(200)
				.Delta(1)
				.SliderExponent(1.0f)
				.ToolTipText(LOCTEXT("ZPosTooltip", "Z position (depth offset) for 2.5D collision"))
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Z : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("ChangeZPos", "Change Z Position"));
							F->Hitboxes[SelIndex].Z = Val;
							EndTransaction();
						}
					}
				})
			]
		];

		// Depth (thickness in Z)
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("DepthLabel", "Depth:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(0).MaxValue(9999)
				.MinSliderValue(0).MaxSliderValue(200)
				.Delta(1)
				.SliderExponent(1.0f)
				.ToolTipText(LOCTEXT("DepthTooltip", "Depth (thickness in Z axis) for 2.5D collision. 0 = use default."))
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Depth : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("ChangeDepth", "Change Depth"));
							F->Hitboxes[SelIndex].Depth = Val;
							EndTransaction();
						}
					}
				})
			]
		];

		// Damage
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("DamageLabel", "Damage:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(0).MaxValue(9999)
				.MinSliderValue(0).MaxSliderValue(200)
				.Delta(1)
				.SliderExponent(1.0f)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Damage : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("ChangeDamage", "Change Damage"));
							F->Hitboxes[SelIndex].Damage = Val;
							EndTransaction();
						}
					}
				})
			]
		];

		// Knockback
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("KnockbackLabel", "Knockback:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(0).MaxValue(9999)
				.MinSliderValue(0).MaxSliderValue(200)
				.Delta(1)
				.SliderExponent(1.0f)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Hitboxes.IsValidIndex(SelIndex)) ? F->Hitboxes[SelIndex].Knockback : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Hitboxes.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("ChangeKnockback", "Change Knockback"));
							F->Hitboxes[SelIndex].Knockback = Val;
							EndTransaction();
						}
					}
				})
			]
		];
	}
	else if (SelType == EHitboxSelectionType::Socket && Frame->Sockets.IsValidIndex(SelIndex))
	{
		// Name
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("NameLabel", "Name:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SEditableTextBox)
				.Text_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Sockets.IsValidIndex(SelIndex)) ? FText::FromString(F->Sockets[SelIndex].Name) : FText();
				})
				.OnTextCommitted_Lambda([this, SelIndex](const FText& Text, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Sockets.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("RenameSocket", "Rename Socket"));
							F->Sockets[SelIndex].Name = Text.ToString();
							EndTransaction();
							RefreshHitboxList();
						}
					}
				})
			]
		];

		// Position
		PropertiesBox->AddSlot()
		.AutoHeight()
		.Padding(4, 2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock).Text(LOCTEXT("PosLabel", "Pos:"))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(-9999).MaxValue(9999)
				.MinSliderValue(-500).MaxSliderValue(500)
				.Delta(1)
				.SliderExponent(1.0f)
				.LinearDeltaSensitivity(1)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Sockets.IsValidIndex(SelIndex)) ? F->Sockets[SelIndex].X : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Sockets.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("MoveSocket", "Move Socket"));
							F->Sockets[SelIndex].X = Val;
							EndTransaction();
						}
					}
				})
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SSpinBox<int32>)
				.MinValue(-9999).MaxValue(9999)
				.MinSliderValue(-500).MaxSliderValue(500)
				.Delta(1)
				.SliderExponent(1.0f)
				.LinearDeltaSensitivity(1)
				.Value_Lambda([this, SelIndex]() {
					FFrameHitboxData* F = GetCurrentFrameMutable();
					return (F && F->Sockets.IsValidIndex(SelIndex)) ? F->Sockets[SelIndex].Y : 0;
				})
				.OnValueCommitted_Lambda([this, SelIndex](int32 Val, ETextCommit::Type) {
					if (FFrameHitboxData* F = GetCurrentFrameMutable())
					{
						if (F->Sockets.IsValidIndex(SelIndex))
						{
							BeginTransaction(LOCTEXT("MoveSocket", "Move Socket"));
							F->Sockets[SelIndex].Y = Val;
							EndTransaction();
						}
					}
				})
			]
		];
	}
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildCopyOperationsPanel()
{
	return SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(4, 4, 4, 8)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("CopyOperations", "Frame Operations"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]

		// Copy from Previous
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.ToolTipText(LOCTEXT("CopyFromPrevTooltip", "Copy hitboxes and sockets from the previous frame to this frame"))
			.OnClicked_Lambda([this]() { OnCopyFromPrevious(); return FReply::Handled(); })
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.Import"))
					.ColorAndOpacity(FLinearColor(0.6f, 0.8f, 1.0f))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CopyFromPrevShort", "Copy from Previous"))
				]
			]
		]

		// Copy to All Frames
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.ToolTipText(LOCTEXT("CopyToAllTooltip", "Copy all hitboxes and sockets from this frame to all other frames in this flipbook"))
			.OnClicked_Lambda([this]() { OnPropagateAllToGroup(); return FReply::Handled(); })
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.Duplicate"))
					.ColorAndOpacity(FLinearColor(0.8f, 0.8f, 0.5f))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CopyToAllShort", "Copy to All Frames"))
				]
			]
		]

		// Copy Selected to All Frames
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.ToolTipText(LOCTEXT("CopySelectedToAllTooltip", "Copy the selected hitbox/socket from this frame to all other frames in this flipbook"))
			.OnClicked_Lambda([this]() { OnPropagateSelectedToGroup(); return FReply::Handled(); })
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.SelectInViewport"))
					.ColorAndOpacity(FLinearColor(0.5f, 0.8f, 0.5f))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CopySelectedShort", "Copy Selected to All"))
				]
			]
		]

		// Clear Frame
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2, 8, 2, 2)
		[
			SNew(SButton)
			.ToolTipText(LOCTEXT("ClearFrameTooltip", "Remove all hitboxes and sockets from this frame"))
			.OnClicked_Lambda([this]() { OnClearCurrentFrame(); return FReply::Handled(); })
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.Delete"))
					.ColorAndOpacity(FLinearColor(1.0f, 0.5f, 0.5f))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.Padding(4, 2)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("ClearFrameShort", "Clear Frame"))
				]
			]
		];
}

void SCharacterDataAssetEditor::RefreshAll()
{
	RefreshAnimationList();
	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();
	RefreshOverviewAnimationList();
}

void SCharacterDataAssetEditor::OnAnimationSelected(int32 Index)
{
	SelectedAnimationIndex = Index;
	SelectedFrameIndex = 0;
	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}
	RefreshAll();
}

void SCharacterDataAssetEditor::OnFrameSelected(int32 Index)
{
	SelectedFrameIndex = Index;
	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}
	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();

	// Update 3D viewport with new frame data
	if (Viewport3D.IsValid())
	{
		const FFrameHitboxData* Frame = GetCurrentFrame();
		Viewport3D->SetFrameData(Frame);
		Viewport3D->SetSelectedHitbox(-1);
		Viewport3D->SetSelectedSocket(-1);
	}
}

void SCharacterDataAssetEditor::OnToolSelected(EHitboxEditorTool Tool)
{
	CurrentTool = Tool;
}

void SCharacterDataAssetEditor::OnSelectionChanged(EHitboxSelectionType Type, int32 Index)
{
	RefreshHitboxList();
	RefreshPropertiesPanel();

	// Update 3D viewport selection
	if (Viewport3D.IsValid())
	{
		if (Type == EHitboxSelectionType::Hitbox)
		{
			Viewport3D->SetSelectedHitbox(Index);
			Viewport3D->SetSelectedSocket(-1);
		}
		else if (Type == EHitboxSelectionType::Socket)
		{
			Viewport3D->SetSelectedHitbox(-1);
			Viewport3D->SetSelectedSocket(Index);
		}
		else
		{
			Viewport3D->SetSelectedHitbox(-1);
			Viewport3D->SetSelectedSocket(-1);
		}
	}
}

void SCharacterDataAssetEditor::OnHitboxDataModified()
{
	if (Asset.IsValid())
	{
		Asset->MarkPackageDirty();
	}
	RefreshHitboxList();

	// Refresh 3D viewport
	if (Viewport3D.IsValid())
	{
		const FFrameHitboxData* Frame = GetCurrentFrame();
		Viewport3D->SetFrameData(Frame);
	}
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::OnImportJsonClicked()
{
	if (!Asset.IsValid()) return;

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (!DesktopPlatform) return;

	TArray<FString> OutFiles;
	const FString DefaultPath = Asset->SourceFilePath.IsEmpty() ? FPaths::ProjectContentDir() : FPaths::GetPath(Asset->SourceFilePath);
	const FString FileTypes = TEXT("JSON Files (*.json)|*.json");

	void* ParentWindowHandle = FSlateApplication::Get().GetActiveTopLevelWindow().IsValid()
		? FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow()->GetOSWindowHandle()
		: nullptr;

	bool bOpened = DesktopPlatform->OpenFileDialog(
		ParentWindowHandle,
		TEXT("Select Character Data JSON File"),
		DefaultPath,
		TEXT(""),
		FileTypes,
		EFileDialogFlags::None,
		OutFiles
	);

	if (!bOpened || OutFiles.Num() == 0) return;

	const FString& JsonFilePath = OutFiles[0];

	TArray<FAnimationHitboxData> ImportedAnimations;
	FString ErrorMessage;
	if (!FCharacterDataJsonImporter::ParseJsonToCharacterData(
		[&JsonFilePath]() { FString Content; FFileHelper::LoadFileToString(Content, *JsonFilePath); return Content; }(),
		ImportedAnimations, ErrorMessage))
	{
		FMessageDialog::Open(EAppMsgType::Ok,
			FText::Format(LOCTEXT("ImportParseFailed", "Failed to parse JSON: {0}"), FText::FromString(ErrorMessage)));
		return;
	}

	BeginTransaction(LOCTEXT("ImportJsonMerge", "Import JSON (Merge)"));

	int32 AnimsMatched = 0;
	int32 FramesMatched = 0;
	int32 HitboxesAdded = 0;
	int32 SocketsAdded = 0;

	for (const FAnimationHitboxData& ImportedAnim : ImportedAnimations)
	{
		FAnimationHitboxData* MatchingAnim = nullptr;
		for (FAnimationHitboxData& ExistingAnim : Asset->Animations)
		{
			if (ExistingAnim.AnimationName.Equals(ImportedAnim.AnimationName, ESearchCase::IgnoreCase))
			{
				MatchingAnim = &ExistingAnim;
				AnimsMatched++;
				break;
			}
		}

		if (!MatchingAnim) continue;

		for (int32 FrameIdx = 0; FrameIdx < ImportedAnim.Frames.Num(); FrameIdx++)
		{
			const FFrameHitboxData& ImportedFrame = ImportedAnim.Frames[FrameIdx];

			FFrameHitboxData* MatchingFrame = nullptr;
			if (MatchingAnim->Frames.IsValidIndex(FrameIdx))
			{
				MatchingFrame = &MatchingAnim->Frames[FrameIdx];
				FramesMatched++;
			}
			else
			{
				for (FFrameHitboxData& ExistingFrame : MatchingAnim->Frames)
				{
					if (ExistingFrame.FrameName.Equals(ImportedFrame.FrameName, ESearchCase::IgnoreCase))
					{
						MatchingFrame = &ExistingFrame;
						FramesMatched++;
						break;
					}
				}
			}

			if (!MatchingFrame) continue;

			MatchingFrame->Hitboxes = ImportedFrame.Hitboxes;
			HitboxesAdded += ImportedFrame.Hitboxes.Num();

			MatchingFrame->Sockets = ImportedFrame.Sockets;
			SocketsAdded += ImportedFrame.Sockets.Num();
		}
	}

	Asset->SourceFilePath = JsonFilePath;
	Asset->LastImportTime = FDateTime::Now();

	EndTransaction();

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}
	RefreshAll();

	FMessageDialog::Open(EAppMsgType::Ok,
		FText::Format(LOCTEXT("ImportMergeSuccess", "Import complete!\n\nFlipbooks matched: {0}\nFrames matched: {1}\nHitboxes imported: {2}\nSockets imported: {3}"),
			FText::AsNumber(AnimsMatched),
			FText::AsNumber(FramesMatched),
			FText::AsNumber(HitboxesAdded),
			FText::AsNumber(SocketsAdded)));
}

void SCharacterDataAssetEditor::OnReimportClicked()
{
	if (Asset.IsValid())
	{
		if (Asset->SourceFilePath.IsEmpty())
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("NoSourcePath", "No source JSON file path stored. Use 'Import JSON' first."));
			return;
		}

		FString ErrorMessage;
		if (FCharacterDataJsonImporter::ReimportAsset(Asset.Get(), ErrorMessage))
		{
			SelectedAnimationIndex = 0;
			SelectedFrameIndex = 0;
			if (EditorCanvas.IsValid())
			{
				EditorCanvas->ClearSelection();
			}
			RefreshAll();
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ReimportSuccess", "Reimport successful!"));
		}
		else
		{
			FMessageDialog::Open(EAppMsgType::Ok,
				FText::Format(LOCTEXT("ReimportFailed", "Reimport failed: {0}"), FText::FromString(ErrorMessage)));
		}
	}
}

void SCharacterDataAssetEditor::OnZoomChanged(float NewZoom)
{
	ZoomLevel = NewZoom;
}

void SCharacterDataAssetEditor::OnPrevFrameClicked()
{
	if (SelectedFrameIndex > 0)
	{
		SelectedFrameIndex--;
		if (EditorCanvas.IsValid())
		{
			EditorCanvas->ClearSelection();
		}
		RefreshFrameList();
		RefreshHitboxList();
		RefreshPropertiesPanel();
	}
}

void SCharacterDataAssetEditor::OnNextFrameClicked()
{
	int32 FrameCount = GetCurrentFrameCount();
	if (SelectedFrameIndex < FrameCount - 1)
	{
		SelectedFrameIndex++;
		if (EditorCanvas.IsValid())
		{
			EditorCanvas->ClearSelection();
		}
		RefreshFrameList();
		RefreshHitboxList();
		RefreshPropertiesPanel();
	}
}

void SCharacterDataAssetEditor::OnCopyFromPrevious()
{
	if (SelectedFrameIndex <= 0) return;

	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim) return;

	if (!Anim->Frames.IsValidIndex(SelectedFrameIndex) || !Anim->Frames.IsValidIndex(SelectedFrameIndex - 1)) return;

	BeginTransaction(LOCTEXT("CopyFromPrev", "Copy from Previous Frame"));

	const FFrameHitboxData& PrevFrame = Anim->Frames[SelectedFrameIndex - 1];
	FFrameHitboxData& CurrentFrame = Anim->Frames[SelectedFrameIndex];

	CurrentFrame.Hitboxes = PrevFrame.Hitboxes;
	CurrentFrame.Sockets = PrevFrame.Sockets;

	EndTransaction();
	RefreshHitboxList();
}

void SCharacterDataAssetEditor::OnPropagateAllToGroup()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim) return;

	FFrameHitboxData* CurrentFrame = GetCurrentFrameMutable();
	if (!CurrentFrame) return;

	BeginTransaction(LOCTEXT("PropagateAll", "Propagate All to Group"));

	for (int32 i = 0; i < Anim->Frames.Num(); i++)
	{
		if (i != SelectedFrameIndex)
		{
			Anim->Frames[i].Hitboxes = CurrentFrame->Hitboxes;
			Anim->Frames[i].Sockets = CurrentFrame->Sockets;
		}
	}

	EndTransaction();
}

void SCharacterDataAssetEditor::OnPropagateSelectedToGroup()
{
	if (!EditorCanvas.IsValid()) return;

	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim) return;

	FFrameHitboxData* CurrentFrame = GetCurrentFrameMutable();
	if (!CurrentFrame) return;

	EHitboxSelectionType SelType = EditorCanvas->GetSelectionType();
	int32 SelIndex = EditorCanvas->GetSelectedIndex();

	if (SelType == EHitboxSelectionType::None) return;

	BeginTransaction(LOCTEXT("PropagateSelected", "Propagate Selected to Group"));

	if (SelType == EHitboxSelectionType::Hitbox && CurrentFrame->Hitboxes.IsValidIndex(SelIndex))
	{
		const FHitboxData& SelectedHitbox = CurrentFrame->Hitboxes[SelIndex];
		for (int32 i = 0; i < Anim->Frames.Num(); i++)
		{
			if (i != SelectedFrameIndex)
			{
				if (Anim->Frames[i].Hitboxes.IsValidIndex(SelIndex))
				{
					Anim->Frames[i].Hitboxes[SelIndex] = SelectedHitbox;
				}
				else
				{
					Anim->Frames[i].Hitboxes.Add(SelectedHitbox);
				}
			}
		}
	}
	else if (SelType == EHitboxSelectionType::Socket && CurrentFrame->Sockets.IsValidIndex(SelIndex))
	{
		const FSocketData& SelectedSocket = CurrentFrame->Sockets[SelIndex];
		for (int32 i = 0; i < Anim->Frames.Num(); i++)
		{
			if (i != SelectedFrameIndex)
			{
				bool bFound = false;
				for (FSocketData& Sock : Anim->Frames[i].Sockets)
				{
					if (Sock.Name == SelectedSocket.Name)
					{
						Sock = SelectedSocket;
						bFound = true;
						break;
					}
				}
				if (!bFound)
				{
					Anim->Frames[i].Sockets.Add(SelectedSocket);
				}
			}
		}
	}

	EndTransaction();
}

void SCharacterDataAssetEditor::OnClearCurrentFrame()
{
	FFrameHitboxData* Frame = GetCurrentFrameMutable();
	if (!Frame) return;

	BeginTransaction(LOCTEXT("ClearFrame", "Clear Frame"));

	Frame->Hitboxes.Empty();
	Frame->Sockets.Empty();

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}

	EndTransaction();
	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::BeginTransaction(const FText& Description)
{
	if (Asset.IsValid())
	{
		if (ActiveTransaction.IsValid())
		{
			ActiveTransaction.Reset();
		}

		ActiveTransaction = MakeUnique<FScopedTransaction>(Description);

		Asset->SetFlags(RF_Transactional);
		Asset->Modify();
		Asset->PreEditChange(nullptr);
	}
}

void SCharacterDataAssetEditor::EndTransaction()
{
	if (Asset.IsValid())
	{
		FPropertyChangedEvent ChangedEvent(nullptr);
		Asset->PostEditChangeProperty(ChangedEvent);
		Asset->MarkPackageDirty();
	}

	if (ActiveTransaction.IsValid())
	{
		ActiveTransaction.Reset();
	}
}

void SCharacterDataAssetEditor::AddNewHitbox()
{
	FFrameHitboxData* Frame = GetCurrentFrameMutable();
	if (!Frame) return;

	BeginTransaction(LOCTEXT("AddHitbox", "Add Hitbox"));

	FHitboxData NewHitbox;
	NewHitbox.Type = EHitboxType::Hurtbox;
	NewHitbox.X = 32;
	NewHitbox.Y = 32;
	NewHitbox.Width = 32;
	NewHitbox.Height = 32;
	NewHitbox.Damage = 0;
	NewHitbox.Knockback = 0;

	int32 NewIndex = Frame->Hitboxes.Add(NewHitbox);

	EndTransaction();

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->SetSelection(EHitboxSelectionType::Hitbox, NewIndex);
	}

	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::AddNewSocket()
{
	FFrameHitboxData* Frame = GetCurrentFrameMutable();
	if (!Frame) return;

	BeginTransaction(LOCTEXT("AddSocket", "Add Socket"));

	FSocketData NewSocket;
	NewSocket.Name = FString::Printf(TEXT("Socket%d"), Frame->Sockets.Num());
	NewSocket.X = 64;
	NewSocket.Y = 64;

	int32 NewIndex = Frame->Sockets.Add(NewSocket);

	EndTransaction();

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->SetSelection(EHitboxSelectionType::Socket, NewIndex);
	}

	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::DeleteSelected()
{
	if (EditorCanvas.IsValid())
	{
		EditorCanvas->DeleteSelection();
	}
}

void SCharacterDataAssetEditor::AddNewAnimation()
{
	if (!Asset.IsValid()) return;

	BeginTransaction(LOCTEXT("AddFlipbookTrans", "Add Flipbook"));

	FAnimationHitboxData NewAnim;
	NewAnim.AnimationName = FString::Printf(TEXT("Animation_%d"), Asset->Animations.Num());

	FFrameHitboxData DefaultFrame;
	DefaultFrame.FrameName = TEXT("Frame_0");
	NewAnim.Frames.Add(DefaultFrame);

	int32 NewIndex = Asset->Animations.Add(NewAnim);

	EndTransaction();

	SelectedAnimationIndex = NewIndex;
	SelectedFrameIndex = 0;

	RefreshAnimationList();
	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::RemoveSelectedAnimation()
{
	if (!Asset.IsValid()) return;
	if (!Asset->Animations.IsValidIndex(SelectedAnimationIndex)) return;

	if (Asset->Animations.Num() <= 1) return;

	BeginTransaction(LOCTEXT("RemoveFlipbookTrans", "Remove Flipbook"));

	Asset->Animations.RemoveAt(SelectedAnimationIndex);

	EndTransaction();

	if (SelectedAnimationIndex >= Asset->Animations.Num())
	{
		SelectedAnimationIndex = Asset->Animations.Num() - 1;
	}
	SelectedFrameIndex = 0;

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}

	RefreshAnimationList();
	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::AddNewFrame()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim) return;

	BeginTransaction(LOCTEXT("AddFrame", "Add Frame"));

	FFrameHitboxData NewFrame;
	NewFrame.FrameName = FString::Printf(TEXT("Frame_%d"), Anim->Frames.Num());

	int32 NewIndex = Anim->Frames.Add(NewFrame);

	EndTransaction();

	SelectedFrameIndex = NewIndex;

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}

	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::RemoveSelectedFrame()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim) return;
	if (!Anim->Frames.IsValidIndex(SelectedFrameIndex)) return;

	if (Anim->Frames.Num() <= 1) return;

	BeginTransaction(LOCTEXT("RemoveFrame", "Remove Frame"));

	Anim->Frames.RemoveAt(SelectedFrameIndex);

	EndTransaction();

	if (SelectedFrameIndex >= Anim->Frames.Num())
	{
		SelectedFrameIndex = Anim->Frames.Num() - 1;
	}

	if (EditorCanvas.IsValid())
	{
		EditorCanvas->ClearSelection();
	}

	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();
}

const FFrameHitboxData* SCharacterDataAssetEditor::GetCurrentFrame() const
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim) return nullptr;
	if (!Anim->Frames.IsValidIndex(SelectedFrameIndex)) return nullptr;
	return &Anim->Frames[SelectedFrameIndex];
}

FFrameHitboxData* SCharacterDataAssetEditor::GetCurrentFrameMutable()
{
	FAnimationHitboxData* Anim = GetCurrentAnimationMutable();
	if (!Anim) return nullptr;
	if (!Anim->Frames.IsValidIndex(SelectedFrameIndex)) return nullptr;
	return &Anim->Frames[SelectedFrameIndex];
}

const FAnimationHitboxData* SCharacterDataAssetEditor::GetCurrentAnimation() const
{
	if (!Asset.IsValid()) return nullptr;
	if (!Asset->Animations.IsValidIndex(SelectedAnimationIndex)) return nullptr;
	return &Asset->Animations[SelectedAnimationIndex];
}

FAnimationHitboxData* SCharacterDataAssetEditor::GetCurrentAnimationMutable()
{
	if (!Asset.IsValid()) return nullptr;
	if (!Asset->Animations.IsValidIndex(SelectedAnimationIndex)) return nullptr;
	return &Asset->Animations[SelectedAnimationIndex];
}

int32 SCharacterDataAssetEditor::GetCurrentFrameCount() const
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	return Anim ? Anim->Frames.Num() : 0;
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildDimensionManagementSection()
{
	return SNew(SExpandableArea)
		.AreaTitle(LOCTEXT("DimensionManagement", "Dimension Management"))
		.InitiallyCollapsed(true)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.BodyBorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.HeaderPadding(FMargin(4, 2))
		.Padding(FMargin(4))
		.BodyContent()
		[
			SNew(SBox)
			.MinDesiredHeight(200)
			.MaxDesiredHeight(350)
			[
				SAssignNew(DimensionPanel, SDimensionManagementPanel)
				.Asset(Asset.Get())
			]
		];
}

// ==========================================
// SSpriteAlignmentCanvas Implementation
// ==========================================

void SSpriteAlignmentCanvas::Construct(const FArguments& InArgs)
{
	Asset = InArgs._Asset;
	SelectedAnimationIndex = InArgs._SelectedAnimationIndex;
	SelectedFrameIndex = InArgs._SelectedFrameIndex;
	ShowGrid = InArgs._ShowGrid;
	Zoom = InArgs._Zoom;
	ShowOnionSkin = InArgs._ShowOnionSkin;
	OnionSkinFrames = InArgs._OnionSkinFrames;
	OnionSkinOpacity = InArgs._OnionSkinOpacity;
	ReticleAnchor = InArgs._ReticleAnchor;

	// Enable clipping so sprites don't render outside canvas bounds
	SetClipping(EWidgetClipping::ClipToBounds);
}

FVector2D SSpriteAlignmentCanvas::ComputeDesiredSize(float) const
{
	// Return a minimum size - the canvas will expand to fill available space
	// Drawing code uses Geom.GetLocalSize() which adapts to actual allocated size
	return FVector2D(100, 100);
}

const FAnimationHitboxData* SSpriteAlignmentCanvas::GetCurrentAnimation() const
{
	if (!Asset.IsValid()) return nullptr;
	int32 AnimIndex = SelectedAnimationIndex.Get();
	if (!Asset->Animations.IsValidIndex(AnimIndex)) return nullptr;
	return &Asset->Animations[AnimIndex];
}

const FSpriteExtractionInfo* SSpriteAlignmentCanvas::GetCurrentExtractionInfo() const
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim) return nullptr;
	int32 FrameIndex = SelectedFrameIndex.Get();
	if (!Anim->FrameExtractionInfo.IsValidIndex(FrameIndex)) return nullptr;
	return &Anim->FrameExtractionInfo[FrameIndex];
}

FSpriteExtractionInfo* SSpriteAlignmentCanvas::GetCurrentExtractionInfoMutable() const
{
	if (!Asset.IsValid()) return nullptr;
	int32 AnimIndex = SelectedAnimationIndex.Get();
	if (!Asset->Animations.IsValidIndex(AnimIndex)) return nullptr;

	FAnimationHitboxData& Anim = Asset->Animations[AnimIndex];
	int32 FrameIndex = SelectedFrameIndex.Get();
	if (!Anim.FrameExtractionInfo.IsValidIndex(FrameIndex)) return nullptr;
	return &Anim.FrameExtractionInfo[FrameIndex];
}

UPaperSprite* SSpriteAlignmentCanvas::GetSpriteAtFrame(int32 FrameIndex) const
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim || !Anim->Flipbook.IsValid()) return nullptr;

	UPaperFlipbook* Flipbook = Anim->Flipbook.LoadSynchronous();
	if (!Flipbook) return nullptr;

	if (FrameIndex < 0 || FrameIndex >= Flipbook->GetNumKeyFrames()) return nullptr;

	const FPaperFlipbookKeyFrame& KeyFrame = Flipbook->GetKeyFrameChecked(FrameIndex);
	return KeyFrame.Sprite;
}

FIntPoint SSpriteAlignmentCanvas::GetOffsetAtFrame(int32 FrameIndex) const
{
	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (!Anim || !Anim->FrameExtractionInfo.IsValidIndex(FrameIndex))
	{
		return FIntPoint::ZeroValue;
	}
	return Anim->FrameExtractionInfo[FrameIndex].SpriteOffset;
}

FIntPoint SSpriteAlignmentCanvas::GetUniformDimensions() const
{
	if (!Asset.IsValid()) return FIntPoint(128, 128);
	return Asset->UniformDimensions;
}

FVector2D SSpriteAlignmentCanvas::GetCanvasCenter(const FGeometry& Geom) const
{
	return Geom.GetLocalSize() * 0.5f + PanOffset;
}

float SSpriteAlignmentCanvas::GetEffectiveZoom() const
{
	return Zoom.Get();
}

FVector2D SSpriteAlignmentCanvas::ScreenToCanvas(const FGeometry& Geom, const FVector2D& ScreenPos) const
{
	FVector2D LocalPos = Geom.AbsoluteToLocal(ScreenPos);
	FVector2D Center = GetCanvasCenter(Geom);
	float EffectiveZoom = GetEffectiveZoom();
	return (LocalPos - Center) / EffectiveZoom;
}

FVector2D SSpriteAlignmentCanvas::CanvasToScreen(const FGeometry& Geom, const FVector2D& CanvasPos) const
{
	FVector2D Center = GetCanvasCenter(Geom);
	float EffectiveZoom = GetEffectiveZoom();
	return Center + CanvasPos * EffectiveZoom;
}

FVector2D SSpriteAlignmentCanvas::GetReticlePosition(const FGeometry& Geom) const
{
	FVector2D CanvasSize = Geom.GetLocalSize();
	FVector2D Center = CanvasSize * 0.5f + PanOffset;
	float EffectiveZoom = GetEffectiveZoom();
	FIntPoint Dims = GetUniformDimensions();
	FVector2D BoundsSize = FVector2D(Dims.X, Dims.Y) * EffectiveZoom;
	FVector2D BoundsTopLeft = Center - BoundsSize * 0.5f;

	ESpriteAnchor Anchor = ReticleAnchor.Get();

	switch (Anchor)
	{
		case ESpriteAnchor::TopLeft:
			return BoundsTopLeft;
		case ESpriteAnchor::TopCenter:
			return FVector2D(Center.X, BoundsTopLeft.Y);
		case ESpriteAnchor::TopRight:
			return FVector2D(BoundsTopLeft.X + BoundsSize.X, BoundsTopLeft.Y);
		case ESpriteAnchor::CenterLeft:
			return FVector2D(BoundsTopLeft.X, Center.Y);
		case ESpriteAnchor::Center:
			return Center;
		case ESpriteAnchor::CenterRight:
			return FVector2D(BoundsTopLeft.X + BoundsSize.X, Center.Y);
		case ESpriteAnchor::BottomLeft:
			return FVector2D(BoundsTopLeft.X, BoundsTopLeft.Y + BoundsSize.Y);
		case ESpriteAnchor::BottomCenter:
			return FVector2D(Center.X, BoundsTopLeft.Y + BoundsSize.Y);
		case ESpriteAnchor::BottomRight:
			return BoundsTopLeft + BoundsSize;
		default:
			return Center;
	}
}

int32 SSpriteAlignmentCanvas::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	// Draw checkerboard background
	DrawCheckerboard(AllottedGeometry, OutDrawElements, LayerId);
	LayerId++;

	// Draw grid if enabled
	if (ShowGrid.Get())
	{
		DrawGrid(AllottedGeometry, OutDrawElements, LayerId);
		LayerId++;
	}

	// Draw onion skin if enabled
	if (ShowOnionSkin.Get())
	{
		DrawOnionSkin(AllottedGeometry, OutDrawElements, LayerId);
		LayerId++;
	}

	// Draw uniform bounds
	DrawUniformBounds(AllottedGeometry, OutDrawElements, LayerId);
	LayerId++;

	// Draw current sprite
	int32 CurrentFrame = SelectedFrameIndex.Get();
	UPaperSprite* CurrentSprite = GetSpriteAtFrame(CurrentFrame);
	FIntPoint CurrentOffset = GetOffsetAtFrame(CurrentFrame);
	if (CurrentSprite)
	{
		DrawSprite(AllottedGeometry, OutDrawElements, LayerId, CurrentSprite, CurrentOffset, FLinearColor::White);
		LayerId++;
	}

	// Draw reticle
	DrawReticle(AllottedGeometry, OutDrawElements, LayerId);
	LayerId++;

	// Draw offset indicator
	DrawOffsetIndicator(AllottedGeometry, OutDrawElements, LayerId);
	LayerId++;

	return LayerId;
}

void SSpriteAlignmentCanvas::DrawCheckerboard(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	const FVector2D LocalSize = Geom.GetLocalSize();

	// Draw dark background
	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(FVector2f(LocalSize), FSlateLayoutTransform()),
		FAppStyle::GetBrush("WhiteBrush"),
		ESlateDrawEffect::None,
		FLinearColor(0.1f, 0.1f, 0.1f, 1.0f)
	);

	// Draw checkerboard pattern - constant size regardless of zoom for stable background
	const float CheckSize = CheckerSize; // Don't scale with zoom

	for (float Y = 0; Y < LocalSize.Y; Y += CheckSize)
	{
		for (float X = 0; X < LocalSize.X; X += CheckSize)
		{
			int32 CheckX = FMath::FloorToInt(X / CheckSize);
			int32 CheckY = FMath::FloorToInt(Y / CheckSize);
			bool bDark = ((CheckX + CheckY) % 2) == 0;

			if (bDark)
			{
				FSlateDrawElement::MakeBox(
					OutDrawElements,
					LayerId,
					Geom.ToPaintGeometry(FVector2f(CheckSize), FSlateLayoutTransform(FVector2f(X, Y))),
					FAppStyle::GetBrush("WhiteBrush"),
					ESlateDrawEffect::None,
					FLinearColor(0.15f, 0.15f, 0.15f, 1.0f)
				);
			}
		}
	}
}

void SSpriteAlignmentCanvas::DrawGrid(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	const FVector2D LocalSize = Geom.GetLocalSize();
	FVector2D Center = GetCanvasCenter(Geom);
	float EffectiveZoom = GetEffectiveZoom();
	float GridStep = GridSize * EffectiveZoom;

	FLinearColor GridColor(0.3f, 0.3f, 0.3f, 0.5f);

	// Draw vertical lines
	for (float X = FMath::Fmod(Center.X, GridStep); X < LocalSize.X; X += GridStep)
	{
		TArray<FVector2D> Points;
		Points.Add(FVector2D(X, 0));
		Points.Add(FVector2D(X, LocalSize.Y));
		FSlateDrawElement::MakeLines(
			OutDrawElements,
			LayerId,
			Geom.ToPaintGeometry(),
			Points,
			ESlateDrawEffect::None,
			GridColor,
			true,
			1.0f
		);
	}

	// Draw horizontal lines
	for (float Y = FMath::Fmod(Center.Y, GridStep); Y < LocalSize.Y; Y += GridStep)
	{
		TArray<FVector2D> Points;
		Points.Add(FVector2D(0, Y));
		Points.Add(FVector2D(LocalSize.X, Y));
		FSlateDrawElement::MakeLines(
			OutDrawElements,
			LayerId,
			Geom.ToPaintGeometry(),
			Points,
			ESlateDrawEffect::None,
			GridColor,
			true,
			1.0f
		);
	}
}

void SSpriteAlignmentCanvas::DrawUniformBounds(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	FIntPoint UniformDims = GetUniformDimensions();
	if (UniformDims.X <= 0 || UniformDims.Y <= 0) return;

	float EffectiveZoom = GetEffectiveZoom();
	FVector2D Center = GetCanvasCenter(Geom);

	FVector2D BoundsSize(UniformDims.X * EffectiveZoom, UniformDims.Y * EffectiveZoom);
	FVector2D BoundsTopLeft = Center - BoundsSize * 0.5f;

	// Draw dashed border
	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(FVector2f(BoundsSize), FSlateLayoutTransform(FVector2f(BoundsTopLeft))),
		FAppStyle::GetBrush("Border"),
		ESlateDrawEffect::None,
		FLinearColor(0.8f, 0.8f, 0.2f, 0.8f)
	);
}

void SSpriteAlignmentCanvas::DrawSprite(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	UPaperSprite* Sprite, FIntPoint Offset, FLinearColor Tint) const
{
	if (!Sprite) return;

	// Get sprite texture
	UTexture2D* SpriteTexture = Sprite->GetBakedTexture();
	if (!SpriteTexture)
	{
		SpriteTexture = Cast<UTexture2D>(Sprite->GetSourceTexture());
	}
	if (!SpriteTexture) return;

	float EffectiveZoom = GetEffectiveZoom();
	FVector2D Center = GetCanvasCenter(Geom);

	// Get sprite dimensions
	FVector2D SpriteDims = Sprite->GetSourceSize();
	FVector2D DrawSize(SpriteDims.X * EffectiveZoom, SpriteDims.Y * EffectiveZoom);

	// Calculate position with offset
	FVector2D DrawPos = Center - DrawSize * 0.5f;
	DrawPos.X += Offset.X * EffectiveZoom;
	DrawPos.Y += Offset.Y * EffectiveZoom;

	// Create brush
	FSlateBrush SpriteBrush;
	SpriteBrush.SetResourceObject(SpriteTexture);
	SpriteBrush.ImageSize = FVector2D(SpriteTexture->GetSizeX(), SpriteTexture->GetSizeY());
	SpriteBrush.DrawAs = ESlateBrushDrawType::Image;
	SpriteBrush.Tiling = ESlateBrushTileType::NoTile;

	// Set UV region to display only this sprite's portion of the texture
	FVector2D SourceUV = Sprite->GetSourceUV();
	FVector2D SourceSize = Sprite->GetSourceSize();
	FVector2D TextureSize(SpriteTexture->GetSizeX(), SpriteTexture->GetSizeY());
	if (TextureSize.X > 0 && TextureSize.Y > 0)
	{
		FBox2D UVRegion(
			FVector2D(SourceUV.X / TextureSize.X, SourceUV.Y / TextureSize.Y),
			FVector2D((SourceUV.X + SourceSize.X) / TextureSize.X, (SourceUV.Y + SourceSize.Y) / TextureSize.Y)
		);
		SpriteBrush.SetUVRegion(UVRegion);
	}

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(FVector2f(DrawSize), FSlateLayoutTransform(FVector2f(DrawPos))),
		&SpriteBrush,
		ESlateDrawEffect::None,
		Tint
	);
}

void SSpriteAlignmentCanvas::DrawOnionSkin(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	int32 CurrentFrame = SelectedFrameIndex.Get();
	int32 NumOnionFrames = OnionSkinFrames.Get();
	float BaseOpacity = OnionSkinOpacity.Get();

	for (int32 i = 1; i <= NumOnionFrames; i++)
	{
		int32 PrevFrame = CurrentFrame - i;
		if (PrevFrame < 0) break;

		UPaperSprite* PrevSprite = GetSpriteAtFrame(PrevFrame);
		if (!PrevSprite) continue;

		FIntPoint PrevOffset = GetOffsetAtFrame(PrevFrame);

		// Calculate opacity (closer frames are more opaque)
		float Opacity = BaseOpacity * (1.0f - (float)(i - 1) / (float)NumOnionFrames);

		// Blue tint for onion skin
		FLinearColor OnionColor(0.5f, 0.5f, 1.0f, Opacity);

		DrawSprite(Geom, OutDrawElements, LayerId, PrevSprite, PrevOffset, OnionColor);
	}
}

void SSpriteAlignmentCanvas::DrawReticle(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	float EffectiveZoom = GetEffectiveZoom();
	FVector2D ReticlePos = GetReticlePosition(Geom);

	// Draw crosshair at reticle position (based on selected anchor)
	float LineLength = 20.0f;
	FLinearColor ReticleColor(1.0f, 0.5f, 0.0f, 1.0f); // Orange

	// Horizontal line
	TArray<FVector2D> HLine;
	HLine.Add(FVector2D(ReticlePos.X - LineLength, ReticlePos.Y));
	HLine.Add(FVector2D(ReticlePos.X + LineLength, ReticlePos.Y));
	FSlateDrawElement::MakeLines(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(),
		HLine,
		ESlateDrawEffect::None,
		ReticleColor,
		true,
		2.0f
	);

	// Vertical line
	TArray<FVector2D> VLine;
	VLine.Add(FVector2D(ReticlePos.X, ReticlePos.Y - LineLength));
	VLine.Add(FVector2D(ReticlePos.X, ReticlePos.Y + LineLength));
	FSlateDrawElement::MakeLines(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(),
		VLine,
		ESlateDrawEffect::None,
		ReticleColor,
		true,
		2.0f
	);

	// Draw circle around reticle position
	const int32 NumSegments = 16;
	float Radius = 10.0f;
	TArray<FVector2D> Circle;
	for (int32 i = 0; i <= NumSegments; i++)
	{
		float Angle = (float)i / (float)NumSegments * 2.0f * PI;
		Circle.Add(FVector2D(
			ReticlePos.X + FMath::Cos(Angle) * Radius,
			ReticlePos.Y + FMath::Sin(Angle) * Radius
		));
	}
	FSlateDrawElement::MakeLines(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(),
		Circle,
		ESlateDrawEffect::None,
		ReticleColor,
		true,
		1.5f
	);
}

void SSpriteAlignmentCanvas::DrawOffsetIndicator(const FGeometry& Geom, FSlateWindowElementList& OutDrawElements, int32 LayerId) const
{
	const FSpriteExtractionInfo* ExtractInfo = GetCurrentExtractionInfo();
	if (!ExtractInfo) return;

	FIntPoint Offset = ExtractInfo->SpriteOffset;
	if (Offset.X == 0 && Offset.Y == 0) return;

	float EffectiveZoom = GetEffectiveZoom();
	FVector2D Center = GetCanvasCenter(Geom);

	// Draw line from center to offset position
	FVector2D OffsetPos = Center + FVector2D(Offset.X * EffectiveZoom, Offset.Y * EffectiveZoom);

	TArray<FVector2D> OffsetLine;
	OffsetLine.Add(Center);
	OffsetLine.Add(OffsetPos);

	FSlateDrawElement::MakeLines(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(),
		OffsetLine,
		ESlateDrawEffect::None,
		FLinearColor(0.0f, 1.0f, 0.0f, 0.8f),
		true,
		1.5f
	);

	// Draw small circle at offset position
	const int32 NumSegments = 8;
	float Radius = 5.0f;
	TArray<FVector2D> Circle;
	for (int32 i = 0; i <= NumSegments; i++)
	{
		float Angle = (float)i / (float)NumSegments * 2.0f * PI;
		Circle.Add(FVector2D(
			OffsetPos.X + FMath::Cos(Angle) * Radius,
			OffsetPos.Y + FMath::Sin(Angle) * Radius
		));
	}
	FSlateDrawElement::MakeLines(
		OutDrawElements,
		LayerId,
		Geom.ToPaintGeometry(),
		Circle,
		ESlateDrawEffect::None,
		FLinearColor(0.0f, 1.0f, 0.0f, 1.0f),
		true,
		1.5f
	);
}

FReply SSpriteAlignmentCanvas::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		// Start dragging to adjust offset
		bIsDragging = true;
		DragStart = MouseEvent.GetScreenSpacePosition();

		const FSpriteExtractionInfo* ExtractInfo = GetCurrentExtractionInfo();
		OffsetAtDragStart = ExtractInfo ? ExtractInfo->SpriteOffset : FIntPoint::ZeroValue;

		return FReply::Handled().CaptureMouse(SharedThis(this));
	}
	else if (MouseEvent.GetEffectingButton() == EKeys::MiddleMouseButton ||
			 MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		// Start panning
		bIsPanning = true;
		PanStart = MouseEvent.GetScreenSpacePosition();
		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

FReply SSpriteAlignmentCanvas::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bIsDragging && MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		bIsDragging = false;
		return FReply::Handled().ReleaseMouseCapture();
	}
	else if (bIsPanning && (MouseEvent.GetEffectingButton() == EKeys::MiddleMouseButton ||
							MouseEvent.GetEffectingButton() == EKeys::RightMouseButton))
	{
		bIsPanning = false;
		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

FReply SSpriteAlignmentCanvas::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bIsDragging)
	{
		float EffectiveZoom = GetEffectiveZoom();
		FVector2D Delta = (MouseEvent.GetScreenSpacePosition() - DragStart) / EffectiveZoom;

		int32 DeltaX = FMath::RoundToInt(Delta.X);
		int32 DeltaY = FMath::RoundToInt(Delta.Y);

		// Calculate new offset
		int32 NewOffsetX = OffsetAtDragStart.X + DeltaX;
		int32 NewOffsetY = OffsetAtDragStart.Y + DeltaY;

		// Get current offset and see if it changed
		FSpriteExtractionInfo* ExtractInfo = GetCurrentExtractionInfoMutable();
		if (ExtractInfo)
		{
			int32 ActualDeltaX = NewOffsetX - ExtractInfo->SpriteOffset.X;
			int32 ActualDeltaY = NewOffsetY - ExtractInfo->SpriteOffset.Y;

			if (ActualDeltaX != 0 || ActualDeltaY != 0)
			{
				OnOffsetChanged.ExecuteIfBound(ActualDeltaX, ActualDeltaY);
			}
		}

		return FReply::Handled();
	}
	else if (bIsPanning)
	{
		FVector2D Delta = MouseEvent.GetScreenSpacePosition() - PanStart;
		PanOffset += Delta;
		PanStart = MouseEvent.GetScreenSpacePosition();
		return FReply::Handled();
	}

	return FReply::Unhandled();
}

FReply SSpriteAlignmentCanvas::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	float ZoomDelta = MouseEvent.GetWheelDelta() * 0.1f;
	float NewZoom = FMath::Clamp(Zoom.Get() + ZoomDelta, 0.5f, 4.0f);

	OnZoomChanged.ExecuteIfBound(NewZoom);

	return FReply::Handled();
}

FReply SSpriteAlignmentCanvas::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	// Shift modifier for 10px nudge, otherwise 1px
	int32 NudgeAmount = InKeyEvent.IsShiftDown() ? 10 : 1;

	// WASD for nudging
	if (InKeyEvent.GetKey() == EKeys::W || InKeyEvent.GetKey() == EKeys::Up)
	{
		OnOffsetChanged.ExecuteIfBound(0, -NudgeAmount);
		return FReply::Handled();
	}
	else if (InKeyEvent.GetKey() == EKeys::A)
	{
		OnOffsetChanged.ExecuteIfBound(-NudgeAmount, 0);
		return FReply::Handled();
	}
	else if (InKeyEvent.GetKey() == EKeys::S || InKeyEvent.GetKey() == EKeys::Down)
	{
		OnOffsetChanged.ExecuteIfBound(0, NudgeAmount);
		return FReply::Handled();
	}
	else if (InKeyEvent.GetKey() == EKeys::D)
	{
		OnOffsetChanged.ExecuteIfBound(NudgeAmount, 0);
		return FReply::Handled();
	}

	return FReply::Unhandled();
}

#undef LOCTEXT_NAMESPACE
