// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealKnights.h"
#include "UserUI.h"

void UUserUI::OnHitButton()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hit!"));
}
