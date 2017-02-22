// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "Engine.h"
#include "CoreUObject.h"
#include "tinyxml2.h"
#include "UnrealTinyXmlNode.generated.h"

using namespace tinyxml2;
/**
 * 
 */
UCLASS(BlueprintType)
class UNREALTINYXML_API UUnrealTinyXmlNode : public UObject
{
	GENERATED_BODY()
public:
	TSharedPtr<XMLDocument> XmlFile; // keeps everything in memory
	const XMLNode* Node = NULL;

public:
	bool IsValid();

	static UUnrealTinyXmlNode* Create(TSharedPtr<XMLDocument> XmlFile, XMLNode* Node);
	static UUnrealTinyXmlNode* Create(TSharedPtr<XMLDocument> XmlFile, const XMLNode* Node);
	
	/**
	* Gets next (Step) node in a list of nodes, can return NULL.if exceeded,return last one.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		UUnrealTinyXmlNode* GetNextNode(int Step = 1);
	/**
	* Gets previous (Step) node in a list of nodes, can return NULL.if exceeded,return last one.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		UUnrealTinyXmlNode* GetPreviousNode(int Step = 1);


	/**
	* Gets the next node in a list of nodes, can return NULL.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		UUnrealTinyXmlNode* GetParentNode();



	/**
	* Gets the value of the node.
	*/
	UFUNCTION(BlueprintPure, Category = "luochuanyuewu|TinyXml")
		FString GetValue();

	/**
	* Gets the first child of this node which can be iterated into with GetNextNode, can return NULL.
	*/
	UFUNCTION(BlueprintCallable, Category = "luochuanyuewu|TinyXml")
		UUnrealTinyXmlNode* GetFirstChildNode();

	/**
	* Gets the name of current node, can return NULL.
	*/
	UFUNCTION(BlueprintPure, Category = "luochuanyuewu|TinyXml")
		FString GetNodeName();

	/**
	* Gets the name of current node, can return NULL.
	*/
	UFUNCTION(BlueprintPure, Category = "luochuanyuewu|TinyXml")
		FString GetAttributeValue(const FString& AttributeName);
};
