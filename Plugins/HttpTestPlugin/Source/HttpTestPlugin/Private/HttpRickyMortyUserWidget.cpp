// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpTestPlugin/Public/HttpRickyMortyUserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2DDynamic.h"

#define SET_TEXT_FROM_STRING(TextField, Str) TextField->SetText(FText::FromString(Str));

void UHttpRickyMortyUserWidget::SetupWidgetText(const FInfoData& InfoData)
{
	SET_TEXT_FROM_STRING(IdTextBlock, FString::FromInt(InfoData.RecievedId))
    SET_TEXT_FROM_STRING(NameTextBlock, InfoData.ReceivedName)
    SET_TEXT_FROM_STRING(StatusTextBlock, InfoData.ReceivedStatus)
    SET_TEXT_FROM_STRING(SpeciesTextBlock, InfoData.ReceivedSpecies)
    SET_TEXT_FROM_STRING(TypeTextBlock, InfoData.ReceivedType)
    SET_TEXT_FROM_STRING(GenderTextBlock, InfoData.ReceivedGender)
    SET_TEXT_FROM_STRING(URLTextBlock, InfoData.ReceivedURL)
    SET_TEXT_FROM_STRING(CreatedTextBlock, InfoData.ReceivedCreated)

	FSlateBrush Brush;
	Brush.SetImageSize(this->ImageSize);
	Brush.SetResourceObject(InfoData.Texture);
	this->DownloadImage->SetBrush(Brush);
}
