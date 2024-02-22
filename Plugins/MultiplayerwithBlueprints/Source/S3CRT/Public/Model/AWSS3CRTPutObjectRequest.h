/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/core/utils/memory/stl/AWSStreamFwd.h"
#include "aws/core/utils/memory/stl/AWSStringStream.h"
#include "aws/core/utils/FileSystemUtils.h"
#include "aws/s3-crt/model/PutObjectRequest.h"

#endif

#include "Model/AWSS3CRTObjectCannedACL.h"
#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTRequestPayer.h"
#include "Model/AWSS3CRTObjectLockMode.h"
#include "Model/AWSS3CRTObjectLockLegalHoldStatus.h"

#include "AWSS3CRTPutObjectRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutObjectRequest {
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectCannedACL aCL = EAWSS3CRTObjectCannedACL::NOT_SET;

    /**
    *  <p>The bucket name to which the PUT action was initiated. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p> Can be used to specify caching behavior along the request/reply chain. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString cacheControl;

    /**
    *  <p>Specifies presentational information for the object. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.5.1">http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.5.1</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentDisposition;

    /**
    *  <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.11">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.11</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentEncoding;

    /**
    *  <p>The language the content is in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentLanguage;

    /**
    *  <p>Size of the body in bytes. This parameter is useful when the size of the body cannot be determined automatically. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.13">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.13</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 contentLength = 0;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the message (without the headers) according to RFC 1864. This header can be used as a message integrity check to verify that the data is the same data that was originally sent. Although it is optional, we recommend using the Content-MD5 mechanism as an end-to-end integrity check. For more information about REST request authentication, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/RESTAuthentication.html">REST Authentication</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    *  <p>The date and time at which the object is no longer cacheable. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.21">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.21</a>.</p>
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
    *  <p>Object key for which the PUT action was initiated.</p>
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
    *  <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata. For information about object metadata, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingMetadata.html">Object Key and Metadata</a>.</p> <p>In the following example, the request header sets the redirect to an object (anotherPage.html) in the same bucket:</p> <p> <code>x-amz-website-redirect-location: /anotherPage.html</code> </p> <p>In the following example, the request header sets the object redirect to another website:</p> <p> <code>x-amz-website-redirect-location: http://www.example.com/</code> </p> <p>For more information about website hosting in Amazon S3, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/WebsiteHosting.html">Hosting Websites on Amazon S3</a> and <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/how-to-page-redirect.html">How to Configure Website Page Redirects</a>. </p>
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
    *  <p>If <code>x-amz-server-side-encryption</code> is present and has the value of <code>aws:kms</code>, this header specifies the ID of the AWS Key Management Service (AWS KMS) symmetrical customer managed customer master key (CMK) that was used for the object.</p> <p> If the value of <code>x-amz-server-side-encryption</code> is <code>aws:kms</code>, this header specifies the ID of the symmetric customer managed AWS KMS CMK that will be used for the object. If you specify <code>x-amz-server-side-encryption:aws:kms</code>, but do not provide<code> x-amz-server-side-encryption-aws-kms-key-id</code>, Amazon S3 uses the AWS managed CMK in AWS to protect the data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSKeyId;

    /**
    *  <p>Specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSEncryptionContext;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption with server-side encryption using AWS KMS (SSE-KMS). Setting this header to <code>true</code> causes Amazon S3 to use an S3 Bucket Key for object encryption with SSE-KMS.</p> <p>Specifying this header with a PUT action doesn’t affect bucket-level settings for S3 Bucket Key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>The tag-set for the object. The tag-set must be encoded as URL Query parameters. (For example, "Key1=Value1")</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString tagging;

    /**
    *  <p>The Object Lock mode that you want to apply to this object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockMode objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when you want this object's Object Lock to expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether a legal hold will be applied to this object. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>.</p>
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
    Aws::S3Crt::Model::PutObjectRequest toAWS() const {
        Aws::S3Crt::Model::PutObjectRequest awsPutObjectRequest;

        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->file)) {
            std::shared_ptr<Aws::IOStream> awsBody = Aws::MakeShared<Aws::Utils::FStreamWithFileName>("s3-crt", TCHAR_TO_UTF8(*this->file), std::ios_base::in | std::ios_base::binary);

            awsPutObjectRequest.SetBody(awsBody);
        } else {
            Aws::String content = TCHAR_TO_UTF8(*this->file);
            auto contentStream = Aws::MakeShared<Aws::StringStream>("s3-crt");
            *contentStream << content;

            awsPutObjectRequest.SetBody(contentStream);
        }

        switch(this->aCL) {
            case EAWSS3CRTObjectCannedACL::private_:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::private_);
                break;
            case EAWSS3CRTObjectCannedACL::public_read:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::public_read);
                break;
            case EAWSS3CRTObjectCannedACL::public_read_write:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSS3CRTObjectCannedACL::authenticated_read:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSS3CRTObjectCannedACL::aws_exec_read:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_read:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_full_control:
                awsPutObjectRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_full_control);
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
            case EAWSS3CRTServerSideEncryption::AES256:
                awsPutObjectRequest.SetServerSideEncryption(Aws::S3Crt::Model::ServerSideEncryption::AES256);
                break;
            case EAWSS3CRTServerSideEncryption::aws_kms:
                awsPutObjectRequest.SetServerSideEncryption(Aws::S3Crt::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

        switch(this->storageClass) {
            case EAWSS3CRTStorageClass::STANDARD:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD);
                break;
            case EAWSS3CRTStorageClass::REDUCED_REDUNDANCY:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3CRTStorageClass::STANDARD_IA:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTStorageClass::ONEZONE_IA:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTStorageClass::INTELLIGENT_TIERING:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTStorageClass::GLACIER:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::GLACIER);
                break;
            case EAWSS3CRTStorageClass::DEEP_ARCHIVE:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3CRTStorageClass::OUTPOSTS:
                awsPutObjectRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::OUTPOSTS);
                break;
            default:
                break;
        }

        if (!(this->websiteRedirectLocation.IsEmpty())) {
            awsPutObjectRequest.SetWebsiteRedirectLocation(TCHAR_TO_UTF8(*this->websiteRedirectLocation));
        }

        if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsPutObjectRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

        if (!(this->sSECustomerKey.IsEmpty())) {
            awsPutObjectRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->sSECustomerKey));
        }

        if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsPutObjectRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

        if (!(this->sSEKMSKeyId.IsEmpty())) {
            awsPutObjectRequest.SetSSEKMSKeyId(TCHAR_TO_UTF8(*this->sSEKMSKeyId));
        }

        if (!(this->sSEKMSEncryptionContext.IsEmpty())) {
            awsPutObjectRequest.SetSSEKMSEncryptionContext(TCHAR_TO_UTF8(*this->sSEKMSEncryptionContext));
        }

        if (!(false)) {
            awsPutObjectRequest.SetBucketKeyEnabled(this->bucketKeyEnabled);
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsPutObjectRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->tagging.IsEmpty())) {
            awsPutObjectRequest.SetTagging(TCHAR_TO_UTF8(*this->tagging));
        }

        switch(this->objectLockMode) {
            case EAWSS3CRTObjectLockMode::GOVERNANCE:
                awsPutObjectRequest.SetObjectLockMode(Aws::S3Crt::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSS3CRTObjectLockMode::COMPLIANCE:
                awsPutObjectRequest.SetObjectLockMode(Aws::S3Crt::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
        }

        if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsPutObjectRequest.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSS3CRTObjectLockLegalHoldStatus::ON:
                awsPutObjectRequest.SetObjectLockLegalHoldStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSS3CRTObjectLockLegalHoldStatus::OFF:
                awsPutObjectRequest.SetObjectLockLegalHoldStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::OFF);
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
        return this->aCL == EAWSS3CRTObjectCannedACL::NOT_SET && this->bucket.IsEmpty() && this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentLength == 0 && this->contentMD5.IsEmpty() && this->expires.ToUnixTimestamp() <= 0 && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWriteACP.IsEmpty() && this->key.IsEmpty() && this->metadata.Num() == 0 && this->serverSideEncryption == EAWSS3CRTServerSideEncryption::NOT_SET && this->storageClass == EAWSS3CRTStorageClass::NOT_SET && this->websiteRedirectLocation.IsEmpty() && this->sSECustomerAlgorithm.IsEmpty() && this->sSECustomerKey.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->sSEKMSKeyId.IsEmpty() && this->sSEKMSEncryptionContext.IsEmpty() && false && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->tagging.IsEmpty() && this->objectLockMode == EAWSS3CRTObjectLockMode::NOT_SET && this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && this->objectLockLegalHoldStatus == EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
