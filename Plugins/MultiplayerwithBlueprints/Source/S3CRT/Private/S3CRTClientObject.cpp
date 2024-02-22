/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#include "S3CRTClientObject.h"
#include "S3CRTGlobals.h"
#include "S3CRTPrivatePCH.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_S3CRTCLIENTSDK

ES3CRTError fromAWS(Aws::S3Crt::S3CrtErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::S3Crt::S3CrtErrors::INCOMPLETE_SIGNATURE:
            return ES3CRTError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::S3Crt::S3CrtErrors::INTERNAL_FAILURE:
            return ES3CRTError::INTERNAL_FAILURE;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_ACTION:
            return ES3CRTError::INVALID_ACTION;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_CLIENT_TOKEN_ID:
            return ES3CRTError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_PARAMETER_COMBINATION:
            return ES3CRTError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_QUERY_PARAMETER:
            return ES3CRTError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_PARAMETER_VALUE:
            return ES3CRTError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::S3Crt::S3CrtErrors::MISSING_ACTION:
            return ES3CRTError::MISSING_ACTION;
            break;
        case Aws::S3Crt::S3CrtErrors::MISSING_AUTHENTICATION_TOKEN:
            return ES3CRTError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::S3Crt::S3CrtErrors::MISSING_PARAMETER:
            return ES3CRTError::MISSING_PARAMETER;
            break;
        case Aws::S3Crt::S3CrtErrors::OPT_IN_REQUIRED:
            return ES3CRTError::OPT_IN_REQUIRED;
            break;
        case Aws::S3Crt::S3CrtErrors::REQUEST_EXPIRED:
            return ES3CRTError::REQUEST_EXPIRED;
            break;
        case Aws::S3Crt::S3CrtErrors::SERVICE_UNAVAILABLE:
            return ES3CRTError::SERVICE_UNAVAILABLE;
            break;
        case Aws::S3Crt::S3CrtErrors::THROTTLING:
            return ES3CRTError::THROTTLING;
            break;
        case Aws::S3Crt::S3CrtErrors::VALIDATION:
            return ES3CRTError::VALIDATION;
            break;
        case Aws::S3Crt::S3CrtErrors::ACCESS_DENIED:
            return ES3CRTError::ACCESS_DENIED;
            break;
        case Aws::S3Crt::S3CrtErrors::RESOURCE_NOT_FOUND:
            return ES3CRTError::RESOURCE_NOT_FOUND;
            break;
        case Aws::S3Crt::S3CrtErrors::UNRECOGNIZED_CLIENT:
            return ES3CRTError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::S3Crt::S3CrtErrors::MALFORMED_QUERY_STRING:
            return ES3CRTError::MALFORMED_QUERY_STRING;
            break;
        case Aws::S3Crt::S3CrtErrors::SLOW_DOWN:
            return ES3CRTError::SLOW_DOWN;
            break;
        case Aws::S3Crt::S3CrtErrors::REQUEST_TIME_TOO_SKEWED:
            return ES3CRTError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_SIGNATURE:
            return ES3CRTError::INVALID_SIGNATURE;
            break;
        case Aws::S3Crt::S3CrtErrors::SIGNATURE_DOES_NOT_MATCH:
            return ES3CRTError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_ACCESS_KEY_ID:
            return ES3CRTError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::S3Crt::S3CrtErrors::REQUEST_TIMEOUT:
            return ES3CRTError::REQUEST_TIMEOUT;
            break;
        case Aws::S3Crt::S3CrtErrors::NETWORK_CONNECTION:
            return ES3CRTError::NETWORK_CONNECTION;
            break;
        case Aws::S3Crt::S3CrtErrors::UNKNOWN:
            return ES3CRTError::UNKNOWN;
            break;
        case Aws::S3Crt::S3CrtErrors::BUCKET_ALREADY_EXISTS:
            return ES3CRTError::BUCKET_ALREADY_EXISTS;
            break;
        case Aws::S3Crt::S3CrtErrors::BUCKET_ALREADY_OWNED_BY_YOU:
            return ES3CRTError::BUCKET_ALREADY_OWNED_BY_YOU;
            break;
        case Aws::S3Crt::S3CrtErrors::INVALID_OBJECT_STATE:
            return ES3CRTError::INVALID_OBJECT_STATE;
            break;
        case Aws::S3Crt::S3CrtErrors::NO_SUCH_BUCKET:
            return ES3CRTError::NO_SUCH_BUCKET;
            break;
        case Aws::S3Crt::S3CrtErrors::NO_SUCH_KEY:
            return ES3CRTError::NO_SUCH_KEY;
            break;
        case Aws::S3Crt::S3CrtErrors::NO_SUCH_UPLOAD:
            return ES3CRTError::NO_SUCH_UPLOAD;
            break;
        case Aws::S3Crt::S3CrtErrors::OBJECT_ALREADY_IN_ACTIVE_TIER:
            return ES3CRTError::OBJECT_ALREADY_IN_ACTIVE_TIER;
            break;
        case Aws::S3Crt::S3CrtErrors::OBJECT_NOT_IN_ACTIVE_TIER:
            return ES3CRTError::OBJECT_NOT_IN_ACTIVE_TIER;
            break;
        default:
            return ES3CRTError::UNKNOWN;
            break;
    }
}

#endif

US3CRTClientObject *US3CRTClientObject::CreateS3CRTObject(
const FAWSCredentials &credentials,
const FAWSS3CRTClientConfiguration &clientConfiguration,
EAWSPayloadSigningPolicy signPayloads,
bool useVirtualAddressing,
EAWSS3CRTUS_EAST_1_REGIONAL_ENDPOINT_OPTION USEast1RegionalEndPointOption
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    US3CRTClientObject *S3CRTClient = NewObject<US3CRTClientObject>();
    Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy awsPayloadSigningPolicy = Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never;
    switch (signPayloads) {
        case EAWSPayloadSigningPolicy::RequestDependent:
            awsPayloadSigningPolicy = Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::RequestDependent;
            break;
        case EAWSPayloadSigningPolicy::Always:
            awsPayloadSigningPolicy = Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Always;
            break;
        case EAWSPayloadSigningPolicy::Never:
            awsPayloadSigningPolicy = Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never;
            break;
    }
    Aws::S3Crt::US_EAST_1_REGIONAL_ENDPOINT_OPTION awsUSEast1RegionalEndPointOption = Aws::S3Crt::US_EAST_1_REGIONAL_ENDPOINT_OPTION::NOT_SET;
    switch (USEast1RegionalEndPointOption) {
        case EAWSS3CRTUS_EAST_1_REGIONAL_ENDPOINT_OPTION::NOT_SET:
            awsUSEast1RegionalEndPointOption = Aws::S3Crt::US_EAST_1_REGIONAL_ENDPOINT_OPTION::NOT_SET;
            break;
        case EAWSS3CRTUS_EAST_1_REGIONAL_ENDPOINT_OPTION::LEGACY:
            awsUSEast1RegionalEndPointOption = Aws::S3Crt::US_EAST_1_REGIONAL_ENDPOINT_OPTION::LEGACY;
            break;
        case EAWSS3CRTUS_EAST_1_REGIONAL_ENDPOINT_OPTION::REGIONAL:
            awsUSEast1RegionalEndPointOption = Aws::S3Crt::US_EAST_1_REGIONAL_ENDPOINT_OPTION::REGIONAL;
            break;
    }
    S3CRTClient->awsS3CRTClient = new Aws::S3Crt::S3CrtClient(credentials.toAWS(),
    clientConfiguration.toAWS(), awsPayloadSigningPolicy, useVirtualAddressing, awsUSEast1RegionalEndPointOption);
    return S3CRTClient;
#endif
    return nullptr;
}

#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FAbortMultipartUploadAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTAbortMultipartUploadResult &abortMultipartUploadResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::AbortMultipartUploadOutcomeCallable callable;

public:
    FAbortMultipartUploadAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTAbortMultipartUploadRequest abortMultipartUploadRequest,
        FAWSS3CRTAbortMultipartUploadResult &abortMultipartUploadResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), abortMultipartUploadResult(abortMultipartUploadResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->AbortMultipartUploadCallable(abortMultipartUploadRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAbortMultipartUploadOutcome = callable.get();

                success = awsAbortMultipartUploadOutcome.IsSuccess();
                if (success) {
                    abortMultipartUploadResult.fromAWS(awsAbortMultipartUploadOutcome.GetResult());
                }

                errorType = fromAWS(awsAbortMultipartUploadOutcome.GetError().GetErrorType());
                errorMessage = ("AbortMultipartUpload error: " + awsAbortMultipartUploadOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AbortMultipartUpload Request");
    }

#endif
};

#endif

void
US3CRTClientObject::AbortMultipartUpload(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTAbortMultipartUploadRequest abortMultipartUploadRequest,
    FAWSS3CRTAbortMultipartUploadResult &abortMultipartUploadResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAbortMultipartUploadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAbortMultipartUploadAction(this->awsS3CRTClient,
                success,
                abortMultipartUploadRequest,
                abortMultipartUploadResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FCompleteMultipartUploadAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTCompleteMultipartUploadResult &completeMultipartUploadResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::CompleteMultipartUploadOutcomeCallable callable;

public:
    FCompleteMultipartUploadAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTCompleteMultipartUploadRequest completeMultipartUploadRequest,
        FAWSS3CRTCompleteMultipartUploadResult &completeMultipartUploadResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), completeMultipartUploadResult(completeMultipartUploadResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->CompleteMultipartUploadCallable(completeMultipartUploadRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCompleteMultipartUploadOutcome = callable.get();

                success = awsCompleteMultipartUploadOutcome.IsSuccess();
                if (success) {
                    completeMultipartUploadResult.fromAWS(awsCompleteMultipartUploadOutcome.GetResult());
                }

                errorType = fromAWS(awsCompleteMultipartUploadOutcome.GetError().GetErrorType());
                errorMessage = ("CompleteMultipartUpload error: " + awsCompleteMultipartUploadOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CompleteMultipartUpload Request");
    }

#endif
};

#endif

void
US3CRTClientObject::CompleteMultipartUpload(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTCompleteMultipartUploadRequest completeMultipartUploadRequest,
    FAWSS3CRTCompleteMultipartUploadResult &completeMultipartUploadResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCompleteMultipartUploadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCompleteMultipartUploadAction(this->awsS3CRTClient,
                success,
                completeMultipartUploadRequest,
                completeMultipartUploadResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FCopyObjectAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTCopyObjectResult &copyObjectResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::CopyObjectOutcomeCallable callable;

public:
    FCopyObjectAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTCopyObjectRequest copyObjectRequest,
        FAWSS3CRTCopyObjectResult &copyObjectResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), copyObjectResult(copyObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->CopyObjectCallable(copyObjectRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCopyObjectOutcome = callable.get();

                success = awsCopyObjectOutcome.IsSuccess();
                if (success) {
                    copyObjectResult.fromAWS(awsCopyObjectOutcome.GetResult());
                }

                errorType = fromAWS(awsCopyObjectOutcome.GetError().GetErrorType());
                errorMessage = ("CopyObject error: " + awsCopyObjectOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CopyObject Request");
    }

#endif
};

#endif

void
US3CRTClientObject::CopyObject(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTCopyObjectRequest copyObjectRequest,
    FAWSS3CRTCopyObjectResult &copyObjectResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCopyObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCopyObjectAction(this->awsS3CRTClient,
                success,
                copyObjectRequest,
                copyObjectResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FCreateBucketAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTCreateBucketResult &createBucketResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::CreateBucketOutcomeCallable callable;

public:
    FCreateBucketAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTCreateBucketRequest createBucketRequest,
        FAWSS3CRTCreateBucketResult &createBucketResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createBucketResult(createBucketResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->CreateBucketCallable(createBucketRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateBucketOutcome = callable.get();

                success = awsCreateBucketOutcome.IsSuccess();
                if (success) {
                    createBucketResult.fromAWS(awsCreateBucketOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateBucketOutcome.GetError().GetErrorType());
                errorMessage = ("CreateBucket error: " + awsCreateBucketOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateBucket Request");
    }

#endif
};

#endif

void
US3CRTClientObject::CreateBucket(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTCreateBucketRequest createBucketRequest,
    FAWSS3CRTCreateBucketResult &createBucketResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateBucketAction(this->awsS3CRTClient,
                success,
                createBucketRequest,
                createBucketResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FCreateMultipartUploadAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTCreateMultipartUploadResult &createMultipartUploadResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::CreateMultipartUploadOutcomeCallable callable;

public:
    FCreateMultipartUploadAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTCreateMultipartUploadRequest createMultipartUploadRequest,
        FAWSS3CRTCreateMultipartUploadResult &createMultipartUploadResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createMultipartUploadResult(createMultipartUploadResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->CreateMultipartUploadCallable(createMultipartUploadRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateMultipartUploadOutcome = callable.get();

                success = awsCreateMultipartUploadOutcome.IsSuccess();
                if (success) {
                    createMultipartUploadResult.fromAWS(awsCreateMultipartUploadOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateMultipartUploadOutcome.GetError().GetErrorType());
                errorMessage = ("CreateMultipartUpload error: " + awsCreateMultipartUploadOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateMultipartUpload Request");
    }

#endif
};

#endif

void
US3CRTClientObject::CreateMultipartUpload(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTCreateMultipartUploadRequest createMultipartUploadRequest,
    FAWSS3CRTCreateMultipartUploadResult &createMultipartUploadResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateMultipartUploadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateMultipartUploadAction(this->awsS3CRTClient,
                success,
                createMultipartUploadRequest,
                createMultipartUploadResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketOutcomeCallable callable;

public:
    FDeleteBucketAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketRequest deleteBucketRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketCallable(deleteBucketRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketOutcome = callable.get();

                success = awsDeleteBucketOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucket error: " + awsDeleteBucketOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucket Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucket(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketRequest deleteBucketRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketAction(this->awsS3CRTClient,
                success,
                deleteBucketRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketAnalyticsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketAnalyticsConfigurationOutcomeCallable callable;

public:
    FDeleteBucketAnalyticsConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketAnalyticsConfigurationRequest deleteBucketAnalyticsConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketAnalyticsConfigurationCallable(deleteBucketAnalyticsConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketAnalyticsConfigurationOutcome = callable.get();

                success = awsDeleteBucketAnalyticsConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketAnalyticsConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketAnalyticsConfiguration error: " + awsDeleteBucketAnalyticsConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketAnalyticsConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketAnalyticsConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketAnalyticsConfigurationRequest deleteBucketAnalyticsConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketAnalyticsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketAnalyticsConfigurationAction(this->awsS3CRTClient,
                success,
                deleteBucketAnalyticsConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketCorsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketCorsOutcomeCallable callable;

public:
    FDeleteBucketCorsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketCorsRequest deleteBucketCorsRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketCorsCallable(deleteBucketCorsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketCorsOutcome = callable.get();

                success = awsDeleteBucketCorsOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketCorsOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketCors error: " + awsDeleteBucketCorsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketCors Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketCors(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketCorsRequest deleteBucketCorsRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketCorsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketCorsAction(this->awsS3CRTClient,
                success,
                deleteBucketCorsRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketEncryptionAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketEncryptionOutcomeCallable callable;

public:
    FDeleteBucketEncryptionAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketEncryptionRequest deleteBucketEncryptionRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketEncryptionCallable(deleteBucketEncryptionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketEncryptionOutcome = callable.get();

                success = awsDeleteBucketEncryptionOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketEncryptionOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketEncryption error: " + awsDeleteBucketEncryptionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketEncryption Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketEncryption(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketEncryptionRequest deleteBucketEncryptionRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketEncryptionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketEncryptionAction(this->awsS3CRTClient,
                success,
                deleteBucketEncryptionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketIntelligentTieringConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketIntelligentTieringConfigurationOutcomeCallable callable;

public:
    FDeleteBucketIntelligentTieringConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketIntelligentTieringConfigurationRequest deleteBucketIntelligentTieringConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketIntelligentTieringConfigurationCallable(deleteBucketIntelligentTieringConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketIntelligentTieringConfigurationOutcome = callable.get();

                success = awsDeleteBucketIntelligentTieringConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketIntelligentTieringConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketIntelligentTieringConfiguration error: " + awsDeleteBucketIntelligentTieringConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketIntelligentTieringConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketIntelligentTieringConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketIntelligentTieringConfigurationRequest deleteBucketIntelligentTieringConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketIntelligentTieringConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketIntelligentTieringConfigurationAction(this->awsS3CRTClient,
                success,
                deleteBucketIntelligentTieringConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketInventoryConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketInventoryConfigurationOutcomeCallable callable;

public:
    FDeleteBucketInventoryConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketInventoryConfigurationRequest deleteBucketInventoryConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketInventoryConfigurationCallable(deleteBucketInventoryConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketInventoryConfigurationOutcome = callable.get();

                success = awsDeleteBucketInventoryConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketInventoryConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketInventoryConfiguration error: " + awsDeleteBucketInventoryConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketInventoryConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketInventoryConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketInventoryConfigurationRequest deleteBucketInventoryConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketInventoryConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketInventoryConfigurationAction(this->awsS3CRTClient,
                success,
                deleteBucketInventoryConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketLifecycleAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketLifecycleOutcomeCallable callable;

public:
    FDeleteBucketLifecycleAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketLifecycleRequest deleteBucketLifecycleRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketLifecycleCallable(deleteBucketLifecycleRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketLifecycleOutcome = callable.get();

                success = awsDeleteBucketLifecycleOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketLifecycleOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketLifecycle error: " + awsDeleteBucketLifecycleOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketLifecycle Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketLifecycle(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketLifecycleRequest deleteBucketLifecycleRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketLifecycleAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketLifecycleAction(this->awsS3CRTClient,
                success,
                deleteBucketLifecycleRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketMetricsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketMetricsConfigurationOutcomeCallable callable;

public:
    FDeleteBucketMetricsConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketMetricsConfigurationRequest deleteBucketMetricsConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketMetricsConfigurationCallable(deleteBucketMetricsConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketMetricsConfigurationOutcome = callable.get();

                success = awsDeleteBucketMetricsConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketMetricsConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketMetricsConfiguration error: " + awsDeleteBucketMetricsConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketMetricsConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketMetricsConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketMetricsConfigurationRequest deleteBucketMetricsConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketMetricsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketMetricsConfigurationAction(this->awsS3CRTClient,
                success,
                deleteBucketMetricsConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketOwnershipControlsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketOwnershipControlsOutcomeCallable callable;

public:
    FDeleteBucketOwnershipControlsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketOwnershipControlsRequest deleteBucketOwnershipControlsRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketOwnershipControlsCallable(deleteBucketOwnershipControlsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketOwnershipControlsOutcome = callable.get();

                success = awsDeleteBucketOwnershipControlsOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketOwnershipControlsOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketOwnershipControls error: " + awsDeleteBucketOwnershipControlsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketOwnershipControls Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketOwnershipControls(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketOwnershipControlsRequest deleteBucketOwnershipControlsRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketOwnershipControlsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketOwnershipControlsAction(this->awsS3CRTClient,
                success,
                deleteBucketOwnershipControlsRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketPolicyOutcomeCallable callable;

public:
    FDeleteBucketPolicyAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketPolicyRequest deleteBucketPolicyRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketPolicyCallable(deleteBucketPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketPolicyOutcome = callable.get();

                success = awsDeleteBucketPolicyOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketPolicy error: " + awsDeleteBucketPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketPolicy Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketPolicyRequest deleteBucketPolicyRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketPolicyAction(this->awsS3CRTClient,
                success,
                deleteBucketPolicyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketReplicationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketReplicationOutcomeCallable callable;

public:
    FDeleteBucketReplicationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketReplicationRequest deleteBucketReplicationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketReplicationCallable(deleteBucketReplicationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketReplicationOutcome = callable.get();

                success = awsDeleteBucketReplicationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketReplicationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketReplication error: " + awsDeleteBucketReplicationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketReplication Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketReplication(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketReplicationRequest deleteBucketReplicationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketReplicationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketReplicationAction(this->awsS3CRTClient,
                success,
                deleteBucketReplicationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketTaggingOutcomeCallable callable;

public:
    FDeleteBucketTaggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketTaggingRequest deleteBucketTaggingRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketTaggingCallable(deleteBucketTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketTaggingOutcome = callable.get();

                success = awsDeleteBucketTaggingOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketTagging error: " + awsDeleteBucketTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketTagging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketTaggingRequest deleteBucketTaggingRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketTaggingAction(this->awsS3CRTClient,
                success,
                deleteBucketTaggingRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteBucketWebsiteAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteBucketWebsiteOutcomeCallable callable;

public:
    FDeleteBucketWebsiteAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteBucketWebsiteRequest deleteBucketWebsiteRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteBucketWebsiteCallable(deleteBucketWebsiteRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketWebsiteOutcome = callable.get();

                success = awsDeleteBucketWebsiteOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketWebsiteOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketWebsite error: " + awsDeleteBucketWebsiteOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketWebsite Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteBucketWebsite(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteBucketWebsiteRequest deleteBucketWebsiteRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketWebsiteAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketWebsiteAction(this->awsS3CRTClient,
                success,
                deleteBucketWebsiteRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteObjectAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTDeleteObjectResult &deleteObjectResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteObjectOutcomeCallable callable;

public:
    FDeleteObjectAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteObjectRequest deleteObjectRequest,
        FAWSS3CRTDeleteObjectResult &deleteObjectResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteObjectResult(deleteObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteObjectCallable(deleteObjectRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteObjectOutcome = callable.get();

                success = awsDeleteObjectOutcome.IsSuccess();
                if (success) {
                    deleteObjectResult.fromAWS(awsDeleteObjectOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteObjectOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteObject error: " + awsDeleteObjectOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteObject Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteObject(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteObjectRequest deleteObjectRequest,
    FAWSS3CRTDeleteObjectResult &deleteObjectResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteObjectAction(this->awsS3CRTClient,
                success,
                deleteObjectRequest,
                deleteObjectResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteObjectTaggingAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTDeleteObjectTaggingResult &deleteObjectTaggingResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteObjectTaggingOutcomeCallable callable;

public:
    FDeleteObjectTaggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteObjectTaggingRequest deleteObjectTaggingRequest,
        FAWSS3CRTDeleteObjectTaggingResult &deleteObjectTaggingResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteObjectTaggingResult(deleteObjectTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteObjectTaggingCallable(deleteObjectTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteObjectTaggingOutcome = callable.get();

                success = awsDeleteObjectTaggingOutcome.IsSuccess();
                if (success) {
                    deleteObjectTaggingResult.fromAWS(awsDeleteObjectTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteObjectTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteObjectTagging error: " + awsDeleteObjectTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteObjectTagging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteObjectTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteObjectTaggingRequest deleteObjectTaggingRequest,
    FAWSS3CRTDeleteObjectTaggingResult &deleteObjectTaggingResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteObjectTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteObjectTaggingAction(this->awsS3CRTClient,
                success,
                deleteObjectTaggingRequest,
                deleteObjectTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeleteObjectsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTDeleteObjectsResult &deleteObjectsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeleteObjectsOutcomeCallable callable;

public:
    FDeleteObjectsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeleteObjectsRequest deleteObjectsRequest,
        FAWSS3CRTDeleteObjectsResult &deleteObjectsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteObjectsResult(deleteObjectsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeleteObjectsCallable(deleteObjectsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteObjectsOutcome = callable.get();

                success = awsDeleteObjectsOutcome.IsSuccess();
                if (success) {
                    deleteObjectsResult.fromAWS(awsDeleteObjectsOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteObjectsOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteObjects error: " + awsDeleteObjectsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteObjects Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeleteObjects(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeleteObjectsRequest deleteObjectsRequest,
    FAWSS3CRTDeleteObjectsResult &deleteObjectsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteObjectsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteObjectsAction(this->awsS3CRTClient,
                success,
                deleteObjectsRequest,
                deleteObjectsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FDeletePublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::DeletePublicAccessBlockOutcomeCallable callable;

public:
    FDeletePublicAccessBlockAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTDeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->DeletePublicAccessBlockCallable(deletePublicAccessBlockRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeletePublicAccessBlockOutcome = callable.get();

                success = awsDeletePublicAccessBlockOutcome.IsSuccess();

                errorType = fromAWS(awsDeletePublicAccessBlockOutcome.GetError().GetErrorType());
                errorMessage = ("DeletePublicAccessBlock error: " + awsDeletePublicAccessBlockOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeletePublicAccessBlock Request");
    }

#endif
};

#endif

void
US3CRTClientObject::DeletePublicAccessBlock(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTDeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeletePublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeletePublicAccessBlockAction(this->awsS3CRTClient,
                success,
                deletePublicAccessBlockRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketAccelerateConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketAccelerateConfigurationResult &getBucketAccelerateConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketAccelerateConfigurationOutcomeCallable callable;

public:
    FGetBucketAccelerateConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketAccelerateConfigurationRequest getBucketAccelerateConfigurationRequest,
        FAWSS3CRTGetBucketAccelerateConfigurationResult &getBucketAccelerateConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketAccelerateConfigurationResult(getBucketAccelerateConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketAccelerateConfigurationCallable(getBucketAccelerateConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketAccelerateConfigurationOutcome = callable.get();

                success = awsGetBucketAccelerateConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketAccelerateConfigurationResult.fromAWS(awsGetBucketAccelerateConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketAccelerateConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketAccelerateConfiguration error: " + awsGetBucketAccelerateConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketAccelerateConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketAccelerateConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketAccelerateConfigurationRequest getBucketAccelerateConfigurationRequest,
    FAWSS3CRTGetBucketAccelerateConfigurationResult &getBucketAccelerateConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAccelerateConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAccelerateConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketAccelerateConfigurationRequest,
                getBucketAccelerateConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketAclAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketAclResult &getBucketAclResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketAclOutcomeCallable callable;

public:
    FGetBucketAclAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketAclRequest getBucketAclRequest,
        FAWSS3CRTGetBucketAclResult &getBucketAclResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketAclResult(getBucketAclResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketAclCallable(getBucketAclRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketAclOutcome = callable.get();

                success = awsGetBucketAclOutcome.IsSuccess();
                if (success) {
                    getBucketAclResult.fromAWS(awsGetBucketAclOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketAclOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketAcl error: " + awsGetBucketAclOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketAcl Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketAcl(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketAclRequest getBucketAclRequest,
    FAWSS3CRTGetBucketAclResult &getBucketAclResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAclAction(this->awsS3CRTClient,
                success,
                getBucketAclRequest,
                getBucketAclResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketAnalyticsConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketAnalyticsConfigurationResult &getBucketAnalyticsConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketAnalyticsConfigurationOutcomeCallable callable;

public:
    FGetBucketAnalyticsConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketAnalyticsConfigurationRequest getBucketAnalyticsConfigurationRequest,
        FAWSS3CRTGetBucketAnalyticsConfigurationResult &getBucketAnalyticsConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketAnalyticsConfigurationResult(getBucketAnalyticsConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketAnalyticsConfigurationCallable(getBucketAnalyticsConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketAnalyticsConfigurationOutcome = callable.get();

                success = awsGetBucketAnalyticsConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketAnalyticsConfigurationResult.fromAWS(awsGetBucketAnalyticsConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketAnalyticsConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketAnalyticsConfiguration error: " + awsGetBucketAnalyticsConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketAnalyticsConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketAnalyticsConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketAnalyticsConfigurationRequest getBucketAnalyticsConfigurationRequest,
    FAWSS3CRTGetBucketAnalyticsConfigurationResult &getBucketAnalyticsConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAnalyticsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAnalyticsConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketAnalyticsConfigurationRequest,
                getBucketAnalyticsConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketCorsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketCorsResult &getBucketCorsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketCorsOutcomeCallable callable;

public:
    FGetBucketCorsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketCorsRequest getBucketCorsRequest,
        FAWSS3CRTGetBucketCorsResult &getBucketCorsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketCorsResult(getBucketCorsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketCorsCallable(getBucketCorsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketCorsOutcome = callable.get();

                success = awsGetBucketCorsOutcome.IsSuccess();
                if (success) {
                    getBucketCorsResult.fromAWS(awsGetBucketCorsOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketCorsOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketCors error: " + awsGetBucketCorsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketCors Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketCors(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketCorsRequest getBucketCorsRequest,
    FAWSS3CRTGetBucketCorsResult &getBucketCorsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketCorsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketCorsAction(this->awsS3CRTClient,
                success,
                getBucketCorsRequest,
                getBucketCorsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketEncryptionAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketEncryptionResult &getBucketEncryptionResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketEncryptionOutcomeCallable callable;

public:
    FGetBucketEncryptionAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketEncryptionRequest getBucketEncryptionRequest,
        FAWSS3CRTGetBucketEncryptionResult &getBucketEncryptionResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketEncryptionResult(getBucketEncryptionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketEncryptionCallable(getBucketEncryptionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketEncryptionOutcome = callable.get();

                success = awsGetBucketEncryptionOutcome.IsSuccess();
                if (success) {
                    getBucketEncryptionResult.fromAWS(awsGetBucketEncryptionOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketEncryptionOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketEncryption error: " + awsGetBucketEncryptionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketEncryption Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketEncryption(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketEncryptionRequest getBucketEncryptionRequest,
    FAWSS3CRTGetBucketEncryptionResult &getBucketEncryptionResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketEncryptionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketEncryptionAction(this->awsS3CRTClient,
                success,
                getBucketEncryptionRequest,
                getBucketEncryptionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketIntelligentTieringConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketIntelligentTieringConfigurationResult &getBucketIntelligentTieringConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketIntelligentTieringConfigurationOutcomeCallable callable;

public:
    FGetBucketIntelligentTieringConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketIntelligentTieringConfigurationRequest getBucketIntelligentTieringConfigurationRequest,
        FAWSS3CRTGetBucketIntelligentTieringConfigurationResult &getBucketIntelligentTieringConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketIntelligentTieringConfigurationResult(getBucketIntelligentTieringConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketIntelligentTieringConfigurationCallable(getBucketIntelligentTieringConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketIntelligentTieringConfigurationOutcome = callable.get();

                success = awsGetBucketIntelligentTieringConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketIntelligentTieringConfigurationResult.fromAWS(awsGetBucketIntelligentTieringConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketIntelligentTieringConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketIntelligentTieringConfiguration error: " + awsGetBucketIntelligentTieringConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketIntelligentTieringConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketIntelligentTieringConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketIntelligentTieringConfigurationRequest getBucketIntelligentTieringConfigurationRequest,
    FAWSS3CRTGetBucketIntelligentTieringConfigurationResult &getBucketIntelligentTieringConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketIntelligentTieringConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketIntelligentTieringConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketIntelligentTieringConfigurationRequest,
                getBucketIntelligentTieringConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketInventoryConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketInventoryConfigurationResult &getBucketInventoryConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketInventoryConfigurationOutcomeCallable callable;

public:
    FGetBucketInventoryConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketInventoryConfigurationRequest getBucketInventoryConfigurationRequest,
        FAWSS3CRTGetBucketInventoryConfigurationResult &getBucketInventoryConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketInventoryConfigurationResult(getBucketInventoryConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketInventoryConfigurationCallable(getBucketInventoryConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketInventoryConfigurationOutcome = callable.get();

                success = awsGetBucketInventoryConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketInventoryConfigurationResult.fromAWS(awsGetBucketInventoryConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketInventoryConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketInventoryConfiguration error: " + awsGetBucketInventoryConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketInventoryConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketInventoryConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketInventoryConfigurationRequest getBucketInventoryConfigurationRequest,
    FAWSS3CRTGetBucketInventoryConfigurationResult &getBucketInventoryConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketInventoryConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketInventoryConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketInventoryConfigurationRequest,
                getBucketInventoryConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketLifecycleConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FGetBucketLifecycleConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
        FAWSS3CRTGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLifecycleConfigurationResult(getBucketLifecycleConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketLifecycleConfigurationCallable(getBucketLifecycleConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketLifecycleConfigurationOutcome = callable.get();

                success = awsGetBucketLifecycleConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketLifecycleConfigurationResult.fromAWS(awsGetBucketLifecycleConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketLifecycleConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketLifecycleConfiguration error: " + awsGetBucketLifecycleConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketLifecycleConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketLifecycleConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
    FAWSS3CRTGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLifecycleConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketLifecycleConfigurationRequest,
                getBucketLifecycleConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketLocationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketLocationResult &getBucketLocationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketLocationOutcomeCallable callable;

public:
    FGetBucketLocationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketLocationRequest getBucketLocationRequest,
        FAWSS3CRTGetBucketLocationResult &getBucketLocationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLocationResult(getBucketLocationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketLocationCallable(getBucketLocationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketLocationOutcome = callable.get();

                success = awsGetBucketLocationOutcome.IsSuccess();
                if (success) {
                    getBucketLocationResult.fromAWS(awsGetBucketLocationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketLocationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketLocation error: " + awsGetBucketLocationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketLocation Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketLocation(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketLocationRequest getBucketLocationRequest,
    FAWSS3CRTGetBucketLocationResult &getBucketLocationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLocationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLocationAction(this->awsS3CRTClient,
                success,
                getBucketLocationRequest,
                getBucketLocationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketLoggingAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketLoggingResult &getBucketLoggingResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketLoggingOutcomeCallable callable;

public:
    FGetBucketLoggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketLoggingRequest getBucketLoggingRequest,
        FAWSS3CRTGetBucketLoggingResult &getBucketLoggingResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLoggingResult(getBucketLoggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketLoggingCallable(getBucketLoggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketLoggingOutcome = callable.get();

                success = awsGetBucketLoggingOutcome.IsSuccess();
                if (success) {
                    getBucketLoggingResult.fromAWS(awsGetBucketLoggingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketLoggingOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketLogging error: " + awsGetBucketLoggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketLogging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketLogging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketLoggingRequest getBucketLoggingRequest,
    FAWSS3CRTGetBucketLoggingResult &getBucketLoggingResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLoggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLoggingAction(this->awsS3CRTClient,
                success,
                getBucketLoggingRequest,
                getBucketLoggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketMetricsConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketMetricsConfigurationResult &getBucketMetricsConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketMetricsConfigurationOutcomeCallable callable;

public:
    FGetBucketMetricsConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketMetricsConfigurationRequest getBucketMetricsConfigurationRequest,
        FAWSS3CRTGetBucketMetricsConfigurationResult &getBucketMetricsConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketMetricsConfigurationResult(getBucketMetricsConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketMetricsConfigurationCallable(getBucketMetricsConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketMetricsConfigurationOutcome = callable.get();

                success = awsGetBucketMetricsConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketMetricsConfigurationResult.fromAWS(awsGetBucketMetricsConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketMetricsConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketMetricsConfiguration error: " + awsGetBucketMetricsConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketMetricsConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketMetricsConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketMetricsConfigurationRequest getBucketMetricsConfigurationRequest,
    FAWSS3CRTGetBucketMetricsConfigurationResult &getBucketMetricsConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketMetricsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketMetricsConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketMetricsConfigurationRequest,
                getBucketMetricsConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketNotificationConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketNotificationConfigurationResult &getBucketNotificationConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketNotificationConfigurationOutcomeCallable callable;

public:
    FGetBucketNotificationConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketNotificationConfigurationRequest getBucketNotificationConfigurationRequest,
        FAWSS3CRTGetBucketNotificationConfigurationResult &getBucketNotificationConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketNotificationConfigurationResult(getBucketNotificationConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketNotificationConfigurationCallable(getBucketNotificationConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketNotificationConfigurationOutcome = callable.get();

                success = awsGetBucketNotificationConfigurationOutcome.IsSuccess();
                if (success) {
                    getBucketNotificationConfigurationResult.fromAWS(awsGetBucketNotificationConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketNotificationConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketNotificationConfiguration error: " + awsGetBucketNotificationConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketNotificationConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketNotificationConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketNotificationConfigurationRequest getBucketNotificationConfigurationRequest,
    FAWSS3CRTGetBucketNotificationConfigurationResult &getBucketNotificationConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketNotificationConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketNotificationConfigurationAction(this->awsS3CRTClient,
                success,
                getBucketNotificationConfigurationRequest,
                getBucketNotificationConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketOwnershipControlsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketOwnershipControlsResult &getBucketOwnershipControlsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketOwnershipControlsOutcomeCallable callable;

public:
    FGetBucketOwnershipControlsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketOwnershipControlsRequest getBucketOwnershipControlsRequest,
        FAWSS3CRTGetBucketOwnershipControlsResult &getBucketOwnershipControlsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketOwnershipControlsResult(getBucketOwnershipControlsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketOwnershipControlsCallable(getBucketOwnershipControlsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketOwnershipControlsOutcome = callable.get();

                success = awsGetBucketOwnershipControlsOutcome.IsSuccess();
                if (success) {
                    getBucketOwnershipControlsResult.fromAWS(awsGetBucketOwnershipControlsOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketOwnershipControlsOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketOwnershipControls error: " + awsGetBucketOwnershipControlsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketOwnershipControls Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketOwnershipControls(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketOwnershipControlsRequest getBucketOwnershipControlsRequest,
    FAWSS3CRTGetBucketOwnershipControlsResult &getBucketOwnershipControlsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketOwnershipControlsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketOwnershipControlsAction(this->awsS3CRTClient,
                success,
                getBucketOwnershipControlsRequest,
                getBucketOwnershipControlsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketPolicyAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketPolicyResult &getBucketPolicyResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketPolicyOutcomeCallable callable;

public:
    FGetBucketPolicyAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketPolicyRequest getBucketPolicyRequest,
        FAWSS3CRTGetBucketPolicyResult &getBucketPolicyResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketPolicyResult(getBucketPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketPolicyCallable(getBucketPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketPolicyOutcome = callable.get();

                success = awsGetBucketPolicyOutcome.IsSuccess();
                if (success) {
                    getBucketPolicyResult.fromAWS(awsGetBucketPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketPolicy error: " + awsGetBucketPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketPolicy Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketPolicyRequest getBucketPolicyRequest,
    FAWSS3CRTGetBucketPolicyResult &getBucketPolicyResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketPolicyAction(this->awsS3CRTClient,
                success,
                getBucketPolicyRequest,
                getBucketPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketPolicyStatusAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketPolicyStatusResult &getBucketPolicyStatusResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketPolicyStatusOutcomeCallable callable;

public:
    FGetBucketPolicyStatusAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketPolicyStatusRequest getBucketPolicyStatusRequest,
        FAWSS3CRTGetBucketPolicyStatusResult &getBucketPolicyStatusResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketPolicyStatusResult(getBucketPolicyStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketPolicyStatusCallable(getBucketPolicyStatusRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketPolicyStatusOutcome = callable.get();

                success = awsGetBucketPolicyStatusOutcome.IsSuccess();
                if (success) {
                    getBucketPolicyStatusResult.fromAWS(awsGetBucketPolicyStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketPolicyStatusOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketPolicyStatus error: " + awsGetBucketPolicyStatusOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketPolicyStatus Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketPolicyStatus(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketPolicyStatusRequest getBucketPolicyStatusRequest,
    FAWSS3CRTGetBucketPolicyStatusResult &getBucketPolicyStatusResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketPolicyStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketPolicyStatusAction(this->awsS3CRTClient,
                success,
                getBucketPolicyStatusRequest,
                getBucketPolicyStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketReplicationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketReplicationResult &getBucketReplicationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketReplicationOutcomeCallable callable;

public:
    FGetBucketReplicationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketReplicationRequest getBucketReplicationRequest,
        FAWSS3CRTGetBucketReplicationResult &getBucketReplicationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketReplicationResult(getBucketReplicationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketReplicationCallable(getBucketReplicationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketReplicationOutcome = callable.get();

                success = awsGetBucketReplicationOutcome.IsSuccess();
                if (success) {
                    getBucketReplicationResult.fromAWS(awsGetBucketReplicationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketReplicationOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketReplication error: " + awsGetBucketReplicationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketReplication Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketReplication(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketReplicationRequest getBucketReplicationRequest,
    FAWSS3CRTGetBucketReplicationResult &getBucketReplicationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketReplicationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketReplicationAction(this->awsS3CRTClient,
                success,
                getBucketReplicationRequest,
                getBucketReplicationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketRequestPaymentAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketRequestPaymentResult &getBucketRequestPaymentResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketRequestPaymentOutcomeCallable callable;

public:
    FGetBucketRequestPaymentAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketRequestPaymentRequest getBucketRequestPaymentRequest,
        FAWSS3CRTGetBucketRequestPaymentResult &getBucketRequestPaymentResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketRequestPaymentResult(getBucketRequestPaymentResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketRequestPaymentCallable(getBucketRequestPaymentRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketRequestPaymentOutcome = callable.get();

                success = awsGetBucketRequestPaymentOutcome.IsSuccess();
                if (success) {
                    getBucketRequestPaymentResult.fromAWS(awsGetBucketRequestPaymentOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketRequestPaymentOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketRequestPayment error: " + awsGetBucketRequestPaymentOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketRequestPayment Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketRequestPayment(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketRequestPaymentRequest getBucketRequestPaymentRequest,
    FAWSS3CRTGetBucketRequestPaymentResult &getBucketRequestPaymentResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketRequestPaymentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketRequestPaymentAction(this->awsS3CRTClient,
                success,
                getBucketRequestPaymentRequest,
                getBucketRequestPaymentResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketTaggingAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketTaggingResult &getBucketTaggingResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketTaggingOutcomeCallable callable;

public:
    FGetBucketTaggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketTaggingRequest getBucketTaggingRequest,
        FAWSS3CRTGetBucketTaggingResult &getBucketTaggingResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketTaggingResult(getBucketTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketTaggingCallable(getBucketTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketTaggingOutcome = callable.get();

                success = awsGetBucketTaggingOutcome.IsSuccess();
                if (success) {
                    getBucketTaggingResult.fromAWS(awsGetBucketTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketTagging error: " + awsGetBucketTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketTagging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketTaggingRequest getBucketTaggingRequest,
    FAWSS3CRTGetBucketTaggingResult &getBucketTaggingResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketTaggingAction(this->awsS3CRTClient,
                success,
                getBucketTaggingRequest,
                getBucketTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketVersioningAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketVersioningResult &getBucketVersioningResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketVersioningOutcomeCallable callable;

public:
    FGetBucketVersioningAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketVersioningRequest getBucketVersioningRequest,
        FAWSS3CRTGetBucketVersioningResult &getBucketVersioningResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketVersioningResult(getBucketVersioningResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketVersioningCallable(getBucketVersioningRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketVersioningOutcome = callable.get();

                success = awsGetBucketVersioningOutcome.IsSuccess();
                if (success) {
                    getBucketVersioningResult.fromAWS(awsGetBucketVersioningOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketVersioningOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketVersioning error: " + awsGetBucketVersioningOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketVersioning Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketVersioning(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketVersioningRequest getBucketVersioningRequest,
    FAWSS3CRTGetBucketVersioningResult &getBucketVersioningResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketVersioningAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketVersioningAction(this->awsS3CRTClient,
                success,
                getBucketVersioningRequest,
                getBucketVersioningResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetBucketWebsiteAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetBucketWebsiteResult &getBucketWebsiteResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetBucketWebsiteOutcomeCallable callable;

public:
    FGetBucketWebsiteAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetBucketWebsiteRequest getBucketWebsiteRequest,
        FAWSS3CRTGetBucketWebsiteResult &getBucketWebsiteResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketWebsiteResult(getBucketWebsiteResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetBucketWebsiteCallable(getBucketWebsiteRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketWebsiteOutcome = callable.get();

                success = awsGetBucketWebsiteOutcome.IsSuccess();
                if (success) {
                    getBucketWebsiteResult.fromAWS(awsGetBucketWebsiteOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketWebsiteOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucketWebsite error: " + awsGetBucketWebsiteOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucketWebsite Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetBucketWebsite(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetBucketWebsiteRequest getBucketWebsiteRequest,
    FAWSS3CRTGetBucketWebsiteResult &getBucketWebsiteResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketWebsiteAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketWebsiteAction(this->awsS3CRTClient,
                success,
                getBucketWebsiteRequest,
                getBucketWebsiteResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::S3Crt::S3CrtClient *S3CrtClient;
    FAWSS3CRTGetObjectRequest getObjectRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetObjectAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectRequest getObjectRequest,
        FAWSS3CRTGetObjectResult &getObjectResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : S3CrtClient(S3CrtClient), getObjectRequest(getObjectRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        S3CrtClient->GetObjectAsync(
            getObjectRequest.toAWS(),
            [&success, &getObjectResult, &errorType, &errorMessage, this](
                const Aws::S3Crt::S3CrtClient *awsS3CRTClient,
                const Aws::S3Crt::Model::GetObjectRequest &awsGetObjectRequest,
                const Aws::S3Crt::Model::GetObjectOutcome &awsGetObjectOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetObjectOutcome.IsSuccess();
                if (success) {
                    getObjectResult.fromAWS(awsGetObjectOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectOutcome.GetError().GetErrorType());
                errorMessage = ("GetObject error: " + awsGetObjectOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
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
US3CRTClientObject::GetObject(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectRequest getObjectRequest,
    FAWSS3CRTGetObjectResult &getObjectResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectAction(this->awsS3CRTClient,
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
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectAclAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetObjectAclResult &getObjectAclResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetObjectAclOutcomeCallable callable;

public:
    FGetObjectAclAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectAclRequest getObjectAclRequest,
        FAWSS3CRTGetObjectAclResult &getObjectAclResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectAclResult(getObjectAclResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetObjectAclCallable(getObjectAclRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectAclOutcome = callable.get();

                success = awsGetObjectAclOutcome.IsSuccess();
                if (success) {
                    getObjectAclResult.fromAWS(awsGetObjectAclOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectAclOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectAcl error: " + awsGetObjectAclOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectAcl Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetObjectAcl(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectAclRequest getObjectAclRequest,
    FAWSS3CRTGetObjectAclResult &getObjectAclResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectAclAction(this->awsS3CRTClient,
                success,
                getObjectAclRequest,
                getObjectAclResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectLegalHoldAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetObjectLegalHoldResult &getObjectLegalHoldResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetObjectLegalHoldOutcomeCallable callable;

public:
    FGetObjectLegalHoldAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectLegalHoldRequest getObjectLegalHoldRequest,
        FAWSS3CRTGetObjectLegalHoldResult &getObjectLegalHoldResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectLegalHoldResult(getObjectLegalHoldResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetObjectLegalHoldCallable(getObjectLegalHoldRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectLegalHoldOutcome = callable.get();

                success = awsGetObjectLegalHoldOutcome.IsSuccess();
                if (success) {
                    getObjectLegalHoldResult.fromAWS(awsGetObjectLegalHoldOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectLegalHoldOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectLegalHold error: " + awsGetObjectLegalHoldOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectLegalHold Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetObjectLegalHold(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectLegalHoldRequest getObjectLegalHoldRequest,
    FAWSS3CRTGetObjectLegalHoldResult &getObjectLegalHoldResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectLegalHoldAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectLegalHoldAction(this->awsS3CRTClient,
                success,
                getObjectLegalHoldRequest,
                getObjectLegalHoldResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectLockConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetObjectLockConfigurationResult &getObjectLockConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetObjectLockConfigurationOutcomeCallable callable;

public:
    FGetObjectLockConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectLockConfigurationRequest getObjectLockConfigurationRequest,
        FAWSS3CRTGetObjectLockConfigurationResult &getObjectLockConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectLockConfigurationResult(getObjectLockConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetObjectLockConfigurationCallable(getObjectLockConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectLockConfigurationOutcome = callable.get();

                success = awsGetObjectLockConfigurationOutcome.IsSuccess();
                if (success) {
                    getObjectLockConfigurationResult.fromAWS(awsGetObjectLockConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectLockConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectLockConfiguration error: " + awsGetObjectLockConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectLockConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetObjectLockConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectLockConfigurationRequest getObjectLockConfigurationRequest,
    FAWSS3CRTGetObjectLockConfigurationResult &getObjectLockConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectLockConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectLockConfigurationAction(this->awsS3CRTClient,
                success,
                getObjectLockConfigurationRequest,
                getObjectLockConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectRetentionAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetObjectRetentionResult &getObjectRetentionResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetObjectRetentionOutcomeCallable callable;

public:
    FGetObjectRetentionAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectRetentionRequest getObjectRetentionRequest,
        FAWSS3CRTGetObjectRetentionResult &getObjectRetentionResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectRetentionResult(getObjectRetentionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetObjectRetentionCallable(getObjectRetentionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectRetentionOutcome = callable.get();

                success = awsGetObjectRetentionOutcome.IsSuccess();
                if (success) {
                    getObjectRetentionResult.fromAWS(awsGetObjectRetentionOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectRetentionOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectRetention error: " + awsGetObjectRetentionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectRetention Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetObjectRetention(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectRetentionRequest getObjectRetentionRequest,
    FAWSS3CRTGetObjectRetentionResult &getObjectRetentionResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectRetentionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectRetentionAction(this->awsS3CRTClient,
                success,
                getObjectRetentionRequest,
                getObjectRetentionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectTaggingAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetObjectTaggingResult &getObjectTaggingResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetObjectTaggingOutcomeCallable callable;

public:
    FGetObjectTaggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectTaggingRequest getObjectTaggingRequest,
        FAWSS3CRTGetObjectTaggingResult &getObjectTaggingResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectTaggingResult(getObjectTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetObjectTaggingCallable(getObjectTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectTaggingOutcome = callable.get();

                success = awsGetObjectTaggingOutcome.IsSuccess();
                if (success) {
                    getObjectTaggingResult.fromAWS(awsGetObjectTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectTagging error: " + awsGetObjectTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectTagging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetObjectTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectTaggingRequest getObjectTaggingRequest,
    FAWSS3CRTGetObjectTaggingResult &getObjectTaggingResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectTaggingAction(this->awsS3CRTClient,
                success,
                getObjectTaggingRequest,
                getObjectTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetObjectTorrentAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetObjectTorrentResult &getObjectTorrentResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetObjectTorrentOutcomeCallable callable;

public:
    FGetObjectTorrentAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetObjectTorrentRequest getObjectTorrentRequest,
        FAWSS3CRTGetObjectTorrentResult &getObjectTorrentResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectTorrentResult(getObjectTorrentResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetObjectTorrentCallable(getObjectTorrentRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectTorrentOutcome = callable.get();

                success = awsGetObjectTorrentOutcome.IsSuccess();
                if (success) {
                    getObjectTorrentResult.fromAWS(awsGetObjectTorrentOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectTorrentOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectTorrent error: " + awsGetObjectTorrentOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectTorrent Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetObjectTorrent(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetObjectTorrentRequest getObjectTorrentRequest,
    FAWSS3CRTGetObjectTorrentResult &getObjectTorrentResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectTorrentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectTorrentAction(this->awsS3CRTClient,
                success,
                getObjectTorrentRequest,
                getObjectTorrentResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FGetPublicAccessBlockAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTGetPublicAccessBlockResult &getPublicAccessBlockResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::GetPublicAccessBlockOutcomeCallable callable;

public:
    FGetPublicAccessBlockAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTGetPublicAccessBlockRequest getPublicAccessBlockRequest,
        FAWSS3CRTGetPublicAccessBlockResult &getPublicAccessBlockResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getPublicAccessBlockResult(getPublicAccessBlockResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->GetPublicAccessBlockCallable(getPublicAccessBlockRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetPublicAccessBlockOutcome = callable.get();

                success = awsGetPublicAccessBlockOutcome.IsSuccess();
                if (success) {
                    getPublicAccessBlockResult.fromAWS(awsGetPublicAccessBlockOutcome.GetResult());
                }

                errorType = fromAWS(awsGetPublicAccessBlockOutcome.GetError().GetErrorType());
                errorMessage = ("GetPublicAccessBlock error: " + awsGetPublicAccessBlockOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetPublicAccessBlock Request");
    }

#endif
};

#endif

void
US3CRTClientObject::GetPublicAccessBlock(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTGetPublicAccessBlockRequest getPublicAccessBlockRequest,
    FAWSS3CRTGetPublicAccessBlockResult &getPublicAccessBlockResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPublicAccessBlockAction(this->awsS3CRTClient,
                success,
                getPublicAccessBlockRequest,
                getPublicAccessBlockResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FHeadBucketAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::HeadBucketOutcomeCallable callable;

public:
    FHeadBucketAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTHeadBucketRequest headBucketRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->HeadBucketCallable(headBucketRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsHeadBucketOutcome = callable.get();

                success = awsHeadBucketOutcome.IsSuccess();

                errorType = fromAWS(awsHeadBucketOutcome.GetError().GetErrorType());
                errorMessage = ("HeadBucket error: " + awsHeadBucketOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("HeadBucket Request");
    }

#endif
};

#endif

void
US3CRTClientObject::HeadBucket(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTHeadBucketRequest headBucketRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FHeadBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FHeadBucketAction(this->awsS3CRTClient,
                success,
                headBucketRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FHeadObjectAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTHeadObjectResult &headObjectResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::HeadObjectOutcomeCallable callable;

public:
    FHeadObjectAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTHeadObjectRequest headObjectRequest,
        FAWSS3CRTHeadObjectResult &headObjectResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), headObjectResult(headObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->HeadObjectCallable(headObjectRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsHeadObjectOutcome = callable.get();

                success = awsHeadObjectOutcome.IsSuccess();
                if (success) {
                    headObjectResult.fromAWS(awsHeadObjectOutcome.GetResult());
                }

                errorType = fromAWS(awsHeadObjectOutcome.GetError().GetErrorType());
                errorMessage = ("HeadObject error: " + awsHeadObjectOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("HeadObject Request");
    }

#endif
};

#endif

void
US3CRTClientObject::HeadObject(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTHeadObjectRequest headObjectRequest,
    FAWSS3CRTHeadObjectResult &headObjectResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FHeadObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FHeadObjectAction(this->awsS3CRTClient,
                success,
                headObjectRequest,
                headObjectResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListBucketAnalyticsConfigurationsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListBucketAnalyticsConfigurationsResult &listBucketAnalyticsConfigurationsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListBucketAnalyticsConfigurationsOutcomeCallable callable;

public:
    FListBucketAnalyticsConfigurationsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListBucketAnalyticsConfigurationsRequest listBucketAnalyticsConfigurationsRequest,
        FAWSS3CRTListBucketAnalyticsConfigurationsResult &listBucketAnalyticsConfigurationsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketAnalyticsConfigurationsResult(listBucketAnalyticsConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListBucketAnalyticsConfigurationsCallable(listBucketAnalyticsConfigurationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBucketAnalyticsConfigurationsOutcome = callable.get();

                success = awsListBucketAnalyticsConfigurationsOutcome.IsSuccess();
                if (success) {
                    listBucketAnalyticsConfigurationsResult.fromAWS(awsListBucketAnalyticsConfigurationsOutcome.GetResult());
                }

                errorType = fromAWS(awsListBucketAnalyticsConfigurationsOutcome.GetError().GetErrorType());
                errorMessage = ("ListBucketAnalyticsConfigurations error: " + awsListBucketAnalyticsConfigurationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBucketAnalyticsConfigurations Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListBucketAnalyticsConfigurations(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListBucketAnalyticsConfigurationsRequest listBucketAnalyticsConfigurationsRequest,
    FAWSS3CRTListBucketAnalyticsConfigurationsResult &listBucketAnalyticsConfigurationsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketAnalyticsConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketAnalyticsConfigurationsAction(this->awsS3CRTClient,
                success,
                listBucketAnalyticsConfigurationsRequest,
                listBucketAnalyticsConfigurationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListBucketIntelligentTieringConfigurationsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListBucketIntelligentTieringConfigurationsResult &listBucketIntelligentTieringConfigurationsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListBucketIntelligentTieringConfigurationsOutcomeCallable callable;

public:
    FListBucketIntelligentTieringConfigurationsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListBucketIntelligentTieringConfigurationsRequest listBucketIntelligentTieringConfigurationsRequest,
        FAWSS3CRTListBucketIntelligentTieringConfigurationsResult &listBucketIntelligentTieringConfigurationsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketIntelligentTieringConfigurationsResult(listBucketIntelligentTieringConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListBucketIntelligentTieringConfigurationsCallable(listBucketIntelligentTieringConfigurationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBucketIntelligentTieringConfigurationsOutcome = callable.get();

                success = awsListBucketIntelligentTieringConfigurationsOutcome.IsSuccess();
                if (success) {
                    listBucketIntelligentTieringConfigurationsResult.fromAWS(awsListBucketIntelligentTieringConfigurationsOutcome.GetResult());
                }

                errorType = fromAWS(awsListBucketIntelligentTieringConfigurationsOutcome.GetError().GetErrorType());
                errorMessage = ("ListBucketIntelligentTieringConfigurations error: " + awsListBucketIntelligentTieringConfigurationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBucketIntelligentTieringConfigurations Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListBucketIntelligentTieringConfigurations(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListBucketIntelligentTieringConfigurationsRequest listBucketIntelligentTieringConfigurationsRequest,
    FAWSS3CRTListBucketIntelligentTieringConfigurationsResult &listBucketIntelligentTieringConfigurationsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketIntelligentTieringConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketIntelligentTieringConfigurationsAction(this->awsS3CRTClient,
                success,
                listBucketIntelligentTieringConfigurationsRequest,
                listBucketIntelligentTieringConfigurationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListBucketInventoryConfigurationsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListBucketInventoryConfigurationsResult &listBucketInventoryConfigurationsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListBucketInventoryConfigurationsOutcomeCallable callable;

public:
    FListBucketInventoryConfigurationsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListBucketInventoryConfigurationsRequest listBucketInventoryConfigurationsRequest,
        FAWSS3CRTListBucketInventoryConfigurationsResult &listBucketInventoryConfigurationsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketInventoryConfigurationsResult(listBucketInventoryConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListBucketInventoryConfigurationsCallable(listBucketInventoryConfigurationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBucketInventoryConfigurationsOutcome = callable.get();

                success = awsListBucketInventoryConfigurationsOutcome.IsSuccess();
                if (success) {
                    listBucketInventoryConfigurationsResult.fromAWS(awsListBucketInventoryConfigurationsOutcome.GetResult());
                }

                errorType = fromAWS(awsListBucketInventoryConfigurationsOutcome.GetError().GetErrorType());
                errorMessage = ("ListBucketInventoryConfigurations error: " + awsListBucketInventoryConfigurationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBucketInventoryConfigurations Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListBucketInventoryConfigurations(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListBucketInventoryConfigurationsRequest listBucketInventoryConfigurationsRequest,
    FAWSS3CRTListBucketInventoryConfigurationsResult &listBucketInventoryConfigurationsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketInventoryConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketInventoryConfigurationsAction(this->awsS3CRTClient,
                success,
                listBucketInventoryConfigurationsRequest,
                listBucketInventoryConfigurationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListBucketMetricsConfigurationsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListBucketMetricsConfigurationsResult &listBucketMetricsConfigurationsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListBucketMetricsConfigurationsOutcomeCallable callable;

public:
    FListBucketMetricsConfigurationsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListBucketMetricsConfigurationsRequest listBucketMetricsConfigurationsRequest,
        FAWSS3CRTListBucketMetricsConfigurationsResult &listBucketMetricsConfigurationsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketMetricsConfigurationsResult(listBucketMetricsConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListBucketMetricsConfigurationsCallable(listBucketMetricsConfigurationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBucketMetricsConfigurationsOutcome = callable.get();

                success = awsListBucketMetricsConfigurationsOutcome.IsSuccess();
                if (success) {
                    listBucketMetricsConfigurationsResult.fromAWS(awsListBucketMetricsConfigurationsOutcome.GetResult());
                }

                errorType = fromAWS(awsListBucketMetricsConfigurationsOutcome.GetError().GetErrorType());
                errorMessage = ("ListBucketMetricsConfigurations error: " + awsListBucketMetricsConfigurationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBucketMetricsConfigurations Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListBucketMetricsConfigurations(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListBucketMetricsConfigurationsRequest listBucketMetricsConfigurationsRequest,
    FAWSS3CRTListBucketMetricsConfigurationsResult &listBucketMetricsConfigurationsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketMetricsConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketMetricsConfigurationsAction(this->awsS3CRTClient,
                success,
                listBucketMetricsConfigurationsRequest,
                listBucketMetricsConfigurationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListBucketsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListBucketsResult &listBucketsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListBucketsOutcomeCallable callable;

public:
    FListBucketsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListBucketsResult &listBucketsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketsResult(listBucketsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListBucketsCallable();
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBucketsOutcome = callable.get();

            success = awsListBucketsOutcome.IsSuccess();
            if (success) {
                listBucketsResult.fromAWS(awsListBucketsOutcome.GetResult());
            }

            errorType = fromAWS(awsListBucketsOutcome.GetError().GetErrorType());
            errorMessage = ("ListBuckets error: " + awsListBucketsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBuckets Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListBuckets(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListBucketsResult &listBucketsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketsAction(this->awsS3CRTClient,
                success,
                listBucketsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListMultipartUploadsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListMultipartUploadsResult &listMultipartUploadsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListMultipartUploadsOutcomeCallable callable;

public:
    FListMultipartUploadsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListMultipartUploadsRequest listMultipartUploadsRequest,
        FAWSS3CRTListMultipartUploadsResult &listMultipartUploadsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listMultipartUploadsResult(listMultipartUploadsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListMultipartUploadsCallable(listMultipartUploadsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListMultipartUploadsOutcome = callable.get();

                success = awsListMultipartUploadsOutcome.IsSuccess();
                if (success) {
                    listMultipartUploadsResult.fromAWS(awsListMultipartUploadsOutcome.GetResult());
                }

                errorType = fromAWS(awsListMultipartUploadsOutcome.GetError().GetErrorType());
                errorMessage = ("ListMultipartUploads error: " + awsListMultipartUploadsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListMultipartUploads Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListMultipartUploads(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListMultipartUploadsRequest listMultipartUploadsRequest,
    FAWSS3CRTListMultipartUploadsResult &listMultipartUploadsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListMultipartUploadsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListMultipartUploadsAction(this->awsS3CRTClient,
                success,
                listMultipartUploadsRequest,
                listMultipartUploadsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListObjectVersionsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListObjectVersionsResult &listObjectVersionsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListObjectVersionsOutcomeCallable callable;

public:
    FListObjectVersionsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListObjectVersionsRequest listObjectVersionsRequest,
        FAWSS3CRTListObjectVersionsResult &listObjectVersionsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listObjectVersionsResult(listObjectVersionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListObjectVersionsCallable(listObjectVersionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListObjectVersionsOutcome = callable.get();

                success = awsListObjectVersionsOutcome.IsSuccess();
                if (success) {
                    listObjectVersionsResult.fromAWS(awsListObjectVersionsOutcome.GetResult());
                }

                errorType = fromAWS(awsListObjectVersionsOutcome.GetError().GetErrorType());
                errorMessage = ("ListObjectVersions error: " + awsListObjectVersionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListObjectVersions Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListObjectVersions(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListObjectVersionsRequest listObjectVersionsRequest,
    FAWSS3CRTListObjectVersionsResult &listObjectVersionsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListObjectVersionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListObjectVersionsAction(this->awsS3CRTClient,
                success,
                listObjectVersionsRequest,
                listObjectVersionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListObjectsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListObjectsResult &listObjectsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListObjectsOutcomeCallable callable;

public:
    FListObjectsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListObjectsRequest listObjectsRequest,
        FAWSS3CRTListObjectsResult &listObjectsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listObjectsResult(listObjectsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListObjectsCallable(listObjectsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListObjectsOutcome = callable.get();

                success = awsListObjectsOutcome.IsSuccess();
                if (success) {
                    listObjectsResult.fromAWS(awsListObjectsOutcome.GetResult());
                }

                errorType = fromAWS(awsListObjectsOutcome.GetError().GetErrorType());
                errorMessage = ("ListObjects error: " + awsListObjectsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListObjects Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListObjects(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListObjectsRequest listObjectsRequest,
    FAWSS3CRTListObjectsResult &listObjectsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListObjectsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListObjectsAction(this->awsS3CRTClient,
                success,
                listObjectsRequest,
                listObjectsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListObjectsV2Action :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListObjectsV2Result &listObjectsV2Result;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListObjectsV2OutcomeCallable callable;

public:
    FListObjectsV2Action(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListObjectsV2Request listObjectsV2Request,
        FAWSS3CRTListObjectsV2Result &listObjectsV2Result,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listObjectsV2Result(listObjectsV2Result), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListObjectsV2Callable(listObjectsV2Request.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListObjectsV2Outcome = callable.get();

                success = awsListObjectsV2Outcome.IsSuccess();
                if (success) {
                    listObjectsV2Result.fromAWS(awsListObjectsV2Outcome.GetResult());
                }

                errorType = fromAWS(awsListObjectsV2Outcome.GetError().GetErrorType());
                errorMessage = ("ListObjectsV2 error: " + awsListObjectsV2Outcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListObjectsV2 Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListObjectsV2(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListObjectsV2Request listObjectsV2Request,
    FAWSS3CRTListObjectsV2Result &listObjectsV2Result,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListObjectsV2Action>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListObjectsV2Action(this->awsS3CRTClient,
                success,
                listObjectsV2Request,
                listObjectsV2Result,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FListPartsAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTListPartsResult &listPartsResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::ListPartsOutcomeCallable callable;

public:
    FListPartsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTListPartsRequest listPartsRequest,
        FAWSS3CRTListPartsResult &listPartsResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listPartsResult(listPartsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->ListPartsCallable(listPartsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListPartsOutcome = callable.get();

                success = awsListPartsOutcome.IsSuccess();
                if (success) {
                    listPartsResult.fromAWS(awsListPartsOutcome.GetResult());
                }

                errorType = fromAWS(awsListPartsOutcome.GetError().GetErrorType());
                errorMessage = ("ListParts error: " + awsListPartsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListParts Request");
    }

#endif
};

#endif

void
US3CRTClientObject::ListParts(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTListPartsRequest listPartsRequest,
    FAWSS3CRTListPartsResult &listPartsResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListPartsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListPartsAction(this->awsS3CRTClient,
                success,
                listPartsRequest,
                listPartsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketAccelerateConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketAccelerateConfigurationOutcomeCallable callable;

public:
    FPutBucketAccelerateConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketAccelerateConfigurationRequest putBucketAccelerateConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketAccelerateConfigurationCallable(putBucketAccelerateConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketAccelerateConfigurationOutcome = callable.get();

                success = awsPutBucketAccelerateConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketAccelerateConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketAccelerateConfiguration error: " + awsPutBucketAccelerateConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketAccelerateConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketAccelerateConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketAccelerateConfigurationRequest putBucketAccelerateConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketAccelerateConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketAccelerateConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketAccelerateConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketAclAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketAclOutcomeCallable callable;

public:
    FPutBucketAclAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketAclRequest putBucketAclRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketAclCallable(putBucketAclRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketAclOutcome = callable.get();

                success = awsPutBucketAclOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketAclOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketAcl error: " + awsPutBucketAclOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketAcl Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketAcl(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketAclRequest putBucketAclRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketAclAction(this->awsS3CRTClient,
                success,
                putBucketAclRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketAnalyticsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketAnalyticsConfigurationOutcomeCallable callable;

public:
    FPutBucketAnalyticsConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketAnalyticsConfigurationRequest putBucketAnalyticsConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketAnalyticsConfigurationCallable(putBucketAnalyticsConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketAnalyticsConfigurationOutcome = callable.get();

                success = awsPutBucketAnalyticsConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketAnalyticsConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketAnalyticsConfiguration error: " + awsPutBucketAnalyticsConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketAnalyticsConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketAnalyticsConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketAnalyticsConfigurationRequest putBucketAnalyticsConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketAnalyticsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketAnalyticsConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketAnalyticsConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketCorsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketCorsOutcomeCallable callable;

public:
    FPutBucketCorsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketCorsRequest putBucketCorsRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketCorsCallable(putBucketCorsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketCorsOutcome = callable.get();

                success = awsPutBucketCorsOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketCorsOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketCors error: " + awsPutBucketCorsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketCors Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketCors(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketCorsRequest putBucketCorsRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketCorsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketCorsAction(this->awsS3CRTClient,
                success,
                putBucketCorsRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketEncryptionAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketEncryptionOutcomeCallable callable;

public:
    FPutBucketEncryptionAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketEncryptionRequest putBucketEncryptionRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketEncryptionCallable(putBucketEncryptionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketEncryptionOutcome = callable.get();

                success = awsPutBucketEncryptionOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketEncryptionOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketEncryption error: " + awsPutBucketEncryptionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketEncryption Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketEncryption(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketEncryptionRequest putBucketEncryptionRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketEncryptionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketEncryptionAction(this->awsS3CRTClient,
                success,
                putBucketEncryptionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketIntelligentTieringConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketIntelligentTieringConfigurationOutcomeCallable callable;

public:
    FPutBucketIntelligentTieringConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketIntelligentTieringConfigurationRequest putBucketIntelligentTieringConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketIntelligentTieringConfigurationCallable(putBucketIntelligentTieringConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketIntelligentTieringConfigurationOutcome = callable.get();

                success = awsPutBucketIntelligentTieringConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketIntelligentTieringConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketIntelligentTieringConfiguration error: " + awsPutBucketIntelligentTieringConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketIntelligentTieringConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketIntelligentTieringConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketIntelligentTieringConfigurationRequest putBucketIntelligentTieringConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketIntelligentTieringConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketIntelligentTieringConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketIntelligentTieringConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketInventoryConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketInventoryConfigurationOutcomeCallable callable;

public:
    FPutBucketInventoryConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketInventoryConfigurationRequest putBucketInventoryConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketInventoryConfigurationCallable(putBucketInventoryConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketInventoryConfigurationOutcome = callable.get();

                success = awsPutBucketInventoryConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketInventoryConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketInventoryConfiguration error: " + awsPutBucketInventoryConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketInventoryConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketInventoryConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketInventoryConfigurationRequest putBucketInventoryConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketInventoryConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketInventoryConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketInventoryConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketLifecycleConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FPutBucketLifecycleConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketLifecycleConfigurationCallable(putBucketLifecycleConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketLifecycleConfigurationOutcome = callable.get();

                success = awsPutBucketLifecycleConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketLifecycleConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketLifecycleConfiguration error: " + awsPutBucketLifecycleConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketLifecycleConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketLifecycleConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketLifecycleConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketLifecycleConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketLoggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketLoggingOutcomeCallable callable;

public:
    FPutBucketLoggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketLoggingRequest putBucketLoggingRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketLoggingCallable(putBucketLoggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketLoggingOutcome = callable.get();

                success = awsPutBucketLoggingOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketLoggingOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketLogging error: " + awsPutBucketLoggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketLogging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketLogging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketLoggingRequest putBucketLoggingRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketLoggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketLoggingAction(this->awsS3CRTClient,
                success,
                putBucketLoggingRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketMetricsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketMetricsConfigurationOutcomeCallable callable;

public:
    FPutBucketMetricsConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketMetricsConfigurationRequest putBucketMetricsConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketMetricsConfigurationCallable(putBucketMetricsConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketMetricsConfigurationOutcome = callable.get();

                success = awsPutBucketMetricsConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketMetricsConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketMetricsConfiguration error: " + awsPutBucketMetricsConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketMetricsConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketMetricsConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketMetricsConfigurationRequest putBucketMetricsConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketMetricsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketMetricsConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketMetricsConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketNotificationConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketNotificationConfigurationOutcomeCallable callable;

public:
    FPutBucketNotificationConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketNotificationConfigurationRequest putBucketNotificationConfigurationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketNotificationConfigurationCallable(putBucketNotificationConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketNotificationConfigurationOutcome = callable.get();

                success = awsPutBucketNotificationConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketNotificationConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketNotificationConfiguration error: " + awsPutBucketNotificationConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketNotificationConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketNotificationConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketNotificationConfigurationRequest putBucketNotificationConfigurationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketNotificationConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketNotificationConfigurationAction(this->awsS3CRTClient,
                success,
                putBucketNotificationConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketOwnershipControlsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketOwnershipControlsOutcomeCallable callable;

public:
    FPutBucketOwnershipControlsAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketOwnershipControlsRequest putBucketOwnershipControlsRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketOwnershipControlsCallable(putBucketOwnershipControlsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketOwnershipControlsOutcome = callable.get();

                success = awsPutBucketOwnershipControlsOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketOwnershipControlsOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketOwnershipControls error: " + awsPutBucketOwnershipControlsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketOwnershipControls Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketOwnershipControls(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketOwnershipControlsRequest putBucketOwnershipControlsRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketOwnershipControlsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketOwnershipControlsAction(this->awsS3CRTClient,
                success,
                putBucketOwnershipControlsRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketPolicyOutcomeCallable callable;

public:
    FPutBucketPolicyAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketPolicyRequest putBucketPolicyRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketPolicyCallable(putBucketPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketPolicyOutcome = callable.get();

                success = awsPutBucketPolicyOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketPolicy error: " + awsPutBucketPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketPolicy Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketPolicyRequest putBucketPolicyRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketPolicyAction(this->awsS3CRTClient,
                success,
                putBucketPolicyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketReplicationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketReplicationOutcomeCallable callable;

public:
    FPutBucketReplicationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketReplicationRequest putBucketReplicationRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketReplicationCallable(putBucketReplicationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketReplicationOutcome = callable.get();

                success = awsPutBucketReplicationOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketReplicationOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketReplication error: " + awsPutBucketReplicationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketReplication Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketReplication(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketReplicationRequest putBucketReplicationRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketReplicationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketReplicationAction(this->awsS3CRTClient,
                success,
                putBucketReplicationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketRequestPaymentAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketRequestPaymentOutcomeCallable callable;

public:
    FPutBucketRequestPaymentAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketRequestPaymentRequest putBucketRequestPaymentRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketRequestPaymentCallable(putBucketRequestPaymentRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketRequestPaymentOutcome = callable.get();

                success = awsPutBucketRequestPaymentOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketRequestPaymentOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketRequestPayment error: " + awsPutBucketRequestPaymentOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketRequestPayment Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketRequestPayment(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketRequestPaymentRequest putBucketRequestPaymentRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketRequestPaymentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketRequestPaymentAction(this->awsS3CRTClient,
                success,
                putBucketRequestPaymentRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketTaggingOutcomeCallable callable;

public:
    FPutBucketTaggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketTaggingRequest putBucketTaggingRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketTaggingCallable(putBucketTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketTaggingOutcome = callable.get();

                success = awsPutBucketTaggingOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketTagging error: " + awsPutBucketTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketTagging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketTaggingRequest putBucketTaggingRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketTaggingAction(this->awsS3CRTClient,
                success,
                putBucketTaggingRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketVersioningAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketVersioningOutcomeCallable callable;

public:
    FPutBucketVersioningAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketVersioningRequest putBucketVersioningRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketVersioningCallable(putBucketVersioningRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketVersioningOutcome = callable.get();

                success = awsPutBucketVersioningOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketVersioningOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketVersioning error: " + awsPutBucketVersioningOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketVersioning Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketVersioning(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketVersioningRequest putBucketVersioningRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketVersioningAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketVersioningAction(this->awsS3CRTClient,
                success,
                putBucketVersioningRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutBucketWebsiteAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutBucketWebsiteOutcomeCallable callable;

public:
    FPutBucketWebsiteAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutBucketWebsiteRequest putBucketWebsiteRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutBucketWebsiteCallable(putBucketWebsiteRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutBucketWebsiteOutcome = callable.get();

                success = awsPutBucketWebsiteOutcome.IsSuccess();

                errorType = fromAWS(awsPutBucketWebsiteOutcome.GetError().GetErrorType());
                errorMessage = ("PutBucketWebsite error: " + awsPutBucketWebsiteOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutBucketWebsite Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutBucketWebsite(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutBucketWebsiteRequest putBucketWebsiteRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketWebsiteAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketWebsiteAction(this->awsS3CRTClient,
                success,
                putBucketWebsiteRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutObjectAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::S3Crt::S3CrtClient *S3CrtClient;
    FAWSS3CRTPutObjectRequest putObjectRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPutObjectAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutObjectRequest putObjectRequest,
        FAWSS3CRTPutObjectResult &putObjectResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : S3CrtClient(S3CrtClient), putObjectRequest(putObjectRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        S3CrtClient->PutObjectAsync(
            putObjectRequest.toAWS(),
            [&success, &putObjectResult, &errorType, &errorMessage, this](
                const Aws::S3Crt::S3CrtClient *awsS3CRTClient,
                const Aws::S3Crt::Model::PutObjectRequest &awsPutObjectRequest,
                const Aws::S3Crt::Model::PutObjectOutcome &awsPutObjectOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPutObjectOutcome.IsSuccess();
                if (success) {
                    putObjectResult.fromAWS(awsPutObjectOutcome.GetResult());
                }

                errorType = fromAWS(awsPutObjectOutcome.GetError().GetErrorType());
                errorMessage = ("PutObject error: " + awsPutObjectOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
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
US3CRTClientObject::PutObject(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutObjectRequest putObjectRequest,
    FAWSS3CRTPutObjectResult &putObjectResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectAction(this->awsS3CRTClient,
                success,
                putObjectRequest,
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
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutObjectAclAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTPutObjectAclResult &putObjectAclResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutObjectAclOutcomeCallable callable;

public:
    FPutObjectAclAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutObjectAclRequest putObjectAclRequest,
        FAWSS3CRTPutObjectAclResult &putObjectAclResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectAclResult(putObjectAclResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutObjectAclCallable(putObjectAclRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutObjectAclOutcome = callable.get();

                success = awsPutObjectAclOutcome.IsSuccess();
                if (success) {
                    putObjectAclResult.fromAWS(awsPutObjectAclOutcome.GetResult());
                }

                errorType = fromAWS(awsPutObjectAclOutcome.GetError().GetErrorType());
                errorMessage = ("PutObjectAcl error: " + awsPutObjectAclOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutObjectAcl Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutObjectAcl(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutObjectAclRequest putObjectAclRequest,
    FAWSS3CRTPutObjectAclResult &putObjectAclResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectAclAction(this->awsS3CRTClient,
                success,
                putObjectAclRequest,
                putObjectAclResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutObjectLegalHoldAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTPutObjectLegalHoldResult &putObjectLegalHoldResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutObjectLegalHoldOutcomeCallable callable;

public:
    FPutObjectLegalHoldAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutObjectLegalHoldRequest putObjectLegalHoldRequest,
        FAWSS3CRTPutObjectLegalHoldResult &putObjectLegalHoldResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectLegalHoldResult(putObjectLegalHoldResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutObjectLegalHoldCallable(putObjectLegalHoldRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutObjectLegalHoldOutcome = callable.get();

                success = awsPutObjectLegalHoldOutcome.IsSuccess();
                if (success) {
                    putObjectLegalHoldResult.fromAWS(awsPutObjectLegalHoldOutcome.GetResult());
                }

                errorType = fromAWS(awsPutObjectLegalHoldOutcome.GetError().GetErrorType());
                errorMessage = ("PutObjectLegalHold error: " + awsPutObjectLegalHoldOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutObjectLegalHold Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutObjectLegalHold(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutObjectLegalHoldRequest putObjectLegalHoldRequest,
    FAWSS3CRTPutObjectLegalHoldResult &putObjectLegalHoldResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectLegalHoldAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectLegalHoldAction(this->awsS3CRTClient,
                success,
                putObjectLegalHoldRequest,
                putObjectLegalHoldResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutObjectLockConfigurationAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTPutObjectLockConfigurationResult &putObjectLockConfigurationResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutObjectLockConfigurationOutcomeCallable callable;

public:
    FPutObjectLockConfigurationAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutObjectLockConfigurationRequest putObjectLockConfigurationRequest,
        FAWSS3CRTPutObjectLockConfigurationResult &putObjectLockConfigurationResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectLockConfigurationResult(putObjectLockConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutObjectLockConfigurationCallable(putObjectLockConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutObjectLockConfigurationOutcome = callable.get();

                success = awsPutObjectLockConfigurationOutcome.IsSuccess();
                if (success) {
                    putObjectLockConfigurationResult.fromAWS(awsPutObjectLockConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsPutObjectLockConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutObjectLockConfiguration error: " + awsPutObjectLockConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutObjectLockConfiguration Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutObjectLockConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutObjectLockConfigurationRequest putObjectLockConfigurationRequest,
    FAWSS3CRTPutObjectLockConfigurationResult &putObjectLockConfigurationResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectLockConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectLockConfigurationAction(this->awsS3CRTClient,
                success,
                putObjectLockConfigurationRequest,
                putObjectLockConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutObjectRetentionAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTPutObjectRetentionResult &putObjectRetentionResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutObjectRetentionOutcomeCallable callable;

public:
    FPutObjectRetentionAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutObjectRetentionRequest putObjectRetentionRequest,
        FAWSS3CRTPutObjectRetentionResult &putObjectRetentionResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectRetentionResult(putObjectRetentionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutObjectRetentionCallable(putObjectRetentionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutObjectRetentionOutcome = callable.get();

                success = awsPutObjectRetentionOutcome.IsSuccess();
                if (success) {
                    putObjectRetentionResult.fromAWS(awsPutObjectRetentionOutcome.GetResult());
                }

                errorType = fromAWS(awsPutObjectRetentionOutcome.GetError().GetErrorType());
                errorMessage = ("PutObjectRetention error: " + awsPutObjectRetentionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutObjectRetention Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutObjectRetention(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutObjectRetentionRequest putObjectRetentionRequest,
    FAWSS3CRTPutObjectRetentionResult &putObjectRetentionResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectRetentionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectRetentionAction(this->awsS3CRTClient,
                success,
                putObjectRetentionRequest,
                putObjectRetentionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutObjectTaggingAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTPutObjectTaggingResult &putObjectTaggingResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutObjectTaggingOutcomeCallable callable;

public:
    FPutObjectTaggingAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutObjectTaggingRequest putObjectTaggingRequest,
        FAWSS3CRTPutObjectTaggingResult &putObjectTaggingResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectTaggingResult(putObjectTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutObjectTaggingCallable(putObjectTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutObjectTaggingOutcome = callable.get();

                success = awsPutObjectTaggingOutcome.IsSuccess();
                if (success) {
                    putObjectTaggingResult.fromAWS(awsPutObjectTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsPutObjectTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("PutObjectTagging error: " + awsPutObjectTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutObjectTagging Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutObjectTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutObjectTaggingRequest putObjectTaggingRequest,
    FAWSS3CRTPutObjectTaggingResult &putObjectTaggingResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectTaggingAction(this->awsS3CRTClient,
                success,
                putObjectTaggingRequest,
                putObjectTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FPutPublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::PutPublicAccessBlockOutcomeCallable callable;

public:
    FPutPublicAccessBlockAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTPutPublicAccessBlockRequest putPublicAccessBlockRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->PutPublicAccessBlockCallable(putPublicAccessBlockRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutPublicAccessBlockOutcome = callable.get();

                success = awsPutPublicAccessBlockOutcome.IsSuccess();

                errorType = fromAWS(awsPutPublicAccessBlockOutcome.GetError().GetErrorType());
                errorMessage = ("PutPublicAccessBlock error: " + awsPutPublicAccessBlockOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutPublicAccessBlock Request");
    }

#endif
};

#endif

void
US3CRTClientObject::PutPublicAccessBlock(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTPutPublicAccessBlockRequest putPublicAccessBlockRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutPublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutPublicAccessBlockAction(this->awsS3CRTClient,
                success,
                putPublicAccessBlockRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FRestoreObjectAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTRestoreObjectResult &restoreObjectResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::RestoreObjectOutcomeCallable callable;

public:
    FRestoreObjectAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTRestoreObjectRequest restoreObjectRequest,
        FAWSS3CRTRestoreObjectResult &restoreObjectResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), restoreObjectResult(restoreObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->RestoreObjectCallable(restoreObjectRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRestoreObjectOutcome = callable.get();

                success = awsRestoreObjectOutcome.IsSuccess();
                if (success) {
                    restoreObjectResult.fromAWS(awsRestoreObjectOutcome.GetResult());
                }

                errorType = fromAWS(awsRestoreObjectOutcome.GetError().GetErrorType());
                errorMessage = ("RestoreObject error: " + awsRestoreObjectOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RestoreObject Request");
    }

#endif
};

#endif

void
US3CRTClientObject::RestoreObject(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTRestoreObjectRequest restoreObjectRequest,
    FAWSS3CRTRestoreObjectResult &restoreObjectResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRestoreObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRestoreObjectAction(this->awsS3CRTClient,
                success,
                restoreObjectRequest,
                restoreObjectResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FSelectObjectContentAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    Aws::S3Crt::Model::SelectObjectContentRequest awsSelectObjectContentRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::SelectObjectContentOutcomeCallable callable;

public:
    FSelectObjectContentAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTSelectObjectContentRequest selectObjectContentRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        awsSelectObjectContentRequest = selectObjectContentRequest.toAWS();
        callable = S3CrtClient->SelectObjectContentCallable(awsSelectObjectContentRequest);
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSelectObjectContentOutcome = callable.get();

            success = awsSelectObjectContentOutcome.IsSuccess();

            errorType = fromAWS(awsSelectObjectContentOutcome.GetError().GetErrorType());
            errorMessage = ("SelectObjectContent error: " + awsSelectObjectContentOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SelectObjectContent Request");
    }

#endif
};

#endif

void
US3CRTClientObject::SelectObjectContent(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTSelectObjectContentRequest selectObjectContentRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSelectObjectContentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSelectObjectContentAction(this->awsS3CRTClient,
                success,
                selectObjectContentRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FUploadPartAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTUploadPartResult &uploadPartResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::UploadPartOutcomeCallable callable;

public:
    FUploadPartAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTUploadPartRequest uploadPartRequest,
        FAWSS3CRTUploadPartResult &uploadPartResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), uploadPartResult(uploadPartResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->UploadPartCallable(uploadPartRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUploadPartOutcome = callable.get();

                success = awsUploadPartOutcome.IsSuccess();
                if (success) {
                    uploadPartResult.fromAWS(awsUploadPartOutcome.GetResult());
                }

                errorType = fromAWS(awsUploadPartOutcome.GetError().GetErrorType());
                errorMessage = ("UploadPart error: " + awsUploadPartOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UploadPart Request");
    }

#endif
};

#endif

void
US3CRTClientObject::UploadPart(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTUploadPartRequest uploadPartRequest,
    FAWSS3CRTUploadPartResult &uploadPartResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUploadPartAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUploadPartAction(this->awsS3CRTClient,
                success,
                uploadPartRequest,
                uploadPartResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FUploadPartCopyAction :  public FPendingLatentAction {
private:
    bool &success;
    FAWSS3CRTUploadPartCopyResult &uploadPartCopyResult;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::UploadPartCopyOutcomeCallable callable;

public:
    FUploadPartCopyAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTUploadPartCopyRequest uploadPartCopyRequest,
        FAWSS3CRTUploadPartCopyResult &uploadPartCopyResult,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), uploadPartCopyResult(uploadPartCopyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->UploadPartCopyCallable(uploadPartCopyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUploadPartCopyOutcome = callable.get();

                success = awsUploadPartCopyOutcome.IsSuccess();
                if (success) {
                    uploadPartCopyResult.fromAWS(awsUploadPartCopyOutcome.GetResult());
                }

                errorType = fromAWS(awsUploadPartCopyOutcome.GetError().GetErrorType());
                errorMessage = ("UploadPartCopy error: " + awsUploadPartCopyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UploadPartCopy Request");
    }

#endif
};

#endif

void
US3CRTClientObject::UploadPartCopy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTUploadPartCopyRequest uploadPartCopyRequest,
    FAWSS3CRTUploadPartCopyResult &uploadPartCopyResult,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUploadPartCopyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUploadPartCopyAction(this->awsS3CRTClient,
                success,
                uploadPartCopyRequest,
                uploadPartCopyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CRTCLIENTSDK && WITH_CORE

class FWriteGetObjectResponseAction : public FPendingLatentAction {
private:
    bool &success;
    ES3CRTError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Crt::Model::WriteGetObjectResponseOutcomeCallable callable;

public:
    FWriteGetObjectResponseAction(
        Aws::S3Crt::S3CrtClient *S3CrtClient,
        bool &success,
        FAWSS3CRTWriteGetObjectResponseRequest writeGetObjectResponseRequest,
        ES3CRTError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        callable = S3CrtClient->WriteGetObjectResponseCallable(writeGetObjectResponseRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsWriteGetObjectResponseOutcome = callable.get();

                success = awsWriteGetObjectResponseOutcome.IsSuccess();

                errorType = fromAWS(awsWriteGetObjectResponseOutcome.GetError().GetErrorType());
                errorMessage = ("WriteGetObjectResponse error: " + awsWriteGetObjectResponseOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("WriteGetObjectResponse Request");
    }

#endif
};

#endif

void
US3CRTClientObject::WriteGetObjectResponse(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3CRTWriteGetObjectResponseRequest writeGetObjectResponseRequest,
    ES3CRTError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CRTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FWriteGetObjectResponseAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FWriteGetObjectResponseAction(this->awsS3CRTClient,
                success,
                writeGetObjectResponseRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}