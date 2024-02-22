/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CreateMultipartUploadResult.h"

#endif

#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTCreateMultipartUploadResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCreateMultipartUploadResult {
GENERATED_BODY()

    /**
    *  <p>If the bucket has a lifecycle rule configured with an action to abort incomplete multipart uploads and the prefix in the lifecycle rule matches the object name in the request, the response includes this header. The header indicates when the initiated multipart upload becomes eligible for an abort operation. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config"> Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a>.</p> <p>The response also includes the <code>x-amz-abort-rule-id</code> header that provides the ID of the lifecycle configuration rule that defines this action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime abortDate;

    /**
    *  <p>This header is returned along with the <code>x-amz-abort-date</code> header. It identifies the applicable lifecycle configuration rule that defines the action to abort incomplete multipart uploads.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString abortRuleId;

    /**
    *  <p>The name of the bucket to which the multipart upload was initiated. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>ID for the initiated multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uploadId;

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
    FAWSS3CRTCreateMultipartUploadResult &fromAWS(const Aws::S3Crt::Model::CreateMultipartUploadResult &awsCreateMultipartUploadResult) {
        this->abortDate = FDateTime(1970, 1, 1) + FTimespan(awsCreateMultipartUploadResult.GetAbortDate().Millis() * ETimespan::TicksPerMillisecond);

        this->abortRuleId = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetAbortRuleId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetBucket().c_str());

        this->key = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetKey().c_str());

        this->uploadId = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetUploadId().c_str());

        switch(awsCreateMultipartUploadResult.GetServerSideEncryption()) {
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

        this->sSECustomerAlgorithm = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSECustomerAlgorithm().c_str());

        this->sSECustomerKeyMD5 = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSECustomerKeyMD5().c_str());

        this->sSEKMSKeyId = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSEKMSKeyId().c_str());

        this->sSEKMSEncryptionContext = UTF8_TO_TCHAR(awsCreateMultipartUploadResult.GetSSEKMSEncryptionContext().c_str());

        this->bucketKeyEnabled = awsCreateMultipartUploadResult.GetBucketKeyEnabled();

        switch(awsCreateMultipartUploadResult.GetRequestCharged()) {
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
