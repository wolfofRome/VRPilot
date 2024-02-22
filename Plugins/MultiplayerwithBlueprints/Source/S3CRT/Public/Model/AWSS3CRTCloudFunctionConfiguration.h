/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CloudFunctionConfiguration.h"

#endif

#include "Model/AWSS3CRTEvent.h"

#include "AWSS3CRTCloudFunctionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCloudFunctionConfiguration {
GENERATED_BODY()

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>Bucket events for which to send notifications.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<EAWSS3CRTEvent> events;

    /**
    *  <p>Lambda cloud function ARN that Amazon S3 can invoke when it detects events of the specified type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString cloudFunction;

    /**
    *  <p>The role supporting the invocation of the Lambda function</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString invocationRole;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
#endif
};
