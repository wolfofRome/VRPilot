/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/LifecycleConfiguration.h"

#endif

#include "Model/AWSS3CRTRule.h"

#include "AWSS3CRTLifecycleConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTLifecycleConfiguration {
GENERATED_BODY()

    /**
    *  <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTRule> rules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
#endif
};
