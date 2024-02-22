/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "S3EncryptionClientObject.h"
#include "S3EncryptionGlobals.h"
#include "S3EncryptionPrivatePCH.h"

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_S3ENCRYPTIONCLIENTSDK

ES3EncryptionError fromAWS(Aws::S3Encryption::S3EncryptionErrors awsErrorType) {
    if (awsErrorType.IsS3Error()) {
        switch (awsErrorType.s3Error) {
            case Aws::S3::S3Errors::INCOMPLETE_SIGNATURE:
                return ES3EncryptionError::INCOMPLETE_SIGNATURE;
                break;
            case Aws::S3::S3Errors::INTERNAL_FAILURE:
                return ES3EncryptionError::INTERNAL_FAILURE;
                break;
            case Aws::S3::S3Errors::INVALID_ACTION:
                return ES3EncryptionError::INVALID_ACTION;
                break;
            case Aws::S3::S3Errors::INVALID_CLIENT_TOKEN_ID:
                return ES3EncryptionError::INVALID_CLIENT_TOKEN_ID;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_COMBINATION:
                return ES3EncryptionError::INVALID_PARAMETER_COMBINATION;
                break;
            case Aws::S3::S3Errors::INVALID_QUERY_PARAMETER:
                return ES3EncryptionError::INVALID_QUERY_PARAMETER;
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_VALUE:
                return ES3EncryptionError::INVALID_PARAMETER_VALUE;
                break;
            case Aws::S3::S3Errors::MISSING_ACTION:
                return ES3EncryptionError::MISSING_ACTION;
                break;
            case Aws::S3::S3Errors::MISSING_AUTHENTICATION_TOKEN:
                return ES3EncryptionError::MISSING_AUTHENTICATION_TOKEN;
                break;
            case Aws::S3::S3Errors::MISSING_PARAMETER:
                return ES3EncryptionError::MISSING_PARAMETER;
                break;
            case Aws::S3::S3Errors::OPT_IN_REQUIRED:
                return ES3EncryptionError::OPT_IN_REQUIRED;
                break;
            case Aws::S3::S3Errors::REQUEST_EXPIRED:
                return ES3EncryptionError::REQUEST_EXPIRED;
                break;
            case Aws::S3::S3Errors::SERVICE_UNAVAILABLE:
                return ES3EncryptionError::SERVICE_UNAVAILABLE;
                break;
            case Aws::S3::S3Errors::THROTTLING:
                return ES3EncryptionError::THROTTLING;
                break;
            case Aws::S3::S3Errors::VALIDATION:
                return ES3EncryptionError::VALIDATION;
                break;
            case Aws::S3::S3Errors::ACCESS_DENIED:
                return ES3EncryptionError::ACCESS_DENIED;
                break;
            case Aws::S3::S3Errors::RESOURCE_NOT_FOUND:
                return ES3EncryptionError::RESOURCE_NOT_FOUND;
                break;
            case Aws::S3::S3Errors::UNRECOGNIZED_CLIENT:
                return ES3EncryptionError::UNRECOGNIZED_CLIENT;
                break;
            case Aws::S3::S3Errors::MALFORMED_QUERY_STRING:
                return ES3EncryptionError::MALFORMED_QUERY_STRING;
                break;
            case Aws::S3::S3Errors::SLOW_DOWN:
                return ES3EncryptionError::SLOW_DOWN;
                break;
            case Aws::S3::S3Errors::REQUEST_TIME_TOO_SKEWED:
                return ES3EncryptionError::REQUEST_TIME_TOO_SKEWED;
                break;
            case Aws::S3::S3Errors::INVALID_SIGNATURE:
                return ES3EncryptionError::INVALID_SIGNATURE;
                break;
            case Aws::S3::S3Errors::SIGNATURE_DOES_NOT_MATCH:
                return ES3EncryptionError::SIGNATURE_DOES_NOT_MATCH;
                break;
            case Aws::S3::S3Errors::INVALID_ACCESS_KEY_ID:
                return ES3EncryptionError::INVALID_ACCESS_KEY_ID;
                break;
            case Aws::S3::S3Errors::REQUEST_TIMEOUT:
                return ES3EncryptionError::REQUEST_TIMEOUT;
                break;
            case Aws::S3::S3Errors::NETWORK_CONNECTION:
                return ES3EncryptionError::NETWORK_CONNECTION;
                break;
            case Aws::S3::S3Errors::UNKNOWN:
                return ES3EncryptionError::UNKNOWN;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_EXISTS:
                return ES3EncryptionError::BUCKET_ALREADY_EXISTS;
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_OWNED_BY_YOU:
                return ES3EncryptionError::BUCKET_ALREADY_OWNED_BY_YOU;
                break;
            case Aws::S3::S3Errors::NO_SUCH_BUCKET:
                return ES3EncryptionError::NO_SUCH_BUCKET;
                break;
            case Aws::S3::S3Errors::NO_SUCH_KEY:
                return ES3EncryptionError::NO_SUCH_KEY;
                break;
            case Aws::S3::S3Errors::NO_SUCH_UPLOAD:
                return ES3EncryptionError::NO_SUCH_UPLOAD;
                break;
            case Aws::S3::S3Errors::OBJECT_ALREADY_IN_ACTIVE_TIER:
                return ES3EncryptionError::OBJECT_ALREADY_IN_ACTIVE_TIER;
                break;
            case Aws::S3::S3Errors::OBJECT_NOT_IN_ACTIVE_TIER:
                return ES3EncryptionError::OBJECT_NOT_IN_ACTIVE_TIER;
                break;
            default:
                return ES3EncryptionError::UNKNOWN;
                break;
        }
    } else if (awsErrorType.IsCryptoError()) {
         switch (awsErrorType.cryptoError) {
            case Aws::Utils::Crypto::CryptoErrors::ENCRYPT_CONTENT_ENCRYPTION_KEY_FAILED:
                return ES3EncryptionError::ENCRYPT_CONTENT_ENCRYPTION_KEY_FAILED;
                break;
            case Aws::Utils::Crypto::CryptoErrors::DECRYPT_CONTENT_ENCRYPTION_KEY_FAILED:
                return ES3EncryptionError::DECRYPT_CONTENT_ENCRYPTION_KEY_FAILED;
                break;
            case Aws::Utils::Crypto::CryptoErrors::GENERATE_CONTENT_ENCRYPTION_KEY_FAILED:
                return ES3EncryptionError::GENERATE_CONTENT_ENCRYPTION_KEY_FAILED;
                break;
            default:
                return ES3EncryptionError::UNKNOWN;
                break;
         }
    } else {
        return ES3EncryptionError::UNKNOWN;
    }
}

#endif

US3EncryptionClientObject *US3EncryptionClientObject::CreateS3EncryptionObject(
        const FCryptoConfiguration &cryptoConfig,
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    US3EncryptionClientObject *S3EncryptionClient = NewObject<US3EncryptionClientObject>();
    S3EncryptionClient->awsS3EncryptionClient =
            new Aws::S3Encryption::S3EncryptionClientV2(
                    cryptoConfig.toAWS(),
                    credentials.toAWS(),
                    clientConfiguration.toAWS()
            );
    return S3EncryptionClient;
#endif
    return nullptr;
}

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE

class FPutObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectResult &putObjectResult;
    ES3EncryptionError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    std::shared_ptr<Aws::Utils::Threading::Executor> executor;
    std::future<Aws::S3::Model::PutObjectOutcome> callable;

public:
    FPutObjectAction(
        Aws::S3Encryption::S3EncryptionClientV2 *S3EncryptionClient,
        bool &success,
        FPutObjectRequest putObjectRequest,
        TMap<FString, FString> contextMap,
        FPutObjectResult &putObjectResult,
        ES3EncryptionError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectResult(putObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        Aws::Map<Aws::String, Aws::String> awsContextMap;
        for (const TPair<FString, FString>& elem : contextMap) {
            awsContextMap.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        executor =
                Aws::MakeShared<Aws::Utils::Threading::DefaultExecutor>("s3 encryption put object");

        auto task = Aws::MakeShared< std::packaged_task< Aws::S3::Model::PutObjectOutcome() > >("s3 encryption put object", [S3EncryptionClient, putObjectRequest, awsContextMap](){
            return S3EncryptionClient->PutObject(
                putObjectRequest.toAWS(),
                awsContextMap
            );
        } );

        auto packagedFunction = [task]() { (*task)(); };
        executor->Submit(packagedFunction);

        callable = task->get_future();
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutObjectOutcome = callable.get();

            success = awsPutObjectOutcome.IsSuccess();
            if (success) {
                putObjectResult.fromAWS(awsPutObjectOutcome.GetResult());
            }

            errorType = fromAWS(awsPutObjectOutcome.GetError().GetErrorType());
            errorMessage = ("PutObject error: " + awsPutObjectOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutObject Request");
    }

#endif
};

#endif

void
US3EncryptionClientObject::PutObject(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectRequest putObjectRequest,
        TMap<FString, FString> contextMap,
        FPutObjectResult &putObjectResult,
        ES3EncryptionError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectAction(this->awsS3EncryptionClient,
                success,
                putObjectRequest,
                contextMap,
                putObjectResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE

class FGetObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectResult &getObjectResult;
    ES3EncryptionError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    std::shared_ptr<Aws::Utils::Threading::Executor> executor;
    std::future<Aws::S3::Model::GetObjectOutcome> callable;

public:
    FGetObjectAction(
        Aws::S3Encryption::S3EncryptionClientV2 *S3EncryptionClient,
        bool &success,
        FGetObjectRequest getObjectRequest,
        FGetObjectResult &getObjectResult,
        ES3EncryptionError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectResult(getObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        executor =
                Aws::MakeShared<Aws::Utils::Threading::DefaultExecutor>("s3 encryption get object");

        auto task = Aws::MakeShared< std::packaged_task< Aws::S3::Model::GetObjectOutcome() > >("s3 encryption get object", [S3EncryptionClient, getObjectRequest](){
            return S3EncryptionClient->GetObject(
                getObjectRequest.toAWS()
            );
        } );

        auto packagedFunction = [task]() { (*task)(); };
        executor->Submit(packagedFunction);

        callable = task->get_future();
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectOutcome = callable.get();

            success = awsGetObjectOutcome.IsSuccess();
            if (success) {
                getObjectResult.fromAWS(awsGetObjectOutcome.GetResult());
            }

            errorType = fromAWS(awsGetObjectOutcome.GetError().GetErrorType());
            errorMessage = ("GetObject error: " + awsGetObjectOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObject Request");
    }

#endif
};

#endif

void
US3EncryptionClientObject::GetObject(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectRequest getObjectRequest,
        FGetObjectResult &getObjectResult,
        ES3EncryptionError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectAction(this->awsS3EncryptionClient,
                success,
                getObjectRequest,
                getObjectResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}

bool US3EncryptionClientObject::MultipartUploadSupported() const {
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    return this->awsS3EncryptionClient->MultipartUploadSupported();
#endif
    return false;
}
