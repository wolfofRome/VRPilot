/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CopyObjectResult.h"

#endif

#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTRequestCharged.h"
#include "Model/AWSS3CRTCopyObjectResultDetails.h"

#include "AWSS3CRTCopyObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCopyObjectResult {
GENERATED_BODY()

    /**
    *  <p>If the object expiration is configured, the response includes this header.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expiration;

    /**
    *  <p>Version of the copied object in the destination bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceVersionId;

    /**
    *  <p>Version ID of the newly created copy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTServerSideEncryption serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSKeyId;

    /**
    *  <p>If present, specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSEncryptionContext;

    /**
    *  <p>Indicates whether the copied object uses an S3 Bucket Key for server-side encryption with AWS KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

    /**
    *  <p>Container for all response elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCopyObjectResultDetails copyObjectResultDetails;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTCopyObjectResult &fromAWS(const Aws::S3Crt::Model::CopyObjectResult &awsCopyObjectResult) {
        this->expiration = UTF8_TO_TCHAR(awsCopyObjectResult.GetExpiration().c_str());

        this->copySourceVersionId = UTF8_TO_TCHAR(awsCopyObjectResult.GetCopySourceVersionId().c_str());

        this->versionId = UTF8_TO_TCHAR(awsCopyObjectResult.GetVersionId().c_str());

        switch(awsCopyObjectResult.GetServerSideEncryption()) {
            case Aws::S3Crt::Model::ServerSideEncryption::NOT_SET:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;
                break;
            case Aws::S3Crt::Model::ServerSideEncryption::AES256:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::AES256;
                break;
            case Aws::S3Crt::Model::ServerSideEncryption::aws_kms:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::aws_kms;
                break;
            default:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;
                break;
        }

        this->sSECustomerAlgorithm = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSECustomerAlgorithm().c_str());

        this->sSECustomerKeyMD5 = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSECustomerKeyMD5().c_str());

        this->sSEKMSKeyId = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSEKMSKeyId().c_str());

        this->sSEKMSEncryptionContext = UTF8_TO_TCHAR(awsCopyObjectResult.GetSSEKMSEncryptionContext().c_str());

        this->bucketKeyEnabled = awsCopyObjectResult.GetBucketKeyEnabled();

        switch(awsCopyObjectResult.GetRequestCharged()) {
            case Aws::S3Crt::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
            case Aws::S3Crt::Model::RequestCharged::requester:
                this->requestCharged = EAWSS3CRTRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
        }

        this->copyObjectResultDetails = FAWSS3CRTCopyObjectResultDetails().fromAWS(awsCopyObjectResult.GetCopyObjectResultDetails());

        return *this;
    }
#endif
};
