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
		URestClient::GetInstance()->Post(
			"/signup",
			json(),
			[this, SaveGame](const json& InData)
			{
				int64 ID = InData["id"];
				std::string Password = InData["password"];

				SaveGame->bIsUserCreated = true;
				SaveGame->UserID = ID;
				SaveGame->Password = FString(Password.c_str());

				SaveGame->Save();

				this->_Login(SaveGame->UserID, SaveGame->Password);
			});
	}
	else
	{
		_Login(SaveGame->UserID, SaveGame->Password);
	}
}

void ULobbyUI::_Login(const int64& InUserID, const FString& InPassword)
{
	json Json;
	Json["id"] = InUserID;
	Json["password"] = TCHAR_TO_UTF8(*InPassword);

	URestClient::GetInstance()->Post(
		"/login",
		Json,
		[this](const json& InData)
		{
			std::string jwt = InData["jwt"];

			URestClient::GetInstance()->SetJWT(FString(jwt.c_str()));

			this->_OpenLevelBattle();
		});
}

void ULobbyUI::_OpenLevelBattle()
{
	UGameplayStatics::OpenLevel(this, "/Game/Level/Battle/L_Battle");
}
