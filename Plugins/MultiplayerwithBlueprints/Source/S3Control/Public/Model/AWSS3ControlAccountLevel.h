/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AccountLevel.h"

#endif

#include "Model/AWSS3ControlActivityMetrics.h"
#include "Model/AWSS3ControlBucketLevel.h"
#include "Model/AWSS3ControlAdvancedCostOptimizationMetrics.h"
#include "Model/AWSS3ControlAdvancedDataProtectionMetrics.h"
#include "Model/AWSS3ControlDetailedStatusCodesMetrics.h"

#include "AWSS3ControlAccountLevel.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAccountLevel {
GENERATED_BODY()

    /**
    *  <p>A container for the S3 Storage Lens activity metrics.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlActivityMetrics activityMetrics;

    /**
    *  <p>A container for the S3 Storage Lens bucket-level configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlBucketLevel bucketLevel;

    /**
    *  <p>A container for S3 Storage Lens advanced cost-optimization metrics.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAdvancedCostOptimizationMetrics advancedCostOptimizationMetrics;

    /**
    *  <p>A container for S3 Storage Lens advanced data-protection metrics.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAdvancedDataProtectionMetrics advancedDataProtectionMetrics;

    /**
    *  <p>A container for detailed status code metrics. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlDetailedStatusCodesMetrics detailedStatusCodesMetrics;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::AccountLevel toAWS() const {
        Aws::S3Control::Model::AccountLevel awsAccountLevel;

        if (!(this->activityMetrics.IsEmpty())) {
            awsAccountLevel.SetActivityMetrics(this->activityMetrics.toAWS());
        }

        if (!(this->bucketLevel.IsEmpty())) {
            awsAccountLevel.SetBucketLevel(this->bucketLevel.toAWS());
        }

        if (!(this->advancedCostOptimizationMetrics.IsEmpty())) {
            awsAccountLevel.SetAdvancedCostOptimizationMetrics(this->advancedCostOptimizationMetrics.toAWS());
        }

        if (!(this->advancedDataProtectionMetrics.IsEmpty())) {
            awsAccountLevel.SetAdvancedDataProtectionMetrics(this->advancedDataProtectionMetrics.toAWS());
        }

        if (!(this->detailedStatusCodesMetrics.IsEmpty())) {
            awsAccountLevel.SetDetailedStatusCodesMetrics(this->detailedStatusCodesMetrics.toAWS());
        }

        return awsAccountLevel;
    }

    bool IsEmpty() const {
        return this->activityMetrics.IsEmpty() && this->bucketLevel.IsEmpty() && this->advancedCostOptimizationMetrics.IsEmpty() && this->advancedDataProtectionMetrics.IsEmpty() && this->detailedStatusCodesMetrics.IsEmpty();
    }

    FAWSS3ControlAccountLevel &fromAWS(const Aws::S3Control::Model::AccountLevel &awsAccountLevel) {
        this->activityMetrics.fromAWS(awsAccountLevel.GetActivityMetrics());

        this->bucketLevel.fromAWS(awsAccountLevel.GetBucketLevel());

        this->advancedCostOptimizationMetrics.fromAWS(awsAccountLevel.GetAdvancedCostOptimizationMetrics());

        this->advancedDataProtectionMetrics.fromAWS(awsAccountLevel.GetAdvancedDataProtectionMetrics());

        this->detailedStatusCodesMetrics.fromAWS(awsAccountLevel.GetDetailedStatusCodesMetrics());

        return *this;
    }
#endif
};
