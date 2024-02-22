/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteStorageLensConfigurationRequest.h"

#endif

#include "AWSS3ControlDeleteStorageLensConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteStorageLensConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the S3 Storage Lens configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString configId;

    /**
    *  <p>The account ID of the requester.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DeleteStorageLensConfigurationRequest toAWS() const {
        Aws::S3Control::Model::DeleteStorageLensConfigurationRequest awsDeleteStorageLensConfigurationRequest;

        if (!(this->configId.IsEmpty())) {
            awsDeleteStorageLensConfigurationRequest.SetConfigId(TCHAR_TO_UTF8(*this->configId));
        }

        if (!(this->accountId.IsEmpty())) {
            awsDeleteStorageLensConfigurationRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        return awsDeleteStorageLensConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->configId.IsEmpty() && this->accountId.IsEmpty();
    }
#endif
};
