/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/UploadPartCopyResult.h"

#endif

#include "Model/CopyPartResult.h"
#include "Model/ServerSideEncryption.h"
#include "Model/RequestCharged.h"

#include "UploadPartCopyResult.generated.h"

USTRUCT(BlueprintType)
struct FUploadPartCopyResult {
GENERATED_BODY()

    /**
    *  <p>The version of the source object that was copied, if you have enabled versioning on the source bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceVersionId;

    /**
    *  <p>Container for all response elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FCopyPartResult copyPartResult;

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
    *  <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>Indicates whether the multipart upload uses an S3 Bucket Key for server-side encryption with AWS KMS (SSE-KMS).</p>
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
    FUploadPartCopyResult &fromAWS(const Aws::S3::Model::UploadPartCopyResult &awsUploadPartCopyResult) {
        this->copySourceVersionId = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetCopySourceVersionId().c_str());

        this->copyPartResult.fromAWS(awsUploadPartCopyResult.GetCopyPartResult());

        switch(awsUploadPartCopyResult.GetServerSideEncryption()) {
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

        this->SSECustomerAlgorithm = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetSSECustomerAlgorithm().c_str());

        this->SSECustomerKeyMD5 = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetSSECustomerKeyMD5().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsUploadPartCopyResult.GetBucketKeyEnabled();

        switch(awsUploadPartCopyResult.GetRequestCharged()) {
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
