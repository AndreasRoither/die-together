// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DieTogether/DieTogetherGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDieTogetherGameMode() {}
// Cross Module References
	DIETOGETHER_API UClass* Z_Construct_UClass_ADieTogetherGameMode_NoRegister();
	DIETOGETHER_API UClass* Z_Construct_UClass_ADieTogetherGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_DieTogether();
// End Cross Module References
	void ADieTogetherGameMode::StaticRegisterNativesADieTogetherGameMode()
	{
	}
	UClass* Z_Construct_UClass_ADieTogetherGameMode_NoRegister()
	{
		return ADieTogetherGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ADieTogetherGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADieTogetherGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_DieTogether,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADieTogetherGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The GameMode defines the game being played. It governs the game rules, scoring, what actors\n * are allowed to exist in this game type, and who may enter the game.\n *\n * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of DieTogetherCharacter\n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "DieTogetherGameMode.h" },
		{ "ModuleRelativePath", "DieTogetherGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "The GameMode defines the game being played. It governs the game rules, scoring, what actors\nare allowed to exist in this game type, and who may enter the game.\n\nThis game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of DieTogetherCharacter" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADieTogetherGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADieTogetherGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADieTogetherGameMode_Statics::ClassParams = {
		&ADieTogetherGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ADieTogetherGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADieTogetherGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADieTogetherGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADieTogetherGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADieTogetherGameMode, 3716457576);
	template<> DIETOGETHER_API UClass* StaticClass<ADieTogetherGameMode>()
	{
		return ADieTogetherGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADieTogetherGameMode(Z_Construct_UClass_ADieTogetherGameMode, &ADieTogetherGameMode::StaticClass, TEXT("/Script/DieTogether"), TEXT("ADieTogetherGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADieTogetherGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
