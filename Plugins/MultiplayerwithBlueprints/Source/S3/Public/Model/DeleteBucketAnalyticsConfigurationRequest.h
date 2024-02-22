/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteBucketAnalyticsConfigurationRequest.h"

#endif

#include "DeleteBucketAnalyticsConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteBucketAnalyticsConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket from which an analytics configuration is deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The ID that identifies the analytics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;
    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::DeleteBucketAnalyticsConfigurationRequest toAWS() const {
        Aws::S3::Model::DeleteBucketAnalyticsConfigurationRequest awsDeleteBucketAnalyticsConfigurationRequest;

		if (!(this->bucket.IsEmpty())) {
            awsDeleteBucketAnalyticsConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->id.IsEmpty())) {
            awsDeleteBucketAnalyticsConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeleteBucketAnalyticsConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteBucketAnalyticsConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteBucketAnalyticsConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
