/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CreateMultipartUploadRequest.h"

#endif

#include "Model/AWSS3CRTObjectCannedACL.h"
#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTRequestPayer.h"
#include "Model/AWSS3CRTObjectLockMode.h"
#include "Model/AWSS3CRTObjectLockLegalHoldStatus.h"

#include "AWSS3CRTCreateMultipartUploadRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCreateMultipartUploadRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectCannedACL aCL = EAWSS3CRTObjectCannedACL::NOT_SET;

    /**
    *  <p>The name of the bucket to which to initiate the upload</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Specifies caching behavior along the request/reply chain.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString cacheControl;

    /**
    *  <p>Specifies presentational information for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentDisposition;

    /**
    *  <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentEncoding;

    /**
    *  <p>The language the content is in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentLanguage;

    /**
    *  <p>A standard MIME type describing the format of the object data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentType;

    /**
    *  <p>The date and time at which the object is no longer cacheable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime expires;

    /**
    *  <p>Gives the grantee READ, READ_ACP, and WRITE_ACP permissions on the object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantFullControl;

    /**
    *  <p>Allows grantee to read the object data and its metadata.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantRead;

    /**
    *  <p>Allows grantee to read the object ACL.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantReadACP;

    /**
    *  <p>Allows grantee to write the ACL for the applicable object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantWriteACP;

    /**
    *  <p>Object key for which the multipart upload is to be initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTServerSideEncryption serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;

    /**
    *  <p>By default, Amazon S3 uses the STANDARD Storage Class to store newly created objects. The STANDARD storage class provides high durability and high availability. Depending on performance needs, you can specify a different Storage Class. Amazon S3 on Outposts only uses the OUTPOSTS Storage Class. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a> in the <i>Amazon S3 Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    *  <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString websiteRedirectLocation;

    /**
    *  <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p>Specifies the ID of the symmetric customer managed AWS KMS CMK to use for object encryption. All GET and PUT requests for an object protected by AWS KMS will fail if not made via SSL or using SigV4. For information about configuring using any of the officially supported AWS SDKs and AWS CLI, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingAWSSDK.html#specify-signature-version">Specifying the Signature Version in Request Authentication</a> in the <i>Amazon S3 Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSKeyId;

    /**
    *  <p>Specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSEncryptionContext;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption with server-side encryption using AWS KMS (SSE-KMS). Setting this header to <code>true</code> causes Amazon S3 to use an S3 Bucket Key for object encryption with SSE-KMS.</p> <p>Specifying this header with an object action doesn’t affect bucket-level settings for S3 Bucket Key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>The tag-set for the object. The tag-set must be encoded as URL Query parameters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString tagging;

    /**
    *  <p>Specifies the Object Lock mode that you want to apply to the uploaded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockMode objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;

    /**
    *  <p>Specifies the date and time when you want the Object Lock to expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether you want to apply a Legal Hold to the uploaded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;

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
    Aws::S3Crt::Model::CreateMultipartUploadRequest toAWS() const {
        Aws::S3Crt::Model::CreateMultipartUploadRequest awsCreateMultipartUploadRequest;

        switch(this->aCL) {
            case EAWSS3CRTObjectCannedACL::private_:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::private_);
                break;
            case EAWSS3CRTObjectCannedACL::public_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::public_read);
                break;
            case EAWSS3CRTObjectCannedACL::public_read_write:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSS3CRTObjectCannedACL::authenticated_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSS3CRTObjectCannedACL::aws_exec_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_full_control:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_full_control);
                break;
            default:
                break;
        }

        if (!(this->bucket.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->cacheControl.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetCacheControl(TCHAR_TO_UTF8(*this->cacheControl));
        }

        if (!(this->contentDisposition.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetContentDisposition(TCHAR_TO_UTF8(*this->contentDisposition));
        }

        if (!(this->contentEncoding.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetContentEncoding(TCHAR_TO_UTF8(*this->contentEncoding));
        }

        if (!(this->contentLanguage.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetContentLanguage(TCHAR_TO_UTF8(*this->contentLanguage));
        }

		if (!(this->contentType.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetContentType(TCHAR_TO_UTF8(*this->contentType));
        }

		if (!(this->expires.ToUnixTimestamp() <= 0)) {
            awsCreateMultipartUploadRequest.SetExpires(Aws::Utils::DateTime((int64_t)((this->expires - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->grantFullControl.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetGrantFullControl(TCHAR_TO_UTF8(*this->grantFullControl));
        }

		if (!(this->grantRead.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetGrantRead(TCHAR_TO_UTF8(*this->grantRead));
        }

		if (!(this->grantReadACP.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetGrantReadACP(TCHAR_TO_UTF8(*this->grantReadACP));
        }

		if (!(this->grantWriteACP.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetGrantWriteACP(TCHAR_TO_UTF8(*this->grantWriteACP));
        }

		if (!(this->key.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		for (const TPair<FString, FString>& elem : this->metadata) {
            awsCreateMultipartUploadRequest.AddMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

		switch(this->serverSideEncryption) {
            case EAWSS3CRTServerSideEncryption::AES256:
                awsCreateMultipartUploadRequest.SetServerSideEncryption(Aws::S3Crt::Model::ServerSideEncryption::AES256);
                break;
            case EAWSS3CRTServerSideEncryption::aws_kms:
                awsCreateMultipartUploadRequest.SetServerSideEncryption(Aws::S3Crt::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
		}

		switch(this->storageClass) {
            case EAWSS3CRTStorageClass::STANDARD:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD);
                break;
            case EAWSS3CRTStorageClass::REDUCED_REDUNDANCY:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3CRTStorageClass::STANDARD_IA:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTStorageClass::ONEZONE_IA:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTStorageClass::INTELLIGENT_TIERING:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTStorageClass::GLACIER:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::GLACIER);
                break;
            case EAWSS3CRTStorageClass::DEEP_ARCHIVE:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3CRTStorageClass::OUTPOSTS:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::OUTPOSTS);
                break;
            default:
                break;
		}

		if (!(this->websiteRedirectLocation.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetWebsiteRedirectLocation(TCHAR_TO_UTF8(*this->websiteRedirectLocation));
        }

		if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

		if (!(this->sSECustomerKey.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->sSECustomerKey));
        }

		if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

		if (!(this->sSEKMSKeyId.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSEKMSKeyId(TCHAR_TO_UTF8(*this->sSEKMSKeyId));
        }

		if (!(this->sSEKMSEncryptionContext.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSEKMSEncryptionContext(TCHAR_TO_UTF8(*this->sSEKMSEncryptionContext));
        }

		if (!(false)) {
            awsCreateMultipartUploadRequest.SetBucketKeyEnabled(this->bucketKeyEnabled);
        }

		switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsCreateMultipartUploadRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->tagging.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetTagging(TCHAR_TO_UTF8(*this->tagging));
        }

		switch(this->objectLockMode) {
            case EAWSS3CRTObjectLockMode::GOVERNANCE:
                awsCreateMultipartUploadRequest.SetObjectLockMode(Aws::S3Crt::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSS3CRTObjectLockMode::COMPLIANCE:
                awsCreateMultipartUploadRequest.SetObjectLockMode(Aws::S3Crt::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
		}

		if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsCreateMultipartUploadRequest.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		switch(this->objectLockLegalHoldStatus) {
            case EAWSS3CRTObjectLockLegalHoldStatus::ON:
                awsCreateMultipartUploadRequest.SetObjectLockLegalHoldStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSS3CRTObjectLockLegalHoldStatus::OFF:
                awsCreateMultipartUploadRequest.SetObjectLockLegalHoldStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
		}

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsCreateMultipartUploadRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

		return awsCreateMultipartUploadRequest;
    }

    bool IsEmpty() const {
        return this->aCL == EAWSS3CRTObjectCannedACL::NOT_SET && this->bucket.IsEmpty() && this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentType.IsEmpty() && this->expires.ToUnixTimestamp() <= 0 && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWriteACP.IsEmpty() && this->key.IsEmpty() && this->metadata.Num() == 0 && this->serverSideEncryption == EAWSS3CRTServerSideEncryption::NOT_SET && this->storageClass == EAWSS3CRTStorageClass::NOT_SET && this->websiteRedirectLocation.IsEmpty() && this->sSECustomerAlgorithm.IsEmpty() && this->sSECustomerKey.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->sSEKMSKeyId.IsEmpty() && this->sSEKMSEncryptionContext.IsEmpty() && false && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->tagging.IsEmpty() && this->objectLockMode == EAWSS3CRTObjectLockMode::NOT_SET && this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && this->objectLockLegalHoldStatus == EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
