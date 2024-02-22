/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/LifecycleConfiguration.h"

#endif

#include "Model/S3Rule.h"

#include "LifecycleConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FLifecycleConfiguration {
GENERATED_BODY()

    /**
    *  <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Rule> rules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
#endif
};
