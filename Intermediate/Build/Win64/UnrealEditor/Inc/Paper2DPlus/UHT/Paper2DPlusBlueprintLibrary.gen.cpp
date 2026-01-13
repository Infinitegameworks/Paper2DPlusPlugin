// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Paper2DPlusBlueprintLibrary.h"
#include "Paper2DPlusTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePaper2DPlusBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FBox2D();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusBlueprintLibrary();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_NoRegister();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_EHitboxType();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FFrameHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FHitboxCollisionResult();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FSocketData();
UPackage* Z_Construct_UPackage__Script_Paper2DPlus();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function CheckAttackCollision ***************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms
	{
		UPaper2DPlusCharacterDataAsset* AttackerData;
		UPaperFlipbook* AttackerFlipbook;
		float AttackerPlaybackPosition;
		FVector2D AttackerPosition;
		bool bAttackerFlipX;
		float AttackerScale;
		UPaper2DPlusCharacterDataAsset* DefenderData;
		UPaperFlipbook* DefenderFlipbook;
		float DefenderPlaybackPosition;
		FVector2D DefenderPosition;
		bool bDefenderFlipX;
		float DefenderScale;
		TArray<FHitboxCollisionResult> OutResults;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * All-in-one collision check using Flipbooks\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All-in-one collision check using Flipbooks" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CheckAttackCollision constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackerData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackerFlipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerPlaybackPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerPosition;
	static void NewProp_bAttackerFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackerFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefenderData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefenderFlipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderPlaybackPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderPosition;
	static void NewProp_bDefenderFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefenderFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutResults;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckAttackCollision constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckAttackCollision Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerData = { "AttackerData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, AttackerData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerFlipbook = { "AttackerFlipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, AttackerFlipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerPlaybackPosition = { "AttackerPlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, AttackerPlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerPosition = { "AttackerPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, AttackerPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bAttackerFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms*)Obj)->bAttackerFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bAttackerFlipX = { "bAttackerFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bAttackerFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerScale = { "AttackerScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, AttackerScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderData = { "DefenderData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, DefenderData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderFlipbook = { "DefenderFlipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, DefenderFlipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderPlaybackPosition = { "DefenderPlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, DefenderPlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderPosition = { "DefenderPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, DefenderPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bDefenderFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms*)Obj)->bDefenderFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bDefenderFlipX = { "bDefenderFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bDefenderFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderScale = { "DefenderScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, DefenderScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_OutResults_Inner = { "OutResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxCollisionResult, METADATA_PARAMS(0, nullptr) }; // 1931338514
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_OutResults = { "OutResults", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms, OutResults), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1931338514
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerFlipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerPlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bAttackerFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_AttackerScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderFlipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderPlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_bDefenderFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_DefenderScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_OutResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_OutResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::PropPointers) < 2048);
// ********** End Function CheckAttackCollision Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "CheckAttackCollision", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::Paper2DPlusBlueprintLibrary_eventCheckAttackCollision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execCheckAttackCollision)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_AttackerData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_AttackerFlipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerPlaybackPosition);
	P_GET_STRUCT(FVector2D,Z_Param_AttackerPosition);
	P_GET_UBOOL(Z_Param_bAttackerFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerScale);
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_DefenderData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_DefenderFlipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderPlaybackPosition);
	P_GET_STRUCT(FVector2D,Z_Param_DefenderPosition);
	P_GET_UBOOL(Z_Param_bDefenderFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderScale);
	P_GET_TARRAY_REF(FHitboxCollisionResult,Z_Param_Out_OutResults);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::CheckAttackCollision(Z_Param_AttackerData,Z_Param_AttackerFlipbook,Z_Param_AttackerPlaybackPosition,Z_Param_AttackerPosition,Z_Param_bAttackerFlipX,Z_Param_AttackerScale,Z_Param_DefenderData,Z_Param_DefenderFlipbook,Z_Param_DefenderPlaybackPosition,Z_Param_DefenderPosition,Z_Param_bDefenderFlipX,Z_Param_DefenderScale,Z_Param_Out_OutResults);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function CheckAttackCollision *****************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function CheckAttackCollision3D *************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms
	{
		UPaper2DPlusCharacterDataAsset* AttackerData;
		UPaperFlipbook* AttackerFlipbook;
		float AttackerPlaybackPosition;
		FVector AttackerPosition;
		bool bAttackerFlipX;
		float AttackerScale;
		UPaper2DPlusCharacterDataAsset* DefenderData;
		UPaperFlipbook* DefenderFlipbook;
		float DefenderPlaybackPosition;
		FVector DefenderPosition;
		bool bDefenderFlipX;
		float DefenderScale;
		TArray<FHitboxCollisionResult> OutResults;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * All-in-one collision check using Flipbooks with 3D positions\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All-in-one collision check using Flipbooks with 3D positions" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CheckAttackCollision3D constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackerData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackerFlipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerPlaybackPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerPosition;
	static void NewProp_bAttackerFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackerFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefenderData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefenderFlipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderPlaybackPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderPosition;
	static void NewProp_bDefenderFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefenderFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutResults;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckAttackCollision3D constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckAttackCollision3D Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerData = { "AttackerData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, AttackerData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerFlipbook = { "AttackerFlipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, AttackerFlipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerPlaybackPosition = { "AttackerPlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, AttackerPlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerPosition = { "AttackerPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, AttackerPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bAttackerFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms*)Obj)->bAttackerFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bAttackerFlipX = { "bAttackerFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bAttackerFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerScale = { "AttackerScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, AttackerScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderData = { "DefenderData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, DefenderData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderFlipbook = { "DefenderFlipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, DefenderFlipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderPlaybackPosition = { "DefenderPlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, DefenderPlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderPosition = { "DefenderPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, DefenderPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bDefenderFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms*)Obj)->bDefenderFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bDefenderFlipX = { "bDefenderFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bDefenderFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderScale = { "DefenderScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, DefenderScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_OutResults_Inner = { "OutResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxCollisionResult, METADATA_PARAMS(0, nullptr) }; // 1931338514
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_OutResults = { "OutResults", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms, OutResults), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1931338514
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerFlipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerPlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bAttackerFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_AttackerScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderFlipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderPlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_bDefenderFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_DefenderScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_OutResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_OutResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::PropPointers) < 2048);
// ********** End Function CheckAttackCollision3D Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "CheckAttackCollision3D", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::Paper2DPlusBlueprintLibrary_eventCheckAttackCollision3D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execCheckAttackCollision3D)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_AttackerData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_AttackerFlipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerPlaybackPosition);
	P_GET_STRUCT(FVector,Z_Param_AttackerPosition);
	P_GET_UBOOL(Z_Param_bAttackerFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerScale);
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_DefenderData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_DefenderFlipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderPlaybackPosition);
	P_GET_STRUCT(FVector,Z_Param_DefenderPosition);
	P_GET_UBOOL(Z_Param_bDefenderFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderScale);
	P_GET_TARRAY_REF(FHitboxCollisionResult,Z_Param_Out_OutResults);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::CheckAttackCollision3D(Z_Param_AttackerData,Z_Param_AttackerFlipbook,Z_Param_AttackerPlaybackPosition,Z_Param_AttackerPosition,Z_Param_bAttackerFlipX,Z_Param_AttackerScale,Z_Param_DefenderData,Z_Param_DefenderFlipbook,Z_Param_DefenderPlaybackPosition,Z_Param_DefenderPosition,Z_Param_bDefenderFlipX,Z_Param_DefenderScale,Z_Param_Out_OutResults);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function CheckAttackCollision3D ***************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function CheckHitboxCollision ***************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms
	{
		FFrameHitboxData AttackerFrame;
		FVector2D AttackerPosition;
		bool bAttackerFlipX;
		float AttackerScale;
		FFrameHitboxData DefenderFrame;
		FVector2D DefenderPosition;
		bool bDefenderFlipX;
		float DefenderScale;
		TArray<FHitboxCollisionResult> OutResults;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check collision between attacker and defender hitboxes (single frame)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check collision between attacker and defender hitboxes (single frame)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerFrame_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefenderFrame_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CheckHitboxCollision constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerPosition;
	static void NewProp_bAttackerFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackerFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderPosition;
	static void NewProp_bDefenderFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefenderFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutResults;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckHitboxCollision constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckHitboxCollision Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_AttackerFrame = { "AttackerFrame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, AttackerFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerFrame_MetaData), NewProp_AttackerFrame_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_AttackerPosition = { "AttackerPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, AttackerPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bAttackerFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms*)Obj)->bAttackerFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bAttackerFlipX = { "bAttackerFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bAttackerFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_AttackerScale = { "AttackerScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, AttackerScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_DefenderFrame = { "DefenderFrame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, DefenderFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefenderFrame_MetaData), NewProp_DefenderFrame_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_DefenderPosition = { "DefenderPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, DefenderPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bDefenderFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms*)Obj)->bDefenderFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bDefenderFlipX = { "bDefenderFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bDefenderFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_DefenderScale = { "DefenderScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, DefenderScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_OutResults_Inner = { "OutResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxCollisionResult, METADATA_PARAMS(0, nullptr) }; // 1931338514
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_OutResults = { "OutResults", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms, OutResults), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1931338514
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_AttackerFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_AttackerPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bAttackerFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_AttackerScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_DefenderFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_DefenderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_bDefenderFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_DefenderScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_OutResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_OutResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::PropPointers) < 2048);
// ********** End Function CheckHitboxCollision Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "CheckHitboxCollision", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execCheckHitboxCollision)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_AttackerFrame);
	P_GET_STRUCT(FVector2D,Z_Param_AttackerPosition);
	P_GET_UBOOL(Z_Param_bAttackerFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerScale);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_DefenderFrame);
	P_GET_STRUCT(FVector2D,Z_Param_DefenderPosition);
	P_GET_UBOOL(Z_Param_bDefenderFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderScale);
	P_GET_TARRAY_REF(FHitboxCollisionResult,Z_Param_Out_OutResults);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::CheckHitboxCollision(Z_Param_Out_AttackerFrame,Z_Param_AttackerPosition,Z_Param_bAttackerFlipX,Z_Param_AttackerScale,Z_Param_Out_DefenderFrame,Z_Param_DefenderPosition,Z_Param_bDefenderFlipX,Z_Param_DefenderScale,Z_Param_Out_OutResults);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function CheckHitboxCollision *****************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function CheckHitboxCollision3D *************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms
	{
		FFrameHitboxData AttackerFrame;
		FVector AttackerPosition;
		bool bAttackerFlipX;
		float AttackerScale;
		FFrameHitboxData DefenderFrame;
		FVector DefenderPosition;
		bool bDefenderFlipX;
		float DefenderScale;
		TArray<FHitboxCollisionResult> OutResults;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check collision using 3D positions (uses X and Z)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check collision using 3D positions (uses X and Z)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerFrame_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefenderFrame_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CheckHitboxCollision3D constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerPosition;
	static void NewProp_bAttackerFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackerFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderPosition;
	static void NewProp_bDefenderFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefenderFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutResults;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckHitboxCollision3D constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckHitboxCollision3D Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_AttackerFrame = { "AttackerFrame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, AttackerFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerFrame_MetaData), NewProp_AttackerFrame_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_AttackerPosition = { "AttackerPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, AttackerPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bAttackerFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms*)Obj)->bAttackerFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bAttackerFlipX = { "bAttackerFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bAttackerFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_AttackerScale = { "AttackerScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, AttackerScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_DefenderFrame = { "DefenderFrame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, DefenderFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefenderFrame_MetaData), NewProp_DefenderFrame_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_DefenderPosition = { "DefenderPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, DefenderPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bDefenderFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms*)Obj)->bDefenderFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bDefenderFlipX = { "bDefenderFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bDefenderFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_DefenderScale = { "DefenderScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, DefenderScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_OutResults_Inner = { "OutResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxCollisionResult, METADATA_PARAMS(0, nullptr) }; // 1931338514
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_OutResults = { "OutResults", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms, OutResults), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1931338514
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_AttackerFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_AttackerPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bAttackerFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_AttackerScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_DefenderFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_DefenderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_bDefenderFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_DefenderScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_OutResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_OutResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::PropPointers) < 2048);
// ********** End Function CheckHitboxCollision3D Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "CheckHitboxCollision3D", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::Paper2DPlusBlueprintLibrary_eventCheckHitboxCollision3D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execCheckHitboxCollision3D)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_AttackerFrame);
	P_GET_STRUCT(FVector,Z_Param_AttackerPosition);
	P_GET_UBOOL(Z_Param_bAttackerFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerScale);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_DefenderFrame);
	P_GET_STRUCT(FVector,Z_Param_DefenderPosition);
	P_GET_UBOOL(Z_Param_bDefenderFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderScale);
	P_GET_TARRAY_REF(FHitboxCollisionResult,Z_Param_Out_OutResults);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::CheckHitboxCollision3D(Z_Param_Out_AttackerFrame,Z_Param_AttackerPosition,Z_Param_bAttackerFlipX,Z_Param_AttackerScale,Z_Param_Out_DefenderFrame,Z_Param_DefenderPosition,Z_Param_bDefenderFlipX,Z_Param_DefenderScale,Z_Param_Out_OutResults);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function CheckHitboxCollision3D ***************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function DoBoxesOverlap *********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms
	{
		FBox2D BoxA;
		FBox2D BoxB;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if two Box2D overlap\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if two Box2D overlap" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxA_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxB_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoBoxesOverlap constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoxA;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoxB;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoBoxesOverlap constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoBoxesOverlap Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_BoxA = { "BoxA", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms, BoxA), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxA_MetaData), NewProp_BoxA_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_BoxB = { "BoxB", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms, BoxB), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxB_MetaData), NewProp_BoxB_MetaData) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_BoxA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_BoxB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::PropPointers) < 2048);
// ********** End Function DoBoxesOverlap Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "DoBoxesOverlap", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::Paper2DPlusBlueprintLibrary_eventDoBoxesOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execDoBoxesOverlap)
{
	P_GET_STRUCT_REF(FBox2D,Z_Param_Out_BoxA);
	P_GET_STRUCT_REF(FBox2D,Z_Param_Out_BoxB);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::DoBoxesOverlap(Z_Param_Out_BoxA,Z_Param_Out_BoxB);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function DoBoxesOverlap ***********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function DrawDebugHitbox ********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms
	{
		UObject* WorldContext;
		FHitboxData Hitbox;
		FVector WorldPosition;
		bool bFlipX;
		float Scale;
		FLinearColor Color;
		bool bUseTypeColor;
		float Duration;
		float Thickness;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Debug" },
		{ "CPP_Default_bUseTypeColor", "true" },
		{ "CPP_Default_Color", "(R=1.000000,G=1.000000,B=1.000000,A=1.000000)" },
		{ "CPP_Default_Duration", "0.000000" },
		{ "CPP_Default_Scale", "1.000000" },
		{ "CPP_Default_Thickness", "1.000000" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hitbox_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DrawDebugHitbox constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hitbox;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static void NewProp_bUseTypeColor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseTypeColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DrawDebugHitbox constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DrawDebugHitbox Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Hitbox = { "Hitbox", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, Hitbox), Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hitbox_MetaData), NewProp_Hitbox_MetaData) }; // 975460340
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bUseTypeColor_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms*)Obj)->bUseTypeColor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bUseTypeColor = { "bUseTypeColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bUseTypeColor_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Hitbox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_bUseTypeColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::NewProp_Thickness,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::PropPointers) < 2048);
// ********** End Function DrawDebugHitbox Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "DrawDebugHitbox", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::Paper2DPlusBlueprintLibrary_eventDrawDebugHitbox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execDrawDebugHitbox)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_GET_STRUCT_REF(FHitboxData,Z_Param_Out_Hitbox);
	P_GET_STRUCT(FVector,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_GET_UBOOL(Z_Param_bUseTypeColor);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPaper2DPlusBlueprintLibrary::DrawDebugHitbox(Z_Param_WorldContext,Z_Param_Out_Hitbox,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale,Z_Param_Color,Z_Param_bUseTypeColor,Z_Param_Duration,Z_Param_Thickness);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function DrawDebugHitbox **********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function DrawDebugHitboxes ******************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms
	{
		UObject* WorldContext;
		FFrameHitboxData FrameData;
		FVector WorldPosition;
		bool bFlipX;
		float Scale;
		float Duration;
		float Thickness;
		bool bDrawSockets;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==========================================\n// DEBUG VISUALIZATION\n// ==========================================\n" },
#endif
		{ "CPP_Default_bDrawSockets", "true" },
		{ "CPP_Default_Duration", "0.000000" },
		{ "CPP_Default_Scale", "1.000000" },
		{ "CPP_Default_Thickness", "1.000000" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DEBUG VISUALIZATION" },
#endif
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DrawDebugHitboxes constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
	static void NewProp_bDrawSockets_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawSockets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DrawDebugHitboxes constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DrawDebugHitboxes Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bDrawSockets_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms*)Obj)->bDrawSockets = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bDrawSockets = { "bDrawSockets", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bDrawSockets_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_Thickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::NewProp_bDrawSockets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::PropPointers) < 2048);
// ********** End Function DrawDebugHitboxes Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "DrawDebugHitboxes", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execDrawDebugHitboxes)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_GET_STRUCT(FVector,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
	P_GET_UBOOL(Z_Param_bDrawSockets);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPaper2DPlusBlueprintLibrary::DrawDebugHitboxes(Z_Param_WorldContext,Z_Param_Out_FrameData,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale,Z_Param_Duration,Z_Param_Thickness,Z_Param_bDrawSockets);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function DrawDebugHitboxes ********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function DrawDebugHitboxesFromFlipbook ******
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms
	{
		UObject* WorldContext;
		UPaper2DPlusCharacterDataAsset* CharacterData;
		UPaperFlipbook* Flipbook;
		float PlaybackPosition;
		FVector WorldPosition;
		bool bFlipX;
		float Scale;
		float Duration;
		float Thickness;
		bool bDrawSockets;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Debug" },
		{ "CPP_Default_bDrawSockets", "true" },
		{ "CPP_Default_Duration", "0.000000" },
		{ "CPP_Default_Scale", "1.000000" },
		{ "CPP_Default_Thickness", "1.000000" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
		{ "WorldContext", "WorldContext" },
	};
#endif // WITH_METADATA

// ********** Begin Function DrawDebugHitboxesFromFlipbook constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
	static void NewProp_bDrawSockets_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawSockets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DrawDebugHitboxesFromFlipbook constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DrawDebugHitboxesFromFlipbook Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_PlaybackPosition = { "PlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, PlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bDrawSockets_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms*)Obj)->bDrawSockets = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bDrawSockets = { "bDrawSockets", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bDrawSockets_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_PlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_Thickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::NewProp_bDrawSockets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::PropPointers) < 2048);
// ********** End Function DrawDebugHitboxesFromFlipbook Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "DrawDebugHitboxesFromFlipbook", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::Paper2DPlusBlueprintLibrary_eventDrawDebugHitboxesFromFlipbook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execDrawDebugHitboxesFromFlipbook)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_CharacterData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlaybackPosition);
	P_GET_STRUCT(FVector,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
	P_GET_UBOOL(Z_Param_bDrawSockets);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPaper2DPlusBlueprintLibrary::DrawDebugHitboxesFromFlipbook(Z_Param_WorldContext,Z_Param_CharacterData,Z_Param_Flipbook,Z_Param_PlaybackPosition,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale,Z_Param_Duration,Z_Param_Thickness,Z_Param_bDrawSockets);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function DrawDebugHitboxesFromFlipbook ********

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function FrameHasAttack *********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms
	{
		UPaper2DPlusCharacterDataAsset* CharacterData;
		UPaperFlipbook* Flipbook;
		float PlaybackPosition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FrameHasAttack constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackPosition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FrameHasAttack constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FrameHasAttack Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_PlaybackPosition = { "PlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms, PlaybackPosition), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_PlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::PropPointers) < 2048);
// ********** End Function FrameHasAttack Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "FrameHasAttack", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::Paper2DPlusBlueprintLibrary_eventFrameHasAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execFrameHasAttack)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_CharacterData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlaybackPosition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::FrameHasAttack(Z_Param_CharacterData,Z_Param_Flipbook,Z_Param_PlaybackPosition);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function FrameHasAttack ***********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetAttackHitboxes ******************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetAttackHitboxes_Parms
	{
		FFrameHitboxData FrameData;
		TArray<FHitboxData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAttackHitboxes constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAttackHitboxes constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAttackHitboxes Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetAttackHitboxes_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetAttackHitboxes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::PropPointers) < 2048);
// ********** End Function GetAttackHitboxes Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetAttackHitboxes", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::Paper2DPlusBlueprintLibrary_eventGetAttackHitboxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::Paper2DPlusBlueprintLibrary_eventGetAttackHitboxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetAttackHitboxes)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FHitboxData>*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetAttackHitboxes(Z_Param_Out_FrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetAttackHitboxes ********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetBoxCenter ***********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetBoxCenter_Parms
	{
		FBox2D Box;
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBoxCenter constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Box;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBoxCenter constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBoxCenter Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetBoxCenter_Parms, Box), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Box_MetaData), NewProp_Box_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetBoxCenter_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::NewProp_Box,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::PropPointers) < 2048);
// ********** End Function GetBoxCenter Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetBoxCenter", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::Paper2DPlusBlueprintLibrary_eventGetBoxCenter_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::Paper2DPlusBlueprintLibrary_eventGetBoxCenter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetBoxCenter)
{
	P_GET_STRUCT_REF(FBox2D,Z_Param_Out_Box);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetBoxCenter(Z_Param_Out_Box);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetBoxCenter *************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetBoxSize *************************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetBoxSize_Parms
	{
		FBox2D Box;
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBoxSize constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Box;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBoxSize constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBoxSize Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetBoxSize_Parms, Box), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Box_MetaData), NewProp_Box_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetBoxSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::NewProp_Box,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::PropPointers) < 2048);
// ********** End Function GetBoxSize Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetBoxSize", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::Paper2DPlusBlueprintLibrary_eventGetBoxSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::Paper2DPlusBlueprintLibrary_eventGetBoxSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetBoxSize)
{
	P_GET_STRUCT_REF(FBox2D,Z_Param_Out_Box);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetBoxSize(Z_Param_Out_Box);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetBoxSize ***************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetCollisionBoxes ******************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetCollisionBoxes_Parms
	{
		FFrameHitboxData FrameData;
		TArray<FHitboxData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCollisionBoxes constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCollisionBoxes constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCollisionBoxes Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetCollisionBoxes_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetCollisionBoxes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::PropPointers) < 2048);
// ********** End Function GetCollisionBoxes Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetCollisionBoxes", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::Paper2DPlusBlueprintLibrary_eventGetCollisionBoxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::Paper2DPlusBlueprintLibrary_eventGetCollisionBoxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetCollisionBoxes)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FHitboxData>*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetCollisionBoxes(Z_Param_Out_FrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetCollisionBoxes ********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetFrameDamage *********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms
	{
		UPaper2DPlusCharacterDataAsset* CharacterData;
		UPaperFlipbook* Flipbook;
		float PlaybackPosition;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==========================================\n// FRAME DATA HELPERS\n// ==========================================\n" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FRAME DATA HELPERS" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetFrameDamage constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackPosition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFrameDamage constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFrameDamage Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_PlaybackPosition = { "PlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms, PlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_PlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::PropPointers) < 2048);
// ********** End Function GetFrameDamage Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetFrameDamage", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::Paper2DPlusBlueprintLibrary_eventGetFrameDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetFrameDamage)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_CharacterData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlaybackPosition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetFrameDamage(Z_Param_CharacterData,Z_Param_Flipbook,Z_Param_PlaybackPosition);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetFrameDamage ***********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetFrameDamageAndKnockback *********
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms
	{
		UPaper2DPlusCharacterDataAsset* CharacterData;
		UPaperFlipbook* Flipbook;
		float PlaybackPosition;
		int32 OutDamage;
		int32 OutKnockback;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFrameDamageAndKnockback constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackPosition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutDamage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutKnockback;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFrameDamageAndKnockback constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFrameDamageAndKnockback Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_PlaybackPosition = { "PlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms, PlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_OutDamage = { "OutDamage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms, OutDamage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_OutKnockback = { "OutKnockback", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms, OutKnockback), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_PlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_OutDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_OutKnockback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::PropPointers) < 2048);
// ********** End Function GetFrameDamageAndKnockback Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetFrameDamageAndKnockback", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::Paper2DPlusBlueprintLibrary_eventGetFrameDamageAndKnockback_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetFrameDamageAndKnockback)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_CharacterData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlaybackPosition);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutDamage);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutKnockback);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetFrameDamageAndKnockback(Z_Param_CharacterData,Z_Param_Flipbook,Z_Param_PlaybackPosition,Z_Param_Out_OutDamage,Z_Param_Out_OutKnockback);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetFrameDamageAndKnockback ***********

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetFrameKnockback ******************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms
	{
		UPaper2DPlusCharacterDataAsset* CharacterData;
		UPaperFlipbook* Flipbook;
		float PlaybackPosition;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFrameKnockback constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackPosition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFrameKnockback constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFrameKnockback Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_PlaybackPosition = { "PlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms, PlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_PlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::PropPointers) < 2048);
// ********** End Function GetFrameKnockback Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetFrameKnockback", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::Paper2DPlusBlueprintLibrary_eventGetFrameKnockback_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetFrameKnockback)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_CharacterData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlaybackPosition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetFrameKnockback(Z_Param_CharacterData,Z_Param_Flipbook,Z_Param_PlaybackPosition);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetFrameKnockback ********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetHitboxFrameFromFlipbook *********
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms
	{
		UPaper2DPlusCharacterDataAsset* CharacterData;
		UPaperFlipbook* Flipbook;
		float PlaybackPosition;
		FFrameHitboxData OutFrameData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get hitbox frame data from a Flipbook's current playback position\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get hitbox frame data from a Flipbook's current playback position" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetHitboxFrameFromFlipbook constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutFrameData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHitboxFrameFromFlipbook constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHitboxFrameFromFlipbook Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_PlaybackPosition = { "PlaybackPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms, PlaybackPosition), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_OutFrameData = { "OutFrameData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms, OutFrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(0, nullptr) }; // 586679813
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_PlaybackPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_OutFrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::PropPointers) < 2048);
// ********** End Function GetHitboxFrameFromFlipbook Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetHitboxFrameFromFlipbook", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::Paper2DPlusBlueprintLibrary_eventGetHitboxFrameFromFlipbook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetHitboxFrameFromFlipbook)
{
	P_GET_OBJECT(UPaper2DPlusCharacterDataAsset,Z_Param_CharacterData);
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlaybackPosition);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_OutFrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetHitboxFrameFromFlipbook(Z_Param_CharacterData,Z_Param_Flipbook,Z_Param_PlaybackPosition,Z_Param_Out_OutFrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetHitboxFrameFromFlipbook ***********

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetHurtboxes ***********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetHurtboxes_Parms
	{
		FFrameHitboxData FrameData;
		TArray<FHitboxData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHurtboxes constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHurtboxes constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHurtboxes Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetHurtboxes_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetHurtboxes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::PropPointers) < 2048);
// ********** End Function GetHurtboxes Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetHurtboxes", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::Paper2DPlusBlueprintLibrary_eventGetHurtboxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::Paper2DPlusBlueprintLibrary_eventGetHurtboxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetHurtboxes)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FHitboxData>*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetHurtboxes(Z_Param_Out_FrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetHurtboxes *************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetMaxKnockback ********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetMaxKnockback_Parms
	{
		TArray<FHitboxCollisionResult> Results;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Results_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetMaxKnockback constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Results_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Results;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMaxKnockback constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMaxKnockback Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::NewProp_Results_Inner = { "Results", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxCollisionResult, METADATA_PARAMS(0, nullptr) }; // 1931338514
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::NewProp_Results = { "Results", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetMaxKnockback_Parms, Results), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Results_MetaData), NewProp_Results_MetaData) }; // 1931338514
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetMaxKnockback_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::NewProp_Results_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::NewProp_Results,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::PropPointers) < 2048);
// ********** End Function GetMaxKnockback Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetMaxKnockback", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::Paper2DPlusBlueprintLibrary_eventGetMaxKnockback_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::Paper2DPlusBlueprintLibrary_eventGetMaxKnockback_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetMaxKnockback)
{
	P_GET_TARRAY_REF(FHitboxCollisionResult,Z_Param_Out_Results);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetMaxKnockback(Z_Param_Out_Results);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetMaxKnockback **********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function GetTotalDamage *********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventGetTotalDamage_Parms
	{
		TArray<FHitboxCollisionResult> Results;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Results_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTotalDamage constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Results_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Results;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTotalDamage constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTotalDamage Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::NewProp_Results_Inner = { "Results", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxCollisionResult, METADATA_PARAMS(0, nullptr) }; // 1931338514
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::NewProp_Results = { "Results", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetTotalDamage_Parms, Results), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Results_MetaData), NewProp_Results_MetaData) }; // 1931338514
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventGetTotalDamage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::NewProp_Results_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::NewProp_Results,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::PropPointers) < 2048);
// ********** End Function GetTotalDamage Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "GetTotalDamage", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::Paper2DPlusBlueprintLibrary_eventGetTotalDamage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::Paper2DPlusBlueprintLibrary_eventGetTotalDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execGetTotalDamage)
{
	P_GET_TARRAY_REF(FHitboxCollisionResult,Z_Param_Out_Results);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::GetTotalDamage(Z_Param_Out_Results);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function GetTotalDamage ***********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function HasAnyData *************************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventHasAnyData_Parms
	{
		FFrameHitboxData FrameData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasAnyData constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAnyData constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAnyData Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHasAnyData_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventHasAnyData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventHasAnyData_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::PropPointers) < 2048);
// ********** End Function HasAnyData Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "HasAnyData", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::Paper2DPlusBlueprintLibrary_eventHasAnyData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::Paper2DPlusBlueprintLibrary_eventHasAnyData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execHasAnyData)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::HasAnyData(Z_Param_Out_FrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function HasAnyData ***************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function HasAttackHitboxes ******************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventHasAttackHitboxes_Parms
	{
		FFrameHitboxData FrameData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasAttackHitboxes constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAttackHitboxes constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAttackHitboxes Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHasAttackHitboxes_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventHasAttackHitboxes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventHasAttackHitboxes_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::PropPointers) < 2048);
// ********** End Function HasAttackHitboxes Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "HasAttackHitboxes", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::Paper2DPlusBlueprintLibrary_eventHasAttackHitboxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::Paper2DPlusBlueprintLibrary_eventHasAttackHitboxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execHasAttackHitboxes)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::HasAttackHitboxes(Z_Param_Out_FrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function HasAttackHitboxes ********************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function HasHurtboxes ***********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventHasHurtboxes_Parms
	{
		FFrameHitboxData FrameData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Frame" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasHurtboxes constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasHurtboxes constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasHurtboxes Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::NewProp_FrameData = { "FrameData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHasHurtboxes_Parms, FrameData), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameData_MetaData), NewProp_FrameData_MetaData) }; // 586679813
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventHasHurtboxes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventHasHurtboxes_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::NewProp_FrameData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::PropPointers) < 2048);
// ********** End Function HasHurtboxes Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "HasHurtboxes", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::Paper2DPlusBlueprintLibrary_eventHasHurtboxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::Paper2DPlusBlueprintLibrary_eventHasHurtboxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execHasHurtboxes)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_FrameData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::HasHurtboxes(Z_Param_Out_FrameData);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function HasHurtboxes *************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function HitboxToWorldSpace *****************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms
	{
		FHitboxData Hitbox;
		FVector2D WorldPosition;
		bool bFlipX;
		float Scale;
		FBox2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Conversion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Convert a hitbox to world space Box2D\n\x09 * @param Hitbox The hitbox data\n\x09 * @param WorldPosition Character's world position (2D)\n\x09 * @param bFlipX Whether character is facing left (flips hitbox horizontally)\n\x09 * @param Scale Scale multiplier (default 1.0)\n\x09 * @return World-space Box2D\n\x09 */" },
#endif
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert a hitbox to world space Box2D\n@param Hitbox The hitbox data\n@param WorldPosition Character's world position (2D)\n@param bFlipX Whether character is facing left (flips hitbox horizontally)\n@param Scale Scale multiplier (default 1.0)\n@return World-space Box2D" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hitbox_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HitboxToWorldSpace constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hitbox;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HitboxToWorldSpace constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HitboxToWorldSpace Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_Hitbox = { "Hitbox", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms, Hitbox), Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hitbox_MetaData), NewProp_Hitbox_MetaData) }; // 975460340
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms, ReturnValue), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_Hitbox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::PropPointers) < 2048);
// ********** End Function HitboxToWorldSpace Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "HitboxToWorldSpace", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execHitboxToWorldSpace)
{
	P_GET_STRUCT_REF(FHitboxData,Z_Param_Out_Hitbox);
	P_GET_STRUCT(FVector2D,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBox2D*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::HitboxToWorldSpace(Z_Param_Out_Hitbox,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function HitboxToWorldSpace *******************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function HitboxToWorldSpace3D ***************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms
	{
		FHitboxData Hitbox;
		FVector WorldPosition;
		bool bFlipX;
		float Scale;
		FBox2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Conversion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Convert a hitbox to world space with 3D vector position (uses X and Z for 2D)\n\x09 */" },
#endif
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert a hitbox to world space with 3D vector position (uses X and Z for 2D)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hitbox_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HitboxToWorldSpace3D constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hitbox;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HitboxToWorldSpace3D constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HitboxToWorldSpace3D Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_Hitbox = { "Hitbox", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms, Hitbox), Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hitbox_MetaData), NewProp_Hitbox_MetaData) }; // 975460340
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms, ReturnValue), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_Hitbox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::PropPointers) < 2048);
// ********** End Function HitboxToWorldSpace3D Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "HitboxToWorldSpace3D", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::Paper2DPlusBlueprintLibrary_eventHitboxToWorldSpace3D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execHitboxToWorldSpace3D)
{
	P_GET_STRUCT_REF(FHitboxData,Z_Param_Out_Hitbox);
	P_GET_STRUCT(FVector,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBox2D*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::HitboxToWorldSpace3D(Z_Param_Out_Hitbox,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function HitboxToWorldSpace3D *****************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function HitboxTypeToString *****************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventHitboxTypeToString_Parms
	{
		EHitboxType Type;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==========================================\n// UTILITIES\n// ==========================================\n" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UTILITIES" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HitboxTypeToString constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HitboxTypeToString constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HitboxTypeToString Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxTypeToString_Parms, Type), Z_Construct_UEnum_Paper2DPlus_EHitboxType, METADATA_PARAMS(0, nullptr) }; // 3673529899
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventHitboxTypeToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::PropPointers) < 2048);
// ********** End Function HitboxTypeToString Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "HitboxTypeToString", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::Paper2DPlusBlueprintLibrary_eventHitboxTypeToString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::Paper2DPlusBlueprintLibrary_eventHitboxTypeToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execHitboxTypeToString)
{
	P_GET_ENUM(EHitboxType,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::HitboxTypeToString(EHitboxType(Z_Param_Type));
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function HitboxTypeToString *******************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function MakeBox2D **************************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventMakeBox2D_Parms
	{
		FVector2D Center;
		FVector2D HalfExtents;
		FBox2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeBox2D constinit property declarations *****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HalfExtents;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeBox2D constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeBox2D Property Definitions ****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventMakeBox2D_Parms, Center), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::NewProp_HalfExtents = { "HalfExtents", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventMakeBox2D_Parms, HalfExtents), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventMakeBox2D_Parms, ReturnValue), Z_Construct_UScriptStruct_FBox2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::NewProp_HalfExtents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::PropPointers) < 2048);
// ********** End Function MakeBox2D Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "MakeBox2D", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::Paper2DPlusBlueprintLibrary_eventMakeBox2D_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::Paper2DPlusBlueprintLibrary_eventMakeBox2D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execMakeBox2D)
{
	P_GET_STRUCT(FVector2D,Z_Param_Center);
	P_GET_STRUCT(FVector2D,Z_Param_HalfExtents);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBox2D*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::MakeBox2D(Z_Param_Center,Z_Param_HalfExtents);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function MakeBox2D ****************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function QuickHitCheck **********************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms
	{
		FFrameHitboxData AttackerFrame;
		FVector2D AttackerPosition;
		bool bAttackerFlipX;
		float AttackerScale;
		FFrameHitboxData DefenderFrame;
		FVector2D DefenderPosition;
		bool bDefenderFlipX;
		float DefenderScale;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Quick check if any attack hitbox overlaps any hurtbox (no detailed results)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quick check if any attack hitbox overlaps any hurtbox (no detailed results)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerFrame_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefenderFrame_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function QuickHitCheck constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerPosition;
	static void NewProp_bAttackerFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackerFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackerScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderPosition;
	static void NewProp_bDefenderFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefenderFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenderScale;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function QuickHitCheck constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function QuickHitCheck Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_AttackerFrame = { "AttackerFrame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms, AttackerFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerFrame_MetaData), NewProp_AttackerFrame_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_AttackerPosition = { "AttackerPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms, AttackerPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bAttackerFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms*)Obj)->bAttackerFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bAttackerFlipX = { "bAttackerFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bAttackerFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_AttackerScale = { "AttackerScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms, AttackerScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_DefenderFrame = { "DefenderFrame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms, DefenderFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefenderFrame_MetaData), NewProp_DefenderFrame_MetaData) }; // 586679813
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_DefenderPosition = { "DefenderPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms, DefenderPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bDefenderFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms*)Obj)->bDefenderFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bDefenderFlipX = { "bDefenderFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bDefenderFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_DefenderScale = { "DefenderScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms, DefenderScale), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_AttackerFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_AttackerPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bAttackerFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_AttackerScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_DefenderFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_DefenderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_bDefenderFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_DefenderScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::PropPointers) < 2048);
// ********** End Function QuickHitCheck Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "QuickHitCheck", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::Paper2DPlusBlueprintLibrary_eventQuickHitCheck_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execQuickHitCheck)
{
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_AttackerFrame);
	P_GET_STRUCT(FVector2D,Z_Param_AttackerPosition);
	P_GET_UBOOL(Z_Param_bAttackerFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AttackerScale);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_DefenderFrame);
	P_GET_STRUCT(FVector2D,Z_Param_DefenderPosition);
	P_GET_UBOOL(Z_Param_bDefenderFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefenderScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::QuickHitCheck(Z_Param_Out_AttackerFrame,Z_Param_AttackerPosition,Z_Param_bAttackerFlipX,Z_Param_AttackerScale,Z_Param_Out_DefenderFrame,Z_Param_DefenderPosition,Z_Param_bDefenderFlipX,Z_Param_DefenderScale);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function QuickHitCheck ************************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function SocketToWorldSpace *****************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms
	{
		FSocketData Socket;
		FVector2D WorldPosition;
		bool bFlipX;
		float Scale;
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Conversion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Convert socket position to world space\n\x09 */" },
#endif
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert socket position to world space" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Socket_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SocketToWorldSpace constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Socket;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SocketToWorldSpace constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SocketToWorldSpace Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_Socket = { "Socket", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms, Socket), Z_Construct_UScriptStruct_FSocketData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Socket_MetaData), NewProp_Socket_MetaData) }; // 3308025426
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_Socket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::PropPointers) < 2048);
// ********** End Function SocketToWorldSpace Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "SocketToWorldSpace", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execSocketToWorldSpace)
{
	P_GET_STRUCT_REF(FSocketData,Z_Param_Out_Socket);
	P_GET_STRUCT(FVector2D,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::SocketToWorldSpace(Z_Param_Out_Socket,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function SocketToWorldSpace *******************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function SocketToWorldSpace3D ***************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms
	{
		FSocketData Socket;
		FVector WorldPosition;
		bool bFlipX;
		float Scale;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Conversion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Convert socket to world space with 3D vector (uses X and Z for 2D)\n\x09 */" },
#endif
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert socket to world space with 3D vector (uses X and Z for 2D)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Socket_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SocketToWorldSpace3D constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Socket;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SocketToWorldSpace3D constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SocketToWorldSpace3D Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_Socket = { "Socket", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms, Socket), Z_Construct_UScriptStruct_FSocketData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Socket_MetaData), NewProp_Socket_MetaData) }; // 3308025426
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms), &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms, Scale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_Socket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::PropPointers) < 2048);
// ********** End Function SocketToWorldSpace3D Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "SocketToWorldSpace3D", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::Paper2DPlusBlueprintLibrary_eventSocketToWorldSpace3D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execSocketToWorldSpace3D)
{
	P_GET_STRUCT_REF(FSocketData,Z_Param_Out_Socket);
	P_GET_STRUCT(FVector,Z_Param_WorldPosition);
	P_GET_UBOOL(Z_Param_bFlipX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::SocketToWorldSpace3D(Z_Param_Out_Socket,Z_Param_WorldPosition,Z_Param_bFlipX,Z_Param_Scale);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function SocketToWorldSpace3D *****************

// ********** Begin Class UPaper2DPlusBlueprintLibrary Function StringToHitboxType *****************
struct Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics
{
	struct Paper2DPlusBlueprintLibrary_eventStringToHitboxType_Parms
	{
		FString TypeString;
		EHitboxType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus|Utilities" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function StringToHitboxType constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeString;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StringToHitboxType constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StringToHitboxType Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::NewProp_TypeString = { "TypeString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventStringToHitboxType_Parms, TypeString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeString_MetaData), NewProp_TypeString_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusBlueprintLibrary_eventStringToHitboxType_Parms, ReturnValue), Z_Construct_UEnum_Paper2DPlus_EHitboxType, METADATA_PARAMS(0, nullptr) }; // 3673529899
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::NewProp_TypeString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::PropPointers) < 2048);
// ********** End Function StringToHitboxType Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, nullptr, "StringToHitboxType", 	Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::Paper2DPlusBlueprintLibrary_eventStringToHitboxType_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::Paper2DPlusBlueprintLibrary_eventStringToHitboxType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusBlueprintLibrary::execStringToHitboxType)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TypeString);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EHitboxType*)Z_Param__Result=UPaper2DPlusBlueprintLibrary::StringToHitboxType(Z_Param_TypeString);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusBlueprintLibrary Function StringToHitboxType *******************

// ********** Begin Class UPaper2DPlusBlueprintLibrary *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary;
UClass* UPaper2DPlusBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = UPaper2DPlusBlueprintLibrary;
	if (!Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("Paper2DPlusBlueprintLibrary"),
			Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesUPaper2DPlusBlueprintLibrary,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_NoRegister()
{
	return UPaper2DPlusBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Blueprint function library for Paper2DPlus operations.\n * Provides world-space conversion, collision detection, and utility functions.\n */" },
#endif
		{ "IncludePath", "Paper2DPlusBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/Paper2DPlusBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint function library for Paper2DPlus operations.\nProvides world-space conversion, collision detection, and utility functions." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPaper2DPlusBlueprintLibrary constinit property declarations *************
// ********** End Class UPaper2DPlusBlueprintLibrary constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CheckAttackCollision"), .Pointer = &UPaper2DPlusBlueprintLibrary::execCheckAttackCollision },
		{ .NameUTF8 = UTF8TEXT("CheckAttackCollision3D"), .Pointer = &UPaper2DPlusBlueprintLibrary::execCheckAttackCollision3D },
		{ .NameUTF8 = UTF8TEXT("CheckHitboxCollision"), .Pointer = &UPaper2DPlusBlueprintLibrary::execCheckHitboxCollision },
		{ .NameUTF8 = UTF8TEXT("CheckHitboxCollision3D"), .Pointer = &UPaper2DPlusBlueprintLibrary::execCheckHitboxCollision3D },
		{ .NameUTF8 = UTF8TEXT("DoBoxesOverlap"), .Pointer = &UPaper2DPlusBlueprintLibrary::execDoBoxesOverlap },
		{ .NameUTF8 = UTF8TEXT("DrawDebugHitbox"), .Pointer = &UPaper2DPlusBlueprintLibrary::execDrawDebugHitbox },
		{ .NameUTF8 = UTF8TEXT("DrawDebugHitboxes"), .Pointer = &UPaper2DPlusBlueprintLibrary::execDrawDebugHitboxes },
		{ .NameUTF8 = UTF8TEXT("DrawDebugHitboxesFromFlipbook"), .Pointer = &UPaper2DPlusBlueprintLibrary::execDrawDebugHitboxesFromFlipbook },
		{ .NameUTF8 = UTF8TEXT("FrameHasAttack"), .Pointer = &UPaper2DPlusBlueprintLibrary::execFrameHasAttack },
		{ .NameUTF8 = UTF8TEXT("GetAttackHitboxes"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetAttackHitboxes },
		{ .NameUTF8 = UTF8TEXT("GetBoxCenter"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetBoxCenter },
		{ .NameUTF8 = UTF8TEXT("GetBoxSize"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetBoxSize },
		{ .NameUTF8 = UTF8TEXT("GetCollisionBoxes"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetCollisionBoxes },
		{ .NameUTF8 = UTF8TEXT("GetFrameDamage"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetFrameDamage },
		{ .NameUTF8 = UTF8TEXT("GetFrameDamageAndKnockback"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetFrameDamageAndKnockback },
		{ .NameUTF8 = UTF8TEXT("GetFrameKnockback"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetFrameKnockback },
		{ .NameUTF8 = UTF8TEXT("GetHitboxFrameFromFlipbook"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetHitboxFrameFromFlipbook },
		{ .NameUTF8 = UTF8TEXT("GetHurtboxes"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetHurtboxes },
		{ .NameUTF8 = UTF8TEXT("GetMaxKnockback"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetMaxKnockback },
		{ .NameUTF8 = UTF8TEXT("GetTotalDamage"), .Pointer = &UPaper2DPlusBlueprintLibrary::execGetTotalDamage },
		{ .NameUTF8 = UTF8TEXT("HasAnyData"), .Pointer = &UPaper2DPlusBlueprintLibrary::execHasAnyData },
		{ .NameUTF8 = UTF8TEXT("HasAttackHitboxes"), .Pointer = &UPaper2DPlusBlueprintLibrary::execHasAttackHitboxes },
		{ .NameUTF8 = UTF8TEXT("HasHurtboxes"), .Pointer = &UPaper2DPlusBlueprintLibrary::execHasHurtboxes },
		{ .NameUTF8 = UTF8TEXT("HitboxToWorldSpace"), .Pointer = &UPaper2DPlusBlueprintLibrary::execHitboxToWorldSpace },
		{ .NameUTF8 = UTF8TEXT("HitboxToWorldSpace3D"), .Pointer = &UPaper2DPlusBlueprintLibrary::execHitboxToWorldSpace3D },
		{ .NameUTF8 = UTF8TEXT("HitboxTypeToString"), .Pointer = &UPaper2DPlusBlueprintLibrary::execHitboxTypeToString },
		{ .NameUTF8 = UTF8TEXT("MakeBox2D"), .Pointer = &UPaper2DPlusBlueprintLibrary::execMakeBox2D },
		{ .NameUTF8 = UTF8TEXT("QuickHitCheck"), .Pointer = &UPaper2DPlusBlueprintLibrary::execQuickHitCheck },
		{ .NameUTF8 = UTF8TEXT("SocketToWorldSpace"), .Pointer = &UPaper2DPlusBlueprintLibrary::execSocketToWorldSpace },
		{ .NameUTF8 = UTF8TEXT("SocketToWorldSpace3D"), .Pointer = &UPaper2DPlusBlueprintLibrary::execSocketToWorldSpace3D },
		{ .NameUTF8 = UTF8TEXT("StringToHitboxType"), .Pointer = &UPaper2DPlusBlueprintLibrary::execStringToHitboxType },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision, "CheckAttackCollision" }, // 159035364
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckAttackCollision3D, "CheckAttackCollision3D" }, // 3863139672
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision, "CheckHitboxCollision" }, // 185991511
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_CheckHitboxCollision3D, "CheckHitboxCollision3D" }, // 425104918
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DoBoxesOverlap, "DoBoxesOverlap" }, // 288975021
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitbox, "DrawDebugHitbox" }, // 2474689915
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxes, "DrawDebugHitboxes" }, // 1821673678
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_DrawDebugHitboxesFromFlipbook, "DrawDebugHitboxesFromFlipbook" }, // 1704761957
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_FrameHasAttack, "FrameHasAttack" }, // 1817543707
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetAttackHitboxes, "GetAttackHitboxes" }, // 1396568527
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxCenter, "GetBoxCenter" }, // 1116552424
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetBoxSize, "GetBoxSize" }, // 679945114
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetCollisionBoxes, "GetCollisionBoxes" }, // 1168080762
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamage, "GetFrameDamage" }, // 3941368197
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameDamageAndKnockback, "GetFrameDamageAndKnockback" }, // 3787764348
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetFrameKnockback, "GetFrameKnockback" }, // 3320819242
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHitboxFrameFromFlipbook, "GetHitboxFrameFromFlipbook" }, // 228679456
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetHurtboxes, "GetHurtboxes" }, // 982651077
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetMaxKnockback, "GetMaxKnockback" }, // 1853678006
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_GetTotalDamage, "GetTotalDamage" }, // 3968259589
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAnyData, "HasAnyData" }, // 2141059726
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasAttackHitboxes, "HasAttackHitboxes" }, // 3444633583
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HasHurtboxes, "HasHurtboxes" }, // 2678127744
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace, "HitboxToWorldSpace" }, // 3513062210
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxToWorldSpace3D, "HitboxToWorldSpace3D" }, // 1468635109
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_HitboxTypeToString, "HitboxTypeToString" }, // 453989458
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_MakeBox2D, "MakeBox2D" }, // 3212710427
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_QuickHitCheck, "QuickHitCheck" }, // 871151558
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace, "SocketToWorldSpace" }, // 234212584
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_SocketToWorldSpace3D, "SocketToWorldSpace3D" }, // 2654070177
		{ &Z_Construct_UFunction_UPaper2DPlusBlueprintLibrary_StringToHitboxType, "StringToHitboxType" }, // 211831668
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaper2DPlusBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics
UObject* (*const Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::ClassParams = {
	&UPaper2DPlusBlueprintLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::Class_MetaDataParams)
};
void UPaper2DPlusBlueprintLibrary::StaticRegisterNativesUPaper2DPlusBlueprintLibrary()
{
	UClass* Class = UPaper2DPlusBlueprintLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPaper2DPlusBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UPaper2DPlusBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary.OuterSingleton;
}
UPaper2DPlusBlueprintLibrary::UPaper2DPlusBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPaper2DPlusBlueprintLibrary);
UPaper2DPlusBlueprintLibrary::~UPaper2DPlusBlueprintLibrary() {}
// ********** End Class UPaper2DPlusBlueprintLibrary ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h__Script_Paper2DPlus_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPaper2DPlusBlueprintLibrary, UPaper2DPlusBlueprintLibrary::StaticClass, TEXT("UPaper2DPlusBlueprintLibrary"), &Z_Registration_Info_UClass_UPaper2DPlusBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaper2DPlusBlueprintLibrary), 4139001504U) },
	};
}; // Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h__Script_Paper2DPlus_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h__Script_Paper2DPlus_272432981{
	TEXT("/Script/Paper2DPlus"),
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h__Script_Paper2DPlus_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusBlueprintLibrary_h__Script_Paper2DPlus_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
