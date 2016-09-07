#include "UnrealKnights.h"
#include "LobbyUI.h"

#include "Network/RestClient.h"
#include "Network/Json/json.hpp"
#include "SaveGame/UnrealKnightsSaveGame.h"

void ULobbyUI::OnStart()
{
	UUnrealKnightsSaveGame* SaveGame = UUnrealKnightsSaveGame::Load();

	if (SaveGame->bIsUserCreated == false)
	{
		URestClient::GetInstance()->Post("/users", "", [this, SaveGame](const json& InData)
		{
			int32 ID = InData[ "id" ];

			SaveGame->bIsUserCreated = true;
			SaveGame->UserID = ID;

			SaveGame->Save();

			this->_OpenLevelBattle();
		});
	}
	else
	{
		_OpenLevelBattle();
	}
}

void ULobbyUI::_OpenLevelBattle()
{
	UGameplayStatics::OpenLevel(this, "/Game/Level/Battle/L_Battle");
}
