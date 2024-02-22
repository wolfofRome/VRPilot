/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketAnalyticsConfigurationsRequest.h"

#endif

#include "AWSS3CRTListBucketAnalyticsConfigurationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketAnalyticsConfigurationsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket from which analytics configurations are retrieved.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The ContinuationToken that represents a placeholder from where this request should begin.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString continuationToken;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ListBucketAnalyticsConfigurationsRequest toAWS() const {
        Aws::S3Crt::Model::ListBucketAnalyticsConfigurationsRequest awsListBucketAnalyticsConfigurationsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsListBucketAnalyticsConfigurationsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->continuationToken.IsEmpty())) {
            awsListBucketAnalyticsConfigurationsRequest.SetContinuationToken(TCHAR_TO_UTF8(*this->continuationToken));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListBucketAnalyticsConfigurationsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListBucketAnalyticsConfigurationsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListBucketAnalyticsConfigurationsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->continuationToken.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
