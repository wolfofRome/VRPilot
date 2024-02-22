/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PrefixLevel.h"

#endif

#include "Model/AWSS3ControlPrefixLevelStorageMetrics.h"

#include "AWSS3ControlPrefixLevel.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPrefixLevel {
GENERATED_BODY()

    /**
    *  <p>A container for the prefix-level storage metrics for S3 Storage Lens.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlPrefixLevelStorageMetrics storageMetrics;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PrefixLevel toAWS() const {
        Aws::S3Control::Model::PrefixLevel awsPrefixLevel;

        if (!(this->storageMetrics.IsEmpty())) {
            awsPrefixLevel.SetStorageMetrics(this->storageMetrics.toAWS());
        }

        return awsPrefixLevel;
    }

    bool IsEmpty() const {
        return this->storageMetrics.IsEmpty();
    }

    FAWSS3ControlPrefixLevel &fromAWS(const Aws::S3Control::Model::PrefixLevel &awsPrefixLevel) {
        this->storageMetrics.fromAWS(awsPrefixLevel.GetStorageMetrics());

        return *this;
    }
#endif
};
