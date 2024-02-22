/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutStorageLensConfigurationTaggingRequest.h"

#endif

#include "Model/AWSS3ControlStorageLensTag.h"

#include "AWSS3ControlPutStorageLensConfigurationTaggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutStorageLensConfigurationTaggingRequest {
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
    *  <p>The tag set of the S3 Storage Lens configuration.</p>  <p>You can set up to a maximum of 50 tags.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlStorageLensTag> tags;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutStorageLensConfigurationTaggingRequest toAWS() const {
        Aws::S3Control::Model::PutStorageLensConfigurationTaggingRequest awsPutStorageLensConfigurationTaggingRequest;

        if (!(this->configId.IsEmpty())) {
            awsPutStorageLensConfigurationTaggingRequest.SetConfigId(TCHAR_TO_UTF8(*this->configId));
        }

        if (!(this->accountId.IsEmpty())) {
            awsPutStorageLensConfigurationTaggingRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        for (const FAWSS3ControlStorageLensTag& elem : this->tags) {
            awsPutStorageLensConfigurationTaggingRequest.AddTags(elem.toAWS());
        }

        return awsPutStorageLensConfigurationTaggingRequest;
    }

    bool IsEmpty() const {
        return this->configId.IsEmpty() && this->accountId.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
