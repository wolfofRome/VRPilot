/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketRequestPaymentRequest.h"

#endif

#include "Model/AWSS3CRTRequestPaymentConfiguration.h"

#include "AWSS3CRTPutBucketRequestPaymentRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketRequestPaymentRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the data. You must use this header as a message integrity check to verify that the request body was not corrupted in transit. For more information, see <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864</a>.</p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    *  <p>Container for Payer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTRequestPaymentConfiguration requestPaymentConfiguration;

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
    Aws::S3Crt::Model::PutBucketRequestPaymentRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketRequestPaymentRequest awsPutBucketRequestPaymentRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketRequestPaymentRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketRequestPaymentRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->requestPaymentConfiguration.IsEmpty())) {
            awsPutBucketRequestPaymentRequest.SetRequestPaymentConfiguration(this->requestPaymentConfiguration.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketRequestPaymentRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketRequestPaymentRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketRequestPaymentRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->requestPaymentConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
