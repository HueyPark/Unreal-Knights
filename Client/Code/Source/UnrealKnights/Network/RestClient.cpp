// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealKnights.h"
#include "RestClient.h"

#include "Http.h"
#include "Network/Json/json.hpp"

const FString DOMAIN_NAME = "127.0.0.1:5000";

URestClient* URestClient::GetInstance()
{
	static URestClient* Instance = NewObject<URestClient>(URestClient::StaticClass());

	return Instance;
}

void URestClient::SetJWT(const FString& InJWT)
{
	JWT = InJWT;
}

void URestClient::Get(const FString& InUrl, std::function<void(const json&)> InCallback /*= nullptr*/)
{
	this->Request(InUrl, TEXT("GET"), "", InCallback);
}

void URestClient::Post(const FString& InUrl, const json& InData, std::function<void(const json&)> InCallback /*= nullptr*/)
{
	this->Request(InUrl, TEXT("POST"), InData, InCallback);
}

void URestClient::Put(const FString& InUrl, const json& InData, std::function<void(const json&)> InCallback /*= nullptr*/)
{
	this->Request(InUrl, TEXT("PUT"), InData, InCallback);
}

void URestClient::Delete(const FString & InUrl, std::function<void(const json&)> InCallback /*= nullptr*/)
{
	this->Request(InUrl, TEXT("DELETE"), "", InCallback);
}

void URestClient::Request(const FString& InUrl, const FString& InVerb, const json& InData, std::function<void(const json&)> InCallback)
{
	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();

	httpRequest->SetURL(DOMAIN_NAME + InUrl);

	httpRequest->SetHeader("Content-Type", TEXT("application/json"));
	httpRequest->SetHeader("JWT", JWT);

	httpRequest->SetVerb(InVerb);

	httpRequest->SetContentAsString(FString(InData.dump().c_str()));

	httpRequest->ProcessRequest();

	httpRequest->OnProcessRequestComplete().BindLambda([InCallback](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
	{
		if (bWasSuccessful == true)
		{
			if (InCallback != nullptr)
			{
				std::string JsonString(TCHAR_TO_UTF8(*(Response->GetContentAsString())));
				json Json = json::parse(JsonString);

				InCallback(Json);
			}
		}
	});
}
