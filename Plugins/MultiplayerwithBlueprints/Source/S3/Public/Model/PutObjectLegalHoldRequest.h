/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutObjectLegalHoldRequest.h"

#endif

#include "Model/ObjectLockLegalHold.h"
#include "Model/RequestPayer.h"
#include "Model/AWSS3ChecksumAlgorithm.h"

#include "PutObjectLegalHoldRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutObjectLegalHoldRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name containing the object that you want to place a legal hold on. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The key name for the object that you want to place a legal hold on.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Container element for the legal hold configuration you want to apply to the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FObjectLockLegalHold legalHold;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>The version ID of the object that you want to place a legal hold on.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>The MD5 hash for the request body.</p> <p>For requests made using the Amazon Web Services Command Line Interface (CLI) or Amazon Web Services SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentMD5;

    /**
    *  <p>Indicates the algorithm used to create the checksum for the object when using the SDK. This header will not provide any additional functionality if not using the SDK. When sending this header, there must be a corresponding <code>x-amz-checksum</code> or <code>x-amz-trailer</code> header sent. Otherwise, Amazon S3 fails the request with the HTTP status code <code>400 Bad Request</code>. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you provide an individual checksum, Amazon S3 ignores any provided <code>ChecksumAlgorithm</code> parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

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
    Aws::S3::Model::PutObjectLegalHoldRequest toAWS() const {
        Aws::S3::Model::PutObjectLegalHoldRequest awsPutObjectLegalHoldRequest;

		if (!(this->bucket.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->key.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->legalHold.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetLegalHold(this->legalHold.toAWS());
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsPutObjectLegalHoldRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

		if (!(this->versionId.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsPutObjectLegalHoldRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsPutObjectLegalHoldRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsPutObjectLegalHoldRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsPutObjectLegalHoldRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutObjectLegalHoldRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutObjectLegalHoldRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->legalHold.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->versionId.IsEmpty() && this->contentMD5.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
