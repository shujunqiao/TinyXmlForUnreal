// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UnrealTinyXmlPrivatePCH.h"
#include "UnrealTinyXmlBPLibrary.h"

UUnrealTinyXmlBPLibrary::UUnrealTinyXmlBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}
UUnrealTinyXmlDocument* UUnrealTinyXmlBPLibrary::NewXmlDocument()
{
	//´´½¨Node
	UUnrealTinyXmlDocument* Instance = NewObject<UUnrealTinyXmlDocument>();
	Instance->XmlFilePtr = new tinyxml2::XMLDocument();;
	return Instance;
}

