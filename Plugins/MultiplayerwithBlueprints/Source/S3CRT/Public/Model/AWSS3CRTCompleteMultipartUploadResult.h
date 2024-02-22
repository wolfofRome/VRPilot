/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CompleteMultipartUploadResult.h"

#endif

#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTCompleteMultipartUploadResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCompleteMultipartUploadResult {
GENERATED_BODY()

    /**
    *  <p>The URI that identifies the newly created object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString location;

    /**
    *  <p>The name of the bucket that contains the newly created object.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The object key of the newly created object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>If the object expiration is configured, this will contain the expiration date (expiry-date) and rule ID (rule-id). The value of rule-id is URL encoded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expiration;

    /**
    *  <p>Entity tag that identifies the newly created object's data. Objects with different object data will have different entity tags. The entity tag is an opaque string. The entity tag may or may not be an MD5 digest of the object data. If the entity tag is not an MD5 digest of the object data, it will contain one or more nonhexadecimal characters and/or will consist of less than 32 or more than 32 hexadecimal digits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>If you specified server-side encryption either with an Amazon S3-managed encryption key or an AWS KMS customer master key (CMK) in your initiate multipart upload request, the response includes this header. It confirms the encryption algorithm that Amazon S3 used to encrypt the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTServerSideEncryption serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;

    /**
    *  <p>Version ID of the newly created object, in case the bucket has versioning turned on.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

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
    FAWSS3CRTCompleteMultipartUploadResult &fromAWS(const Aws::S3Crt::Model::CompleteMultipartUploadResult &awsCompleteMultipartUploadResult) {
        this->location = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetLocation().c_str());

        this->bucket = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetBucket().c_str());

        this->key = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetKey().c_str());

        this->expiration = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetExpiration().c_str());

        this->eTag = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetETag().c_str());

        switch(awsCompleteMultipartUploadResult.GetServerSideEncryption()) {
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

        this->versionId = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetVersionId().c_str());

        this->sSEKMSKeyId = UTF8_TO_TCHAR(awsCompleteMultipartUploadResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsCompleteMultipartUploadResult.GetBucketKeyEnabled();

        switch(awsCompleteMultipartUploadResult.GetRequestCharged()) {
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
