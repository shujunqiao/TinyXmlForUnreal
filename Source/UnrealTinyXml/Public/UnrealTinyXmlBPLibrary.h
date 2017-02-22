// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "tinyxml2.h"
#include "UnrealTinyXmlBPLibrary.generated.h"
using namespace tinyxml2;
/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UUnrealTinyXmlBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "UnrealTinyXml sample test testing"), Category = "UnrealTinyXmlTesting")
	static float UnrealTinyXmlSampleFunction(float Param);

	UFUNCTION(BlueprintCallable,Category = "luochuanyuewu|TinyXml")
		static int TestXML(const FString& file);


	/**
	* Parses XML file and returns the root node, returns NULL if it can't be parsed.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml", Meta = (DisplayName = "Parse Xml From File"))
		static UUnrealTinyXmlNode* ParseXmlFile(const FString& File);
};
