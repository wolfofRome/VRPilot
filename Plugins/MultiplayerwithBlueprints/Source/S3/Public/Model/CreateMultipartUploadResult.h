/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CreateMultipartUploadResult.h"

#endif

#include "Model/ServerSideEncryption.h"
#include "Model/RequestCharged.h"
#include "Model/AWSS3ChecksumAlgorithm.h"

#include "CreateMultipartUploadResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateMultipartUploadResult {
GENERATED_BODY()

    /**
    *  <p>If the bucket has a lifecycle rule configured with an action to abort incomplete multipart uploads and the prefix in the lifecycle rule matches the object name in the request, the response includes this header. The header indicates when the initiated multipart upload becomes eligible for an abort operation. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config"> Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a>.</p> <p>The response also includes the <code>x-amz-abort-rule-id</code> header that provides the ID of the lifecycle configuration rule that defines this action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime abortDate;

    /**
    *  <p>This header is returned along with the <code>x-amz-abort-date</code> header. It identifies the applicable lifecycle configuration rule that defines the action to abort incomplete multipart uploads.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString abortRuleId;

    /**
    *  <p>The name of the bucket to which the multipart upload was initiated. Does not return the access point ARN or access point alias if used.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>ID for the initiated multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uploadId;

    /**
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption serverSideEncryption = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerAlgorithm;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKeyMD5;

    /**
    *  <p>If present, specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetric customer managed key that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>If present, specifies the Amazon Web Services KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSEncryptionContext;

    /**
    *  <p>Indicates whether the multipart upload uses an S3 Bucket Key for server-side encryption with Amazon Web Services KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>The algorithm that was used to create a checksum of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FCreateMultipartUploadResult &fromAWS(const Aws::S3::Model::CreateMultipartUploadResult &awsCreateMultipartUploadResult) {
        this->abortDate = FDateTime(1970, 1, 1) + FTimespan(awsCreateMultipartUploadResult.GetAbortDate().Millis() * ETimespan::TicksPerMillisecond);

        this->abortRuleId = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetAbortRuleId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetBucket().c_str());

        this->key = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetKey().c_str());

        this->uploadId = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetUploadId().c_str());

        switch(awsCreateMultipartUploadResult.GetServerSideEncryption()) {
            case Aws::S3::Model::ServerSideEncryption::NOT_SET:
                this->serverSideEncryption = EAWSServerSideEncryption::NOT_SET;
                break;
            case Aws::S3::Model::ServerSideEncryption::AES256:
                this->serverSideEncryption = EAWSServerSideEncryption::AES256;
                break;
            case Aws::S3::Model::ServerSideEncryption::aws_kms:
                this->serverSideEncryption = EAWSServerSideEncryption::aws_kms;
                break;
            default:
                this->serverSideEncryption = EAWSServerSideEncryption::NOT_SET;
                break;
        }

        this->SSECustomerAlgorithm = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSECustomerAlgorithm().c_str());

        this->SSECustomerKeyMD5 = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSECustomerKeyMD5().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSEKMSKeyId().c_str());

        this->SSEKMSEncryptionContext = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSEKMSEncryptionContext().c_str());

        this->bucketKeyEnabled = awsCreateMultipartUploadResult.GetBucketKeyEnabled();

        switch(awsCreateMultipartUploadResult.GetRequestCharged()) {
            case Aws::S3::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
            case Aws::S3::Model::RequestCharged::requester:
                this->requestCharged = EAWSRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
        }

        switch(awsCreateMultipartUploadResult.GetChecksumAlgorithm()) {
            case Aws::S3::Model::ChecksumAlgorithm::NOT_SET:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::CRC32:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::CRC32;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::CRC32C:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::CRC32C;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::SHA1:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::SHA1;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::SHA256:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::SHA256;
                break;
            default:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
