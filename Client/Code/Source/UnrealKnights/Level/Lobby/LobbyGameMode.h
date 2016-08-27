#pragma once

#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

UCLASS()
class UNREALKNIGHTS_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	TSubclassOf<class ULobbyUI> CLASS_LobbyUI;

public:
	ALobbyGameMode();

	virtual void StartPlay() override;
};
