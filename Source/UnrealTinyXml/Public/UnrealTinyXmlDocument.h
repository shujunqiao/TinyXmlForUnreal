// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreUObject.h"
#include "tinyxml2.h"
#include "UnrealTinyXmlDocument.generated.h"
using namespace tinyxml2;

/**
 * 
 */
UCLASS(BlueprintType)
class UNREALTINYXML_API UUnrealTinyXmlDocument : public UObject
{
	GENERATED_BODY()
	
	
public:
	XMLDocument* XmlFilePtr; // 指向Xml文档对象的指针

	/**
	* Load xml file from disk, return ture if load successful, or it will be false.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		bool LoadXmlFie(const FString& File);

	/**
	* Get the root node of current loaded xml file, returns NULL if it can't be parsed.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		UUnrealTinyXmlNode* GetRootNode();

	/**
	* Clear the document that has this node, resetting it to the initial state(All nodes of this document will become null!).
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		void Clear();

};
