#include "DimensionManagementPanel.h"
#include "Paper2DPlusCharacterDataAsset.h"
#include "SpriteReExtractor.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SExpandableArea.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"
#include "ScopedTransaction.h"
#include "Engine/Texture2D.h"
#include "PaperFlipbook.h"

#define LOCTEXT_NAMESPACE "DimensionManagementPanel"

// ============================================
// SDimensionPanelHeader Implementation
// ============================================

void SDimensionPanelHeader::Construct(const FArguments& InArgs)
{
	bIsExpanded = InArgs._IsExpanded;

	ChildSlot
	[
		SNew(SButton)
		.ButtonStyle(FAppStyle::Get(), "NoBorder")
		.OnClicked(InArgs._OnToggleExpansion)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(2, 0)
			[
				SNew(SImage)
				.Image_Lambda([this]()
				{
					return bIsExpanded.Get()
						? FAppStyle::GetBrush("TreeArrow_Expanded")
						: FAppStyle::GetBrush("TreeArrow_Collapsed");
				})
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.VAlign(VAlign_Center)
			.Padding(4, 2)
			[
				SNew(STextBlock)
				.Text(InArgs._Title)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
			]
		]
	];
}

// ============================================
// SDimensionManagementPanel Implementation
// ============================================

void SDimensionManagementPanel::Construct(const FArguments& InArgs)
{
	Asset = InArgs._Asset;

	UpdateAnimationRows();

	ChildSlot
	[
		SNew(SVerticalBox)

		// Uniform Settings Section
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(4)
		[
			BuildUniformSettingsSection()
		]

		// Animation Table
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(4)
		[
			BuildAnimationTable()
		]

		// Action Buttons
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(4)
		[
			BuildActionButtons()
		]
	];
}

void SDimensionManagementPanel::RefreshData()
{
	UpdateAnimationRows();

	if (AnimationListBox.IsValid())
	{
		AnimationListBox->ClearChildren();

		for (const FAnimationDimensionRow& Row : AnimationRows)
		{
			AnimationListBox->AddSlot()
			.AutoHeight()
			[
				BuildAnimationRow(Row)
			];
		}
	}
}

TSharedRef<SWidget> SDimensionManagementPanel::BuildUniformSettingsSection()
{
	return SNew(SVerticalBox)

		// Header
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("UniformDimensions", "Uniform Dimensions"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
		]

		// Enable checkbox
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SCheckBox)
			.IsChecked_Lambda([this]()
			{
				return Asset.IsValid() && Asset->bUseUniformDimensions
					? ECheckBoxState::Checked
					: ECheckBoxState::Unchecked;
			})
			.OnCheckStateChanged_Lambda([this](ECheckBoxState State)
			{
				if (Asset.IsValid())
				{
					FScopedTransaction Transaction(LOCTEXT("ToggleUniform", "Toggle Uniform Dimensions"));
					Asset->Modify();
					Asset->bUseUniformDimensions = (State == ECheckBoxState::Checked);
					RefreshData();
					OnAssetModified.ExecuteIfBound();
				}
			})
			[
				SNew(STextBlock).Text(LOCTEXT("UseUniformSize", "Use Uniform Dimensions for All Animations"))
			]
		]

		// Dimension inputs
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 8, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Width", "Width:"))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SBox)
				.WidthOverride(80)
				[
					SNew(SNumericEntryBox<int32>)
					.Value_Lambda([this]() { return Asset.IsValid() ? Asset->UniformDimensions.X : 64; })
					.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type)
					{
						if (Asset.IsValid())
						{
							FScopedTransaction Transaction(LOCTEXT("SetUniformWidth", "Set Uniform Width"));
							Asset->Modify();
							Asset->UniformDimensions.X = FMath::Max(1, Value);
							RefreshData();
							OnAssetModified.ExecuteIfBound();
						}
					})
				]
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(16, 0, 8, 0)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Height", "Height:"))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SBox)
				.WidthOverride(80)
				[
					SNew(SNumericEntryBox<int32>)
					.Value_Lambda([this]() { return Asset.IsValid() ? Asset->UniformDimensions.Y : 64; })
					.OnValueCommitted_Lambda([this](int32 Value, ETextCommit::Type)
					{
						if (Asset.IsValid())
						{
							FScopedTransaction Transaction(LOCTEXT("SetUniformHeight", "Set Uniform Height"));
							Asset->Modify();
							Asset->UniformDimensions.Y = FMath::Max(1, Value);
							RefreshData();
							OnAssetModified.ExecuteIfBound();
						}
					})
				]
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNullWidget::NullWidget
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(8, 0, 0, 0)
			[
				SNew(SButton)
				.Text(LOCTEXT("CalcLargest", "Calculate Largest"))
				.OnClicked(this, &SDimensionManagementPanel::OnCalculateLargestClicked)
				.IsEnabled_Lambda([this]() { return Asset.IsValid() && Asset->Animations.Num() > 0; })
			]
		]

		// Status summary
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 8, 0, 4)
		[
			SNew(STextBlock)
			.Text_Lambda([this]()
			{
				int32 Matching = CountMatchingAnimations();
				int32 Total = AnimationRows.Num();
				return FText::Format(LOCTEXT("StatusSummary", "Status: {0}/{1} animations match uniform dimensions"),
					FText::AsNumber(Matching), FText::AsNumber(Total));
			})
			.ColorAndOpacity_Lambda([this]()
			{
				int32 Matching = CountMatchingAnimations();
				int32 Total = AnimationRows.Num();
				if (Total == 0) return FSlateColor(FLinearColor::Gray);
				return Matching == Total
					? FSlateColor(FLinearColor::Green)
					: FSlateColor(FLinearColor(1.0f, 0.7f, 0.0f));
			})
		];
}

TSharedRef<SWidget> SDimensionManagementPanel::BuildAnimationTable()
{
	return SNew(SVerticalBox)

		// Table header
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(0.25f)
			.Padding(4, 2)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ColAnimation", "Animation"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.2f)
			.Padding(4, 2)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ColTexture", "Source Texture"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.15f)
			.Padding(4, 2)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ColSize", "Size"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.2f)
			.Padding(4, 2)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ColStatus", "Status"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(0.2f)
			.Padding(4, 2)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ColAction", "Action"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
			]
		]

		// Separator
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBox)
			.HeightOverride(1)
			[
				SNew(SImage)
				.Image(FAppStyle::GetBrush("WhiteBrush"))
				.ColorAndOpacity(FLinearColor(0.3f, 0.3f, 0.3f))
			]
		]

		// Animation list
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
			[
				SAssignNew(AnimationListBox, SVerticalBox)
			]
		];
}

TSharedRef<SWidget> SDimensionManagementPanel::BuildAnimationRow(const FAnimationDimensionRow& Row)
{
	return SNew(SHorizontalBox)

		// Animation name
		+ SHorizontalBox::Slot()
		.FillWidth(0.25f)
		.VAlign(VAlign_Center)
		.Padding(4, 4)
		[
			SNew(STextBlock)
			.Text(FText::FromString(Row.AnimationName))
		]

		// Source texture
		+ SHorizontalBox::Slot()
		.FillWidth(0.2f)
		.VAlign(VAlign_Center)
		.Padding(4, 4)
		[
			SNew(STextBlock)
			.Text(FText::FromString(Row.bHasSourceTexture ? Row.TextureName : TEXT("(none)")))
			.ColorAndOpacity(Row.bHasSourceTexture ? FSlateColor::UseForeground() : FSlateColor(FLinearColor::Gray))
		]

		// Size
		+ SHorizontalBox::Slot()
		.FillWidth(0.15f)
		.VAlign(VAlign_Center)
		.Padding(4, 4)
		[
			SNew(STextBlock)
			.Text(FText::Format(LOCTEXT("SizeFormat", "{0}x{1}"),
				FText::AsNumber(Row.SpriteDimensions.X),
				FText::AsNumber(Row.SpriteDimensions.Y)))
		]

		// Status
		+ SHorizontalBox::Slot()
		.FillWidth(0.2f)
		.VAlign(VAlign_Center)
		.Padding(4, 4)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 4, 0)
			[
				SNew(SBox)
				.WidthOverride(12)
				.HeightOverride(12)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("WhiteBrush"))
					.ColorAndOpacity(GetStatusColor(Row.Status))
				]
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(GetStatusText(Row.Status))
			]
		]

		// Action button
		+ SHorizontalBox::Slot()
		.FillWidth(0.2f)
		.VAlign(VAlign_Center)
		.Padding(4, 4)
		[
			SNew(SButton)
			.Text(LOCTEXT("ReExtract", "Re-Extract"))
			.IsEnabled(Row.bHasSourceTexture && Row.Status != EDimensionStatus::MatchesUniform)
			.OnClicked_Lambda([this, Index = Row.AnimationIndex]()
			{
				return OnReExtractAnimation(Index);
			})
		];
}

TSharedRef<SWidget> SDimensionManagementPanel::BuildActionButtons()
{
	return SNew(SHorizontalBox)

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(4)
		[
			SNew(SButton)
			.Text(LOCTEXT("ApplyUniformToAll", "Apply Uniform to All"))
			.OnClicked(this, &SDimensionManagementPanel::OnApplyUniformToAllClicked)
			.IsEnabled_Lambda([this]()
			{
				return Asset.IsValid() && Asset->bUseUniformDimensions && Asset->Animations.Num() > 0;
			})
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(4)
		[
			SNew(SButton)
			.Text_Lambda([this]()
			{
				int32 Mismatched = CountMismatchedAnimations();
				return FText::Format(LOCTEXT("ReExtractMismatched", "Re-Extract Mismatched ({0})"),
					FText::AsNumber(Mismatched));
			})
			.OnClicked(this, &SDimensionManagementPanel::OnReExtractMismatchedClicked)
			.IsEnabled_Lambda([this]()
			{
				return CountMismatchedAnimations() > 0;
			})
		];
}

FReply SDimensionManagementPanel::OnCalculateLargestClicked()
{
	if (!Asset.IsValid()) return FReply::Handled();

	FScopedTransaction Transaction(LOCTEXT("CalcLargest", "Calculate Largest Dimensions"));
	Asset->Modify();

	FIntPoint Largest = Asset->CalculateLargestDimensions();
	if (Largest.X > 0 && Largest.Y > 0)
	{
		Asset->UniformDimensions = Largest;
		RefreshData();
		OnAssetModified.ExecuteIfBound();
	}

	return FReply::Handled();
}

FReply SDimensionManagementPanel::OnApplyUniformToAllClicked()
{
	if (!Asset.IsValid()) return FReply::Handled();

	FScopedTransaction Transaction(LOCTEXT("ApplyUniform", "Apply Uniform Dimensions"));
	Asset->Modify();

	for (FAnimationHitboxData& Animation : Asset->Animations)
	{
		Animation.SpriteDimensions = Asset->UniformDimensions;
	}

	RefreshData();
	OnAssetModified.ExecuteIfBound();

	return FReply::Handled();
}

FReply SDimensionManagementPanel::OnReExtractMismatchedClicked()
{
	if (!Asset.IsValid()) return FReply::Handled();

	FScopedTransaction Transaction(LOCTEXT("ReExtractMismatched", "Re-Extract Mismatched Animations"));
	Asset->Modify();

	TArray<FReExtractionResult> Results = FSpriteReExtractor::ReExtractAllMismatched(Asset.Get());

	// Count successes and failures
	int32 Successes = 0;
	int32 Failures = 0;
	for (const FReExtractionResult& Result : Results)
	{
		if (Result.bSuccess)
			Successes++;
		else
			Failures++;
	}

	// Show notification
	FNotificationInfo Info(FText::Format(
		LOCTEXT("ReExtractComplete", "Re-extraction complete: {0} succeeded, {1} failed"),
		FText::AsNumber(Successes),
		FText::AsNumber(Failures)
	));
	Info.ExpireDuration = 3.0f;
	Info.bUseLargeFont = false;
	FSlateNotificationManager::Get().AddNotification(Info);

	RefreshData();
	OnAssetModified.ExecuteIfBound();

	return FReply::Handled();
}

FReply SDimensionManagementPanel::OnReExtractAnimation(int32 AnimationIndex)
{
	if (!Asset.IsValid()) return FReply::Handled();

	FString Reason;
	if (!FSpriteReExtractor::CanReExtractAnimation(Asset.Get(), AnimationIndex, Reason))
	{
		FNotificationInfo Info(FText::Format(
			LOCTEXT("CannotReExtract", "Cannot re-extract: {0}"),
			FText::FromString(Reason)
		));
		Info.ExpireDuration = 3.0f;
		Info.bUseLargeFont = false;
		FSlateNotificationManager::Get().AddNotification(Info);
		return FReply::Handled();
	}

	FScopedTransaction Transaction(LOCTEXT("ReExtractAnimation", "Re-Extract Animation"));
	Asset->Modify();

	FReExtractionResult Result = FSpriteReExtractor::ReExtractAnimation(Asset.Get(), AnimationIndex);

	// Show notification
	FNotificationInfo Info(Result.bSuccess
		? FText::Format(LOCTEXT("ReExtractSuccess", "Re-extracted {0} sprites"), FText::AsNumber(Result.SpritesCreated))
		: FText::Format(LOCTEXT("ReExtractFailed", "Re-extraction failed: {0}"), FText::FromString(Result.ErrorMessage))
	);
	Info.ExpireDuration = 3.0f;
	Info.bUseLargeFont = false;
	FSlateNotificationManager::Get().AddNotification(Info);

	RefreshData();
	OnAssetModified.ExecuteIfBound();

	return FReply::Handled();
}

void SDimensionManagementPanel::UpdateAnimationRows()
{
	AnimationRows.Empty();

	if (!Asset.IsValid()) return;

	for (int32 i = 0; i < Asset->Animations.Num(); i++)
	{
		const FAnimationHitboxData& Animation = Asset->Animations[i];

		FAnimationDimensionRow Row;
		Row.AnimationName = Animation.AnimationName;
		Row.AnimationIndex = i;
		Row.SpriteDimensions = Animation.SpriteDimensions;

		// Get texture name
		if (Animation.SourceTexture.IsValid())
		{
			Row.TextureName = Animation.SourceTexture.GetAssetName();
			Row.bHasSourceTexture = true;
		}
		else if (UTexture2D* LoadedTexture = Animation.SourceTexture.LoadSynchronous())
		{
			Row.TextureName = LoadedTexture->GetName();
			Row.bHasSourceTexture = true;
		}
		else
		{
			Row.TextureName = TEXT("");
			Row.bHasSourceTexture = false;
		}

		// Determine status
		Row.Status = Asset->GetAnimationDimensionStatus(Animation.AnimationName);

		AnimationRows.Add(Row);
	}

	// Refresh list widget if it exists
	if (AnimationListBox.IsValid())
	{
		AnimationListBox->ClearChildren();

		for (const FAnimationDimensionRow& Row : AnimationRows)
		{
			AnimationListBox->AddSlot()
			.AutoHeight()
			[
				BuildAnimationRow(Row)
			];
		}
	}
}

FLinearColor SDimensionManagementPanel::GetStatusColor(EDimensionStatus Status) const
{
	switch (Status)
	{
	case EDimensionStatus::MatchesUniform:
		return FLinearColor::Green;
	case EDimensionStatus::SmallerThanUniform:
		return FLinearColor(0.0f, 0.7f, 1.0f); // Light blue
	case EDimensionStatus::LargerThanUniform:
		return FLinearColor(1.0f, 0.5f, 0.0f); // Orange
	case EDimensionStatus::NoUniformSet:
		return FLinearColor::Gray;
	default:
		return FLinearColor::Gray;
	}
}

FText SDimensionManagementPanel::GetStatusText(EDimensionStatus Status) const
{
	switch (Status)
	{
	case EDimensionStatus::MatchesUniform:
		return LOCTEXT("StatusMatch", "OK");
	case EDimensionStatus::SmallerThanUniform:
		return LOCTEXT("StatusSmaller", "Smaller");
	case EDimensionStatus::LargerThanUniform:
		return LOCTEXT("StatusLarger", "Larger");
	case EDimensionStatus::NoUniformSet:
		return LOCTEXT("StatusNoUniform", "N/A");
	default:
		return LOCTEXT("StatusUnknown", "Unknown");
	}
}

int32 SDimensionManagementPanel::CountMatchingAnimations() const
{
	int32 Count = 0;
	for (const FAnimationDimensionRow& Row : AnimationRows)
	{
		if (Row.Status == EDimensionStatus::MatchesUniform)
		{
			Count++;
		}
	}
	return Count;
}

int32 SDimensionManagementPanel::CountMismatchedAnimations() const
{
	int32 Count = 0;
	for (const FAnimationDimensionRow& Row : AnimationRows)
	{
		if (Row.bHasSourceTexture &&
			Row.Status != EDimensionStatus::MatchesUniform &&
			Row.Status != EDimensionStatus::NoUniformSet)
		{
			Count++;
		}
	}
	return Count;
}

#undef LOCTEXT_NAMESPACE
