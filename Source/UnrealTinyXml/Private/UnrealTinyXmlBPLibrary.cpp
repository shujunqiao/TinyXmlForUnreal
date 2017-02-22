// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UnrealTinyXmlPrivatePCH.h"
#include "UnrealTinyXmlBPLibrary.h"

UUnrealTinyXmlBPLibrary::UUnrealTinyXmlBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UUnrealTinyXmlBPLibrary::UnrealTinyXmlSampleFunction(float Param)
{
	return -1;
}

int UUnrealTinyXmlBPLibrary::TestXML(const FString& file)
{
	FString XmlPath = FPaths::GameContentDir() + "XmlConfig/" + file;

	if (!(FPaths::FileExists(XmlPath)))
		return 1;
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();


	doc->LoadFile(TCHAR_TO_UTF8(*XmlPath));

	if (doc->Error())
	{
		UE_LOG(LogTemp, Error, TEXT("Xml文件加载错误,错误描述:%s"), UTF8_TO_TCHAR(doc->ErrorName()));
		return 1;
	}
	tinyxml2::XMLNode* RootElement = doc->RootElement();
	const char* ourchar = RootElement->FirstChild()->ToElement()->Attribute("category");
	TCHAR* text = UTF8_TO_TCHAR(ourchar);
	UE_LOG(LogTemp, Warning, TEXT("%s"),text);
	return 0;
}

UUnrealTinyXmlNode* UUnrealTinyXmlBPLibrary::ParseXmlFile(const FString& File)
{
	//获取Xml文件路径
	FString XmlPath = FPaths::GameContentDir() + "XmlConfig/" + File;

	//检查文件是否存在
	if (!(FPaths::FileExists(XmlPath)))
	{
		UE_LOG(LogTemp, Error, TEXT("要解析的Xml文件不存在，确认路径正确"));
		return nullptr;
	}

	//创建xml文档对象
	tinyxml2::XMLDocument* XmlFilePtr = new tinyxml2::XMLDocument();
	//读取文件
	XmlFilePtr->LoadFile(TCHAR_TO_UTF8(*XmlPath));

	//检测Xml文件解析是否包含错误
	if (XmlFilePtr->Error())
	{
		UE_LOG(LogTemp, Error, TEXT("Xml文件加载错误,错误描述:%s"), UTF8_TO_TCHAR(XmlFilePtr->ErrorName()));
		return nullptr;
	}

	//获取第一个字节点
	tinyxml2::XMLNode* RootNode = XmlFilePtr->RootElement();

	//检查错误
	if (RootNode == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("获取给定Xml文件根结点失败"));
		return nullptr;
	}

	TSharedPtr<XMLDocument> XmlFile = MakeShareable(XmlFilePtr);
	
	return UUnrealTinyXmlNode::Create(XmlFile, RootNode);
}

