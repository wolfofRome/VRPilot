/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointConfigurationForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlGetAccessPointConfigurationForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointConfigurationForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the Object Lambda Access Point you want to return the configuration for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetAccessPointConfigurationForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::GetAccessPointConfigurationForObjectLambdaRequest awsGetAccessPointConfigurationForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsGetAccessPointConfigurationForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsGetAccessPointConfigurationForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsGetAccessPointConfigurationForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
