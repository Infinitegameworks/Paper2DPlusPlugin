// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Paper2DPlusBlueprintLibrary.h"

#ifdef PAPER2DPLUS_Paper2DPlusBlueprintLibrary_generated_h
#error "Paper2DPlusBlueprintLibrary.generated.h already included, missing '#pragma once' in Paper2DPlusBlueprintLibrary.h"
#endif
#define PAPER2DPLUS_Paper2DPlusBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UPaper2DPlusCharacterDataAsset;
class UPaperFlipbook;
enum class EHitboxType : uint8;
struct FFrameHitboxData;
struct FHitboxCollisionResult;
struct FHitboxData;
struct FLinearColor;
struct FSocketData;

// ********** Begin Class UPaper2DPlusBlueprintLibrary *********************************************
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDrawDebugHitbox); \
	DECLARE_FUNCTION(execDrawDebugHitboxesFromFlipbook); \
	DECLARE_FUNCTION(execDrawDebugHitboxes); \
	DECLARE_FUNCTION(execGetMaxKnockback); \
	DECLARE_FUNCTION(execGetTotalDamage); \
	DECLARE_FUNCTION(execMakeBox2D); \
	DECLARE_FUNCTION(execGetBoxSize); \
	DECLARE_FUNCTION(execGetBoxCenter); \
	DECLARE_FUNCTION(execStringToHitboxType); \
	DECLARE_FUNCTION(execHitboxTypeToString); \
	DECLARE_FUNCTION(execHasAnyData); \
	DECLARE_FUNCTION(execHasHurtboxes); \
	DECLARE_FUNCTION(execHasAttackHitboxes); \
	DECLARE_FUNCTION(execGetCollisionBoxes); \
	DECLARE_FUNCTION(execGetHurtboxes); \
	DECLARE_FUNCTION(execGetAttackHitboxes); \
	DECLARE_FUNCTION(execFrameHasAttack); \
	DECLARE_FUNCTION(execGetFrameDamageAndKnockback); \
	DECLARE_FUNCTION(execGetFrameKnockback); \
	DECLARE_FUNCTION(execGetFrameDamage); \
	DECLARE_FUNCTION(execCheckAttackCollision3D); \
	DECLARE_FUNCTION(execCheckAttackCollision); \
	DECLARE_FUNCTION(execGetHitboxFrameFromFlipbook); \
	DECLARE_FUNCTION(execQuickHitCheck); \
	DECLARE_FUNCTION(execCheckHitboxCollision3D); \
	DECLARE_FUNCTION(execCheckHitboxCollision); \
	DECLARE_FUNCTION(execDoBoxesOverlap); \
	DECLARE_FUNCTION(execSocketToWorldSpace3D); \
	DECLARE_FUNCTION(execSocketToWorldSpace); \
	DECLARE_FUNCTION(execHitboxToWorldSpace3D); \
	DECLARE_FUNCTION(execHitboxToWorldSpace);


struct Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics;
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_NoRegister();

#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaper2DPlusBlueprintLibrary(); \
	friend struct ::Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DPLUS_API UClass* ::Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaper2DPlusBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DPlus"), Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UPaper2DPlusBlueprintLibrary)


#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaper2DPlusBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaper2DPlusBlueprintLibrary(UPaper2DPlusBlueprintLibrary&&) = delete; \
	UPaper2DPlusBlueprintLibrary(const UPaper2DPlusBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaper2DPlusBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaper2DPlusBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaper2DPlusBlueprintLibrary) \
	NO_API virtual ~UPaper2DPlusBlueprintLibrary();


#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_13_PROLOG
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_INCLASS_NO_PURE_DECLS \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaper2DPlusBlueprintLibrary;

// ********** End Class UPaper2DPlusBlueprintLibrary ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
