/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AdvancedDataProtectionMetrics.h"

#endif

#include "AWSS3ControlAdvancedDataProtectionMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAdvancedDataProtectionMetrics {
GENERATED_BODY()

    /**
    *  <p>A container that indicates whether advanced data-protection metrics are enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::AdvancedDataProtectionMetrics toAWS() const {
        Aws::S3Control::Model::AdvancedDataProtectionMetrics awsAdvancedDataProtectionMetrics;

        awsAdvancedDataProtectionMetrics.SetIsEnabled(this->isEnabled);

        return awsAdvancedDataProtectionMetrics;
    }

    bool IsEmpty() const {
        return false;
    }

    FAWSS3ControlAdvancedDataProtectionMetrics &fromAWS(const Aws::S3Control::Model::AdvancedDataProtectionMetrics &awsAdvancedDataProtectionMetrics) {
        this->isEnabled = awsAdvancedDataProtectionMetrics.GetIsEnabled();

        return *this;
    }
#endif
};
