/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, October 2022
 */


#pragma once

#define CURRENT_CLASS								(FString(__FUNCTION__).Left(FString(__FUNCTION__).Find(TEXT(":"))) )
#define CURRENT_CLASS_FUNCTION							(FString(__FUNCTION__))
#define CURRENT_FUNCTION							(FString(__FUNCTION__).Right(FString(__FUNCTION__).Len() - FString(__FUNCTION__).Find(TEXT("::"))))
#define CURRENT_LINE_NUMBER							(FString::FromInt(__LINE__))
#define CURRENT_CLASS_WITH_LINE							("(" + CURRENT_LINE_NUMBER + ") " + CURRENT_CLASS)
#define CURRENT_FUNCTION_SIGNATURE						(FString(__FUNCSIG__))

#define NETMODE_WORLD (((GEngine == nullptr) || (GetWorld() == nullptr)) ? TEXT("[UNKNOWN_NETMODE] ") \
		: (GEngine->GetNetMode(GetWorld()) == NM_Client) ? TEXT("[Client] ") \
		: (GEngine->GetNetMode(GetWorld()) == NM_ListenServer) ? TEXT("[ListenServer] ") \
		: (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer) ? TEXT("[DedicatedServer] ") \
		: TEXT("[Standalone] "))

#define DEFINE_LOG(LogCategory)							DEFINE_LOG_CATEGORY_STATIC(LogCategory, All, All)

DEFINE_LOG(LogRestful)

#define CREATE_RESTFUL_LOG_NORMAL(LogCategory, Param1)	   		UE_LOG(LogCategory, Log, TEXT("[%s::%s] %s"), *CURRENT_CLASS, *CURRENT_FUNCTION, *FString(Param1))
#define CREATE_RESTFUL_LOG_VERBOSE(LogCategory, Param1)	   	UE_LOG(LogCategory, Verbose, TEXT("[%s::%s] %s"), *CURRENT_CLASS, *CURRENT_FUNCTION, *FString(Param1))
#define CREATE_RESTFUL_LOG_VERYVERBOSE(LogCategory, Param1)	UE_LOG(LogCategory, VeryVerbose, TEXT("[%s::%s] %s"), *CURRENT_CLASS, *CURRENT_FUNCTION, *FString(Param1))
#define CREATE_RESTFUL_LOG_WARNING(LogCategory, Param1)   		UE_LOG(LogCategory, Warning, TEXT("[%s::%s] %s"), *CURRENT_CLASS, *CURRENT_FUNCTION, *FString(Param1))
#define CREATE_RESTFUL_LOG_ERROR(LogCategory, Param1)	   		UE_LOG(LogCategory, Error, TEXT("[%s::%s] %s"), *CURRENT_CLASS, *CURRENT_FUNCTION, *FString(Param1))

#define LOG_RESTFUL_NORMAL(Param1)	   							CREATE_RESTFUL_LOG_NORMAL(LogRESTFUL, Param1)
#define LOG_RESTFUL_VERBOSE(Param1)	   						CREATE_RESTFUL_LOG_VERBOSE(LogRESTFUL, Param1)
#define LOG_RESTFUL_VERYVERBOSE(Param1)						CREATE_RESTFUL_LOG_VERYVERBOSE(LogRESTFUL, Param1)
#define LOG_RESTFUL_WARNING(Param1)	   						CREATE_RESTFUL_LOG_WARNING(LogRESTFUL, Param1)
#define LOG_RESTFUL_ERROR(Param1)	   							CREATE_RESTFUL_LOG_ERROR(LogRESTFUL, Param1)