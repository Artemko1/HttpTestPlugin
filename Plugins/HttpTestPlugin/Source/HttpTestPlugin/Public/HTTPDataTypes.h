#pragma once

#include "HTTPDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FInfoData
{
	GENERATED_BODY();

	int32 Id;
	FString Name;
	FString Status;
	FString Species;
	FString Type;
	FString Gender;
	FString URL;
	FString Created;
	FString ImageURL;
	UPROPERTY()
	UTexture2DDynamic* Texture;

	void Reset()
	{
		Id = 0;
		Name.Empty();
		Status.Empty();
		Species.Empty();
		Type.Empty();
		Gender.Empty();
		URL.Empty();
		Created.Empty();
		ImageURL.Empty();
		Texture = nullptr;
	}

	void Parse(TSharedPtr<FJsonObject> JsonObject)
	{
		Id = JsonObject->GetIntegerField("id");
		Name = JsonObject->GetStringField("name");
		Status = JsonObject->GetStringField("status");
		Species = JsonObject->GetStringField("species");
		Type = JsonObject->GetStringField("type");
		Gender = JsonObject->GetStringField("gender");
		URL = JsonObject->GetStringField("url");
		Created = JsonObject->GetStringField("created");
		ImageURL = JsonObject->GetStringField("image");
	}
};