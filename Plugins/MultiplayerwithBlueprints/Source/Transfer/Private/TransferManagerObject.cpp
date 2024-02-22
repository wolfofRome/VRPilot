/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "TransferManagerObject.h"
#include "TransferGlobals.h"
#include "TransferPrivatePCH.h"

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#endif

UTransferManagerConfiguration::~UTransferManagerConfiguration() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    this->executor = nullptr;
#endif
}

void UTransferManagerConfiguration::uploadProgressCallback_Implementation(const FConstTransferHandle transferHandle) const {
}

void UTransferManagerConfiguration::downloadProgressCallback_Implementation(const FConstTransferHandle transferHandle) const {
}

void UTransferManagerConfiguration::transferStatusUpdatedCallback_Implementation(const FConstTransferHandle transferHandle) const {
}

void UTransferManagerConfiguration::transferInitiatedCallback_Implementation(const FConstTransferHandle transferHandle) const {
}

void UTransferManagerConfiguration::errorCallback_Implementation(const FConstTransferHandle transferHandle, const ES3Error error) const {
}

#if WITH_S3CLIENTSDK && WITH_TRANSFERCLIENTSDK && WITH_CORE
Aws::Transfer::TransferManagerConfiguration UTransferManagerConfiguration::toAWS() {
    this->executor = Aws::MakeShared<Aws::Utils::Threading::PooledThreadExecutor>("Transfer Manager Configuration", this->maxThreadExecutor);

    Aws::Transfer::TransferManagerConfiguration awsTransferManagerConfiguration(this->executor.get());

    awsTransferManagerConfiguration.s3Client = std::shared_ptr<Aws::S3::S3Client>(this->s3Client->awsS3Client);

    awsTransferManagerConfiguration.computeContentMD5 = this->computeContentMD5;

    if (!(this->putObjectTemplate.IsEmpty())) {
        awsTransferManagerConfiguration.putObjectTemplate = this->putObjectTemplate.toAWS();
    }

    if (!(this->getObjectTemplate.IsEmpty())) {
        awsTransferManagerConfiguration.getObjectTemplate = this->getObjectTemplate.toAWS();
    }

    if (!(this->createMultipartUploadTemplate.IsEmpty())) {
        awsTransferManagerConfiguration.createMultipartUploadTemplate = this->createMultipartUploadTemplate.toAWS();
    }

    if (!(this->uploadPartTemplate.IsEmpty())) {
        awsTransferManagerConfiguration.uploadPartTemplate = this->uploadPartTemplate.toAWS();
    }

    awsTransferManagerConfiguration.transferBufferMaxHeapSize = (uint64_t)this->transferBufferMaxHeapSize;

    awsTransferManagerConfiguration.bufferSize = (uint64_t)this->bufferSize;

    awsTransferManagerConfiguration.uploadProgressCallback = [this](
            const Aws::Transfer::TransferManager* awsTransferManager, const std::shared_ptr<const Aws::Transfer::TransferHandle>& awsTransferHandle
    ) {
        this->uploadProgressCallback(FConstTransferHandle().fromAWS(awsTransferHandle));
    };

    awsTransferManagerConfiguration.downloadProgressCallback = [this](
            const Aws::Transfer::TransferManager* awsTransferManager, const std::shared_ptr<const Aws::Transfer::TransferHandle>& awsTransferHandle
    ) {
        this->downloadProgressCallback(FConstTransferHandle().fromAWS(awsTransferHandle));
    };

    awsTransferManagerConfiguration.transferStatusUpdatedCallback = [this](
            const Aws::Transfer::TransferManager* awsTransferManager, const std::shared_ptr<const Aws::Transfer::TransferHandle>& awsTransferHandle
    ) {
        this->transferStatusUpdatedCallback(FConstTransferHandle().fromAWS(awsTransferHandle));
    };

    awsTransferManagerConfiguration.transferInitiatedCallback = [this](
            const Aws::Transfer::TransferManager* awsTransferManager, const std::shared_ptr<const Aws::Transfer::TransferHandle>& awsTransferHandle
    ) {
        this->transferInitiatedCallback(FConstTransferHandle().fromAWS(awsTransferHandle));
    };

    awsTransferManagerConfiguration.errorCallback = [this](
            const Aws::Transfer::TransferManager* awsTransferManager, const std::shared_ptr<const Aws::Transfer::TransferHandle>& awsTransferHandle, const Aws::Client::AWSError<Aws::S3::S3Errors>& awsError
    ) {
        ES3Error error = ES3Error::UNKNOWN;

        switch (awsError.GetErrorType()) {
            case Aws::S3::S3Errors::INCOMPLETE_SIGNATURE:
                error = ES3Error::INCOMPLETE_SIGNATURE;
                break;
            case Aws::S3::S3Errors::INTERNAL_FAILURE:
                error = ES3Error::INTERNAL_FAILURE;
                break;
            case Aws::S3::S3Errors::INVALID_ACTION:
                error = ES3Error::INVALID_ACTION;
                break;
            case Aws::S3::S3Errors::INVALID_CLIENT_TOKEN_ID:
                error = ES3Error::INVALID_CLIENT_TOKEN_ID;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_COMBINATION:
                error = ES3Error::INVALID_PARAMETER_COMBINATION;
                break;
            case Aws::S3::S3Errors::INVALID_QUERY_PARAMETER:
                error = ES3Error::INVALID_QUERY_PARAMETER;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_VALUE:
                error = ES3Error::INVALID_PARAMETER_VALUE;
                break;
            case Aws::S3::S3Errors::MISSING_ACTION:
                error = ES3Error::MISSING_ACTION;
                break;
            case Aws::S3::S3Errors::MISSING_AUTHENTICATION_TOKEN:
                error = ES3Error::MISSING_AUTHENTICATION_TOKEN;
                break;
            case Aws::S3::S3Errors::MISSING_PARAMETER:
                error = ES3Error::MISSING_PARAMETER;
                break;
            case Aws::S3::S3Errors::OPT_IN_REQUIRED:
                error = ES3Error::OPT_IN_REQUIRED;
                break;
            case Aws::S3::S3Errors::REQUEST_EXPIRED:
                error = ES3Error::REQUEST_EXPIRED;
                break;
            case Aws::S3::S3Errors::SERVICE_UNAVAILABLE:
                error = ES3Error::SERVICE_UNAVAILABLE;
                break;
            case Aws::S3::S3Errors::THROTTLING:
                error = ES3Error::THROTTLING;
                break;
            case Aws::S3::S3Errors::VALIDATION:
                error = ES3Error::VALIDATION;
                break;
            case Aws::S3::S3Errors::ACCESS_DENIED:
                error = ES3Error::ACCESS_DENIED;
                break;
            case Aws::S3::S3Errors::RESOURCE_NOT_FOUND:
                error = ES3Error::RESOURCE_NOT_FOUND;
                break;
            case Aws::S3::S3Errors::UNRECOGNIZED_CLIENT:
                error = ES3Error::UNRECOGNIZED_CLIENT;
                break;
            case Aws::S3::S3Errors::MALFORMED_QUERY_STRING:
                error = ES3Error::MALFORMED_QUERY_STRING;
                break;
            case Aws::S3::S3Errors::SLOW_DOWN:
                error = ES3Error::SLOW_DOWN;
                break;
            case Aws::S3::S3Errors::REQUEST_TIME_TOO_SKEWED:
                error = ES3Error::REQUEST_TIME_TOO_SKEWED;
                break;
            case Aws::S3::S3Errors::INVALID_SIGNATURE:
                error = ES3Error::INVALID_SIGNATURE;
                break;
            case Aws::S3::S3Errors::SIGNATURE_DOES_NOT_MATCH:
                error = ES3Error::SIGNATURE_DOES_NOT_MATCH;
                break;
            case Aws::S3::S3Errors::INVALID_ACCESS_KEY_ID:
                error = ES3Error::INVALID_ACCESS_KEY_ID;
                break;
            case Aws::S3::S3Errors::REQUEST_TIMEOUT:
                error = ES3Error::REQUEST_TIMEOUT;
                break;
            case Aws::S3::S3Errors::NETWORK_CONNECTION:
                error = ES3Error::NETWORK_CONNECTION;
                break;
            case Aws::S3::S3Errors::UNKNOWN:
                error = ES3Error::UNKNOWN;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_EXISTS:
                error = ES3Error::BUCKET_ALREADY_EXISTS;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_OWNED_BY_YOU:
                error = ES3Error::BUCKET_ALREADY_OWNED_BY_YOU;
                break;
            case Aws::S3::S3Errors::NO_SUCH_BUCKET:
                error = ES3Error::NO_SUCH_BUCKET;
                break;
            case Aws::S3::S3Errors::NO_SUCH_KEY:
                error = ES3Error::NO_SUCH_KEY;
                break;
            case Aws::S3::S3Errors::NO_SUCH_UPLOAD:
                error = ES3Error::NO_SUCH_UPLOAD;
                break;
            case Aws::S3::S3Errors::OBJECT_ALREADY_IN_ACTIVE_TIER:
                error = ES3Error::OBJECT_ALREADY_IN_ACTIVE_TIER;
                break;
            case Aws::S3::S3Errors::OBJECT_NOT_IN_ACTIVE_TIER:
                error = ES3Error::OBJECT_NOT_IN_ACTIVE_TIER;
                break;
            default:
                error = ES3Error::UNKNOWN;
                break;
        }

        this->errorCallback(FConstTransferHandle().fromAWS(awsTransferHandle), error);
    };

    for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
        awsTransferManagerConfiguration.customizedAccessLogTag.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
    }

    return awsTransferManagerConfiguration;
}
#endif

void UTransferManagerObject::BeginDestroy() {
	Super::BeginDestroy();
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
	LOG_TRANSFER_NORMAL("Begin Destroy transfer manager object...");

	if (this->awsTransferManager != nullptr) {
		this->awsTransferManager->CancelAll();
	}

	if (this->config != nullptr && this->config->IsRooted()) {
		this->config->RemoveFromRoot();
	}
#endif
}

bool UTransferManagerObject::IsReadyForFinishDestroy() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
	LOG_TRANSFER_NORMAL("Is Ready For Finish Destroy transfer manager object...");

	if (this->awsTransferManager == nullptr) return true;

	Aws::Transfer::TransferStatus status = this->awsTransferManager->WaitUntilAllFinished(0);
	return status != Aws::Transfer::TransferStatus::IN_PROGRESS;
#endif
	return true;
}

UTransferManagerObject::~UTransferManagerObject() {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    this->awsTransferManager = nullptr;
#endif
}

UTransferManagerObject *UTransferManagerObject::CreateTransferManagerObject(
        UTransferManagerConfiguration *transferManagerConfiguration
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    UTransferManagerObject *TransferManager = NewObject<UTransferManagerObject>();
    TransferManager->config = transferManagerConfiguration;
	TransferManager->config->AddToRoot();
    TransferManager->awsTransferManager = Aws::Transfer::TransferManager::Create(transferManagerConfiguration->toAWS());
    return TransferManager;
#endif
    return nullptr;
}

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

class FUploadFileAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager;
    UTransferHandle* transferHandle;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUploadFileAction(
        std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager,
        const FString& fileName,
        const FString& bucketName,
        const FString& keyName,
        const FString& contentType,
        const TMap<FString, FString>& metadata,
        const FLatentActionInfo &LatentInfo
    )
    : awsTransferManager(awsTransferManager),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        Aws::Map<Aws::String, Aws::String> awsMetadata;
        for (const TPair<FString, FString>& elem : metadata) {
            awsMetadata.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        this->transferHandle = NewObject<UTransferHandle>();
//		this->transferHandle->AddToRoot();
        this->transferHandle->awsTransferHandle = awsTransferManager->UploadFile(
                TCHAR_TO_UTF8(*fileName),
                TCHAR_TO_UTF8(*bucketName),
                TCHAR_TO_UTF8(*keyName),
                TCHAR_TO_UTF8(*contentType),
                awsMetadata,
                std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

	/*virtual void NotifyObjectDestroyed() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual void NotifyActionAborted() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual ~FUploadFileAction() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
			 this->transferHandle=nullptr;
		}
	}*/

    UTransferHandle* GetTransferHandle() {
        return this->transferHandle;
    }

    void UpdateOperation(FLatentResponse &Response) override {
		if(this->transferHandle && this->transferHandle->awsTransferHandle) {
	        Aws::Transfer::TransferStatus status = this->transferHandle->awsTransferHandle->GetStatus();
	        Response.FinishAndTriggerIf(
                (status != Aws::Transfer::TransferStatus::NOT_STARTED && status != Aws::Transfer::TransferStatus::IN_PROGRESS) || !this->transferHandle->awsTransferHandle->HasPendingParts(),
                ExecutionFunction, OutputLink, CallbackTarget
                );
		} else {
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UploadFile Request");
    }

#endif
};

#endif

UTransferHandle*
UTransferManagerObject::UploadFile(
        UObject *WorldContextObject,
        const FString& fileName,
        const FString& bucketName,
        const FString& keyName,
        const FString& contentType,
        const TMap<FString, FString>& metadata,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUploadFileAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            FUploadFileAction *action = new FUploadFileAction(this->awsTransferManager,
                fileName,
                bucketName,
                keyName,
                contentType,
                metadata,
                LatentInfo);
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                    action
                );
            return action->GetTransferHandle();
        }
    }
    return nullptr;
#endif
    return nullptr;
}

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

class FDownloadFileAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager;
    UTransferHandle* transferHandle;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDownloadFileAction(
        std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager,
        const FString& bucketName,
        const FString& keyName,
        const FString& writeToFile,
        const FDownloadConfiguration& downloadConfig,
        const FLatentActionInfo &LatentInfo
    )
    : awsTransferManager(awsTransferManager),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        this->transferHandle = NewObject<UTransferHandle>();
//		this->transferHandle->AddToRoot();
        this->transferHandle->awsTransferHandle = awsTransferManager->DownloadFile(
                TCHAR_TO_UTF8(*bucketName),
                TCHAR_TO_UTF8(*keyName),
                TCHAR_TO_UTF8(*writeToFile),
                downloadConfig.toAWS(),
                std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

	/*virtual void NotifyObjectDestroyed() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual void NotifyActionAborted() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual ~FDownloadFileAction() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
			 this->transferHandle=nullptr;
		}
	}*/

    UTransferHandle* GetTransferHandle() {
        return this->transferHandle;
    }

    void UpdateOperation(FLatentResponse &Response) override {
		if(this->transferHandle && this->transferHandle->awsTransferHandle) {
	        Aws::Transfer::TransferStatus status = this->transferHandle->awsTransferHandle->GetStatus();
	        Response.FinishAndTriggerIf(
                (status != Aws::Transfer::TransferStatus::NOT_STARTED && status != Aws::Transfer::TransferStatus::IN_PROGRESS) || !this->transferHandle->awsTransferHandle->HasPendingParts(),
                ExecutionFunction, OutputLink, CallbackTarget
                );
		} else {
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DownloadFile Request");
    }

#endif
};

#endif

UTransferHandle*
UTransferManagerObject::DownloadFile(
        UObject *WorldContextObject,
        const FString& bucketName,
        const FString& keyName,
        const FString& writeToFile,
        const FDownloadConfiguration& downloadConfig,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDownloadFileAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            FDownloadFileAction *action = new FDownloadFileAction(this->awsTransferManager,
                bucketName,
                keyName,
                writeToFile,
                downloadConfig,
                LatentInfo);
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                    action
                );
            return action->GetTransferHandle();
        }
    }
    return nullptr;
#endif
    return nullptr;
}

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

class FRetryDownloadAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager;
    UTransferHandle* transferHandle;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FRetryDownloadAction(
        std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager,
        UTransferHandle* retryHandle,
        const FLatentActionInfo &LatentInfo
    )
    : awsTransferManager(awsTransferManager),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        this->transferHandle = NewObject<UTransferHandle>();
//		this->transferHandle->AddToRoot();
        this->transferHandle->awsTransferHandle = awsTransferManager->RetryDownload(
                retryHandle->awsTransferHandle
        );
    }

	/*virtual void NotifyObjectDestroyed() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual void NotifyActionAborted() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual ~FRetryDownloadAction() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
			 this->transferHandle=nullptr;
		}
	}*/

    UTransferHandle* GetTransferHandle() {
        return this->transferHandle;
    }

    void UpdateOperation(FLatentResponse &Response) override {
		if(this->transferHandle && this->transferHandle->awsTransferHandle) {
	        Aws::Transfer::TransferStatus status = this->transferHandle->awsTransferHandle->GetStatus();
	        Response.FinishAndTriggerIf(
                (status != Aws::Transfer::TransferStatus::NOT_STARTED && status != Aws::Transfer::TransferStatus::IN_PROGRESS) || !this->transferHandle->awsTransferHandle->HasPendingParts(),
                ExecutionFunction, OutputLink, CallbackTarget
                );
		} else {
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RetryDownload Request");
    }

#endif
};

#endif

UTransferHandle*
UTransferManagerObject::RetryDownload(
        UObject *WorldContextObject,
        UTransferHandle* retryHandle,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRetryDownloadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            FRetryDownloadAction *action = new FRetryDownloadAction(this->awsTransferManager,
                retryHandle,
                LatentInfo);
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                    action
                );
            return action->GetTransferHandle();
        }
    }
    return nullptr;
#endif
    return nullptr;
}

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

class FRetryUploadAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager;
    UTransferHandle* transferHandle;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FRetryUploadAction(
        std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager,
        const FString& fileName,
        UTransferHandle* retryHandle,
        const FLatentActionInfo &LatentInfo
    )
    : awsTransferManager(awsTransferManager),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        this->transferHandle = NewObject<UTransferHandle>();
//		this->transferHandle->AddToRoot();
        this->transferHandle->awsTransferHandle = awsTransferManager->RetryUpload(
                TCHAR_TO_UTF8(*fileName),
                retryHandle->awsTransferHandle
        );
    }

	/*virtual void NotifyObjectDestroyed() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual void NotifyActionAborted() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
		}
	}

	virtual ~FRetryUploadAction() override {
		if (this->transferHandle != nullptr) {
			this->transferHandle->Cancel();
			 if (this->transferHandle->IsRooted()) {
				this->transferHandle->RemoveFromRoot();
			 }
			 this->transferHandle=nullptr;
		}
	}*/

    UTransferHandle* GetTransferHandle() {
        return this->transferHandle;
    }

    void UpdateOperation(FLatentResponse &Response) override {
		if(this->transferHandle && this->transferHandle->awsTransferHandle) {
	        Aws::Transfer::TransferStatus status = this->transferHandle->awsTransferHandle->GetStatus();
	        Response.FinishAndTriggerIf(
                (status != Aws::Transfer::TransferStatus::NOT_STARTED && status != Aws::Transfer::TransferStatus::IN_PROGRESS) || !this->transferHandle->awsTransferHandle->HasPendingParts(),
                ExecutionFunction, OutputLink, CallbackTarget
                );
		} else {
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RetryUpload Request");
    }

#endif
};

#endif

UTransferHandle*
UTransferManagerObject::RetryUpload(
        UObject *WorldContextObject,
        const FString& fileName,
        UTransferHandle* retryHandle,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRetryDownloadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            FRetryUploadAction *action = new FRetryUploadAction(this->awsTransferManager,
                fileName,
                retryHandle,
                LatentInfo);
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                    action
                );
            return action->GetTransferHandle();
        }
    }
    return nullptr;
#endif
    return nullptr;
}

void
UTransferManagerObject::AbortMultipartUpload(
        UTransferHandle* inProgressHandle
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    this->awsTransferManager->AbortMultipartUpload(
            inProgressHandle->awsTransferHandle
    );
#endif
    return;
}

void UTransferManagerObject::UploadDirectory (
        const FString& directory,
        const FString& bucketName,
        const FString& prefix,
        const TMap<FString, FString>& metadata
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    Aws::Map<Aws::String, Aws::String> awsMetadata;
    for (const TPair<FString, FString>& elem : metadata) {
        awsMetadata.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
    }

    this->awsTransferManager->UploadDirectory(
            TCHAR_TO_UTF8(*directory),
            TCHAR_TO_UTF8(*bucketName),
            TCHAR_TO_UTF8(*prefix),
            awsMetadata
    );
#endif
    return;
}

void UTransferManagerObject::DownloadToDirectory (
        const FString& directory,
        const FString& bucketName,
        const FString& prefix
) {
#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    this->awsTransferManager->DownloadToDirectory(
            TCHAR_TO_UTF8(*directory),
            TCHAR_TO_UTF8(*bucketName),
            TCHAR_TO_UTF8(*prefix)
    );
#endif
    return;
}