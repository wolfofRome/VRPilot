/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/UploadPartResult.h"

#endif

#include "Model/ServerSideEncryption.h"
#include "Model/RequestCharged.h"

#include "UploadPartResult.generated.h"

USTRUCT(BlueprintType)
struct FUploadPartResult {
GENERATED_BODY()

    /**
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption serverSideEncryption = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>Entity tag for the uploaded object.</p>
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
    *  <p>If present, specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetric customer managed key was used for the object.</p>
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
    FUploadPartResult &fromAWS(const Aws::S3::Model::UploadPartResult &awsUploadPartResult) {
        switch(awsUploadPartResult.GetServerSideEncryption()) {
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

        this->eTag = UTF8_TO_TCHAR(awsUploadPartResult.GetETag().c_str());

        this->checksumCRC32 = UTF8_TO_TCHAR(awsUploadPartResult.GetChecksumCRC32().c_str());

        this->checksumCRC32C = UTF8_TO_TCHAR(awsUploadPartResult.GetChecksumCRC32C().c_str());

        this->checksumSHA1 = UTF8_TO_TCHAR(awsUploadPartResult.GetChecksumSHA1().c_str());

        this->checksumSHA256 = UTF8_TO_TCHAR(awsUploadPartResult.GetChecksumSHA256().c_str());

        this->SSECustomerAlgorithm = UTF8_TO_TCHAR(awsUploadPartResult.GetSSECustomerAlgorithm().c_str());

        this->SSECustomerKeyMD5 = UTF8_TO_TCHAR(awsUploadPartResult.GetSSECustomerKeyMD5().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsUploadPartResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsUploadPartResult.GetBucketKeyEnabled();

        switch(awsUploadPartResult.GetRequestCharged()) {
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
