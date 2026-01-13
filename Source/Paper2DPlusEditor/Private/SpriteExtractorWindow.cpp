#include "SpriteExtractorWindow.h"
#include "Paper2DPlusCharacterDataAsset.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Docking/TabManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ToolMenus.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "Engine/Texture2D.h"
#include "PaperSprite.h"
#include "PaperFlipbook.h"
#include "ObjectTools.h"
#include "PackageTools.h"
#include "ScopedTransaction.h"
#include "DesktopPlatformModule.h"
#include "EditorDirectories.h"
#include "Misc/FileHelper.h"
#include "Misc/ScopedSlowTask.h"
#include "PropertyCustomizationHelpers.h"

#define LOCTEXT_NAMESPACE "SpriteExtractor"

// ============================================
// SSpriteExtractorCanvas Implementation
// ============================================

void SSpriteExtractorCanvas::Construct(const FArguments& InArgs)
{
	CurrentTexture = InArgs._Texture;
}

FVector2D SSpriteExtractorCanvas::ComputeDesiredSize(float) const
{
	return FVector2D(800, 600);
}

int32 SSpriteExtractorCanvas::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	// Draw background
	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId,
		AllottedGeometry.ToPaintGeometry(),
		FAppStyle::GetBrush("Graph.Panel.SolidBackground"),
		ESlateDrawEffect::None,
		FLinearColor(0.1f, 0.1f, 0.12f)
	);
	LayerId++;

	// Draw texture if available
	if (CurrentTexture)
	{
		FSlateBrush TextureBrush;
		TextureBrush.SetResourceObject(CurrentTexture);
		TextureBrush.ImageSize = FVector2D(CurrentTexture->GetSizeX(), CurrentTexture->GetSizeY());

		FVector2D TextureSize = TextureBrush.ImageSize * ZoomLevel;
		FVector2D DrawPos = PanOffset + (AllottedGeometry.GetLocalSize() - TextureSize) * 0.5f;

		// Draw checkered background for transparency (like Unreal's texture viewer)
		const float CheckerSize = 16.0f * ZoomLevel;
		FLinearColor CheckerLight(0.4f, 0.4f, 0.4f, 1.0f);
		FLinearColor CheckerDark(0.2f, 0.2f, 0.2f, 1.0f);

		int32 NumChecksX = FMath::CeilToInt(TextureSize.X / CheckerSize);
		int32 NumChecksY = FMath::CeilToInt(TextureSize.Y / CheckerSize);

		for (int32 Y = 0; Y < NumChecksY; Y++)
		{
			for (int32 X = 0; X < NumChecksX; X++)
			{
				FLinearColor CheckerColor = ((X + Y) % 2 == 0) ? CheckerLight : CheckerDark;
				FVector2D CheckerPos = DrawPos + FVector2D(X * CheckerSize, Y * CheckerSize);
				FVector2D CheckerDrawSize(
					FMath::Min(CheckerSize, TextureSize.X - X * CheckerSize),
					FMath::Min(CheckerSize, TextureSize.Y - Y * CheckerSize)
				);

				FSlateDrawElement::MakeBox(
					OutDrawElements,
					LayerId,
					AllottedGeometry.ToPaintGeometry(CheckerDrawSize, FSlateLayoutTransform(CheckerPos)),
					FAppStyle::GetBrush("WhiteBrush"),
					ESlateDrawEffect::None,
					CheckerColor
				);
			}
		}
		LayerId++;

		// Draw the texture on top
		FSlateDrawElement::MakeBox(
			OutDrawElements,
			LayerId,
			AllottedGeometry.ToPaintGeometry(TextureSize, FSlateLayoutTransform(DrawPos)),
			&TextureBrush,
			ESlateDrawEffect::None,
			FLinearColor::White
		);
		LayerId++;

		// Draw detected sprites
		for (int32 i = 0; i < DetectedSprites.Num(); i++)
		{
			const FDetectedSprite& Sprite = DetectedSprites[i];

			FVector2D TopLeft = TextureToScreen(AllottedGeometry, FVector2D(Sprite.Bounds.Min.X, Sprite.Bounds.Min.Y));
			FVector2D BottomRight = TextureToScreen(AllottedGeometry, FVector2D(Sprite.Bounds.Max.X, Sprite.Bounds.Max.Y));
			FVector2D Size = BottomRight - TopLeft;

			FLinearColor Color = Sprite.bSelected ? FLinearColor(0.0f, 1.0f, 0.0f, 0.5f) : FLinearColor(1.0f, 0.0f, 0.0f, 0.3f);
			FLinearColor BorderColor = Sprite.bSelected ? FLinearColor::Green : FLinearColor(0.5f, 0.5f, 0.5f);

			// Fill
			FSlateDrawElement::MakeBox(
				OutDrawElements,
				LayerId,
				AllottedGeometry.ToPaintGeometry(Size, FSlateLayoutTransform(TopLeft)),
				FAppStyle::GetBrush("WhiteBrush"),
				ESlateDrawEffect::None,
				Color
			);

			// Border
			TArray<FVector2D> BoxPoints;
			BoxPoints.Add(TopLeft);
			BoxPoints.Add(FVector2D(BottomRight.X, TopLeft.Y));
			BoxPoints.Add(BottomRight);
			BoxPoints.Add(FVector2D(TopLeft.X, BottomRight.Y));
			BoxPoints.Add(TopLeft);

			FSlateDrawElement::MakeLines(
				OutDrawElements,
				LayerId + 1,
				AllottedGeometry.ToPaintGeometry(),
				BoxPoints,
				ESlateDrawEffect::None,
				BorderColor,
				true,
				2.0f
			);

			// Index label with dimensions
			FString IndexText = FString::Printf(TEXT("%d"), Sprite.Index);
			FString DimText = FString::Printf(TEXT("%dx%d"), Sprite.Bounds.Width(), Sprite.Bounds.Height());
			FSlateFontInfo FontInfo = FCoreStyle::GetDefaultFontStyle("Bold", 10);
			FSlateFontInfo SmallFontInfo = FCoreStyle::GetDefaultFontStyle("Regular", 9);

			// Draw index number
			FSlateDrawElement::MakeText(
				OutDrawElements,
				LayerId + 2,
				AllottedGeometry.ToPaintGeometry(FVector2D(50, 20), FSlateLayoutTransform(TopLeft + FVector2D(4, 2))),
				IndexText,
				FontInfo,
				ESlateDrawEffect::None,
				FLinearColor::White
			);

			// Draw dimension text below sprite box
			FSlateDrawElement::MakeText(
				OutDrawElements,
				LayerId + 2,
				AllottedGeometry.ToPaintGeometry(FVector2D(100, 16), FSlateLayoutTransform(FVector2D(TopLeft.X + 4, BottomRight.Y + 2))),
				DimText,
				SmallFontInfo,
				ESlateDrawEffect::None,
				FLinearColor(0.8f, 0.8f, 0.8f)
			);

			// Show uniform size overlay
			if (bShowUniformOverlay && UniformSize.X > 0 && UniformSize.Y > 0)
			{
				FVector2D OrigTopLeft = TextureToScreen(AllottedGeometry, FVector2D(Sprite.OriginalBounds.Min.X, Sprite.OriginalBounds.Min.Y));
				FVector2D OrigBottomRight = TextureToScreen(AllottedGeometry, FVector2D(Sprite.OriginalBounds.Max.X, Sprite.OriginalBounds.Max.Y));

				TArray<FVector2D> OrigPoints;
				OrigPoints.Add(OrigTopLeft);
				OrigPoints.Add(FVector2D(OrigBottomRight.X, OrigTopLeft.Y));
				OrigPoints.Add(OrigBottomRight);
				OrigPoints.Add(FVector2D(OrigTopLeft.X, OrigBottomRight.Y));
				OrigPoints.Add(OrigTopLeft);

				FSlateDrawElement::MakeLines(
					OutDrawElements,
					LayerId + 1,
					AllottedGeometry.ToPaintGeometry(),
					OrigPoints,
					ESlateDrawEffect::None,
					FLinearColor(1.0f, 1.0f, 0.0f, 0.5f),
					true,
					1.0f
				);
			}
		}
		LayerId += 3;
	}
	else
	{
		// Draw "No texture" message
		FSlateFontInfo FontInfo = FCoreStyle::GetDefaultFontStyle("Regular", 14);
		FSlateDrawElement::MakeText(
			OutDrawElements,
			LayerId,
			AllottedGeometry.ToPaintGeometry(FVector2D(200, 30), FSlateLayoutTransform(AllottedGeometry.GetLocalSize() * 0.5f - FVector2D(100, 15))),
			LOCTEXT("NoTexture", "No texture selected"),
			FontInfo,
			ESlateDrawEffect::None,
			FLinearColor(0.5f, 0.5f, 0.5f)
		);
		LayerId++;
	}

	return LayerId;
}

FReply SSpriteExtractorCanvas::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		int32 HitIndex = HitTestSprite(MyGeometry, MouseEvent.GetScreenSpacePosition());
		if (HitIndex >= 0)
		{
			ToggleSpriteSelection(HitIndex);
			return FReply::Handled();
		}
	}
	else if (MouseEvent.GetEffectingButton() == EKeys::MiddleMouseButton || MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		bIsPanning = true;
		LastMousePos = MouseEvent.GetScreenSpacePosition();
		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

FReply SSpriteExtractorCanvas::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bIsPanning && (MouseEvent.GetEffectingButton() == EKeys::MiddleMouseButton || MouseEvent.GetEffectingButton() == EKeys::RightMouseButton))
	{
		bIsPanning = false;
		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

FReply SSpriteExtractorCanvas::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bIsPanning)
	{
		FVector2D Delta = MouseEvent.GetScreenSpacePosition() - LastMousePos;
		PanOffset += Delta;
		LastMousePos = MouseEvent.GetScreenSpacePosition();
		return FReply::Handled();
	}

	return FReply::Unhandled();
}

FReply SSpriteExtractorCanvas::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	float Delta = MouseEvent.GetWheelDelta();
	float OldZoom = ZoomLevel;
	ZoomLevel = FMath::Clamp(ZoomLevel + Delta * 0.1f, 0.1f, 10.0f);

	// Zoom toward mouse position
	FVector2D MousePos = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
	FVector2D Center = MyGeometry.GetLocalSize() * 0.5f;
	FVector2D ToMouse = MousePos - Center - PanOffset;
	PanOffset += ToMouse * (1.0f - ZoomLevel / OldZoom);

	return FReply::Handled();
}

void SSpriteExtractorCanvas::SetTexture(UTexture2D* NewTexture)
{
	CurrentTexture = NewTexture;
	DetectedSprites.Empty();
	ResetView();
}

void SSpriteExtractorCanvas::SetDetectedSprites(const TArray<FDetectedSprite>& InSprites)
{
	DetectedSprites = InSprites;
}

void SSpriteExtractorCanvas::ToggleSpriteSelection(int32 Index)
{
	if (DetectedSprites.IsValidIndex(Index))
	{
		DetectedSprites[Index].bSelected = !DetectedSprites[Index].bSelected;
	}
}

void SSpriteExtractorCanvas::SelectAll(bool bSelect)
{
	for (FDetectedSprite& Sprite : DetectedSprites)
	{
		Sprite.bSelected = bSelect;
	}
}

void SSpriteExtractorCanvas::SetZoom(float NewZoom)
{
	ZoomLevel = FMath::Clamp(NewZoom, 0.1f, 10.0f);
}

void SSpriteExtractorCanvas::ResetView()
{
	ZoomLevel = 1.0f;
	PanOffset = FVector2D::ZeroVector;
}

int32 SSpriteExtractorCanvas::HitTestSprite(const FGeometry& Geom, const FVector2D& ScreenPos) const
{
	FVector2D LocalPos = Geom.AbsoluteToLocal(ScreenPos);
	FVector2D TexturePos = ScreenToTexture(Geom, LocalPos);

	for (int32 i = DetectedSprites.Num() - 1; i >= 0; i--)
	{
		const FDetectedSprite& Sprite = DetectedSprites[i];
		if (TexturePos.X >= Sprite.Bounds.Min.X && TexturePos.X < Sprite.Bounds.Max.X &&
			TexturePos.Y >= Sprite.Bounds.Min.Y && TexturePos.Y < Sprite.Bounds.Max.Y)
		{
			return i;
		}
	}

	return -1;
}

FVector2D SSpriteExtractorCanvas::ScreenToTexture(const FGeometry& Geom, const FVector2D& ScreenPos) const
{
	if (!CurrentTexture) return FVector2D::ZeroVector;

	FVector2D TextureSize(CurrentTexture->GetSizeX() * ZoomLevel, CurrentTexture->GetSizeY() * ZoomLevel);
	FVector2D DrawOffset = PanOffset + (Geom.GetLocalSize() - TextureSize) * 0.5f;
	return (ScreenPos - DrawOffset) / ZoomLevel;
}

FVector2D SSpriteExtractorCanvas::TextureToScreen(const FGeometry& Geom, const FVector2D& TexturePos) const
{
	if (!CurrentTexture) return FVector2D::ZeroVector;

	FVector2D TextureSize(CurrentTexture->GetSizeX() * ZoomLevel, CurrentTexture->GetSizeY() * ZoomLevel);
	FVector2D DrawOffset = PanOffset + (Geom.GetLocalSize() - TextureSize) * 0.5f;
	return TexturePos * ZoomLevel + DrawOffset;
}

// ============================================
// SSpriteExtractorWindow Implementation
// ============================================

void SSpriteExtractorWindow::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SSplitter)
		.Orientation(Orient_Horizontal)

		// Left panel - Settings
		+ SSplitter::Slot()
		.Value(0.3f)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					BuildTextureSection()
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					BuildDetectionSection()
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					BuildUniformSizingSection()
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					BuildOutputSection()
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					BuildCharacterAssetSection()
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					BuildButtonBar()
				]
			]
		]

		// Center - Canvas (wrapped in clipping box)
		+ SSplitter::Slot()
		.Value(0.5f)
		[
			SNew(SBox)
			.Clipping(EWidgetClipping::ClipToBounds)
			[
				SAssignNew(Canvas, SSpriteExtractorCanvas)
			]
		]

		// Right panel - Sprite list
		+ SSplitter::Slot()
		.Value(0.2f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(4)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("SelectAll", "Select All"))
					.OnClicked(this, &SSpriteExtractorWindow::OnSelectAllClicked)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("DeselectAll", "Deselect All"))
					.OnClicked(this, &SSpriteExtractorWindow::OnDeselectAllClicked)
				]
			]

			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			.Padding(4)
			[
				SNew(SScrollBox)
				+ SScrollBox::Slot()
				[
					SAssignNew(SpriteListBox, SVerticalBox)
				]
			]
		]
	];
}

TSharedRef<SWidget> SSpriteExtractorWindow::BuildTextureSection()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SourceTexture", "Source Texture"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SEditableTextBox)
				.IsReadOnly(true)
				.Text_Lambda([this]() { return FText::FromString(SourceTexturePath.IsEmpty() ? TEXT("No texture selected") : SourceTexturePath); })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(4, 0, 0, 0)
			[
				SNew(SButton)
				.Text(LOCTEXT("Browse", "Browse..."))
				.OnClicked(this, &SSpriteExtractorWindow::OnSelectTextureClicked)
			]
		];
}

TSharedRef<SWidget> SSpriteExtractorWindow::BuildDetectionSection()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Detection", "Detection Settings"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Mode", "Mode: "))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(4, 0)
			[
				SNew(SCheckBox)
				.IsChecked_Lambda([this]() { return DetectionMode == ESpriteDetectionMode::Island ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { if (State == ECheckBoxState::Checked) DetectionMode = ESpriteDetectionMode::Island; })
				[
					SNew(STextBlock).Text(LOCTEXT("Island", "Island"))
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(4, 0)
			[
				SNew(SCheckBox)
				.IsChecked_Lambda([this]() { return DetectionMode == ESpriteDetectionMode::Grid ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
				.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { if (State == ECheckBoxState::Checked) DetectionMode = ESpriteDetectionMode::Grid; })
				[
					SNew(STextBlock).Text(LOCTEXT("Grid", "Grid"))
				]
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("AlphaThreshold", "Alpha Threshold:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(SNumericEntryBox<int32>)
				.Value_Lambda([this]() { return AlphaThreshold; })
				.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) { AlphaThreshold = FMath::Clamp(Value, 0, 255); })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("MinSize", "Min Sprite Size:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(SNumericEntryBox<int32>)
				.Value_Lambda([this]() { return MinSpriteSize; })
				.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) { MinSpriteSize = FMath::Max(1, Value); })
			]
		]

		// Grid-specific settings
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)
			.Visibility_Lambda([this]() { return DetectionMode == ESpriteDetectionMode::Grid ? EVisibility::Visible : EVisibility::Collapsed; })

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("GridColumns", "Columns:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(SNumericEntryBox<int32>)
				.Value_Lambda([this]() { return GridColumns; })
				.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) { GridColumns = FMath::Max(1, Value); })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)
			.Visibility_Lambda([this]() { return DetectionMode == ESpriteDetectionMode::Grid ? EVisibility::Visible : EVisibility::Collapsed; })

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("GridRows", "Rows:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.5f)
			[
				SNew(SNumericEntryBox<int32>)
				.Value_Lambda([this]() { return GridRows; })
				.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) { GridRows = FMath::Max(1, Value); })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 8)
		[
			SNew(SButton)
			.Text(LOCTEXT("DetectSprites", "Detect Sprites"))
			.OnClicked(this, &SSpriteExtractorWindow::OnDetectSpritesClicked)
			.IsEnabled_Lambda([this]() { return SourceTexture != nullptr; })
		];
}

TSharedRef<SWidget> SSpriteExtractorWindow::BuildUniformSizingSection()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("UniformSizing", "Uniform Sizing"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SCheckBox)
			.IsChecked_Lambda([this]() { return bUseUniformSizing ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
			.OnCheckStateChanged_Lambda([this](ECheckBoxState State) {
				bUseUniformSizing = (State == ECheckBoxState::Checked);
				if (Canvas.IsValid() && Canvas->GetDetectedSprites().Num() > 0)
				{
					if (bUseUniformSizing)
					{
						ApplyUniformSizing();
					}
					else
					{
						// Reset bounds back to original
						TArray<FDetectedSprite>& CanvasSprites = Canvas->GetDetectedSprites();
						for (FDetectedSprite& Sprite : CanvasSprites)
						{
							Sprite.Bounds = Sprite.OriginalBounds;
						}
						Canvas->SetShowUniformOverlay(false);
					}
					RefreshSpriteList();
				}
			})
			[
				SNew(STextBlock).Text(LOCTEXT("UseUniformSize", "Use Uniform Size"))
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(0.25f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Width", "Width:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.25f)
			[
				SNew(SNumericEntryBox<int32>)
				.Value_Lambda([this]() { return UniformSize.X; })
				.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) {
					UniformSize.X = FMath::Max(1, Value);
					if (bUseUniformSizing && Canvas.IsValid() && Canvas->GetDetectedSprites().Num() > 0)
					{
						ApplyUniformSizing();
						RefreshSpriteList();
					}
				})
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.25f)
			.Padding(8, 0, 0, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Height", "Height:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.25f)
			[
				SNew(SNumericEntryBox<int32>)
				.Value_Lambda([this]() { return UniformSize.Y; })
				.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type) {
					UniformSize.Y = FMath::Max(1, Value);
					if (bUseUniformSizing && Canvas.IsValid() && Canvas->GetDetectedSprites().Num() > 0)
					{
						ApplyUniformSizing();
						RefreshSpriteList();
					}
				})
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SButton)
			.Text(LOCTEXT("CalcLargest", "Calculate Largest"))
			.OnClicked(this, &SSpriteExtractorWindow::OnCalculateLargestClicked)
			.IsEnabled_Lambda([this]() { return Canvas.IsValid() && Canvas->GetDetectedSprites().Num() > 0; })
		];
}

TSharedRef<SWidget> SSpriteExtractorWindow::BuildOutputSection()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Output", "Output Settings"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(0.3f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("OutputPath", "Output Path:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.7f)
			[
				SNew(SEditableTextBox)
				.Text_Lambda([this]() { return FText::FromString(OutputPath.IsEmpty() ? TEXT("/Game/Sprites") : OutputPath); })
				.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type) { OutputPath = Text.ToString(); })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(0.3f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SpritePrefix", "Sprite Prefix:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.7f)
			[
				SNew(SEditableTextBox)
				.Text_Lambda([this]() { return FText::FromString(SpritePrefix); })
				.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type) { SpritePrefix = Text.ToString(); })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SCheckBox)
			.IsChecked_Lambda([this]() { return bCreateFlipbook ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
			.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { bCreateFlipbook = (State == ECheckBoxState::Checked); })
			[
				SNew(STextBlock).Text(LOCTEXT("CreateFlipbook", "Create Flipbook"))
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)
			.Visibility_Lambda([this]() { return bCreateFlipbook ? EVisibility::Visible : EVisibility::Collapsed; })

			+ SHorizontalBox::Slot()
			.FillWidth(0.3f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("FlipbookName", "Flipbook Name:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.7f)
			[
				SNew(SEditableTextBox)
				.Text_Lambda([this]() { return FText::FromString(FlipbookName); })
				.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type) { FlipbookName = Text.ToString(); })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)
			.Visibility_Lambda([this]() { return bCreateFlipbook ? EVisibility::Visible : EVisibility::Collapsed; })

			+ SHorizontalBox::Slot()
			.FillWidth(0.3f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("FrameRate", "Frame Rate:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.7f)
			[
				SNew(SNumericEntryBox<float>)
				.Value_Lambda([this]() { return FlipbookFrameRate; })
				.OnValueCommitted_Lambda([this](float Value, ETextCommit::Type) { FlipbookFrameRate = FMath::Max(0.1f, Value); })
			]
		];
}

TSharedRef<SWidget> SSpriteExtractorWindow::BuildCharacterAssetSection()
{
	return SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("CharacterAsset", "Character Data Asset"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SCheckBox)
			.IsChecked_Lambda([this]() { return bAddToCharacterAsset ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
			.OnCheckStateChanged_Lambda([this](ECheckBoxState State) { bAddToCharacterAsset = (State == ECheckBoxState::Checked); })
			[
				SNew(STextBlock).Text(LOCTEXT("AddToAsset", "Add to Character Data Asset"))
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)
			.Visibility_Lambda([this]() { return bAddToCharacterAsset ? EVisibility::Visible : EVisibility::Collapsed; })

			+ SHorizontalBox::Slot()
			.FillWidth(0.3f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("TargetAsset", "Target Asset:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.7f)
			[
				SNew(SObjectPropertyEntryBox)
				.AllowedClass(UPaper2DPlusCharacterDataAsset::StaticClass())
				.ObjectPath_Lambda([this]() { return TargetCharacterAsset ? TargetCharacterAsset->GetPathName() : FString(); })
				.OnObjectChanged_Lambda([this](const FAssetData& AssetData) {
					TargetCharacterAsset = Cast<UPaper2DPlusCharacterDataAsset>(AssetData.GetAsset());
				})
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)
			.Visibility_Lambda([this]() { return bAddToCharacterAsset ? EVisibility::Visible : EVisibility::Collapsed; })

			+ SHorizontalBox::Slot()
			.FillWidth(0.3f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("AnimationName", "Animation Name:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.7f)
			[
				SNew(SEditableTextBox)
				.Text_Lambda([this]() { return FText::FromString(AnimationName); })
				.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type) { AnimationName = Text.ToString(); })
			]
		];
}

TSharedRef<SWidget> SSpriteExtractorWindow::BuildButtonBar()
{
	return SNew(SHorizontalBox)

		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		.Padding(4)
		[
			SNew(SButton)
			.Text(LOCTEXT("ExtractSprites", "Extract Sprites"))
			.OnClicked(this, &SSpriteExtractorWindow::OnExtractSpritesClicked)
			.IsEnabled_Lambda([this]()
			{
				if (!Canvas.IsValid()) return false;
				TArray<FDetectedSprite>& Sprites = Canvas->GetDetectedSprites();
				for (const FDetectedSprite& S : Sprites)
				{
					if (S.bSelected) return true;
				}
				return false;
			})
		];
}

void SSpriteExtractorWindow::SetInitialTexture(UTexture2D* Texture)
{
	if (Texture)
	{
		SourceTexture = Texture;
		SourceTexturePath = Texture->GetPathName();

		if (Canvas.IsValid())
		{
			Canvas->SetTexture(SourceTexture);
		}

		DetectedSprites.Empty();
		RefreshSpriteList();

		// Auto-set output path based on texture location
		FString TexturePath = FPackageName::GetLongPackagePath(SourceTexturePath);
		OutputPath = TexturePath + TEXT("/Sprites");

		// Auto-set prefix based on texture name
		SpritePrefix = SourceTexture->GetName() + TEXT("_");
	}
}

FReply SSpriteExtractorWindow::OnSelectTextureClicked()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	FOpenAssetDialogConfig Config;
	Config.DialogTitleOverride = LOCTEXT("SelectTexture", "Select Texture");
	Config.AssetClassNames.Add(UTexture2D::StaticClass()->GetClassPathName());
	Config.bAllowMultipleSelection = false;

	TArray<FAssetData> SelectedAssets = ContentBrowserModule.Get().CreateModalOpenAssetDialog(Config);
	if (SelectedAssets.Num() > 0)
	{
		SourceTexture = Cast<UTexture2D>(SelectedAssets[0].GetAsset());
		if (SourceTexture)
		{
			SourceTexturePath = SelectedAssets[0].GetObjectPathString();
			Canvas->SetTexture(SourceTexture);
			DetectedSprites.Empty();
			RefreshSpriteList();

			// Auto-set output path based on texture location
			FString TexturePath = FPackageName::GetLongPackagePath(SourceTexturePath);
			OutputPath = TexturePath + TEXT("/Sprites");

			// Auto-set prefix based on texture name
			SpritePrefix = SourceTexture->GetName() + TEXT("_");
		}
	}

	return FReply::Handled();
}

FReply SSpriteExtractorWindow::OnSelectAllClicked()
{
	Canvas->SelectAll(true);
	RefreshSpriteList();
	return FReply::Handled();
}

FReply SSpriteExtractorWindow::OnDeselectAllClicked()
{
	Canvas->SelectAll(false);
	RefreshSpriteList();
	return FReply::Handled();
}

FReply SSpriteExtractorWindow::OnDetectSpritesClicked()
{
	if (!SourceTexture) return FReply::Handled();

	DetectedSprites.Empty();

	if (DetectionMode == ESpriteDetectionMode::Island)
	{
		DetectIslands();
	}
	else
	{
		DetectGrid();
	}

	// First copy sprites to canvas
	Canvas->SetDetectedSprites(DetectedSprites);

	// Then apply uniform sizing if enabled (this modifies canvas sprites)
	if (bUseUniformSizing)
	{
		ApplyUniformSizing();
	}

	RefreshSpriteList();

	UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Detected %d sprites"), DetectedSprites.Num());

	return FReply::Handled();
}

FReply SSpriteExtractorWindow::OnExtractSpritesClicked()
{
	ExtractSprites();
	return FReply::Handled();
}

FReply SSpriteExtractorWindow::OnCalculateLargestClicked()
{
	FIntPoint Largest = CalculateLargestSize();
	UniformSize = Largest;
	Canvas->SetUniformSize(UniformSize);
	return FReply::Handled();
}

void SSpriteExtractorWindow::DetectIslands()
{
	TArray<FColor> Pixels;
	int32 Width, Height;
	if (!LoadTextureData(Pixels, Width, Height)) return;

	TArray<bool> Visited;
	Visited.SetNumZeroed(Width * Height);

	int32 Index = 0;
	for (int32 Y = 0; Y < Height; Y++)
	{
		for (int32 X = 0; X < Width; X++)
		{
			if (!Visited[Y * Width + X] && IsPixelOpaque(Pixels, Width, X, Y))
			{
				FIntRect Bounds(X, Y, X, Y);
				FloodFillMark(Visited, Pixels, Width, Height, X, Y, Bounds);

				// Check minimum size
				if (Bounds.Width() >= MinSpriteSize && Bounds.Height() >= MinSpriteSize)
				{
					FDetectedSprite Sprite;
					Sprite.Bounds = Bounds;
					Sprite.OriginalBounds = Bounds;
					Sprite.bSelected = true;
					Sprite.Index = Index++;
					DetectedSprites.Add(Sprite);
				}
			}
		}
	}

	// Sort by position (top-left to bottom-right)
	DetectedSprites.Sort([](const FDetectedSprite& A, const FDetectedSprite& B)
	{
		if (A.Bounds.Min.Y != B.Bounds.Min.Y)
			return A.Bounds.Min.Y < B.Bounds.Min.Y;
		return A.Bounds.Min.X < B.Bounds.Min.X;
	});

	// Re-index after sorting
	for (int32 i = 0; i < DetectedSprites.Num(); i++)
	{
		DetectedSprites[i].Index = i;
	}
}

void SSpriteExtractorWindow::DetectGrid()
{
	if (!SourceTexture || GridColumns < 1 || GridRows < 1) return;

	int32 Width = SourceTexture->GetSizeX();
	int32 Height = SourceTexture->GetSizeY();
	int32 CellWidth = Width / GridColumns;
	int32 CellHeight = Height / GridRows;

	int32 Index = 0;
	for (int32 Row = 0; Row < GridRows; Row++)
	{
		for (int32 Col = 0; Col < GridColumns; Col++)
		{
			FDetectedSprite Sprite;
			Sprite.Bounds = FIntRect(
				Col * CellWidth,
				Row * CellHeight,
				(Col + 1) * CellWidth,
				(Row + 1) * CellHeight
			);
			Sprite.OriginalBounds = Sprite.Bounds;
			Sprite.bSelected = true;
			Sprite.Index = Index++;
			DetectedSprites.Add(Sprite);
		}
	}
}

void SSpriteExtractorWindow::ApplyUniformSizing()
{
	if (!Canvas.IsValid()) return;

	TArray<FDetectedSprite>& CanvasSprites = Canvas->GetDetectedSprites();
	for (FDetectedSprite& Sprite : CanvasSprites)
	{
		Sprite.Bounds = CalculateAnchoredBounds(Sprite.OriginalBounds, UniformSize, UniformAnchor);
	}
	Canvas->SetUniformSize(UniformSize);
	Canvas->SetShowUniformOverlay(true);
}

FIntPoint SSpriteExtractorWindow::CalculateLargestSize() const
{
	FIntPoint Largest(0, 0);
	if (!Canvas.IsValid()) return Largest;

	const TArray<FDetectedSprite>& CanvasSprites = const_cast<SSpriteExtractorCanvas*>(Canvas.Get())->GetDetectedSprites();
	for (const FDetectedSprite& Sprite : CanvasSprites)
	{
		if (Sprite.bSelected)
		{
			Largest.X = FMath::Max(Largest.X, Sprite.OriginalBounds.Width());
			Largest.Y = FMath::Max(Largest.Y, Sprite.OriginalBounds.Height());
		}
	}
	return Largest;
}

bool SSpriteExtractorWindow::ExtractSprites()
{
	if (!SourceTexture || !Canvas.IsValid()) return false;

	// Collect selected sprites from canvas (which has the current selection state)
	TArray<FDetectedSprite> SelectedSprites;
	TArray<FDetectedSprite>& CanvasSprites = Canvas->GetDetectedSprites();
	for (const FDetectedSprite& Sprite : CanvasSprites)
	{
		if (Sprite.bSelected)
		{
			SelectedSprites.Add(Sprite);
		}
	}

	if (SelectedSprites.Num() == 0) return false;

	FScopedSlowTask Progress(SelectedSprites.Num(), LOCTEXT("ExtractingSprites", "Extracting sprites..."));
	Progress.MakeDialog();

	TArray<UPaperSprite*> CreatedSprites;

	for (int32 i = 0; i < SelectedSprites.Num(); i++)
	{
		Progress.EnterProgressFrame(1);

		const FDetectedSprite& Sprite = SelectedSprites[i];
		UPaperSprite* NewSprite = CreateSpriteFromBounds(Sprite.Bounds, i);
		if (NewSprite)
		{
			CreatedSprites.Add(NewSprite);
		}
	}

	// Create flipbook if requested
	UPaperFlipbook* Flipbook = nullptr;
	if (bCreateFlipbook && CreatedSprites.Num() > 0)
	{
		Flipbook = CreateFlipbook(CreatedSprites);
	}

	// Add to character asset if requested
	if (bAddToCharacterAsset && TargetCharacterAsset && Flipbook)
	{
		FScopedTransaction Transaction(LOCTEXT("AddAnimation", "Add Animation to Character Asset"));
		TargetCharacterAsset->Modify();

		FAnimationHitboxData NewAnimation;
		NewAnimation.AnimationName = AnimationName;
		NewAnimation.Flipbook = Flipbook;
		NewAnimation.SourceTexture = SourceTexture;
		NewAnimation.SpriteDimensions = bUseUniformSizing ? UniformSize : CalculateLargestSize();

		// Create frame data for each sprite
		for (int32 i = 0; i < SelectedSprites.Num(); i++)
		{
			FFrameHitboxData FrameData;
			FrameData.FrameName = FString::Printf(TEXT("%s_%02d"), *AnimationName, i);
			NewAnimation.Frames.Add(FrameData);

			// Store extraction info
			FSpriteExtractionInfo ExtractionInfo;
			ExtractionInfo.SourceOffset = SelectedSprites[i].OriginalBounds.Min;
			ExtractionInfo.OriginalDimensions = SelectedSprites[i].GetOriginalSize();
			ExtractionInfo.CurrentDimensions = SelectedSprites[i].GetSize();
			ExtractionInfo.AlphaThreshold = AlphaThreshold;
			ExtractionInfo.Anchor = UniformAnchor;
			ExtractionInfo.bUsedUniformSizing = bUseUniformSizing;
			ExtractionInfo.ExtractionTime = FDateTime::Now();
			NewAnimation.FrameExtractionInfo.Add(ExtractionInfo);
		}

		TargetCharacterAsset->Animations.Add(NewAnimation);
	}

	return true;
}

UPaperSprite* SSpriteExtractorWindow::CreateSpriteFromBounds(const FIntRect& Bounds, int32 Index)
{
	if (!SourceTexture) return nullptr;

	FString PackagePath = OutputPath;
	FString SpriteName = FString::Printf(TEXT("%s%02d"), *SpritePrefix, Index);
	FString PackageName = PackagePath / SpriteName;

	UPackage* Package = CreatePackage(*PackageName);
	if (!Package) return nullptr;

	UPaperSprite* Sprite = NewObject<UPaperSprite>(Package, *SpriteName, RF_Public | RF_Standalone);
	if (!Sprite) return nullptr;

	// Initialize sprite with source region
	FSpriteAssetInitParameters InitParams;
	InitParams.Texture = SourceTexture;
	InitParams.Offset = FIntPoint(Bounds.Min.X, Bounds.Min.Y);
	InitParams.Dimension = FIntPoint(Bounds.Width(), Bounds.Height());
	InitParams.SetPixelsPerUnrealUnit(1.0f);
	Sprite->InitializeSprite(InitParams);

	// Mark package dirty and register
	Package->MarkPackageDirty();

	FAssetRegistryModule::AssetCreated(Sprite);

	return Sprite;
}

UPaperFlipbook* SSpriteExtractorWindow::CreateFlipbook(const TArray<UPaperSprite*>& Sprites)
{
	if (Sprites.Num() == 0) return nullptr;

	FString PackagePath = OutputPath;
	FString PackageName = PackagePath / FlipbookName;

	UPackage* Package = CreatePackage(*PackageName);
	if (!Package) return nullptr;

	UPaperFlipbook* Flipbook = NewObject<UPaperFlipbook>(Package, *FlipbookName, RF_Public | RF_Standalone);
	if (!Flipbook) return nullptr;

	// Use FScopedFlipbookMutator to modify the flipbook's protected members
	{
		FScopedFlipbookMutator Mutator(Flipbook);
		Mutator.FramesPerSecond = FlipbookFrameRate;
		Mutator.KeyFrames.Empty();

		for (UPaperSprite* Sprite : Sprites)
		{
			FPaperFlipbookKeyFrame KeyFrame;
			KeyFrame.Sprite = Sprite;
			KeyFrame.FrameRun = 1;
			Mutator.KeyFrames.Add(KeyFrame);
		}
	}

	// Mark package dirty and register
	Package->MarkPackageDirty();
	FAssetRegistryModule::AssetCreated(Flipbook);

	UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Created flipbook '%s' with %d frames at %.1f FPS"),
		*FlipbookName, Sprites.Num(), FlipbookFrameRate);

	return Flipbook;
}

void SSpriteExtractorWindow::RefreshSpriteList()
{
	if (!SpriteListBox.IsValid()) return;

	SpriteListBox->ClearChildren();

	TArray<FDetectedSprite>& Sprites = Canvas->GetDetectedSprites();
	for (int32 i = 0; i < Sprites.Num(); i++)
	{
		const FDetectedSprite& Sprite = Sprites[i];

		SpriteListBox->AddSlot()
		.AutoHeight()
		.Padding(2)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2)
			[
				SNew(SCheckBox)
				.IsChecked(Sprite.bSelected ? ECheckBoxState::Checked : ECheckBoxState::Unchecked)
				.OnCheckStateChanged_Lambda([this, i](ECheckBoxState State)
				{
					Canvas->ToggleSpriteSelection(i);
					RefreshSpriteList();
				})
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.VAlign(VAlign_Center)
			.Padding(4, 0)
			[
				SNew(STextBlock)
				.Text(FText::Format(LOCTEXT("SpriteEntry", "{0}: {1}x{2}"),
					FText::AsNumber(Sprite.Index),
					FText::AsNumber(Sprite.Bounds.Width()),
					FText::AsNumber(Sprite.Bounds.Height())))
			]
		];
	}
}

void SSpriteExtractorWindow::RefreshCanvas()
{
	if (Canvas.IsValid())
	{
		Canvas->SetDetectedSprites(DetectedSprites);
	}
}

bool SSpriteExtractorWindow::LoadTextureData(TArray<FColor>& OutPixels, int32& OutWidth, int32& OutHeight) const
{
	if (!SourceTexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpriteExtractor: No source texture"));
		return false;
	}

	OutWidth = SourceTexture->GetSizeX();
	OutHeight = SourceTexture->GetSizeY();

	UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Loading texture %s (%dx%d)"), *SourceTexture->GetName(), OutWidth, OutHeight);

	// Check if platform data exists
	if (!SourceTexture->GetPlatformData() || SourceTexture->GetPlatformData()->Mips.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpriteExtractor: No platform data or mips available"));
		return false;
	}

	// Get texture data
	FTexture2DMipMap& Mip = SourceTexture->GetPlatformData()->Mips[0];
	void* Data = Mip.BulkData.Lock(LOCK_READ_ONLY);

	if (!Data)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpriteExtractor: Could not lock bulk data - texture may not have CPU access"));
		Mip.BulkData.Unlock();
		return false;
	}

	int32 PixelCount = OutWidth * OutHeight;
	OutPixels.SetNum(PixelCount);

	EPixelFormat Format = SourceTexture->GetPixelFormat();
	UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Pixel format: %d"), (int32)Format);

	if (Format == PF_B8G8R8A8)
	{
		FMemory::Memcpy(OutPixels.GetData(), Data, PixelCount * sizeof(FColor));
		UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Loaded B8G8R8A8 data"));
	}
	else if (Format == PF_R8G8B8A8)
	{
		const uint8* SrcData = static_cast<const uint8*>(Data);
		for (int32 i = 0; i < PixelCount; i++)
		{
			OutPixels[i].R = SrcData[i * 4 + 0];
			OutPixels[i].G = SrcData[i * 4 + 1];
			OutPixels[i].B = SrcData[i * 4 + 2];
			OutPixels[i].A = SrcData[i * 4 + 3];
		}
		UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Loaded R8G8B8A8 data"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SpriteExtractor: Unsupported pixel format %d"), (int32)Format);
		Mip.BulkData.Unlock();
		return false;
	}

	Mip.BulkData.Unlock();
	UE_LOG(LogTemp, Log, TEXT("SpriteExtractor: Successfully loaded %d pixels"), PixelCount);
	return true;
}

bool SSpriteExtractorWindow::IsPixelOpaque(const TArray<FColor>& Pixels, int32 Width, int32 X, int32 Y) const
{
	int32 Index = Y * Width + X;
	if (Index < 0 || Index >= Pixels.Num()) return false;
	return Pixels[Index].A > AlphaThreshold;
}

void SSpriteExtractorWindow::FloodFillMark(TArray<bool>& Visited, const TArray<FColor>& Pixels, int32 Width, int32 Height, int32 StartX, int32 StartY, FIntRect& OutBounds) const
{
	TArray<FIntPoint> Stack;
	Stack.Push(FIntPoint(StartX, StartY));

	while (Stack.Num() > 0)
	{
		FIntPoint Pos = Stack.Pop();
		int32 X = Pos.X;
		int32 Y = Pos.Y;

		if (X < 0 || X >= Width || Y < 0 || Y >= Height) continue;

		int32 Index = Y * Width + X;
		if (Visited[Index]) continue;
		if (!IsPixelOpaque(Pixels, Width, X, Y)) continue;

		Visited[Index] = true;

		// Expand bounds
		OutBounds.Min.X = FMath::Min(OutBounds.Min.X, X);
		OutBounds.Min.Y = FMath::Min(OutBounds.Min.Y, Y);
		OutBounds.Max.X = FMath::Max(OutBounds.Max.X, X + 1);
		OutBounds.Max.Y = FMath::Max(OutBounds.Max.Y, Y + 1);

		// Add neighbors
		Stack.Push(FIntPoint(X + 1, Y));
		Stack.Push(FIntPoint(X - 1, Y));
		Stack.Push(FIntPoint(X, Y + 1));
		Stack.Push(FIntPoint(X, Y - 1));
	}
}

FIntRect SSpriteExtractorWindow::CalculateAnchoredBounds(const FIntRect& OriginalBounds, FIntPoint TargetSize, ESpriteAnchor Anchor) const
{
	FIntPoint OriginalSize(OriginalBounds.Width(), OriginalBounds.Height());
	FIntPoint SizeDiff = TargetSize - OriginalSize;

	FIntPoint Offset(0, 0);

	switch (Anchor)
	{
	case ESpriteAnchor::TopLeft:
		Offset = FIntPoint(0, 0);
		break;
	case ESpriteAnchor::TopCenter:
		Offset = FIntPoint(-SizeDiff.X / 2, 0);
		break;
	case ESpriteAnchor::TopRight:
		Offset = FIntPoint(-SizeDiff.X, 0);
		break;
	case ESpriteAnchor::CenterLeft:
		Offset = FIntPoint(0, -SizeDiff.Y / 2);
		break;
	case ESpriteAnchor::Center:
		Offset = FIntPoint(-SizeDiff.X / 2, -SizeDiff.Y / 2);
		break;
	case ESpriteAnchor::CenterRight:
		Offset = FIntPoint(-SizeDiff.X, -SizeDiff.Y / 2);
		break;
	case ESpriteAnchor::BottomLeft:
		Offset = FIntPoint(0, -SizeDiff.Y);
		break;
	case ESpriteAnchor::BottomCenter:
		Offset = FIntPoint(-SizeDiff.X / 2, -SizeDiff.Y);
		break;
	case ESpriteAnchor::BottomRight:
		Offset = FIntPoint(-SizeDiff.X, -SizeDiff.Y);
		break;
	}

	return FIntRect(
		OriginalBounds.Min + Offset,
		OriginalBounds.Min + Offset + TargetSize
	);
}

// ============================================
// FSpriteExtractorActions Implementation
// ============================================

TSharedPtr<FUICommandList> FSpriteExtractorActions::CommandList;

void FSpriteExtractorActions::RegisterMenus()
{
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateLambda([]()
	{
		// Extend texture context menu
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("ContentBrowser.AssetContextMenu.Texture2D");
		if (Menu)
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("GetAssetActions");
			Section.AddMenuEntry(
				"ExtractSprites",
				LOCTEXT("ExtractSprites", "Extract Sprites (Paper2D+)"),
				LOCTEXT("ExtractSpritesTooltip", "Open sprite extractor for this texture"),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.PaperSprite"),
				FUIAction(FExecuteAction::CreateLambda([]()
				{
					// Get selected textures from content browser
					FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
					TArray<FAssetData> SelectedAssets;
					ContentBrowserModule.Get().GetSelectedAssets(SelectedAssets);

					for (const FAssetData& Asset : SelectedAssets)
					{
						if (UTexture2D* Texture = Cast<UTexture2D>(Asset.GetAsset()))
						{
							OpenSpriteExtractorForTexture(Texture);
							break;
						}
					}
				}))
			);
		}

		// Add to Tools menu
		UToolMenu* ToolsMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
		if (ToolsMenu)
		{
			FToolMenuSection& Section = ToolsMenu->FindOrAddSection("Paper2DPlus");
			Section.AddMenuEntry(
				"OpenSpriteExtractor",
				LOCTEXT("OpenSpriteExtractor", "Sprite Extractor"),
				LOCTEXT("OpenSpriteExtractorTooltip", "Open the Paper2D+ Sprite Extractor"),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.PaperSprite"),
				FUIAction(FExecuteAction::CreateStatic(&FSpriteExtractorActions::OpenSpriteExtractor))
			);
		}
	}));
}

void FSpriteExtractorActions::UnregisterMenus()
{
	// Menus are automatically cleaned up when the module shuts down
}

void FSpriteExtractorActions::OpenSpriteExtractor()
{
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("SpriteExtractorTitle", "Paper2D+ Sprite Extractor"))
		.ClientSize(FVector2D(1400, 800))
		.SupportsMinimize(true)
		.SupportsMaximize(true);

	Window->SetContent(
		SNew(SSpriteExtractorWindow)
	);

	FSlateApplication::Get().AddWindow(Window);
}

void FSpriteExtractorActions::OpenSpriteExtractorForTexture(UTexture2D* Texture)
{
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("SpriteExtractorTitle", "Paper2D+ Sprite Extractor"))
		.ClientSize(FVector2D(1400, 800))
		.SupportsMinimize(true)
		.SupportsMaximize(true);

	TSharedRef<SSpriteExtractorWindow> ExtractorWidget = SNew(SSpriteExtractorWindow);

	// Set the initial texture
	if (Texture)
	{
		ExtractorWidget->SetInitialTexture(Texture);
	}

	Window->SetContent(ExtractorWidget);

	FSlateApplication::Get().AddWindow(Window);
}

#undef LOCTEXT_NAMESPACE
