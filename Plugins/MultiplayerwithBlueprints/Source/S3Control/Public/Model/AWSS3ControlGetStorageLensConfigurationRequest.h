/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetStorageLensConfigurationRequest.h"

#endif

#include "AWSS3ControlGetStorageLensConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetStorageLensConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the Amazon S3 Storage Lens configuration.</p>
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
    Aws::S3Control::Model::GetStorageLensConfigurationRequest toAWS() const {
        Aws::S3Control::Model::GetStorageLensConfigurationRequest awsGetStorageLensConfigurationRequest;

        if (!(this->configId.IsEmpty())) {
            awsGetStorageLensConfigurationRequest.SetConfigId(TCHAR_TO_UTF8(*this->configId));
        }

        if (!(this->accountId.IsEmpty())) {
            awsGetStorageLensConfigurationRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        return awsGetStorageLensConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->configId.IsEmpty() && this->accountId.IsEmpty();
    }
#endif
};
