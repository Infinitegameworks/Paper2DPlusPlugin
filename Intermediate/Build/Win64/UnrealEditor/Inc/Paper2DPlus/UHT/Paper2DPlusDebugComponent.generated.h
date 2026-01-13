// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Paper2DPlusDebugComponent.h"

#ifdef PAPER2DPLUS_Paper2DPlusDebugComponent_generated_h
#error "Paper2DPlusDebugComponent.generated.h already included, missing '#pragma once' in Paper2DPlusDebugComponent.h"
#endif
#define PAPER2DPLUS_Paper2DPlusDebugComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPaper2DPlusDebugComponent ***********************************************
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDrawHitboxesNow); \
	DECLARE_FUNCTION(execSetFlipX); \
	DECLARE_FUNCTION(execSetDebugDrawEnabled);


struct Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics;
PAPER2DPLUS_API UClass* Z_Construct_UClass_UPaper2DPlusDebugComponent_NoRegister();

#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaper2DPlusDebugComponent(); \
	friend struct ::Z_Construct_UClass_UPaper2DPlusDebugComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PAPER2DPLUS_API UClass* ::Z_Construct_UClass_UPaper2DPlusDebugComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPaper2DPlusDebugComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Paper2DPlus"), Z_Construct_UClass_UPaper2DPlusDebugComponent_NoRegister) \
	DECLARE_SERIALIZER(UPaper2DPlusDebugComponent)


#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPaper2DPlusDebugComponent(UPaper2DPlusDebugComponent&&) = delete; \
	UPaper2DPlusDebugComponent(const UPaper2DPlusDebugComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaper2DPlusDebugComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaper2DPlusDebugComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPaper2DPlusDebugComponent) \
	NO_API virtual ~UPaper2DPlusDebugComponent();


#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_14_PROLOG
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPaper2DPlusDebugComponent;

// ********** End Class UPaper2DPlusDebugComponent *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusDebugComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
