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
	FString Password;

public:
	UUnrealKnightsSaveGame();

	void Save();
	static UUnrealKnightsSaveGame* Load();
};
