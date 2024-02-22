/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListStorageLensConfigurationEntry.h"

#endif

#include "AWSS3ControlListStorageLensConfigurationEntry.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListStorageLensConfigurationEntry {
GENERATED_BODY()

    /**
    *  <p>A container for the S3 Storage Lens configuration ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString id;

    /**
    *  <p>The ARN of the S3 Storage Lens configuration. This property is read-only.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString storageLensArn;

    /**
    *  <p>A container for the S3 Storage Lens home Region. Your metrics data is stored and retained in your designated S3 Storage Lens home Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString homeRegion;

    /**
    *  <p>A container for whether the S3 Storage Lens configuration is enabled. This property is required.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlListStorageLensConfigurationEntry &fromAWS(const Aws::S3Control::Model::ListStorageLensConfigurationEntry &awsListStorageLensConfigurationEntry) {
        this->id = UTF8_TO_TCHAR(awsListStorageLensConfigurationEntry.GetId().c_str());

        this->storageLensArn = UTF8_TO_TCHAR(awsListStorageLensConfigurationEntry.GetStorageLensArn().c_str());

        this->homeRegion = UTF8_TO_TCHAR(awsListStorageLensConfigurationEntry.GetHomeRegion().c_str());

        this->isEnabled = awsListStorageLensConfigurationEntry.GetIsEnabled();

        return *this;
    }
#endif
};
