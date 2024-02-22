/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListBucketIntelligentTieringConfigurationsRequest.h"

#endif

#include "AWSS3ListBucketIntelligentTieringConfigurationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ListBucketIntelligentTieringConfigurationsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Amazon S3 bucket whose configuration you want to modify or retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The ContinuationToken that represents a placeholder from where this request should begin.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ListBucketIntelligentTieringConfigurationsRequest toAWS() const {
        Aws::S3::Model::ListBucketIntelligentTieringConfigurationsRequest awsListBucketIntelligentTieringConfigurationsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsListBucketIntelligentTieringConfigurationsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->continuationToken.IsEmpty())) {
            awsListBucketIntelligentTieringConfigurationsRequest.SetContinuationToken(TCHAR_TO_UTF8(*this->continuationToken));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListBucketIntelligentTieringConfigurationsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListBucketIntelligentTieringConfigurationsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->continuationToken.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
