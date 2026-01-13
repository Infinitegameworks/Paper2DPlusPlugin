// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Paper2DPlusCharacterDataAsset.h"

#ifdef PAPER2DPLUS_Paper2DPlusCharacterDataAsset_generated_h
#error "Paper2DPlusCharacterDataAsset.generated.h already included, missing '#pragma once' in Paper2DPlusCharacterDataAsset.h"
#endif
#define PAPER2DPLUS_Paper2DPlusCharacterDataAsset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPaperFlipbook;
enum class EDimensionStatus : uint8;
enum class EHitboxType : uint8;
struct FAnimationHitboxData;
struct FFrameHitboxData;
struct FHitboxData;
struct FSocketData;

// ********** Begin ScriptStruct FAnimationHitboxData **********************************************
struct Z_Construct_UScriptStruct_FAnimationHitboxData_Statics;
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FAnimationHitboxData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FAnimationHitboxData;
// ********** End ScriptStruct FAnimationHitboxData ************************************************

// ********** Begin Class UPaper2DPlusCharacterDataAsset *******************************************
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetUniformToLargest); \
	DECLARE_FUNCTION(execGetDimensionStatusCounts); \
	DECLARE_FUNCTION(execGetMismatchedAnimations); \
	DECLARE_FUNCTION(execAllAnimationsMatchUniform); \
	DECLARE_FUNCTION(execGetAnimationDimensionStatus); \
	DECLARE_FUNCTION(execCalculateLargestDimensions); \
	DECLARE_FUNCTION(execHasAnimation); \
	DECLARE_FUNCTION(execGetAnimationCount); \
	DECLARE_FUNCTION(execFindSocket); \
	DECLARE_FUNCTION(execGetSockets); \
	DECLARE_FUNCTION(execGetHitboxesByType); \
	DECLARE_FUNCTION(execGetHitboxes); \
	DECLARE_FUNCTION(execFindAnimationByFlipbook); \
	DECLARE_FUNCTION(execGetFrameByName); \
	DECLARE_FUNCTION(execGetFrame); \
	DECLARE_FUNCTION(execGetFrameCount); \
	DECLARE_FUNCTION(execGetAnimationByIndex); \
	DECLARE_FUNCTION(execGetAnimation); \
	DECLARE_FUNCTION(execGetAnimationNames);


struct Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics;
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister();

#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaper2DPlusCharacterDataAsset(); \
	friend struct ::Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DPLUS_API UClass* ::Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaper2DPlusCharacterDataAsset, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Paper2DPlus"), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister) \
	DECLARE_SERIALIZER(UPaper2DPlusCharacterDataAsset)


#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaper2DPlusCharacterDataAsset(UPaper2DPlusCharacterDataAsset&&) = delete; \
	UPaper2DPlusCharacterDataAsset(const UPaper2DPlusCharacterDataAsset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaper2DPlusCharacterDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaper2DPlusCharacterDataAsset); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPaper2DPlusCharacterDataAsset) \
	NO_API virtual ~UPaper2DPlusCharacterDataAsset();


#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_153_PROLOG
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_INCLASS_NO_PURE_DECLS \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h_156_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaper2DPlusCharacterDataAsset;

// ********** End Class UPaper2DPlusCharacterDataAsset *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
