/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketMetricsConfigurationResult.h"

#endif

#include "Model/MetricsConfiguration.h"

#include "GetBucketMetricsConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketMetricsConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FMetricsConfiguration metricsConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketMetricsConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketMetricsConfigurationResult &awsGetBucketMetricsConfigurationResult) {
        this->metricsConfiguration.fromAWS(awsGetBucketMetricsConfigurationResult.GetMetricsConfiguration());

        return *this;
    }
#endif
};
