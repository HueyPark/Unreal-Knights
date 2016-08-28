#include "UnrealKnights.h"
#include "LobbyUI.h"
#include "SaveGame/UnrealKnightsSaveGame.h"

void ULobbyUI::OnStart()
{
	UUnrealKnightsSaveGame* SaveGame = UUnrealKnightsSaveGame::Load();
	SaveGame->UserID++;
	UUnrealKnightsSaveGame::Save(SaveGame);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("User ID: %d"), SaveGame->UserID));
}
