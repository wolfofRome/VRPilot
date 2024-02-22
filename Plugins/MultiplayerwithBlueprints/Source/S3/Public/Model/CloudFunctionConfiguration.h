/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CloudFunctionConfiguration.h"

#endif

#include "Model/S3Event.h"

#include "CloudFunctionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FCloudFunctionConfiguration {
GENERATED_BODY()

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>Bucket events for which to send notifications.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<ES3Event> events;

    /**
    *  <p>Lambda cloud function ARN that Amazon S3 can invoke when it detects events of the specified type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString cloudFunction;

    /**
    *  <p>The role supporting the invocation of the Lambda function</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString invocationRole;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
#endif
};
