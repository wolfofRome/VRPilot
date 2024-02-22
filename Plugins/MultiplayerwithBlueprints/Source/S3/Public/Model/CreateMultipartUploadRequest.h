/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CreateMultipartUploadRequest.h"

#endif

#include "Model/ObjectCannedACL.h"
#include "Model/ServerSideEncryption.h"
#include "Model/AWSS3StorageClass.h"
#include "Model/RequestPayer.h"
#include "Model/ObjectLockMode.h"
#include "Model/ObjectLockLegalHoldStatus.h"
#include "Model/AWSS3ChecksumAlgorithm.h"

#include "CreateMultipartUploadRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateMultipartUploadRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectCannedACL ACL = EAWSObjectCannedACL::NOT_SET;

    /**
    *  <p>The name of the bucket to which to initiate the upload</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Specifies caching behavior along the request/reply chain.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString cacheControl;

    /**
    *  <p>Specifies presentational information for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentDisposition;

    /**
    *  <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentEncoding;

    /**
    *  <p>The language the content is in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentLanguage;

    /**
    *  <p>A standard MIME type describing the format of the object data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentType;

    /**
    *  <p>The date and time at which the object is no longer cacheable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime expires;

    /**
    *  <p>Gives the grantee READ, READ_ACP, and WRITE_ACP permissions on the object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantFullControl;

    /**
    *  <p>Allows grantee to read the object data and its metadata.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantRead;

    /**
    *  <p>Allows grantee to read the object ACL.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantReadACP;

    /**
    *  <p>Allows grantee to write the ACL for the applicable object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantWriteACP;

    /**
    *  <p>Object key for which the multipart upload is to be initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption serverSideEncryption = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>By default, Amazon S3 uses the STANDARD Storage Class to store newly created objects. The STANDARD storage class provides high durability and high availability. Depending on performance needs, you can specify a different Storage Class. Amazon S3 on Outposts only uses the OUTPOSTS Storage Class. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    *  <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString websiteRedirectLocation;

    /**
    *  <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKeyMD5;

    /**
    *  <p>Specifies the ID of the symmetric customer managed key to use for object encryption. All GET and PUT requests for an object protected by Amazon Web Services KMS will fail if not made via SSL or using SigV4. For information about configuring using any of the officially supported Amazon Web Services SDKs and Amazon Web Services CLI, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingAWSSDK.html#specify-signature-version">Specifying the Signature Version in Request Authentication</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>Specifies the Amazon Web Services KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSEncryptionContext;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption with server-side encryption using AWS KMS (SSE-KMS). Setting this header to <code>true</code> causes Amazon S3 to use an S3 Bucket Key for object encryption with SSE-KMS.</p> <p>Specifying this header with an object action doesn’t affect bucket-level settings for S3 Bucket Key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>The tag-set for the object. The tag-set must be encoded as URL Query parameters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString tagging;

    /**
    *  <p>Specifies the Object Lock mode that you want to apply to the uploaded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockMode objectLockMode = EAWSObjectLockMode::NOT_SET;

    /**
    *  <p>Specifies the date and time when you want the Object Lock to expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether you want to apply a legal hold to the uploaded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>Indicates the algorithm you want Amazon S3 to use to create the checksum for the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CreateMultipartUploadRequest toAWS() const {
        Aws::S3::Model::CreateMultipartUploadRequest awsCreateMultipartUploadRequest;

        switch(this->ACL) {
            case EAWSObjectCannedACL::private_:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::private_);
                break;
            case EAWSObjectCannedACL::public_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::public_read);
                break;
            case EAWSObjectCannedACL::public_read_write:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSObjectCannedACL::authenticated_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSObjectCannedACL::aws_exec_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_read:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_full_control:
                awsCreateMultipartUploadRequest.SetACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_full_control);
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
            case EAWSServerSideEncryption::AES256:
                awsCreateMultipartUploadRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::AES256);
                break;
            case EAWSServerSideEncryption::aws_kms:
                awsCreateMultipartUploadRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

        switch(this->storageClass) {
            case EAWSS3StorageClass::STANDARD:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD);
                break;
            case EAWSS3StorageClass::REDUCED_REDUNDANCY:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3StorageClass::STANDARD_IA:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3StorageClass::ONEZONE_IA:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3StorageClass::INTELLIGENT_TIERING:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3StorageClass::GLACIER:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER);
                break;
            case EAWSS3StorageClass::DEEP_ARCHIVE:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3StorageClass::OUTPOSTS:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::OUTPOSTS);
                break;
            case EAWSS3StorageClass::GLACIER_IR:
                awsCreateMultipartUploadRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER_IR);
                break;
            default:
                break;
        }

		if (!(this->websiteRedirectLocation.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetWebsiteRedirectLocation(TCHAR_TO_UTF8(*this->websiteRedirectLocation));
        }

		if (!(this->SSECustomerAlgorithm.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->SSECustomerAlgorithm));
        }

		if (!(this->SSECustomerKey.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->SSECustomerKey));
        }

		if (!(this->SSECustomerKeyMD5.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->SSECustomerKeyMD5));
        }

		if (!(this->SSEKMSKeyId.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSEKMSKeyId(TCHAR_TO_UTF8(*this->SSEKMSKeyId));
        }

		if (!(this->SSEKMSEncryptionContext.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetSSEKMSEncryptionContext(TCHAR_TO_UTF8(*this->SSEKMSEncryptionContext));
        }

        if (!(false)) {
            awsCreateMultipartUploadRequest.SetBucketKeyEnabled(this->bucketKeyEnabled);
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsCreateMultipartUploadRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->tagging.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetTagging(TCHAR_TO_UTF8(*this->tagging));
        }

        switch(this->objectLockMode) {
            case EAWSObjectLockMode::GOVERNANCE:
                awsCreateMultipartUploadRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSObjectLockMode::COMPLIANCE:
                awsCreateMultipartUploadRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
		}

        if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsCreateMultipartUploadRequest.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSObjectLockLegalHoldStatus::ON:
                awsCreateMultipartUploadRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSObjectLockLegalHoldStatus::OFF:
                awsCreateMultipartUploadRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsCreateMultipartUploadRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsCreateMultipartUploadRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsCreateMultipartUploadRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsCreateMultipartUploadRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsCreateMultipartUploadRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsCreateMultipartUploadRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsCreateMultipartUploadRequest;
    }

    bool IsEmpty() const {
        return ACL == EAWSObjectCannedACL::NOT_SET && this->bucket.IsEmpty() && this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentType.IsEmpty() && expires.ToUnixTimestamp() <= 0 && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWriteACP.IsEmpty() && this->key.IsEmpty() && this->metadata.Num() == 0 && serverSideEncryption == EAWSServerSideEncryption::NOT_SET && storageClass == EAWSS3StorageClass::NOT_SET && this->websiteRedirectLocation.IsEmpty() && this->SSECustomerAlgorithm.IsEmpty() && this->SSECustomerKey.IsEmpty() && this->SSECustomerKeyMD5.IsEmpty() && this->SSEKMSKeyId.IsEmpty() && this->SSEKMSEncryptionContext.IsEmpty() && false && this->requestPayer == EAWSRequestPayer::NOT_SET && this->tagging.IsEmpty() && objectLockMode == EAWSObjectLockMode::NOT_SET && objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && objectLockLegalHoldStatus == EAWSObjectLockLegalHoldStatus::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
