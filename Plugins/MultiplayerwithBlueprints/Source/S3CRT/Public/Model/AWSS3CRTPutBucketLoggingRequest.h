/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketLoggingRequest.h"

#endif

#include "Model/AWSS3CRTBucketLoggingStatus.h"

#include "AWSS3CRTPutBucketLoggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketLoggingRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which to set the logging parameters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Container for logging status information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTBucketLoggingStatus bucketLoggingStatus;

    /**
    *  <p>The MD5 hash of the <code>PutBucketLogging</code> request body.</p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

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
    Aws::S3Crt::Model::PutBucketLoggingRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketLoggingRequest awsPutBucketLoggingRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketLoggingRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->bucketLoggingStatus.IsEmpty())) {
            awsPutBucketLoggingRequest.SetBucketLoggingStatus(this->bucketLoggingStatus.toAWS());
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketLoggingRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketLoggingRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketLoggingRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketLoggingRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->bucketLoggingStatus.IsEmpty() && this->contentMD5.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
