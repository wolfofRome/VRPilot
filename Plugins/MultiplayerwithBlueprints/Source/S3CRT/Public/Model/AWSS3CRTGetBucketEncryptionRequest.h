/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketEncryptionRequest.h"

#endif

#include "AWSS3CRTGetBucketEncryptionRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketEncryptionRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket from which the server-side encryption configuration is retrieved.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

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
    Aws::S3Crt::Model::GetBucketEncryptionRequest toAWS() const {
        Aws::S3Crt::Model::GetBucketEncryptionRequest awsGetBucketEncryptionRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketEncryptionRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetBucketEncryptionRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketEncryptionRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketEncryptionRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
