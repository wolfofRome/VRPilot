/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketLoggingRequest.h"

#endif

#include "Model/BucketLoggingStatus.h"

#include "PutBucketLoggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutBucketLoggingRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which to set the logging parameters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Container for logging status information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FBucketLoggingStatus bucketLoggingStatus;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the data. This header must be used as a message integrity check to verify that the request body was not corrupted in transit. For more information, go to <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864.</a> </p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentMD5;

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
    Aws::S3::Model::PutBucketLoggingRequest toAWS() const {
        Aws::S3::Model::PutBucketLoggingRequest awsPutBucketLoggingRequest;

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
