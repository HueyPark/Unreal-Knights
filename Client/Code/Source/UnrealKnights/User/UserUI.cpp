// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealKnights.h"
#include "UserUI.h"
#include "Blueprint/WidgetTree.h"
#include "Slate/SlateBrushAsset.h"
#include "Components/ProgressBar.h"

float MIN_POWER = 0.0f;
float MAX_POWER = 1.0f;

void UUserUI::NativeConstruct()
{
	PowerState = EPowerState::Up;
	Power = 0.0f;
	PowerProgressBar = WidgetTree->FindWidget<UProgressBar>("PowerProgressBar");
}

void UUserUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (PowerState== EPowerState::Up)
	{
		Power += InDeltaTime;
		if (Power > MAX_POWER)
		{
			Power = MAX_POWER;
			PowerState = EPowerState::Down;
		}
	}
	else
	{
		Power -= InDeltaTime;
		if (Power < MIN_POWER)
		{
			Power = MIN_POWER;
			PowerState = EPowerState::Up;
		}
	}

	PowerProgressBar->SetPercent(Power);
}

void UUserUI::OnHitButton()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit: %f"), Power));
}
