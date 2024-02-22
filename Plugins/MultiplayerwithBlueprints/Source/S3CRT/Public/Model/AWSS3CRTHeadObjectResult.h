/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/HeadObjectResult.h"

#endif

#include "Model/AWSS3CRTArchiveStatus.h"
#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTRequestCharged.h"
#include "Model/AWSS3CRTReplicationStatus.h"
#include "Model/AWSS3CRTObjectLockMode.h"
#include "Model/AWSS3CRTObjectLockLegalHoldStatus.h"

#include "AWSS3CRTHeadObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTHeadObjectResult {
GENERATED_BODY()

    /**
    *  <p>Specifies whether the object retrieved was (true) or was not (false) a Delete Marker. If false, this response header does not appear in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool deleteMarker = false;

    /**
    *  <p>Indicates that a range of bytes was specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString acceptRanges;

    /**
    *  <p>If the object expiration is configured (see PUT Bucket lifecycle), the response includes this header. It includes the expiry-date and rule-id key-value pairs providing object expiration information. The value of the rule-id is URL encoded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expiration;

    /**
    *  <p>If the object is an archived object (an object whose storage class is GLACIER), the response includes this header if either the archive restoration is in progress (see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_RestoreObject.html">RestoreObject</a> or an archive copy is already restored.</p> <p> If an archive copy is already restored, the header value indicates when Amazon S3 is scheduled to delete the object copy. For example:</p> <p> <code>x-amz-restore: ongoing-request="false", expiry-date="Fri, 21 Dec 2012 00:00:00 GMT"</code> </p> <p>If the object restoration is in progress, the header returns the value <code>ongoing-request="true"</code>.</p> <p>For more information about archiving objects, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lifecycle-mgmt.html#lifecycle-transition-general-considerations">Transitioning Objects: General Considerations</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString restore;

    /**
    *  <p>The archive state of the head object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTArchiveStatus archiveStatus = EAWSS3CRTArchiveStatus::NOT_SET;

    /**
    *  <p>Creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

    /**
    *  <p>Size of the body in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 contentLength = 0;

    /**
    *  <p>An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>This is set to the number of metadata entries not returned in <code>x-amz-meta</code> headers. This can happen if you create metadata using an API like SOAP that supports more flexible metadata than the REST API. For example, using SOAP, you can create metadata whose values are not legal HTTP headers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int missingMeta = 0;

    /**
    *  <p>Version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

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
    *  <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString websiteRedirectLocation;

    /**
    *  <p>If the object is stored using server-side encryption either with an AWS KMS customer master key (CMK) or an Amazon S3-managed encryption key, the response includes this header with the value of the server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTServerSideEncryption serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSKeyId;

    /**
    *  <p>Indicates whether the object uses an S3 Bucket Key for server-side encryption with AWS KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

    /**
    *  <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

    /**
    *  <p>Amazon S3 can return this header if your request involves a bucket that is either a source or a destination in a replication rule.</p> <p>In replication, you have a source bucket on which you configure replication and destination bucket or buckets where Amazon S3 stores object replicas. When you request an object (<code>GetObject</code>) or object metadata (<code>HeadObject</code>) from these buckets, Amazon S3 will return the <code>x-amz-replication-status</code> header in the response as follows:</p> <ul> <li> <p>If requesting an object from the source bucket — Amazon S3 will return the <code>x-amz-replication-status</code> header if the object in your request is eligible for replication.</p> <p> For example, suppose that in your replication configuration, you specify object prefix <code>TaxDocs</code> requesting Amazon S3 to replicate objects with key prefix <code>TaxDocs</code>. Any objects you upload with this key name prefix, for example <code>TaxDocs/document1.pdf</code>, are eligible for replication. For any object request with this key name prefix, Amazon S3 will return the <code>x-amz-replication-status</code> header with value PENDING, COMPLETED or FAILED indicating object replication status.</p> </li> <li> <p>If requesting an object from a destination bucket — Amazon S3 will return the <code>x-amz-replication-status</code> header with value REPLICA if the object in your request is a replica that Amazon S3 created and there is no replica modification replication in progress.</p> </li> <li> <p>When replicating objects to multiple destination buckets the <code>x-amz-replication-status</code> header acts differently. The header of the source object will only return a value of COMPLETED when replication is successful to all destinations. The header will remain at value PENDING until replication has completed for all destinations. If one or more destinations fails replication the header will return FAILED. </p> </li> </ul> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Replication</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTReplicationStatus replicationStatus = EAWSS3CRTReplicationStatus::NOT_SET;

    /**
    *  <p>The count of parts this object has.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partsCount = 0;

    /**
    *  <p>The Object Lock mode, if any, that's in effect for this object. This header is only returned if the requester has the <code>s3:GetObjectRetention</code> permission. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockMode objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when the Object Lock retention period expires. This header is only returned if the requester has the <code>s3:GetObjectRetention</code> permission.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether a legal hold is in effect for this object. This header is only returned if the requester has the <code>s3:GetObjectLegalHold</code> permission. This header is not returned if the specified version of this object has never had a legal hold applied. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTHeadObjectResult &fromAWS(const Aws::S3Crt::Model::HeadObjectResult &awsHeadObjectResult) {
        this->deleteMarker = awsHeadObjectResult.GetDeleteMarker();

        this->acceptRanges = UTF8_TO_TCHAR(awsHeadObjectResult.GetAcceptRanges().c_str());

        this->expiration = UTF8_TO_TCHAR(awsHeadObjectResult.GetExpiration().c_str());

        this->restore = UTF8_TO_TCHAR(awsHeadObjectResult.GetRestore().c_str());

        switch(awsHeadObjectResult.GetArchiveStatus()) {
            case Aws::S3Crt::Model::ArchiveStatus::NOT_SET:
                this->archiveStatus = EAWSS3CRTArchiveStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ArchiveStatus::ARCHIVE_ACCESS:
                this->archiveStatus = EAWSS3CRTArchiveStatus::ARCHIVE_ACCESS;
                break;
            case Aws::S3Crt::Model::ArchiveStatus::DEEP_ARCHIVE_ACCESS:
                this->archiveStatus = EAWSS3CRTArchiveStatus::DEEP_ARCHIVE_ACCESS;
                break;
            default:
                this->archiveStatus = EAWSS3CRTArchiveStatus::NOT_SET;
                break;
        }

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsHeadObjectResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->contentLength = (int64)awsHeadObjectResult.GetContentLength();

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
            case Aws::S3Crt::Model::ServerSideEncryption::NOT_SET:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;
                break;
            case Aws::S3Crt::Model::ServerSideEncryption::AES256:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::AES256;
                break;
            case Aws::S3Crt::Model::ServerSideEncryption::aws_kms:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::aws_kms;
                break;
            default:
                this->serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;
                break;
        }

        this->metadata.Empty();
        for (const auto& elem : awsHeadObjectResult.GetMetadata()) {
            this->metadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        this->sSECustomerAlgorithm = UTF8_TO_TCHAR(awsHeadObjectResult.GetSSECustomerAlgorithm().c_str());

        this->sSECustomerKeyMD5 = UTF8_TO_TCHAR(awsHeadObjectResult.GetSSECustomerKeyMD5().c_str());

        this->sSEKMSKeyId = UTF8_TO_TCHAR(awsHeadObjectResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsHeadObjectResult.GetBucketKeyEnabled();

        switch(awsHeadObjectResult.GetStorageClass()) {
            case Aws::S3Crt::Model::StorageClass::NOT_SET:
                this->storageClass = EAWSS3CRTStorageClass::NOT_SET;
                break;
            case Aws::S3Crt::Model::StorageClass::STANDARD:
                this->storageClass = EAWSS3CRTStorageClass::STANDARD;
                break;
            case Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3CRTStorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3Crt::Model::StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3CRTStorageClass::STANDARD_IA;
                break;
            case Aws::S3Crt::Model::StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3CRTStorageClass::ONEZONE_IA;
                break;
            case Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3CRTStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Crt::Model::StorageClass::GLACIER:
                this->storageClass = EAWSS3CRTStorageClass::GLACIER;
                break;
            case Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3CRTStorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3Crt::Model::StorageClass::OUTPOSTS:
                this->storageClass = EAWSS3CRTStorageClass::OUTPOSTS;
                break;
            default:
                this->storageClass = EAWSS3CRTStorageClass::NOT_SET;
                break;
        }

        switch(awsHeadObjectResult.GetRequestCharged()) {
            case Aws::S3Crt::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
            case Aws::S3Crt::Model::RequestCharged::requester:
                this->requestCharged = EAWSS3CRTRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
        }

        switch(awsHeadObjectResult.GetReplicationStatus()) {
            case Aws::S3Crt::Model::ReplicationStatus::NOT_SET:
                this->replicationStatus = EAWSS3CRTReplicationStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ReplicationStatus::COMPLETED:
                this->replicationStatus = EAWSS3CRTReplicationStatus::COMPLETED;
                break;
            case Aws::S3Crt::Model::ReplicationStatus::PENDING:
                this->replicationStatus = EAWSS3CRTReplicationStatus::PENDING;
                break;
            case Aws::S3Crt::Model::ReplicationStatus::FAILED:
                this->replicationStatus = EAWSS3CRTReplicationStatus::FAILED;
                break;
            case Aws::S3Crt::Model::ReplicationStatus::REPLICA:
                this->replicationStatus = EAWSS3CRTReplicationStatus::REPLICA;
                break;
            default:
                this->replicationStatus = EAWSS3CRTReplicationStatus::NOT_SET;
                break;
        }

		this->partsCount = awsHeadObjectResult.GetPartsCount();

        switch(awsHeadObjectResult.GetObjectLockMode()) {
            case Aws::S3Crt::Model::ObjectLockMode::NOT_SET:
                this->objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectLockMode::GOVERNANCE:
                this->objectLockMode = EAWSS3CRTObjectLockMode::GOVERNANCE;
                break;
            case Aws::S3Crt::Model::ObjectLockMode::COMPLIANCE:
                this->objectLockMode = EAWSS3CRTObjectLockMode::COMPLIANCE;
                break;
            default:
                this->objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;
                break;
        }

        this->objectLockRetainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsHeadObjectResult.GetObjectLockRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsHeadObjectResult.GetObjectLockLegalHoldStatus()) {
            case Aws::S3Crt::Model::ObjectLockLegalHoldStatus::NOT_SET:
                this->objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectLockLegalHoldStatus::ON:
                this->objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::ON;
                break;
            case Aws::S3Crt::Model::ObjectLockLegalHoldStatus::OFF:
                this->objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::OFF;
                break;
            default:
                this->objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
