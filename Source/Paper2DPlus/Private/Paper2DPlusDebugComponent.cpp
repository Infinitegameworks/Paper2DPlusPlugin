#include "Paper2DPlusDebugComponent.h"
#include "Paper2DPlusBlueprintLibrary.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UPaper2DPlusDebugComponent::UPaper2DPlusDebugComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

#if UE_BUILD_SHIPPING
	PrimaryComponentTick.bCanEverTick = false;
#endif
}

void UPaper2DPlusDebugComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!FlipbookComponent)
	{
		AutoFindFlipbookComponent();
	}
}

void UPaper2DPlusDebugComponent::AutoFindFlipbookComponent()
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	FlipbookComponent = Owner->FindComponentByClass<UPaperFlipbookComponent>();

	if (FlipbookComponent)
	{
		UE_LOG(LogTemp, Log, TEXT("Paper2DPlusDebugComponent: Auto-found FlipbookComponent on %s"), *Owner->GetName());
	}
}

void UPaper2DPlusDebugComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

#if !UE_BUILD_SHIPPING
	if (bEnableDebugDraw)
	{
		DrawHitboxesNow(0.0f);
	}
#endif
}

void UPaper2DPlusDebugComponent::SetDebugDrawEnabled(bool bEnabled)
{
	bEnableDebugDraw = bEnabled;
}

void UPaper2DPlusDebugComponent::SetFlipX(bool bNewFlipX)
{
	bFlipX = bNewFlipX;
}

void UPaper2DPlusDebugComponent::DrawHitboxesNow(float Duration)
{
#if !UE_BUILD_SHIPPING
	if (!CharacterData || !FlipbookComponent) return;

	UPaperFlipbook* Flipbook = FlipbookComponent->GetFlipbook();
	if (!Flipbook) return;

	FFrameHitboxData FrameData;
	float PlaybackPosition = FlipbookComponent->GetPlaybackPosition();

	if (!UPaper2DPlusBlueprintLibrary::GetHitboxFrameFromFlipbook(CharacterData, Flipbook, PlaybackPosition, FrameData))
		return;

	AActor* Owner = GetOwner();
	if (!Owner) return;

	FVector WorldPosition = Owner->GetActorLocation();

	for (const FHitboxData& Hitbox : FrameData.Hitboxes)
	{
		bool bShouldDraw = false;

		switch (Hitbox.Type)
		{
			case EHitboxType::Attack: bShouldDraw = bDrawAttackHitboxes; break;
			case EHitboxType::Hurtbox: bShouldDraw = bDrawHurtboxes; break;
			case EHitboxType::Collision: bShouldDraw = bDrawCollisionBoxes; break;
		}

		if (bShouldDraw)
		{
			DrawHitbox(Hitbox, WorldPosition, Duration);
		}
	}

	if (bDrawSockets)
	{
		for (const FSocketData& Socket : FrameData.Sockets)
		{
			DrawSocket(Socket, WorldPosition, Duration);
		}
	}
#endif
}

void UPaper2DPlusDebugComponent::DrawHitbox(const FHitboxData& Hitbox, const FVector& WorldPosition, float Duration)
{
	UWorld* World = GetWorld();
	if (!World) return;

	FColor DrawColor = GetColorForType(Hitbox.Type);

	float X = Hitbox.X * Scale;
	float Z = Hitbox.Y * Scale;
	float W = Hitbox.Width * Scale;
	float H = Hitbox.Height * Scale;

	if (bFlipX) X = -(X + W);

	FVector Min(WorldPosition.X + X, WorldPosition.Y, WorldPosition.Z + Z);
	FVector Max(WorldPosition.X + X + W, WorldPosition.Y, WorldPosition.Z + Z + H);

	DrawDebugLine(World, FVector(Min.X, Min.Y, Min.Z), FVector(Max.X, Min.Y, Min.Z), DrawColor, false, Duration, 0, LineThickness);
	DrawDebugLine(World, FVector(Max.X, Min.Y, Min.Z), FVector(Max.X, Min.Y, Max.Z), DrawColor, false, Duration, 0, LineThickness);
	DrawDebugLine(World, FVector(Max.X, Min.Y, Max.Z), FVector(Min.X, Min.Y, Max.Z), DrawColor, false, Duration, 0, LineThickness);
	DrawDebugLine(World, FVector(Min.X, Min.Y, Max.Z), FVector(Min.X, Min.Y, Min.Z), DrawColor, false, Duration, 0, LineThickness);

	FVector BoxCenter = (Min + Max) * 0.5f;
	FVector BoxExtent((Max.X - Min.X) * 0.5f, 2.0f, (Max.Z - Min.Z) * 0.5f);
	DrawDebugBox(World, BoxCenter, BoxExtent, DrawColor, false, Duration, 0, LineThickness * 0.5f);
}

void UPaper2DPlusDebugComponent::DrawSocket(const FSocketData& Socket, const FVector& WorldPosition, float Duration)
{
	UWorld* World = GetWorld();
	if (!World) return;

	FVector SocketWorld = UPaper2DPlusBlueprintLibrary::SocketToWorldSpace3D(Socket, WorldPosition, bFlipX, Scale);

	float CrossSize = 5.0f * Scale;
	DrawDebugLine(World, SocketWorld - FVector(CrossSize, 0, 0), SocketWorld + FVector(CrossSize, 0, 0), SocketColor, false, Duration, 0, LineThickness);
	DrawDebugLine(World, SocketWorld - FVector(0, 0, CrossSize), SocketWorld + FVector(0, 0, CrossSize), SocketColor, false, Duration, 0, LineThickness);
	DrawDebugPoint(World, SocketWorld, 8.0f, SocketColor, false, Duration);
	DrawDebugString(World, SocketWorld + FVector(0, 0, CrossSize + 5.0f), Socket.Name, nullptr, SocketColor, Duration, false, 1.0f);
}

FColor UPaper2DPlusDebugComponent::GetColorForType(EHitboxType Type) const
{
	switch (Type)
	{
		case EHitboxType::Attack: return AttackColor;
		case EHitboxType::Hurtbox: return HurtboxColor;
		case EHitboxType::Collision: return CollisionColor;
		default: return FColor::White;
	}
}
