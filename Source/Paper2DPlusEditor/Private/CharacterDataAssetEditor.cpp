#include "CharacterDataAssetEditor.h"
#include "CharacterDataJsonImporter.h"
#include "DimensionManagementPanel.h"
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Layout/SExpandableArea.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Docking/SDockTab.h"
#include "PaperFlipbook.h"
#include "PaperSprite.h"
#include "Engine/Texture2D.h"
#include "PropertyCustomizationHelpers.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "ScopedTransaction.h"
#include "Framework/Commands/UICommandList.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "DesktopPlatformModule.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"

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

	ChildSlot
	[
		SNew(SVerticalBox)

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
		]
	];
}

FReply SCharacterDataAssetEditor::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
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
				.ToolTipText(LOCTEXT("ImportJSONTooltip", "Import character data from JSON, merging with existing animations"))
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
			.Padding(2)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Tools", "Tools"))
				.Font(FAppStyle::GetFontStyle("BoldFont"))
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(2)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("DrawTool", "Draw (D)"))
					.ButtonColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Draw ? FLinearColor(0.2f, 0.6f, 0.2f) : FLinearColor(0.15f, 0.15f, 0.15f); })
					.OnClicked_Lambda([this]() { OnToolSelected(EHitboxEditorTool::Draw); return FReply::Handled(); })
				]

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("EditTool", "Edit (E)"))
					.ButtonColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Edit ? FLinearColor(0.2f, 0.4f, 0.8f) : FLinearColor(0.15f, 0.15f, 0.15f); })
					.OnClicked_Lambda([this]() { OnToolSelected(EHitboxEditorTool::Edit); return FReply::Handled(); })
				]

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("SocketTool", "Socket (S)"))
					.ButtonColorAndOpacity_Lambda([this]() { return CurrentTool == EHitboxEditorTool::Socket ? FLinearColor(0.8f, 0.6f, 0.2f) : FLinearColor(0.15f, 0.15f, 0.15f); })
					.OnClicked_Lambda([this]() { OnToolSelected(EHitboxEditorTool::Socket); return FReply::Handled(); })
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
			.Text(LOCTEXT("Animations", "Animations"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("AddAnim", "+"))
			.ToolTipText(LOCTEXT("AddAnimTooltip", "Add new animation"))
			.OnClicked_Lambda([this]() { AddNewAnimation(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("RemoveAnim", "-"))
			.ToolTipText(LOCTEXT("RemoveAnimTooltip", "Remove selected animation"))
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
						.Text(FText::Format(LOCTEXT("AnimName", "{0} ({1})"),
							FText::FromString(Anim.AnimationName),
							FText::AsNumber(Anim.Frames.Num())))
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(FText::FromString(bHasFlipbook ? Anim.Flipbook.GetAssetName() : TEXT("No Flipbook")))
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

	const FAnimationHitboxData* Anim = GetCurrentAnimation();
	if (Anim)
	{
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

			FString Info = FString::Printf(TEXT("A:%d H:%d C:%d S:%d"),
				AttackCount, HurtCount, ColCount, Frame.Sockets.Num());

			FrameListBox->AddSlot()
			.AutoHeight()
			.Padding(1)
			[
				SNew(SButton)
				.ButtonColorAndOpacity(bIsSelected ? FLinearColor(0.2f, 0.6f, 0.3f) : FLinearColor(0.12f, 0.12f, 0.12f))
				.OnClicked_Lambda([this, i]() { OnFrameSelected(i); return FReply::Handled(); })
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(2)
					[
						SNew(STextBlock)
						.Text(FText::AsNumber(i))
						.Font(FAppStyle::GetFontStyle("SmallFont"))
					]
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					.VAlign(VAlign_Center)
					.Padding(4, 0)
					[
						SNew(STextBlock)
						.Text(FText::FromString(Info))
						.Font(FAppStyle::GetFontStyle("SmallFont"))
						.ColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f)))
					]
				]
			];
		}
	}
}

TSharedRef<SWidget> SCharacterDataAssetEditor::BuildCanvasArea()
{
	TSharedRef<SVerticalBox> CanvasArea = SNew(SVerticalBox)
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
				.Text(LOCTEXT("FlipbookLabel", "Flipbook:"))
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
			SAssignNew(EditorCanvas, SCharacterDataEditorCanvas)
			.Asset(Asset)
			.SelectedAnimationIndex_Lambda([this]() { return SelectedAnimationIndex; })
			.SelectedFrameIndex_Lambda([this]() { return SelectedFrameIndex; })
			.CurrentTool_Lambda([this]() { return CurrentTool; })
			.ShowGrid_Lambda([this]() { return bShowGrid; })
			.Zoom_Lambda([this]() { return ZoomLevel; })
		];

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
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("HitboxesSockets", "Hitboxes & Sockets"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("AddHitbox", "+Box"))
			.OnClicked_Lambda([this]() { AddNewHitbox(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("AddSocket", "+Sock"))
			.OnClicked_Lambda([this]() { AddNewSocket(); return FReply::Handled(); })
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("Delete", "Del"))
			.OnClicked_Lambda([this]() { DeleteSelected(); return FReply::Handled(); })
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
		.Padding(4)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("CopyOperations", "Copy Operations"))
			.Font(FAppStyle::GetFontStyle("BoldFont"))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.Text(LOCTEXT("CopyFromPrev", "Copy from Previous Frame"))
			.OnClicked_Lambda([this]() { OnCopyFromPrevious(); return FReply::Handled(); })
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.Text(LOCTEXT("PropagateAll", "Propagate All to Group"))
			.OnClicked_Lambda([this]() { OnPropagateAllToGroup(); return FReply::Handled(); })
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.Text(LOCTEXT("PropagateSelected", "Propagate Selected to Group"))
			.OnClicked_Lambda([this]() { OnPropagateSelectedToGroup(); return FReply::Handled(); })
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SButton)
			.Text(LOCTEXT("ClearFrame", "Clear Current Frame"))
			.OnClicked_Lambda([this]() { OnClearCurrentFrame(); return FReply::Handled(); })
		];
}

void SCharacterDataAssetEditor::RefreshAll()
{
	RefreshAnimationList();
	RefreshFrameList();
	RefreshHitboxList();
	RefreshPropertiesPanel();
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
}

void SCharacterDataAssetEditor::OnToolSelected(EHitboxEditorTool Tool)
{
	CurrentTool = Tool;
}

void SCharacterDataAssetEditor::OnSelectionChanged(EHitboxSelectionType Type, int32 Index)
{
	RefreshHitboxList();
	RefreshPropertiesPanel();
}

void SCharacterDataAssetEditor::OnHitboxDataModified()
{
	if (Asset.IsValid())
	{
		Asset->MarkPackageDirty();
	}
	RefreshHitboxList();
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
		FText::Format(LOCTEXT("ImportMergeSuccess", "Import complete!\n\nAnimations matched: {0}\nFrames matched: {1}\nHitboxes imported: {2}\nSockets imported: {3}"),
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

	BeginTransaction(LOCTEXT("AddAnimation", "Add Animation"));

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

	BeginTransaction(LOCTEXT("RemoveAnimation", "Remove Animation"));

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

#undef LOCTEXT_NAMESPACE
