/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketAnalyticsConfigurationRequest.h"

#endif

#include "Model/AWSS3CRTAnalyticsConfiguration.h"

#include "AWSS3CRTPutBucketAnalyticsConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketAnalyticsConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket to which an analytics configuration is stored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The ID that identifies the analytics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>The configuration and any analyses for the analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAnalyticsConfiguration analyticsConfiguration;

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
    Aws::S3Crt::Model::PutBucketAnalyticsConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketAnalyticsConfigurationRequest awsPutBucketAnalyticsConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketAnalyticsConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->id.IsEmpty())) {
            awsPutBucketAnalyticsConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->analyticsConfiguration.IsEmpty())) {
            awsPutBucketAnalyticsConfigurationRequest.SetAnalyticsConfiguration(this->analyticsConfiguration.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketAnalyticsConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketAnalyticsConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketAnalyticsConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->analyticsConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
