/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, October 2022
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/LatentActionManager.h"
#include "Engine/EngineTypes.h"

#include "RestfulFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RESTFUL_API URestfulFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    /**
     *
    */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Restful Function")
    static void SendRestfulRequest (
        UObject *WorldContextObject,
        bool &success,
        FString url,
        FString verb,
        FString content,
        TMap<FString, FString> headers,
        float timeout,
        int32 &responseCode,
        FString &data,
        TMap<FString, FString> &responseHeaders,
        struct FLatentActionInfo LatentInfo
    );

    /**
     *
    */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "Restful Function")
    static void SendRestfulWithFileRequest (
        UObject *WorldContextObject,
        bool &success,
        FString url,
        FString verb,
        FString filename,
        TMap<FString, FString> headers,
        float timeout,
        int32 &responseCode,
        FString &data,
        TMap<FString, FString> &responseHeaders,
        struct FLatentActionInfo LatentInfo
    );
};
