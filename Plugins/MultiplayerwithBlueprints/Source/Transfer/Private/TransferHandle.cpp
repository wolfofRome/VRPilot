/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "TransferHandle.h"
#include "TransferGlobals.h"
#include "TransferPrivatePCH.h"

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#endif

UPartState::~UPartState() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    this->awsPartState = nullptr;
#endif
}

int UPartState::GetPartId() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsPartState == nullptr) {
        return 0;
    }
    return this->awsPartState->GetPartId();
#endif
    return 0;
}

int64 UPartState::GetBestProgressInBytes() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsPartState == nullptr) {
        return 0;
    }
    return (int64)this->awsPartState->GetBestProgressInBytes();
#endif
    return 0;
}

int64 UPartState::GetSizeInBytes() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsPartState == nullptr) {
        return 0;
    }
    return (int64)this->awsPartState->GetSizeInBytes();
#endif
    return 0;
}

FString UPartState::GetETag() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsPartState == nullptr) {
        return FString();
    }
    return UTF8_TO_TCHAR(this->awsPartState->GetETag().c_str());
#endif
    return FString();
}

bool UPartState::IsLastPart() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsPartState == nullptr) {
        return false;
    }
    return this->awsPartState->IsLastPart();
#endif
    return false;
}

UTransferHandle::~UTransferHandle() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    this->awsTransferHandle = nullptr;
#endif
}

bool UTransferHandle::IsMultipart () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return this->awsTransferHandle->IsMultipart();
    }
    return false;
#endif
    return false;
}

FString UTransferHandle::GetMultiPartId () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetMultiPartId().c_str());
    }
    return FString();
#endif
    return FString();
}

TMap<int, UPartState*> UTransferHandle::GetCompletedParts () {
    TMap<int, UPartState*> completedParts;
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        for (const auto& elem : this->awsTransferHandle->GetCompletedParts()) {
            UPartState* partState = NewObject<UPartState>();
            partState->awsPartState = elem.second;
            completedParts.Add(elem.first, partState);
        }
    }
#endif
    return completedParts;
}

TMap<int, UPartState*> UTransferHandle::GetPendingParts () {
    TMap<int, UPartState*> pendingParts;
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        for (const auto& elem : this->awsTransferHandle->GetPendingParts()) {
            UPartState* partState = NewObject<UPartState>();
            partState->awsPartState = elem.second;
            pendingParts.Add(elem.first, partState);
        }
    }
#endif
    return pendingParts;
}

bool UTransferHandle::HasPendingParts () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return this->awsTransferHandle->HasPendingParts();
    }
    return false;
#endif
    return false;
}

TMap<int, UPartState*> UTransferHandle::GetQueuedParts () {
    TMap<int, UPartState*> queuedParts;
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        for (const auto& elem : this->awsTransferHandle->GetQueuedParts()) {
            UPartState* partState = NewObject<UPartState>();
            partState->awsPartState = elem.second;
            queuedParts.Add(elem.first, partState);
        }
    }
#endif
    return queuedParts;
}

bool UTransferHandle::HasQueuedParts () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return this->awsTransferHandle->HasQueuedParts();
    }
    return false;
#endif
    return false;
}

TMap<int, UPartState*> UTransferHandle::GetFailedParts () {
    TMap<int, UPartState*> failedParts;
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        for (const auto& elem : this->awsTransferHandle->GetFailedParts()) {
            UPartState* partState = NewObject<UPartState>();
            partState->awsPartState = elem.second;
            failedParts.Add(elem.first, partState);
        }
    }
#endif
    return failedParts;
}

bool UTransferHandle::HasFailedParts () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return this->awsTransferHandle->HasFailedParts();
    }
    return false;
#endif
    return false;
}

bool UTransferHandle::HasParts () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return this->awsTransferHandle->HasParts();
    }
    return false;
#endif
    return false;
}

void UTransferHandle::Cancel () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        this->awsTransferHandle->Cancel();
    }
#endif
    return;
}

void UTransferHandle::Restart () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        this->awsTransferHandle->Restart();
    }
#endif
    return;
}

int64 UTransferHandle::GetBytesTransferred () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return (int64)this->awsTransferHandle->GetBytesTransferred();
    }
#endif
    return 0;
}

int64 UTransferHandle::GetBytesOffset () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return (int64)this->awsTransferHandle->GetBytesOffset();
    }
#endif
    return 0;
}

int64 UTransferHandle::GetBytesTotalSize () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return (int64)this->awsTransferHandle->GetBytesTotalSize();
    }
#endif
    return 0;
}

int64 UTransferHandle::GetBytesAvailableFromStart () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return (int64)this->awsTransferHandle->GetBytesAvailableFromStart();
    }
#endif
    return 0;
}

FString UTransferHandle::GetBucketName () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetBucketName().c_str());
    }
#endif
    return FString();
}

FString UTransferHandle::GetKey () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetKey().c_str());
    }
#endif
    return FString();
}

FString UTransferHandle::GetTargetFilePath () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetTargetFilePath().c_str());
    }
#endif
    return FString();
}

FString UTransferHandle::GetVersionId () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetVersionId().c_str());
    }
#endif
    return FString();
}

ETransferDirection UTransferHandle::GetTransferDirection () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        switch (this->awsTransferHandle->GetTransferDirection()) {
            case Aws::Transfer::TransferDirection::UPLOAD:
                return ETransferDirection::UPLOAD;
                break;
            case Aws::Transfer::TransferDirection::DOWNLOAD:
                return ETransferDirection::DOWNLOAD;
                break;
            default:
                return ETransferDirection::UNKNOWN;
                break;
        }
    }
#endif
    return ETransferDirection::UNKNOWN;
}

FString UTransferHandle::GetContentType () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetContentType().c_str());
    }
#endif
    return FString();
}

TMap<FString, FString> UTransferHandle::GetMetadata () {
    TMap<FString, FString> metadata;
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        for (const auto& elem : this->awsTransferHandle->GetMetadata()) {
            metadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }
    }
#endif
    return metadata;
}

ETransferStatus UTransferHandle::GetStatus () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        switch (this->awsTransferHandle->GetStatus()) {
            case Aws::Transfer::TransferStatus::EXACT_OBJECT_ALREADY_EXISTS:
                return ETransferStatus::EXACT_OBJECT_ALREADY_EXISTS;
                break;
            case Aws::Transfer::TransferStatus::NOT_STARTED:
                return ETransferStatus::NOT_STARTED;
                break;
            case Aws::Transfer::TransferStatus::IN_PROGRESS:
                return ETransferStatus::IN_PROGRESS;
                break;
            case Aws::Transfer::TransferStatus::CANCELED:
                return ETransferStatus::CANCELED;
                break;
            case Aws::Transfer::TransferStatus::FAILED:
                return ETransferStatus::FAILED;
                break;
            case Aws::Transfer::TransferStatus::COMPLETED:
                return ETransferStatus::COMPLETED;
                break;
            case Aws::Transfer::TransferStatus::ABORTED:
                return ETransferStatus::ABORTED;
                break;
            default:
                return ETransferStatus::UNKNOWN;
                break;
        }
    }
#endif
    return ETransferStatus::UNKNOWN;
}

ES3Error UTransferHandle::GetLastError () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        switch (this->awsTransferHandle->GetLastError().GetErrorType()) {
            case Aws::S3::S3Errors::INCOMPLETE_SIGNATURE:
                return ES3Error::INCOMPLETE_SIGNATURE;
                break;
            case Aws::S3::S3Errors::INTERNAL_FAILURE:
                return ES3Error::INTERNAL_FAILURE;
                break;
            case Aws::S3::S3Errors::INVALID_ACTION:
                return ES3Error::INVALID_ACTION;
                break;
            case Aws::S3::S3Errors::INVALID_CLIENT_TOKEN_ID:
                return ES3Error::INVALID_CLIENT_TOKEN_ID;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_COMBINATION:
                return ES3Error::INVALID_PARAMETER_COMBINATION;
                break;
            case Aws::S3::S3Errors::INVALID_QUERY_PARAMETER:
                return ES3Error::INVALID_QUERY_PARAMETER;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_VALUE:
                return ES3Error::INVALID_PARAMETER_VALUE;
                break;
            case Aws::S3::S3Errors::MISSING_ACTION:
                return ES3Error::MISSING_ACTION;
                break;
            case Aws::S3::S3Errors::MISSING_AUTHENTICATION_TOKEN:
                return ES3Error::MISSING_AUTHENTICATION_TOKEN;
                break;
            case Aws::S3::S3Errors::MISSING_PARAMETER:
                return ES3Error::MISSING_PARAMETER;
                break;
            case Aws::S3::S3Errors::OPT_IN_REQUIRED:
                return ES3Error::OPT_IN_REQUIRED;
                break;
            case Aws::S3::S3Errors::REQUEST_EXPIRED:
                return ES3Error::REQUEST_EXPIRED;
                break;
            case Aws::S3::S3Errors::SERVICE_UNAVAILABLE:
                return ES3Error::SERVICE_UNAVAILABLE;
                break;
            case Aws::S3::S3Errors::THROTTLING:
                return ES3Error::THROTTLING;
                break;
            case Aws::S3::S3Errors::VALIDATION:
                return ES3Error::VALIDATION;
                break;
            case Aws::S3::S3Errors::ACCESS_DENIED:
                return ES3Error::ACCESS_DENIED;
                break;
            case Aws::S3::S3Errors::RESOURCE_NOT_FOUND:
                return ES3Error::RESOURCE_NOT_FOUND;
                break;
            case Aws::S3::S3Errors::UNRECOGNIZED_CLIENT:
                return ES3Error::UNRECOGNIZED_CLIENT;
                break;
            case Aws::S3::S3Errors::MALFORMED_QUERY_STRING:
                return ES3Error::MALFORMED_QUERY_STRING;
                break;
            case Aws::S3::S3Errors::SLOW_DOWN:
                return ES3Error::SLOW_DOWN;
                break;
            case Aws::S3::S3Errors::REQUEST_TIME_TOO_SKEWED:
                return ES3Error::REQUEST_TIME_TOO_SKEWED;
                break;
            case Aws::S3::S3Errors::INVALID_SIGNATURE:
                return ES3Error::INVALID_SIGNATURE;
                break;
            case Aws::S3::S3Errors::SIGNATURE_DOES_NOT_MATCH:
                return ES3Error::SIGNATURE_DOES_NOT_MATCH;
                break;
            case Aws::S3::S3Errors::INVALID_ACCESS_KEY_ID:
                return ES3Error::INVALID_ACCESS_KEY_ID;
                break;
            case Aws::S3::S3Errors::REQUEST_TIMEOUT:
                return ES3Error::REQUEST_TIMEOUT;
                break;
            case Aws::S3::S3Errors::NETWORK_CONNECTION:
                return ES3Error::NETWORK_CONNECTION;
                break;
            case Aws::S3::S3Errors::UNKNOWN:
                return ES3Error::UNKNOWN;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_EXISTS:
                return ES3Error::BUCKET_ALREADY_EXISTS;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_OWNED_BY_YOU:
                return ES3Error::BUCKET_ALREADY_OWNED_BY_YOU;
                break;
            case Aws::S3::S3Errors::NO_SUCH_BUCKET:
                return ES3Error::NO_SUCH_BUCKET;
                break;
            case Aws::S3::S3Errors::NO_SUCH_KEY:
                return ES3Error::NO_SUCH_KEY;
                break;
            case Aws::S3::S3Errors::NO_SUCH_UPLOAD:
                return ES3Error::NO_SUCH_UPLOAD;
                break;
            case Aws::S3::S3Errors::OBJECT_ALREADY_IN_ACTIVE_TIER:
                return ES3Error::OBJECT_ALREADY_IN_ACTIVE_TIER;
                break;
            case Aws::S3::S3Errors::OBJECT_NOT_IN_ACTIVE_TIER:
                return ES3Error::OBJECT_NOT_IN_ACTIVE_TIER;
                break;
            default:
                return ES3Error::UNKNOWN;
                break;
        }
    }
#endif
    return ES3Error::UNKNOWN;
}

FString UTransferHandle::GetId () {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    if (this->awsTransferHandle != nullptr) {
        return UTF8_TO_TCHAR(this->awsTransferHandle->GetId().c_str());
    }
#endif
    return FString();
}