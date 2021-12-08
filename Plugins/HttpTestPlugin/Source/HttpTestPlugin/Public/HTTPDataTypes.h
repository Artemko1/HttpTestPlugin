#pragma once

#include "HTTPDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FInfoData
{
	GENERATED_BODY();

	int32 RecievedId;
	FString ReceivedName;
	FString ReceivedStatus;
	FString ReceivedSpecies;
	FString ReceivedType;
	FString ReceivedGender;
	FString ReceivedURL;
	FString ReceivedCreated;
	FString ImageURL;
	UPROPERTY()
	UTexture2DDynamic* Texture;

	void Reset()
	{
		RecievedId = 0;
		ReceivedName.Empty();
		ReceivedStatus.Empty();
		ReceivedSpecies.Empty();
		ReceivedType.Empty();
		ReceivedGender.Empty();
		ReceivedURL.Empty();
		ReceivedCreated.Empty();
		ImageURL.Empty();
		Texture = nullptr;
	}

	void Parse(TSharedPtr<FJsonObject> JsonObject)
	{
		RecievedId = JsonObject->GetIntegerField("id");
		ReceivedName = JsonObject->GetStringField("name");
		ReceivedStatus = JsonObject->GetStringField("status");
		ReceivedSpecies = JsonObject->GetStringField("species");
		ReceivedType = JsonObject->GetStringField("type");
		ReceivedGender = JsonObject->GetStringField("gender");
		ReceivedURL = JsonObject->GetStringField("url");
		ReceivedCreated = JsonObject->GetStringField("created");
		ImageURL = JsonObject->GetStringField("image");
	}
};