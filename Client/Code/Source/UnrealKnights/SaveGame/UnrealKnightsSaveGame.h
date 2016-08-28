#pragma once

#include "GameFramework/SaveGame.h"
#include "UnrealKnightsSaveGame.generated.h"

UCLASS()
class UNREALKNIGHTS_API UUnrealKnightsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsUserCreated;

	UPROPERTY()
	uint64 UserID;

public:
	UUnrealKnightsSaveGame();

	static UUnrealKnightsSaveGame* Load();
	static void Save(UUnrealKnightsSaveGame* SaveGame);
};
