/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketRequestPaymentRequest.h"

#endif

#include "Model/AWSS3ChecksumAlgorithm.h"
#include "Model/RequestPaymentConfiguration.h"

#include "PutBucketRequestPaymentRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutBucketRequestPaymentRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the data. You must use this header as a message integrity check to verify that the request body was not corrupted in transit. For more information, see <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864</a>.</p> <p>For requests made using the Amazon Web Services Command Line Interface (CLI) or Amazon Web Services SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentMD5;

    /**
    *  <p>Indicates the algorithm used to create the checksum for the object when using the SDK. This header will not provide any additional functionality if not using the SDK. When sending this header, there must be a corresponding <code>x-amz-checksum</code> or <code>x-amz-trailer</code> header sent. Otherwise, Amazon S3 fails the request with the HTTP status code <code>400 Bad Request</code>. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you provide an individual checksum, Amazon S3 ignores any provided <code>ChecksumAlgorithm</code> parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

    /**
    *  <p>Container for Payer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FRequestPaymentConfiguration requestPaymentConfiguration;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
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
    Aws::S3::Model::PutBucketRequestPaymentRequest toAWS() const {
        Aws::S3::Model::PutBucketRequestPaymentRequest awsPutBucketRequestPaymentRequest;

		if (!(this->bucket.IsEmpty())) {
            awsPutBucketRequestPaymentRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketRequestPaymentRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsPutBucketRequestPaymentRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsPutBucketRequestPaymentRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsPutBucketRequestPaymentRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsPutBucketRequestPaymentRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
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
        return this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->requestPaymentConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
