/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketLoggingRequest.h"

#endif

#include "AWSS3CRTGetBucketLoggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketLoggingRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name for which to get the logging information.</p>
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
    Aws::S3Crt::Model::GetBucketLoggingRequest toAWS() const {
        Aws::S3Crt::Model::GetBucketLoggingRequest awsGetBucketLoggingRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketLoggingRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetBucketLoggingRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketLoggingRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketLoggingRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
