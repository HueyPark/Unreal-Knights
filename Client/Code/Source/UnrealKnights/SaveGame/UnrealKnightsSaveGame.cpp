#include "UnrealKnights.h"
#include "UnrealKnightsSaveGame.h"

#include "Kismet/GameplayStatics.h"

const FString SLOT_NAME = "UnrealKnightSlot";
const int32 USER_INDEX = 0;

UUnrealKnightsSaveGame::UUnrealKnightsSaveGame()
{
	bIsUserCreated = false;
	UserID = 0;
}

void UUnrealKnightsSaveGame::Save()
{
	UGameplayStatics::SaveGameToSlot(this, SLOT_NAME, USER_INDEX);
}


UUnrealKnightsSaveGame* UUnrealKnightsSaveGame::Load()
{
	UUnrealKnightsSaveGame* SaveGame = Cast<UUnrealKnightsSaveGame>(UGameplayStatics::LoadGameFromSlot(SLOT_NAME, USER_INDEX));
	if (SaveGame == nullptr)
	{
		SaveGame = Cast<UUnrealKnightsSaveGame>(UGameplayStatics::CreateSaveGameObject(UUnrealKnightsSaveGame::StaticClass()));
	}

	return SaveGame;
}
