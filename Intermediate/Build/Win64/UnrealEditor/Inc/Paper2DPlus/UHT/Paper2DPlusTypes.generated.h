// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Paper2DPlusTypes.h"

#ifdef PAPER2DPLUS_Paper2DPlusTypes_generated_h
#error "Paper2DPlusTypes.generated.h already included, missing '#pragma once' in Paper2DPlusTypes.h"
#endif
#define PAPER2DPLUS_Paper2DPlusTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FHitboxData *******************************************************
struct Z_Construct_UScriptStruct_FHitboxData_Statics;
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h_27_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitboxData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitboxData;
// ********** End ScriptStruct FHitboxData *********************************************************

// ********** Begin ScriptStruct FSocketData *******************************************************
struct Z_Construct_UScriptStruct_FSocketData_Statics;
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h_76_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSocketData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FSocketData;
// ********** End ScriptStruct FSocketData *********************************************************

// ********** Begin ScriptStruct FFrameHitboxData **************************************************
struct Z_Construct_UScriptStruct_FFrameHitboxData_Statics;
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h_103_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FFrameHitboxData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FFrameHitboxData;
// ********** End ScriptStruct FFrameHitboxData ****************************************************

// ********** Begin ScriptStruct FHitboxCollisionResult ********************************************
struct Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics;
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h_158_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitboxCollisionResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitboxCollisionResult;
// ********** End ScriptStruct FHitboxCollisionResult **********************************************

// ********** Begin ScriptStruct FSpriteExtractionInfo *********************************************
struct Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics;
#define FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h_225_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSpriteExtractionInfo_Statics; \
	static class UScriptStruct* StaticStruct();


struct FSpriteExtractionInfo;
// ********** End ScriptStruct FSpriteExtractionInfo ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlus_Public_Paper2DPlusTypes_h

// ********** Begin Enum EHitboxType ***************************************************************
#define FOREACH_ENUM_EHITBOXTYPE(op) \
	op(EHitboxType::Attack) \
	op(EHitboxType::Hurtbox) \
	op(EHitboxType::Collision) 

enum class EHitboxType : uint8;
template<> struct TIsUEnumClass<EHitboxType> { enum { Value = true }; };
template<> PAPER2DPLUS_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitboxType>();
// ********** End Enum EHitboxType *****************************************************************

// ********** Begin Enum ESpriteAnchor *************************************************************
#define FOREACH_ENUM_ESPRITEANCHOR(op) \
	op(ESpriteAnchor::TopLeft) \
	op(ESpriteAnchor::TopCenter) \
	op(ESpriteAnchor::TopRight) \
	op(ESpriteAnchor::CenterLeft) \
	op(ESpriteAnchor::Center) \
	op(ESpriteAnchor::CenterRight) \
	op(ESpriteAnchor::BottomLeft) \
	op(ESpriteAnchor::BottomCenter) \
	op(ESpriteAnchor::BottomRight) 

enum class ESpriteAnchor : uint8;
template<> struct TIsUEnumClass<ESpriteAnchor> { enum { Value = true }; };
template<> PAPER2DPLUS_NON_ATTRIBUTED_API UEnum* StaticEnum<ESpriteAnchor>();
// ********** End Enum ESpriteAnchor ***************************************************************

// ********** Begin Enum EDimensionStatus **********************************************************
#define FOREACH_ENUM_EDIMENSIONSTATUS(op) \
	op(EDimensionStatus::Unknown) \
	op(EDimensionStatus::MatchesUniform) \
	op(EDimensionStatus::SmallerThanUniform) \
	op(EDimensionStatus::LargerThanUniform) \
	op(EDimensionStatus::NoUniformSet) 

enum class EDimensionStatus : uint8;
template<> struct TIsUEnumClass<EDimensionStatus> { enum { Value = true }; };
template<> PAPER2DPLUS_NON_ATTRIBUTED_API UEnum* StaticEnum<EDimensionStatus>();
// ********** End Enum EDimensionStatus ************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
