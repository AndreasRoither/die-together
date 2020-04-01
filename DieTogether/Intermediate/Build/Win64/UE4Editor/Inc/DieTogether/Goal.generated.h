// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef DIETOGETHER_Goal_generated_h
#error "Goal.generated.h already included, missing '#pragma once' in Goal.h"
#endif
#define DIETOGETHER_Goal_generated_h

#define DieTogether_Source_DieTogether_world_Goal_h_12_SPARSE_DATA
#define DieTogether_Source_DieTogether_world_Goal_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetStatusText) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetStatusText(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define DieTogether_Source_DieTogether_world_Goal_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetStatusText) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetStatusText(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define DieTogether_Source_DieTogether_world_Goal_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGoal(); \
	friend struct Z_Construct_UClass_AGoal_Statics; \
public: \
	DECLARE_CLASS(AGoal, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DieTogether"), NO_API) \
	DECLARE_SERIALIZER(AGoal)


#define DieTogether_Source_DieTogether_world_Goal_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGoal(); \
	friend struct Z_Construct_UClass_AGoal_Statics; \
public: \
	DECLARE_CLASS(AGoal, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DieTogether"), NO_API) \
	DECLARE_SERIALIZER(AGoal)


#define DieTogether_Source_DieTogether_world_Goal_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGoal(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGoal) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGoal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGoal); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGoal(AGoal&&); \
	NO_API AGoal(const AGoal&); \
public:


#define DieTogether_Source_DieTogether_world_Goal_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGoal(AGoal&&); \
	NO_API AGoal(const AGoal&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGoal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGoal); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGoal)


#define DieTogether_Source_DieTogether_world_Goal_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CapsuleComponent() { return STRUCT_OFFSET(AGoal, CapsuleComponent); } \
	FORCEINLINE static uint32 __PPO__StatusText() { return STRUCT_OFFSET(AGoal, StatusText); }


#define DieTogether_Source_DieTogether_world_Goal_h_9_PROLOG
#define DieTogether_Source_DieTogether_world_Goal_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DieTogether_Source_DieTogether_world_Goal_h_12_PRIVATE_PROPERTY_OFFSET \
	DieTogether_Source_DieTogether_world_Goal_h_12_SPARSE_DATA \
	DieTogether_Source_DieTogether_world_Goal_h_12_RPC_WRAPPERS \
	DieTogether_Source_DieTogether_world_Goal_h_12_INCLASS \
	DieTogether_Source_DieTogether_world_Goal_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DieTogether_Source_DieTogether_world_Goal_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DieTogether_Source_DieTogether_world_Goal_h_12_PRIVATE_PROPERTY_OFFSET \
	DieTogether_Source_DieTogether_world_Goal_h_12_SPARSE_DATA \
	DieTogether_Source_DieTogether_world_Goal_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DieTogether_Source_DieTogether_world_Goal_h_12_INCLASS_NO_PURE_DECLS \
	DieTogether_Source_DieTogether_world_Goal_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DIETOGETHER_API UClass* StaticClass<class AGoal>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DieTogether_Source_DieTogether_world_Goal_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
