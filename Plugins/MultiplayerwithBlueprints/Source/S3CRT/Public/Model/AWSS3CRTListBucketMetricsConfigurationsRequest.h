/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketMetricsConfigurationsRequest.h"

#endif

#include "AWSS3CRTListBucketMetricsConfigurationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketMetricsConfigurationsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket containing the metrics configurations to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The marker that is used to continue a metrics configuration listing that has been truncated. Use the NextContinuationToken from a previously truncated list response to continue the listing. The continuation token is an opaque value that Amazon S3 understands.</p>
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
    Aws::S3Crt::Model::ListBucketMetricsConfigurationsRequest toAWS() const {
        Aws::S3Crt::Model::ListBucketMetricsConfigurationsRequest awsListBucketMetricsConfigurationsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsListBucketMetricsConfigurationsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->continuationToken.IsEmpty())) {
            awsListBucketMetricsConfigurationsRequest.SetContinuationToken(TCHAR_TO_UTF8(*this->continuationToken));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListBucketMetricsConfigurationsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListBucketMetricsConfigurationsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListBucketMetricsConfigurationsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->continuationToken.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
