#pragma once

#include "CoreMinimal.h"
#include "Paper2DPlusTypes.h"
#include "Paper2DPlusCharacterDataAsset.h"

class UTexture2D;
class UPaperSprite;
class UPaperFlipbook;

/**
 * Result of a sprite re-extraction operation
 */
struct PAPER2DPLUSEDITOR_API FReExtractionResult
{
	bool bSuccess = false;
	FString ErrorMessage;
	int32 SpritesCreated = 0;
	TArray<UPaperSprite*> CreatedSprites;
	UPaperFlipbook* UpdatedFlipbook = nullptr;
};

/**
 * Handles re-extracting sprites from source textures with new dimensions.
 * Used when applying uniform dimensions to an existing character asset.
 */
class PAPER2DPLUSEDITOR_API FSpriteReExtractor
{
public:
	/**
	 * Re-extract sprites for a single animation in the character asset.
	 * Uses the asset's uniform dimensions and anchor settings.
	 *
	 * @param Asset The character data asset containing animation data
	 * @param AnimationIndex Index of the animation to re-extract
	 * @return Result containing success status, created sprites, and any error
	 */
	static FReExtractionResult ReExtractAnimation(
		UPaper2DPlusCharacterDataAsset* Asset,
		int32 AnimationIndex
	);

	/**
	 * Re-extract sprites for a single animation with custom dimensions.
	 *
	 * @param Asset The character data asset
	 * @param AnimationIndex Index of the animation to re-extract
	 * @param TargetDimensions The uniform size to apply
	 * @param Anchor Anchor point for alignment
	 * @return Result containing success status and created sprites
	 */
	static FReExtractionResult ReExtractAnimation(
		UPaper2DPlusCharacterDataAsset* Asset,
		int32 AnimationIndex,
		FIntPoint TargetDimensions,
		ESpriteAnchor Anchor
	);

	/**
	 * Re-extract all animations that don't match the uniform dimensions.
	 *
	 * @param Asset The character data asset
	 * @return Array of results, one per animation processed
	 */
	static TArray<FReExtractionResult> ReExtractAllMismatched(
		UPaper2DPlusCharacterDataAsset* Asset
	);

	/**
	 * Re-extract all animations in the asset.
	 *
	 * @param Asset The character data asset
	 * @return Array of results, one per animation
	 */
	static TArray<FReExtractionResult> ReExtractAll(
		UPaper2DPlusCharacterDataAsset* Asset
	);

	/**
	 * Check if an animation can be re-extracted.
	 * Requires: source texture, frame extraction info
	 *
	 * @param Asset The character data asset
	 * @param AnimationIndex Index of the animation to check
	 * @param OutReason If false, reason why re-extraction is not possible
	 * @return True if re-extraction is possible
	 */
	static bool CanReExtractAnimation(
		UPaper2DPlusCharacterDataAsset* Asset,
		int32 AnimationIndex,
		FString& OutReason
	);

private:
	/**
	 * Load pixel data from a texture
	 */
	static bool LoadTextureData(
		UTexture2D* Texture,
		TArray<FColor>& OutPixels,
		int32& OutWidth,
		int32& OutHeight
	);

	/**
	 * Create a new sprite from source texture bounds
	 */
	static UPaperSprite* CreateSpriteFromBounds(
		UTexture2D* SourceTexture,
		const FIntRect& Bounds,
		const FString& SpriteName,
		const FString& OutputPath
	);

	/**
	 * Calculate aligned bounds when applying uniform dimensions
	 */
	static FIntRect CalculateAnchoredBounds(
		const FIntRect& OriginalBounds,
		FIntPoint TargetSize,
		ESpriteAnchor Anchor
	);

	/**
	 * Update flipbook key frames with new sprites
	 */
	static void UpdateFlipbookSprites(
		UPaperFlipbook* Flipbook,
		const TArray<UPaperSprite*>& NewSprites
	);

	/**
	 * Delete old sprites that will be replaced
	 */
	static void DeleteOldSprites(
		UPaperFlipbook* Flipbook
	);

	/**
	 * Get output path for sprites based on animation and asset
	 */
	static FString GetOutputPath(
		UPaper2DPlusCharacterDataAsset* Asset,
		const FAnimationHitboxData& Animation
	);
};
