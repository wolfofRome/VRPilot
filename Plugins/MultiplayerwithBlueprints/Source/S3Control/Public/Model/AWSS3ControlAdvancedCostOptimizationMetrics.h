/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AdvancedCostOptimizationMetrics.h"

#endif

#include "AWSS3ControlAdvancedCostOptimizationMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAdvancedCostOptimizationMetrics {
GENERATED_BODY()

    /**
    *  <p>A container that indicates whether advanced cost-optimization metrics are enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::AdvancedCostOptimizationMetrics toAWS() const {
        Aws::S3Control::Model::AdvancedCostOptimizationMetrics awsAdvancedCostOptimizationMetrics;

        awsAdvancedCostOptimizationMetrics.SetIsEnabled(this->isEnabled);

        return awsAdvancedCostOptimizationMetrics;
    }

    bool IsEmpty() const {
        return false;
    }

    FAWSS3ControlAdvancedCostOptimizationMetrics &fromAWS(const Aws::S3Control::Model::AdvancedCostOptimizationMetrics &awsAdvancedCostOptimizationMetrics) {
        this->isEnabled = awsAdvancedCostOptimizationMetrics.GetIsEnabled();

        return *this;
    }
#endif
};
