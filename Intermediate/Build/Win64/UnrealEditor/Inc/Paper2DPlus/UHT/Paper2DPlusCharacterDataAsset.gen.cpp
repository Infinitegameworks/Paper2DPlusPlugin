// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Paper2DPlusCharacterDataAsset.h"
#include "Paper2DPlusTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePaper2DPlusCharacterDataAsset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_EDimensionStatus();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_EHitboxType();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FAnimationHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FFrameHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FSocketData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FSpriteExtractionInfo();
UPackage* Z_Construct_UPackage__Script_Paper2DPlus();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FAnimationHitboxData **********************************************
struct Z_Construct_UScriptStruct_FAnimationHitboxData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAnimationHitboxData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAnimationHitboxData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Animation data with hitbox information and sprite extraction metadata\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animation data with hitbox information and sprite extraction metadata" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the animation/flipbook group */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the animation/flipbook group" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Flipbook_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional reference to the Paper2D Flipbook for this animation */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional reference to the Paper2D Flipbook for this animation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Frames_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All frames in this animation with hitbox data */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All frames in this animation with hitbox data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceTexture_MetaData[] = {
		{ "Category", "Sprite Source" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Source texture this animation was extracted from */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source texture this animation was extracted from" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpriteDimensions_MetaData[] = {
		{ "Category", "Sprite Dimensions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current sprite dimensions for this animation */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current sprite dimensions for this animation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameExtractionInfo_MetaData[] = {
		{ "Category", "Sprite Source" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-frame extraction metadata */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-frame extraction metadata" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpritesOutputPath_MetaData[] = {
		{ "Category", "Sprite Source" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Output path where sprites for this animation are saved */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Output path where sprites for this animation are saved" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAnimationHitboxData constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Frames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Frames;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SourceTexture;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpriteDimensions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FrameExtractionInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FrameExtractionInfo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SpritesOutputPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAnimationHitboxData constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimationHitboxData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAnimationHitboxData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAnimationHitboxData;
class UScriptStruct* FAnimationHitboxData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAnimationHitboxData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAnimationHitboxData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimationHitboxData, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("AnimationHitboxData"));
	}
	return Z_Registration_Info_UScriptStruct_FAnimationHitboxData.OuterSingleton;
	}

// ********** Begin ScriptStruct FAnimationHitboxData Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Flipbook_MetaData), NewProp_Flipbook_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_Frames_Inner = { "Frames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(0, nullptr) }; // 586679813
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_Frames = { "Frames", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, Frames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Frames_MetaData), NewProp_Frames_MetaData) }; // 586679813
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_SourceTexture = { "SourceTexture", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, SourceTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceTexture_MetaData), NewProp_SourceTexture_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_SpriteDimensions = { "SpriteDimensions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, SpriteDimensions), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpriteDimensions_MetaData), NewProp_SpriteDimensions_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_FrameExtractionInfo_Inner = { "FrameExtractionInfo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSpriteExtractionInfo, METADATA_PARAMS(0, nullptr) }; // 3759999667
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_FrameExtractionInfo = { "FrameExtractionInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, FrameExtractionInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameExtractionInfo_MetaData), NewProp_FrameExtractionInfo_MetaData) }; // 3759999667
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_SpritesOutputPath = { "SpritesOutputPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationHitboxData, SpritesOutputPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpritesOutputPath_MetaData), NewProp_SpritesOutputPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_Frames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_Frames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_SourceTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_SpriteDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_FrameExtractionInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_FrameExtractionInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewProp_SpritesOutputPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAnimationHitboxData Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	&NewStructOps,
	"AnimationHitboxData",
	Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::PropPointers),
	sizeof(FAnimationHitboxData),
	alignof(FAnimationHitboxData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAnimationHitboxData()
{
	if (!Z_Registration_Info_UScriptStruct_FAnimationHitboxData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAnimationHitboxData.InnerSingleton, Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAnimationHitboxData.InnerSingleton);
}
// ********** End ScriptStruct FAnimationHitboxData ************************************************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function AllAnimationsMatchUniform ********
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventAllAnimationsMatchUniform_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dimension Management" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Check if all animations match uniform dimensions */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if all animations match uniform dimensions" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AllAnimationsMatchUniform constinit property declarations *************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AllAnimationsMatchUniform constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AllAnimationsMatchUniform Property Definitions ************************
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventAllAnimationsMatchUniform_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventAllAnimationsMatchUniform_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::PropPointers) < 2048);
// ********** End Function AllAnimationsMatchUniform Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "AllAnimationsMatchUniform", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::Paper2DPlusCharacterDataAsset_eventAllAnimationsMatchUniform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::Paper2DPlusCharacterDataAsset_eventAllAnimationsMatchUniform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execAllAnimationsMatchUniform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AllAnimationsMatchUniform();
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function AllAnimationsMatchUniform **********

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function CalculateLargestDimensions *******
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventCalculateLargestDimensions_Parms
	{
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dimension Management" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Calculate the largest dimensions needed across all animations */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate the largest dimensions needed across all animations" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CalculateLargestDimensions constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CalculateLargestDimensions constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CalculateLargestDimensions Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventCalculateLargestDimensions_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::PropPointers) < 2048);
// ********** End Function CalculateLargestDimensions Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "CalculateLargestDimensions", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::Paper2DPlusCharacterDataAsset_eventCalculateLargestDimensions_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::Paper2DPlusCharacterDataAsset_eventCalculateLargestDimensions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execCalculateLargestDimensions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->CalculateLargestDimensions();
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function CalculateLargestDimensions *********

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function FindAnimationByFlipbook **********
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms
	{
		UPaperFlipbook* Flipbook;
		FAnimationHitboxData OutAnimation;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Find animation index by Flipbook reference */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Find animation index by Flipbook reference" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindAnimationByFlipbook constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flipbook;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutAnimation;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindAnimationByFlipbook constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindAnimationByFlipbook Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_Flipbook = { "Flipbook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms, Flipbook), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_OutAnimation = { "OutAnimation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms, OutAnimation), Z_Construct_UScriptStruct_FAnimationHitboxData, METADATA_PARAMS(0, nullptr) }; // 3390691277
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_Flipbook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_OutAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::PropPointers) < 2048);
// ********** End Function FindAnimationByFlipbook Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "FindAnimationByFlipbook", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::Paper2DPlusCharacterDataAsset_eventFindAnimationByFlipbook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execFindAnimationByFlipbook)
{
	P_GET_OBJECT(UPaperFlipbook,Z_Param_Flipbook);
	P_GET_STRUCT_REF(FAnimationHitboxData,Z_Param_Out_OutAnimation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->FindAnimationByFlipbook(Z_Param_Flipbook,Z_Param_Out_OutAnimation);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function FindAnimationByFlipbook ************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function FindSocket ***********************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventFindSocket_Parms
	{
		FString AnimationName;
		int32 FrameIndex;
		FString SocketName;
		FSocketData OutSocket;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Find a specific socket by name */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Find a specific socket by name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindSocket constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SocketName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSocket;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindSocket constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindSocket Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventFindSocket_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventFindSocket_Parms, FrameIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventFindSocket_Parms, SocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketName_MetaData), NewProp_SocketName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_OutSocket = { "OutSocket", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventFindSocket_Parms, OutSocket), Z_Construct_UScriptStruct_FSocketData, METADATA_PARAMS(0, nullptr) }; // 3308025426
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventFindSocket_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventFindSocket_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_FrameIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_SocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_OutSocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::PropPointers) < 2048);
// ********** End Function FindSocket Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "FindSocket", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::Paper2DPlusCharacterDataAsset_eventFindSocket_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::Paper2DPlusCharacterDataAsset_eventFindSocket_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execFindSocket)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
	P_GET_PROPERTY(FStrProperty,Z_Param_SocketName);
	P_GET_STRUCT_REF(FSocketData,Z_Param_Out_OutSocket);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->FindSocket(Z_Param_AnimationName,Z_Param_FrameIndex,Z_Param_SocketName,Z_Param_Out_OutSocket);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function FindSocket *************************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetAnimation *********************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms
	{
		FString AnimationName;
		FAnimationHitboxData OutAnimation;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get animation data by name */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get animation data by name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAnimation constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutAnimation;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAnimation constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAnimation Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_OutAnimation = { "OutAnimation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms, OutAnimation), Z_Construct_UScriptStruct_FAnimationHitboxData, METADATA_PARAMS(0, nullptr) }; // 3390691277
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_OutAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::PropPointers) < 2048);
// ********** End Function GetAnimation Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetAnimation", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetAnimation)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_STRUCT_REF(FAnimationHitboxData,Z_Param_Out_OutAnimation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAnimation(Z_Param_AnimationName,Z_Param_Out_OutAnimation);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetAnimation ***********************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetAnimationByIndex **************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms
	{
		int32 Index;
		FAnimationHitboxData OutAnimation;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get animation data by index */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get animation data by index" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAnimationByIndex constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutAnimation;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAnimationByIndex constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAnimationByIndex Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_OutAnimation = { "OutAnimation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms, OutAnimation), Z_Construct_UScriptStruct_FAnimationHitboxData, METADATA_PARAMS(0, nullptr) }; // 3390691277
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_OutAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::PropPointers) < 2048);
// ********** End Function GetAnimationByIndex Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetAnimationByIndex", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetAnimationByIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_GET_STRUCT_REF(FAnimationHitboxData,Z_Param_Out_OutAnimation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAnimationByIndex(Z_Param_Index,Z_Param_Out_OutAnimation);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetAnimationByIndex ****************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetAnimationCount ****************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetAnimationCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get total number of animations */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get total number of animations" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAnimationCount constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAnimationCount constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAnimationCount Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimationCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::PropPointers) < 2048);
// ********** End Function GetAnimationCount Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetAnimationCount", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetAnimationCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetAnimationCount();
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetAnimationCount ******************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetAnimationDimensionStatus ******
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetAnimationDimensionStatus_Parms
	{
		FString AnimationName;
		EDimensionStatus ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dimension Management" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get dimension status for a specific animation */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get dimension status for a specific animation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAnimationDimensionStatus constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAnimationDimensionStatus constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAnimationDimensionStatus Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimationDimensionStatus_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimationDimensionStatus_Parms, ReturnValue), Z_Construct_UEnum_Paper2DPlus_EDimensionStatus, METADATA_PARAMS(0, nullptr) }; // 4196416693
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::PropPointers) < 2048);
// ********** End Function GetAnimationDimensionStatus Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetAnimationDimensionStatus", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationDimensionStatus_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationDimensionStatus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetAnimationDimensionStatus)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDimensionStatus*)Z_Param__Result=P_THIS->GetAnimationDimensionStatus(Z_Param_AnimationName);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetAnimationDimensionStatus ********

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetAnimationNames ****************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetAnimationNames_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get all animation names */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all animation names" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAnimationNames constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAnimationNames constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAnimationNames Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetAnimationNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::PropPointers) < 2048);
// ********** End Function GetAnimationNames Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetAnimationNames", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationNames_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::Paper2DPlusCharacterDataAsset_eventGetAnimationNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetAnimationNames)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=P_THIS->GetAnimationNames();
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetAnimationNames ******************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetDimensionStatusCounts *********
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms
	{
		int32 OutMatching;
		int32 OutSmaller;
		int32 OutLarger;
		int32 OutUnknown;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dimension Management" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get animation count by dimension status */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get animation count by dimension status" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDimensionStatusCounts constinit property declarations **************
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutMatching;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutSmaller;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutLarger;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutUnknown;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDimensionStatusCounts constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDimensionStatusCounts Property Definitions *************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutMatching = { "OutMatching", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms, OutMatching), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutSmaller = { "OutSmaller", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms, OutSmaller), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutLarger = { "OutLarger", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms, OutLarger), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutUnknown = { "OutUnknown", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms, OutUnknown), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutMatching,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutSmaller,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutLarger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::NewProp_OutUnknown,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::PropPointers) < 2048);
// ********** End Function GetDimensionStatusCounts Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetDimensionStatusCounts", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::Paper2DPlusCharacterDataAsset_eventGetDimensionStatusCounts_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetDimensionStatusCounts)
{
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutMatching);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutSmaller);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutLarger);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutUnknown);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetDimensionStatusCounts(Z_Param_Out_OutMatching,Z_Param_Out_OutSmaller,Z_Param_Out_OutLarger,Z_Param_Out_OutUnknown);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetDimensionStatusCounts ***********

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetFrame *************************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetFrame_Parms
	{
		FString AnimationName;
		int32 FrameIndex;
		FFrameHitboxData OutFrame;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get frame data by animation name and frame index */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get frame data by animation name and frame index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFrame constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutFrame;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFrame constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFrame Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrame_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrame_Parms, FrameIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_OutFrame = { "OutFrame", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrame_Parms, OutFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(0, nullptr) }; // 586679813
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventGetFrame_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventGetFrame_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_FrameIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_OutFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::PropPointers) < 2048);
// ********** End Function GetFrame Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetFrame", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::Paper2DPlusCharacterDataAsset_eventGetFrame_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::Paper2DPlusCharacterDataAsset_eventGetFrame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetFrame)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_OutFrame);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetFrame(Z_Param_AnimationName,Z_Param_FrameIndex,Z_Param_Out_OutFrame);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetFrame ***************************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetFrameByName *******************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms
	{
		FString AnimationName;
		FString FrameName;
		FFrameHitboxData OutFrame;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get frame data by animation name and frame name */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get frame data by animation name and frame name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFrameByName constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FrameName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutFrame;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFrameByName constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFrameByName Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_FrameName = { "FrameName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms, FrameName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameName_MetaData), NewProp_FrameName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_OutFrame = { "OutFrame", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms, OutFrame), Z_Construct_UScriptStruct_FFrameHitboxData, METADATA_PARAMS(0, nullptr) }; // 586679813
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_FrameName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_OutFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::PropPointers) < 2048);
// ********** End Function GetFrameByName Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetFrameByName", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::Paper2DPlusCharacterDataAsset_eventGetFrameByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetFrameByName)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_PROPERTY(FStrProperty,Z_Param_FrameName);
	P_GET_STRUCT_REF(FFrameHitboxData,Z_Param_Out_OutFrame);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetFrameByName(Z_Param_AnimationName,Z_Param_FrameName,Z_Param_Out_OutFrame);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetFrameByName *********************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetFrameCount ********************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetFrameCount_Parms
	{
		FString AnimationName;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get frame count for an animation */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get frame count for an animation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFrameCount constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFrameCount constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFrameCount Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrameCount_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetFrameCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::PropPointers) < 2048);
// ********** End Function GetFrameCount Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetFrameCount", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::Paper2DPlusCharacterDataAsset_eventGetFrameCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::Paper2DPlusCharacterDataAsset_eventGetFrameCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetFrameCount)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetFrameCount(Z_Param_AnimationName);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetFrameCount **********************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetHitboxes **********************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetHitboxes_Parms
	{
		FString AnimationName;
		int32 FrameIndex;
		TArray<FHitboxData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get all hitboxes for a specific frame */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all hitboxes for a specific frame" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHitboxes constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHitboxes constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHitboxes Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxes_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxes_Parms, FrameIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_FrameIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::PropPointers) < 2048);
// ********** End Function GetHitboxes Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetHitboxes", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::Paper2DPlusCharacterDataAsset_eventGetHitboxes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::Paper2DPlusCharacterDataAsset_eventGetHitboxes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetHitboxes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FHitboxData>*)Z_Param__Result=P_THIS->GetHitboxes(Z_Param_AnimationName,Z_Param_FrameIndex);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetHitboxes ************************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetHitboxesByType ****************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms
	{
		FString AnimationName;
		int32 FrameIndex;
		EHitboxType Type;
		TArray<FHitboxData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get hitboxes of a specific type for a frame */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get hitboxes of a specific type for a frame" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHitboxesByType constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHitboxesByType constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHitboxesByType Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms, FrameIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms, Type), Z_Construct_UEnum_Paper2DPlus_EHitboxType, METADATA_PARAMS(0, nullptr) }; // 3673529899
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_FrameIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::PropPointers) < 2048);
// ********** End Function GetHitboxesByType Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetHitboxesByType", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::Paper2DPlusCharacterDataAsset_eventGetHitboxesByType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetHitboxesByType)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
	P_GET_ENUM(EHitboxType,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FHitboxData>*)Z_Param__Result=P_THIS->GetHitboxesByType(Z_Param_AnimationName,Z_Param_FrameIndex,EHitboxType(Z_Param_Type));
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetHitboxesByType ******************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetMismatchedAnimations **********
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetMismatchedAnimations_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dimension Management" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get list of animations that don't match uniform dimensions */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get list of animations that don't match uniform dimensions" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMismatchedAnimations constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMismatchedAnimations constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMismatchedAnimations Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetMismatchedAnimations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::PropPointers) < 2048);
// ********** End Function GetMismatchedAnimations Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetMismatchedAnimations", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::Paper2DPlusCharacterDataAsset_eventGetMismatchedAnimations_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::Paper2DPlusCharacterDataAsset_eventGetMismatchedAnimations_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetMismatchedAnimations)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=P_THIS->GetMismatchedAnimations();
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetMismatchedAnimations ************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function GetSockets ***********************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventGetSockets_Parms
	{
		FString AnimationName;
		int32 FrameIndex;
		TArray<FSocketData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get all sockets for a specific frame */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all sockets for a specific frame" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSockets constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSockets constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSockets Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetSockets_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetSockets_Parms, FrameIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSocketData, METADATA_PARAMS(0, nullptr) }; // 3308025426
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventGetSockets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3308025426
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_FrameIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::PropPointers) < 2048);
// ********** End Function GetSockets Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "GetSockets", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::Paper2DPlusCharacterDataAsset_eventGetSockets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::Paper2DPlusCharacterDataAsset_eventGetSockets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execGetSockets)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FSocketData>*)Z_Param__Result=P_THIS->GetSockets(Z_Param_AnimationName,Z_Param_FrameIndex);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function GetSockets *************************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function HasAnimation *********************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics
{
	struct Paper2DPlusCharacterDataAsset_eventHasAnimation_Parms
	{
		FString AnimationName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Check if a specific animation exists */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if a specific animation exists" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasAnimation constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnimationName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAnimation constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAnimation Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::NewProp_AnimationName = { "AnimationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusCharacterDataAsset_eventHasAnimation_Parms, AnimationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationName_MetaData), NewProp_AnimationName_MetaData) };
void Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Paper2DPlusCharacterDataAsset_eventHasAnimation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusCharacterDataAsset_eventHasAnimation_Parms), &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::NewProp_AnimationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::PropPointers) < 2048);
// ********** End Function HasAnimation Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "HasAnimation", 	Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::Paper2DPlusCharacterDataAsset_eventHasAnimation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::Paper2DPlusCharacterDataAsset_eventHasAnimation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execHasAnimation)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AnimationName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasAnimation(Z_Param_AnimationName);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function HasAnimation ***********************

// ********** Begin Class UPaper2DPlusCharacterDataAsset Function SetUniformToLargest **************
struct Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dimension Management" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Set uniform dimensions to the largest found across all animations */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set uniform dimensions to the largest found across all animations" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetUniformToLargest constinit property declarations *******************
// ********** End Function SetUniformToLargest constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, nullptr, "SetUniformToLargest", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusCharacterDataAsset::execSetUniformToLargest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetUniformToLargest();
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusCharacterDataAsset Function SetUniformToLargest ****************

// ********** Begin Class UPaper2DPlusCharacterDataAsset *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset;
UClass* UPaper2DPlusCharacterDataAsset::GetPrivateStaticClass()
{
	using TClass = UPaper2DPlusCharacterDataAsset;
	if (!Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("Paper2DPlusCharacterDataAsset"),
			Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset.InnerSingleton,
			StaticRegisterNativesUPaper2DPlusCharacterDataAsset,
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
	return Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister()
{
	return UPaper2DPlusCharacterDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character Data Asset containing all animation hitbox data and sprite dimension management.\n * Manages flipbooks, hitboxes, sockets, and uniform dimensions across all character animations.\n */" },
#endif
		{ "IncludePath", "Paper2DPlusCharacterDataAsset.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character Data Asset containing all animation hitbox data and sprite dimension management.\nManages flipbooks, hitboxes, sockets, and uniform dimensions across all character animations." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display name for this character data (e.g., character name) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display name for this character data (e.g., character name)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Animations_MetaData[] = {
		{ "Category", "Character Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All animations with their hitbox data */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All animations with their hitbox data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceFilePath_MetaData[] = {
		{ "Category", "Import" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Source JSON file path (for re-importing hitbox data) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source JSON file path (for re-importing hitbox data)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastImportTime_MetaData[] = {
		{ "Category", "Import" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Last import timestamp */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Last import timestamp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UniformDimensions_MetaData[] = {
		{ "Category", "Uniform Dimensions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master uniform dimensions for all animations in this character */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master uniform dimensions for all animations in this character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseUniformDimensions_MetaData[] = {
		{ "Category", "Uniform Dimensions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to enforce uniform dimensions across all animations */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to enforce uniform dimensions across all animations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UniformAnchor_MetaData[] = {
		{ "Category", "Uniform Dimensions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Anchor point for uniform dimension alignment */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anchor point for uniform dimension alignment" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAlphaThreshold_MetaData[] = {
		{ "Category", "Extraction Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Alpha threshold to use for sprite extraction */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Alpha threshold to use for sprite extraction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPadding_MetaData[] = {
		{ "Category", "Extraction Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding to apply around detected sprites */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding to apply around detected sprites" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMinSpriteSize_MetaData[] = {
		{ "Category", "Extraction Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum sprite size filter */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusCharacterDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum sprite size filter" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPaper2DPlusCharacterDataAsset constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Animations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Animations;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceFilePath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastImportTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UniformDimensions;
	static void NewProp_bUseUniformDimensions_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseUniformDimensions;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UniformAnchor_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UniformAnchor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultAlphaThreshold;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultPadding;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultMinSpriteSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPaper2DPlusCharacterDataAsset constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AllAnimationsMatchUniform"), .Pointer = &UPaper2DPlusCharacterDataAsset::execAllAnimationsMatchUniform },
		{ .NameUTF8 = UTF8TEXT("CalculateLargestDimensions"), .Pointer = &UPaper2DPlusCharacterDataAsset::execCalculateLargestDimensions },
		{ .NameUTF8 = UTF8TEXT("FindAnimationByFlipbook"), .Pointer = &UPaper2DPlusCharacterDataAsset::execFindAnimationByFlipbook },
		{ .NameUTF8 = UTF8TEXT("FindSocket"), .Pointer = &UPaper2DPlusCharacterDataAsset::execFindSocket },
		{ .NameUTF8 = UTF8TEXT("GetAnimation"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetAnimation },
		{ .NameUTF8 = UTF8TEXT("GetAnimationByIndex"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetAnimationByIndex },
		{ .NameUTF8 = UTF8TEXT("GetAnimationCount"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetAnimationCount },
		{ .NameUTF8 = UTF8TEXT("GetAnimationDimensionStatus"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetAnimationDimensionStatus },
		{ .NameUTF8 = UTF8TEXT("GetAnimationNames"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetAnimationNames },
		{ .NameUTF8 = UTF8TEXT("GetDimensionStatusCounts"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetDimensionStatusCounts },
		{ .NameUTF8 = UTF8TEXT("GetFrame"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetFrame },
		{ .NameUTF8 = UTF8TEXT("GetFrameByName"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetFrameByName },
		{ .NameUTF8 = UTF8TEXT("GetFrameCount"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetFrameCount },
		{ .NameUTF8 = UTF8TEXT("GetHitboxes"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetHitboxes },
		{ .NameUTF8 = UTF8TEXT("GetHitboxesByType"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetHitboxesByType },
		{ .NameUTF8 = UTF8TEXT("GetMismatchedAnimations"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetMismatchedAnimations },
		{ .NameUTF8 = UTF8TEXT("GetSockets"), .Pointer = &UPaper2DPlusCharacterDataAsset::execGetSockets },
		{ .NameUTF8 = UTF8TEXT("HasAnimation"), .Pointer = &UPaper2DPlusCharacterDataAsset::execHasAnimation },
		{ .NameUTF8 = UTF8TEXT("SetUniformToLargest"), .Pointer = &UPaper2DPlusCharacterDataAsset::execSetUniformToLargest },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_AllAnimationsMatchUniform, "AllAnimationsMatchUniform" }, // 1272840839
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_CalculateLargestDimensions, "CalculateLargestDimensions" }, // 2057252601
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindAnimationByFlipbook, "FindAnimationByFlipbook" }, // 2096396867
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_FindSocket, "FindSocket" }, // 519258411
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimation, "GetAnimation" }, // 1124730466
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationByIndex, "GetAnimationByIndex" }, // 109491989
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationCount, "GetAnimationCount" }, // 1647674737
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationDimensionStatus, "GetAnimationDimensionStatus" }, // 1805851653
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetAnimationNames, "GetAnimationNames" }, // 545962209
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetDimensionStatusCounts, "GetDimensionStatusCounts" }, // 2471239472
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrame, "GetFrame" }, // 2831334154
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameByName, "GetFrameByName" }, // 2731446933
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetFrameCount, "GetFrameCount" }, // 4069294788
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxes, "GetHitboxes" }, // 2825632273
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetHitboxesByType, "GetHitboxesByType" }, // 1759154145
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetMismatchedAnimations, "GetMismatchedAnimations" }, // 2148822897
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_GetSockets, "GetSockets" }, // 2300300088
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_HasAnimation, "HasAnimation" }, // 4272256799
		{ &Z_Construct_UFunction_UPaper2DPlusCharacterDataAsset_SetUniformToLargest, "SetUniformToLargest" }, // 2697505289
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaper2DPlusCharacterDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics

// ********** Begin Class UPaper2DPlusCharacterDataAsset Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_Animations_Inner = { "Animations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAnimationHitboxData, METADATA_PARAMS(0, nullptr) }; // 3390691277
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_Animations = { "Animations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, Animations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Animations_MetaData), NewProp_Animations_MetaData) }; // 3390691277
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_SourceFilePath = { "SourceFilePath", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, SourceFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceFilePath_MetaData), NewProp_SourceFilePath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_LastImportTime = { "LastImportTime", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, LastImportTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastImportTime_MetaData), NewProp_LastImportTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_UniformDimensions = { "UniformDimensions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, UniformDimensions), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UniformDimensions_MetaData), NewProp_UniformDimensions_MetaData) };
void Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_bUseUniformDimensions_SetBit(void* Obj)
{
	((UPaper2DPlusCharacterDataAsset*)Obj)->bUseUniformDimensions = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_bUseUniformDimensions = { "bUseUniformDimensions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusCharacterDataAsset), &Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_bUseUniformDimensions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseUniformDimensions_MetaData), NewProp_bUseUniformDimensions_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_UniformAnchor_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_UniformAnchor = { "UniformAnchor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, UniformAnchor), Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UniformAnchor_MetaData), NewProp_UniformAnchor_MetaData) }; // 3330642034
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DefaultAlphaThreshold = { "DefaultAlphaThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, DefaultAlphaThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultAlphaThreshold_MetaData), NewProp_DefaultAlphaThreshold_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DefaultPadding = { "DefaultPadding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, DefaultPadding), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPadding_MetaData), NewProp_DefaultPadding_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DefaultMinSpriteSize = { "DefaultMinSpriteSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusCharacterDataAsset, DefaultMinSpriteSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMinSpriteSize_MetaData), NewProp_DefaultMinSpriteSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_Animations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_Animations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_SourceFilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_LastImportTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_UniformDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_bUseUniformDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_UniformAnchor_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_UniformAnchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DefaultAlphaThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DefaultPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::NewProp_DefaultMinSpriteSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::PropPointers) < 2048);
// ********** End Class UPaper2DPlusCharacterDataAsset Property Definitions ************************
UObject* (*const Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::ClassParams = {
	&UPaper2DPlusCharacterDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::Class_MetaDataParams)
};
void UPaper2DPlusCharacterDataAsset::StaticRegisterNativesUPaper2DPlusCharacterDataAsset()
{
	UClass* Class = UPaper2DPlusCharacterDataAsset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset()
{
	if (!Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset.OuterSingleton, Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPaper2DPlusCharacterDataAsset);
UPaper2DPlusCharacterDataAsset::~UPaper2DPlusCharacterDataAsset() {}
// ********** End Class UPaper2DPlusCharacterDataAsset *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAnimationHitboxData::StaticStruct, Z_Construct_UScriptStruct_FAnimationHitboxData_Statics::NewStructOps, TEXT("AnimationHitboxData"),&Z_Registration_Info_UScriptStruct_FAnimationHitboxData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimationHitboxData), 3390691277U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPaper2DPlusCharacterDataAsset, UPaper2DPlusCharacterDataAsset::StaticClass, TEXT("UPaper2DPlusCharacterDataAsset"), &Z_Registration_Info_UClass_UPaper2DPlusCharacterDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaper2DPlusCharacterDataAsset), 185231426U) },
	};
}; // Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_347161063{
	TEXT("/Script/Paper2DPlus"),
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusCharacterDataAsset_h__Script_Paper2DPlus_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
