/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateAccessPointForObjectLambdaRequest.h"

#endif

#include "Model/AWSS3ControlObjectLambdaConfiguration.h"

#include "AWSS3ControlCreateAccessPointForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateAccessPointForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID for owner of the specified Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name you want to assign to this Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>Object Lambda Access Point configuration as a JSON document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlObjectLambdaConfiguration configuration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateAccessPointForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::CreateAccessPointForObjectLambdaRequest awsCreateAccessPointForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsCreateAccessPointForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsCreateAccessPointForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->configuration.IsEmpty())) {
            awsCreateAccessPointForObjectLambdaRequest.SetConfiguration(this->configuration.toAWS());
        }

        return awsCreateAccessPointForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty() && this->configuration.IsEmpty();
    }
#endif
};
