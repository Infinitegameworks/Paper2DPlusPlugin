#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Paper2DPlusTypes.h"

class UPaper2DPlusCharacterDataAsset;

/**
 * Row data for the animation dimension table
 */
struct FAnimationDimensionRow
{
	FString AnimationName;
	FString TextureName;
	FIntPoint SpriteDimensions;
	EDimensionStatus Status;
	int32 AnimationIndex;
	bool bHasSourceTexture;
};

/**
 * Panel widget for managing uniform dimensions across all animations
 * in a Paper2DPlusCharacterDataAsset.
 */
class PAPER2DPLUSEDITOR_API SDimensionManagementPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDimensionManagementPanel) {}
		SLATE_ARGUMENT(UPaper2DPlusCharacterDataAsset*, Asset)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Refresh the panel data */
	void RefreshData();

	/** Delegate for when asset data is modified */
	DECLARE_DELEGATE(FOnAssetModified);
	FOnAssetModified OnAssetModified;

private:
	TWeakObjectPtr<UPaper2DPlusCharacterDataAsset> Asset;

	// Cached animation rows
	TArray<FAnimationDimensionRow> AnimationRows;

	// Widget references
	TSharedPtr<SVerticalBox> AnimationListBox;

	// UI Builders
	TSharedRef<SWidget> BuildUniformSettingsSection();
	TSharedRef<SWidget> BuildAnimationTable();
	TSharedRef<SWidget> BuildActionButtons();

	// Row widget builder
	TSharedRef<SWidget> BuildAnimationRow(const FAnimationDimensionRow& Row);

	// Actions
	FReply OnCalculateLargestClicked();
	FReply OnApplyUniformToAllClicked();
	FReply OnReExtractMismatchedClicked();
	FReply OnReExtractAnimation(int32 AnimationIndex);

	// Helpers
	void UpdateAnimationRows();
	FLinearColor GetStatusColor(EDimensionStatus Status) const;
	FText GetStatusText(EDimensionStatus Status) const;
	int32 CountMatchingAnimations() const;
	int32 CountMismatchedAnimations() const;
};

/**
 * Collapsible header for dimension panel
 */
class PAPER2DPLUSEDITOR_API SDimensionPanelHeader : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDimensionPanelHeader)
		: _IsExpanded(true)
	{}
		SLATE_ARGUMENT(FText, Title)
		SLATE_ATTRIBUTE(bool, IsExpanded)
		SLATE_EVENT(FOnClicked, OnToggleExpansion)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	TAttribute<bool> bIsExpanded;
};
