/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/core/utils/FileSystemUtils.h"
#include "aws/s3/model/GetObjectResult.h"

#endif

#include "Model/ServerSideEncryption.h"
#include "Model/AWSS3StorageClass.h"
#include "Model/RequestCharged.h"
#include "Model/ReplicationStatus.h"
#include "Model/ObjectLockMode.h"
#include "Model/ObjectLockLegalHoldStatus.h"

#include "GetObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectResult {
GENERATED_BODY()

    /**
    *  <p>Object data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString body;

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
    *  <p>If the object expiration is configured (see PUT Bucket lifecycle), the response includes this header. It includes the expiry-date and rule-id key-value pairs providing object expiration information. The value of the rule-id is URL encoded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expiration;

    /**
    *  <p>Provides information about object restoration operation and expiration time of the restored object copy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString restore;

    /**
    *  <p>Last modified date of the object</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

    /**
    *  <p>Size of the body in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 contentLength = 0;

    /**
    *  <p>An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

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
    *  <p>The portion of the object returned in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentRange;

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
    *  <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
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
    *  <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSEKMSKeyId;

    /**
    *  <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>Amazon S3 can return this if your request involves a bucket that is either a source or destination in a replication rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSReplicationStatus replicationStatus = EAWSReplicationStatus::NOT_SET;

    /**
    *  <p>The count of parts this object has.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partsCount = 0;

    /**
    *  <p>The number of tags, if any, on the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int tagCount = 0;

    /**
    *  <p>The Object Lock mode currently in place for this object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockMode objectLockMode = EAWSObjectLockMode::NOT_SET;

    /**
    *  <p>The date and time when this object's Object Lock will expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Indicates whether this object has an active legal hold. This field is only returned if you have permission to view an object's legal hold status. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id2;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString requestId;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectResult &fromAWS(const Aws::S3::Model::GetObjectResult &awsGetObjectResult) {
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

        this->checksumCRC32 = UTF8_TO_TCHAR(awsGetObjectResult.GetChecksumCRC32().c_str());

        this->checksumCRC32C = UTF8_TO_TCHAR(awsGetObjectResult.GetChecksumCRC32C().c_str());

        this->checksumSHA1 = UTF8_TO_TCHAR(awsGetObjectResult.GetChecksumSHA1().c_str());

        this->checksumSHA256 = UTF8_TO_TCHAR(awsGetObjectResult.GetChecksumSHA256().c_str());

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
        for (const auto& elem : awsGetObjectResult.GetMetadata()) {
            this->metadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        this->SSECustomerAlgorithm = UTF8_TO_TCHAR(awsGetObjectResult.GetSSECustomerAlgorithm().c_str());

        this->SSECustomerKeyMD5 = UTF8_TO_TCHAR(awsGetObjectResult.GetSSECustomerKeyMD5().c_str());

        this->SSEKMSKeyId = UTF8_TO_TCHAR(awsGetObjectResult.GetSSEKMSKeyId().c_str());

        switch(awsGetObjectResult.GetStorageClass()) {
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

        switch(awsGetObjectResult.GetRequestCharged()) {
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

        switch(awsGetObjectResult.GetReplicationStatus()) {
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

		this->partsCount = awsGetObjectResult.GetPartsCount();

		this->tagCount = awsGetObjectResult.GetTagCount();

        switch(awsGetObjectResult.GetObjectLockMode()) {
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

        this->objectLockRetainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsGetObjectResult.GetObjectLockRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsGetObjectResult.GetObjectLockLegalHoldStatus()) {
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

        this->id2 = UTF8_TO_TCHAR(awsGetObjectResult.GetId2().c_str());

        this->requestId = UTF8_TO_TCHAR(awsGetObjectResult.GetRequestId().c_str());

        return *this;
    }
#endif
};
