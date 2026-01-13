#include "Paper2DPlusBlueprintLibrary.h"
#include "PaperFlipbook.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// ==========================================
// WORLD SPACE CONVERSION
// ==========================================

FBox2D UPaper2DPlusBlueprintLibrary::HitboxToWorldSpace(const FHitboxData& Hitbox, FVector2D WorldPosition, bool bFlipX, float Scale)
{
	float X = Hitbox.X * Scale;
	float Y = Hitbox.Y * Scale;
	float W = Hitbox.Width * Scale;
	float H = Hitbox.Height * Scale;

	if (bFlipX)
	{
		X = -(X + W);
	}

	return FBox2D(
		FVector2D(WorldPosition.X + X, WorldPosition.Y + Y),
		FVector2D(WorldPosition.X + X + W, WorldPosition.Y + Y + H)
	);
}

FBox2D UPaper2DPlusBlueprintLibrary::HitboxToWorldSpace3D(const FHitboxData& Hitbox, FVector WorldPosition, bool bFlipX, float Scale)
{
	return HitboxToWorldSpace(Hitbox, FVector2D(WorldPosition.X, WorldPosition.Z), bFlipX, Scale);
}

FVector2D UPaper2DPlusBlueprintLibrary::SocketToWorldSpace(const FSocketData& Socket, FVector2D WorldPosition, bool bFlipX, float Scale)
{
	float X = Socket.X * Scale;
	float Y = Socket.Y * Scale;

	if (bFlipX)
	{
		X = -X;
	}

	return FVector2D(WorldPosition.X + X, WorldPosition.Y + Y);
}

FVector UPaper2DPlusBlueprintLibrary::SocketToWorldSpace3D(const FSocketData& Socket, FVector WorldPosition, bool bFlipX, float Scale)
{
	FVector2D Pos2D = SocketToWorldSpace(Socket, FVector2D(WorldPosition.X, WorldPosition.Z), bFlipX, Scale);
	return FVector(Pos2D.X, WorldPosition.Y, Pos2D.Y);
}

// ==========================================
// COLLISION DETECTION
// ==========================================

bool UPaper2DPlusBlueprintLibrary::DoBoxesOverlap(const FBox2D& BoxA, const FBox2D& BoxB)
{
	return BoxA.Intersect(BoxB);
}

bool UPaper2DPlusBlueprintLibrary::CheckHitboxCollision(
	const FFrameHitboxData& AttackerFrame,
	FVector2D AttackerPosition,
	bool bAttackerFlipX,
	float AttackerScale,
	const FFrameHitboxData& DefenderFrame,
	FVector2D DefenderPosition,
	bool bDefenderFlipX,
	float DefenderScale,
	TArray<FHitboxCollisionResult>& OutResults)
{
	OutResults.Empty();

	TArray<FHitboxData> AttackBoxes = AttackerFrame.GetHitboxesByType(EHitboxType::Attack);
	if (AttackBoxes.Num() == 0) return false;

	TArray<FHitboxData> HurtBoxes = DefenderFrame.GetHitboxesByType(EHitboxType::Hurtbox);
	if (HurtBoxes.Num() == 0) return false;

	bool bAnyHit = false;

	for (const FHitboxData& Attack : AttackBoxes)
	{
		FBox2D AttackWorld = HitboxToWorldSpace(Attack, AttackerPosition, bAttackerFlipX, AttackerScale);

		for (const FHitboxData& Hurt : HurtBoxes)
		{
			FBox2D HurtWorld = HitboxToWorldSpace(Hurt, DefenderPosition, bDefenderFlipX, DefenderScale);

			if (AttackWorld.Intersect(HurtWorld))
			{
				FHitboxCollisionResult Result;
				Result.bHit = true;
				Result.AttackHitbox = Attack;
				Result.HurtHitbox = Hurt;
				Result.Damage = Attack.Damage;
				Result.Knockback = Attack.Knockback;

				FBox2D Overlap(
					FVector2D(FMath::Max(AttackWorld.Min.X, HurtWorld.Min.X), FMath::Max(AttackWorld.Min.Y, HurtWorld.Min.Y)),
					FVector2D(FMath::Min(AttackWorld.Max.X, HurtWorld.Max.X), FMath::Min(AttackWorld.Max.Y, HurtWorld.Max.Y))
				);
				Result.HitLocation = Overlap.GetCenter();

				OutResults.Add(Result);
				bAnyHit = true;
			}
		}
	}

	return bAnyHit;
}

bool UPaper2DPlusBlueprintLibrary::CheckHitboxCollision3D(
	const FFrameHitboxData& AttackerFrame,
	FVector AttackerPosition,
	bool bAttackerFlipX,
	float AttackerScale,
	const FFrameHitboxData& DefenderFrame,
	FVector DefenderPosition,
	bool bDefenderFlipX,
	float DefenderScale,
	TArray<FHitboxCollisionResult>& OutResults)
{
	return CheckHitboxCollision(
		AttackerFrame, FVector2D(AttackerPosition.X, AttackerPosition.Z), bAttackerFlipX, AttackerScale,
		DefenderFrame, FVector2D(DefenderPosition.X, DefenderPosition.Z), bDefenderFlipX, DefenderScale,
		OutResults
	);
}

bool UPaper2DPlusBlueprintLibrary::QuickHitCheck(
	const FFrameHitboxData& AttackerFrame,
	FVector2D AttackerPosition,
	bool bAttackerFlipX,
	float AttackerScale,
	const FFrameHitboxData& DefenderFrame,
	FVector2D DefenderPosition,
	bool bDefenderFlipX,
	float DefenderScale)
{
	TArray<FHitboxData> AttackBoxes = AttackerFrame.GetHitboxesByType(EHitboxType::Attack);
	if (AttackBoxes.Num() == 0) return false;

	TArray<FHitboxData> HurtBoxes = DefenderFrame.GetHitboxesByType(EHitboxType::Hurtbox);
	if (HurtBoxes.Num() == 0) return false;

	for (const FHitboxData& Attack : AttackBoxes)
	{
		FBox2D AttackWorld = HitboxToWorldSpace(Attack, AttackerPosition, bAttackerFlipX, AttackerScale);

		for (const FHitboxData& Hurt : HurtBoxes)
		{
			FBox2D HurtWorld = HitboxToWorldSpace(Hurt, DefenderPosition, bDefenderFlipX, DefenderScale);

			if (AttackWorld.Intersect(HurtWorld))
			{
				return true;
			}
		}
	}

	return false;
}

bool UPaper2DPlusBlueprintLibrary::GetHitboxFrameFromFlipbook(
	UPaper2DPlusCharacterDataAsset* CharacterData,
	UPaperFlipbook* Flipbook,
	float PlaybackPosition,
	FFrameHitboxData& OutFrameData)
{
	if (!CharacterData || !Flipbook) return false;

	FAnimationHitboxData AnimData;
	if (!CharacterData->FindAnimationByFlipbook(Flipbook, AnimData)) return false;

	int32 NumKeyFrames = Flipbook->GetNumKeyFrames();
	if (NumKeyFrames == 0) return false;

	float TotalDuration = Flipbook->GetTotalDuration();
	if (TotalDuration <= 0.0f) return false;

	float WrappedPosition = FMath::Fmod(PlaybackPosition, TotalDuration);
	if (WrappedPosition < 0.0f) WrappedPosition += TotalDuration;

	int32 FrameIndex = Flipbook->GetKeyFrameIndexAtTime(WrappedPosition);
	FrameIndex = FMath::Clamp(FrameIndex, 0, NumKeyFrames - 1);

	if (AnimData.Frames.IsValidIndex(FrameIndex))
	{
		OutFrameData = AnimData.Frames[FrameIndex];
		return true;
	}

	return false;
}

bool UPaper2DPlusBlueprintLibrary::CheckAttackCollision(
	UPaper2DPlusCharacterDataAsset* AttackerData,
	UPaperFlipbook* AttackerFlipbook,
	float AttackerPlaybackPosition,
	FVector2D AttackerPosition,
	bool bAttackerFlipX,
	float AttackerScale,
	UPaper2DPlusCharacterDataAsset* DefenderData,
	UPaperFlipbook* DefenderFlipbook,
	float DefenderPlaybackPosition,
	FVector2D DefenderPosition,
	bool bDefenderFlipX,
	float DefenderScale,
	TArray<FHitboxCollisionResult>& OutResults)
{
	OutResults.Empty();

	FFrameHitboxData AttackerFrame;
	if (!GetHitboxFrameFromFlipbook(AttackerData, AttackerFlipbook, AttackerPlaybackPosition, AttackerFrame))
		return false;

	FFrameHitboxData DefenderFrame;
	if (!GetHitboxFrameFromFlipbook(DefenderData, DefenderFlipbook, DefenderPlaybackPosition, DefenderFrame))
		return false;

	return CheckHitboxCollision(
		AttackerFrame, AttackerPosition, bAttackerFlipX, AttackerScale,
		DefenderFrame, DefenderPosition, bDefenderFlipX, DefenderScale,
		OutResults
	);
}

bool UPaper2DPlusBlueprintLibrary::CheckAttackCollision3D(
	UPaper2DPlusCharacterDataAsset* AttackerData,
	UPaperFlipbook* AttackerFlipbook,
	float AttackerPlaybackPosition,
	FVector AttackerPosition,
	bool bAttackerFlipX,
	float AttackerScale,
	UPaper2DPlusCharacterDataAsset* DefenderData,
	UPaperFlipbook* DefenderFlipbook,
	float DefenderPlaybackPosition,
	FVector DefenderPosition,
	bool bDefenderFlipX,
	float DefenderScale,
	TArray<FHitboxCollisionResult>& OutResults)
{
	return CheckAttackCollision(
		AttackerData, AttackerFlipbook, AttackerPlaybackPosition,
		FVector2D(AttackerPosition.X, AttackerPosition.Z), bAttackerFlipX, AttackerScale,
		DefenderData, DefenderFlipbook, DefenderPlaybackPosition,
		FVector2D(DefenderPosition.X, DefenderPosition.Z), bDefenderFlipX, DefenderScale,
		OutResults
	);
}

// ==========================================
// FRAME DATA HELPERS
// ==========================================

int32 UPaper2DPlusBlueprintLibrary::GetFrameDamage(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition)
{
	FFrameHitboxData FrameData;
	if (!GetHitboxFrameFromFlipbook(CharacterData, Flipbook, PlaybackPosition, FrameData)) return 0;

	int32 TotalDamage = 0;
	for (const FHitboxData& Hitbox : FrameData.Hitboxes)
	{
		if (Hitbox.Type == EHitboxType::Attack) TotalDamage += Hitbox.Damage;
	}
	return TotalDamage;
}

int32 UPaper2DPlusBlueprintLibrary::GetFrameKnockback(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition)
{
	FFrameHitboxData FrameData;
	if (!GetHitboxFrameFromFlipbook(CharacterData, Flipbook, PlaybackPosition, FrameData)) return 0;

	int32 MaxKnockback = 0;
	for (const FHitboxData& Hitbox : FrameData.Hitboxes)
	{
		if (Hitbox.Type == EHitboxType::Attack && Hitbox.Knockback > MaxKnockback)
			MaxKnockback = Hitbox.Knockback;
	}
	return MaxKnockback;
}

bool UPaper2DPlusBlueprintLibrary::GetFrameDamageAndKnockback(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition, int32& OutDamage, int32& OutKnockback)
{
	OutDamage = 0;
	OutKnockback = 0;

	FFrameHitboxData FrameData;
	if (!GetHitboxFrameFromFlipbook(CharacterData, Flipbook, PlaybackPosition, FrameData)) return false;

	bool bHasAttack = false;
	for (const FHitboxData& Hitbox : FrameData.Hitboxes)
	{
		if (Hitbox.Type == EHitboxType::Attack)
		{
			bHasAttack = true;
			OutDamage += Hitbox.Damage;
			if (Hitbox.Knockback > OutKnockback) OutKnockback = Hitbox.Knockback;
		}
	}
	return bHasAttack;
}

bool UPaper2DPlusBlueprintLibrary::FrameHasAttack(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition)
{
	FFrameHitboxData FrameData;
	if (!GetHitboxFrameFromFlipbook(CharacterData, Flipbook, PlaybackPosition, FrameData)) return false;
	return FrameData.HasHitboxOfType(EHitboxType::Attack);
}

TArray<FHitboxData> UPaper2DPlusBlueprintLibrary::GetAttackHitboxes(const FFrameHitboxData& FrameData)
{
	return FrameData.GetHitboxesByType(EHitboxType::Attack);
}

TArray<FHitboxData> UPaper2DPlusBlueprintLibrary::GetHurtboxes(const FFrameHitboxData& FrameData)
{
	return FrameData.GetHitboxesByType(EHitboxType::Hurtbox);
}

TArray<FHitboxData> UPaper2DPlusBlueprintLibrary::GetCollisionBoxes(const FFrameHitboxData& FrameData)
{
	return FrameData.GetHitboxesByType(EHitboxType::Collision);
}

bool UPaper2DPlusBlueprintLibrary::HasAttackHitboxes(const FFrameHitboxData& FrameData)
{
	return FrameData.HasHitboxOfType(EHitboxType::Attack);
}

bool UPaper2DPlusBlueprintLibrary::HasHurtboxes(const FFrameHitboxData& FrameData)
{
	return FrameData.HasHitboxOfType(EHitboxType::Hurtbox);
}

bool UPaper2DPlusBlueprintLibrary::HasAnyData(const FFrameHitboxData& FrameData)
{
	return FrameData.Hitboxes.Num() > 0 || FrameData.Sockets.Num() > 0;
}

// ==========================================
// UTILITIES
// ==========================================

FString UPaper2DPlusBlueprintLibrary::HitboxTypeToString(EHitboxType Type)
{
	switch (Type)
	{
	case EHitboxType::Attack: return TEXT("Attack");
	case EHitboxType::Hurtbox: return TEXT("Hurtbox");
	case EHitboxType::Collision: return TEXT("Collision");
	default: return TEXT("Unknown");
	}
}

EHitboxType UPaper2DPlusBlueprintLibrary::StringToHitboxType(const FString& TypeString)
{
	if (TypeString.Equals(TEXT("hurtbox"), ESearchCase::IgnoreCase)) return EHitboxType::Hurtbox;
	if (TypeString.Equals(TEXT("collision"), ESearchCase::IgnoreCase)) return EHitboxType::Collision;
	return EHitboxType::Attack;
}

FVector2D UPaper2DPlusBlueprintLibrary::GetBoxCenter(const FBox2D& Box) { return Box.GetCenter(); }
FVector2D UPaper2DPlusBlueprintLibrary::GetBoxSize(const FBox2D& Box) { return Box.GetSize(); }
FBox2D UPaper2DPlusBlueprintLibrary::MakeBox2D(FVector2D Center, FVector2D HalfExtents) { return FBox2D(Center - HalfExtents, Center + HalfExtents); }

int32 UPaper2DPlusBlueprintLibrary::GetTotalDamage(const TArray<FHitboxCollisionResult>& Results)
{
	int32 Total = 0;
	for (const FHitboxCollisionResult& Result : Results) Total += Result.Damage;
	return Total;
}

int32 UPaper2DPlusBlueprintLibrary::GetMaxKnockback(const TArray<FHitboxCollisionResult>& Results)
{
	int32 Max = 0;
	for (const FHitboxCollisionResult& Result : Results)
		if (Result.Knockback > Max) Max = Result.Knockback;
	return Max;
}

// ==========================================
// DEBUG VISUALIZATION
// ==========================================

FColor UPaper2DPlusBlueprintLibrary::GetDebugColorForType(EHitboxType Type)
{
	switch (Type)
	{
	case EHitboxType::Attack: return FColor::Red;
	case EHitboxType::Hurtbox: return FColor::Green;
	case EHitboxType::Collision: return FColor::Blue;
	default: return FColor::White;
	}
}

void UPaper2DPlusBlueprintLibrary::DrawDebugHitboxes(
	UObject* WorldContext,
	const FFrameHitboxData& FrameData,
	FVector WorldPosition,
	bool bFlipX,
	float Scale,
	float Duration,
	float Thickness,
	bool bDrawSockets)
{
	if (!WorldContext) return;
	UWorld* World = WorldContext->GetWorld();
	if (!World) return;

	for (const FHitboxData& Hitbox : FrameData.Hitboxes)
	{
		DrawDebugHitbox(WorldContext, Hitbox, WorldPosition, bFlipX, Scale, FLinearColor::White, true, Duration, Thickness);
	}

	if (bDrawSockets)
	{
		for (const FSocketData& Socket : FrameData.Sockets)
		{
			FVector SocketWorld = SocketToWorldSpace3D(Socket, WorldPosition, bFlipX, Scale);
			float CrossSize = 5.0f * Scale;
			DrawDebugLine(World, SocketWorld - FVector(CrossSize, 0, 0), SocketWorld + FVector(CrossSize, 0, 0), FColor::Yellow, false, Duration, 0, Thickness);
			DrawDebugLine(World, SocketWorld - FVector(0, 0, CrossSize), SocketWorld + FVector(0, 0, CrossSize), FColor::Yellow, false, Duration, 0, Thickness);
			DrawDebugPoint(World, SocketWorld, 8.0f, FColor::Yellow, false, Duration);
		}
	}
}

void UPaper2DPlusBlueprintLibrary::DrawDebugHitboxesFromFlipbook(
	UObject* WorldContext,
	UPaper2DPlusCharacterDataAsset* CharacterData,
	UPaperFlipbook* Flipbook,
	float PlaybackPosition,
	FVector WorldPosition,
	bool bFlipX,
	float Scale,
	float Duration,
	float Thickness,
	bool bDrawSockets)
{
	FFrameHitboxData FrameData;
	if (!GetHitboxFrameFromFlipbook(CharacterData, Flipbook, PlaybackPosition, FrameData)) return;
	DrawDebugHitboxes(WorldContext, FrameData, WorldPosition, bFlipX, Scale, Duration, Thickness, bDrawSockets);
}

void UPaper2DPlusBlueprintLibrary::DrawDebugHitbox(
	UObject* WorldContext,
	const FHitboxData& Hitbox,
	FVector WorldPosition,
	bool bFlipX,
	float Scale,
	FLinearColor Color,
	bool bUseTypeColor,
	float Duration,
	float Thickness)
{
	if (!WorldContext) return;
	UWorld* World = WorldContext->GetWorld();
	if (!World) return;

	FColor DrawColor = bUseTypeColor ? GetDebugColorForType(Hitbox.Type) : Color.ToFColor(true);

	float X = Hitbox.X * Scale;
	float Z = Hitbox.Y * Scale;
	float W = Hitbox.Width * Scale;
	float H = Hitbox.Height * Scale;

	if (bFlipX) X = -(X + W);

	FVector BoxCenter(WorldPosition.X + X + W * 0.5f, WorldPosition.Y, WorldPosition.Z + Z + H * 0.5f);
	FVector BoxExtent(W * 0.5f, 2.0f, H * 0.5f);

	DrawDebugBox(World, BoxCenter, BoxExtent, DrawColor, false, Duration, 0, Thickness);

	FVector Min(WorldPosition.X + X, WorldPosition.Y, WorldPosition.Z + Z);
	FVector Max(WorldPosition.X + X + W, WorldPosition.Y, WorldPosition.Z + Z + H);

	DrawDebugLine(World, FVector(Min.X, Min.Y, Min.Z), FVector(Max.X, Min.Y, Min.Z), DrawColor, false, Duration, 0, Thickness);
	DrawDebugLine(World, FVector(Max.X, Min.Y, Min.Z), FVector(Max.X, Min.Y, Max.Z), DrawColor, false, Duration, 0, Thickness);
	DrawDebugLine(World, FVector(Max.X, Min.Y, Max.Z), FVector(Min.X, Min.Y, Max.Z), DrawColor, false, Duration, 0, Thickness);
	DrawDebugLine(World, FVector(Min.X, Min.Y, Max.Z), FVector(Min.X, Min.Y, Min.Z), DrawColor, false, Duration, 0, Thickness);
}
