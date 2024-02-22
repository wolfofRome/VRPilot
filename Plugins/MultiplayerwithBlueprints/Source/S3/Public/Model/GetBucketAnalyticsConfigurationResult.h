/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketAnalyticsConfigurationResult.h"

#endif

#include "Model/AnalyticsConfiguration.h"

#include "GetBucketAnalyticsConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketAnalyticsConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The configuration and any analyses for the analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAnalyticsConfiguration analyticsConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketAnalyticsConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketAnalyticsConfigurationResult &awsGetBucketAnalyticsConfigurationResult) {
        this->analyticsConfiguration.fromAWS(awsGetBucketAnalyticsConfigurationResult.GetAnalyticsConfiguration());

        return *this;
    }
#endif
};
