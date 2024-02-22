/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/UploadPartCopyRequest.h"

#endif

#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTUploadPartCopyRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTUploadPartCopyRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Specifies the source object for the copy operation. You specify the value in one of two formats, depending on whether you want to access the source object through an <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/access-points.html">access point</a>:</p> <ul> <li> <p>For objects not accessed through an access point, specify the name of the source bucket and key of the source object, separated by a slash (/). For example, to copy the object <code>reports/january.pdf</code> from the bucket <code>awsexamplebucket</code>, use <code>awsexamplebucket/reports/january.pdf</code>. The value must be URL encoded.</p> </li> <li> <p>For objects accessed through access points, specify the Amazon Resource Name (ARN) of the object as accessed through the access point, in the format <code>arn:aws:s3:&lt;Region&gt;:&lt;account-id&gt;:accesspoint/&lt;access-point-name&gt;/object/&lt;key&gt;</code>. For example, to copy the object <code>reports/january.pdf</code> through access point <code>my-access-point</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3:us-west-2:123456789012:accesspoint/my-access-point/object/reports/january.pdf</code>. The value must be URL encoded.</p>  <p>Amazon S3 supports copy operations using access points only when the source and destination buckets are in the same AWS Region.</p>  <p>Alternatively, for objects accessed through Amazon S3 on Outposts, specify the ARN of the object as accessed in the format <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/object/&lt;key&gt;</code>. For example, to copy the object <code>reports/january.pdf</code> through outpost <code>my-outpost</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/object/reports/january.pdf</code>. The value must be URL encoded. </p> </li> </ul> <p>To copy a specific version of an object, append <code>?versionId=&lt;version-id&gt;</code> to the value (for example, <code>awsexamplebucket/reports/january.pdf?versionId=QUpfdndhfd8438MNFDN93jdnJFkdmqnh893</code>). If you don't specify a version ID, Amazon S3 copies the latest version of the source object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySource;

    /**
    *  <p>Copies the object if its entity tag (ETag) matches the specified tag.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceIfMatch;

    /**
    *  <p>Copies the object if it has been modified since the specified time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime copySourceIfModifiedSince;

    /**
    *  <p>Copies the object if its entity tag (ETag) is different than the specified ETag.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceIfNoneMatch;

    /**
    *  <p>Copies the object if it hasn't been modified since the specified time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime copySourceIfUnmodifiedSince;

    /**
    *  <p>The range of bytes to copy from the source object. The range value must use the form bytes=first-last, where the first and last are the zero-based byte offsets to copy. For example, bytes=0-9 indicates that you want to copy the first 10 bytes of the source. You can copy a range only if the source object is greater than 5 MB.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceRange;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Part number of part being copied. This is a positive integer between 1 and 10,000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partNumber = 0;

    /**
    *  <p>Upload ID identifying the multipart upload whose part is being copied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uploadId;

    /**
    *  <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header. This must be the same encryption key specified in the initiate multipart upload request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p>Specifies the algorithm to use when decrypting the source object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceSSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use to decrypt the source object. The encryption key provided in this header must be one that was used when the source object was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceSSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString copySourceSSECustomerKeyMD5;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>The account ID of the expected destination bucket owner. If the destination bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedBucketOwner;

    /**
    *  <p>The account ID of the expected source bucket owner. If the source bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedSourceBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::UploadPartCopyRequest toAWS() const {
        Aws::S3Crt::Model::UploadPartCopyRequest awsUploadPartCopyRequest;

        if (!(this->bucket.IsEmpty())) {
            awsUploadPartCopyRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->copySource.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySource(TCHAR_TO_UTF8(*this->copySource));
        }

        if (!(this->copySourceIfMatch.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySourceIfMatch(TCHAR_TO_UTF8(*this->copySourceIfMatch));
        }

        if (!(this->copySourceIfModifiedSince.ToUnixTimestamp() <= 0)) {
            awsUploadPartCopyRequest.SetCopySourceIfModifiedSince(Aws::Utils::DateTime((int64_t)((this->copySourceIfModifiedSince - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->copySourceIfNoneMatch.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySourceIfNoneMatch(TCHAR_TO_UTF8(*this->copySourceIfNoneMatch));
        }

        if (!(this->copySourceIfUnmodifiedSince.ToUnixTimestamp() <= 0)) {
            awsUploadPartCopyRequest.SetCopySourceIfUnmodifiedSince(Aws::Utils::DateTime((int64_t)((this->copySourceIfUnmodifiedSince - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->copySourceRange.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySourceRange(TCHAR_TO_UTF8(*this->copySourceRange));
        }

        if (!(this->key.IsEmpty())) {
            awsUploadPartCopyRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->partNumber == 0)) {
            awsUploadPartCopyRequest.SetPartNumber(this->partNumber);
        }

        if (!(this->uploadId.IsEmpty())) {
            awsUploadPartCopyRequest.SetUploadId(TCHAR_TO_UTF8(*this->uploadId));
        }

        if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsUploadPartCopyRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

        if (!(this->sSECustomerKey.IsEmpty())) {
            awsUploadPartCopyRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->sSECustomerKey));
        }

        if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsUploadPartCopyRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

        if (!(this->copySourceSSECustomerAlgorithm.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySourceSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->copySourceSSECustomerAlgorithm));
        }

        if (!(this->copySourceSSECustomerKey.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySourceSSECustomerKey(TCHAR_TO_UTF8(*this->copySourceSSECustomerKey));
        }

        if (!(this->copySourceSSECustomerKeyMD5.IsEmpty())) {
            awsUploadPartCopyRequest.SetCopySourceSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->copySourceSSECustomerKeyMD5));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsUploadPartCopyRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsUploadPartCopyRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        if (!(this->expectedSourceBucketOwner.IsEmpty())) {
            awsUploadPartCopyRequest.SetExpectedSourceBucketOwner(TCHAR_TO_UTF8(*this->expectedSourceBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsUploadPartCopyRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsUploadPartCopyRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->copySource.IsEmpty() && this->copySourceIfMatch.IsEmpty() && this->copySourceIfModifiedSince.ToUnixTimestamp() <= 0 && this->copySourceIfNoneMatch.IsEmpty() && this->copySourceIfUnmodifiedSince.ToUnixTimestamp() <= 0 && this->copySourceRange.IsEmpty() && this->key.IsEmpty() && this->partNumber == 0 && this->uploadId.IsEmpty() && this->sSECustomerAlgorithm.IsEmpty() && this->sSECustomerKey.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->copySourceSSECustomerAlgorithm.IsEmpty() && this->copySourceSSECustomerKey.IsEmpty() && this->copySourceSSECustomerKeyMD5.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->expectedSourceBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
