/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/HeadObjectResult.h"

#endif

#include "Model/AWSS3ArchiveStatus.h"
#include "Model/ServerSideEncryption.h"
#include "Model/AWSS3StorageClass.h"
#include "Model/RequestCharged.h"
#include "Model/ReplicationStatus.h"
#include "Model/ObjectLockMode.h"
#include "Model/ObjectLockLegalHoldStatus.h"

#include "HeadObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FHeadObjectResult {
GENERATED_BODY()

    /**
    *  <p>Specifies whether the object retrieved was (true) or was not (false) a Delete Marker. If false, this response header does not appear in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool deleteMarker = false;

    /**
    *  <p>Indicates that a range of bytes was specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString acceptRanges;

    /**
    *  <p>If the object expiration is configured (see PUT Bucket lifecycle), the response includes this header. It includes the <code>expiry-date</code> and <code>rule-id</code> key-value pairs providing object expiration information. The value of the <code>rule-id</code> is URL-encoded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expiration;

    /**
    *  <p>If the object is an archived object (an object whose storage class is GLACIER), the response includes this header if either the archive restoration is in progress (see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_RestoreObject.html">RestoreObject</a> or an archive copy is already restored.</p> <p> If an archive copy is already restored, the header value indicates when Amazon S3 is scheduled to delete the object copy. For example:</p> <p> <code>x-amz-restore: ongoing-request="false", expiry-date="Fri, 21 Dec 2012 00:00:00 GMT"</code> </p> <p>If the object restoration is in progress, the header returns the value <code>ongoing-request="true"</code>.</p> <p>For more information about archiving objects, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lifecycle-mgmt.html#lifecycle-transition-general-considerations">Transitioning Objects: General Considerations</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString restore;

    /**
    *  <p>The archive state of the head object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ArchiveStatus archiveStatus = EAWSS3ArchiveStatus::NOT_SET;

    /**
    *  <p>Creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

    /**
    *  <p>Size of the body in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 contentLength = 0;

    /**
    *  <p>The base64-encoded, 32-bit CRC32 checksum of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32;

    /**
    *  <p>The base64-encoded, 32-bit CRC32C checksum of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32C;

    /**
    *  <p>The base64-encoded, 160-bit SHA-1 digest of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA1;

    /**
    *  <p>The base64-encoded, 256-bit SHA-256 digest of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA256;

    /**
    *  <p>An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

    /**
    *  <p>This is set to the number of metadata entries not returned in <code>x-amz-meta</code> headers. This can happen if you create metadata using an API like SOAP that supports more flexible metadata than the REST API. For example, using SOAP, you can create metadata whose values are not legal HTTP headers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int missingMeta = 0;

    /**
    *  <p>Version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

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
    *  <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString websiteRedirectLocation;

    /**
    *  <p>If the object is stored using server-side encryption either with an Amazon Web Services KMS key or an Amazon S3-managed encryption key, the response includes this header with the value of the server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption serverSideEncryption = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerAlgorithm;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKeyMD5;

    /**
    *  <p>If present, specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetric customer managed key that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>Indicates whether the object uses an S3 Bucket Key for server-side encryption with Amazon Web Services KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

    /**
    *  <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>Amazon S3 can return this header if your request involves a bucket that is either a source or destination in a replication rule.</p> <p>In replication, you have a source bucket on which you configure replication and destination bucket where Amazon S3 stores object replicas. When you request an object (<code>GetObject</code>) or object metadata (<code>HeadObject</code>) from these buckets, Amazon S3 will return the <code>x-amz-replication-status</code> header in the response as follows:</p> <ul> <li> <p>If requesting an object from the source bucket — Amazon S3 will return the <code>x-amz-replication-status</code> header if the object in your request is eligible for replication.</p> <p> For example, suppose that in your replication configuration, you specify object prefix <code>TaxDocs</code> requesting Amazon S3 to replicate objects with key prefix <code>TaxDocs</code>. Any objects you upload with this key name prefix, for example <code>TaxDocs/document1.pdf</code>, are eligible for replication. For any object request with this key name prefix, Amazon S3 will return the <code>x-amz-replication-status</code> header with value PENDING, COMPLETED or FAILED indicating object replication status.</p> </li> <li> <p>If requesting an object from the destination bucket — Amazon S3 will return the <code>x-amz-replication-status</code> header with value REPLICA if the object in your request is a replica that Amazon S3 created.</p> </li> </ul> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Replication</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSReplicationStatus replicationStatus = EAWSReplicationStatus::NOT_SET;

    /**
    *  <p>The count of parts this object has. This value is only returned if you specify <code>partNumber</code> in your request and the object was uploaded as a multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partsCount = 0;

    /**
    *  <p>The Object Lock mode, if any, that's in effect for this object. This header is only returned if the requester has the <code>s3:GetObjectRetention</code> permission. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockMode objectLockMode = EAWSObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when the Object Lock retention period expires. This header is only returned if the requester has the <code>s3:GetObjectRetention</code> permission.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether a legal hold is in effect for this object. This header is only returned if the requester has the <code>s3:GetObjectLegalHold</code> permission. This header is not returned if the specified version of this object has never had a legal hold applied. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FHeadObjectResult &fromAWS(const Aws::S3::Model::HeadObjectResult &awsHeadObjectResult) {
        this->deleteMarker = awsHeadObjectResult.GetDeleteMarker();

        this->acceptRanges = UTF8_TO_TCHAR(awsHeadObjectResult.GetAcceptRanges().c_str());

        this->expiration = UTF8_TO_TCHAR(awsHeadObjectResult.GetExpiration().c_str());

        this->restore = UTF8_TO_TCHAR(awsHeadObjectResult.GetRestore().c_str());

        switch(awsHeadObjectResult.GetArchiveStatus()) {
            case Aws::S3::Model::ArchiveStatus::NOT_SET:
                this->archiveStatus = EAWSS3ArchiveStatus::NOT_SET;
                break;
            case Aws::S3::Model::ArchiveStatus::ARCHIVE_ACCESS:
                this->archiveStatus = EAWSS3ArchiveStatus::ARCHIVE_ACCESS;
                break;
            case Aws::S3::Model::ArchiveStatus::DEEP_ARCHIVE_ACCESS:
                this->archiveStatus = EAWSS3ArchiveStatus::DEEP_ARCHIVE_ACCESS;
                break;
            default:
                this->archiveStatus = EAWSS3ArchiveStatus::NOT_SET;
                break;
        }

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsHeadObjectResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->contentLength = (int64)awsHeadObjectResult.GetContentLength();

        this->checksumCRC32 = UTF8_TO_TCHAR(awsHeadObjectResult.GetChecksumCRC32().c_str());

        this->checksumCRC32C = UTF8_TO_TCHAR(awsHeadObjectResult.GetChecksumCRC32C().c_str());

        this->checksumSHA1 = UTF8_TO_TCHAR(awsHeadObjectResult.GetChecksumSHA1().c_str());

        this->checksumSHA256 = UTF8_TO_TCHAR(awsHeadObjectResult.GetChecksumSHA256().c_str());

        this->eTag = UTF8_TO_TCHAR(awsHeadObjectResult.GetETag().c_str());

		this->missingMeta = awsHeadObjectResult.GetMissingMeta();

        this->versionId = UTF8_TO_TCHAR(awsHeadObjectResult.GetVersionId().c_str());

        this->cacheControl = UTF8_TO_TCHAR(awsHeadObjectResult.GetCacheControl().c_str());

        this->contentDisposition = UTF8_TO_TCHAR(awsHeadObjectResult.GetContentDisposition().c_str());

        this->contentEncoding = UTF8_TO_TCHAR(awsHeadObjectResult.GetContentEncoding().c_str());

        this->contentLanguage = UTF8_TO_TCHAR(awsHeadObjectResult.GetContentLanguage().c_str());

        this->contentType = UTF8_TO_TCHAR(awsHeadObjectResult.GetContentType().c_str());

        this->expires = FDateTime(1970, 1, 1) + FTimespan(awsHeadObjectResult.GetExpires().Millis() * ETimespan::TicksPerMillisecond);

        this->websiteRedirectLocation = UTF8_TO_TCHAR(awsHeadObjectResult.GetWebsiteRedirectLocation().c_str());

        switch(awsHeadObjectResult.GetServerSideEncryption()) {
            case Aws::S3::Model::ServerSideEncryption::NOT_SET:
                this->serverSideEncryption = EAWSServerSideEncryption::NOT_SET;
                break;
            case Aws::S3::Model::ServerSideEncryption::AES256:
                this->serverSideEncryption = EAWSServerSideEncryption::AES256;
                break;
            case Aws::S3::Model::ServerSideEncryption::aws_kms:
                this->serverSideEncryption = EAWSServerSideEncryption::aws_kms;
                break;
            default:
                this->serverSideEncryption = EAWSServerSideEncryption::NOT_SET;
                break;
        }

        this->metadata.Empty();
        for (const auto& elem : awsHeadObjectResult.GetMetadata()) {
            this->metadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        this->SSECustomerAlgorithm = UTF8_TO_TCHAR(awsHeadObjectResult.GetSSECustomerAlgorithm().c_str());

        this->SSECustomerKeyMD5 = UTF8_TO_TCHAR(awsHeadObjectResult.GetSSECustomerKeyMD5().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsHeadObjectResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsHeadObjectResult.GetBucketKeyEnabled();

        switch(awsHeadObjectResult.GetStorageClass()) {
            case Aws::S3::Model::StorageClass::NOT_SET:
                this->storageClass = EAWSS3StorageClass::NOT_SET;
                break;
            case Aws::S3::Model::StorageClass::STANDARD:
                this->storageClass = EAWSS3StorageClass::STANDARD;
                break;
            case Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3StorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3::Model::StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3StorageClass::STANDARD_IA;
                break;
            case Aws::S3::Model::StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3StorageClass::ONEZONE_IA;
                break;
            case Aws::S3::Model::StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3StorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3::Model::StorageClass::GLACIER:
                this->storageClass = EAWSS3StorageClass::GLACIER;
                break;
            case Aws::S3::Model::StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3StorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3::Model::StorageClass::OUTPOSTS:
                this->storageClass = EAWSS3StorageClass::OUTPOSTS;
                break;
            case Aws::S3::Model::StorageClass::GLACIER_IR:
                this->storageClass = EAWSS3StorageClass::GLACIER_IR;
                break;
            default:
                this->storageClass = EAWSS3StorageClass::NOT_SET;
                break;
        }

        switch(awsHeadObjectResult.GetRequestCharged()) {
            case Aws::S3::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
            case Aws::S3::Model::RequestCharged::requester:
                this->requestCharged = EAWSRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
        }

        switch(awsHeadObjectResult.GetReplicationStatus()) {
            case Aws::S3::Model::ReplicationStatus::NOT_SET:
                this->replicationStatus = EAWSReplicationStatus::NOT_SET;
                break;
            case Aws::S3::Model::ReplicationStatus::COMPLETED:
                this->replicationStatus = EAWSReplicationStatus::COMPLETED;
                break;
            case Aws::S3::Model::ReplicationStatus::PENDING:
                this->replicationStatus = EAWSReplicationStatus::PENDING;
                break;
            case Aws::S3::Model::ReplicationStatus::FAILED:
                this->replicationStatus = EAWSReplicationStatus::FAILED;
                break;
            case Aws::S3::Model::ReplicationStatus::REPLICA:
                this->replicationStatus = EAWSReplicationStatus::REPLICA;
                break;
            default:
                this->replicationStatus = EAWSReplicationStatus::NOT_SET;
                break;
        }

		this->partsCount = awsHeadObjectResult.GetPartsCount();

        switch(awsHeadObjectResult.GetObjectLockMode()) {
            case Aws::S3::Model::ObjectLockMode::NOT_SET:
                this->objectLockMode = EAWSObjectLockMode::NOT_SET;
                break;
            case Aws::S3::Model::ObjectLockMode::GOVERNANCE:
                this->objectLockMode = EAWSObjectLockMode::GOVERNANCE;
                break;
            case Aws::S3::Model::ObjectLockMode::COMPLIANCE:
                this->objectLockMode = EAWSObjectLockMode::COMPLIANCE;
                break;
            default:
                this->objectLockMode = EAWSObjectLockMode::NOT_SET;
                break;
        }

        this->objectLockRetainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsHeadObjectResult.GetObjectLockRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsHeadObjectResult.GetObjectLockLegalHoldStatus()) {
            case Aws::S3::Model::ObjectLockLegalHoldStatus::NOT_SET:
                this->objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;
                break;
            case Aws::S3::Model::ObjectLockLegalHoldStatus::ON:
                this->objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::ON;
                break;
            case Aws::S3::Model::ObjectLockLegalHoldStatus::OFF:
                this->objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::OFF;
                break;
            default:
                this->objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
