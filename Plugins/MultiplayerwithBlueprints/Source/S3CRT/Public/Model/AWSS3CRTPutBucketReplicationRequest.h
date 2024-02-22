/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketReplicationRequest.h"

#endif

#include "Model/AWSS3CRTReplicationConfiguration.h"

#include "AWSS3CRTPutBucketReplicationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketReplicationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the data. You must use this header as a message integrity check to verify that the request body was not corrupted in transit. For more information, see <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864</a>.</p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTReplicationConfiguration replicationConfiguration;

    /**
    *  <p>A token to allow Object Lock to be enabled for an existing bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString token;

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
    Aws::S3Crt::Model::PutBucketReplicationRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketReplicationRequest awsPutBucketReplicationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketReplicationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketReplicationRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->replicationConfiguration.IsEmpty())) {
            awsPutBucketReplicationRequest.SetReplicationConfiguration(this->replicationConfiguration.toAWS());
        }

        if (!(this->token.IsEmpty())) {
            awsPutBucketReplicationRequest.SetToken(TCHAR_TO_UTF8(*this->token));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketReplicationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketReplicationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketReplicationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->replicationConfiguration.IsEmpty() && this->token.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
