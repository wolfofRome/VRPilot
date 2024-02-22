/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketAccelerateConfigurationRequest.h"

#endif

#include "Model/AWSS3CRTAccelerateConfiguration.h"

#include "AWSS3CRTPutBucketAccelerateConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketAccelerateConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which the accelerate configuration is set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Container for setting the transfer acceleration state.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAccelerateConfiguration accelerateConfiguration;

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
    Aws::S3Crt::Model::PutBucketAccelerateConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketAccelerateConfigurationRequest awsPutBucketAccelerateConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketAccelerateConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->accelerateConfiguration.IsEmpty())) {
            awsPutBucketAccelerateConfigurationRequest.SetAccelerateConfiguration(this->accelerateConfiguration.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketAccelerateConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketAccelerateConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }
        return awsPutBucketAccelerateConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->accelerateConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
