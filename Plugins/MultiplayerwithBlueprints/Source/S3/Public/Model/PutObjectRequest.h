/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/core/utils/memory/stl/AWSStreamFwd.h"
#include "aws/core/utils/memory/stl/AWSStringStream.h"
#include "aws/core/utils/FileSystemUtils.h"
#include "aws/s3/model/PutObjectRequest.h"

#endif

#include "Model/ObjectCannedACL.h"
#include "Model/AWSS3ChecksumAlgorithm.h"
#include "Model/ServerSideEncryption.h"
#include "Model/AWSS3StorageClass.h"
#include "Model/RequestPayer.h"
#include "Model/ObjectLockMode.h"
#include "Model/ObjectLockLegalHoldStatus.h"

#include "PutObjectRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutObjectRequest {
GENERATED_BODY()

    /**
    *  Indicate the file path. Absolute File Path
    *  or as content
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString file;

    /**
    *  <p>The canned ACL to apply to the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/acl-overview.html#CannedACL">Canned ACL</a>.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectCannedACL ACL = EAWSObjectCannedACL::NOT_SET;

    /**
    *  <p>The bucket name to which the PUT action was initiated. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p> Can be used to specify caching behavior along the request/reply chain. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString cacheControl;

    /**
    *  <p>Specifies presentational information for the object. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.5.1">http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.5.1</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentDisposition;

    /**
    *  <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.11">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.11</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentEncoding;

    /**
    *  <p>The language the content is in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentLanguage;

    /**
    *  <p>Size of the body in bytes. This parameter is useful when the size of the body cannot be determined automatically. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.13">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.13</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 contentLength = 0;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the message (without the headers) according to RFC 1864. This header can be used as a message integrity check to verify that the data is the same data that was originally sent. Although it is optional, we recommend using the Content-MD5 mechanism as an end-to-end integrity check. For more information about REST request authentication, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/RESTAuthentication.html">REST Authentication</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentMD5;

    /**
    *  <p>Indicates the algorithm used to create the checksum for the object when using the SDK. This header will not provide any additional functionality if not using the SDK. When sending this header, there must be a corresponding <code>x-amz-checksum</code> or <code>x-amz-trailer</code> header sent. Otherwise, Amazon S3 fails the request with the HTTP status code <code>400 Bad Request</code>. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you provide an individual checksum, Amazon S3 ignores any provided <code>ChecksumAlgorithm</code> parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This header specifies the base64-encoded, 32-bit CRC32 checksum of the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This header specifies the base64-encoded, 32-bit CRC32C checksum of the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32C;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This header specifies the base64-encoded, 160-bit SHA-1 digest of the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA1;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This header specifies the base64-encoded, 256-bit SHA-256 digest of the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA256;

    /**
    *  <p>The date and time at which the object is no longer cacheable. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.21">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.21</a>.</p>
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
    *  <p>Object key for which the PUT action was initiated.</p>
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
    *  <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata. For information about object metadata, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingMetadata.html">Object Key and Metadata</a>.</p> <p>In the following example, the request header sets the redirect to an object (anotherPage.html) in the same bucket:</p> <p> <code>x-amz-website-redirect-location: /anotherPage.html</code> </p> <p>In the following example, the request header sets the object redirect to another website:</p> <p> <code>x-amz-website-redirect-location: http://www.example.com/</code> </p> <p>For more information about website hosting in Amazon S3, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/WebsiteHosting.html">Hosting Websites on Amazon S3</a> and <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/how-to-page-redirect.html">How to Configure Website Page Redirects</a>. </p>
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
    *  <p>If <code>x-amz-server-side-encryption</code> is present and has the value of <code>aws:kms</code>, this header specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetrical customer managed key that was used for the object. If you specify <code>x-amz-server-side-encryption:aws:kms</code>, but do not provide<code> x-amz-server-side-encryption-aws-kms-key-id</code>, Amazon S3 uses the Amazon Web Services managed key to protect the data. If the KMS key does not exist in the same account issuing the command, you must use the full ARN and not just the ID. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>Specifies the Amazon Web Services KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSEncryptionContext;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption with server-side encryption using AWS KMS (SSE-KMS). Setting this header to <code>true</code> causes Amazon S3 to use an S3 Bucket Key for object encryption with SSE-KMS.</p> <p>Specifying this header with a PUT action doesn’t affect bucket-level settings for S3 Bucket Key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>The tag-set for the object. The tag-set must be encoded as URL Query parameters. (For example, "Key1=Value1")</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString tagging;

    /**
    *  <p>The Object Lock mode that you want to apply to this object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockMode objectLockMode = EAWSObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when you want this object's Object Lock to expire. Must be formatted as a timestamp parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether a legal hold will be applied to this object. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::PutObjectRequest toAWS() const {
        Aws::S3::Model::PutObjectRequest awsPutObjectRequest;

        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->file)) {
            std::shared_ptr<Aws::IOStream> awsBody = Aws::MakeShared<Aws::Utils::FStreamWithFileName>("s3", TCHAR_TO_UTF8(*this->file), std::ios_base::in | std::ios_base::binary);

            awsPutObjectRequest.SetBody(awsBody);
        } else {
            Aws::String content = TCHAR_TO_UTF8(*this->file);
            auto contentStream = Aws::MakeShared<Aws::StringStream>("s3");
            *contentStream << content;

            awsPutObjectRequest.SetBody(contentStream);
        }

        switch(this->ACL) {
            case EAWSObjectCannedACL::private_:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::private_);
                break;
            case EAWSObjectCannedACL::public_read:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::public_read);
                break;
            case EAWSObjectCannedACL::public_read_write:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSObjectCannedACL::authenticated_read:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSObjectCannedACL::aws_exec_read:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_read:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_full_control:
                awsPutObjectRequest.SetACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_full_control);
                break;
            default:
                break;
        }

		if (!(this->bucket.IsEmpty())) {
            awsPutObjectRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->cacheControl.IsEmpty())) {
            awsPutObjectRequest.SetCacheControl(TCHAR_TO_UTF8(*this->cacheControl));
        }

		if (!(this->contentDisposition.IsEmpty())) {
            awsPutObjectRequest.SetContentDisposition(TCHAR_TO_UTF8(*this->contentDisposition));
        }

		if (!(this->contentEncoding.IsEmpty())) {
            awsPutObjectRequest.SetContentEncoding(TCHAR_TO_UTF8(*this->contentEncoding));
        }

		if (!(this->contentLanguage.IsEmpty())) {
            awsPutObjectRequest.SetContentLanguage(TCHAR_TO_UTF8(*this->contentLanguage));
        }

        if (!(this->contentLength == 0)) {
            awsPutObjectRequest.SetContentLength(this->contentLength);
        }

		if (!(this->contentMD5.IsEmpty())) {
            awsPutObjectRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        switch(this->checksumAlgorithm) {
            case EAWSS3ChecksumAlgorithm::CRC32:
                awsPutObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ChecksumAlgorithm::CRC32C:
                awsPutObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ChecksumAlgorithm::SHA1:
                awsPutObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ChecksumAlgorithm::SHA256:
                awsPutObjectRequest.SetChecksumAlgorithm(Aws::S3::Model::ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        if (!(this->checksumCRC32.IsEmpty())) {
            awsPutObjectRequest.SetChecksumCRC32(TCHAR_TO_UTF8(*this->checksumCRC32));
        }

        if (!(this->checksumCRC32C.IsEmpty())) {
            awsPutObjectRequest.SetChecksumCRC32C(TCHAR_TO_UTF8(*this->checksumCRC32C));
        }

        if (!(this->checksumSHA1.IsEmpty())) {
            awsPutObjectRequest.SetChecksumSHA1(TCHAR_TO_UTF8(*this->checksumSHA1));
        }

        if (!(this->checksumSHA256.IsEmpty())) {
            awsPutObjectRequest.SetChecksumSHA256(TCHAR_TO_UTF8(*this->checksumSHA256));
        }

        if (!(this->expires.ToUnixTimestamp() <= 0)) {
            awsPutObjectRequest.SetExpires(Aws::Utils::DateTime((int64_t)((this->expires - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->grantFullControl.IsEmpty())) {
            awsPutObjectRequest.SetGrantFullControl(TCHAR_TO_UTF8(*this->grantFullControl));
        }

		if (!(this->grantRead.IsEmpty())) {
            awsPutObjectRequest.SetGrantRead(TCHAR_TO_UTF8(*this->grantRead));
        }

		if (!(this->grantReadACP.IsEmpty())) {
            awsPutObjectRequest.SetGrantReadACP(TCHAR_TO_UTF8(*this->grantReadACP));
        }

		if (!(this->grantWriteACP.IsEmpty())) {
            awsPutObjectRequest.SetGrantWriteACP(TCHAR_TO_UTF8(*this->grantWriteACP));
        }

		if (!(this->key.IsEmpty())) {
            awsPutObjectRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        for (const TPair<FString, FString>& elem : this->metadata) {
            awsPutObjectRequest.AddMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        switch(this->serverSideEncryption) {
            case EAWSServerSideEncryption::AES256:
                awsPutObjectRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::AES256);
                break;
            case EAWSServerSideEncryption::aws_kms:
                awsPutObjectRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

        switch(this->storageClass) {
            case EAWSS3StorageClass::STANDARD:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD);
                break;
            case EAWSS3StorageClass::REDUCED_REDUNDANCY:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3StorageClass::STANDARD_IA:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3StorageClass::ONEZONE_IA:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3StorageClass::INTELLIGENT_TIERING:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3StorageClass::GLACIER:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER);
                break;
            case EAWSS3StorageClass::DEEP_ARCHIVE:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3StorageClass::OUTPOSTS:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::OUTPOSTS);
                break;
            case EAWSS3StorageClass::GLACIER_IR:
                awsPutObjectRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER_IR);
                break;
            default:
                break;
        }

		if (!(this->websiteRedirectLocation.IsEmpty())) {
            awsPutObjectRequest.SetWebsiteRedirectLocation(TCHAR_TO_UTF8(*this->websiteRedirectLocation));
        }

		if (!(this->SSECustomerAlgorithm.IsEmpty())) {
            awsPutObjectRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->SSECustomerAlgorithm));
        }

		if (!(this->SSECustomerKey.IsEmpty())) {
            awsPutObjectRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->SSECustomerKey));
        }

		if (!(this->SSECustomerKeyMD5.IsEmpty())) {
            awsPutObjectRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->SSECustomerKeyMD5));
        }

		if (!(this->SSEKMSKeyId.IsEmpty())) {
            awsPutObjectRequest.SetSSEKMSKeyId(TCHAR_TO_UTF8(*this->SSEKMSKeyId));
        }

		if (!(this->SSEKMSEncryptionContext.IsEmpty())) {
            awsPutObjectRequest.SetSSEKMSEncryptionContext(TCHAR_TO_UTF8(*this->SSEKMSEncryptionContext));
        }

        awsPutObjectRequest.SetBucketKeyEnabled(this->bucketKeyEnabled);

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsPutObjectRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->tagging.IsEmpty())) {
            awsPutObjectRequest.SetTagging(TCHAR_TO_UTF8(*this->tagging));
        }

        switch(this->objectLockMode) {
            case EAWSObjectLockMode::GOVERNANCE:
                awsPutObjectRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSObjectLockMode::COMPLIANCE:
                awsPutObjectRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
		}

        if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsPutObjectRequest.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSObjectLockLegalHoldStatus::ON:
                awsPutObjectRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSObjectLockLegalHoldStatus::OFF:
                awsPutObjectRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutObjectRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutObjectRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutObjectRequest;
    }

    bool IsEmpty() const {
        return ACL == EAWSObjectCannedACL::NOT_SET && this->bucket.IsEmpty() && this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentLength == 0 && this->contentMD5.IsEmpty() && this->checksumAlgorithm == EAWSS3ChecksumAlgorithm::NOT_SET && this->checksumCRC32.IsEmpty() && this->checksumCRC32C.IsEmpty() && this->checksumSHA1.IsEmpty() && this->checksumSHA256.IsEmpty() && expires.ToUnixTimestamp() <= 0 && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWriteACP.IsEmpty() && this->key.IsEmpty() && this->metadata.Num() == 0 && serverSideEncryption == EAWSServerSideEncryption::NOT_SET && storageClass == EAWSS3StorageClass::NOT_SET && this->websiteRedirectLocation.IsEmpty() && this->SSECustomerAlgorithm.IsEmpty() && this->SSECustomerKey.IsEmpty() && this->SSECustomerKeyMD5.IsEmpty() && this->SSEKMSKeyId.IsEmpty() && this->SSEKMSEncryptionContext.IsEmpty() && false && this->requestPayer == EAWSRequestPayer::NOT_SET && this->tagging.IsEmpty() && objectLockMode == EAWSObjectLockMode::NOT_SET && objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && objectLockLegalHoldStatus == EAWSObjectLockLegalHoldStatus::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
