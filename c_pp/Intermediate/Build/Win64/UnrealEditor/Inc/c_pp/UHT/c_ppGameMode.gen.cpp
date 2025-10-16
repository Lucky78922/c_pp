// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "c_ppGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodec_ppGameMode() {}

// ********** Begin Cross Module References ********************************************************
C_PP_API UClass* Z_Construct_UClass_Ac_ppGameMode();
C_PP_API UClass* Z_Construct_UClass_Ac_ppGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_c_pp();
// ********** End Cross Module References **********************************************************

// ********** Begin Class Ac_ppGameMode ************************************************************
void Ac_ppGameMode::StaticRegisterNativesAc_ppGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_Ac_ppGameMode;
UClass* Ac_ppGameMode::GetPrivateStaticClass()
{
	using TClass = Ac_ppGameMode;
	if (!Z_Registration_Info_UClass_Ac_ppGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("c_ppGameMode"),
			Z_Registration_Info_UClass_Ac_ppGameMode.InnerSingleton,
			StaticRegisterNativesAc_ppGameMode,
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
	return Z_Registration_Info_UClass_Ac_ppGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_Ac_ppGameMode_NoRegister()
{
	return Ac_ppGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_Ac_ppGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "c_ppGameMode.h" },
		{ "ModuleRelativePath", "c_ppGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Ac_ppGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_Ac_ppGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_c_pp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Ac_ppGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_Ac_ppGameMode_Statics::ClassParams = {
	&Ac_ppGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Ac_ppGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_Ac_ppGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_Ac_ppGameMode()
{
	if (!Z_Registration_Info_UClass_Ac_ppGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Ac_ppGameMode.OuterSingleton, Z_Construct_UClass_Ac_ppGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_Ac_ppGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(Ac_ppGameMode);
Ac_ppGameMode::~Ac_ppGameMode() {}
// ********** End Class Ac_ppGameMode **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_gitt_c_pp_c_pp_Source_c_pp_c_ppGameMode_h__Script_c_pp_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_Ac_ppGameMode, Ac_ppGameMode::StaticClass, TEXT("Ac_ppGameMode"), &Z_Registration_Info_UClass_Ac_ppGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Ac_ppGameMode), 3619516198U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_gitt_c_pp_c_pp_Source_c_pp_c_ppGameMode_h__Script_c_pp_1025024585(TEXT("/Script/c_pp"),
	Z_CompiledInDeferFile_FID_gitt_c_pp_c_pp_Source_c_pp_c_ppGameMode_h__Script_c_pp_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_gitt_c_pp_c_pp_Source_c_pp_c_ppGameMode_h__Script_c_pp_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
