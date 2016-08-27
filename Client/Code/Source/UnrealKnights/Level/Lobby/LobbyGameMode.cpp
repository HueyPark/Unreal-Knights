#include "UnrealKnights.h"
#include "LobbyGameMode.h"
#include "Level/Lobby/LobbyUI.h"

ALobbyGameMode::ALobbyGameMode()
{
	static ConstructorHelpers::FClassFinder<ULobbyUI> LobbyUIBPCLass(TEXT("/Game/Level/Lobby/WB_LobbyUI"));
	if (LobbyUIBPCLass.Class != nullptr)
	{
		CLASS_LobbyUI = LobbyUIBPCLass.Class;
	}
}

void ALobbyGameMode::StartPlay()
{
	Super::StartPlay();

	if (CLASS_LobbyUI != nullptr)
	{
		ULobbyUI* LobbyUI = CreateWidget<ULobbyUI>(GetWorld(), CLASS_LobbyUI);
		LobbyUI->AddToViewport();
	}
}
