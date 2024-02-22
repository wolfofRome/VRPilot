/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketIntelligentTieringConfigurationsResult.h"

#endif

#include "Model/AWSS3CRTIntelligentTieringConfiguration.h"

#include "AWSS3CRTListBucketIntelligentTieringConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketIntelligentTieringConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the returned list of analytics configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken will be provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p>The ContinuationToken that represents a placeholder from where this request should begin.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString continuationToken;

    /**
    *  <p>The marker used to continue this inventory configuration listing. Use the <code>NextContinuationToken</code> from this response to continue the listing in a subsequent request. The continuation token is an opaque value that Amazon S3 understands.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextContinuationToken;

    /**
    *  <p>The list of S3 Intelligent-Tiering configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTIntelligentTieringConfiguration> intelligentTieringConfigurationList;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListBucketIntelligentTieringConfigurationsResult &fromAWS(const Aws::S3Crt::Model::ListBucketIntelligentTieringConfigurationsResult &awsListBucketIntelligentTieringConfigurationsResult) {
        this->isTruncated = awsListBucketIntelligentTieringConfigurationsResult.GetIsTruncated();

        this->continuationToken = UTF8_TO_TCHAR(awsListBucketIntelligentTieringConfigurationsResult.GetContinuationToken().c_str());

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketIntelligentTieringConfigurationsResult.GetNextContinuationToken().c_str());

        this->intelligentTieringConfigurationList.Empty();
        for (const Aws::S3Crt::Model::IntelligentTieringConfiguration& elem : awsListBucketIntelligentTieringConfigurationsResult.GetIntelligentTieringConfigurationList()) {
            this->intelligentTieringConfigurationList.Add(FAWSS3CRTIntelligentTieringConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
