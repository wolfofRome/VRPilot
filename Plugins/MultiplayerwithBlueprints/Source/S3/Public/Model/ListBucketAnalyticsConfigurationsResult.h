/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListBucketAnalyticsConfigurationsResult.h"

#endif

#include "Model/AnalyticsConfiguration.h"

#include "ListBucketAnalyticsConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FListBucketAnalyticsConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the returned list of analytics configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken will be provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>The marker that is used as a starting point for this analytics configuration list response. This value is present if it was sent in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

    /**
    *  <p> <code>NextContinuationToken</code> is sent when <code>isTruncated</code> is true, which indicates that there are more analytics configurations to list. The next request must include this <code>NextContinuationToken</code>. The token is obfuscated and is not a usable value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextContinuationToken;

    /**
    *  <p>The list of analytics configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FAnalyticsConfiguration> analyticsConfigurationList;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListBucketAnalyticsConfigurationsResult &fromAWS(const Aws::S3::Model::ListBucketAnalyticsConfigurationsResult &awsListBucketAnalyticsConfigurationsResult) {
        this->isTruncated = awsListBucketAnalyticsConfigurationsResult.GetIsTruncated();

        this->continuationToken = UTF8_TO_TCHAR(awsListBucketAnalyticsConfigurationsResult.GetContinuationToken().c_str());

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketAnalyticsConfigurationsResult.GetNextContinuationToken().c_str());

        this->analyticsConfigurationList.Empty();
        for (const Aws::S3::Model::AnalyticsConfiguration& elem : awsListBucketAnalyticsConfigurationsResult.GetAnalyticsConfigurationList()) {
            this->analyticsConfigurationList.Add(FAnalyticsConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
