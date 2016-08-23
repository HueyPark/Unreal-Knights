// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UserUI.generated.h"

UCLASS()
class UNREALKNIGHTS_API UUserUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "UserUI")
	void OnHitButton();
};
