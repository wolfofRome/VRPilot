/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketLifecycleConfigurationRequest.h"

#endif

#include "Model/AWSS3CRTBucketLifecycleConfiguration.h"

#include "AWSS3CRTPutBucketLifecycleConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketLifecycleConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which to set the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Container for lifecycle rules. You can add as many as 1,000 rules.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTBucketLifecycleConfiguration lifecycleConfiguration;

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
    Aws::S3Crt::Model::PutBucketLifecycleConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketLifecycleConfigurationRequest awsPutBucketLifecycleConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketLifecycleConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->lifecycleConfiguration.IsEmpty())) {
            awsPutBucketLifecycleConfigurationRequest.SetLifecycleConfiguration(this->lifecycleConfiguration.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketLifecycleConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketLifecycleConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketLifecycleConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->lifecycleConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
