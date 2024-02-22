/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutAccessPointConfigurationForObjectLambdaRequest.h"

#endif

#include "Model/AWSS3ControlObjectLambdaConfiguration.h"

#include "AWSS3ControlPutAccessPointConfigurationForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutAccessPointConfigurationForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>Object Lambda Access Point configuration document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlObjectLambdaConfiguration configuration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutAccessPointConfigurationForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::PutAccessPointConfigurationForObjectLambdaRequest awsPutAccessPointConfigurationForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsPutAccessPointConfigurationForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsPutAccessPointConfigurationForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->configuration.IsEmpty())) {
            awsPutAccessPointConfigurationForObjectLambdaRequest.SetConfiguration(this->configuration.toAWS());
        }

        return awsPutAccessPointConfigurationForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty() && this->configuration.IsEmpty();
    }
#endif
};
