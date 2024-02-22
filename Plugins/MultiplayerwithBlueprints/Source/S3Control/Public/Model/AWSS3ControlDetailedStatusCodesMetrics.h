/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DetailedStatusCodesMetrics.h"

#endif

#include "AWSS3ControlDetailedStatusCodesMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDetailedStatusCodesMetrics {
GENERATED_BODY()

    /**
    *  <p>A container that indicates whether detailed status code metrics are enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DetailedStatusCodesMetrics toAWS() const {
        Aws::S3Control::Model::DetailedStatusCodesMetrics awsDetailedStatusCodesMetrics;

        awsDetailedStatusCodesMetrics.SetIsEnabled(this->isEnabled);

        return awsDetailedStatusCodesMetrics;
    }

    bool IsEmpty() const {
        return false;
    }

    FAWSS3ControlDetailedStatusCodesMetrics &fromAWS(const Aws::S3Control::Model::DetailedStatusCodesMetrics &awsDetailedStatusCodesMetrics) {
        this->isEnabled = awsDetailedStatusCodesMetrics.GetIsEnabled();

        return *this;
    }
#endif
};
