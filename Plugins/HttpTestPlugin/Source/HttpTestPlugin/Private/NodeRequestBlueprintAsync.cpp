// Fill out your copyright notice in the Description page of Project Settings.

#include "NodeRequestBlueprintAsync.h"
#include "HttpModule.h"
#include "Blueprint/AsyncTaskDownloadImage.h"
#include "Interfaces/IHttpResponse.h"

DEFINE_LOG_CATEGORY_STATIC(LogNodeRequestBlueprintAsync, All, All);

namespace
{
FString makeURL()
{
	const int32 RandomValue = FMath::RandRange(1, 826);
	return FString("https://rickandmortyapi.com/api/character/").Append(FString::FromInt(RandomValue));
}
}  // namespace

UNodeRequestBlueprintAsync* UNodeRequestBlueprintAsync::RequestRickyMorty()
{
	UNodeRequestBlueprintAsync* NodeTask = NewObject<UNodeRequestBlueprintAsync>();
	NodeTask->Start();
	return NodeTask;
}

void UNodeRequestBlueprintAsync::Start()
{
	UE_LOG(LogNodeRequestBlueprintAsync, Display, TEXT("Request data"));
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UNodeRequestBlueprintAsync::HandleRequest);

	// Reset Data
	InfoData.Reset();

	// This is the url on which to process the request
	Request->SetURL(makeURL());
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UNodeRequestBlueprintAsync::HandleRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	UE_LOG(LogNodeRequestBlueprintAsync, Display, TEXT("Request URL: %s | Status request: %i"), *HttpRequest->GetURL(), bSucceeded);

	// Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;
	// Create a reader pointer to read the json data
	const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(HttpResponse->GetContentAsString());

	// Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		// Get the value of the json object by field id and name
		InfoData.Parse(JsonObject);

		UAsyncTaskDownloadImage* DownloadTask = NewObject<UAsyncTaskDownloadImage>();
		DownloadTask->OnSuccess.AddDynamic(this, &UNodeRequestBlueprintAsync::DownloadSuccess);
		DownloadTask->OnFail.AddDynamic(this, &UNodeRequestBlueprintAsync::DownloadFail);
		DownloadTask->Start(InfoData.Image);
	}
	else
	{
		OnFail.Broadcast(InfoData);
	}
}

void UNodeRequestBlueprintAsync::DownloadSuccess(UTexture2DDynamic* Texture)
{
	UE_LOG(LogNodeRequestBlueprintAsync, Display, TEXT("Image download Success"));
	InfoData.Texture = Texture;
	OnSuccess.Broadcast(InfoData);
}

void UNodeRequestBlueprintAsync::DownloadFail(UTexture2DDynamic* Texture)
{
	UE_LOG(LogNodeRequestBlueprintAsync, Error, TEXT("Image download Fail"));
	InfoData.Texture = Texture;
	OnFail.Broadcast(this->InfoData);
}
