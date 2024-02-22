/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListBucketMetricsConfigurationsResult.h"

#endif

#include "Model/MetricsConfiguration.h"

#include "ListBucketMetricsConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FListBucketMetricsConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the returned list of metrics configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken will be provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>The marker that is used as a starting point for this metrics configuration list response. This value is present if it was sent in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

    /**
    *  <p>The marker used to continue a metrics configuration listing that has been truncated. Use the <code>NextContinuationToken</code> from a previously truncated list response to continue the listing. The continuation token is an opaque value that Amazon S3 understands.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextContinuationToken;

    /**
    *  <p>The list of metrics configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FMetricsConfiguration> metricsConfigurationList;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListBucketMetricsConfigurationsResult &fromAWS(const Aws::S3::Model::ListBucketMetricsConfigurationsResult &awsListBucketMetricsConfigurationsResult) {
        this->isTruncated = awsListBucketMetricsConfigurationsResult.GetIsTruncated();

        this->continuationToken = UTF8_TO_TCHAR(awsListBucketMetricsConfigurationsResult.GetContinuationToken().c_str());

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketMetricsConfigurationsResult.GetNextContinuationToken().c_str());

        this->metricsConfigurationList.Empty();
        for (const Aws::S3::Model::MetricsConfiguration& elem : awsListBucketMetricsConfigurationsResult.GetMetricsConfigurationList()) {
            this->metricsConfigurationList.Add(FMetricsConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
