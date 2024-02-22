/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteStorageLensConfigurationTaggingRequest.h"

#endif

#include "AWSS3ControlDeleteStorageLensConfigurationTaggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteStorageLensConfigurationTaggingRequest {
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
    Aws::S3Control::Model::DeleteStorageLensConfigurationTaggingRequest toAWS() const {
        Aws::S3Control::Model::DeleteStorageLensConfigurationTaggingRequest awsDeleteStorageLensConfigurationTaggingRequest;

        if (!(this->configId.IsEmpty())) {
            awsDeleteStorageLensConfigurationTaggingRequest.SetConfigId(TCHAR_TO_UTF8(*this->configId));
        }

        if (!(this->accountId.IsEmpty())) {
            awsDeleteStorageLensConfigurationTaggingRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        return awsDeleteStorageLensConfigurationTaggingRequest;
    }

    bool IsEmpty() const {
        return this->configId.IsEmpty() && this->accountId.IsEmpty();
    }
#endif
};
