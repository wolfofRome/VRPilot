/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/UploadPartCopyResult.h"

#endif

#include "Model/AWSS3CRTCopyPartResult.h"
#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTUploadPartCopyResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTUploadPartCopyResult {
GENERATED_BODY()

    /**
    *  <p>The version of the source object that was copied, if you have enabled versioning on the source bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceVersionId;

    /**
    *  <p>Container for all response elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCopyPartResult copyPartResult;

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
    *  <p>Indicates whether the multipart upload uses an S3 Bucket Key for server-side encryption with AWS KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTUploadPartCopyResult &fromAWS(const Aws::S3Crt::Model::UploadPartCopyResult &awsUploadPartCopyResult) {
        this->copySourceVersionId = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetCopySourceVersionId().c_str());

        this->copyPartResult = FAWSS3CRTCopyPartResult().fromAWS(awsUploadPartCopyResult.GetCopyPartResult());

        switch(awsUploadPartCopyResult.GetServerSideEncryption()) {
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

        this->sSECustomerAlgorithm = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetSSECustomerAlgorithm().c_str());

        this->sSECustomerKeyMD5 = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetSSECustomerKeyMD5().c_str());

        this->sSEKMSKeyId = UTF8_TO_TCHAR(awsUploadPartCopyResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsUploadPartCopyResult.GetBucketKeyEnabled();

        switch(awsUploadPartCopyResult.GetRequestCharged()) {
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

        return *this;
    }
#endif
};
