/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PrefixLevelStorageMetrics.h"

#endif

#include "Model/AWSS3ControlSelectionCriteria.h"

#include "AWSS3ControlPrefixLevelStorageMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPrefixLevelStorageMetrics {
GENERATED_BODY()

    /**
    *  <p>A container for whether prefix-level storage metrics are enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlSelectionCriteria selectionCriteria;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PrefixLevelStorageMetrics toAWS() const {
        Aws::S3Control::Model::PrefixLevelStorageMetrics awsPrefixLevelStorageMetrics;

        if (!(false)) {
            awsPrefixLevelStorageMetrics.SetIsEnabled(this->isEnabled);
        }

        if (!(this->selectionCriteria.IsEmpty())) {
            awsPrefixLevelStorageMetrics.SetSelectionCriteria(this->selectionCriteria.toAWS());
        }

        return awsPrefixLevelStorageMetrics;
    }

    bool IsEmpty() const {
        return false && this->selectionCriteria.IsEmpty();
    }

    FAWSS3ControlPrefixLevelStorageMetrics &fromAWS(const Aws::S3Control::Model::PrefixLevelStorageMetrics &awsPrefixLevelStorageMetrics) {
        this->isEnabled = awsPrefixLevelStorageMetrics.GetIsEnabled();

        this->selectionCriteria.fromAWS(awsPrefixLevelStorageMetrics.GetSelectionCriteria());

        return *this;
    }
#endif
};
