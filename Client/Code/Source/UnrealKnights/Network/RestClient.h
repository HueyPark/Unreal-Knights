// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include <functional>
#include "RestClient.generated.h"

UCLASS()
class UNREALKNIGHTS_API URestClient : public UObject
{
	GENERATED_BODY()

public:
	static URestClient* GetInstance();

	void Get(const FString& InUrl, std::function<void(const FString&)> InCallback = nullptr);
	void Post(const FString& InUrl, const FString& InData, std::function<void(const FString&)> InCallback = nullptr);
	void Put(const FString& InUrl, const FString& InData, std::function<void(const FString&)> InCallback = nullptr);
	void Delete(const FString& InUrl, const FString& InData, std::function<void(const FString&)> InCallback = nullptr);

private:
	void Request(const FString& InUrl, const FString& InVerb, const FString& InData, std::function<void(const FString&)> InCallback);
};
