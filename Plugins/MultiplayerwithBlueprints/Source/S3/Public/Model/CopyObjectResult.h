/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CopyObjectResult.h"

#endif

#include "Model/ServerSideEncryption.h"
#include "Model/RequestCharged.h"
#include "Model/CopyObjectResultDetails.h"

#include "CopyObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FCopyObjectResult {
GENERATED_BODY()

    /**
    *  <p>If the object expiration is configured, the response includes this header.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expiration;

    /**
    *  <p>Version of the copied object in the destination bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceVersionId;

    /**
    *  <p>Version ID of the newly created copy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

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
    *  <p>If present, specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSEncryptionContext;

    /**
    *  <p>Indicates whether the copied object uses an S3 Bucket Key for server-side encryption with AWS KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>Container for all response elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FCopyObjectResultDetails copyObjectResultDetails;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FCopyObjectResult &fromAWS(const Aws::S3::Model::CopyObjectResult &awsCopyObjectResult) {
        this->expiration = UTF8_TO_TCHAR(awsCopyObjectResult.GetExpiration().c_str());

        this->copySourceVersionId = UTF8_TO_TCHAR(awsCopyObjectResult.GetCopySourceVersionId().c_str());

        this->versionId = UTF8_TO_TCHAR(awsCopyObjectResult.GetVersionId().c_str());

        switch(awsCopyObjectResult.GetServerSideEncryption()) {
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

        this->SSECustomerAlgorithm = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSECustomerAlgorithm().c_str());

        this->SSECustomerKeyMD5 = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSECustomerKeyMD5().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSEKMSKeyId().c_str());

        this->SSEKMSEncryptionContext = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSEKMSEncryptionContext().c_str());

        this->bucketKeyEnabled = awsCopyObjectResult.GetBucketKeyEnabled();

        switch(awsCopyObjectResult.GetRequestCharged()) {
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

        this->copyObjectResultDetails.fromAWS(awsCopyObjectResult.GetCopyObjectResultDetails());

        return *this;
    }
#endif
};
