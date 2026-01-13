// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterDataAssetFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCharacterDataAssetFactory() {}

// ********** Begin Cross Module References ********************************************************
PAPER2DPLUSEDITOR_API UClass* Z_Construct_UClass_UCharacterDataAssetFactory();
PAPER2DPLUSEDITOR_API UClass* Z_Construct_UClass_UCharacterDataAssetFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_Paper2DPlusEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCharacterDataAssetFactory ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCharacterDataAssetFactory;
UClass* UCharacterDataAssetFactory::GetPrivateStaticClass()
{
	using TClass = UCharacterDataAssetFactory;
	if (!Z_Registration_Info_UClass_UCharacterDataAssetFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CharacterDataAssetFactory"),
			Z_Registration_Info_UClass_UCharacterDataAssetFactory.InnerSingleton,
			StaticRegisterNativesUCharacterDataAssetFactory,
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
	return Z_Registration_Info_UClass_UCharacterDataAssetFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UCharacterDataAssetFactory_NoRegister()
{
	return UCharacterDataAssetFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCharacterDataAssetFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Factory for creating Paper2DPlusCharacterDataAsset instances from the Content Browser.\n */" },
#endif
		{ "IncludePath", "CharacterDataAssetFactory.h" },
		{ "ModuleRelativePath", "Public/CharacterDataAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Factory for creating Paper2DPlusCharacterDataAsset instances from the Content Browser." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCharacterDataAssetFactory constinit property declarations ***************
// ********** End Class UCharacterDataAssetFactory constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterDataAssetFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCharacterDataAssetFactory_Statics
UObject* (*const Z_Construct_UClass_UCharacterDataAssetFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_Paper2DPlusEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterDataAssetFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterDataAssetFactory_Statics::ClassParams = {
	&UCharacterDataAssetFactory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterDataAssetFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterDataAssetFactory_Statics::Class_MetaDataParams)
};
void UCharacterDataAssetFactory::StaticRegisterNativesUCharacterDataAssetFactory()
{
}
UClass* Z_Construct_UClass_UCharacterDataAssetFactory()
{
	if (!Z_Registration_Info_UClass_UCharacterDataAssetFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterDataAssetFactory.OuterSingleton, Z_Construct_UClass_UCharacterDataAssetFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharacterDataAssetFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCharacterDataAssetFactory);
UCharacterDataAssetFactory::~UCharacterDataAssetFactory() {}
// ********** End Class UCharacterDataAssetFactory *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlusEditor_Public_CharacterDataAssetFactory_h__Script_Paper2DPlusEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterDataAssetFactory, UCharacterDataAssetFactory::StaticClass, TEXT("UCharacterDataAssetFactory"), &Z_Registration_Info_UClass_UCharacterDataAssetFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterDataAssetFactory), 2452830751U) },
	};
}; // Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlusEditor_Public_CharacterDataAssetFactory_h__Script_Paper2DPlusEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlusEditor_Public_CharacterDataAssetFactory_h__Script_Paper2DPlusEditor_1418261655{
	TEXT("/Script/Paper2DPlusEditor"),
	Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlusEditor_Public_CharacterDataAssetFactory_h__Script_Paper2DPlusEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LostFromLight_Plugins_Paper2DPlus_Source_Paper2DPlusEditor_Public_CharacterDataAssetFactory_h__Script_Paper2DPlusEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
