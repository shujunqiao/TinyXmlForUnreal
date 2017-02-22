// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UnrealTinyXmlPrivatePCH.h"
#define LOCTEXT_NAMESPACE "FUnrealTinyXmlModule"

void FUnrealTinyXmlModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FUnrealTinyXmlModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealTinyXmlModule, UnrealTinyXml)