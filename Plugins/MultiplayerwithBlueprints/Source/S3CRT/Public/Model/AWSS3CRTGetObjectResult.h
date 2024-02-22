/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/core/utils/FileSystemUtils.h"
#include "aws/s3-crt/model/GetObjectResult.h"

#endif

#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTRequestCharged.h"
#include "Model/AWSS3CRTReplicationStatus.h"
#include "Model/AWSS3CRTObjectLockMode.h"
#include "Model/AWSS3CRTObjectLockLegalHoldStatus.h"
#include "AWSS3CRTGetObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectResult {
GENERATED_BODY()

    /**
    *  <p>Object data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString body;

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
    *  <p>Provides information about object restoration action and expiration time of the restored object copy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString restore;

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
    *  <p>The portion of the object returned in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentRange;

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
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
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
    *  <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

    /**
    *  <p>Amazon S3 can return this if your request involves a bucket that is either a source or destination in a replication rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTReplicationStatus replicationStatus = EAWSS3CRTReplicationStatus::NOT_SET;

    /**
    *  <p>The count of parts this object has.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partsCount = 0;

    /**
    *  <p>The number of tags, if any, on the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int tagCount = 0;

    /**
    *  <p>The Object Lock mode currently in place for this object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockMode objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when this object's Object Lock will expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Indicates whether this object has an active legal hold. This field is only returned if you have permission to view an object's legal hold status. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id2;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString requestId;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectResult &fromAWS(const Aws::S3Crt::Model::GetObjectResult &awsGetObjectResult) {
        Aws::Utils::FStreamWithFileName awsTempFile("" + Aws::FileSystem::CreateTempFilePath() + "", std::ios_base::binary | std::ios_base::app | std::ios_base::out);

        Aws::IOStream& awsStream = awsGetObjectResult.GetBody();
        unsigned int Size = 0;
        TArray<uint8> rawData;
        awsStream.seekg(0, std::ios::end);
        Size = awsStream.tellg();
        awsStream.seekg(0);
        rawData.SetNum(Size);
        awsStream.read((char*)rawData.GetData(), Size);

        awsTempFile.write((char*)rawData.GetData(), Size);
        awsTempFile.close();
        this->body = UTF8_TO_TCHAR(awsTempFile.GetFileName().c_str());

        this->deleteMarker = awsGetObjectResult.GetDeleteMarker();

        this->acceptRanges = UTF8_TO_TCHAR(awsGetObjectResult.GetAcceptRanges().c_str());

        this->expiration = UTF8_TO_TCHAR(awsGetObjectResult.GetExpiration().c_str());

        this->restore = UTF8_TO_TCHAR(awsGetObjectResult.GetRestore().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsGetObjectResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->contentLength = (int64)awsGetObjectResult.GetContentLength();

        this->eTag = UTF8_TO_TCHAR(awsGetObjectResult.GetETag().c_str());

		this->missingMeta = awsGetObjectResult.GetMissingMeta();

        this->versionId = UTF8_TO_TCHAR(awsGetObjectResult.GetVersionId().c_str());

        this->cacheControl = UTF8_TO_TCHAR(awsGetObjectResult.GetCacheControl().c_str());

        this->contentDisposition = UTF8_TO_TCHAR(awsGetObjectResult.GetContentDisposition().c_str());

        this->contentEncoding = UTF8_TO_TCHAR(awsGetObjectResult.GetContentEncoding().c_str());

        this->contentLanguage = UTF8_TO_TCHAR(awsGetObjectResult.GetContentLanguage().c_str());

        this->contentRange = UTF8_TO_TCHAR(awsGetObjectResult.GetContentRange().c_str());

        this->contentType = UTF8_TO_TCHAR(awsGetObjectResult.GetContentType().c_str());

        this->expires = FDateTime(1970, 1, 1) + FTimespan(awsGetObjectResult.GetExpires().Millis() * ETimespan::TicksPerMillisecond);

        this->websiteRedirectLocation = UTF8_TO_TCHAR(awsGetObjectResult.GetWebsiteRedirectLocation().c_str());

        switch(awsGetObjectResult.GetServerSideEncryption()) {
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
        for (const auto& elem : awsGetObjectResult.GetMetadata()) {
            this->metadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        this->sSECustomerAlgorithm = UTF8_TO_TCHAR(awsGetObjectResult.GetSSECustomerAlgorithm().c_str());

        this->sSECustomerKeyMD5 = UTF8_TO_TCHAR(awsGetObjectResult.GetSSECustomerKeyMD5().c_str());

        this->sSEKMSKeyId = UTF8_TO_TCHAR(awsGetObjectResult.GetSSEKMSKeyId().c_str());

        this->bucketKeyEnabled = awsGetObjectResult.GetBucketKeyEnabled();

        switch(awsGetObjectResult.GetStorageClass()) {
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

        switch(awsGetObjectResult.GetRequestCharged()) {
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

        switch(awsGetObjectResult.GetReplicationStatus()) {
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

		this->partsCount = awsGetObjectResult.GetPartsCount();

		this->tagCount = awsGetObjectResult.GetTagCount();

        switch(awsGetObjectResult.GetObjectLockMode()) {
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

        this->objectLockRetainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsGetObjectResult.GetObjectLockRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsGetObjectResult.GetObjectLockLegalHoldStatus()) {
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

        this->id2 = UTF8_TO_TCHAR(awsGetObjectResult.GetId2().c_str());

        this->requestId = UTF8_TO_TCHAR(awsGetObjectResult.GetRequestId().c_str());

        return *this;
    }
#endif
};
