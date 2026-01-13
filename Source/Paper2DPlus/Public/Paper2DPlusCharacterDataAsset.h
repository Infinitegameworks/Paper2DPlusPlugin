#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Paper2DPlusTypes.h"
#include "PaperFlipbook.h"
#include "Engine/Texture2D.h"
#include "Paper2DPlusCharacterDataAsset.generated.h"

/**
 * Animation data with hitbox information and sprite extraction metadata
 */
USTRUCT(BlueprintType)
struct PAPER2DPLUS_API FAnimationHitboxData
{
	GENERATED_BODY()

	// ==========================================
	// EXISTING FIELDS (for backward compatibility)
	// ==========================================

	/** Name of the animation/flipbook group */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FString AnimationName;

	/** Optional reference to the Paper2D Flipbook for this animation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TSoftObjectPtr<UPaperFlipbook> Flipbook;

	/** All frames in this animation with hitbox data */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TArray<FFrameHitboxData> Frames;

	// ==========================================
	// NEW FIELDS FOR DIMENSION MANAGEMENT
	// ==========================================

	/** Source texture this animation was extracted from */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Source")
	TSoftObjectPtr<UTexture2D> SourceTexture;

	/** Current sprite dimensions for this animation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Dimensions")
	FIntPoint SpriteDimensions = FIntPoint::ZeroValue;

	/** Per-frame extraction metadata */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Source")
	TArray<FSpriteExtractionInfo> FrameExtractionInfo;

	/** Output path where sprites for this animation are saved */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Source")
	FString SpritesOutputPath;

	// ==========================================
	// EXISTING HELPER FUNCTIONS
	// ==========================================

	/** Get frame data by index */
	const FFrameHitboxData* GetFrame(int32 Index) const
	{
		if (Frames.IsValidIndex(Index))
		{
			return &Frames[Index];
		}
		return nullptr;
	}

	/** Get frame data by name */
	const FFrameHitboxData* GetFrameByName(const FString& FrameName) const
	{
		for (const FFrameHitboxData& Frame : Frames)
		{
			if (Frame.FrameName.Equals(FrameName, ESearchCase::IgnoreCase))
			{
				return &Frame;
			}
		}
		return nullptr;
	}

	/** Get total frame count */
	int32 GetFrameCount() const
	{
		return Frames.Num();
	}

	// ==========================================
	// NEW HELPER FUNCTIONS
	// ==========================================

	/** Get dimension status compared to a uniform size */
	EDimensionStatus GetDimensionStatus(FIntPoint UniformSize) const
	{
		if (UniformSize == FIntPoint::ZeroValue)
		{
			return EDimensionStatus::NoUniformSet;
		}

		if (SpriteDimensions == FIntPoint::ZeroValue)
		{
			return EDimensionStatus::Unknown;
		}

		if (SpriteDimensions == UniformSize)
		{
			return EDimensionStatus::MatchesUniform;
		}

		if (SpriteDimensions.X < UniformSize.X || SpriteDimensions.Y < UniformSize.Y)
		{
			return EDimensionStatus::SmallerThanUniform;
		}

		return EDimensionStatus::LargerThanUniform;
	}

	/** Check if this animation has extraction info available */
	bool HasExtractionInfo() const
	{
		return !SourceTexture.IsNull() && FrameExtractionInfo.Num() > 0;
	}

	/** Check if all frames have matching dimensions */
	bool HasConsistentDimensions() const
	{
		if (FrameExtractionInfo.Num() == 0) return true;

		FIntPoint FirstDims = FrameExtractionInfo[0].CurrentDimensions;
		for (const FSpriteExtractionInfo& Info : FrameExtractionInfo)
		{
			if (Info.CurrentDimensions != FirstDims) return false;
		}
		return true;
	}

	/** Get the largest dimensions found across all frames */
	FIntPoint GetLargestFrameDimensions() const
	{
		FIntPoint Largest = FIntPoint::ZeroValue;
		for (const FSpriteExtractionInfo& Info : FrameExtractionInfo)
		{
			Largest.X = FMath::Max(Largest.X, Info.OriginalDimensions.X);
			Largest.Y = FMath::Max(Largest.Y, Info.OriginalDimensions.Y);
		}
		return Largest;
	}
};

/**
 * Character Data Asset containing all animation hitbox data and sprite dimension management.
 * Manages flipbooks, hitboxes, sockets, and uniform dimensions across all character animations.
 */
UCLASS(BlueprintType, NotBlueprintable)
class PAPER2DPLUS_API UPaper2DPlusCharacterDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPaper2DPlusCharacterDataAsset();

	// ==========================================
	// EXISTING PROPERTIES (for backward compatibility)
	// ==========================================

	/** Display name for this character data (e.g., character name) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	FString DisplayName;

	/** All animations with their hitbox data */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	TArray<FAnimationHitboxData> Animations;

	/** Source JSON file path (for re-importing hitbox data) */
	UPROPERTY(VisibleAnywhere, Category = "Import")
	FString SourceFilePath;

	/** Last import timestamp */
	UPROPERTY(VisibleAnywhere, Category = "Import")
	FDateTime LastImportTime;

	// ==========================================
	// NEW PROPERTIES FOR DIMENSION MANAGEMENT
	// ==========================================

	/** Master uniform dimensions for all animations in this character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Uniform Dimensions")
	FIntPoint UniformDimensions = FIntPoint::ZeroValue;

	/** Whether to enforce uniform dimensions across all animations */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Uniform Dimensions")
	bool bUseUniformDimensions = false;

	/** Anchor point for uniform dimension alignment */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Uniform Dimensions")
	ESpriteAnchor UniformAnchor = ESpriteAnchor::BottomCenter;

	/** Alpha threshold to use for sprite extraction */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction Settings")
	int32 DefaultAlphaThreshold = 10;

	/** Padding to apply around detected sprites */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction Settings")
	int32 DefaultPadding = 0;

	/** Minimum sprite size filter */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction Settings")
	int32 DefaultMinSpriteSize = 4;

	// ==========================================
	// EXISTING LOOKUP FUNCTIONS
	// ==========================================

	/** Get all animation names */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	TArray<FString> GetAnimationNames() const;

	/** Get animation data by name */
	UFUNCTION(BlueprintCallable, Category = "Character Data")
	bool GetAnimation(const FString& AnimationName, FAnimationHitboxData& OutAnimation) const;

	/** Get animation data by index */
	UFUNCTION(BlueprintCallable, Category = "Character Data")
	bool GetAnimationByIndex(int32 Index, FAnimationHitboxData& OutAnimation) const;

	/** Get frame count for an animation */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	int32 GetFrameCount(const FString& AnimationName) const;

	/** Get frame data by animation name and frame index */
	UFUNCTION(BlueprintCallable, Category = "Character Data")
	bool GetFrame(const FString& AnimationName, int32 FrameIndex, FFrameHitboxData& OutFrame) const;

	/** Get frame data by animation name and frame name */
	UFUNCTION(BlueprintCallable, Category = "Character Data")
	bool GetFrameByName(const FString& AnimationName, const FString& FrameName, FFrameHitboxData& OutFrame) const;

	/** Find animation index by Flipbook reference */
	UFUNCTION(BlueprintCallable, Category = "Character Data")
	bool FindAnimationByFlipbook(UPaperFlipbook* Flipbook, FAnimationHitboxData& OutAnimation) const;

	// ==========================================
	// DIRECT HITBOX ACCESS
	// ==========================================

	/** Get all hitboxes for a specific frame */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	TArray<FHitboxData> GetHitboxes(const FString& AnimationName, int32 FrameIndex) const;

	/** Get hitboxes of a specific type for a frame */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	TArray<FHitboxData> GetHitboxesByType(const FString& AnimationName, int32 FrameIndex, EHitboxType Type) const;

	/** Get all sockets for a specific frame */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	TArray<FSocketData> GetSockets(const FString& AnimationName, int32 FrameIndex) const;

	/** Find a specific socket by name */
	UFUNCTION(BlueprintCallable, Category = "Character Data")
	bool FindSocket(const FString& AnimationName, int32 FrameIndex, const FString& SocketName, FSocketData& OutSocket) const;

	// ==========================================
	// ASSET INFO
	// ==========================================

	/** Get total number of animations */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	int32 GetAnimationCount() const { return Animations.Num(); }

	/** Check if a specific animation exists */
	UFUNCTION(BlueprintPure, Category = "Character Data")
	bool HasAnimation(const FString& AnimationName) const;

	// ==========================================
	// NEW DIMENSION MANAGEMENT FUNCTIONS
	// ==========================================

	/** Calculate the largest dimensions needed across all animations */
	UFUNCTION(BlueprintPure, Category = "Dimension Management")
	FIntPoint CalculateLargestDimensions() const;

	/** Get dimension status for a specific animation */
	UFUNCTION(BlueprintPure, Category = "Dimension Management")
	EDimensionStatus GetAnimationDimensionStatus(const FString& AnimationName) const;

	/** Check if all animations match uniform dimensions */
	UFUNCTION(BlueprintPure, Category = "Dimension Management")
	bool AllAnimationsMatchUniform() const;

	/** Get list of animations that don't match uniform dimensions */
	UFUNCTION(BlueprintPure, Category = "Dimension Management")
	TArray<FString> GetMismatchedAnimations() const;

	/** Get animation count by dimension status */
	UFUNCTION(BlueprintPure, Category = "Dimension Management")
	void GetDimensionStatusCounts(int32& OutMatching, int32& OutSmaller, int32& OutLarger, int32& OutUnknown) const;

	/** Set uniform dimensions to the largest found across all animations */
	UFUNCTION(BlueprintCallable, Category = "Dimension Management")
	void SetUniformToLargest();

	/** Get asset primary ID for async loading */
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	/** Populate dimension info from existing flipbooks (for migration) */
	virtual void PostLoad() override;

protected:
	/** Internal lookup - find animation by name */
	const FAnimationHitboxData* FindAnimation(const FString& AnimationName) const;
};
