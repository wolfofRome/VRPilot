/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketAnalyticsConfigurationResult.h"

#endif

#include "Model/AWSS3CRTAnalyticsConfiguration.h"

#include "AWSS3CRTGetBucketAnalyticsConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketAnalyticsConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The configuration and any analyses for the analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAnalyticsConfiguration analyticsConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketAnalyticsConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketAnalyticsConfigurationResult &awsGetBucketAnalyticsConfigurationResult) {
        this->analyticsConfiguration = FAWSS3CRTAnalyticsConfiguration().fromAWS(awsGetBucketAnalyticsConfigurationResult.GetAnalyticsConfiguration());

        return *this;
    }
#endif
};
