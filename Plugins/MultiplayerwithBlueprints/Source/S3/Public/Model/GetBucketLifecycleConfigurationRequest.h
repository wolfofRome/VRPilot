/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketLifecycleConfigurationRequest.h"

#endif

#include "GetBucketLifecycleConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketLifecycleConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which to get the lifecycle information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

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
    Aws::S3::Model::GetBucketLifecycleConfigurationRequest toAWS() const {
        Aws::S3::Model::GetBucketLifecycleConfigurationRequest awsGetBucketLifecycleConfigurationRequest;

		if (!(this->bucket.IsEmpty())) {
            awsGetBucketLifecycleConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetBucketLifecycleConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketLifecycleConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketLifecycleConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};