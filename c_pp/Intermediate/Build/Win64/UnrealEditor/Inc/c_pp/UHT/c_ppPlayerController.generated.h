// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "c_ppPlayerController.h"

#ifdef C_PP_c_ppPlayerController_generated_h
#error "c_ppPlayerController.generated.h already included, missing '#pragma once' in c_ppPlayerController.h"
#endif
#define C_PP_c_ppPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class Ac_ppPlayerController ****************************************************
C_PP_API UClass* Z_Construct_UClass_Ac_ppPlayerController_NoRegister();

#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAc_ppPlayerController(); \
	friend struct Z_Construct_UClass_Ac_ppPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend C_PP_API UClass* Z_Construct_UClass_Ac_ppPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(Ac_ppPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/c_pp"), Z_Construct_UClass_Ac_ppPlayerController_NoRegister) \
	DECLARE_SERIALIZER(Ac_ppPlayerController)


#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API Ac_ppPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	Ac_ppPlayerController(Ac_ppPlayerController&&) = delete; \
	Ac_ppPlayerController(const Ac_ppPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Ac_ppPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Ac_ppPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(Ac_ppPlayerController) \
	NO_API virtual ~Ac_ppPlayerController();


#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h_16_PROLOG
#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class Ac_ppPlayerController;

// ********** End Class Ac_ppPlayerController ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_gitt_c_pp_c_pp_Source_c_pp_c_ppPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
