/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CopyObjectRequest.h"

#endif

#include "Model/ObjectCannedACL.h"
#include "Model/AWSS3ChecksumAlgorithm.h"
#include "Model/MetadataDirective.h"
#include "Model/TaggingDirective.h"
#include "Model/ServerSideEncryption.h"
#include "Model/AWSS3StorageClass.h"
#include "Model/RequestPayer.h"
#include "Model/ObjectLockMode.h"
#include "Model/ObjectLockLegalHoldStatus.h"

#include "CopyObjectRequest.generated.h"

USTRUCT(BlueprintType)
struct FCopyObjectRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the object.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectCannedACL ACL = EAWSObjectCannedACL::NOT_SET;

    /**
    *  <p>The name of the destination bucket.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Specifies caching behavior along the request/reply chain.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString cacheControl;

    /**
    *  <p>Indicates the algorithm you want Amazon S3 to use to create the checksum for the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

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
    *  <p>Specifies the source object for the copy operation. You specify the value in one of two formats, depending on whether you want to access the source object through an <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/access-points.html">access point</a>:</p> <ul> <li> <p>For objects not accessed through an access point, specify the name of the source bucket and the key of the source object, separated by a slash (/). For example, to copy the object <code>reports/january.pdf</code> from the bucket <code>awsexamplebucket</code>, use <code>awsexamplebucket/reports/january.pdf</code>. The value must be URL encoded.</p> </li> <li> <p>For objects accessed through access points, specify the Amazon Resource Name (ARN) of the object as accessed through the access point, in the format <code>arn:aws:s3:&lt;Region&gt;:&lt;account-id&gt;:accesspoint/&lt;access-point-name&gt;/object/&lt;key&gt;</code>. For example, to copy the object <code>reports/january.pdf</code> through access point <code>my-access-point</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3:us-west-2:123456789012:accesspoint/my-access-point/object/reports/january.pdf</code>. The value must be URL encoded.</p>  <p>Amazon S3 supports copy operations using access points only when the source and destination buckets are in the same AWS Region.</p>  <p>Alternatively, for objects accessed through Amazon S3 on Outposts, specify the ARN of the object as accessed in the format <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/object/&lt;key&gt;</code>. For example, to copy the object <code>reports/january.pdf</code> through outpost <code>my-outpost</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/object/reports/january.pdf</code>. The value must be URL encoded. </p> </li> </ul> <p>To copy a specific version of an object, append <code>?versionId=&lt;version-id&gt;</code> to the value (for example, <code>awsexamplebucket/reports/january.pdf?versionId=QUpfdndhfd8438MNFDN93jdnJFkdmqnh893</code>). If you don't specify a version ID, Amazon S3 copies the latest version of the source object.</p>
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
    *  <p>The key of the destination object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>Specifies whether the metadata is copied from the source object or replaced with metadata provided in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSMetadataDirective metadataDirective = EAWSMetadataDirective::NOT_SET;

    /**
    *  <p>Specifies whether the object tag-set are copied from the source object or replaced with tag-set provided in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSTaggingDirective taggingDirective = EAWSTaggingDirective::NOT_SET;

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
    *  <p>Specifies the Amazon Web Services KMS key ID to use for object encryption. All GET and PUT requests for an object protected by Amazon Web Services KMS will fail if not made via SSL or using SigV4. For information about configuring using any of the officially supported Amazon Web Services SDKs and Amazon Web Services CLI, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingAWSSDK.html#specify-signature-version">Specifying the Signature Version in Request Authentication</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>Specifies the Amazon Web Services KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSEncryptionContext;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption with server-side encryption using AWS KMS (SSE-KMS). Setting this header to <code>true</code> causes Amazon S3 to use an S3 Bucket Key for object encryption with SSE-KMS. </p> <p>Specifying this header with a COPY action doesn’t affect bucket-level settings for S3 Bucket Key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

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
    *  <p>The tag-set for the object destination object this value must be used in conjunction with the <code>TaggingDirective</code>. The tag-set must be encoded as URL Query parameters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString tagging;

    /**
    *  <p>The Object Lock mode that you want to apply to the copied object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockMode objectLockMode = EAWSObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when you want the copied object's Object Lock to expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether you want to apply a legal hold to the copied object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;

    /**
    *  <p>The account ID of the expected destination bucket owner. If the destination bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>The account ID of the expected source bucket owner. If the source bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
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
    Aws::S3::Model::CopyObjectRequest toAWS() const {
        Aws::S3::Model::CopyObjectRequest awsCopyObjectRequest;

        switch(this->ACL) {
            case EAWSObjectCannedACL::private_:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::private_);
                break;
            case EAWSObjectCannedACL::public_read:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::public_read);
                break;
            case EAWSObjectCannedACL::public_read_write:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSObjectCannedACL::authenticated_read:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSObjectCannedACL::aws_exec_read:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_read:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_full_control:
                awsCopyObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_full_control);
                break;
            default:
                break;
        }

		if (!(this->bucket.IsEmpty())) {
            awsCopyObjectRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->cacheControl.IsEmpty())) {
            awsCopyObjectRequest.SetCacheControl(TCHAR_TO_UTF8(*this->cacheControl));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsCopyObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsCopyObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsCopyObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsCopyObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        if (!(this->contentDisposition.IsEmpty())) {
            awsCopyObjectRequest.SetContentDisposition(TCHAR_TO_UTF8(*this->contentDisposition));
        }

		if (!(this->contentEncoding.IsEmpty())) {
            awsCopyObjectRequest.SetContentEncoding(TCHAR_TO_UTF8(*this->contentEncoding));
        }

		if (!(this->contentLanguage.IsEmpty())) {
            awsCopyObjectRequest.SetContentLanguage(TCHAR_TO_UTF8(*this->contentLanguage));
        }

		if (!(this->contentType.IsEmpty())) {
            awsCopyObjectRequest.SetContentType(TCHAR_TO_UTF8(*this->contentType));
        }

		if (!(this->copySource.IsEmpty())) {
            awsCopyObjectRequest.SetCopySource(TCHAR_TO_UTF8(*this->copySource));
        }

		if (!(this->copySourceIfMatch.IsEmpty())) {
            awsCopyObjectRequest.SetCopySourceIfMatch(TCHAR_TO_UTF8(*this->copySourceIfMatch));
        }

        if (!(this->copySourceIfModifiedSince.ToUnixTimestamp() <= 0)) {
            awsCopyObjectRequest.SetCopySourceIfModifiedSince(Aws::Utils::DateTime((int64_t)((this->copySourceIfModifiedSince - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->copySourceIfNoneMatch.IsEmpty())) {
            awsCopyObjectRequest.SetCopySourceIfNoneMatch(TCHAR_TO_UTF8(*this->copySourceIfNoneMatch));
        }

        if (!(this->copySourceIfUnmodifiedSince.ToUnixTimestamp() <= 0)) {
            awsCopyObjectRequest.SetCopySourceIfUnmodifiedSince(Aws::Utils::DateTime((int64_t)((this->copySourceIfUnmodifiedSince - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->expires.ToUnixTimestamp() <= 0)) {
            awsCopyObjectRequest.SetExpires(Aws::Utils::DateTime((int64_t)((this->expires - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->grantFullControl.IsEmpty())) {
            awsCopyObjectRequest.SetGrantFullControl(TCHAR_TO_UTF8(*this->grantFullControl));
        }

		if (!(this->grantRead.IsEmpty())) {
            awsCopyObjectRequest.SetGrantRead(TCHAR_TO_UTF8(*this->grantRead));
        }

		if (!(this->grantReadACP.IsEmpty())) {
            awsCopyObjectRequest.SetGrantReadACP(TCHAR_TO_UTF8(*this->grantReadACP));
        }

		if (!(this->grantWriteACP.IsEmpty())) {
            awsCopyObjectRequest.SetGrantWriteACP(TCHAR_TO_UTF8(*this->grantWriteACP));
        }

		if (!(this->key.IsEmpty())) {
            awsCopyObjectRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        for (const TPair<FString, FString>& elem : this->metadata) {
            awsCopyObjectRequest.AddMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        switch(this->metadataDirective) {
            case EAWSMetadataDirective::COPY:
                awsCopyObjectRequest.SetMetadataDirective(Aws::S3::Model::MetadataDirective::COPY);
                break;
            case EAWSMetadataDirective::REPLACE:
                awsCopyObjectRequest.SetMetadataDirective(Aws::S3::Model::MetadataDirective::REPLACE);
                break;
            default:
                break;
        }

        switch(this->taggingDirective) {
            case EAWSTaggingDirective::COPY:
                awsCopyObjectRequest.SetTaggingDirective(Aws::S3::Model::TaggingDirective::COPY);
                break;
            case EAWSTaggingDirective::REPLACE:
                awsCopyObjectRequest.SetTaggingDirective(Aws::S3::Model::TaggingDirective::REPLACE);
                break;
            default:
                break;
        }

        switch(this->serverSideEncryption) {
            case EAWSServerSideEncryption::AES256:
                awsCopyObjectRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::AES256);
                break;
            case EAWSServerSideEncryption::aws_kms:
                awsCopyObjectRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

        switch(this->storageClass) {
            case EAWSS3StorageClass::STANDARD:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD);
                break;
            case EAWSS3StorageClass::REDUCED_REDUNDANCY:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3StorageClass::STANDARD_IA:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3StorageClass::ONEZONE_IA:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3StorageClass::INTELLIGENT_TIERING:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3StorageClass::GLACIER:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER);
                break;
            case EAWSS3StorageClass::DEEP_ARCHIVE:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3StorageClass::OUTPOSTS:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::OUTPOSTS);
                break;
            case EAWSS3StorageClass::GLACIER_IR:
                awsCopyObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER_IR);
                break;
            default:
                break;
        }

		if (!(this->websiteRedirectLocation.IsEmpty())) {
            awsCopyObjectRequest.SetWebsiteRedirectLocation(TCHAR_TO_UTF8(*this->websiteRedirectLocation));
        }

		if (!(this->SSECustomerAlgorithm.IsEmpty())) {
            awsCopyObjectRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->SSECustomerAlgorithm));
        }

		if (!(this->SSECustomerKey.IsEmpty())) {
            awsCopyObjectRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->SSECustomerKey));
        }

		if (!(this->SSECustomerKeyMD5.IsEmpty())) {
            awsCopyObjectRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->SSECustomerKeyMD5));
        }

		if (!(this->SSEKMSKeyId.IsEmpty())) {
            awsCopyObjectRequest.SetSSEKMSKeyId(TCHAR_TO_UTF8(*this->SSEKMSKeyId));
        }

		if (!(this->SSEKMSEncryptionContext.IsEmpty())) {
            awsCopyObjectRequest.SetSSEKMSEncryptionContext(TCHAR_TO_UTF8(*this->SSEKMSEncryptionContext));
        }

        if (!(false)) {
            awsCopyObjectRequest.SetBucketKeyEnabled(this->bucketKeyEnabled);
        }

		if (!(this->copySourceSSECustomerAlgorithm.IsEmpty())) {
            awsCopyObjectRequest.SetCopySourceSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->copySourceSSECustomerAlgorithm));
        }

		if (!(this->copySourceSSECustomerKey.IsEmpty())) {
            awsCopyObjectRequest.SetCopySourceSSECustomerKey(TCHAR_TO_UTF8(*this->copySourceSSECustomerKey));
        }

		if (!(this->copySourceSSECustomerKeyMD5.IsEmpty())) {
            awsCopyObjectRequest.SetCopySourceSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->copySourceSSECustomerKeyMD5));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsCopyObjectRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->tagging.IsEmpty())) {
            awsCopyObjectRequest.SetTagging(TCHAR_TO_UTF8(*this->tagging));
        }

        switch(this->objectLockMode) {
            case EAWSObjectLockMode::GOVERNANCE:
                awsCopyObjectRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSObjectLockMode::COMPLIANCE:
                awsCopyObjectRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
		}

        if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsCopyObjectRequest.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSObjectLockLegalHoldStatus::ON:
                awsCopyObjectRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSObjectLockLegalHoldStatus::OFF:
                awsCopyObjectRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsCopyObjectRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		if (!(this->expectedSourceBucketOwner.IsEmpty())) {
            awsCopyObjectRequest.SetExpectedSourceBucketOwner(TCHAR_TO_UTF8(*this->expectedSourceBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsCopyObjectRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsCopyObjectRequest;
    }

    bool IsEmpty() const {
        return ACL == EAWSObjectCannedACL::NOT_SET && this->bucket.IsEmpty() && this->cacheControl.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentType.IsEmpty() && this->copySource.IsEmpty() && this->copySourceIfMatch.IsEmpty() && copySourceIfModifiedSince.ToUnixTimestamp() <= 0 && this->copySourceIfNoneMatch.IsEmpty() && copySourceIfUnmodifiedSince.ToUnixTimestamp() <= 0 && expires.ToUnixTimestamp() <= 0 && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWriteACP.IsEmpty() && this->key.IsEmpty() && this->metadata.Num() == 0 && metadataDirective == EAWSMetadataDirective::NOT_SET && taggingDirective == EAWSTaggingDirective::NOT_SET && serverSideEncryption == EAWSServerSideEncryption::NOT_SET && storageClass == EAWSS3StorageClass::NOT_SET && this->websiteRedirectLocation.IsEmpty() && this->SSECustomerAlgorithm.IsEmpty() && this->SSECustomerKey.IsEmpty() && this->SSECustomerKeyMD5.IsEmpty() && this->SSEKMSKeyId.IsEmpty() && this->SSEKMSEncryptionContext.IsEmpty() && false && this->copySourceSSECustomerAlgorithm.IsEmpty() && this->copySourceSSECustomerKey.IsEmpty() && this->copySourceSSECustomerKeyMD5.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->tagging.IsEmpty() && objectLockMode == EAWSObjectLockMode::NOT_SET && objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && objectLockLegalHoldStatus == EAWSObjectLockLegalHoldStatus::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->expectedSourceBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
