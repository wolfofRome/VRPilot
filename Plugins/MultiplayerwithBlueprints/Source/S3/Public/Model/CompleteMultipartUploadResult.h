/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CompleteMultipartUploadResult.h"

#endif

#include "Model/ServerSideEncryption.h"
#include "Model/RequestCharged.h"

#include "CompleteMultipartUploadResult.generated.h"

USTRUCT(BlueprintType)
struct FCompleteMultipartUploadResult {
GENERATED_BODY()

    /**
    *  <p>The URI that identifies the newly created object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString location;

    /**
    *  <p>The name of the bucket that contains the newly created object. Does not return the access point ARN or access point alias if used.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The object key of the newly created object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>If the object expiration is configured, this will contain the expiration date (<code>expiry-date</code>) and rule ID (<code>rule-id</code>). The value of <code>rule-id</code> is URL-encoded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expiration;

    /**
    *  <p>Entity tag that identifies the newly created object's data. Objects with different object data will have different entity tags. The entity tag is an opaque string. The entity tag may or may not be an MD5 digest of the object data. If the entity tag is not an MD5 digest of the object data, it will contain one or more nonhexadecimal characters and/or will consist of less than 32 or more than 32 hexadecimal digits. For more information about how the entity tag is calculated, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

    /**
    *  <p>The base64-encoded, 32-bit CRC32 checksum of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32;

    /**
    *  <p>The base64-encoded, 32-bit CRC32C checksum of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32C;

    /**
    *  <p>The base64-encoded, 160-bit SHA-1 digest of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA1;

    /**
    *  <p>The base64-encoded, 256-bit SHA-256 digest of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA256;

    /**
    *  <p>If you specified server-side encryption either with an Amazon S3-managed encryption key or an Amazon Web Services KMS key in your initiate multipart upload request, the response includes this header. It confirms the encryption algorithm that Amazon S3 used to encrypt the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption serverSideEncryption = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>Version ID of the newly created object, in case the bucket has versioning turned on.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>If present, specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetric customer managed key that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

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

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FCompleteMultipartUploadResult &fromAWS(const Aws::S3::Model::CompleteMultipartUploadResult &awsCompleteMultipartUploadResult) {
        this->location = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetLocation().c_str());

        this->bucket = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetBucket().c_str());

        this->key = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetKey().c_str());

        this->expiration = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetExpiration().c_str());

        this->eTag = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetETag().c_str());

        this->checksumCRC32 = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetChecksumCRC32().c_str());

        this->checksumCRC32C = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetChecksumCRC32C().c_str());

        this->checksumSHA1 = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetChecksumSHA1().c_str());

        this->checksumSHA256 = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetChecksumSHA256().c_str());

        switch(awsCompleteMultipartUploadResult.GetServerSideEncryption()) {
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

        this->versionId = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetVersionId().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsCompleteMultipartUploadResult.GetBucketKeyEnabled();

        switch(awsCompleteMultipartUploadResult.GetRequestCharged()) {
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

        return *this;
    }
#endif
};
