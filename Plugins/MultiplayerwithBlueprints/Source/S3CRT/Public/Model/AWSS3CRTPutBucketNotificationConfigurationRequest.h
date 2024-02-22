/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketNotificationConfigurationRequest.h"

#endif

#include "Model/AWSS3CRTNotificationConfiguration.h"

#include "AWSS3CRTPutBucketNotificationConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketNotificationConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTNotificationConfiguration notificationConfiguration;

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
    Aws::S3Crt::Model::PutBucketNotificationConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketNotificationConfigurationRequest awsPutBucketNotificationConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketNotificationConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->notificationConfiguration.IsEmpty())) {
            awsPutBucketNotificationConfigurationRequest.SetNotificationConfiguration(this->notificationConfiguration.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketNotificationConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketNotificationConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketNotificationConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->notificationConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
