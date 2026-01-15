#include "SpriteReExtractor.h"
#include "Paper2DPlusCharacterDataAsset.h"
#include "Engine/Texture2D.h"
#include "PaperSprite.h"
#include "PaperFlipbook.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "ObjectTools.h"
#include "ScopedTransaction.h"
#include "Misc/ScopedSlowTask.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "SpriteReExtractor"

FReExtractionResult FSpriteReExtractor::ReExtractAnimation(
	UPaper2DPlusCharacterDataAsset* Asset,
	int32 AnimationIndex)
{
	if (!Asset || !Asset->Animations.IsValidIndex(AnimationIndex))
	{
		FReExtractionResult Result;
		Result.bSuccess = false;
		Result.ErrorMessage = TEXT("Invalid asset or animation index");
		return Result;
	}

	return ReExtractAnimation(
		Asset,
		AnimationIndex,
		Asset->UniformDimensions,
		Asset->UniformAnchor
	);
}

FReExtractionResult FSpriteReExtractor::ReExtractAnimation(
	UPaper2DPlusCharacterDataAsset* Asset,
	int32 AnimationIndex,
	FIntPoint TargetDimensions,
	ESpriteAnchor Anchor)
{
	FReExtractionResult Result;

	if (!Asset)
	{
		Result.bSuccess = false;
		Result.ErrorMessage = TEXT("Asset is null");
		return Result;
	}

	if (!Asset->Animations.IsValidIndex(AnimationIndex))
	{
		Result.bSuccess = false;
		Result.ErrorMessage = TEXT("Invalid animation index");
		return Result;
	}

	FString Reason;
	if (!CanReExtractAnimation(Asset, AnimationIndex, Reason))
	{
		Result.bSuccess = false;
		Result.ErrorMessage = Reason;
		return Result;
	}

	FAnimationHitboxData& Animation = Asset->Animations[AnimationIndex];

	// Load source texture
	UTexture2D* SourceTexture = Animation.SourceTexture.LoadSynchronous();
	if (!SourceTexture)
	{
		Result.bSuccess = false;
		Result.ErrorMessage = TEXT("Could not load source texture");
		return Result;
	}

	// Load texture pixel data
	TArray<FColor> Pixels;
	int32 TexWidth, TexHeight;
	if (!LoadTextureData(SourceTexture, Pixels, TexWidth, TexHeight))
	{
		Result.bSuccess = false;
		Result.ErrorMessage = TEXT("Could not load texture pixel data");
		return Result;
	}

	// Get output path
	FString OutputPath = GetOutputPath(Asset, Animation);

	// Create progress dialog
	FScopedSlowTask Progress(Animation.FrameExtractionInfo.Num(),
		FText::Format(LOCTEXT("ReExtractingAnimation", "Re-extracting {0}..."),
		FText::FromString(Animation.AnimationName)));
	Progress.MakeDialog();

	// Delete old sprites if flipbook exists
	UPaperFlipbook* Flipbook = Animation.Flipbook.LoadSynchronous();
	if (Flipbook)
	{
		DeleteOldSprites(Flipbook);
	}

	// Re-extract each frame
	TArray<UPaperSprite*> NewSprites;
	for (int32 i = 0; i < Animation.FrameExtractionInfo.Num(); i++)
	{
		Progress.EnterProgressFrame(1);

		FSpriteExtractionInfo& ExtractionInfo = Animation.FrameExtractionInfo[i];

		// Calculate original bounds from extraction info
		FIntRect OriginalBounds(
			ExtractionInfo.SourceOffset.X,
			ExtractionInfo.SourceOffset.Y,
			ExtractionInfo.SourceOffset.X + ExtractionInfo.OriginalDimensions.X,
			ExtractionInfo.SourceOffset.Y + ExtractionInfo.OriginalDimensions.Y
		);

		// Calculate new bounds with uniform dimensions
		FIntRect NewBounds = CalculateAnchoredBounds(OriginalBounds, TargetDimensions, Anchor);

		// Clamp to texture bounds
		NewBounds.Min.X = FMath::Max(0, NewBounds.Min.X);
		NewBounds.Min.Y = FMath::Max(0, NewBounds.Min.Y);
		NewBounds.Max.X = FMath::Min(TexWidth, NewBounds.Max.X);
		NewBounds.Max.Y = FMath::Min(TexHeight, NewBounds.Max.Y);

		// Create sprite name
		FString SpriteName = FString::Printf(TEXT("%s_%02d"), *Animation.AnimationName, i);

		// Create the sprite
		UPaperSprite* NewSprite = CreateSpriteFromBounds(SourceTexture, NewBounds, SpriteName, OutputPath);
		if (NewSprite)
		{
			NewSprites.Add(NewSprite);

			// Update extraction info
			ExtractionInfo.CurrentDimensions = FIntPoint(NewBounds.Width(), NewBounds.Height());
			ExtractionInfo.Anchor = Anchor;
			ExtractionInfo.bUsedUniformSizing = true;
			ExtractionInfo.ExtractionTime = FDateTime::Now();
		}
	}

	// Update animation dimensions
	Animation.SpriteDimensions = TargetDimensions;

	// Update flipbook with new sprites
	if (Flipbook && NewSprites.Num() > 0)
	{
		UpdateFlipbookSprites(Flipbook, NewSprites);
		Result.UpdatedFlipbook = Flipbook;
	}

	Result.bSuccess = NewSprites.Num() > 0;
	Result.SpritesCreated = NewSprites.Num();
	Result.CreatedSprites = NewSprites;

	if (NewSprites.Num() == 0)
	{
		Result.ErrorMessage = TEXT("No sprites were created");
	}

	return Result;
}

TArray<FReExtractionResult> FSpriteReExtractor::ReExtractAllMismatched(
	UPaper2DPlusCharacterDataAsset* Asset)
{
	TArray<FReExtractionResult> Results;

	if (!Asset)
	{
		FReExtractionResult ErrorResult;
		ErrorResult.bSuccess = false;
		ErrorResult.ErrorMessage = TEXT("Asset is null");
		Results.Add(ErrorResult);
		return Results;
	}

	TArray<FString> MismatchedAnimations = Asset->GetMismatchedAnimations();

	FScopedSlowTask Progress(MismatchedAnimations.Num(),
		LOCTEXT("ReExtractingMismatched", "Re-extracting mismatched animations..."));
	Progress.MakeDialog();

	for (const FString& AnimName : MismatchedAnimations)
	{
		Progress.EnterProgressFrame(1);

		// Find animation index
		int32 AnimIndex = -1;
		for (int32 i = 0; i < Asset->Animations.Num(); i++)
		{
			if (Asset->Animations[i].AnimationName == AnimName)
			{
				AnimIndex = i;
				break;
			}
		}

		if (AnimIndex >= 0)
		{
			FReExtractionResult Result = ReExtractAnimation(Asset, AnimIndex);
			Results.Add(Result);
		}
	}

	return Results;
}

TArray<FReExtractionResult> FSpriteReExtractor::ReExtractAll(
	UPaper2DPlusCharacterDataAsset* Asset)
{
	TArray<FReExtractionResult> Results;

	if (!Asset)
	{
		FReExtractionResult ErrorResult;
		ErrorResult.bSuccess = false;
		ErrorResult.ErrorMessage = TEXT("Asset is null");
		Results.Add(ErrorResult);
		return Results;
	}

	FScopedSlowTask Progress(Asset->Animations.Num(),
		LOCTEXT("ReExtractingAll", "Re-extracting all animations..."));
	Progress.MakeDialog();

	for (int32 i = 0; i < Asset->Animations.Num(); i++)
	{
		Progress.EnterProgressFrame(1);
		FReExtractionResult Result = ReExtractAnimation(Asset, i);
		Results.Add(Result);
	}

	return Results;
}

bool FSpriteReExtractor::CanReExtractAnimation(
	UPaper2DPlusCharacterDataAsset* Asset,
	int32 AnimationIndex,
	FString& OutReason)
{
	if (!Asset)
	{
		OutReason = TEXT("Asset is null");
		return false;
	}

	if (!Asset->Animations.IsValidIndex(AnimationIndex))
	{
		OutReason = TEXT("Invalid animation index");
		return false;
	}

	const FAnimationHitboxData& Animation = Asset->Animations[AnimationIndex];

	// Check for source texture
	if (!Animation.SourceTexture.IsValid() && !Animation.SourceTexture.ToSoftObjectPath().IsValid())
	{
		OutReason = TEXT("No source texture set");
		return false;
	}

	// Check if we can load the source texture
	UTexture2D* SourceTexture = Animation.SourceTexture.LoadSynchronous();
	if (!SourceTexture)
	{
		OutReason = TEXT("Could not load source texture");
		return false;
	}

	// Check for extraction info
	if (Animation.FrameExtractionInfo.Num() == 0)
	{
		OutReason = TEXT("No extraction info available");
		return false;
	}

	return true;
}

bool FSpriteReExtractor::LoadTextureData(
	UTexture2D* Texture,
	TArray<FColor>& OutPixels,
	int32& OutWidth,
	int32& OutHeight)
{
	if (!Texture) return false;

	// Null check for platform data
	if (!Texture->GetPlatformData() || Texture->GetPlatformData()->Mips.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpriteReExtractor: Texture has no platform data or mips"));
		return false;
	}

	OutWidth = Texture->GetSizeX();
	OutHeight = Texture->GetSizeY();

	// Get texture data
	FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];
	void* Data = Mip.BulkData.Lock(LOCK_READ_ONLY);

	if (!Data)
	{
		Mip.BulkData.Unlock();
		return false;
	}

	int32 PixelCount = OutWidth * OutHeight;
	OutPixels.SetNum(PixelCount);

	EPixelFormat Format = Texture->GetPixelFormat();
	if (Format == PF_B8G8R8A8)
	{
		FMemory::Memcpy(OutPixels.GetData(), Data, PixelCount * sizeof(FColor));
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
	}
	else
	{
		Mip.BulkData.Unlock();
		return false;
	}

	Mip.BulkData.Unlock();
	return true;
}

UPaperSprite* FSpriteReExtractor::CreateSpriteFromBounds(
	UTexture2D* SourceTexture,
	const FIntRect& Bounds,
	const FString& SpriteName,
	const FString& OutputPath)
{
	if (!SourceTexture) return nullptr;

	FString PackageName = OutputPath / SpriteName;

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

FIntRect FSpriteReExtractor::CalculateAnchoredBounds(
	const FIntRect& OriginalBounds,
	FIntPoint TargetSize,
	ESpriteAnchor Anchor)
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

void FSpriteReExtractor::UpdateFlipbookSprites(
	UPaperFlipbook* Flipbook,
	const TArray<UPaperSprite*>& NewSprites)
{
	// Note: UPaperFlipbook doesn't expose setters for KeyFrames in UE 5.7
	// Flipbook update is not supported - users should recreate flipbooks manually
	if (!Flipbook) return;

	UE_LOG(LogTemp, Warning, TEXT("Flipbook update not supported in UE 5.7 - please recreate flipbook manually from extracted sprites"));

	// Show notification to user
	FNotificationInfo Info(LOCTEXT("FlipbookRecreateNote", "Sprites re-extracted. Please recreate the flipbook manually from the new sprites."));
	Info.ExpireDuration = 5.0f;
	Info.bUseSuccessFailIcons = false;
	FSlateNotificationManager::Get().AddNotification(Info);
}

void FSpriteReExtractor::DeleteOldSprites(UPaperFlipbook* Flipbook)
{
	if (!Flipbook) return;

	// Collect sprites to delete
	TArray<UObject*> SpritesToDelete;
	for (int32 i = 0; i < Flipbook->GetNumKeyFrames(); i++)
	{
		const FPaperFlipbookKeyFrame& KeyFrame = Flipbook->GetKeyFrameChecked(i);
		if (KeyFrame.Sprite)
		{
			SpritesToDelete.Add(KeyFrame.Sprite);
		}
	}

	// Delete sprites
	if (SpritesToDelete.Num() > 0)
	{
		ObjectTools::DeleteObjects(SpritesToDelete, false);
	}
}

FString FSpriteReExtractor::GetOutputPath(
	UPaper2DPlusCharacterDataAsset* Asset,
	const FAnimationHitboxData& Animation)
{
	// Try to use animation's stored output path
	if (!Animation.SpritesOutputPath.IsEmpty())
	{
		return Animation.SpritesOutputPath;
	}

	// Fall back to asset's folder + Animation name
	FString AssetPath = Asset->GetPathName();
	FString AssetFolder = FPaths::GetPath(AssetPath);
	return AssetFolder / TEXT("Sprites") / Animation.AnimationName;
}

#undef LOCTEXT_NAMESPACE
