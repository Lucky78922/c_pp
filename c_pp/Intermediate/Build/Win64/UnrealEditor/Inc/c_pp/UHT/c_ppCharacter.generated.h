// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "c_ppCharacter.h"

#ifdef C_PP_c_ppCharacter_generated_h
#error "c_ppCharacter.generated.h already included, missing '#pragma once' in c_ppCharacter.h"
#endif
#define C_PP_c_ppCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class Ac_ppCharacter ***********************************************************
#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


C_PP_API UClass* Z_Construct_UClass_Ac_ppCharacter_NoRegister();

#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAc_ppCharacter(); \
	friend struct Z_Construct_UClass_Ac_ppCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend C_PP_API UClass* Z_Construct_UClass_Ac_ppCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(Ac_ppCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/c_pp"), Z_Construct_UClass_Ac_ppCharacter_NoRegister) \
	DECLARE_SERIALIZER(Ac_ppCharacter)


#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	Ac_ppCharacter(Ac_ppCharacter&&) = delete; \
	Ac_ppCharacter(const Ac_ppCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Ac_ppCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Ac_ppCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(Ac_ppCharacter) \
	NO_API virtual ~Ac_ppCharacter();


#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_21_PROLOG
#define FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class Ac_ppCharacter;

// ********** End Class Ac_ppCharacter *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_gitt_c_pp_c_pp_Source_c_pp_c_ppCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
