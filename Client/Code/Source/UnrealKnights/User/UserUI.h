// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UserUI.generated.h"

class UProgressBar;

UCLASS()
class UNREALKNIGHTS_API UUserUI : public UUserWidget
{
	GENERATED_BODY()

private:
	enum class EPowerState
	{
		Up,
		Down
	};

private:
	EPowerState PowerState;
	float Power;
	UProgressBar* PowerProgressBar;

public:
	virtual void NativeConstruct();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

protected:
	UFUNCTION(BlueprintCallable, Category = "UserUI")
	void OnHitButton();
};
