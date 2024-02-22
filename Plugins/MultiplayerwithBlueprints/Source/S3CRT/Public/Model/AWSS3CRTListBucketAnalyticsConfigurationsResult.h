/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketAnalyticsConfigurationsResult.h"

#endif

#include "Model/AWSS3CRTAnalyticsConfiguration.h"

#include "AWSS3CRTListBucketAnalyticsConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketAnalyticsConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the returned list of analytics configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken will be provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p>The marker that is used as a starting point for this analytics configuration list response. This value is present if it was sent in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString continuationToken;

    /**
    *  <p> <code>NextContinuationToken</code> is sent when <code>isTruncated</code> is true, which indicates that there are more analytics configurations to list. The next request must include this <code>NextContinuationToken</code>. The token is obfuscated and is not a usable value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextContinuationToken;

    /**
    *  <p>The list of analytics configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTAnalyticsConfiguration> analyticsConfigurationList;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListBucketAnalyticsConfigurationsResult &fromAWS(const Aws::S3Crt::Model::ListBucketAnalyticsConfigurationsResult &awsListBucketAnalyticsConfigurationsResult) {
        this->isTruncated = awsListBucketAnalyticsConfigurationsResult.GetIsTruncated();

        this->continuationToken = UTF8_TO_TCHAR(awsListBucketAnalyticsConfigurationsResult.GetContinuationToken().c_str());

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketAnalyticsConfigurationsResult.GetNextContinuationToken().c_str());

        this->analyticsConfigurationList.Empty();
        for (const Aws::S3Crt::Model::AnalyticsConfiguration& elem : awsListBucketAnalyticsConfigurationsResult.GetAnalyticsConfigurationList()) {
            this->analyticsConfigurationList.Add(FAWSS3CRTAnalyticsConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
