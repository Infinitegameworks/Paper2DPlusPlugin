#include "Paper2DPlusCharacterDataAsset.h"
#include "PaperSprite.h"

UPaper2DPlusCharacterDataAsset::UPaper2DPlusCharacterDataAsset()
{
	DisplayName = TEXT("New Character Data");
}

FPrimaryAssetId UPaper2DPlusCharacterDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(TEXT("CharacterData"), GetFName());
}

void UPaper2DPlusCharacterDataAsset::PostLoad()
{
	Super::PostLoad();

	// Migrate old assets: populate missing dimension info from flipbooks
	for (FAnimationHitboxData& Anim : Animations)
	{
		// If we have a flipbook but no dimension info, try to extract it
		if (Anim.SpriteDimensions == FIntPoint::ZeroValue && !Anim.Flipbook.IsNull())
		{
			if (UPaperFlipbook* FB = Anim.Flipbook.LoadSynchronous())
			{
				// Get dimensions from first sprite
				if (FB->GetNumKeyFrames() > 0)
				{
					if (UPaperSprite* Sprite = FB->GetKeyFrameChecked(0).Sprite)
					{
						FVector2D SourceDim = Sprite->GetSourceSize();
						Anim.SpriteDimensions = FIntPoint(
							FMath::RoundToInt(SourceDim.X),
							FMath::RoundToInt(SourceDim.Y)
						);
					}
				}
			}
		}

		// Initialize extraction info array if empty but we have frames
		if (Anim.FrameExtractionInfo.Num() == 0 && Anim.Frames.Num() > 0)
		{
			Anim.FrameExtractionInfo.SetNum(Anim.Frames.Num());
			for (FSpriteExtractionInfo& Info : Anim.FrameExtractionInfo)
			{
				Info.CurrentDimensions = Anim.SpriteDimensions;
				// Other fields will be unknown for migrated assets
			}
		}
	}
}

const FAnimationHitboxData* UPaper2DPlusCharacterDataAsset::FindAnimation(const FString& AnimationName) const
{
	for (const FAnimationHitboxData& Anim : Animations)
	{
		if (Anim.AnimationName.Equals(AnimationName, ESearchCase::IgnoreCase))
		{
			return &Anim;
		}
	}
	return nullptr;
}

TArray<FString> UPaper2DPlusCharacterDataAsset::GetAnimationNames() const
{
	TArray<FString> Names;
	Names.Reserve(Animations.Num());
	for (const FAnimationHitboxData& Anim : Animations)
	{
		Names.Add(Anim.AnimationName);
	}
	return Names;
}

bool UPaper2DPlusCharacterDataAsset::GetAnimation(const FString& AnimationName, FAnimationHitboxData& OutAnimation) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		OutAnimation = *Anim;
		return true;
	}
	return false;
}

bool UPaper2DPlusCharacterDataAsset::GetAnimationByIndex(int32 Index, FAnimationHitboxData& OutAnimation) const
{
	if (Animations.IsValidIndex(Index))
	{
		OutAnimation = Animations[Index];
		return true;
	}
	return false;
}

int32 UPaper2DPlusCharacterDataAsset::GetFrameCount(const FString& AnimationName) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		return Anim->Frames.Num();
	}
	return 0;
}

bool UPaper2DPlusCharacterDataAsset::GetFrame(const FString& AnimationName, int32 FrameIndex, FFrameHitboxData& OutFrame) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		if (const FFrameHitboxData* Frame = Anim->GetFrame(FrameIndex))
		{
			OutFrame = *Frame;
			return true;
		}
	}
	return false;
}

bool UPaper2DPlusCharacterDataAsset::GetFrameByName(const FString& AnimationName, const FString& FrameName, FFrameHitboxData& OutFrame) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		if (const FFrameHitboxData* Frame = Anim->GetFrameByName(FrameName))
		{
			OutFrame = *Frame;
			return true;
		}
	}
	return false;
}

bool UPaper2DPlusCharacterDataAsset::FindAnimationByFlipbook(UPaperFlipbook* Flipbook, FAnimationHitboxData& OutAnimation) const
{
	if (!Flipbook) return false;

	for (const FAnimationHitboxData& Anim : Animations)
	{
		if (Anim.Flipbook.Get() == Flipbook)
		{
			OutAnimation = Anim;
			return true;
		}
	}
	return false;
}

TArray<FHitboxData> UPaper2DPlusCharacterDataAsset::GetHitboxes(const FString& AnimationName, int32 FrameIndex) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		if (const FFrameHitboxData* Frame = Anim->GetFrame(FrameIndex))
		{
			return Frame->Hitboxes;
		}
	}
	return TArray<FHitboxData>();
}

TArray<FHitboxData> UPaper2DPlusCharacterDataAsset::GetHitboxesByType(const FString& AnimationName, int32 FrameIndex, EHitboxType Type) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		if (const FFrameHitboxData* Frame = Anim->GetFrame(FrameIndex))
		{
			return Frame->GetHitboxesByType(Type);
		}
	}
	return TArray<FHitboxData>();
}

TArray<FSocketData> UPaper2DPlusCharacterDataAsset::GetSockets(const FString& AnimationName, int32 FrameIndex) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		if (const FFrameHitboxData* Frame = Anim->GetFrame(FrameIndex))
		{
			return Frame->Sockets;
		}
	}
	return TArray<FSocketData>();
}

bool UPaper2DPlusCharacterDataAsset::FindSocket(const FString& AnimationName, int32 FrameIndex, const FString& SocketName, FSocketData& OutSocket) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		if (const FFrameHitboxData* Frame = Anim->GetFrame(FrameIndex))
		{
			if (const FSocketData* Socket = Frame->FindSocket(SocketName))
			{
				OutSocket = *Socket;
				return true;
			}
		}
	}
	return false;
}

bool UPaper2DPlusCharacterDataAsset::HasAnimation(const FString& AnimationName) const
{
	return FindAnimation(AnimationName) != nullptr;
}

// ==========================================
// DIMENSION MANAGEMENT IMPLEMENTATIONS
// ==========================================

FIntPoint UPaper2DPlusCharacterDataAsset::CalculateLargestDimensions() const
{
	FIntPoint Largest = FIntPoint::ZeroValue;
	for (const FAnimationHitboxData& Anim : Animations)
	{
		Largest.X = FMath::Max(Largest.X, Anim.SpriteDimensions.X);
		Largest.Y = FMath::Max(Largest.Y, Anim.SpriteDimensions.Y);

		// Also check frame extraction info for original dimensions
		for (const FSpriteExtractionInfo& Info : Anim.FrameExtractionInfo)
		{
			Largest.X = FMath::Max(Largest.X, Info.OriginalDimensions.X);
			Largest.Y = FMath::Max(Largest.Y, Info.OriginalDimensions.Y);
		}
	}
	return Largest;
}

EDimensionStatus UPaper2DPlusCharacterDataAsset::GetAnimationDimensionStatus(const FString& AnimationName) const
{
	if (const FAnimationHitboxData* Anim = FindAnimation(AnimationName))
	{
		return Anim->GetDimensionStatus(UniformDimensions);
	}
	return EDimensionStatus::Unknown;
}

bool UPaper2DPlusCharacterDataAsset::AllAnimationsMatchUniform() const
{
	if (UniformDimensions == FIntPoint::ZeroValue)
	{
		return false;
	}

	for (const FAnimationHitboxData& Anim : Animations)
	{
		if (Anim.GetDimensionStatus(UniformDimensions) != EDimensionStatus::MatchesUniform)
		{
			return false;
		}
	}
	return true;
}

TArray<FString> UPaper2DPlusCharacterDataAsset::GetMismatchedAnimations() const
{
	TArray<FString> Mismatched;
	for (const FAnimationHitboxData& Anim : Animations)
	{
		EDimensionStatus Status = Anim.GetDimensionStatus(UniformDimensions);
		if (Status != EDimensionStatus::MatchesUniform && Status != EDimensionStatus::NoUniformSet)
		{
			Mismatched.Add(Anim.AnimationName);
		}
	}
	return Mismatched;
}

void UPaper2DPlusCharacterDataAsset::GetDimensionStatusCounts(int32& OutMatching, int32& OutSmaller, int32& OutLarger, int32& OutUnknown) const
{
	OutMatching = 0;
	OutSmaller = 0;
	OutLarger = 0;
	OutUnknown = 0;

	for (const FAnimationHitboxData& Anim : Animations)
	{
		switch (Anim.GetDimensionStatus(UniformDimensions))
		{
		case EDimensionStatus::MatchesUniform:
			OutMatching++;
			break;
		case EDimensionStatus::SmallerThanUniform:
			OutSmaller++;
			break;
		case EDimensionStatus::LargerThanUniform:
			OutLarger++;
			break;
		default:
			OutUnknown++;
			break;
		}
	}
}

void UPaper2DPlusCharacterDataAsset::SetUniformToLargest()
{
	UniformDimensions = CalculateLargestDimensions();
	bUseUniformDimensions = true;
}
