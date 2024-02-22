/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteObjectsRequest.h"

#endif

#include "Model/Delete.h"
#include "Model/RequestPayer.h"
#include "Model/AWSS3ChecksumAlgorithm.h"

#include "DeleteObjectsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteObjectsRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name containing the objects to delete. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Container for the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Delete deleteObject;

    /**
    *  <p>The concatenation of the authentication device's serial number, a space, and the value that is displayed on your authentication device. Required to permanently delete a versioned object if versioning is configured with MFA delete enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString mFA;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>Specifies whether you want to delete this object even if it has a Governance-type Object Lock in place. To use this header, you must have the <code>s3:BypassGovernanceRetention</code> permission.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bypassGovernanceRetention = false;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>Indicates the algorithm used to create the checksum for the object when using the SDK. This header will not provide any additional functionality if not using the SDK. When sending this header, there must be a corresponding <code>x-amz-checksum</code> or <code>x-amz-trailer</code> header sent. Otherwise, Amazon S3 fails the request with the HTTP status code <code>400 Bad Request</code>. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you provide an individual checksum, Amazon S3 ignores any provided <code>ChecksumAlgorithm</code> parameter.</p> <p>This checksum algorithm must be the same for all parts and it match the checksum value supplied in the <code>CreateMultipartUpload</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::DeleteObjectsRequest toAWS() const {
        Aws::S3::Model::DeleteObjectsRequest awsDeleteObjectsRequest;

		if (!(this->bucket.IsEmpty())) {
            awsDeleteObjectsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->deleteObject.IsEmpty())) {
            awsDeleteObjectsRequest.SetDelete(this->deleteObject.toAWS());
        }

		if (!(this->mFA.IsEmpty())) {
            awsDeleteObjectsRequest.SetMFA(TCHAR_TO_UTF8(*this->mFA));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsDeleteObjectsRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

        if (this->bypassGovernanceRetention) {
            awsDeleteObjectsRequest.SetBypassGovernanceRetention(this->bypassGovernanceRetention);
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeleteObjectsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsDeleteObjectsRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsDeleteObjectsRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsDeleteObjectsRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsDeleteObjectsRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteObjectsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteObjectsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->deleteObject.IsEmpty() && this->mFA.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && !(this->bypassGovernanceRetention) && this->expectedBucketOwner.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
