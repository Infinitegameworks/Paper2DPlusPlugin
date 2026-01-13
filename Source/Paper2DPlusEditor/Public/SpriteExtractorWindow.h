#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SLeafWidget.h"
#include "Paper2DPlusTypes.h"

class UTexture2D;
class UPaperSprite;
class UPaperFlipbook;
class UPaper2DPlusCharacterDataAsset;

/**
 * Detection mode for finding sprites in a texture
 */
enum class ESpriteDetectionMode : uint8
{
	Island,		// Detect isolated sprite regions by flood fill
	Grid		// Split texture into uniform grid cells
};

/**
 * Represents a detected sprite region in the source texture
 */
struct FDetectedSprite
{
	FIntRect Bounds;			// Bounding rectangle in texture space
	FIntRect OriginalBounds;	// Original tight-fit bounds before uniform sizing
	bool bSelected = true;		// Is this sprite selected for extraction?
	int32 Index = 0;			// Detection order index

	FIntPoint GetSize() const { return FIntPoint(Bounds.Width(), Bounds.Height()); }
	FIntPoint GetOriginalSize() const { return FIntPoint(OriginalBounds.Width(), OriginalBounds.Height()); }
};

/**
 * Canvas widget for displaying texture and detected sprites
 */
class PAPER2DPLUSEDITOR_API SSpriteExtractorCanvas : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SSpriteExtractorCanvas) {}
		SLATE_ARGUMENT(UTexture2D*, Texture)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SWidget interface
	virtual FVector2D ComputeDesiredSize(float) const override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	// Set new texture to display
	void SetTexture(UTexture2D* NewTexture);

	// Sprite data
	void SetDetectedSprites(const TArray<FDetectedSprite>& InSprites);
	TArray<FDetectedSprite>& GetDetectedSprites() { return DetectedSprites; }

	// Selection
	void ToggleSpriteSelection(int32 Index);
	void SelectAll(bool bSelect);

	// View control
	void SetZoom(float NewZoom);
	float GetZoom() const { return ZoomLevel; }
	void ResetView();

	// Uniform sizing display
	void SetUniformSize(FIntPoint Size) { UniformSize = Size; }
	void SetShowUniformOverlay(bool bShow) { bShowUniformOverlay = bShow; }

private:
	UTexture2D* CurrentTexture = nullptr;
	TArray<FDetectedSprite> DetectedSprites;

	float ZoomLevel = 1.0f;
	FVector2D PanOffset = FVector2D::ZeroVector;
	FVector2D LastMousePos;
	bool bIsPanning = false;

	// Uniform size display
	FIntPoint UniformSize = FIntPoint::ZeroValue;
	bool bShowUniformOverlay = true;

	// Hit testing
	int32 HitTestSprite(const FGeometry& Geom, const FVector2D& ScreenPos) const;
	FVector2D ScreenToTexture(const FGeometry& Geom, const FVector2D& ScreenPos) const;
	FVector2D TextureToScreen(const FGeometry& Geom, const FVector2D& TexturePos) const;
};

/**
 * Main sprite extractor window widget
 */
class PAPER2DPLUSEDITOR_API SSpriteExtractorWindow : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSpriteExtractorWindow) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Set the initial texture to extract from */
	void SetInitialTexture(UTexture2D* Texture);

private:
	// UI Components
	TSharedPtr<SSpriteExtractorCanvas> Canvas;
	TSharedPtr<SVerticalBox> SpriteListBox;

	// Source texture
	UTexture2D* SourceTexture = nullptr;
	FString SourceTexturePath;

	// Detection settings
	ESpriteDetectionMode DetectionMode = ESpriteDetectionMode::Island;
	int32 AlphaThreshold = 10;
	int32 MinSpriteSize = 4;

	// Grid mode settings
	int32 GridColumns = 4;
	int32 GridRows = 4;

	// Uniform sizing
	bool bUseUniformSizing = false;
	FIntPoint UniformSize = FIntPoint(64, 64);
	ESpriteAnchor UniformAnchor = ESpriteAnchor::BottomCenter;

	// Output settings
	FString OutputPath;
	FString SpritePrefix = TEXT("Sprite");
	bool bCreateFlipbook = true;
	FString FlipbookName = TEXT("NewFlipbook");
	float FlipbookFrameRate = 12.0f;

	// Character asset integration
	bool bAddToCharacterAsset = false;
	UPaper2DPlusCharacterDataAsset* TargetCharacterAsset = nullptr;
	FString AnimationName = TEXT("NewAnimation");

	// Detected sprites
	TArray<FDetectedSprite> DetectedSprites;

	// UI Builders
	TSharedRef<SWidget> BuildTextureSection();
	TSharedRef<SWidget> BuildDetectionSection();
	TSharedRef<SWidget> BuildUniformSizingSection();
	TSharedRef<SWidget> BuildOutputSection();
	TSharedRef<SWidget> BuildCharacterAssetSection();
	TSharedRef<SWidget> BuildSpriteList();
	TSharedRef<SWidget> BuildButtonBar();

	// Actions
	FReply OnSelectTextureClicked();
	FReply OnDetectSpritesClicked();
	FReply OnExtractSpritesClicked();
	FReply OnCalculateLargestClicked();
	FReply OnSelectAllClicked();
	FReply OnDeselectAllClicked();

	// Detection algorithms
	void DetectIslands();
	void DetectGrid();

	// Uniform sizing
	void ApplyUniformSizing();
	FIntPoint CalculateLargestSize() const;

	// Extraction
	bool ExtractSprites();
	UPaperSprite* CreateSpriteFromBounds(const FIntRect& Bounds, int32 Index);
	UPaperFlipbook* CreateFlipbook(const TArray<UPaperSprite*>& Sprites);

	// UI refresh
	void RefreshSpriteList();
	void RefreshCanvas();

	// Helpers
	bool LoadTextureData(TArray<FColor>& OutPixels, int32& OutWidth, int32& OutHeight) const;
	bool IsPixelOpaque(const TArray<FColor>& Pixels, int32 Width, int32 X, int32 Y) const;
	void FloodFillMark(TArray<bool>& Visited, const TArray<FColor>& Pixels, int32 Width, int32 Height, int32 StartX, int32 StartY, FIntRect& OutBounds) const;
	FIntRect CalculateAnchoredBounds(const FIntRect& OriginalBounds, FIntPoint TargetSize, ESpriteAnchor Anchor) const;
};

/**
 * Static actions for registering sprite extractor menus
 */
class PAPER2DPLUSEDITOR_API FSpriteExtractorActions
{
public:
	static void RegisterMenus();
	static void UnregisterMenus();

	static void OpenSpriteExtractor();
	static void OpenSpriteExtractorForTexture(UTexture2D* Texture);

private:
	static TSharedPtr<class FUICommandList> CommandList;
	static void OnTextureContextMenuExtension(class FMenuBuilder& MenuBuilder, TArray<TWeakObjectPtr<UTexture2D>> Textures);
};
