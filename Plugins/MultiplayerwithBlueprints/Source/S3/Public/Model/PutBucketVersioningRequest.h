/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketVersioningRequest.h"

#endif

#include "Model/AWSS3ChecksumAlgorithm.h"
#include "Model/VersioningConfiguration.h"

#include "PutBucketVersioningRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutBucketVersioningRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>&gt;The base64-encoded 128-bit MD5 digest of the data. You must use this header as a message integrity check to verify that the request body was not corrupted in transit. For more information, see <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864</a>.</p> <p>For requests made using the Amazon Web Services Command Line Interface (CLI) or Amazon Web Services SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentMD5;

    /**
    *  <p>Indicates the algorithm used to create the checksum for the object when using the SDK. This header will not provide any additional functionality if not using the SDK. When sending this header, there must be a corresponding <code>x-amz-checksum</code> or <code>x-amz-trailer</code> header sent. Otherwise, Amazon S3 fails the request with the HTTP status code <code>400 Bad Request</code>. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you provide an individual checksum, Amazon S3 ignores any provided <code>ChecksumAlgorithm</code> parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

    /**
    *  <p>The concatenation of the authentication device's serial number, a space, and the value that is displayed on your authentication device.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString mFA;

    /**
    *  <p>Container for setting the versioning state.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FVersioningConfiguration versioningConfiguration;

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
    Aws::S3::Model::PutBucketVersioningRequest toAWS() const {
        Aws::S3::Model::PutBucketVersioningRequest awsPutBucketVersioningRequest;

		if (!(this->bucket.IsEmpty())) {
            awsPutBucketVersioningRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketVersioningRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsPutBucketVersioningRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsPutBucketVersioningRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsPutBucketVersioningRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsPutBucketVersioningRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        if (!(this->mFA.IsEmpty())) {
            awsPutBucketVersioningRequest.SetMFA(TCHAR_TO_UTF8(*this->mFA));
        }

        if (!(this->versioningConfiguration.IsEmpty())) {
            awsPutBucketVersioningRequest.SetVersioningConfiguration(this->versioningConfiguration.toAWS());
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketVersioningRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketVersioningRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketVersioningRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->mFA.IsEmpty() && this->versioningConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
