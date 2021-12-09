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
	FString Image;
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
		Image.Empty();
		Texture = nullptr;
	}

#define TO_JSON_ID(param) FString(#param).ToLower()

	void Parse(TSharedPtr<FJsonObject> JsonObject)
	{
		Id = JsonObject->GetIntegerField(TO_JSON_ID(Id));
		Name = JsonObject->GetStringField(TO_JSON_ID(Name));
		Status = JsonObject->GetStringField(TO_JSON_ID(Status));
		Species = JsonObject->GetStringField(TO_JSON_ID(Species));
		Type = JsonObject->GetStringField(TO_JSON_ID(Type));
		Gender = JsonObject->GetStringField(TO_JSON_ID(Gender));
		URL = JsonObject->GetStringField(TO_JSON_ID(URL));
		Created = JsonObject->GetStringField(TO_JSON_ID(Created));
		Image = JsonObject->GetStringField(TO_JSON_ID(Image));
	}
};