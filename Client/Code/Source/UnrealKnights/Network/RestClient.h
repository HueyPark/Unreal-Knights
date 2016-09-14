// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include <functional>
#include "Network/Json/json.hpp"
#include "RestClient.generated.h"

UCLASS()
class UNREALKNIGHTS_API URestClient : public UObject
{
	GENERATED_BODY()

private:
	FString JWT;

public:
	static URestClient* GetInstance();

	void SetJWT(const FString& InJWT);

	void Get(const FString& InUrl, std::function<void(const json&)> InCallback = nullptr);
	void Post(const FString& InUrl, const json& InData, std::function<void(const json&)> InCallback = nullptr);
	void Put(const FString& InUrl, const json& InData, std::function<void(const json&)> InCallback = nullptr);
	void Delete(const FString& InUrl, std::function<void(const json&)> InCallback = nullptr);

private:
	void Request(const FString& InUrl, const FString& InVerb, const json& InData, std::function<void(const json&)> InCallback);
};
