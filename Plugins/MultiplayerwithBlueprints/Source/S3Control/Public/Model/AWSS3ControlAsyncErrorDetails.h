/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AsyncErrorDetails.h"

#endif

#include "AWSS3ControlAsyncErrorDetails.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAsyncErrorDetails {
GENERATED_BODY()

    /**
    *  <p>A string that uniquely identifies the error condition.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString code;

    /**
    *  <p>A generic description of the error condition in English.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString message;

    /**
    *  <p>The identifier of the resource associated with the error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString resource;

    /**
    *  <p>The ID of the request associated with the error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString requestId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlAsyncErrorDetails &fromAWS(const Aws::S3Control::Model::AsyncErrorDetails &awsAsyncErrorDetails) {
        this->code = UTF8_TO_TCHAR(awsAsyncErrorDetails.GetCode().c_str());

        this->message = UTF8_TO_TCHAR(awsAsyncErrorDetails.GetMessage().c_str());

        this->resource = UTF8_TO_TCHAR(awsAsyncErrorDetails.GetResource().c_str());

        this->requestId = UTF8_TO_TCHAR(awsAsyncErrorDetails.GetRequestId().c_str());

        return *this;
    }
#endif
};
