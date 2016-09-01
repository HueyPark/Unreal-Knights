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
		URestClient::GetInstance()->Post("/users", "", [this, SaveGame](const FString& Response)
		{
			const int temp = 5;

			std::string JsonString(TCHAR_TO_UTF8(*Response));
			json Json = json::parse(JsonString);

			int32 ID = Json[ "id" ];

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
