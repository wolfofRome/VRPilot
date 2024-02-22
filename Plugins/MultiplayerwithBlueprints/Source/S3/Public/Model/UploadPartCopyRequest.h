/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/UploadPartCopyRequest.h"

#endif

#include "Model/RequestPayer.h"

#include "UploadPartCopyRequest.generated.h"

USTRUCT(BlueprintType)
struct FUploadPartCopyRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The name of the source bucket and key name of the source object, separated by a slash (/). Must be URL-encoded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySource;

    /**
    *  <p>Copies the object if its entity tag (ETag) matches the specified tag.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceIfMatch;

    /**
    *  <p>Copies the object if it has been modified since the specified time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime copySourceIfModifiedSince;

    /**
    *  <p>Copies the object if its entity tag (ETag) is different than the specified ETag.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceIfNoneMatch;

    /**
    *  <p>Copies the object if it hasn't been modified since the specified time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime copySourceIfUnmodifiedSince;

    /**
    *  <p>The range of bytes to copy from the source object. The range value must use the form bytes=first-last, where the first and last are the zero-based byte offsets to copy. For example, bytes=0-9 indicates that you want to copy the first 10 bytes of the source. You can copy a range only if the source object is greater than 5 MB.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceRange;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Part number of part being copied. This is a positive integer between 1 and 10,000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partNumber = 0;

    /**
    *  <p>Upload ID identifying the multipart upload whose part is being copied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uploadId;

    /**
    *  <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side​-encryption​-customer-algorithm</code> header. This must be the same encryption key specified in the initiate multipart upload request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKeyMD5;

    /**
    *  <p>Specifies the algorithm to use when decrypting the source object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceSSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use to decrypt the source object. The encryption key provided in this header must be one that was used when the source object was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceSSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString copySourceSSECustomerKeyMD5;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>The account ID of the expected source bucket owner. If the source bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedSourceBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::UploadPartCopyRequest toAWS() const {
        Aws::S3::Model::UploadPartCopyRequest awsUploadPartCopyRequest;

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

		if (!(this->SSECustomerAlgorithm.IsEmpty())) {
            awsUploadPartCopyRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->SSECustomerAlgorithm));
        }

		if (!(this->SSECustomerKey.IsEmpty())) {
            awsUploadPartCopyRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->SSECustomerKey));
        }

		if (!(this->SSECustomerKeyMD5.IsEmpty())) {
            awsUploadPartCopyRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->SSECustomerKeyMD5));
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
            case EAWSRequestPayer::requester:
                awsUploadPartCopyRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
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
        return this->bucket.IsEmpty() && this->copySource.IsEmpty() && this->copySourceIfMatch.IsEmpty() && copySourceIfModifiedSince.ToUnixTimestamp() <= 0 && this->copySourceIfNoneMatch.IsEmpty() && copySourceIfUnmodifiedSince.ToUnixTimestamp() <= 0 && this->copySourceRange.IsEmpty() && this->key.IsEmpty() && this->partNumber == 0 && this->uploadId.IsEmpty() && this->SSECustomerAlgorithm.IsEmpty() && this->SSECustomerKey.IsEmpty() && this->SSECustomerKeyMD5.IsEmpty() && this->copySourceSSECustomerAlgorithm.IsEmpty() && this->copySourceSSECustomerKey.IsEmpty() && this->copySourceSSECustomerKeyMD5.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->expectedSourceBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
