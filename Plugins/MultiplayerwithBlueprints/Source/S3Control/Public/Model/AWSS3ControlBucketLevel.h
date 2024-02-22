/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/BucketLevel.h"

#endif

#include "Model/AWSS3ControlActivityMetrics.h"
#include "Model/AWSS3ControlPrefixLevel.h"
#include "Model/AWSS3ControlAdvancedCostOptimizationMetrics.h"
#include "Model/AWSS3ControlAdvancedDataProtectionMetrics.h"
#include "Model/AWSS3ControlDetailedStatusCodesMetrics.h"

#include "AWSS3ControlBucketLevel.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlBucketLevel {
GENERATED_BODY()

    /**
    *  <p>A container for the bucket-level activity metrics for Amazon S3 Storage Lens</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlActivityMetrics activityMetrics;

    /**
    *  <p>A container for the prefix-level metrics for S3 Storage Lens. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlPrefixLevel prefixLevel;

    /**
    *  <p>A container for bucket-level advanced cost-optimization metrics for S3 Storage Lens.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAdvancedCostOptimizationMetrics advancedCostOptimizationMetrics;

    /**
    *  <p>A container for bucket-level advanced data-protection metrics for S3 Storage Lens.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAdvancedDataProtectionMetrics advancedDataProtectionMetrics;

    /**
    *  <p>A container for bucket-level detailed status code metrics for S3 Storage Lens.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlDetailedStatusCodesMetrics detailedStatusCodesMetrics;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::BucketLevel toAWS() const {
        Aws::S3Control::Model::BucketLevel awsBucketLevel;

        if (!(this->activityMetrics.IsEmpty())) {
            awsBucketLevel.SetActivityMetrics(this->activityMetrics.toAWS());
        }

        if (!(this->prefixLevel.IsEmpty())) {
            awsBucketLevel.SetPrefixLevel(this->prefixLevel.toAWS());
        }

        if (!(this->advancedCostOptimizationMetrics.IsEmpty())) {
            awsBucketLevel.SetAdvancedCostOptimizationMetrics(this->advancedCostOptimizationMetrics.toAWS());
        }

        if (!(this->advancedDataProtectionMetrics.IsEmpty())) {
            awsBucketLevel.SetAdvancedDataProtectionMetrics(this->advancedDataProtectionMetrics.toAWS());
        }

        if (!(this->detailedStatusCodesMetrics.IsEmpty())) {
            awsBucketLevel.SetDetailedStatusCodesMetrics(this->detailedStatusCodesMetrics.toAWS());
        }

        return awsBucketLevel;
    }

    bool IsEmpty() const {
        return this->activityMetrics.IsEmpty() && this->prefixLevel.IsEmpty() && this->advancedCostOptimizationMetrics.IsEmpty() && this->advancedDataProtectionMetrics.IsEmpty() && this->detailedStatusCodesMetrics.IsEmpty();
    }

    FAWSS3ControlBucketLevel &fromAWS(const Aws::S3Control::Model::BucketLevel &awsBucketLevel) {
        this->activityMetrics.fromAWS(awsBucketLevel.GetActivityMetrics());

        this->prefixLevel.fromAWS(awsBucketLevel.GetPrefixLevel());

        this->advancedCostOptimizationMetrics.fromAWS(awsBucketLevel.GetAdvancedCostOptimizationMetrics());

        this->advancedDataProtectionMetrics.fromAWS(awsBucketLevel.GetAdvancedDataProtectionMetrics());

        this->detailedStatusCodesMetrics.fromAWS(awsBucketLevel.GetDetailedStatusCodesMetrics());

        return *this;
    }
#endif
};
