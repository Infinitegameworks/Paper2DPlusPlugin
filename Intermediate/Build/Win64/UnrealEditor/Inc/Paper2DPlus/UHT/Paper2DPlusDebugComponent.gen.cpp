// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Paper2DPlusDebugComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePaper2DPlusDebugComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusDebugComponent();
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusDebugComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Paper2DPlus();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPaper2DPlusDebugComponent Function DrawHitboxesNow **********************
struct Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics
{
	struct Paper2DPlusDebugComponent_eventDrawHitboxesNow_Parms
	{
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus Debug" },
		{ "CPP_Default_Duration", "0.000000" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DrawHitboxesNow constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DrawHitboxesNow constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DrawHitboxesNow Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Paper2DPlusDebugComponent_eventDrawHitboxesNow_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::PropPointers) < 2048);
// ********** End Function DrawHitboxesNow Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusDebugComponent, nullptr, "DrawHitboxesNow", 	Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::Paper2DPlusDebugComponent_eventDrawHitboxesNow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::Paper2DPlusDebugComponent_eventDrawHitboxesNow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusDebugComponent::execDrawHitboxesNow)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DrawHitboxesNow(Z_Param_Duration);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusDebugComponent Function DrawHitboxesNow ************************

// ********** Begin Class UPaper2DPlusDebugComponent Function SetDebugDrawEnabled ******************
struct Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics
{
	struct Paper2DPlusDebugComponent_eventSetDebugDrawEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==========================================\n// BLUEPRINT FUNCTIONS\n// ==========================================\n" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BLUEPRINT FUNCTIONS" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetDebugDrawEnabled constinit property declarations *******************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDebugDrawEnabled constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDebugDrawEnabled Property Definitions ******************************
void Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((Paper2DPlusDebugComponent_eventSetDebugDrawEnabled_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusDebugComponent_eventSetDebugDrawEnabled_Parms), &Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::PropPointers) < 2048);
// ********** End Function SetDebugDrawEnabled Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusDebugComponent, nullptr, "SetDebugDrawEnabled", 	Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::Paper2DPlusDebugComponent_eventSetDebugDrawEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::Paper2DPlusDebugComponent_eventSetDebugDrawEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusDebugComponent::execSetDebugDrawEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDebugDrawEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusDebugComponent Function SetDebugDrawEnabled ********************

// ********** Begin Class UPaper2DPlusDebugComponent Function SetFlipX *****************************
struct Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics
{
	struct Paper2DPlusDebugComponent_eventSetFlipX_Parms
	{
		bool bNewFlipX;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Paper2DPlus Debug" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFlipX constinit property declarations ******************************
	static void NewProp_bNewFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewFlipX;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFlipX constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFlipX Property Definitions *****************************************
void Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::NewProp_bNewFlipX_SetBit(void* Obj)
{
	((Paper2DPlusDebugComponent_eventSetFlipX_Parms*)Obj)->bNewFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::NewProp_bNewFlipX = { "bNewFlipX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Paper2DPlusDebugComponent_eventSetFlipX_Parms), &Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::NewProp_bNewFlipX_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::NewProp_bNewFlipX,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::PropPointers) < 2048);
// ********** End Function SetFlipX Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPaper2DPlusDebugComponent, nullptr, "SetFlipX", 	Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::Paper2DPlusDebugComponent_eventSetFlipX_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::Paper2DPlusDebugComponent_eventSetFlipX_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPaper2DPlusDebugComponent::execSetFlipX)
{
	P_GET_UBOOL(Z_Param_bNewFlipX);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFlipX(Z_Param_bNewFlipX);
	P_NATIVE_END;
}
// ********** End Class UPaper2DPlusDebugComponent Function SetFlipX *******************************

// ********** Begin Class UPaper2DPlusDebugComponent ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPaper2DPlusDebugComponent;
UClass* UPaper2DPlusDebugComponent::GetPrivateStaticClass()
{
	using TClass = UPaper2DPlusDebugComponent;
	if (!Z_Registration_Info_UClass_UPaper2DPlusDebugComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("Paper2DPlusDebugComponent"),
			Z_Registration_Info_UClass_UPaper2DPlusDebugComponent.InnerSingleton,
			StaticRegisterNativesUPaper2DPlusDebugComponent,
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
	return Z_Registration_Info_UClass_UPaper2DPlusDebugComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPaper2DPlusDebugComponent_NoRegister()
{
	return UPaper2DPlusDebugComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Paper2DPlus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Component that automatically draws debug hitboxes for an actor.\n * Add to any actor with a PaperFlipbookComponent to visualize hitboxes in-game.\n */" },
#endif
		{ "DisplayName", "Paper2DPlus Debug Draw" },
		{ "IncludePath", "Paper2DPlusDebugComponent.h" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component that automatically draws debug hitboxes for an actor.\nAdd to any actor with a PaperFlipbookComponent to visualize hitboxes in-game." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterData_MetaData[] = {
		{ "Category", "Paper2DPlus Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The character data asset to visualize */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The character data asset to visualize" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlipbookComponent_MetaData[] = {
		{ "Category", "Paper2DPlus Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to the flipbook component (auto-found if not set) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the flipbook component (auto-found if not set)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugDraw_MetaData[] = {
		{ "Category", "Paper2DPlus Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable/disable debug drawing */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable/disable debug drawing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFlipX_MetaData[] = {
		{ "Category", "Paper2DPlus Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the character is facing left (flips hitboxes) */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the character is facing left (flips hitboxes)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "Paper2DPlus Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale multiplier for hitboxes */" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale multiplier for hitboxes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawAttackHitboxes_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Options" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==========================================\n// DRAW OPTIONS\n// ==========================================\n" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DRAW OPTIONS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawHurtboxes_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Options" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawCollisionBoxes_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Options" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawSockets_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Options" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackColor_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Colors" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==========================================\n// COLORS\n// ==========================================\n" },
#endif
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COLORS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtboxColor_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Colors" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionColor_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Colors" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketColor_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Colors" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineThickness_MetaData[] = {
		{ "Category", "Paper2DPlus Debug|Colors" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.5" },
		{ "ModuleRelativePath", "Public/Paper2DPlusDebugComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPaper2DPlusDebugComponent constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FlipbookComponent;
	static void NewProp_bEnableDebugDraw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugDraw;
	static void NewProp_bFlipX_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static void NewProp_bDrawAttackHitboxes_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawAttackHitboxes;
	static void NewProp_bDrawHurtboxes_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawHurtboxes;
	static void NewProp_bDrawCollisionBoxes_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawCollisionBoxes;
	static void NewProp_bDrawSockets_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawSockets;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HurtboxColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CollisionColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SocketColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineThickness;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPaper2DPlusDebugComponent constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DrawHitboxesNow"), .Pointer = &UPaper2DPlusDebugComponent::execDrawHitboxesNow },
		{ .NameUTF8 = UTF8TEXT("SetDebugDrawEnabled"), .Pointer = &UPaper2DPlusDebugComponent::execSetDebugDrawEnabled },
		{ .NameUTF8 = UTF8TEXT("SetFlipX"), .Pointer = &UPaper2DPlusDebugComponent::execSetFlipX },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaper2DPlusDebugComponent_DrawHitboxesNow, "DrawHitboxesNow" }, // 528649500
		{ &Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetDebugDrawEnabled, "SetDebugDrawEnabled" }, // 1522695926
		{ &Z_Construct_UFunction_UPaper2DPlusDebugComponent_SetFlipX, "SetFlipX" }, // 2309260350
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaper2DPlusDebugComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics

// ********** Begin Class UPaper2DPlusDebugComponent Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, CharacterData), Z_Construct_UClass_UPaper2DPlusCharacterDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterData_MetaData), NewProp_CharacterData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_FlipbookComponent = { "FlipbookComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, FlipbookComponent), Z_Construct_UClass_UPaperFlipbookComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlipbookComponent_MetaData), NewProp_FlipbookComponent_MetaData) };
void Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bEnableDebugDraw_SetBit(void* Obj)
{
	((UPaper2DPlusDebugComponent*)Obj)->bEnableDebugDraw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bEnableDebugDraw = { "bEnableDebugDraw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusDebugComponent), &Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bEnableDebugDraw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugDraw_MetaData), NewProp_bEnableDebugDraw_MetaData) };
void Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bFlipX_SetBit(void* Obj)
{
	((UPaper2DPlusDebugComponent*)Obj)->bFlipX = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bFlipX = { "bFlipX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusDebugComponent), &Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bFlipX_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFlipX_MetaData), NewProp_bFlipX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, Scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
void Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawAttackHitboxes_SetBit(void* Obj)
{
	((UPaper2DPlusDebugComponent*)Obj)->bDrawAttackHitboxes = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawAttackHitboxes = { "bDrawAttackHitboxes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusDebugComponent), &Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawAttackHitboxes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawAttackHitboxes_MetaData), NewProp_bDrawAttackHitboxes_MetaData) };
void Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawHurtboxes_SetBit(void* Obj)
{
	((UPaper2DPlusDebugComponent*)Obj)->bDrawHurtboxes = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawHurtboxes = { "bDrawHurtboxes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusDebugComponent), &Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawHurtboxes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawHurtboxes_MetaData), NewProp_bDrawHurtboxes_MetaData) };
void Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawCollisionBoxes_SetBit(void* Obj)
{
	((UPaper2DPlusDebugComponent*)Obj)->bDrawCollisionBoxes = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawCollisionBoxes = { "bDrawCollisionBoxes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusDebugComponent), &Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawCollisionBoxes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawCollisionBoxes_MetaData), NewProp_bDrawCollisionBoxes_MetaData) };
void Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawSockets_SetBit(void* Obj)
{
	((UPaper2DPlusDebugComponent*)Obj)->bDrawSockets = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawSockets = { "bDrawSockets", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaper2DPlusDebugComponent), &Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawSockets_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawSockets_MetaData), NewProp_bDrawSockets_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_AttackColor = { "AttackColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, AttackColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackColor_MetaData), NewProp_AttackColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_HurtboxColor = { "HurtboxColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, HurtboxColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtboxColor_MetaData), NewProp_HurtboxColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_CollisionColor = { "CollisionColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, CollisionColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionColor_MetaData), NewProp_CollisionColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_SocketColor = { "SocketColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, SocketColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketColor_MetaData), NewProp_SocketColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_LineThickness = { "LineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaper2DPlusDebugComponent, LineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineThickness_MetaData), NewProp_LineThickness_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_CharacterData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_FlipbookComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bEnableDebugDraw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bFlipX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawAttackHitboxes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawHurtboxes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawCollisionBoxes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_bDrawSockets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_AttackColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_HurtboxColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_CollisionColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_SocketColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::NewProp_LineThickness,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::PropPointers) < 2048);
// ********** End Class UPaper2DPlusDebugComponent Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::ClassParams = {
	&UPaper2DPlusDebugComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::Class_MetaDataParams)
};
void UPaper2DPlusDebugComponent::StaticRegisterNativesUPaper2DPlusDebugComponent()
{
	UClass* Class = UPaper2DPlusDebugComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPaper2DPlusDebugComponent()
{
	if (!Z_Registration_Info_UClass_UPaper2DPlusDebugComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaper2DPlusDebugComponent.OuterSingleton, Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPaper2DPlusDebugComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPaper2DPlusDebugComponent);
UPaper2DPlusDebugComponent::~UPaper2DPlusDebugComponent() {}
// ********** End Class UPaper2DPlusDebugComponent *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h__Script_Paper2DPlus_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPaper2DPlusDebugComponent, UPaper2DPlusDebugComponent::StaticClass, TEXT("UPaper2DPlusDebugComponent"), &Z_Registration_Info_UClass_UPaper2DPlusDebugComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaper2DPlusDebugComponent), 1614031867U) },
	};
}; // Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h__Script_Paper2DPlus_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h__Script_Paper2DPlus_438901000{
	TEXT("/Script/Paper2DPlus"),
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h__Script_Paper2DPlus_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h__Script_Paper2DPlus_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
