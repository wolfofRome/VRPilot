/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketMetricsConfigurationResult.h"

#endif

#include "Model/AWSS3CRTMetricsConfiguration.h"

#include "AWSS3CRTGetBucketMetricsConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketMetricsConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTMetricsConfiguration metricsConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketMetricsConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketMetricsConfigurationResult &awsGetBucketMetricsConfigurationResult) {
        this->metricsConfiguration = FAWSS3CRTMetricsConfiguration().fromAWS(awsGetBucketMetricsConfigurationResult.GetMetricsConfiguration());

        return *this;
    }
#endif
};
