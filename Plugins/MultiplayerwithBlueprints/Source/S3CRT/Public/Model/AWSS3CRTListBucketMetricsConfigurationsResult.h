/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketMetricsConfigurationsResult.h"

#endif

#include "Model/AWSS3CRTMetricsConfiguration.h"

#include "AWSS3CRTListBucketMetricsConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketMetricsConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the returned list of metrics configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken will be provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p>The marker that is used as a starting point for this metrics configuration list response. This value is present if it was sent in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString continuationToken;

    /**
    *  <p>The marker used to continue a metrics configuration listing that has been truncated. Use the <code>NextContinuationToken</code> from a previously truncated list response to continue the listing. The continuation token is an opaque value that Amazon S3 understands.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextContinuationToken;

    /**
    *  <p>The list of metrics configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTMetricsConfiguration> metricsConfigurationList;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListBucketMetricsConfigurationsResult &fromAWS(const Aws::S3Crt::Model::ListBucketMetricsConfigurationsResult &awsListBucketMetricsConfigurationsResult) {
        this->isTruncated = awsListBucketMetricsConfigurationsResult.GetIsTruncated();

        this->continuationToken = UTF8_TO_TCHAR(awsListBucketMetricsConfigurationsResult.GetContinuationToken().c_str());

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketMetricsConfigurationsResult.GetNextContinuationToken().c_str());

        this->metricsConfigurationList.Empty();
        for (const Aws::S3Crt::Model::MetricsConfiguration& elem : awsListBucketMetricsConfigurationsResult.GetMetricsConfigurationList()) {
            this->metricsConfigurationList.Add(FAWSS3CRTMetricsConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
