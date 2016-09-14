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
		URestClient::GetInstance()->Post("/signup", "", [this, SaveGame](const json& InData)
		{
			int32 ID = InData[ "id" ];
			std::string Password = InData[ "password" ];

			SaveGame->bIsUserCreated = true;
			SaveGame->UserID = ID;
			SaveGame->Password = FString(Password.c_str());

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
