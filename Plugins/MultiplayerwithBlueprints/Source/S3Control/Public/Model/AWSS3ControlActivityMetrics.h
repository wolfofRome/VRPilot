/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ActivityMetrics.h"

#endif

#include "AWSS3ControlActivityMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlActivityMetrics {
GENERATED_BODY()

    /**
    *  <p>A container for whether the activity metrics are enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ActivityMetrics toAWS() const {
        Aws::S3Control::Model::ActivityMetrics awsActivityMetrics;

        if (!(false)) {
            awsActivityMetrics.SetIsEnabled(this->isEnabled);
        }

        return awsActivityMetrics;
    }

    bool IsEmpty() const {
        return false;
    }

    FAWSS3ControlActivityMetrics &fromAWS(const Aws::S3Control::Model::ActivityMetrics &awsActivityMetrics) {
        this->isEnabled = awsActivityMetrics.GetIsEnabled();

        return *this;
    }
#endif
};
