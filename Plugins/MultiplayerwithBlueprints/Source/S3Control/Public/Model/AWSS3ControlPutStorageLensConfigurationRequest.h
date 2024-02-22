/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutStorageLensConfigurationRequest.h"

#endif

#include "Model/AWSS3ControlStorageLensConfiguration.h"
#include "Model/AWSS3ControlStorageLensTag.h"

#include "AWSS3ControlPutStorageLensConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutStorageLensConfigurationRequest {
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

    /**
    *  <p>The S3 Storage Lens configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlStorageLensConfiguration storageLensConfiguration;

    /**
    *  <p>The tag set of the S3 Storage Lens configuration.</p>  <p>You can set up to a maximum of 50 tags.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlStorageLensTag> tags;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutStorageLensConfigurationRequest toAWS() const {
        Aws::S3Control::Model::PutStorageLensConfigurationRequest awsPutStorageLensConfigurationRequest;

        if (!(this->configId.IsEmpty())) {
            awsPutStorageLensConfigurationRequest.SetConfigId(TCHAR_TO_UTF8(*this->configId));
        }

        if (!(this->accountId.IsEmpty())) {
            awsPutStorageLensConfigurationRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->storageLensConfiguration.IsEmpty())) {
            awsPutStorageLensConfigurationRequest.SetStorageLensConfiguration(this->storageLensConfiguration.toAWS());
        }

        for (const FAWSS3ControlStorageLensTag& elem : this->tags) {
            awsPutStorageLensConfigurationRequest.AddTags(elem.toAWS());
        }

        return awsPutStorageLensConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->configId.IsEmpty() && this->accountId.IsEmpty() && this->storageLensConfiguration.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
