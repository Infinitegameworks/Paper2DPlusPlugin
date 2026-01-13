// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Paper2DPlusTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePaper2DPlusTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_EDimensionStatus();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_EHitboxType();
PAPER2DPLUS_API UEnum* Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FFrameHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FHitboxCollisionResult();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FHitboxData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FSocketData();
PAPER2DPLUS_API UScriptStruct* Z_Construct_UScriptStruct_FSpriteExtractionInfo();
UPackage* Z_Construct_UPackage__Script_Paper2DPlus();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHitboxType ***************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitboxType;
static UEnum* EHitboxType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitboxType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitboxType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Paper2DPlus_EHitboxType, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("EHitboxType"));
	}
	return Z_Registration_Info_UEnum_EHitboxType.OuterSingleton;
}
template<> PAPER2DPLUS_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitboxType>()
{
	return EHitboxType_StaticEnum();
}
struct Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Attack.DisplayName", "Attack" },
		{ "Attack.Name", "EHitboxType::Attack" },
		{ "BlueprintType", "true" },
		{ "Collision.DisplayName", "Collision" },
		{ "Collision.Name", "EHitboxType::Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Type of hitbox - matches the editor export format\n */" },
#endif
		{ "Hurtbox.DisplayName", "Hurtbox" },
		{ "Hurtbox.Name", "EHitboxType::Hurtbox" },
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of hitbox - matches the editor export format" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitboxType::Attack", (int64)EHitboxType::Attack },
		{ "EHitboxType::Hurtbox", (int64)EHitboxType::Hurtbox },
		{ "EHitboxType::Collision", (int64)EHitboxType::Collision },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	"EHitboxType",
	"EHitboxType",
	Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Paper2DPlus_EHitboxType()
{
	if (!Z_Registration_Info_UEnum_EHitboxType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitboxType.InnerSingleton, Z_Construct_UEnum_Paper2DPlus_EHitboxType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitboxType.InnerSingleton;
}
// ********** End Enum EHitboxType *****************************************************************

// ********** Begin ScriptStruct FHitboxData *******************************************************
struct Z_Construct_UScriptStruct_FHitboxData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitboxData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitboxData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Single hitbox data\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single hitbox data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of hitbox: attack, hurtbox, or collision */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of hitbox: attack, hurtbox, or collision" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** X position relative to sprite origin */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "X position relative to sprite origin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Y position relative to sprite origin */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Y position relative to sprite origin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Width of the hitbox */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width of the hitbox" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the hitbox */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the hitbox" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Damage dealt (for attack type) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Damage dealt (for attack type)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Knockback_MetaData[] = {
		{ "Category", "Hitbox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Knockback force (for attack type) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Knockback force (for attack type)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitboxData constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Knockback;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitboxData constinit property declarations *************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitboxData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitboxData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitboxData;
class UScriptStruct* FHitboxData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitboxData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitboxData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitboxData, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("HitboxData"));
	}
	return Z_Registration_Info_UScriptStruct_FHitboxData.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitboxData Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, Type), Z_Construct_UEnum_Paper2DPlus_EHitboxType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 3673529899
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, X), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_X_MetaData), NewProp_X_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, Y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Y_MetaData), NewProp_Y_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, Width), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Width_MetaData), NewProp_Width_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, Height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Height_MetaData), NewProp_Height_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Knockback = { "Knockback", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxData, Knockback), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Knockback_MetaData), NewProp_Knockback_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitboxData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Width,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxData_Statics::NewProp_Knockback,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitboxData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitboxData Property Definitions ************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitboxData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	&NewStructOps,
	"HitboxData",
	Z_Construct_UScriptStruct_FHitboxData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitboxData_Statics::PropPointers),
	sizeof(FHitboxData),
	alignof(FHitboxData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitboxData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitboxData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitboxData()
{
	if (!Z_Registration_Info_UScriptStruct_FHitboxData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitboxData.InnerSingleton, Z_Construct_UScriptStruct_FHitboxData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitboxData.InnerSingleton);
}
// ********** End ScriptStruct FHitboxData *********************************************************

// ********** Begin ScriptStruct FSocketData *******************************************************
struct Z_Construct_UScriptStruct_FSocketData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSocketData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSocketData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Socket/attachment point data\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Socket/attachment point data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Socket" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the socket (e.g., \"Muzzle\", \"Hand\", \"Foot\") */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the socket (e.g., \"Muzzle\", \"Hand\", \"Foot\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
		{ "Category", "Socket" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** X position relative to sprite origin */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "X position relative to sprite origin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
		{ "Category", "Socket" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Y position relative to sprite origin */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Y position relative to sprite origin" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSocketData constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSocketData constinit property declarations *************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSocketData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSocketData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSocketData;
class UScriptStruct* FSocketData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSocketData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSocketData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSocketData, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("SocketData"));
	}
	return Z_Registration_Info_UScriptStruct_FSocketData.OuterSingleton;
	}

// ********** Begin ScriptStruct FSocketData Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSocketData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSocketData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSocketData_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSocketData, X), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_X_MetaData), NewProp_X_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSocketData_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSocketData, Y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Y_MetaData), NewProp_Y_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSocketData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSocketData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSocketData_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSocketData_Statics::NewProp_Y,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSocketData Property Definitions ************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSocketData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	&NewStructOps,
	"SocketData",
	Z_Construct_UScriptStruct_FSocketData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketData_Statics::PropPointers),
	sizeof(FSocketData),
	alignof(FSocketData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSocketData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSocketData()
{
	if (!Z_Registration_Info_UScriptStruct_FSocketData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSocketData.InnerSingleton, Z_Construct_UScriptStruct_FSocketData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSocketData.InnerSingleton);
}
// ********** End ScriptStruct FSocketData *********************************************************

// ********** Begin ScriptStruct FFrameHitboxData **************************************************
struct Z_Construct_UScriptStruct_FFrameHitboxData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFrameHitboxData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFrameHitboxData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * All hitbox/socket data for a single frame\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All hitbox/socket data for a single frame" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameName_MetaData[] = {
		{ "Category", "Frame" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the frame (filename without extension) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the frame (filename without extension)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hitboxes_MetaData[] = {
		{ "Category", "Frame" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All hitboxes on this frame */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All hitboxes on this frame" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sockets_MetaData[] = {
		{ "Category", "Frame" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All sockets/attachment points on this frame */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All sockets/attachment points on this frame" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFrameHitboxData constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FrameName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hitboxes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Hitboxes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Sockets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Sockets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFrameHitboxData constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFrameHitboxData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFrameHitboxData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFrameHitboxData;
class UScriptStruct* FFrameHitboxData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFrameHitboxData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFrameHitboxData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFrameHitboxData, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("FrameHitboxData"));
	}
	return Z_Registration_Info_UScriptStruct_FFrameHitboxData.OuterSingleton;
	}

// ********** Begin ScriptStruct FFrameHitboxData Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_FrameName = { "FrameName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFrameHitboxData, FrameName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameName_MetaData), NewProp_FrameName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Hitboxes_Inner = { "Hitboxes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(0, nullptr) }; // 975460340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Hitboxes = { "Hitboxes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFrameHitboxData, Hitboxes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hitboxes_MetaData), NewProp_Hitboxes_MetaData) }; // 975460340
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Sockets_Inner = { "Sockets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSocketData, METADATA_PARAMS(0, nullptr) }; // 3308025426
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Sockets = { "Sockets", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFrameHitboxData, Sockets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sockets_MetaData), NewProp_Sockets_MetaData) }; // 3308025426
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFrameHitboxData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_FrameName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Hitboxes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Hitboxes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Sockets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewProp_Sockets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFrameHitboxData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFrameHitboxData Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFrameHitboxData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	&NewStructOps,
	"FrameHitboxData",
	Z_Construct_UScriptStruct_FFrameHitboxData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFrameHitboxData_Statics::PropPointers),
	sizeof(FFrameHitboxData),
	alignof(FFrameHitboxData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFrameHitboxData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFrameHitboxData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFrameHitboxData()
{
	if (!Z_Registration_Info_UScriptStruct_FFrameHitboxData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFrameHitboxData.InnerSingleton, Z_Construct_UScriptStruct_FFrameHitboxData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFrameHitboxData.InnerSingleton);
}
// ********** End ScriptStruct FFrameHitboxData ****************************************************

// ********** Begin ScriptStruct FHitboxCollisionResult ********************************************
struct Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitboxCollisionResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitboxCollisionResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Result of a hitbox collision check\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Result of a hitbox collision check" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHit_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Did a collision occur? */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Did a collision occur?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackHitbox_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The attack hitbox that made contact */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The attack hitbox that made contact" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtHitbox_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The hurtbox that was hit */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The hurtbox that was hit" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitLocation_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space center of the collision overlap */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space center of the collision overlap" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total damage from this hit */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total damage from this hit" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Knockback_MetaData[] = {
		{ "Category", "Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total knockback from this hit */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total knockback from this hit" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitboxCollisionResult constinit property declarations ************
	static void NewProp_bHit_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackHitbox;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HurtHitbox;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitLocation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Knockback;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitboxCollisionResult constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitboxCollisionResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitboxCollisionResult;
class UScriptStruct* FHitboxCollisionResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitboxCollisionResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitboxCollisionResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitboxCollisionResult, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("HitboxCollisionResult"));
	}
	return Z_Registration_Info_UScriptStruct_FHitboxCollisionResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitboxCollisionResult Property Definitions ***********************
void Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_bHit_SetBit(void* Obj)
{
	((FHitboxCollisionResult*)Obj)->bHit = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_bHit = { "bHit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHitboxCollisionResult), &Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_bHit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHit_MetaData), NewProp_bHit_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_AttackHitbox = { "AttackHitbox", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxCollisionResult, AttackHitbox), Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackHitbox_MetaData), NewProp_AttackHitbox_MetaData) }; // 975460340
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_HurtHitbox = { "HurtHitbox", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxCollisionResult, HurtHitbox), Z_Construct_UScriptStruct_FHitboxData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtHitbox_MetaData), NewProp_HurtHitbox_MetaData) }; // 975460340
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_HitLocation = { "HitLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxCollisionResult, HitLocation), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitLocation_MetaData), NewProp_HitLocation_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxCollisionResult, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_Knockback = { "Knockback", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitboxCollisionResult, Knockback), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Knockback_MetaData), NewProp_Knockback_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_bHit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_AttackHitbox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_HurtHitbox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_HitLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewProp_Knockback,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitboxCollisionResult Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	&NewStructOps,
	"HitboxCollisionResult",
	Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::PropPointers),
	sizeof(FHitboxCollisionResult),
	alignof(FHitboxCollisionResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitboxCollisionResult()
{
	if (!Z_Registration_Info_UScriptStruct_FHitboxCollisionResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitboxCollisionResult.InnerSingleton, Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitboxCollisionResult.InnerSingleton);
}
// ********** End ScriptStruct FHitboxCollisionResult **********************************************

// ********** Begin Enum ESpriteAnchor *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESpriteAnchor;
static UEnum* ESpriteAnchor_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESpriteAnchor.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESpriteAnchor.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("ESpriteAnchor"));
	}
	return Z_Registration_Info_UEnum_ESpriteAnchor.OuterSingleton;
}
template<> PAPER2DPLUS_NON_ATTRIBUTED_API UEnum* StaticEnum<ESpriteAnchor>()
{
	return ESpriteAnchor_StaticEnum();
}
struct Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BottomCenter.DisplayName", "Bottom Center" },
		{ "BottomCenter.Name", "ESpriteAnchor::BottomCenter" },
		{ "BottomLeft.DisplayName", "Bottom Left" },
		{ "BottomLeft.Name", "ESpriteAnchor::BottomLeft" },
		{ "BottomRight.DisplayName", "Bottom Right" },
		{ "BottomRight.Name", "ESpriteAnchor::BottomRight" },
		{ "Center.DisplayName", "Center" },
		{ "Center.Name", "ESpriteAnchor::Center" },
		{ "CenterLeft.DisplayName", "Center Left" },
		{ "CenterLeft.Name", "ESpriteAnchor::CenterLeft" },
		{ "CenterRight.DisplayName", "Center Right" },
		{ "CenterRight.Name", "ESpriteAnchor::CenterRight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Anchor point for sprite alignment when applying uniform dimensions\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anchor point for sprite alignment when applying uniform dimensions" },
#endif
		{ "TopCenter.DisplayName", "Top Center" },
		{ "TopCenter.Name", "ESpriteAnchor::TopCenter" },
		{ "TopLeft.DisplayName", "Top Left" },
		{ "TopLeft.Name", "ESpriteAnchor::TopLeft" },
		{ "TopRight.DisplayName", "Top Right" },
		{ "TopRight.Name", "ESpriteAnchor::TopRight" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESpriteAnchor::TopLeft", (int64)ESpriteAnchor::TopLeft },
		{ "ESpriteAnchor::TopCenter", (int64)ESpriteAnchor::TopCenter },
		{ "ESpriteAnchor::TopRight", (int64)ESpriteAnchor::TopRight },
		{ "ESpriteAnchor::CenterLeft", (int64)ESpriteAnchor::CenterLeft },
		{ "ESpriteAnchor::Center", (int64)ESpriteAnchor::Center },
		{ "ESpriteAnchor::CenterRight", (int64)ESpriteAnchor::CenterRight },
		{ "ESpriteAnchor::BottomLeft", (int64)ESpriteAnchor::BottomLeft },
		{ "ESpriteAnchor::BottomCenter", (int64)ESpriteAnchor::BottomCenter },
		{ "ESpriteAnchor::BottomRight", (int64)ESpriteAnchor::BottomRight },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	"ESpriteAnchor",
	"ESpriteAnchor",
	Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor()
{
	if (!Z_Registration_Info_UEnum_ESpriteAnchor.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESpriteAnchor.InnerSingleton, Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESpriteAnchor.InnerSingleton;
}
// ********** End Enum ESpriteAnchor ***************************************************************

// ********** Begin Enum EDimensionStatus **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDimensionStatus;
static UEnum* EDimensionStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDimensionStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDimensionStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Paper2DPlus_EDimensionStatus, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("EDimensionStatus"));
	}
	return Z_Registration_Info_UEnum_EDimensionStatus.OuterSingleton;
}
template<> PAPER2DPLUS_NON_ATTRIBUTED_API UEnum* StaticEnum<EDimensionStatus>()
{
	return EDimensionStatus_StaticEnum();
}
struct Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Dimension status indicator for visual feedback\n */" },
#endif
		{ "LargerThanUniform.DisplayName", "Larger Than Uniform" },
		{ "LargerThanUniform.Name", "EDimensionStatus::LargerThanUniform" },
		{ "MatchesUniform.DisplayName", "Matches Uniform" },
		{ "MatchesUniform.Name", "EDimensionStatus::MatchesUniform" },
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
		{ "NoUniformSet.DisplayName", "No Uniform Set" },
		{ "NoUniformSet.Name", "EDimensionStatus::NoUniformSet" },
		{ "SmallerThanUniform.DisplayName", "Smaller Than Uniform" },
		{ "SmallerThanUniform.Name", "EDimensionStatus::SmallerThanUniform" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dimension status indicator for visual feedback" },
#endif
		{ "Unknown.DisplayName", "Unknown" },
		{ "Unknown.Name", "EDimensionStatus::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDimensionStatus::Unknown", (int64)EDimensionStatus::Unknown },
		{ "EDimensionStatus::MatchesUniform", (int64)EDimensionStatus::MatchesUniform },
		{ "EDimensionStatus::SmallerThanUniform", (int64)EDimensionStatus::SmallerThanUniform },
		{ "EDimensionStatus::LargerThanUniform", (int64)EDimensionStatus::LargerThanUniform },
		{ "EDimensionStatus::NoUniformSet", (int64)EDimensionStatus::NoUniformSet },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	"EDimensionStatus",
	"EDimensionStatus",
	Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Paper2DPlus_EDimensionStatus()
{
	if (!Z_Registration_Info_UEnum_EDimensionStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDimensionStatus.InnerSingleton, Z_Construct_UEnum_Paper2DPlus_EDimensionStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDimensionStatus.InnerSingleton;
}
// ********** End Enum EDimensionStatus ************************************************************

// ********** Begin ScriptStruct FSpriteExtractionInfo *********************************************
struct Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSpriteExtractionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSpriteExtractionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Extraction metadata for sprites - stores information needed to re-extract\n */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extraction metadata for sprites - stores information needed to re-extract" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceOffset_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Position in source texture (top-left corner) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Position in source texture (top-left corner)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginalDimensions_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Original detected bounds (tight fit around opaque pixels) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Original detected bounds (tight fit around opaque pixels)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentDimensions_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current sprite dimensions (may differ from original if uniform sizing applied) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current sprite dimensions (may differ from original if uniform sizing applied)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaThreshold_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Alpha threshold used during extraction */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Alpha threshold used during extraction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding applied during extraction */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding applied during extraction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Anchor_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Anchor point used for uniform sizing alignment */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anchor point used for uniform sizing alignment" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUsedUniformSizing_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Was this frame created with uniform sizing? */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Was this frame created with uniform sizing?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtractionTime_MetaData[] = {
		{ "Category", "Extraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Timestamp of last extraction */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timestamp of last extraction" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSpriteExtractionInfo constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OriginalDimensions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentDimensions;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AlphaThreshold;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Anchor_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Anchor;
	static void NewProp_bUsedUniformSizing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsedUniformSizing;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExtractionTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSpriteExtractionInfo constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSpriteExtractionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo;
class UScriptStruct* FSpriteExtractionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSpriteExtractionInfo, (UObject*)Z_Construct_UPackage__Script_Paper2DPlus(), TEXT("SpriteExtractionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FSpriteExtractionInfo Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_SourceOffset = { "SourceOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, SourceOffset), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceOffset_MetaData), NewProp_SourceOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_OriginalDimensions = { "OriginalDimensions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, OriginalDimensions), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginalDimensions_MetaData), NewProp_OriginalDimensions_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_CurrentDimensions = { "CurrentDimensions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, CurrentDimensions), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentDimensions_MetaData), NewProp_CurrentDimensions_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_AlphaThreshold = { "AlphaThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, AlphaThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaThreshold_MetaData), NewProp_AlphaThreshold_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, Padding), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_Anchor_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, Anchor), Z_Construct_UEnum_Paper2DPlus_ESpriteAnchor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Anchor_MetaData), NewProp_Anchor_MetaData) }; // 3330642034
void Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_bUsedUniformSizing_SetBit(void* Obj)
{
	((FSpriteExtractionInfo*)Obj)->bUsedUniformSizing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_bUsedUniformSizing = { "bUsedUniformSizing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSpriteExtractionInfo), &Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_bUsedUniformSizing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUsedUniformSizing_MetaData), NewProp_bUsedUniformSizing_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_ExtractionTime = { "ExtractionTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpriteExtractionInfo, ExtractionTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtractionTime_MetaData), NewProp_ExtractionTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_SourceOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_OriginalDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_CurrentDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_AlphaThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_Anchor_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_bUsedUniformSizing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewProp_ExtractionTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSpriteExtractionInfo Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
	nullptr,
	&NewStructOps,
	"SpriteExtractionInfo",
	Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::PropPointers),
	sizeof(FSpriteExtractionInfo),
	alignof(FSpriteExtractionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSpriteExtractionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo.InnerSingleton, Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo.InnerSingleton);
}
// ********** End ScriptStruct FSpriteExtractionInfo ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHitboxType_StaticEnum, TEXT("EHitboxType"), &Z_Registration_Info_UEnum_EHitboxType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3673529899U) },
		{ ESpriteAnchor_StaticEnum, TEXT("ESpriteAnchor"), &Z_Registration_Info_UEnum_ESpriteAnchor, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3330642034U) },
		{ EDimensionStatus_StaticEnum, TEXT("EDimensionStatus"), &Z_Registration_Info_UEnum_EDimensionStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4196416693U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FHitboxData::StaticStruct, Z_Construct_UScriptStruct_FHitboxData_Statics::NewStructOps, TEXT("HitboxData"),&Z_Registration_Info_UScriptStruct_FHitboxData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitboxData), 975460340U) },
		{ FSocketData::StaticStruct, Z_Construct_UScriptStruct_FSocketData_Statics::NewStructOps, TEXT("SocketData"),&Z_Registration_Info_UScriptStruct_FSocketData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSocketData), 3308025426U) },
		{ FFrameHitboxData::StaticStruct, Z_Construct_UScriptStruct_FFrameHitboxData_Statics::NewStructOps, TEXT("FrameHitboxData"),&Z_Registration_Info_UScriptStruct_FFrameHitboxData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFrameHitboxData), 586679813U) },
		{ FHitboxCollisionResult::StaticStruct, Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics::NewStructOps, TEXT("HitboxCollisionResult"),&Z_Registration_Info_UScriptStruct_FHitboxCollisionResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitboxCollisionResult), 1931338514U) },
		{ FSpriteExtractionInfo::StaticStruct, Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics::NewStructOps, TEXT("SpriteExtractionInfo"),&Z_Registration_Info_UScriptStruct_FSpriteExtractionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSpriteExtractionInfo), 3759999667U) },
	};
}; // Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_4117885432{
	TEXT("/Script/Paper2DPlus"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h__Script_Paper2DPlus_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
