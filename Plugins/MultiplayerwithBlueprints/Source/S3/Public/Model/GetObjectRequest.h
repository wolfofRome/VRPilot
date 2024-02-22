/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectRequest.h"

#endif

#include "Model/RequestPayer.h"
#include "Model/AWSS3ChecksumMode.h"

#include "GetObjectRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name containing the object. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using an Object Lambda access point the hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-object-lambda.<i>Region</i>.amazonaws.com.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Return the object only if its entity tag (ETag) is the same as the one specified; otherwise, return a 412 (precondition failed) error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString ifMatch;

    /**
    *  <p>Return the object only if it has been modified since the specified time; otherwise, return a 304 (not modified) error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime ifModifiedSince;

    /**
    *  <p>Return the object only if its entity tag (ETag) is different from the one specified; otherwise, return a 304 (not modified) error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString ifNoneMatch;

    /**
    *  <p>Return the object only if it has not been modified since the specified time; otherwise, return a 412 (precondition failed) error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime ifUnmodifiedSince;

    /**
    *  <p>Key of the object to get.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Downloads the specified range bytes of an object. For more information about the HTTP Range header, see <a href="https://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35">https://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35</a>.</p>  <p>Amazon S3 doesn't support retrieving multiple ranges of data per <code>GET</code> request.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString range;

    /**
    *  <p>Sets the <code>Cache-Control</code> header of the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString responseCacheControl;

    /**
    *  <p>Sets the <code>Content-Disposition</code> header of the response</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString responseContentDisposition;

    /**
    *  <p>Sets the <code>Content-Encoding</code> header of the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString responseContentEncoding;

    /**
    *  <p>Sets the <code>Content-Language</code> header of the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString responseContentLanguage;

    /**
    *  <p>Sets the <code>Content-Type</code> header of the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString responseContentType;

    /**
    *  <p>Sets the <code>Expires</code> header of the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime responseExpires;

    /**
    *  <p>VersionId used to reference a specific version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>Specifies the algorithm to use to when decrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 used to encrypt the data. This value is used to decrypt the object when recovering it and must match the one used when storing the data. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKeyMD5;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>Part number of the object being read. This is a positive integer between 1 and 10,000. Effectively performs a 'ranged' GET request for the part specified. Useful for downloading just a part of an object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partNumber = 0;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>To retrieve the checksum, this mode must be enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumMode checksumMode = EAWSS3ChecksumMode::NOT_SET;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::GetObjectRequest toAWS() const {
        Aws::S3::Model::GetObjectRequest awsGetObjectRequest;

		if (!(this->bucket.IsEmpty())) {
            awsGetObjectRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->ifMatch.IsEmpty())) {
            awsGetObjectRequest.SetIfMatch(TCHAR_TO_UTF8(*this->ifMatch));
        }

        if (!(this->ifModifiedSince.ToUnixTimestamp() <= 0)) {
            awsGetObjectRequest.SetIfModifiedSince(Aws::Utils::DateTime((int64_t)((this->ifModifiedSince - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->ifNoneMatch.IsEmpty())) {
            awsGetObjectRequest.SetIfNoneMatch(TCHAR_TO_UTF8(*this->ifNoneMatch));
        }

        if (!(this->ifUnmodifiedSince.ToUnixTimestamp() <= 0)) {
            awsGetObjectRequest.SetIfUnmodifiedSince(Aws::Utils::DateTime((int64_t)((this->ifUnmodifiedSince - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->key.IsEmpty())) {
            awsGetObjectRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		if (!(this->range.IsEmpty())) {
            awsGetObjectRequest.SetRange(TCHAR_TO_UTF8(*this->range));
        }

		if (!(this->responseCacheControl.IsEmpty())) {
            awsGetObjectRequest.SetResponseCacheControl(TCHAR_TO_UTF8(*this->responseCacheControl));
        }

		if (!(this->responseContentDisposition.IsEmpty())) {
            awsGetObjectRequest.SetResponseContentDisposition(TCHAR_TO_UTF8(*this->responseContentDisposition));
        }

		if (!(this->responseContentEncoding.IsEmpty())) {
            awsGetObjectRequest.SetResponseContentEncoding(TCHAR_TO_UTF8(*this->responseContentEncoding));
        }

		if (!(this->responseContentLanguage.IsEmpty())) {
            awsGetObjectRequest.SetResponseContentLanguage(TCHAR_TO_UTF8(*this->responseContentLanguage));
        }

		if (!(this->responseContentType.IsEmpty())) {
            awsGetObjectRequest.SetResponseContentType(TCHAR_TO_UTF8(*this->responseContentType));
        }

        if (!(this->responseExpires.ToUnixTimestamp() <= 0)) {
            awsGetObjectRequest.SetResponseExpires(Aws::Utils::DateTime((int64_t)((this->responseExpires - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->versionId.IsEmpty())) {
            awsGetObjectRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

		if (!(this->SSECustomerAlgorithm.IsEmpty())) {
            awsGetObjectRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->SSECustomerAlgorithm));
        }

		if (!(this->SSECustomerKey.IsEmpty())) {
            awsGetObjectRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->SSECustomerKey));
        }

		if (!(this->SSECustomerKeyMD5.IsEmpty())) {
            awsGetObjectRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->SSECustomerKeyMD5));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsGetObjectRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

        if (!(this->partNumber == 0)) {
            awsGetObjectRequest.SetPartNumber(this->partNumber);
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetObjectRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        switch(this->checksumMode) {
            case EAWSS3ChecksumMode::ENABLED:
                awsGetObjectRequest.SetChecksumMode(Aws::S3::Model::ChecksumMode::ENABLED);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetObjectRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetObjectRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->ifMatch.IsEmpty() && ifModifiedSince.ToUnixTimestamp() <= 0 && this->ifNoneMatch.IsEmpty() && ifUnmodifiedSince.ToUnixTimestamp() <= 0 && this->key.IsEmpty() && this->range.IsEmpty() && this->responseCacheControl.IsEmpty() && this->responseContentDisposition.IsEmpty() && this->responseContentEncoding.IsEmpty() && this->responseContentLanguage.IsEmpty() && this->responseContentType.IsEmpty() && responseExpires.ToUnixTimestamp() <= 0 && this->versionId.IsEmpty() && this->SSECustomerAlgorithm.IsEmpty() && this->SSECustomerKey.IsEmpty() && this->SSECustomerKeyMD5.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->partNumber == 0 && this->expectedBucketOwner.IsEmpty() && this->checksumMode == EAWSS3ChecksumMode::NOT_SET && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};