/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/UploadPartRequest.h"

#endif

#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTUploadPartRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTUploadPartRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket to which the multipart upload was initiated.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Size of the body in bytes. This parameter is useful when the size of the body cannot be determined automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 contentLength = 0;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the part data. This parameter is auto-populated when using the command from the CLI. This parameter is required if object lock parameters are specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Part number of part being uploaded. This is a positive integer between 1 and 10,000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partNumber = 0;

    /**
    *  <p>Upload ID identifying the multipart upload whose part is being uploaded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uploadId;

    /**
    *  <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm header</code>. This must be the same encryption key specified in the initiate multipart upload request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::UploadPartRequest toAWS() const {
        Aws::S3Crt::Model::UploadPartRequest awsUploadPartRequest;

        if (!(this->bucket.IsEmpty())) {
            awsUploadPartRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentLength == 0)) {
            awsUploadPartRequest.SetContentLength(this->contentLength);
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsUploadPartRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->key.IsEmpty())) {
            awsUploadPartRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->partNumber == 0)) {
            awsUploadPartRequest.SetPartNumber(this->partNumber);
        }

        if (!(this->uploadId.IsEmpty())) {
            awsUploadPartRequest.SetUploadId(TCHAR_TO_UTF8(*this->uploadId));
        }

        if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsUploadPartRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

        if (!(this->sSECustomerKey.IsEmpty())) {
            awsUploadPartRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->sSECustomerKey));
        }

        if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsUploadPartRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsUploadPartRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsUploadPartRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsUploadPartRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsUploadPartRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->contentLength == 0 && this->contentMD5.IsEmpty() && this->key.IsEmpty() && this->partNumber == 0 && this->uploadId.IsEmpty() && this->sSECustomerAlgorithm.IsEmpty() && this->sSECustomerKey.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
