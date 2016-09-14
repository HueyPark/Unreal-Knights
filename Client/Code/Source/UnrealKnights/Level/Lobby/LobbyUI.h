#pragma once

#include "Blueprint/UserWidget.h"
#include "LobbyUI.generated.h"

UCLASS()
class UNREALKNIGHTS_API ULobbyUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "LobbyUI")
	void OnStart();

private:
	void _Login(const int64& InUserID, const FString& InPassword);
	void _OpenLevelBattle();
};
