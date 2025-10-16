// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodec_pp_init() {}
	C_PP_API UFunction* Z_Construct_UDelegateFunction_c_pp_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_c_pp;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_c_pp()
	{
		if (!Z_Registration_Info_UPackage__Script_c_pp.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_c_pp_OnEnemyDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/c_pp",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xE33E7562,
				0xF5E94377,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_c_pp.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_c_pp.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_c_pp(Z_Construct_UPackage__Script_c_pp, TEXT("/Script/c_pp"), Z_Registration_Info_UPackage__Script_c_pp, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE33E7562, 0xF5E94377));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
