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

	FInfoData() {}
	FInfoData(int32 NewRecievedId, const FString& NewReceivedName, const FString& NewReceivedStatus, const FString& NewReceivedSpecies,
		const FString NewReceivedType, const FString& NewReceivedGender, const FString& NewReceivedURL, const FString& NewReceivedCreated,
		UTexture2DDynamic* NewTexture)
	{
		this->RecievedId = NewRecievedId;
		this->ReceivedName = NewReceivedName;
		this->ReceivedStatus = NewReceivedStatus;
		this->ReceivedSpecies = NewReceivedSpecies;
		this->ReceivedType = NewReceivedType;
		this->ReceivedGender = NewReceivedGender;
		this->ReceivedURL = NewReceivedURL;
		this->ReceivedCreated = NewReceivedCreated;
		this->Texture = NewTexture;
	}

	FInfoData(const FInfoData& Other) { *this = Other; }

	void operator=(const FInfoData& Other)
	{
		this->RecievedId = Other.RecievedId;
		this->ReceivedName = Other.ReceivedName;
		this->ReceivedStatus = Other.ReceivedStatus;
		this->ReceivedSpecies = Other.ReceivedSpecies;
		this->ReceivedType = Other.ReceivedType;
		this->ReceivedGender = Other.ReceivedGender;
		this->ReceivedURL = Other.ReceivedURL;
		this->ReceivedCreated = Other.ReceivedCreated;
		this->Texture = Other.Texture;
	}

	void Reset()
	{
		RecievedId = 0;
		ReceivedName = "";
		ReceivedStatus = "";
		ReceivedSpecies = "";
		ReceivedType = "";
		ReceivedGender = "";
		ReceivedURL = "";
		ReceivedCreated = "";
        ImageURL = "";
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