// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DieTogetherGameMode.h"
#include "DieTogetherCharacter.h"

ADieTogetherGameMode::ADieTogetherGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ADieTogetherCharacter::StaticClass();	
}
