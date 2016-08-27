// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UnrealKnights.h"
#include "BattleGameMode.h"

ABattleGameMode::ABattleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/User/BP_User"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
