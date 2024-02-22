/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CloudWatchMetrics.h"

#endif

#include "AWSS3ControlCloudWatchMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCloudWatchMetrics {
GENERATED_BODY()

    /**
    *  <p>A container that indicates whether CloudWatch publishing for S3 Storage Lens metrics is enabled. A value of <code>true</code> indicates that CloudWatch publishing for S3 Storage Lens metrics is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CloudWatchMetrics toAWS() const {
        Aws::S3Control::Model::CloudWatchMetrics awsCloudWatchMetrics;

        awsCloudWatchMetrics.SetIsEnabled(this->isEnabled);

        return awsCloudWatchMetrics;
    }

    bool IsEmpty() const {
        return false;
    }

    FAWSS3ControlCloudWatchMetrics &fromAWS(const Aws::S3Control::Model::CloudWatchMetrics &awsCloudWatchMetrics) {
        this->isEnabled = awsCloudWatchMetrics.GetIsEnabled();

        return *this;
    }
#endif
};
