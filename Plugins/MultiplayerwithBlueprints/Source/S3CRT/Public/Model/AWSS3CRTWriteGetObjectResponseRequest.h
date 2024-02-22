/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/WriteGetObjectResponseRequest.h"

#endif

#include "Model/AWSS3CRTObjectLockMode.h"
#include "Model/AWSS3CRTObjectLockLegalHoldStatus.h"
#include "Model/AWSS3CRTReplicationStatus.h"
#include "Model/AWSS3CRTRequestCharged.h"
#include "Model/AWSS3CRTServerSideEncryption.h"
#include "Model/AWSS3CRTStorageClass.h"

#include "AWSS3CRTWriteGetObjectResponseRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTWriteGetObjectResponseRequest {
GENERATED_BODY()

    /**
    *  <p>Route prefix to the HTTP URL generated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString requestRoute;

    /**
    *  <p>A single use encrypted token that maps <code>WriteGetObjectResponse</code> to the end user <code>GetObject</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString requestToken;

    /**
    *  <p>The integer status code for an HTTP response of a corresponding <code>GetObject</code> request.</p> <p class="title"> <b>Status Codes</b> </p> <ul> <li> <p> <i>200 - OK</i> </p> </li> <li> <p> <i>206 - Partial Content</i> </p> </li> <li> <p> <i>304 - Not Modified</i> </p> </li> <li> <p> <i>400 - Bad Request</i> </p> </li> <li> <p> <i>401 - Unauthorized</i> </p> </li> <li> <p> <i>403 - Forbidden</i> </p> </li> <li> <p> <i>404 - Not Found</i> </p> </li> <li> <p> <i>405 - Method Not Allowed</i> </p> </li> <li> <p> <i>409 - Conflict</i> </p> </li> <li> <p> <i>411 - Length Required</i> </p> </li> <li> <p> <i>412 - Precondition Failed</i> </p> </li> <li> <p> <i>416 - Range Not Satisfiable</i> </p> </li> <li> <p> <i>500 - Internal Server Error</i> </p> </li> <li> <p> <i>503 - Service Unavailable</i> </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int statusCode = 0;

    /**
    *  <p>A string that uniquely identifies an error condition. Returned in the &lt;Code&gt; tag of the error XML response for a corresponding <code>GetObject</code> call. Cannot be used with a successful <code>StatusCode</code> header or when the transformed object is provided in the body. All error codes from S3 are sentence-cased. Regex value is "^[A-Z][a-zA-Z]+$".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString errorCode;

    /**
    *  <p>Contains a generic description of the error condition. Returned in the &lt;Message&gt; tag of the error XML response for a corresponding <code>GetObject</code> call. Cannot be used with a successful <code>StatusCode</code> header or when the transformed object is provided in body.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString errorMessage;

    /**
    *  <p>Indicates that a range of bytes was specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString acceptRanges;

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
    *  <p>The size of the content body in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 contentLength = 0;

    /**
    *  <p>The portion of the object returned in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentRange;

    /**
    *  <p>Specifies whether an object stored in Amazon S3 is (<code>true</code>) or is not (<code>false</code>) a delete marker. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool deleteMarker = false;

    /**
    *  <p>An opaque identifier assigned by a web server to a specific version of a resource found at a URL. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>The date and time at which the object is no longer cacheable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime expires;

    /**
    *  <p>If object stored in Amazon S3 expiration is configured (see PUT Bucket lifecycle) it includes expiry-date and rule-id key-value pairs providing object expiration information. The value of the rule-id is URL encoded. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expiration;

    /**
    *  <p>The date and time that the object was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

    /**
    *  <p>Set to the number of metadata entries not returned in <code>x-amz-meta</code> headers. This can happen if you create metadata using an API like SOAP that supports more flexible metadata than the REST API. For example, using SOAP, you can create metadata whose values are not legal HTTP headers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int missingMeta = 0;

    /**
    *  <p>A map of metadata to store with the object in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> metadata;

    /**
    *  <p>Indicates whether an object stored in Amazon S3 has Object Lock enabled. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-lock.html">Object Lock</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockMode objectLockMode = EAWSS3CRTObjectLockMode::NOT_SET;

    /**
    *  <p>Indicates whether an object stored in Amazon S3 has an active legal hold.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;

    /**
    *  <p>The date and time when Object Lock is configured to expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>The count of parts this object has.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partsCount = 0;

    /**
    *  <p>Indicates if request involves bucket that is either a source or destination in a Replication rule. For more information about S3 Replication, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/replication.html">Replication</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTReplicationStatus replicationStatus = EAWSS3CRTReplicationStatus::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

    /**
    *  <p>Provides information about object restoration operation and expiration time of the restored object copy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString restore;

    /**
    *  <p> The server-side encryption algorithm used when storing requested object in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTServerSideEncryption serverSideEncryption = EAWSS3CRTServerSideEncryption::NOT_SET;

    /**
    *  <p>Encryption algorithm used if server-side encryption with a customer-provided encryption key was specified for object stored in Amazon S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p> If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for stored in Amazon S3 object. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSEKMSKeyId;

    /**
    *  <p> 128-bit MD5 digest of customer-provided encryption key used in Amazon S3 to encrypt data stored in S3. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ServerSideEncryptionCustomerKeys.html">Protecting data using server-side encryption with customer-provided encryption keys (SSE-C)</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p> The class of storage used to store object in Amazon S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    *  <p>The number of tags, if any, on the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int tagCount = 0;

    /**
    *  <p>An ID used to reference a specific version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p> Indicates whether the object stored in Amazon S3 uses an S3 bucket key for server-side encryption with AWS KMS (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::WriteGetObjectResponseRequest toAWS() const {
        Aws::S3Crt::Model::WriteGetObjectResponseRequest awsWriteGetObjectResponseRequest;

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
            case EAWSS3CRTObjectLockMode::GOVERNANCE:
                awsWriteGetObjectResponseRequest.SetObjectLockMode(Aws::S3Crt::Model::ObjectLockMode::GOVERNANCE);
                break;
            case EAWSS3CRTObjectLockMode::COMPLIANCE:
                awsWriteGetObjectResponseRequest.SetObjectLockMode(Aws::S3Crt::Model::ObjectLockMode::COMPLIANCE);
                break;
            default:
                break;
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSS3CRTObjectLockLegalHoldStatus::ON:
                awsWriteGetObjectResponseRequest.SetObjectLockLegalHoldStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSS3CRTObjectLockLegalHoldStatus::OFF:
                awsWriteGetObjectResponseRequest.SetObjectLockLegalHoldStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::OFF);
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
            case EAWSS3CRTReplicationStatus::COMPLETED:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3Crt::Model::ReplicationStatus::COMPLETED);
                break;
            case EAWSS3CRTReplicationStatus::PENDING:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3Crt::Model::ReplicationStatus::PENDING);
                break;
            case EAWSS3CRTReplicationStatus::FAILED:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3Crt::Model::ReplicationStatus::FAILED);
                break;
            case EAWSS3CRTReplicationStatus::REPLICA:
                awsWriteGetObjectResponseRequest.SetReplicationStatus(Aws::S3Crt::Model::ReplicationStatus::REPLICA);
                break;
            default:
                break;
        }

        switch(this->requestCharged) {
            case EAWSS3CRTRequestCharged::requester:
                awsWriteGetObjectResponseRequest.SetRequestCharged(Aws::S3Crt::Model::RequestCharged::requester);
                break;
            default:
                break;
        }

        if (!(this->restore.IsEmpty())) {
            awsWriteGetObjectResponseRequest.SetRestore(TCHAR_TO_UTF8(*this->restore));
        }

        switch(this->serverSideEncryption) {
            case EAWSS3CRTServerSideEncryption::AES256:
                awsWriteGetObjectResponseRequest.SetServerSideEncryption(Aws::S3Crt::Model::ServerSideEncryption::AES256);
                break;
            case EAWSS3CRTServerSideEncryption::aws_kms:
                awsWriteGetObjectResponseRequest.SetServerSideEncryption(Aws::S3Crt::Model::ServerSideEncryption::aws_kms);
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
            case EAWSS3CRTStorageClass::STANDARD:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD);
                break;
            case EAWSS3CRTStorageClass::REDUCED_REDUNDANCY:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3CRTStorageClass::STANDARD_IA:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTStorageClass::ONEZONE_IA:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTStorageClass::INTELLIGENT_TIERING:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTStorageClass::GLACIER:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::GLACIER);
                break;
            case EAWSS3CRTStorageClass::DEEP_ARCHIVE:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3CRTStorageClass::OUTPOSTS:
                awsWriteGetObjectResponseRequest.SetStorageClass(Aws::S3Crt::Model::StorageClass::OUTPOSTS);
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
        return this->requestRoute.IsEmpty() && this->requestToken.IsEmpty() && this->statusCode == 0 && this->errorCode.IsEmpty() && this->errorMessage.IsEmpty() && this->acceptRanges.IsEmpty() && this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->contentLength == 0 && this->contentRange.IsEmpty() && false && this->eTag.IsEmpty() && this->expires.ToUnixTimestamp() <= 0 && this->expiration.IsEmpty() && this->lastModified.ToUnixTimestamp() <= 0 && this->missingMeta == 0 && this->metadata.Num() == 0 && this->objectLockMode == EAWSS3CRTObjectLockMode::NOT_SET && this->objectLockLegalHoldStatus == EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET && this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && this->partsCount == 0 && this->replicationStatus == EAWSS3CRTReplicationStatus::NOT_SET && this->requestCharged == EAWSS3CRTRequestCharged::NOT_SET && this->restore.IsEmpty() && this->serverSideEncryption == EAWSS3CRTServerSideEncryption::NOT_SET && this->sSECustomerAlgorithm.IsEmpty() && this->sSEKMSKeyId.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->storageClass == EAWSS3CRTStorageClass::NOT_SET && this->tagCount == 0 && this->versionId.IsEmpty() && false && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
