// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DIETOGETHER_DieTogetherCharacter_generated_h
#error "DieTogetherCharacter.generated.h already included, missing '#pragma once' in DieTogetherCharacter.h"
#endif
#define DIETOGETHER_DieTogetherCharacter_generated_h

#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_SPARSE_DATA
#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_RPC_WRAPPERS
#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADieTogetherCharacter(); \
	friend struct Z_Construct_UClass_ADieTogetherCharacter_Statics; \
public: \
	DECLARE_CLASS(ADieTogetherCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DieTogether"), NO_API) \
	DECLARE_SERIALIZER(ADieTogetherCharacter)


#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_INCLASS \
private: \
	static void StaticRegisterNativesADieTogetherCharacter(); \
	friend struct Z_Construct_UClass_ADieTogetherCharacter_Statics; \
public: \
	DECLARE_CLASS(ADieTogetherCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DieTogether"), NO_API) \
	DECLARE_SERIALIZER(ADieTogetherCharacter)


#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADieTogetherCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADieTogetherCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADieTogetherCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADieTogetherCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADieTogetherCharacter(ADieTogetherCharacter&&); \
	NO_API ADieTogetherCharacter(const ADieTogetherCharacter&); \
public:


#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADieTogetherCharacter(ADieTogetherCharacter&&); \
	NO_API ADieTogetherCharacter(const ADieTogetherCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADieTogetherCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADieTogetherCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADieTogetherCharacter)


#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(ADieTogetherCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ADieTogetherCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__RunningAnimation() { return STRUCT_OFFSET(ADieTogetherCharacter, RunningAnimation); } \
	FORCEINLINE static uint32 __PPO__IdleAnimation() { return STRUCT_OFFSET(ADieTogetherCharacter, IdleAnimation); }


#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_19_PROLOG
#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_SPARSE_DATA \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_RPC_WRAPPERS \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_INCLASS \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_SPARSE_DATA \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_INCLASS_NO_PURE_DECLS \
	DieTogether_Source_DieTogether_DieTogetherCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DIETOGETHER_API UClass* StaticClass<class ADieTogetherCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DieTogether_Source_DieTogether_DieTogetherCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
