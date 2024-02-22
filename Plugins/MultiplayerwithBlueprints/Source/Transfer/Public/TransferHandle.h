/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

#include "aws/transfer/TransferHandle.h"

#endif

#include "S3Error.h"

#include "TransferHandle.generated.h"

USTRUCT(BlueprintType)
struct FDownloadConfiguration {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString versionId;

#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    Aws::Transfer::DownloadConfiguration toAWS() const {
        Aws::Transfer::DownloadConfiguration awsDownloadConfiguration;

        if (this->versionId.IsEmpty()) {
            awsDownloadConfiguration.versionId = TCHAR_TO_UTF8(*this->versionId);
        }

        return awsDownloadConfiguration;
    }
#endif
};

UCLASS(BlueprintType)
class TRANSFER_API UPartState : public UObject {
GENERATED_BODY()

public:
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    std::shared_ptr<Aws::Transfer::PartState> awsPartState;
#endif
    ~UPartState();

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int GetPartId ();

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int64 GetBestProgressInBytes ();

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int64 GetSizeInBytes ();

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetETag ();

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    bool IsLastPart ();
};

UENUM(BlueprintType)
enum class ETransferStatus : uint8 {
    UNKNOWN UMETA(DisplayName = "Unknow"),
    EXACT_OBJECT_ALREADY_EXISTS UMETA(DisplayName = "Exact Object Already Exists"),
    NOT_STARTED UMETA(DisplayName = "Not Started"),
    IN_PROGRESS UMETA(DisplayName = "In Progress"),
    CANCELED UMETA(DisplayName = "Cancel"),
    FAILED UMETA(DisplayName = "Failed"),
    COMPLETED UMETA(DisplayName = "Completed"),
    ABORTED UMETA(DisplayName = "Aborted"),
};

UENUM(BlueprintType)
enum class ETransferDirection : uint8 {
    UNKNOWN UMETA(DisplayName = "Unknow"),
    UPLOAD UMETA(DisplayName = "Upload"),
    DOWNLOAD UMETA(DisplayName = "DOWNLOAD")
};

/**
* This is the interface for interacting with an in-process transfer. All operations from TransferManager return an instance of this class.
* In addition to the status of the transfer and details about what operation is being performed, this class also has the Cancel() operation which is used to cancel a transfer, and WaitUntilCompleted() which will cause the calling thread to block until the transfer is finished.
*
* In the context that by the time you are using this class, it is thread safe.
*/
UCLASS(BlueprintType)
class TRANSFER_API UTransferHandle : public UObject {
    GENERATED_BODY()

public:
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    std::shared_ptr<Aws::Transfer::TransferHandle> awsTransferHandle;
#endif
    ~UTransferHandle();

    /**
     * Whether or not this transfer is being performed using parallel parts via a multi-part s3 api.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    bool IsMultipart ();

    /**
     * If this is a multi-part transfer, this is the ID of it. e.g. UploadId for UploadPart
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetMultiPartId ();

    /**
     * Returns a copy of the completed parts, in the structure of <partId, ETag>. Used for all transfers.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    TMap<int, UPartState*> GetCompletedParts ();

    /**
     * Returns a copy of the pending parts. Used for all transfers.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    TMap<int, UPartState*> GetPendingParts ();

    /**
     * Returns true or false if there are currently any pending parts.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    bool HasPendingParts ();

    /**
     * Returns a copy of the queued parts. Used for all transfers.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    TMap<int, UPartState*> GetQueuedParts ();

    /**
     * Returns true or false if there are currently any queued parts.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    bool HasQueuedParts ();

    /**
     * Returns a copy of the failed parts. Used for all transfers.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    TMap<int, UPartState*> GetFailedParts ();

    /**
     * Returns true or false if there are currently any failed parts.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    bool HasFailedParts ();

    /**
     * Returns true or false if any parts have been created for this transfer
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    bool HasParts ();

    /**
     * Cancel the transfer. This will happen asynchronously, so if you need to wait for it to be canceled, either handle the callbacks.
     */
    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void Cancel ();

    /**
     * Reset the cancellation status for a retry. This will be done automatically by Transfermanager.
     */
    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void Restart ();

    /**
     * Total bytes transferred successfully on this transfer operation.
     * We implement transfer progress with two invariants:
     *  (1) Never lock; given a callback that can happen hundreds of times a second or more on a solid connection, it isn't acceptable to lock each time
     *  (2) Never go backwards, in spite of part upload/download failures.  Negative progress (canceling a highly concurrent transfer can
     *      lead to an enormous step backwards if many parts are aborted at once) is a confusing and undesirable user experience.
     * In this sense, progress represents a high-water mark, and in the presence of heavy failures or cancellation, it may appear to pause until the necessary retries exceed the previous high-water mark.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int64 GetBytesTransferred ();

    /**
     * The offset from which to start downloading
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int64 GetBytesOffset ();

    /**
     * The calculated total size of the object being transferred.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int64 GetBytesTotalSize ();

    /**
     * The calculated total size of the object being transferred.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    int64 GetBytesAvailableFromStart ();

    /**
     * Bucket portion of the object location in Amazon S3.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetBucketName ();

    /**
     * Key of the object location in Amazon S3.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetKey ();

    /**
     * If known, this is the location of the local file being uploaded from, or downloaded to. If you use the stream api however, this will always be blank.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetTargetFilePath ();

    /**
     * (Download only) version id of the object to retrieve; if not specified in constructor, then latest is used
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetVersionId ();

    /**
     * Upload or Download?
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    ETransferDirection GetTransferDirection ();

    /**
     * Content type of the object being transferred
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetContentType ();

    /**
     * In case of an upload, this is the metadata that was placed on the object when it was uploaded.
     * In the case of a download, this is the object metadata from the GetObject operation.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    TMap<FString, FString> GetMetadata ();

    /**
     * The current status of the operation
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    ETransferStatus GetStatus ();

    /**
     * The last error that was encountered by the transfer. You can handle each error individually via the errorCallback callback function in the TransferConfiguration.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    ES3Error GetLastError ();

    /**
     * Returns a unique identifier tied to this particular transfer handle.
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Transfer")
    FString GetId ();
};

USTRUCT(BlueprintType)
struct FConstPartState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    int PartId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    int64 BestProgressInBytes = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    int64 SizeInBytes = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString ETag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    bool IsLastPart = false;

#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    public:
    FConstPartState &fromAWS(const std::shared_ptr<Aws::Transfer::PartState> &awsPartState) {
        this->PartId = awsPartState->GetPartId();

        this->BestProgressInBytes = (int64)awsPartState->GetBestProgressInBytes();

        this->SizeInBytes = (int64)awsPartState->GetSizeInBytes();
        
        this->ETag = UTF8_TO_TCHAR(awsPartState->GetETag().c_str());
        
        this->IsLastPart = awsPartState->IsLastPart();

        return *this;
    }
#endif
};

USTRUCT(BlueprintType)
struct FConstTransferHandle {
    GENERATED_BODY()
public:
    /**
     * Whether or not this transfer is being performed using parallel parts via a multi-part s3 api.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    bool IsMultipart = false;

    /**
     * If this is a multi-part transfer, this is the ID of it. e.g. UploadId for UploadPart
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString MultiPartId;

    /**
     * Returns a copy of the completed parts, in the structure of <partId, ETag>. Used for all transfers.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    TMap<int, FConstPartState> CompletedParts;

    /**
     * Returns a copy of the pending parts. Used for all transfers.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    TMap<int, FConstPartState> PendingParts;

    /**
     * Returns true or false if there are currently any pending parts.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    bool HasPendingParts = false;

    /**
     * Returns a copy of the queued parts. Used for all transfers.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    TMap<int, FConstPartState> QueuedParts;

    /**
     * Returns true or false if there are currently any queued parts.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    bool HasQueuedParts = false;

    /**
     * Returns a copy of the failed parts. Used for all transfers.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    TMap<int, FConstPartState> FailedParts;

    /**
     * Returns true or false if there are currently any failed parts.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    bool HasFailedParts = false;

    /**
     * Returns true or false if any parts have been created for this transfer
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    bool HasParts = false;

    /**
     * Total bytes transferred successfully on this transfer operation.
     * We implement transfer progress with two invariants:
     *  (1) Never lock; given a callback that can happen hundreds of times a second or more on a solid connection, it isn't acceptable to lock each time
     *  (2) Never go backwards, in spite of part upload/download failures.  Negative progress (canceling a highly concurrent transfer can
     *      lead to an enormous step backwards if many parts are aborted at once) is a confusing and undesirable user experience.
     * In this sense, progress represents a high-water mark, and in the presence of heavy failures or cancellation, it may appear to pause until the necessary retries exceed the previous high-water mark.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    int64 BytesTransferred = 0;

    /**
     * The offset from which to start downloading
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    int64 BytesOffset = 0;

    /**
     * The calculated total size of the object being transferred.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    int64 BytesTotalSize = 0;

    /**
     * Bucket portion of the object location in Amazon S3.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString BucketName;

    /**
     * Key of the object location in Amazon S3.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString Key;

    /**
     * If known, this is the location of the local file being uploaded from, or downloaded to. If you use the stream api however, this will always be blank.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString TargetFilePath;

    /**
     * (Download only) version id of the object to retrieve; if not specified in constructor, then latest is used
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString VersionId;

    /**
     * Upload or Download?
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    ETransferDirection TransferDirection = ETransferDirection::UNKNOWN;

    /**
     * Content type of the object being transferred
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString ContentType;

    /**
     * In case of an upload, this is the metadata that was placed on the object when it was uploaded.
     * In the case of a download, this is the object metadata from the GetObject operation.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    TMap<FString, FString> Metadata;

    /**
     * The current status of the operation
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    ETransferStatus Status = ETransferStatus::UNKNOWN;

    /**
     * The last error that was encountered by the transfer. You can handle each error individually via the errorCallback callback function in the TransferConfiguration.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    ES3Error LastError = ES3Error::UNKNOWN;

    /**
     * Returns a unique identifier tied to this particular transfer handle.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer")
    FString Id;

#if WITH_TRANSFERCLIENTSDK && WITH_CORE
public:
    FConstTransferHandle &fromAWS(const std::shared_ptr<const Aws::Transfer::TransferHandle> &awsTransferHandle) {
        this->IsMultipart = awsTransferHandle->IsMultipart();
        
        this->MultiPartId = UTF8_TO_TCHAR(awsTransferHandle->GetMultiPartId().c_str());
        
        for (const auto& elem : awsTransferHandle->GetCompletedParts()) {
            this->CompletedParts.Add(elem.first, FConstPartState().fromAWS(elem.second));
        }
        
        for (const auto& elem : awsTransferHandle->GetPendingParts()) {
            this->PendingParts.Add(elem.first, FConstPartState().fromAWS(elem.second));
        }
        
        this->HasPendingParts = awsTransferHandle->HasPendingParts();
        
        for (const auto& elem : awsTransferHandle->GetQueuedParts()) {
            this->QueuedParts.Add(elem.first, FConstPartState().fromAWS(elem.second));
        }
        
        this->HasQueuedParts = awsTransferHandle->HasQueuedParts();
        
        for (const auto& elem : awsTransferHandle->GetFailedParts()) {
            this->FailedParts.Add(elem.first, FConstPartState().fromAWS(elem.second));
        }
        
        this->HasFailedParts = awsTransferHandle->HasFailedParts();
        
        this->HasParts = awsTransferHandle->HasParts();
        
        this->BytesTransferred = (int64)awsTransferHandle->GetBytesTransferred();
        
        this->BytesOffset = (int64)awsTransferHandle->GetBytesOffset();
        
        this->BytesTotalSize = (int64)awsTransferHandle->GetBytesTotalSize();
        
        this->BucketName = UTF8_TO_TCHAR(awsTransferHandle->GetBucketName().c_str());
        
        this->Key = UTF8_TO_TCHAR(awsTransferHandle->GetKey().c_str());
        
        this->TargetFilePath = UTF8_TO_TCHAR(awsTransferHandle->GetTargetFilePath().c_str());
        
        this->VersionId = UTF8_TO_TCHAR(awsTransferHandle->GetVersionId().c_str());
        
        switch (awsTransferHandle->GetTransferDirection()) {
            case Aws::Transfer::TransferDirection::UPLOAD:
                this->TransferDirection = ETransferDirection::UPLOAD;
                break;
            case Aws::Transfer::TransferDirection::DOWNLOAD:
                this->TransferDirection = ETransferDirection::DOWNLOAD;
                break;
        }
        
        this->ContentType = UTF8_TO_TCHAR(awsTransferHandle->GetContentType().c_str());
        
        for (const auto& elem : awsTransferHandle->GetMetadata()) {
            this->Metadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }
        
        switch (awsTransferHandle->GetStatus()) {
            case Aws::Transfer::TransferStatus::EXACT_OBJECT_ALREADY_EXISTS:
                this->Status = ETransferStatus::EXACT_OBJECT_ALREADY_EXISTS;
                break;
            case Aws::Transfer::TransferStatus::NOT_STARTED:
                this->Status = ETransferStatus::NOT_STARTED;
                break;
            case Aws::Transfer::TransferStatus::IN_PROGRESS:
                this->Status = ETransferStatus::IN_PROGRESS;
                break;
            case Aws::Transfer::TransferStatus::CANCELED:
                this->Status = ETransferStatus::CANCELED;
                break;
            case Aws::Transfer::TransferStatus::FAILED:
                this->Status = ETransferStatus::FAILED;
                break;
            case Aws::Transfer::TransferStatus::COMPLETED:
                this->Status = ETransferStatus::COMPLETED;
                break;
            case Aws::Transfer::TransferStatus::ABORTED:
                this->Status = ETransferStatus::ABORTED;
                break;
        }
        
        switch (awsTransferHandle->GetLastError().GetErrorType()) {
            case Aws::S3::S3Errors::INCOMPLETE_SIGNATURE:
                this->LastError = ES3Error::INCOMPLETE_SIGNATURE;
                break;
            case Aws::S3::S3Errors::INTERNAL_FAILURE:
                this->LastError = ES3Error::INTERNAL_FAILURE;
                break;
            case Aws::S3::S3Errors::INVALID_ACTION:
                this->LastError = ES3Error::INVALID_ACTION;
                break;
            case Aws::S3::S3Errors::INVALID_CLIENT_TOKEN_ID:
                this->LastError = ES3Error::INVALID_CLIENT_TOKEN_ID;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_COMBINATION:
                this->LastError = ES3Error::INVALID_PARAMETER_COMBINATION;
                break;
            case Aws::S3::S3Errors::INVALID_QUERY_PARAMETER:
                this->LastError = ES3Error::INVALID_QUERY_PARAMETER;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_VALUE:
                this->LastError = ES3Error::INVALID_PARAMETER_VALUE;
                break;
            case Aws::S3::S3Errors::MISSING_ACTION:
                this->LastError = ES3Error::MISSING_ACTION;
                break;
            case Aws::S3::S3Errors::MISSING_AUTHENTICATION_TOKEN:
                this->LastError = ES3Error::MISSING_AUTHENTICATION_TOKEN;
                break;
            case Aws::S3::S3Errors::MISSING_PARAMETER:
                this->LastError = ES3Error::MISSING_PARAMETER;
                break;
            case Aws::S3::S3Errors::OPT_IN_REQUIRED:
                this->LastError = ES3Error::OPT_IN_REQUIRED;
                break;
            case Aws::S3::S3Errors::REQUEST_EXPIRED:
                this->LastError = ES3Error::REQUEST_EXPIRED;
                break;
            case Aws::S3::S3Errors::SERVICE_UNAVAILABLE:
                this->LastError = ES3Error::SERVICE_UNAVAILABLE;
                break;
            case Aws::S3::S3Errors::THROTTLING:
                this->LastError = ES3Error::THROTTLING;
                break;
            case Aws::S3::S3Errors::VALIDATION:
                this->LastError = ES3Error::VALIDATION;
                break;
            case Aws::S3::S3Errors::ACCESS_DENIED:
                this->LastError = ES3Error::ACCESS_DENIED;
                break;
            case Aws::S3::S3Errors::RESOURCE_NOT_FOUND:
                this->LastError = ES3Error::RESOURCE_NOT_FOUND;
                break;
            case Aws::S3::S3Errors::UNRECOGNIZED_CLIENT:
                this->LastError = ES3Error::UNRECOGNIZED_CLIENT;
                break;
            case Aws::S3::S3Errors::MALFORMED_QUERY_STRING:
                this->LastError = ES3Error::MALFORMED_QUERY_STRING;
                break;
            case Aws::S3::S3Errors::SLOW_DOWN:
                this->LastError = ES3Error::SLOW_DOWN;
                break;
            case Aws::S3::S3Errors::REQUEST_TIME_TOO_SKEWED:
                this->LastError = ES3Error::REQUEST_TIME_TOO_SKEWED;
                break;
            case Aws::S3::S3Errors::INVALID_SIGNATURE:
                this->LastError = ES3Error::INVALID_SIGNATURE;
                break;
            case Aws::S3::S3Errors::SIGNATURE_DOES_NOT_MATCH:
                this->LastError = ES3Error::SIGNATURE_DOES_NOT_MATCH;
                break;
            case Aws::S3::S3Errors::INVALID_ACCESS_KEY_ID:
                this->LastError = ES3Error::INVALID_ACCESS_KEY_ID;
                break;
            case Aws::S3::S3Errors::REQUEST_TIMEOUT:
                this->LastError = ES3Error::REQUEST_TIMEOUT;
                break;
            case Aws::S3::S3Errors::NETWORK_CONNECTION:
                this->LastError = ES3Error::NETWORK_CONNECTION;
                break;
            case Aws::S3::S3Errors::UNKNOWN:
                this->LastError = ES3Error::UNKNOWN;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_EXISTS:
                this->LastError = ES3Error::BUCKET_ALREADY_EXISTS;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_OWNED_BY_YOU:
                this->LastError = ES3Error::BUCKET_ALREADY_OWNED_BY_YOU;
                break;
            case Aws::S3::S3Errors::NO_SUCH_BUCKET:
                this->LastError = ES3Error::NO_SUCH_BUCKET;
                break;
            case Aws::S3::S3Errors::NO_SUCH_KEY:
                this->LastError = ES3Error::NO_SUCH_KEY;
                break;
            case Aws::S3::S3Errors::NO_SUCH_UPLOAD:
                this->LastError = ES3Error::NO_SUCH_UPLOAD;
                break;
            case Aws::S3::S3Errors::OBJECT_ALREADY_IN_ACTIVE_TIER:
                this->LastError = ES3Error::OBJECT_ALREADY_IN_ACTIVE_TIER;
                break;
            case Aws::S3::S3Errors::OBJECT_NOT_IN_ACTIVE_TIER:
                this->LastError = ES3Error::OBJECT_NOT_IN_ACTIVE_TIER;
                break;
            default:
                this->LastError = ES3Error::UNKNOWN;
                break;
        }
        
        this->Id = UTF8_TO_TCHAR(awsTransferHandle->GetId().c_str());

        return *this;
    }
#endif
};