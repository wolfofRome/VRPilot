/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketAnalyticsConfigurationRequest.h"

#endif

#include "AWSS3CRTGetBucketAnalyticsConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketAnalyticsConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket from which an analytics configuration is retrieved.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The ID that identifies the analytics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

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
    Aws::S3Crt::Model::GetBucketAnalyticsConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::GetBucketAnalyticsConfigurationRequest awsGetBucketAnalyticsConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketAnalyticsConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->id.IsEmpty())) {
            awsGetBucketAnalyticsConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetBucketAnalyticsConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketAnalyticsConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketAnalyticsConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
