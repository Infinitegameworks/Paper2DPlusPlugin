#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Paper2DPlusTypes.h"
#include "Paper2DPlusCharacterDataAsset.h"
#include "Paper2DPlusBlueprintLibrary.generated.h"

/**
 * Blueprint function library for Paper2DPlus operations.
 * Provides world-space conversion, collision detection, and utility functions.
 */
UCLASS()
class PAPER2DPLUS_API UPaper2DPlusBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ==========================================
	// WORLD SPACE CONVERSION
	// ==========================================

	/**
	 * Convert a hitbox to world space Box2D
	 * @param Hitbox The hitbox data
	 * @param WorldPosition Character's world position (2D)
	 * @param bFlipX Whether character is facing left (flips hitbox horizontally)
	 * @param Scale Scale multiplier (default 1.0)
	 * @return World-space Box2D
	 */
	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Conversion")
	static FBox2D HitboxToWorldSpace(const FHitboxData& Hitbox, FVector2D WorldPosition, bool bFlipX, float Scale = 1.0f);

	/**
	 * Convert a hitbox to world space with 3D vector position (uses X and Z for 2D)
	 */
	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Conversion")
	static FBox2D HitboxToWorldSpace3D(const FHitboxData& Hitbox, FVector WorldPosition, bool bFlipX, float Scale = 1.0f);

	/**
	 * Convert socket position to world space
	 */
	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Conversion")
	static FVector2D SocketToWorldSpace(const FSocketData& Socket, FVector2D WorldPosition, bool bFlipX, float Scale = 1.0f);

	/**
	 * Convert socket to world space with 3D vector (uses X and Z for 2D)
	 */
	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Conversion")
	static FVector SocketToWorldSpace3D(const FSocketData& Socket, FVector WorldPosition, bool bFlipX, float Scale = 1.0f);

	// ==========================================
	// COLLISION DETECTION
	// ==========================================

	/**
	 * Check if two Box2D overlap
	 */
	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Collision")
	static bool DoBoxesOverlap(const FBox2D& BoxA, const FBox2D& BoxB);

	/**
	 * Check collision between attacker and defender hitboxes (single frame)
	 */
	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Collision")
	static bool CheckHitboxCollision(
		const FFrameHitboxData& AttackerFrame,
		FVector2D AttackerPosition,
		bool bAttackerFlipX,
		float AttackerScale,
		const FFrameHitboxData& DefenderFrame,
		FVector2D DefenderPosition,
		bool bDefenderFlipX,
		float DefenderScale,
		TArray<FHitboxCollisionResult>& OutResults
	);

	/**
	 * Check collision using 3D positions (uses X and Z)
	 */
	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Collision")
	static bool CheckHitboxCollision3D(
		const FFrameHitboxData& AttackerFrame,
		FVector AttackerPosition,
		bool bAttackerFlipX,
		float AttackerScale,
		const FFrameHitboxData& DefenderFrame,
		FVector DefenderPosition,
		bool bDefenderFlipX,
		float DefenderScale,
		TArray<FHitboxCollisionResult>& OutResults
	);

	/**
	 * Quick check if any attack hitbox overlaps any hurtbox (no detailed results)
	 */
	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Collision")
	static bool QuickHitCheck(
		const FFrameHitboxData& AttackerFrame,
		FVector2D AttackerPosition,
		bool bAttackerFlipX,
		float AttackerScale,
		const FFrameHitboxData& DefenderFrame,
		FVector2D DefenderPosition,
		bool bDefenderFlipX,
		float DefenderScale
	);

	/**
	 * Get hitbox frame data from a Flipbook's current playback position
	 */
	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Collision")
	static bool GetHitboxFrameFromFlipbook(
		UPaper2DPlusCharacterDataAsset* CharacterData,
		UPaperFlipbook* Flipbook,
		float PlaybackPosition,
		FFrameHitboxData& OutFrameData
	);

	/**
	 * All-in-one collision check using Flipbooks
	 */
	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Collision")
	static bool CheckAttackCollision(
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
		TArray<FHitboxCollisionResult>& OutResults
	);

	/**
	 * All-in-one collision check using Flipbooks with 3D positions
	 */
	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Collision")
	static bool CheckAttackCollision3D(
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
		TArray<FHitboxCollisionResult>& OutResults
	);

	// ==========================================
	// FRAME DATA HELPERS
	// ==========================================

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static int32 GetFrameDamage(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static int32 GetFrameKnockback(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition);

	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Frame")
	static bool GetFrameDamageAndKnockback(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition, int32& OutDamage, int32& OutKnockback);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static bool FrameHasAttack(UPaper2DPlusCharacterDataAsset* CharacterData, UPaperFlipbook* Flipbook, float PlaybackPosition);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static TArray<FHitboxData> GetAttackHitboxes(const FFrameHitboxData& FrameData);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static TArray<FHitboxData> GetHurtboxes(const FFrameHitboxData& FrameData);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static TArray<FHitboxData> GetCollisionBoxes(const FFrameHitboxData& FrameData);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static bool HasAttackHitboxes(const FFrameHitboxData& FrameData);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static bool HasHurtboxes(const FFrameHitboxData& FrameData);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Frame")
	static bool HasAnyData(const FFrameHitboxData& FrameData);

	// ==========================================
	// UTILITIES
	// ==========================================

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static FString HitboxTypeToString(EHitboxType Type);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static EHitboxType StringToHitboxType(const FString& TypeString);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static FVector2D GetBoxCenter(const FBox2D& Box);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static FVector2D GetBoxSize(const FBox2D& Box);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static FBox2D MakeBox2D(FVector2D Center, FVector2D HalfExtents);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static int32 GetTotalDamage(const TArray<FHitboxCollisionResult>& Results);

	UFUNCTION(BlueprintPure, Category = "Paper2DPlus|Utilities")
	static int32 GetMaxKnockback(const TArray<FHitboxCollisionResult>& Results);

	// ==========================================
	// DEBUG VISUALIZATION
	// ==========================================

	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Debug", meta = (WorldContext = "WorldContext", DevelopmentOnly))
	static void DrawDebugHitboxes(
		UObject* WorldContext,
		const FFrameHitboxData& FrameData,
		FVector WorldPosition,
		bool bFlipX,
		float Scale = 1.0f,
		float Duration = 0.0f,
		float Thickness = 1.0f,
		bool bDrawSockets = true
	);

	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Debug", meta = (WorldContext = "WorldContext", DevelopmentOnly))
	static void DrawDebugHitboxesFromFlipbook(
		UObject* WorldContext,
		UPaper2DPlusCharacterDataAsset* CharacterData,
		UPaperFlipbook* Flipbook,
		float PlaybackPosition,
		FVector WorldPosition,
		bool bFlipX,
		float Scale = 1.0f,
		float Duration = 0.0f,
		float Thickness = 1.0f,
		bool bDrawSockets = true
	);

	UFUNCTION(BlueprintCallable, Category = "Paper2DPlus|Debug", meta = (WorldContext = "WorldContext", DevelopmentOnly))
	static void DrawDebugHitbox(
		UObject* WorldContext,
		const FHitboxData& Hitbox,
		FVector WorldPosition,
		bool bFlipX,
		float Scale = 1.0f,
		FLinearColor Color = FLinearColor::White,
		bool bUseTypeColor = true,
		float Duration = 0.0f,
		float Thickness = 1.0f
	);

private:
	static FColor GetDebugColorForType(EHitboxType Type);
};
