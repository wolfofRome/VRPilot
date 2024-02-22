/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "S3ControlClientObject.h"
#include "S3ControlGlobals.h"
#include "S3ControlPrivatePCH.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_S3CONTROLCLIENTSDK

ES3ControlError fromAWS(Aws::S3Control::S3ControlErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::S3Control::S3ControlErrors::INCOMPLETE_SIGNATURE:
            return ES3ControlError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::S3Control::S3ControlErrors::INTERNAL_FAILURE:
            return ES3ControlError::INTERNAL_FAILURE;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_ACTION:
            return ES3ControlError::INVALID_ACTION;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_CLIENT_TOKEN_ID:
            return ES3ControlError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_PARAMETER_COMBINATION:
            return ES3ControlError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_QUERY_PARAMETER:
            return ES3ControlError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_PARAMETER_VALUE:
            return ES3ControlError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::S3Control::S3ControlErrors::MISSING_ACTION:
            return ES3ControlError::MISSING_ACTION;
            break;
        case Aws::S3Control::S3ControlErrors::MISSING_AUTHENTICATION_TOKEN:
            return ES3ControlError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::S3Control::S3ControlErrors::MISSING_PARAMETER:
            return ES3ControlError::MISSING_PARAMETER;
            break;
        case Aws::S3Control::S3ControlErrors::OPT_IN_REQUIRED:
            return ES3ControlError::OPT_IN_REQUIRED;
            break;
        case Aws::S3Control::S3ControlErrors::REQUEST_EXPIRED:
            return ES3ControlError::REQUEST_EXPIRED;
            break;
        case Aws::S3Control::S3ControlErrors::SERVICE_UNAVAILABLE:
            return ES3ControlError::SERVICE_UNAVAILABLE;
            break;
        case Aws::S3Control::S3ControlErrors::THROTTLING:
            return ES3ControlError::THROTTLING;
            break;
        case Aws::S3Control::S3ControlErrors::VALIDATION:
            return ES3ControlError::VALIDATION;
            break;
        case Aws::S3Control::S3ControlErrors::ACCESS_DENIED:
            return ES3ControlError::ACCESS_DENIED;
            break;
        case Aws::S3Control::S3ControlErrors::RESOURCE_NOT_FOUND:
            return ES3ControlError::RESOURCE_NOT_FOUND;
            break;
        case Aws::S3Control::S3ControlErrors::UNRECOGNIZED_CLIENT:
            return ES3ControlError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::S3Control::S3ControlErrors::MALFORMED_QUERY_STRING:
            return ES3ControlError::MALFORMED_QUERY_STRING;
            break;
        case Aws::S3Control::S3ControlErrors::SLOW_DOWN:
            return ES3ControlError::SLOW_DOWN;
            break;
        case Aws::S3Control::S3ControlErrors::REQUEST_TIME_TOO_SKEWED:
            return ES3ControlError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_SIGNATURE:
            return ES3ControlError::INVALID_SIGNATURE;
            break;
        case Aws::S3Control::S3ControlErrors::SIGNATURE_DOES_NOT_MATCH:
            return ES3ControlError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_ACCESS_KEY_ID:
            return ES3ControlError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::S3Control::S3ControlErrors::REQUEST_TIMEOUT:
            return ES3ControlError::REQUEST_TIMEOUT;
            break;
        case Aws::S3Control::S3ControlErrors::NETWORK_CONNECTION:
            return ES3ControlError::NETWORK_CONNECTION;
            break;
        case Aws::S3Control::S3ControlErrors::UNKNOWN:
            return ES3ControlError::UNKNOWN;
            break;
        case Aws::S3Control::S3ControlErrors::BAD_REQUEST:
            return ES3ControlError::BAD_REQUEST;
            break;
        case Aws::S3Control::S3ControlErrors::BUCKET_ALREADY_EXISTS:
            return ES3ControlError::BUCKET_ALREADY_EXISTS;
            break;
        case Aws::S3Control::S3ControlErrors::BUCKET_ALREADY_OWNED_BY_YOU:
            return ES3ControlError::BUCKET_ALREADY_OWNED_BY_YOU;
            break;
        case Aws::S3Control::S3ControlErrors::IDEMPOTENCY:
            return ES3ControlError::IDEMPOTENCY;
            break;
        case Aws::S3Control::S3ControlErrors::INTERNAL_SERVICE:
            return ES3ControlError::INTERNAL_SERVICE;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_NEXT_TOKEN:
            return ES3ControlError::INVALID_NEXT_TOKEN;
            break;
        case Aws::S3Control::S3ControlErrors::INVALID_REQUEST:
            return ES3ControlError::INVALID_REQUEST;
            break;
        case Aws::S3Control::S3ControlErrors::JOB_STATUS:
            return ES3ControlError::JOB_STATUS;
            break;
        case Aws::S3Control::S3ControlErrors::NOT_FOUND:
            return ES3ControlError::NOT_FOUND;
            break;
        case Aws::S3Control::S3ControlErrors::NO_SUCH_PUBLIC_ACCESS_BLOCK_CONFIGURATION:
            return ES3ControlError::NO_SUCH_PUBLIC_ACCESS_BLOCK_CONFIGURATION;
            break;
        case Aws::S3Control::S3ControlErrors::TOO_MANY_REQUESTS:
            return ES3ControlError::TOO_MANY_REQUESTS;
            break;
        case Aws::S3Control::S3ControlErrors::TOO_MANY_TAGS:
            return ES3ControlError::TOO_MANY_TAGS;
            break;
        default:
            return ES3ControlError::UNKNOWN;
            break;
    }
}

#endif

US3ControlClientObject *US3ControlClientObject::CreateS3ControlObject(
const FAWSCredentials &credentials,
const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    US3ControlClientObject *S3ControlClient = NewObject<US3ControlClientObject>();
    S3ControlClient->awsS3ControlClient = new Aws::S3Control::S3ControlClient(credentials.toAWS(),
    Aws::MakeShared<Aws::S3Control::S3ControlEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return S3ControlClient;
#endif
    return nullptr;
}

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FCreateAccessPointAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlCreateAccessPointResult &createAccessPointResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::CreateAccessPointOutcomeCallable callable;

public:
    FCreateAccessPointAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FCreateAccessPointRequest createAccessPointRequest,
        FAWSS3ControlCreateAccessPointResult &createAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createAccessPointResult(createAccessPointResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->CreateAccessPointCallable(createAccessPointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateAccessPointOutcome = callable.get();

            success = awsCreateAccessPointOutcome.IsSuccess();
                if (success) {
                    createAccessPointResult.fromAWS(awsCreateAccessPointOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateAccessPointOutcome.GetError().GetErrorType());
                errorMessage = ("CreateAccessPoint error: " + awsCreateAccessPointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateAccessPoint Request");
    }

#endif
};

#endif

void
US3ControlClientObject::CreateAccessPoint(
    UObject *WorldContextObject,
    bool &success,
    FCreateAccessPointRequest createAccessPointRequest,
    FAWSS3ControlCreateAccessPointResult &createAccessPointResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateAccessPointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateAccessPointAction(this->awsS3ControlClient,
                success,
                createAccessPointRequest,
                createAccessPointResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FCreateAccessPointForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlCreateAccessPointForObjectLambdaResult &createAccessPointForObjectLambdaResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::CreateAccessPointForObjectLambdaOutcomeCallable callable;

public:
    FCreateAccessPointForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlCreateAccessPointForObjectLambdaRequest createAccessPointForObjectLambdaRequest,
        FAWSS3ControlCreateAccessPointForObjectLambdaResult &createAccessPointForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createAccessPointForObjectLambdaResult(createAccessPointForObjectLambdaResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->CreateAccessPointForObjectLambdaCallable(createAccessPointForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateAccessPointForObjectLambdaOutcome = callable.get();

            success = awsCreateAccessPointForObjectLambdaOutcome.IsSuccess();
                if (success) {
                    createAccessPointForObjectLambdaResult.fromAWS(awsCreateAccessPointForObjectLambdaOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateAccessPointForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("CreateAccessPointForObjectLambda error: " + awsCreateAccessPointForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateAccessPointForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::CreateAccessPointForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlCreateAccessPointForObjectLambdaRequest createAccessPointForObjectLambdaRequest,
    FAWSS3ControlCreateAccessPointForObjectLambdaResult &createAccessPointForObjectLambdaResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateAccessPointForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateAccessPointForObjectLambdaAction(this->awsS3ControlClient,
                success,
                createAccessPointForObjectLambdaRequest,
                createAccessPointForObjectLambdaResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FCreateBucketAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlCreateBucketResult &createBucketResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::CreateBucketOutcomeCallable callable;

public:
    FCreateBucketAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlCreateBucketRequest createBucketRequest,
        FAWSS3ControlCreateBucketResult &createBucketResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createBucketResult(createBucketResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->CreateBucketCallable(createBucketRequest.toAWS());
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
US3ControlClientObject::CreateBucket(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlCreateBucketRequest createBucketRequest,
    FAWSS3ControlCreateBucketResult &createBucketResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateBucketAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FCreateJobAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateJobResult &createJobResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::CreateJobOutcomeCallable callable;

public:
    FCreateJobAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FCreateJobRequest createJobRequest,
        FCreateJobResult &createJobResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createJobResult(createJobResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->CreateJobCallable(createJobRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateJobOutcome = callable.get();

            success = awsCreateJobOutcome.IsSuccess();
                if (success) {
                    createJobResult.fromAWS(awsCreateJobOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateJobOutcome.GetError().GetErrorType());
                errorMessage = ("CreateJob error: " + awsCreateJobOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateJob Request");
    }

#endif
};

#endif

void
US3ControlClientObject::CreateJob(
    UObject *WorldContextObject,
    bool &success,
    FCreateJobRequest createJobRequest,
    FCreateJobResult &createJobResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateJobAction(this->awsS3ControlClient,
                success,
                createJobRequest,
                createJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FCreateMultiRegionAccessPointAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlCreateMultiRegionAccessPointResult &createMultiRegionAccessPointResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::CreateMultiRegionAccessPointOutcomeCallable callable;

public:
    FCreateMultiRegionAccessPointAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlCreateMultiRegionAccessPointRequest createMultiRegionAccessPointRequest,
        FAWSS3ControlCreateMultiRegionAccessPointResult &createMultiRegionAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createMultiRegionAccessPointResult(createMultiRegionAccessPointResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->CreateMultiRegionAccessPointCallable(createMultiRegionAccessPointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateMultiRegionAccessPointOutcome = callable.get();

            success = awsCreateMultiRegionAccessPointOutcome.IsSuccess();
                if (success) {
                    createMultiRegionAccessPointResult.fromAWS(awsCreateMultiRegionAccessPointOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateMultiRegionAccessPointOutcome.GetError().GetErrorType());
                errorMessage = ("CreateMultiRegionAccessPoint error: " + awsCreateMultiRegionAccessPointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateMultiRegionAccessPoint Request");
    }

#endif
};

#endif

void
US3ControlClientObject::CreateMultiRegionAccessPoint(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlCreateMultiRegionAccessPointRequest createMultiRegionAccessPointRequest,
    FAWSS3ControlCreateMultiRegionAccessPointResult &createMultiRegionAccessPointResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateMultiRegionAccessPointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateMultiRegionAccessPointAction(this->awsS3ControlClient,
                success,
                createMultiRegionAccessPointRequest,
                createMultiRegionAccessPointResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteAccessPointAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteAccessPointOutcomeCallable callable;

public:
    FDeleteAccessPointAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FDeleteAccessPointRequest deleteAccessPointRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteAccessPointCallable(deleteAccessPointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteAccessPointOutcome = callable.get();

            success = awsDeleteAccessPointOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteAccessPointOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteAccessPoint error: " + awsDeleteAccessPointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteAccessPoint Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteAccessPoint(
    UObject *WorldContextObject,
    bool &success,
    FDeleteAccessPointRequest deleteAccessPointRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAccessPointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAccessPointAction(this->awsS3ControlClient,
                success,
                deleteAccessPointRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteAccessPointForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteAccessPointForObjectLambdaOutcomeCallable callable;

public:
    FDeleteAccessPointForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteAccessPointForObjectLambdaRequest deleteAccessPointForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteAccessPointForObjectLambdaCallable(deleteAccessPointForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteAccessPointForObjectLambdaOutcome = callable.get();

            success = awsDeleteAccessPointForObjectLambdaOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteAccessPointForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteAccessPointForObjectLambda error: " + awsDeleteAccessPointForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteAccessPointForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteAccessPointForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteAccessPointForObjectLambdaRequest deleteAccessPointForObjectLambdaRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAccessPointForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAccessPointForObjectLambdaAction(this->awsS3ControlClient,
                success,
                deleteAccessPointForObjectLambdaRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteAccessPointPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteAccessPointPolicyOutcomeCallable callable;

public:
    FDeleteAccessPointPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FDeleteAccessPointPolicyRequest deleteAccessPointPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteAccessPointPolicyCallable(deleteAccessPointPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteAccessPointPolicyOutcome = callable.get();

            success = awsDeleteAccessPointPolicyOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteAccessPointPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteAccessPointPolicy error: " + awsDeleteAccessPointPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteAccessPointPolicy Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteAccessPointPolicy(
    UObject *WorldContextObject,
    bool &success,
    FDeleteAccessPointPolicyRequest deleteAccessPointPolicyRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAccessPointPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAccessPointPolicyAction(this->awsS3ControlClient,
                success,
                deleteAccessPointPolicyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteAccessPointPolicyForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteAccessPointPolicyForObjectLambdaOutcomeCallable callable;

public:
    FDeleteAccessPointPolicyForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteAccessPointPolicyForObjectLambdaRequest deleteAccessPointPolicyForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteAccessPointPolicyForObjectLambdaCallable(deleteAccessPointPolicyForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteAccessPointPolicyForObjectLambdaOutcome = callable.get();

            success = awsDeleteAccessPointPolicyForObjectLambdaOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteAccessPointPolicyForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteAccessPointPolicyForObjectLambda error: " + awsDeleteAccessPointPolicyForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteAccessPointPolicyForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteAccessPointPolicyForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteAccessPointPolicyForObjectLambdaRequest deleteAccessPointPolicyForObjectLambdaRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAccessPointPolicyForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAccessPointPolicyForObjectLambdaAction(this->awsS3ControlClient,
                success,
                deleteAccessPointPolicyForObjectLambdaRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteBucketAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteBucketOutcomeCallable callable;

public:
    FDeleteBucketAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteBucketRequest deleteBucketRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteBucketCallable(deleteBucketRequest.toAWS());
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
US3ControlClientObject::DeleteBucket(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteBucketRequest deleteBucketRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteBucketLifecycleConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FDeleteBucketLifecycleConfigurationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteBucketLifecycleConfigurationRequest deleteBucketLifecycleConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteBucketLifecycleConfigurationCallable(deleteBucketLifecycleConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBucketLifecycleConfigurationOutcome = callable.get();

            success = awsDeleteBucketLifecycleConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBucketLifecycleConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBucketLifecycleConfiguration error: " + awsDeleteBucketLifecycleConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBucketLifecycleConfiguration Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteBucketLifecycleConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteBucketLifecycleConfigurationRequest deleteBucketLifecycleConfigurationRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketLifecycleConfigurationAction(this->awsS3ControlClient,
                success,
                deleteBucketLifecycleConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteBucketPolicyOutcomeCallable callable;

public:
    FDeleteBucketPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteBucketPolicyRequest deleteBucketPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteBucketPolicyCallable(deleteBucketPolicyRequest.toAWS());
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
US3ControlClientObject::DeleteBucketPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteBucketPolicyRequest deleteBucketPolicyRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketPolicyAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteBucketTaggingOutcomeCallable callable;

public:
    FDeleteBucketTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteBucketTaggingRequest deleteBucketTaggingRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteBucketTaggingCallable(deleteBucketTaggingRequest.toAWS());
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
US3ControlClientObject::DeleteBucketTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteBucketTaggingRequest deleteBucketTaggingRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketTaggingAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteJobTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteJobTaggingResult &deleteJobTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteJobTaggingOutcomeCallable callable;

public:
    FDeleteJobTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FDeleteJobTaggingRequest deleteJobTaggingRequest,
        FDeleteJobTaggingResult &deleteJobTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteJobTaggingResult(deleteJobTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteJobTaggingCallable(deleteJobTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteJobTaggingOutcome = callable.get();

            success = awsDeleteJobTaggingOutcome.IsSuccess();
                if (success) {
                    deleteJobTaggingResult.fromAWS(awsDeleteJobTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteJobTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteJobTagging error: " + awsDeleteJobTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteJobTagging Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteJobTagging(
    UObject *WorldContextObject,
    bool &success,
    FDeleteJobTaggingRequest deleteJobTaggingRequest,
    FDeleteJobTaggingResult &deleteJobTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteJobTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteJobTaggingAction(this->awsS3ControlClient,
                success,
                deleteJobTaggingRequest,
                deleteJobTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteMultiRegionAccessPointAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlDeleteMultiRegionAccessPointResult &deleteMultiRegionAccessPointResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteMultiRegionAccessPointOutcomeCallable callable;

public:
    FDeleteMultiRegionAccessPointAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteMultiRegionAccessPointRequest deleteMultiRegionAccessPointRequest,
        FAWSS3ControlDeleteMultiRegionAccessPointResult &deleteMultiRegionAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteMultiRegionAccessPointResult(deleteMultiRegionAccessPointResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteMultiRegionAccessPointCallable(deleteMultiRegionAccessPointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteMultiRegionAccessPointOutcome = callable.get();

            success = awsDeleteMultiRegionAccessPointOutcome.IsSuccess();
                if (success) {
                    deleteMultiRegionAccessPointResult.fromAWS(awsDeleteMultiRegionAccessPointOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteMultiRegionAccessPointOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteMultiRegionAccessPoint error: " + awsDeleteMultiRegionAccessPointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteMultiRegionAccessPoint Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteMultiRegionAccessPoint(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteMultiRegionAccessPointRequest deleteMultiRegionAccessPointRequest,
    FAWSS3ControlDeleteMultiRegionAccessPointResult &deleteMultiRegionAccessPointResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteMultiRegionAccessPointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteMultiRegionAccessPointAction(this->awsS3ControlClient,
                success,
                deleteMultiRegionAccessPointRequest,
                deleteMultiRegionAccessPointResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeletePublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeletePublicAccessBlockOutcomeCallable callable;

public:
    FDeletePublicAccessBlockAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FS3ControlDeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeletePublicAccessBlockCallable(deletePublicAccessBlockRequest.toAWS());
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
US3ControlClientObject::DeletePublicAccessBlock(
    UObject *WorldContextObject,
    bool &success,
    FS3ControlDeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeletePublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeletePublicAccessBlockAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteStorageLensConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteStorageLensConfigurationOutcomeCallable callable;

public:
    FDeleteStorageLensConfigurationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteStorageLensConfigurationRequest deleteStorageLensConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteStorageLensConfigurationCallable(deleteStorageLensConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteStorageLensConfigurationOutcome = callable.get();

            success = awsDeleteStorageLensConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteStorageLensConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteStorageLensConfiguration error: " + awsDeleteStorageLensConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteStorageLensConfiguration Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteStorageLensConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteStorageLensConfigurationRequest deleteStorageLensConfigurationRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteStorageLensConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteStorageLensConfigurationAction(this->awsS3ControlClient,
                success,
                deleteStorageLensConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDeleteStorageLensConfigurationTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlDeleteStorageLensConfigurationTaggingResult &deleteStorageLensConfigurationTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DeleteStorageLensConfigurationTaggingOutcomeCallable callable;

public:
    FDeleteStorageLensConfigurationTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDeleteStorageLensConfigurationTaggingRequest deleteStorageLensConfigurationTaggingRequest,
        FAWSS3ControlDeleteStorageLensConfigurationTaggingResult &deleteStorageLensConfigurationTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteStorageLensConfigurationTaggingResult(deleteStorageLensConfigurationTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DeleteStorageLensConfigurationTaggingCallable(deleteStorageLensConfigurationTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteStorageLensConfigurationTaggingOutcome = callable.get();

            success = awsDeleteStorageLensConfigurationTaggingOutcome.IsSuccess();
                if (success) {
                    deleteStorageLensConfigurationTaggingResult.fromAWS(awsDeleteStorageLensConfigurationTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteStorageLensConfigurationTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteStorageLensConfigurationTagging error: " + awsDeleteStorageLensConfigurationTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteStorageLensConfigurationTagging Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DeleteStorageLensConfigurationTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDeleteStorageLensConfigurationTaggingRequest deleteStorageLensConfigurationTaggingRequest,
    FAWSS3ControlDeleteStorageLensConfigurationTaggingResult &deleteStorageLensConfigurationTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteStorageLensConfigurationTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteStorageLensConfigurationTaggingAction(this->awsS3ControlClient,
                success,
                deleteStorageLensConfigurationTaggingRequest,
                deleteStorageLensConfigurationTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDescribeJobAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeJobResult &describeJobResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DescribeJobOutcomeCallable callable;

public:
    FDescribeJobAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FDescribeJobRequest describeJobRequest,
        FDescribeJobResult &describeJobResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeJobResult(describeJobResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DescribeJobCallable(describeJobRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeJobOutcome = callable.get();

            success = awsDescribeJobOutcome.IsSuccess();
                if (success) {
                    describeJobResult.fromAWS(awsDescribeJobOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeJobOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeJob error: " + awsDescribeJobOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeJob Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DescribeJob(
    UObject *WorldContextObject,
    bool &success,
    FDescribeJobRequest describeJobRequest,
    FDescribeJobResult &describeJobResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeJobAction(this->awsS3ControlClient,
                success,
                describeJobRequest,
                describeJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FDescribeMultiRegionAccessPointOperationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlDescribeMultiRegionAccessPointOperationResult &describeMultiRegionAccessPointOperationResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::DescribeMultiRegionAccessPointOperationOutcomeCallable callable;

public:
    FDescribeMultiRegionAccessPointOperationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlDescribeMultiRegionAccessPointOperationRequest describeMultiRegionAccessPointOperationRequest,
        FAWSS3ControlDescribeMultiRegionAccessPointOperationResult &describeMultiRegionAccessPointOperationResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeMultiRegionAccessPointOperationResult(describeMultiRegionAccessPointOperationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->DescribeMultiRegionAccessPointOperationCallable(describeMultiRegionAccessPointOperationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeMultiRegionAccessPointOperationOutcome = callable.get();

            success = awsDescribeMultiRegionAccessPointOperationOutcome.IsSuccess();
                if (success) {
                    describeMultiRegionAccessPointOperationResult.fromAWS(awsDescribeMultiRegionAccessPointOperationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeMultiRegionAccessPointOperationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeMultiRegionAccessPointOperation error: " + awsDescribeMultiRegionAccessPointOperationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeMultiRegionAccessPointOperation Request");
    }

#endif
};

#endif

void
US3ControlClientObject::DescribeMultiRegionAccessPointOperation(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlDescribeMultiRegionAccessPointOperationRequest describeMultiRegionAccessPointOperationRequest,
    FAWSS3ControlDescribeMultiRegionAccessPointOperationResult &describeMultiRegionAccessPointOperationResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeMultiRegionAccessPointOperationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeMultiRegionAccessPointOperationAction(this->awsS3ControlClient,
                success,
                describeMultiRegionAccessPointOperationRequest,
                describeMultiRegionAccessPointOperationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointAction : public FPendingLatentAction {
private:
    bool &success;
    FGetAccessPointResult &getAccessPointResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointOutcomeCallable callable;

public:
    FGetAccessPointAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FGetAccessPointRequest getAccessPointRequest,
        FGetAccessPointResult &getAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointResult(getAccessPointResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointCallable(getAccessPointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointOutcome = callable.get();

            success = awsGetAccessPointOutcome.IsSuccess();
                if (success) {
                    getAccessPointResult.fromAWS(awsGetAccessPointOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPoint error: " + awsGetAccessPointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPoint Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPoint(
    UObject *WorldContextObject,
    bool &success,
    FGetAccessPointRequest getAccessPointRequest,
    FGetAccessPointResult &getAccessPointResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointAction(this->awsS3ControlClient,
                success,
                getAccessPointRequest,
                getAccessPointResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointConfigurationForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetAccessPointConfigurationForObjectLambdaResult &getAccessPointConfigurationForObjectLambdaResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointConfigurationForObjectLambdaOutcomeCallable callable;

public:
    FGetAccessPointConfigurationForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetAccessPointConfigurationForObjectLambdaRequest getAccessPointConfigurationForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointConfigurationForObjectLambdaResult &getAccessPointConfigurationForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointConfigurationForObjectLambdaResult(getAccessPointConfigurationForObjectLambdaResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointConfigurationForObjectLambdaCallable(getAccessPointConfigurationForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointConfigurationForObjectLambdaOutcome = callable.get();

            success = awsGetAccessPointConfigurationForObjectLambdaOutcome.IsSuccess();
                if (success) {
                    getAccessPointConfigurationForObjectLambdaResult.fromAWS(awsGetAccessPointConfigurationForObjectLambdaOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointConfigurationForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPointConfigurationForObjectLambda error: " + awsGetAccessPointConfigurationForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPointConfigurationForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPointConfigurationForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetAccessPointConfigurationForObjectLambdaRequest getAccessPointConfigurationForObjectLambdaRequest,
    FAWSS3ControlGetAccessPointConfigurationForObjectLambdaResult &getAccessPointConfigurationForObjectLambdaResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointConfigurationForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointConfigurationForObjectLambdaAction(this->awsS3ControlClient,
                success,
                getAccessPointConfigurationForObjectLambdaRequest,
                getAccessPointConfigurationForObjectLambdaResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetAccessPointForObjectLambdaResult &getAccessPointForObjectLambdaResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointForObjectLambdaOutcomeCallable callable;

public:
    FGetAccessPointForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetAccessPointForObjectLambdaRequest getAccessPointForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointForObjectLambdaResult &getAccessPointForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointForObjectLambdaResult(getAccessPointForObjectLambdaResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointForObjectLambdaCallable(getAccessPointForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointForObjectLambdaOutcome = callable.get();

            success = awsGetAccessPointForObjectLambdaOutcome.IsSuccess();
                if (success) {
                    getAccessPointForObjectLambdaResult.fromAWS(awsGetAccessPointForObjectLambdaOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPointForObjectLambda error: " + awsGetAccessPointForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPointForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPointForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetAccessPointForObjectLambdaRequest getAccessPointForObjectLambdaRequest,
    FAWSS3ControlGetAccessPointForObjectLambdaResult &getAccessPointForObjectLambdaResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointForObjectLambdaAction(this->awsS3ControlClient,
                success,
                getAccessPointForObjectLambdaRequest,
                getAccessPointForObjectLambdaResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FGetAccessPointPolicyResult &getAccessPointPolicyResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointPolicyOutcomeCallable callable;

public:
    FGetAccessPointPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FGetAccessPointPolicyRequest getAccessPointPolicyRequest,
        FGetAccessPointPolicyResult &getAccessPointPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointPolicyResult(getAccessPointPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointPolicyCallable(getAccessPointPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointPolicyOutcome = callable.get();

            success = awsGetAccessPointPolicyOutcome.IsSuccess();
                if (success) {
                    getAccessPointPolicyResult.fromAWS(awsGetAccessPointPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPointPolicy error: " + awsGetAccessPointPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPointPolicy Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPointPolicy(
    UObject *WorldContextObject,
    bool &success,
    FGetAccessPointPolicyRequest getAccessPointPolicyRequest,
    FGetAccessPointPolicyResult &getAccessPointPolicyResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointPolicyAction(this->awsS3ControlClient,
                success,
                getAccessPointPolicyRequest,
                getAccessPointPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointPolicyForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetAccessPointPolicyForObjectLambdaResult &getAccessPointPolicyForObjectLambdaResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointPolicyForObjectLambdaOutcomeCallable callable;

public:
    FGetAccessPointPolicyForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetAccessPointPolicyForObjectLambdaRequest getAccessPointPolicyForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointPolicyForObjectLambdaResult &getAccessPointPolicyForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointPolicyForObjectLambdaResult(getAccessPointPolicyForObjectLambdaResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointPolicyForObjectLambdaCallable(getAccessPointPolicyForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointPolicyForObjectLambdaOutcome = callable.get();

            success = awsGetAccessPointPolicyForObjectLambdaOutcome.IsSuccess();
                if (success) {
                    getAccessPointPolicyForObjectLambdaResult.fromAWS(awsGetAccessPointPolicyForObjectLambdaOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointPolicyForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPointPolicyForObjectLambda error: " + awsGetAccessPointPolicyForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPointPolicyForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPointPolicyForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetAccessPointPolicyForObjectLambdaRequest getAccessPointPolicyForObjectLambdaRequest,
    FAWSS3ControlGetAccessPointPolicyForObjectLambdaResult &getAccessPointPolicyForObjectLambdaResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointPolicyForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointPolicyForObjectLambdaAction(this->awsS3ControlClient,
                success,
                getAccessPointPolicyForObjectLambdaRequest,
                getAccessPointPolicyForObjectLambdaResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointPolicyStatusAction : public FPendingLatentAction {
private:
    bool &success;
    FGetAccessPointPolicyStatusResult &getAccessPointPolicyStatusResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointPolicyStatusOutcomeCallable callable;

public:
    FGetAccessPointPolicyStatusAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FGetAccessPointPolicyStatusRequest getAccessPointPolicyStatusRequest,
        FGetAccessPointPolicyStatusResult &getAccessPointPolicyStatusResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointPolicyStatusResult(getAccessPointPolicyStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointPolicyStatusCallable(getAccessPointPolicyStatusRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointPolicyStatusOutcome = callable.get();

            success = awsGetAccessPointPolicyStatusOutcome.IsSuccess();
                if (success) {
                    getAccessPointPolicyStatusResult.fromAWS(awsGetAccessPointPolicyStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointPolicyStatusOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPointPolicyStatus error: " + awsGetAccessPointPolicyStatusOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPointPolicyStatus Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPointPolicyStatus(
    UObject *WorldContextObject,
    bool &success,
    FGetAccessPointPolicyStatusRequest getAccessPointPolicyStatusRequest,
    FGetAccessPointPolicyStatusResult &getAccessPointPolicyStatusResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointPolicyStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointPolicyStatusAction(this->awsS3ControlClient,
                success,
                getAccessPointPolicyStatusRequest,
                getAccessPointPolicyStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetAccessPointPolicyStatusForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult &getAccessPointPolicyStatusForObjectLambdaResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetAccessPointPolicyStatusForObjectLambdaOutcomeCallable callable;

public:
    FGetAccessPointPolicyStatusForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaRequest getAccessPointPolicyStatusForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult &getAccessPointPolicyStatusForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccessPointPolicyStatusForObjectLambdaResult(getAccessPointPolicyStatusForObjectLambdaResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetAccessPointPolicyStatusForObjectLambdaCallable(getAccessPointPolicyStatusForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccessPointPolicyStatusForObjectLambdaOutcome = callable.get();

            success = awsGetAccessPointPolicyStatusForObjectLambdaOutcome.IsSuccess();
                if (success) {
                    getAccessPointPolicyStatusForObjectLambdaResult.fromAWS(awsGetAccessPointPolicyStatusForObjectLambdaOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccessPointPolicyStatusForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccessPointPolicyStatusForObjectLambda error: " + awsGetAccessPointPolicyStatusForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccessPointPolicyStatusForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetAccessPointPolicyStatusForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaRequest getAccessPointPolicyStatusForObjectLambdaRequest,
    FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult &getAccessPointPolicyStatusForObjectLambdaResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccessPointPolicyStatusForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccessPointPolicyStatusForObjectLambdaAction(this->awsS3ControlClient,
                success,
                getAccessPointPolicyStatusForObjectLambdaRequest,
                getAccessPointPolicyStatusForObjectLambdaResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetBucketAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetBucketResult &getBucketResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetBucketOutcomeCallable callable;

public:
    FGetBucketAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetBucketRequest getBucketRequest,
        FAWSS3ControlGetBucketResult &getBucketResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketResult(getBucketResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetBucketCallable(getBucketRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetBucketOutcome = callable.get();

            success = awsGetBucketOutcome.IsSuccess();
                if (success) {
                    getBucketResult.fromAWS(awsGetBucketOutcome.GetResult());
                }

                errorType = fromAWS(awsGetBucketOutcome.GetError().GetErrorType());
                errorMessage = ("GetBucket error: " + awsGetBucketOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetBucket Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetBucket(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetBucketRequest getBucketRequest,
    FAWSS3ControlGetBucketResult &getBucketResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAction(this->awsS3ControlClient,
                success,
                getBucketRequest,
                getBucketResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetBucketLifecycleConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FGetBucketLifecycleConfigurationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
        FAWSS3ControlGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLifecycleConfigurationResult(getBucketLifecycleConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetBucketLifecycleConfigurationCallable(getBucketLifecycleConfigurationRequest.toAWS());
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
US3ControlClientObject::GetBucketLifecycleConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
    FAWSS3ControlGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLifecycleConfigurationAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetBucketPolicyResult &getBucketPolicyResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetBucketPolicyOutcomeCallable callable;

public:
    FGetBucketPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetBucketPolicyRequest getBucketPolicyRequest,
        FAWSS3ControlGetBucketPolicyResult &getBucketPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketPolicyResult(getBucketPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetBucketPolicyCallable(getBucketPolicyRequest.toAWS());
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
US3ControlClientObject::GetBucketPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetBucketPolicyRequest getBucketPolicyRequest,
    FAWSS3ControlGetBucketPolicyResult &getBucketPolicyResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketPolicyAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetBucketTaggingResult &getBucketTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetBucketTaggingOutcomeCallable callable;

public:
    FGetBucketTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetBucketTaggingRequest getBucketTaggingRequest,
        FAWSS3ControlGetBucketTaggingResult &getBucketTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketTaggingResult(getBucketTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetBucketTaggingCallable(getBucketTaggingRequest.toAWS());
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
US3ControlClientObject::GetBucketTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetBucketTaggingRequest getBucketTaggingRequest,
    FAWSS3ControlGetBucketTaggingResult &getBucketTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketTaggingAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetBucketVersioningAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetBucketVersioningResult &getBucketVersioningResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetBucketVersioningOutcomeCallable callable;

public:
    FGetBucketVersioningAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetBucketVersioningRequest getBucketVersioningRequest,
        FAWSS3ControlGetBucketVersioningResult &getBucketVersioningResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketVersioningResult(getBucketVersioningResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetBucketVersioningCallable(getBucketVersioningRequest.toAWS());
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
US3ControlClientObject::GetBucketVersioning(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetBucketVersioningRequest getBucketVersioningRequest,
    FAWSS3ControlGetBucketVersioningResult &getBucketVersioningResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketVersioningAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketVersioningAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetJobTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FGetJobTaggingResult &getJobTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetJobTaggingOutcomeCallable callable;

public:
    FGetJobTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FGetJobTaggingRequest getJobTaggingRequest,
        FGetJobTaggingResult &getJobTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getJobTaggingResult(getJobTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetJobTaggingCallable(getJobTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetJobTaggingOutcome = callable.get();

            success = awsGetJobTaggingOutcome.IsSuccess();
                if (success) {
                    getJobTaggingResult.fromAWS(awsGetJobTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetJobTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("GetJobTagging error: " + awsGetJobTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetJobTagging Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetJobTagging(
    UObject *WorldContextObject,
    bool &success,
    FGetJobTaggingRequest getJobTaggingRequest,
    FGetJobTaggingResult &getJobTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetJobTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetJobTaggingAction(this->awsS3ControlClient,
                success,
                getJobTaggingRequest,
                getJobTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetMultiRegionAccessPointAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetMultiRegionAccessPointResult &getMultiRegionAccessPointResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetMultiRegionAccessPointOutcomeCallable callable;

public:
    FGetMultiRegionAccessPointAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointRequest getMultiRegionAccessPointRequest,
        FAWSS3ControlGetMultiRegionAccessPointResult &getMultiRegionAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getMultiRegionAccessPointResult(getMultiRegionAccessPointResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetMultiRegionAccessPointCallable(getMultiRegionAccessPointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetMultiRegionAccessPointOutcome = callable.get();

            success = awsGetMultiRegionAccessPointOutcome.IsSuccess();
                if (success) {
                    getMultiRegionAccessPointResult.fromAWS(awsGetMultiRegionAccessPointOutcome.GetResult());
                }

                errorType = fromAWS(awsGetMultiRegionAccessPointOutcome.GetError().GetErrorType());
                errorMessage = ("GetMultiRegionAccessPoint error: " + awsGetMultiRegionAccessPointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetMultiRegionAccessPoint Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetMultiRegionAccessPoint(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetMultiRegionAccessPointRequest getMultiRegionAccessPointRequest,
    FAWSS3ControlGetMultiRegionAccessPointResult &getMultiRegionAccessPointResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetMultiRegionAccessPointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetMultiRegionAccessPointAction(this->awsS3ControlClient,
                success,
                getMultiRegionAccessPointRequest,
                getMultiRegionAccessPointResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetMultiRegionAccessPointPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetMultiRegionAccessPointPolicyResult &getMultiRegionAccessPointPolicyResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetMultiRegionAccessPointPolicyOutcomeCallable callable;

public:
    FGetMultiRegionAccessPointPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointPolicyRequest getMultiRegionAccessPointPolicyRequest,
        FAWSS3ControlGetMultiRegionAccessPointPolicyResult &getMultiRegionAccessPointPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getMultiRegionAccessPointPolicyResult(getMultiRegionAccessPointPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetMultiRegionAccessPointPolicyCallable(getMultiRegionAccessPointPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetMultiRegionAccessPointPolicyOutcome = callable.get();

            success = awsGetMultiRegionAccessPointPolicyOutcome.IsSuccess();
                if (success) {
                    getMultiRegionAccessPointPolicyResult.fromAWS(awsGetMultiRegionAccessPointPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetMultiRegionAccessPointPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetMultiRegionAccessPointPolicy error: " + awsGetMultiRegionAccessPointPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetMultiRegionAccessPointPolicy Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetMultiRegionAccessPointPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetMultiRegionAccessPointPolicyRequest getMultiRegionAccessPointPolicyRequest,
    FAWSS3ControlGetMultiRegionAccessPointPolicyResult &getMultiRegionAccessPointPolicyResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetMultiRegionAccessPointPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetMultiRegionAccessPointPolicyAction(this->awsS3ControlClient,
                success,
                getMultiRegionAccessPointPolicyRequest,
                getMultiRegionAccessPointPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetMultiRegionAccessPointPolicyStatusAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetMultiRegionAccessPointPolicyStatusResult &getMultiRegionAccessPointPolicyStatusResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetMultiRegionAccessPointPolicyStatusOutcomeCallable callable;

public:
    FGetMultiRegionAccessPointPolicyStatusAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointPolicyStatusRequest getMultiRegionAccessPointPolicyStatusRequest,
        FAWSS3ControlGetMultiRegionAccessPointPolicyStatusResult &getMultiRegionAccessPointPolicyStatusResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getMultiRegionAccessPointPolicyStatusResult(getMultiRegionAccessPointPolicyStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetMultiRegionAccessPointPolicyStatusCallable(getMultiRegionAccessPointPolicyStatusRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetMultiRegionAccessPointPolicyStatusOutcome = callable.get();

            success = awsGetMultiRegionAccessPointPolicyStatusOutcome.IsSuccess();
                if (success) {
                    getMultiRegionAccessPointPolicyStatusResult.fromAWS(awsGetMultiRegionAccessPointPolicyStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsGetMultiRegionAccessPointPolicyStatusOutcome.GetError().GetErrorType());
                errorMessage = ("GetMultiRegionAccessPointPolicyStatus error: " + awsGetMultiRegionAccessPointPolicyStatusOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetMultiRegionAccessPointPolicyStatus Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetMultiRegionAccessPointPolicyStatus(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetMultiRegionAccessPointPolicyStatusRequest getMultiRegionAccessPointPolicyStatusRequest,
    FAWSS3ControlGetMultiRegionAccessPointPolicyStatusResult &getMultiRegionAccessPointPolicyStatusResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetMultiRegionAccessPointPolicyStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetMultiRegionAccessPointPolicyStatusAction(this->awsS3ControlClient,
                success,
                getMultiRegionAccessPointPolicyStatusRequest,
                getMultiRegionAccessPointPolicyStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetMultiRegionAccessPointRoutesAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetMultiRegionAccessPointRoutesResult &getMultiRegionAccessPointRoutesResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetMultiRegionAccessPointRoutesOutcomeCallable callable;

public:
    FGetMultiRegionAccessPointRoutesAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointRoutesRequest getMultiRegionAccessPointRoutesRequest,
        FAWSS3ControlGetMultiRegionAccessPointRoutesResult &getMultiRegionAccessPointRoutesResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getMultiRegionAccessPointRoutesResult(getMultiRegionAccessPointRoutesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetMultiRegionAccessPointRoutesCallable(getMultiRegionAccessPointRoutesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetMultiRegionAccessPointRoutesOutcome = callable.get();

            success = awsGetMultiRegionAccessPointRoutesOutcome.IsSuccess();
                if (success) {
                    getMultiRegionAccessPointRoutesResult.fromAWS(awsGetMultiRegionAccessPointRoutesOutcome.GetResult());
                }

                errorType = fromAWS(awsGetMultiRegionAccessPointRoutesOutcome.GetError().GetErrorType());
                errorMessage = ("GetMultiRegionAccessPointRoutes error: " + awsGetMultiRegionAccessPointRoutesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetMultiRegionAccessPointRoutes Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetMultiRegionAccessPointRoutes(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetMultiRegionAccessPointRoutesRequest getMultiRegionAccessPointRoutesRequest,
    FAWSS3ControlGetMultiRegionAccessPointRoutesResult &getMultiRegionAccessPointRoutesResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetMultiRegionAccessPointRoutesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetMultiRegionAccessPointRoutesAction(this->awsS3ControlClient,
                success,
                getMultiRegionAccessPointRoutesRequest,
                getMultiRegionAccessPointRoutesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetPublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    FS3ControlGetPublicAccessBlockResult &getPublicAccessBlockResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetPublicAccessBlockOutcomeCallable callable;

public:
    FGetPublicAccessBlockAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FS3ControlGetPublicAccessBlockRequest getPublicAccessBlockRequest,
        FS3ControlGetPublicAccessBlockResult &getPublicAccessBlockResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getPublicAccessBlockResult(getPublicAccessBlockResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetPublicAccessBlockCallable(getPublicAccessBlockRequest.toAWS());
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
US3ControlClientObject::GetPublicAccessBlock(
    UObject *WorldContextObject,
    bool &success,
    FS3ControlGetPublicAccessBlockRequest getPublicAccessBlockRequest,
    FS3ControlGetPublicAccessBlockResult &getPublicAccessBlockResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPublicAccessBlockAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetStorageLensConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetStorageLensConfigurationResult &getStorageLensConfigurationResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetStorageLensConfigurationOutcomeCallable callable;

public:
    FGetStorageLensConfigurationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetStorageLensConfigurationRequest getStorageLensConfigurationRequest,
        FAWSS3ControlGetStorageLensConfigurationResult &getStorageLensConfigurationResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getStorageLensConfigurationResult(getStorageLensConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetStorageLensConfigurationCallable(getStorageLensConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetStorageLensConfigurationOutcome = callable.get();

            success = awsGetStorageLensConfigurationOutcome.IsSuccess();
                if (success) {
                    getStorageLensConfigurationResult.fromAWS(awsGetStorageLensConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetStorageLensConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetStorageLensConfiguration error: " + awsGetStorageLensConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetStorageLensConfiguration Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetStorageLensConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetStorageLensConfigurationRequest getStorageLensConfigurationRequest,
    FAWSS3ControlGetStorageLensConfigurationResult &getStorageLensConfigurationResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetStorageLensConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetStorageLensConfigurationAction(this->awsS3ControlClient,
                success,
                getStorageLensConfigurationRequest,
                getStorageLensConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FGetStorageLensConfigurationTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlGetStorageLensConfigurationTaggingResult &getStorageLensConfigurationTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::GetStorageLensConfigurationTaggingOutcomeCallable callable;

public:
    FGetStorageLensConfigurationTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlGetStorageLensConfigurationTaggingRequest getStorageLensConfigurationTaggingRequest,
        FAWSS3ControlGetStorageLensConfigurationTaggingResult &getStorageLensConfigurationTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getStorageLensConfigurationTaggingResult(getStorageLensConfigurationTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->GetStorageLensConfigurationTaggingCallable(getStorageLensConfigurationTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetStorageLensConfigurationTaggingOutcome = callable.get();

            success = awsGetStorageLensConfigurationTaggingOutcome.IsSuccess();
                if (success) {
                    getStorageLensConfigurationTaggingResult.fromAWS(awsGetStorageLensConfigurationTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetStorageLensConfigurationTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("GetStorageLensConfigurationTagging error: " + awsGetStorageLensConfigurationTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetStorageLensConfigurationTagging Request");
    }

#endif
};

#endif

void
US3ControlClientObject::GetStorageLensConfigurationTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlGetStorageLensConfigurationTaggingRequest getStorageLensConfigurationTaggingRequest,
    FAWSS3ControlGetStorageLensConfigurationTaggingResult &getStorageLensConfigurationTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetStorageLensConfigurationTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetStorageLensConfigurationTaggingAction(this->awsS3ControlClient,
                success,
                getStorageLensConfigurationTaggingRequest,
                getStorageLensConfigurationTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FListAccessPointsAction : public FPendingLatentAction {
private:
    bool &success;
    FListAccessPointsResult &listAccessPointsResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::ListAccessPointsOutcomeCallable callable;

public:
    FListAccessPointsAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FListAccessPointsRequest listAccessPointsRequest,
        FListAccessPointsResult &listAccessPointsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listAccessPointsResult(listAccessPointsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->ListAccessPointsCallable(listAccessPointsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListAccessPointsOutcome = callable.get();

            success = awsListAccessPointsOutcome.IsSuccess();
                if (success) {
                    listAccessPointsResult.fromAWS(awsListAccessPointsOutcome.GetResult());
                }

                errorType = fromAWS(awsListAccessPointsOutcome.GetError().GetErrorType());
                errorMessage = ("ListAccessPoints error: " + awsListAccessPointsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListAccessPoints Request");
    }

#endif
};

#endif

void
US3ControlClientObject::ListAccessPoints(
    UObject *WorldContextObject,
    bool &success,
    FListAccessPointsRequest listAccessPointsRequest,
    FListAccessPointsResult &listAccessPointsResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListAccessPointsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListAccessPointsAction(this->awsS3ControlClient,
                success,
                listAccessPointsRequest,
                listAccessPointsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FListAccessPointsForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlListAccessPointsForObjectLambdaResult &listAccessPointsForObjectLambdaResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::ListAccessPointsForObjectLambdaOutcomeCallable callable;

public:
    FListAccessPointsForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlListAccessPointsForObjectLambdaRequest listAccessPointsForObjectLambdaRequest,
        FAWSS3ControlListAccessPointsForObjectLambdaResult &listAccessPointsForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listAccessPointsForObjectLambdaResult(listAccessPointsForObjectLambdaResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->ListAccessPointsForObjectLambdaCallable(listAccessPointsForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListAccessPointsForObjectLambdaOutcome = callable.get();

            success = awsListAccessPointsForObjectLambdaOutcome.IsSuccess();
                if (success) {
                    listAccessPointsForObjectLambdaResult.fromAWS(awsListAccessPointsForObjectLambdaOutcome.GetResult());
                }

                errorType = fromAWS(awsListAccessPointsForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("ListAccessPointsForObjectLambda error: " + awsListAccessPointsForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListAccessPointsForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::ListAccessPointsForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlListAccessPointsForObjectLambdaRequest listAccessPointsForObjectLambdaRequest,
    FAWSS3ControlListAccessPointsForObjectLambdaResult &listAccessPointsForObjectLambdaResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListAccessPointsForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListAccessPointsForObjectLambdaAction(this->awsS3ControlClient,
                success,
                listAccessPointsForObjectLambdaRequest,
                listAccessPointsForObjectLambdaResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FListJobsAction : public FPendingLatentAction {
private:
    bool &success;
    FListJobsResult &listJobsResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::ListJobsOutcomeCallable callable;

public:
    FListJobsAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FListJobsRequest listJobsRequest,
        FListJobsResult &listJobsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listJobsResult(listJobsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->ListJobsCallable(listJobsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListJobsOutcome = callable.get();

            success = awsListJobsOutcome.IsSuccess();
                if (success) {
                    listJobsResult.fromAWS(awsListJobsOutcome.GetResult());
                }

                errorType = fromAWS(awsListJobsOutcome.GetError().GetErrorType());
                errorMessage = ("ListJobs error: " + awsListJobsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListJobs Request");
    }

#endif
};

#endif

void
US3ControlClientObject::ListJobs(
    UObject *WorldContextObject,
    bool &success,
    FListJobsRequest listJobsRequest,
    FListJobsResult &listJobsResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListJobsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListJobsAction(this->awsS3ControlClient,
                success,
                listJobsRequest,
                listJobsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FListMultiRegionAccessPointsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlListMultiRegionAccessPointsResult &listMultiRegionAccessPointsResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::ListMultiRegionAccessPointsOutcomeCallable callable;

public:
    FListMultiRegionAccessPointsAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlListMultiRegionAccessPointsRequest listMultiRegionAccessPointsRequest,
        FAWSS3ControlListMultiRegionAccessPointsResult &listMultiRegionAccessPointsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listMultiRegionAccessPointsResult(listMultiRegionAccessPointsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->ListMultiRegionAccessPointsCallable(listMultiRegionAccessPointsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListMultiRegionAccessPointsOutcome = callable.get();

            success = awsListMultiRegionAccessPointsOutcome.IsSuccess();
                if (success) {
                    listMultiRegionAccessPointsResult.fromAWS(awsListMultiRegionAccessPointsOutcome.GetResult());
                }

                errorType = fromAWS(awsListMultiRegionAccessPointsOutcome.GetError().GetErrorType());
                errorMessage = ("ListMultiRegionAccessPoints error: " + awsListMultiRegionAccessPointsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListMultiRegionAccessPoints Request");
    }

#endif
};

#endif

void
US3ControlClientObject::ListMultiRegionAccessPoints(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlListMultiRegionAccessPointsRequest listMultiRegionAccessPointsRequest,
    FAWSS3ControlListMultiRegionAccessPointsResult &listMultiRegionAccessPointsResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListMultiRegionAccessPointsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListMultiRegionAccessPointsAction(this->awsS3ControlClient,
                success,
                listMultiRegionAccessPointsRequest,
                listMultiRegionAccessPointsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FListRegionalBucketsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlListRegionalBucketsResult &listRegionalBucketsResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::ListRegionalBucketsOutcomeCallable callable;

public:
    FListRegionalBucketsAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlListRegionalBucketsRequest listRegionalBucketsRequest,
        FAWSS3ControlListRegionalBucketsResult &listRegionalBucketsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listRegionalBucketsResult(listRegionalBucketsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->ListRegionalBucketsCallable(listRegionalBucketsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListRegionalBucketsOutcome = callable.get();

            success = awsListRegionalBucketsOutcome.IsSuccess();
                if (success) {
                    listRegionalBucketsResult.fromAWS(awsListRegionalBucketsOutcome.GetResult());
                }

                errorType = fromAWS(awsListRegionalBucketsOutcome.GetError().GetErrorType());
                errorMessage = ("ListRegionalBuckets error: " + awsListRegionalBucketsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListRegionalBuckets Request");
    }

#endif
};

#endif

void
US3ControlClientObject::ListRegionalBuckets(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlListRegionalBucketsRequest listRegionalBucketsRequest,
    FAWSS3ControlListRegionalBucketsResult &listRegionalBucketsResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListRegionalBucketsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListRegionalBucketsAction(this->awsS3ControlClient,
                success,
                listRegionalBucketsRequest,
                listRegionalBucketsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FListStorageLensConfigurationsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlListStorageLensConfigurationsResult &listStorageLensConfigurationsResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::ListStorageLensConfigurationsOutcomeCallable callable;

public:
    FListStorageLensConfigurationsAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlListStorageLensConfigurationsRequest listStorageLensConfigurationsRequest,
        FAWSS3ControlListStorageLensConfigurationsResult &listStorageLensConfigurationsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listStorageLensConfigurationsResult(listStorageLensConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->ListStorageLensConfigurationsCallable(listStorageLensConfigurationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListStorageLensConfigurationsOutcome = callable.get();

            success = awsListStorageLensConfigurationsOutcome.IsSuccess();
                if (success) {
                    listStorageLensConfigurationsResult.fromAWS(awsListStorageLensConfigurationsOutcome.GetResult());
                }

                errorType = fromAWS(awsListStorageLensConfigurationsOutcome.GetError().GetErrorType());
                errorMessage = ("ListStorageLensConfigurations error: " + awsListStorageLensConfigurationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListStorageLensConfigurations Request");
    }

#endif
};

#endif

void
US3ControlClientObject::ListStorageLensConfigurations(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlListStorageLensConfigurationsRequest listStorageLensConfigurationsRequest,
    FAWSS3ControlListStorageLensConfigurationsResult &listStorageLensConfigurationsResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListStorageLensConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListStorageLensConfigurationsAction(this->awsS3ControlClient,
                success,
                listStorageLensConfigurationsRequest,
                listStorageLensConfigurationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutAccessPointConfigurationForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutAccessPointConfigurationForObjectLambdaOutcomeCallable callable;

public:
    FPutAccessPointConfigurationForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutAccessPointConfigurationForObjectLambdaRequest putAccessPointConfigurationForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutAccessPointConfigurationForObjectLambdaCallable(putAccessPointConfigurationForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutAccessPointConfigurationForObjectLambdaOutcome = callable.get();

            success = awsPutAccessPointConfigurationForObjectLambdaOutcome.IsSuccess();

                errorType = fromAWS(awsPutAccessPointConfigurationForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("PutAccessPointConfigurationForObjectLambda error: " + awsPutAccessPointConfigurationForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutAccessPointConfigurationForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutAccessPointConfigurationForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutAccessPointConfigurationForObjectLambdaRequest putAccessPointConfigurationForObjectLambdaRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutAccessPointConfigurationForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutAccessPointConfigurationForObjectLambdaAction(this->awsS3ControlClient,
                success,
                putAccessPointConfigurationForObjectLambdaRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutAccessPointPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutAccessPointPolicyOutcomeCallable callable;

public:
    FPutAccessPointPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FPutAccessPointPolicyRequest putAccessPointPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutAccessPointPolicyCallable(putAccessPointPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutAccessPointPolicyOutcome = callable.get();

            success = awsPutAccessPointPolicyOutcome.IsSuccess();

                errorType = fromAWS(awsPutAccessPointPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("PutAccessPointPolicy error: " + awsPutAccessPointPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutAccessPointPolicy Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutAccessPointPolicy(
    UObject *WorldContextObject,
    bool &success,
    FPutAccessPointPolicyRequest putAccessPointPolicyRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutAccessPointPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutAccessPointPolicyAction(this->awsS3ControlClient,
                success,
                putAccessPointPolicyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutAccessPointPolicyForObjectLambdaAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutAccessPointPolicyForObjectLambdaOutcomeCallable callable;

public:
    FPutAccessPointPolicyForObjectLambdaAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutAccessPointPolicyForObjectLambdaRequest putAccessPointPolicyForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutAccessPointPolicyForObjectLambdaCallable(putAccessPointPolicyForObjectLambdaRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutAccessPointPolicyForObjectLambdaOutcome = callable.get();

            success = awsPutAccessPointPolicyForObjectLambdaOutcome.IsSuccess();

                errorType = fromAWS(awsPutAccessPointPolicyForObjectLambdaOutcome.GetError().GetErrorType());
                errorMessage = ("PutAccessPointPolicyForObjectLambda error: " + awsPutAccessPointPolicyForObjectLambdaOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutAccessPointPolicyForObjectLambda Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutAccessPointPolicyForObjectLambda(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutAccessPointPolicyForObjectLambdaRequest putAccessPointPolicyForObjectLambdaRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutAccessPointPolicyForObjectLambdaAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutAccessPointPolicyForObjectLambdaAction(this->awsS3ControlClient,
                success,
                putAccessPointPolicyForObjectLambdaRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutBucketLifecycleConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FPutBucketLifecycleConfigurationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutBucketLifecycleConfigurationCallable(putBucketLifecycleConfigurationRequest.toAWS());
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
US3ControlClientObject::PutBucketLifecycleConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketLifecycleConfigurationAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutBucketPolicyOutcomeCallable callable;

public:
    FPutBucketPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutBucketPolicyRequest putBucketPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutBucketPolicyCallable(putBucketPolicyRequest.toAWS());
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
US3ControlClientObject::PutBucketPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutBucketPolicyRequest putBucketPolicyRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketPolicyAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutBucketTaggingOutcomeCallable callable;

public:
    FPutBucketTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutBucketTaggingRequest putBucketTaggingRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutBucketTaggingCallable(putBucketTaggingRequest.toAWS());
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
US3ControlClientObject::PutBucketTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutBucketTaggingRequest putBucketTaggingRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketTaggingAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutBucketVersioningAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutBucketVersioningOutcomeCallable callable;

public:
    FPutBucketVersioningAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutBucketVersioningRequest putBucketVersioningRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutBucketVersioningCallable(putBucketVersioningRequest.toAWS());
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
US3ControlClientObject::PutBucketVersioning(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutBucketVersioningRequest putBucketVersioningRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketVersioningAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketVersioningAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutJobTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FPutJobTaggingResult &putJobTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutJobTaggingOutcomeCallable callable;

public:
    FPutJobTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FPutJobTaggingRequest putJobTaggingRequest,
        FPutJobTaggingResult &putJobTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putJobTaggingResult(putJobTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutJobTaggingCallable(putJobTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutJobTaggingOutcome = callable.get();

            success = awsPutJobTaggingOutcome.IsSuccess();
                if (success) {
                    putJobTaggingResult.fromAWS(awsPutJobTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsPutJobTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("PutJobTagging error: " + awsPutJobTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutJobTagging Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutJobTagging(
    UObject *WorldContextObject,
    bool &success,
    FPutJobTaggingRequest putJobTaggingRequest,
    FPutJobTaggingResult &putJobTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutJobTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutJobTaggingAction(this->awsS3ControlClient,
                success,
                putJobTaggingRequest,
                putJobTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutMultiRegionAccessPointPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlPutMultiRegionAccessPointPolicyResult &putMultiRegionAccessPointPolicyResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutMultiRegionAccessPointPolicyOutcomeCallable callable;

public:
    FPutMultiRegionAccessPointPolicyAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutMultiRegionAccessPointPolicyRequest putMultiRegionAccessPointPolicyRequest,
        FAWSS3ControlPutMultiRegionAccessPointPolicyResult &putMultiRegionAccessPointPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putMultiRegionAccessPointPolicyResult(putMultiRegionAccessPointPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutMultiRegionAccessPointPolicyCallable(putMultiRegionAccessPointPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutMultiRegionAccessPointPolicyOutcome = callable.get();

            success = awsPutMultiRegionAccessPointPolicyOutcome.IsSuccess();
                if (success) {
                    putMultiRegionAccessPointPolicyResult.fromAWS(awsPutMultiRegionAccessPointPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsPutMultiRegionAccessPointPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("PutMultiRegionAccessPointPolicy error: " + awsPutMultiRegionAccessPointPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutMultiRegionAccessPointPolicy Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutMultiRegionAccessPointPolicy(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutMultiRegionAccessPointPolicyRequest putMultiRegionAccessPointPolicyRequest,
    FAWSS3ControlPutMultiRegionAccessPointPolicyResult &putMultiRegionAccessPointPolicyResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutMultiRegionAccessPointPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutMultiRegionAccessPointPolicyAction(this->awsS3ControlClient,
                success,
                putMultiRegionAccessPointPolicyRequest,
                putMultiRegionAccessPointPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutPublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutPublicAccessBlockOutcomeCallable callable;

public:
    FPutPublicAccessBlockAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FS3ControlPutPublicAccessBlockRequest putPublicAccessBlockRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutPublicAccessBlockCallable(putPublicAccessBlockRequest.toAWS());
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
US3ControlClientObject::PutPublicAccessBlock(
    UObject *WorldContextObject,
    bool &success,
    FS3ControlPutPublicAccessBlockRequest putPublicAccessBlockRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutPublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutPublicAccessBlockAction(this->awsS3ControlClient,
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
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutStorageLensConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutStorageLensConfigurationOutcomeCallable callable;

public:
    FPutStorageLensConfigurationAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutStorageLensConfigurationRequest putStorageLensConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutStorageLensConfigurationCallable(putStorageLensConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutStorageLensConfigurationOutcome = callable.get();

            success = awsPutStorageLensConfigurationOutcome.IsSuccess();

                errorType = fromAWS(awsPutStorageLensConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("PutStorageLensConfiguration error: " + awsPutStorageLensConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutStorageLensConfiguration Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutStorageLensConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutStorageLensConfigurationRequest putStorageLensConfigurationRequest,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutStorageLensConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutStorageLensConfigurationAction(this->awsS3ControlClient,
                success,
                putStorageLensConfigurationRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FPutStorageLensConfigurationTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlPutStorageLensConfigurationTaggingResult &putStorageLensConfigurationTaggingResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::PutStorageLensConfigurationTaggingOutcomeCallable callable;

public:
    FPutStorageLensConfigurationTaggingAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlPutStorageLensConfigurationTaggingRequest putStorageLensConfigurationTaggingRequest,
        FAWSS3ControlPutStorageLensConfigurationTaggingResult &putStorageLensConfigurationTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putStorageLensConfigurationTaggingResult(putStorageLensConfigurationTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->PutStorageLensConfigurationTaggingCallable(putStorageLensConfigurationTaggingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutStorageLensConfigurationTaggingOutcome = callable.get();

            success = awsPutStorageLensConfigurationTaggingOutcome.IsSuccess();
                if (success) {
                    putStorageLensConfigurationTaggingResult.fromAWS(awsPutStorageLensConfigurationTaggingOutcome.GetResult());
                }

                errorType = fromAWS(awsPutStorageLensConfigurationTaggingOutcome.GetError().GetErrorType());
                errorMessage = ("PutStorageLensConfigurationTagging error: " + awsPutStorageLensConfigurationTaggingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutStorageLensConfigurationTagging Request");
    }

#endif
};

#endif

void
US3ControlClientObject::PutStorageLensConfigurationTagging(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlPutStorageLensConfigurationTaggingRequest putStorageLensConfigurationTaggingRequest,
    FAWSS3ControlPutStorageLensConfigurationTaggingResult &putStorageLensConfigurationTaggingResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutStorageLensConfigurationTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutStorageLensConfigurationTaggingAction(this->awsS3ControlClient,
                success,
                putStorageLensConfigurationTaggingRequest,
                putStorageLensConfigurationTaggingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FSubmitMultiRegionAccessPointRoutesAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ControlSubmitMultiRegionAccessPointRoutesResult &submitMultiRegionAccessPointRoutesResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::SubmitMultiRegionAccessPointRoutesOutcomeCallable callable;

public:
    FSubmitMultiRegionAccessPointRoutesAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FAWSS3ControlSubmitMultiRegionAccessPointRoutesRequest submitMultiRegionAccessPointRoutesRequest,
        FAWSS3ControlSubmitMultiRegionAccessPointRoutesResult &submitMultiRegionAccessPointRoutesResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), submitMultiRegionAccessPointRoutesResult(submitMultiRegionAccessPointRoutesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->SubmitMultiRegionAccessPointRoutesCallable(submitMultiRegionAccessPointRoutesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSubmitMultiRegionAccessPointRoutesOutcome = callable.get();

            success = awsSubmitMultiRegionAccessPointRoutesOutcome.IsSuccess();
                if (success) {
                    submitMultiRegionAccessPointRoutesResult.fromAWS(awsSubmitMultiRegionAccessPointRoutesOutcome.GetResult());
                }

                errorType = fromAWS(awsSubmitMultiRegionAccessPointRoutesOutcome.GetError().GetErrorType());
                errorMessage = ("SubmitMultiRegionAccessPointRoutes error: " + awsSubmitMultiRegionAccessPointRoutesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SubmitMultiRegionAccessPointRoutes Request");
    }

#endif
};

#endif

void
US3ControlClientObject::SubmitMultiRegionAccessPointRoutes(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ControlSubmitMultiRegionAccessPointRoutesRequest submitMultiRegionAccessPointRoutesRequest,
    FAWSS3ControlSubmitMultiRegionAccessPointRoutesResult &submitMultiRegionAccessPointRoutesResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSubmitMultiRegionAccessPointRoutesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSubmitMultiRegionAccessPointRoutesAction(this->awsS3ControlClient,
                success,
                submitMultiRegionAccessPointRoutesRequest,
                submitMultiRegionAccessPointRoutesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FUpdateJobPriorityAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateJobPriorityResult &updateJobPriorityResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::UpdateJobPriorityOutcomeCallable callable;

public:
    FUpdateJobPriorityAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FUpdateJobPriorityRequest updateJobPriorityRequest,
        FUpdateJobPriorityResult &updateJobPriorityResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateJobPriorityResult(updateJobPriorityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->UpdateJobPriorityCallable(updateJobPriorityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateJobPriorityOutcome = callable.get();

            success = awsUpdateJobPriorityOutcome.IsSuccess();
                if (success) {
                    updateJobPriorityResult.fromAWS(awsUpdateJobPriorityOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateJobPriorityOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateJobPriority error: " + awsUpdateJobPriorityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateJobPriority Request");
    }

#endif
};

#endif

void
US3ControlClientObject::UpdateJobPriority(
    UObject *WorldContextObject,
    bool &success,
    FUpdateJobPriorityRequest updateJobPriorityRequest,
    FUpdateJobPriorityResult &updateJobPriorityResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateJobPriorityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateJobPriorityAction(this->awsS3ControlClient,
                success,
                updateJobPriorityRequest,
                updateJobPriorityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

class FUpdateJobStatusAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateJobStatusResult &updateJobStatusResult;
    ES3ControlError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Control::Model::UpdateJobStatusOutcomeCallable callable;

public:
    FUpdateJobStatusAction(
        Aws::S3Control::S3ControlClient *S3ControlClient,
        bool &success,
        FUpdateJobStatusRequest updateJobStatusRequest,
        FUpdateJobStatusResult &updateJobStatusResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateJobStatusResult(updateJobStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3ControlClient->UpdateJobStatusCallable(updateJobStatusRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateJobStatusOutcome = callable.get();

            success = awsUpdateJobStatusOutcome.IsSuccess();
                if (success) {
                    updateJobStatusResult.fromAWS(awsUpdateJobStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateJobStatusOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateJobStatus error: " + awsUpdateJobStatusOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateJobStatus Request");
    }

#endif
};

#endif

void
US3ControlClientObject::UpdateJobStatus(
    UObject *WorldContextObject,
    bool &success,
    FUpdateJobStatusRequest updateJobStatusRequest,
    FUpdateJobStatusResult &updateJobStatusResult,
    ES3ControlError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateJobStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateJobStatusAction(this->awsS3ControlClient,
                success,
                updateJobStatusRequest,
                updateJobStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}