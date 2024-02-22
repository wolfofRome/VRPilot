/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/WriteGetObjectResponseRequest.h"

#endif

#include "Model/ObjectLockMode.h"
#include "Model/ObjectLockLegalHoldStatus.h"
#include "Model/ReplicationStatus.h"
#include "Model/RequestCharged.h"
#include "Model/ServerSideEncryption.h"
#include "Model/AWSS3StorageClass.h"

#include "AWSS3WriteGetObjectResponseRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3WriteGetObjectResponseRequest {
GENERATED_BODY()

    /**
    *  <p>Route prefix to the HTTP URL generated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString requestRoute;

    /**
    *  <p>A single use encrypted token that maps <code>WriteGetObjectResponse</code> to the end user <code>GetObject</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString requestToken;

    /**
    *  <p>The integer status code for an HTTP response of a corresponding <code>GetObject</code> request.</p> <p class="title"> <b>Status Codes</b> </p> <ul> <li> <p> <code>200 - OK</code> </p> </li> <li> <p> <code>206 - Partial Content</code> </p> </li> <li> <p> <code>304 - Not Modified</code> </p> </li> <li> <p> <code>400 - Bad Request</code> </p> </li> <li> <p> <code>401 - Unauthorized</code> </p> </li> <li> <p> <code>403 - Forbidden</code> </p> </li> <li> <p> <code>404 - Not Found</code> </p> </li> <li> <p> <code>405 - Method Not Allowed</code> </p> </li> <li> <p> <code>409 - Conflict</code> </p> </li> <li> <p> <code>411 - Length Required</code> </p> </li> <li> <p> <code>412 - Precondition Failed</code> </p> </li> <li> <p> <code>416 - Range Not Satisfiable</code> </p> </li> <li> <p> <code>500 - Internal Server Error</code> </p> </li> <li> <p> <code>503 - Service Unavailable</code> </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int statusCode = 0;

    /**
    *  <p>A string that uniquely identifies an error condition. Returned in the &lt;Code&gt; tag of the error XML response for a corresponding <code>GetObject</code> call. Cannot be used with a successful <code>StatusCode</code> header or when the transformed object is provided in the body. All error codes from S3 are sentence-cased. The regular expression (regex) value is <code>"^[A-Z][a-zA-Z]+$"</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString errorCode;

    /**
    *  <p>Contains a generic description of the error condition. Returned in the &lt;Message&gt; tag of the error XML response for a corresponding <code>GetObject</code> call. Cannot be used with a successful <code>StatusCode</code> header or when the transformed object is provided in body.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString errorMessage;

    /**
    *  <p>Indicates that a range of bytes was specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString acceptRanges;

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
    *  <p>The size of the content body in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 contentLength = 0;

    /**
    *  <p>The portion of the object returned in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentRange;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This specifies the base64-encoded, 32-bit CRC32 checksum of the object returned by the Object Lambda function. This may not match the checksum for the object stored in Amazon S3. Amazon S3 will perform validation of the checksum values only when the original <code>GetObject</code> request required checksum validation. For more information about checksums, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Only one checksum header can be specified at a time. If you supply multiple checksum headers, this request will fail.</p> <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This specifies the base64-encoded, 32-bit CRC32C checksum of the object returned by the Object Lambda function. This may not match the checksum for the object stored in Amazon S3. Amazon S3 will perform validation of the checksum values only when the original <code>GetObject</code> request required checksum validation. For more information about checksums, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Only one checksum header can be specified at a time. If you supply multiple checksum headers, this request will fail.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32C;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This specifies the base64-encoded, 160-bit SHA-1 digest of the object returned by the Object Lambda function. This may not match the checksum for the object stored in Amazon S3. Amazon S3 will perform validation of the checksum values only when the original <code>GetObject</code> request required checksum validation. For more information about checksums, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Only one checksum header can be specified at a time. If you supply multiple checksum headers, this request will fail.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA1;

    /**
    *  <p>This header can be used as a data integrity check to verify that the data received is the same data that was originally sent. This specifies the base64-encoded, 256-bit SHA-256 digest of the object returned by the Object Lambda function. This may not match the checksum for the object stored in Amazon S3. Amazon S3 will perform validation of the checksum values only when the original <code>GetObject</code> request required checksum validation. For more information about checksums, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Only one checksum header can be specified at a time. If you supply multiple checksum headers, this request will fail.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA256;

    /**
    *  <p>Specifies whether an object stored in Amazon S3 is (<code>true</code>) or is not (<code>false</code>) a delete marker. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool deleteMarker = false;

    /**
    *  <p>An opaque identifier assigned by a web server to a specific version of a resource found at a URL. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

    /**
    *  <p>The date and time at which the object is no longer cacheable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime expires;

    /**
    *  <p>If the object expiration is configured (see PUT Bucket lifecycle), the response includes this header. It includes the <code>expiry-date</code> and <code>rule-id</code> key-value pairs that provide the object expiration information. The value of the <code>rule-id</code> is URL-encoded. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expiration;

    /**
    *  <p>The date and time that the object was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

    /**
    *  <p>Set to the number of metadata entries not returned in <code>x-amz-meta</code> headers. This can happen if you create metadata using an API like SOAP that supports more flexible metadata than the REST API. For example, using SOAP, you can create metadata whose values are not legal HTTP headers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int missingMeta = 0;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>Indicates whether an object stored in Amazon S3 has Object Lock enabled. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-lock.html">Object Lock</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockMode objectLockMode = EAWSObjectLockMode::NOT_SET;

    /**
    *  <p>Indicates whether an object stored in Amazon S3 has an active legal hold.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSObjectLockLegalHoldStatus::NOT_SET;

    /**
    *  <p>The date and time when Object Lock is configured to expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>The count of parts this object has.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partsCount = 0;

    /**
    *  <p>Indicates if request involves bucket that is either a source or destination in a Replication rule. For more information about S3 Replication, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/replication.html">Replication</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSReplicationStatus replicationStatus = EAWSReplicationStatus::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>Provides information about object restoration operation and expiration time of the restored object copy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString restore;

    /**
    *  <p> The server-side encryption algorithm used when storing requested object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption serverSideEncryption = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>Encryption algorithm used if server-side encryption with a customer-provided encryption key was specified for object stored in Amazon S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p> If present, specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetric customer managed key that was used for stored in Amazon S3 object. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString sSEKMSKeyId;

    /**
    *  <p> 128-bit MD5 digest of customer-provided encryption key used in Amazon S3 to encrypt data stored in S3. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ServerSideEncryptionCustomerKeys.html">Protecting data using server-side encryption with customer-provided encryption keys (SSE-C)</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    *  <p>The number of tags, if any, on the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int tagCount = 0;

    /**
    *  <p>An ID used to reference a specific version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p> Indicates whether the object stored in Amazon S3 uses an S3 bucket key for server-side encryption with Amazon Web Services KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::WriteGetObjectResponseRequest toAWS() const {
        Aws::S3::Model::WriteGetObjectResponseRequest awsWriteGetObjectResponseRequest;

        if (!(this->requestRoute.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetRequestRoute(TCHAR_TO_UTF8(*this->requestRoute));
        }

        if (!(this->requestToken.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetRequestToken(TCHAR_TO_UTF8(*this->requestToken));
        }

        if (!(this->statusCode == 0)) {
            awsWriteGetObjectResponseRequest.SetStatusCode(this->statusCode);
        }

        if (!(this->errorCode.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetErrorCode(TCHAR_TO_UTF8(*this->errorCode));
        }

        if (!(this->errorMessage.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetErrorMessage(TCHAR_TO_UTF8(*this->errorMessage));
        }

        if (!(this->acceptRanges.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetAcceptRanges(TCHAR_TO_UTF8(*this->acceptRanges));
        }

        if (!(this->cacheControl.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetCacheControl(TCHAR_TO_UTF8(*this->cacheControl));
        }

        if (!(this->contentDisposition.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetContentDisposition(TCHAR_TO_UTF8(*this->contentDisposition));
        }

        if (!(this->contentEncoding.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetContentEncoding(TCHAR_TO_UTF8(*this->contentEncoding));
        }

        if (!(this->contentLanguage.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetContentLanguage(TCHAR_TO_UTF8(*this->contentLanguage));
        }

        if (!(this->contentLength == 0)) {
            awsWriteGetObjectResponseRequest.SetContentLength(this->contentLength);
        }

        if (!(this->contentRange.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetContentRange(TCHAR_TO_UTF8(*this->contentRange));
        }

		if (!(this->checksumCRC32.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetChecksumCRC32(TCHAR_TO_UTF8(*this->checksumCRC32));
        }

        if (!(this->checksumCRC32C.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetChecksumCRC32C(TCHAR_TO_UTF8(*this->checksumCRC32C));
        }

        if (!(this->checksumSHA1.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetChecksumSHA1(TCHAR_TO_UTF8(*this->checksumSHA1));
        }

        if (!(this->checksumSHA256.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetChecksumSHA256(TCHAR_TO_UTF8(*this->checksumSHA256));
        }

        if (!(false)) {
            awsWriteGetObjectResponseRequest.SetDeleteMarker(this->deleteMarker);
        }

        if (!(this->eTag.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetETag(TCHAR_TO_UTF8(*this->eTag));
        }

        if (!(this->expires.ToUnixTimestamp() <= 0)) {
            awsWriteGetObjectResponseRequest.SetExpires(Aws::Utils::DateTime((int64_t)((this->expires - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->expiration.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetExpiration(TCHAR_TO_UTF8(*this->expiration));
        }

        if (!(this->lastModified.ToUnixTimestamp() <= 0)) {
            awsWriteGetObjectResponseRequest.SetLastModified(Aws::Utils::DateTime((int64_t)((this->lastModified - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->missingMeta == 0)) {
            awsWriteGetObjectResponseRequest.SetMissingMeta(this->missingMeta);
        }

        for (const TPair<FString, FString>& elem : this->metadata) {
            awsWriteGetObjectResponseRequest.AddMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        switch(this->objectLockMode) {
            case EAWSObjectLockMode::GOVERNANCE:
                awsWriteGetObjectResponseRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSObjectLockMode::COMPLIANCE:
                awsWriteGetObjectResponseRequest.SetObjectLockMode(Aws::S3::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSObjectLockLegalHoldStatus::ON:
                awsWriteGetObjectResponseRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSObjectLockLegalHoldStatus::OFF:
                awsWriteGetObjectResponseRequest.SetObjectLockLegalHoldStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
        }

        if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsWriteGetObjectResponseRequest.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->partsCount == 0)) {
            awsWriteGetObjectResponseRequest.SetPartsCount(this->partsCount);
        }

        switch(this->replicationStatus) {
            case EAWSReplicationStatus::COMPLETED:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3::Model::ReplicationStatus::COMPLETED);
                break;
            case EAWSReplicationStatus::PENDING:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3::Model::ReplicationStatus::PENDING);
                break;
            case EAWSReplicationStatus::FAILED:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3::Model::ReplicationStatus::FAILED);
                break;
            case EAWSReplicationStatus::REPLICA:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3::Model::ReplicationStatus::REPLICA);
                break;
            default:
                break;
        }

        switch(this->requestCharged) {
            case EAWSRequestCharged::requester:
                awsWriteGetObjectResponseRequest.SetRequestCharged(Aws::S3::Model::RequestCharged::requester);
                break;
            default:
                break;
        }

        if (!(this->restore.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetRestore(TCHAR_TO_UTF8(*this->restore));
        }

        switch(this->serverSideEncryption) {
            case EAWSServerSideEncryption::AES256:
                awsWriteGetObjectResponseRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::AES256);
                break;
            case EAWSServerSideEncryption::aws_kms:
                awsWriteGetObjectResponseRequest.SetServerSideEncryption(Aws::S3::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

        if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

		if (!(this->sSEKMSKeyId.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetSSEKMSKeyId(TCHAR_TO_UTF8(*this->sSEKMSKeyId));
        }

		if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

		switch(this->storageClass) {
            case EAWSS3StorageClass::STANDARD:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD);
                break;
            case EAWSS3StorageClass::REDUCED_REDUNDANCY:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3StorageClass::STANDARD_IA:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3StorageClass::ONEZONE_IA:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3StorageClass::INTELLIGENT_TIERING:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3StorageClass::GLACIER:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER);
                break;
            case EAWSS3StorageClass::DEEP_ARCHIVE:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3StorageClass::OUTPOSTS:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::OUTPOSTS);
                break;
            case EAWSS3StorageClass::GLACIER_IR:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER_IR);
                break;
            default:
                break;
		}

		if (!(this->tagCount == 0)) {
            awsWriteGetObjectResponseRequest.SetTagCount(this->tagCount);
        }

		if (!(this->versionId.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

		if (!(false)) {
            awsWriteGetObjectResponseRequest.SetBucketKeyEnabled(this->bucketKeyEnabled);
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsWriteGetObjectResponseRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

		return awsWriteGetObjectResponseRequest;
    }

    bool IsEmpty() const {
        return this->requestRoute.IsEmpty() && this->requestToken.IsEmpty() && this->statusCode == 0 && this->errorCode.IsEmpty() && this->errorMessage.IsEmpty() && this->acceptRanges.IsEmpty() && this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentLength == 0 && this->contentRange.IsEmpty() && false && this->eTag.IsEmpty() && expires.ToUnixTimestamp() <= 0 && this->expiration.IsEmpty() && lastModified.ToUnixTimestamp() <= 0 && this->missingMeta == 0 && this->metadata.Num() == 0 && this->objectLockMode == EAWSObjectLockMode::NOT_SET && this->objectLockLegalHoldStatus == EAWSObjectLockLegalHoldStatus::NOT_SET && this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && this->partsCount == 0 && this->replicationStatus == EAWSReplicationStatus::NOT_SET && this->requestCharged == EAWSRequestCharged::NOT_SET && this->restore.IsEmpty() && this->serverSideEncryption == EAWSServerSideEncryption::NOT_SET && this->sSECustomerAlgorithm.IsEmpty() && this->sSEKMSKeyId.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->storageClass == EAWSS3StorageClass::NOT_SET && this->tagCount == 0 && this->versionId.IsEmpty() && false && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
