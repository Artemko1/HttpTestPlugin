// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpTestPlugin/Public/HttpRickyMortyUserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2DDynamic.h"

#define SET_TEXT_FROM_STRING(TextField, Str) TextField->SetText(FText::FromString(Str));

void UHttpRickyMortyUserWidget::SetupWidgetText(const FInfoData& InfoData)
{
	SET_TEXT_FROM_STRING(IdTextBlock, FString::FromInt(InfoData.Id))
    SET_TEXT_FROM_STRING(NameTextBlock, InfoData.Name)
    SET_TEXT_FROM_STRING(StatusTextBlock, InfoData.Status)
    SET_TEXT_FROM_STRING(SpeciesTextBlock, InfoData.Species)
    SET_TEXT_FROM_STRING(TypeTextBlock, InfoData.Type)
    SET_TEXT_FROM_STRING(GenderTextBlock, InfoData.Gender)
    SET_TEXT_FROM_STRING(URLTextBlock, InfoData.URL)
    SET_TEXT_FROM_STRING(CreatedTextBlock, InfoData.Created)

	FSlateBrush Brush;
	Brush.SetImageSize(this->ImageSize);
	Brush.SetResourceObject(InfoData.Texture);
	this->DownloadImage->SetBrush(Brush);
}
