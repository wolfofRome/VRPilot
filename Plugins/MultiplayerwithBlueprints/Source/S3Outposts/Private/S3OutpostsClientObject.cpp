/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#include "S3OutpostsClientObject.h"
#include "S3OutpostsGlobals.h"
#include "S3OutpostsPrivatePCH.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_S3OUTPOSTSCLIENTSDK

ES3OutpostsError fromAWS(Aws::S3Outposts::S3OutpostsErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::S3Outposts::S3OutpostsErrors::INCOMPLETE_SIGNATURE:
            return ES3OutpostsError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INTERNAL_FAILURE:
            return ES3OutpostsError::INTERNAL_FAILURE;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_ACTION:
            return ES3OutpostsError::INVALID_ACTION;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_CLIENT_TOKEN_ID:
            return ES3OutpostsError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_PARAMETER_COMBINATION:
            return ES3OutpostsError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_QUERY_PARAMETER:
            return ES3OutpostsError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_PARAMETER_VALUE:
            return ES3OutpostsError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::MISSING_ACTION:
            return ES3OutpostsError::MISSING_ACTION;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::MISSING_AUTHENTICATION_TOKEN:
            return ES3OutpostsError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::MISSING_PARAMETER:
            return ES3OutpostsError::MISSING_PARAMETER;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::OPT_IN_REQUIRED:
            return ES3OutpostsError::OPT_IN_REQUIRED;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::REQUEST_EXPIRED:
            return ES3OutpostsError::REQUEST_EXPIRED;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::SERVICE_UNAVAILABLE:
            return ES3OutpostsError::SERVICE_UNAVAILABLE;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::THROTTLING:
            return ES3OutpostsError::THROTTLING;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::VALIDATION:
            return ES3OutpostsError::VALIDATION;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::ACCESS_DENIED:
            return ES3OutpostsError::ACCESS_DENIED;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::RESOURCE_NOT_FOUND:
            return ES3OutpostsError::RESOURCE_NOT_FOUND;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::UNRECOGNIZED_CLIENT:
            return ES3OutpostsError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::MALFORMED_QUERY_STRING:
            return ES3OutpostsError::MALFORMED_QUERY_STRING;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::SLOW_DOWN:
            return ES3OutpostsError::SLOW_DOWN;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::REQUEST_TIME_TOO_SKEWED:
            return ES3OutpostsError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_SIGNATURE:
            return ES3OutpostsError::INVALID_SIGNATURE;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::SIGNATURE_DOES_NOT_MATCH:
            return ES3OutpostsError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INVALID_ACCESS_KEY_ID:
            return ES3OutpostsError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::REQUEST_TIMEOUT:
            return ES3OutpostsError::REQUEST_TIMEOUT;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::NETWORK_CONNECTION:
            return ES3OutpostsError::NETWORK_CONNECTION;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::UNKNOWN:
            return ES3OutpostsError::UNKNOWN;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::CONFLICT:
            return ES3OutpostsError::CONFLICT;
            break;
        case Aws::S3Outposts::S3OutpostsErrors::INTERNAL_SERVER:
            return ES3OutpostsError::INTERNAL_SERVER;
            break;
        default:
            return ES3OutpostsError::UNKNOWN;
            break;
    }
}

#endif

US3OutpostsClientObject *US3OutpostsClientObject::CreateS3OutpostsObject(
const FAWSCredentials &credentials,
const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
    US3OutpostsClientObject *S3OutpostsClient = NewObject<US3OutpostsClientObject>();
    S3OutpostsClient->awsS3OutpostsClient = new Aws::S3Outposts::S3OutpostsClient(credentials.toAWS(),
    Aws::MakeShared<Aws::S3Outposts::S3OutpostsEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return S3OutpostsClient;
#endif
    return nullptr;
}

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

class FCreateEndpointAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3OutpostsCreateEndpointResult &createEndpointResult;
    ES3OutpostsError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Outposts::Model::CreateEndpointOutcomeCallable callable;

public:
    FCreateEndpointAction(
        Aws::S3Outposts::S3OutpostsClient *S3OutpostsClient,
        bool &success,
        FAWSS3OutpostsCreateEndpointRequest createEndpointRequest,
        FAWSS3OutpostsCreateEndpointResult &createEndpointResult,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createEndpointResult(createEndpointResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3OutpostsClient->CreateEndpointCallable(createEndpointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateEndpointOutcome = callable.get();

            success = awsCreateEndpointOutcome.IsSuccess();
                if (success) {
                    createEndpointResult.fromAWS(awsCreateEndpointOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateEndpointOutcome.GetError().GetErrorType());
                errorMessage = ("CreateEndpoint error: " + awsCreateEndpointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateEndpoint Request");
    }

#endif
};

#endif

void
US3OutpostsClientObject::CreateEndpoint(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3OutpostsCreateEndpointRequest createEndpointRequest,
    FAWSS3OutpostsCreateEndpointResult &createEndpointResult,
    ES3OutpostsError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateEndpointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateEndpointAction(this->awsS3OutpostsClient,
                success,
                createEndpointRequest,
                createEndpointResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

class FDeleteEndpointAction : public FPendingLatentAction {
private:
    bool &success;
    ES3OutpostsError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Outposts::Model::DeleteEndpointOutcomeCallable callable;

public:
    FDeleteEndpointAction(
        Aws::S3Outposts::S3OutpostsClient *S3OutpostsClient,
        bool &success,
        FAWSS3OutpostsDeleteEndpointRequest deleteEndpointRequest,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3OutpostsClient->DeleteEndpointCallable(deleteEndpointRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteEndpointOutcome = callable.get();

            success = awsDeleteEndpointOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteEndpointOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteEndpoint error: " + awsDeleteEndpointOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteEndpoint Request");
    }

#endif
};

#endif

void
US3OutpostsClientObject::DeleteEndpoint(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3OutpostsDeleteEndpointRequest deleteEndpointRequest,
    ES3OutpostsError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteEndpointAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteEndpointAction(this->awsS3OutpostsClient,
                success,
                deleteEndpointRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

class FListEndpointsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3OutpostsListEndpointsResult &listEndpointsResult;
    ES3OutpostsError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Outposts::Model::ListEndpointsOutcomeCallable callable;

public:
    FListEndpointsAction(
        Aws::S3Outposts::S3OutpostsClient *S3OutpostsClient,
        bool &success,
        FAWSS3OutpostsListEndpointsRequest listEndpointsRequest,
        FAWSS3OutpostsListEndpointsResult &listEndpointsResult,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listEndpointsResult(listEndpointsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3OutpostsClient->ListEndpointsCallable(listEndpointsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListEndpointsOutcome = callable.get();

            success = awsListEndpointsOutcome.IsSuccess();
                if (success) {
                    listEndpointsResult.fromAWS(awsListEndpointsOutcome.GetResult());
                }

                errorType = fromAWS(awsListEndpointsOutcome.GetError().GetErrorType());
                errorMessage = ("ListEndpoints error: " + awsListEndpointsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListEndpoints Request");
    }

#endif
};

#endif

void
US3OutpostsClientObject::ListEndpoints(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3OutpostsListEndpointsRequest listEndpointsRequest,
    FAWSS3OutpostsListEndpointsResult &listEndpointsResult,
    ES3OutpostsError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListEndpointsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListEndpointsAction(this->awsS3OutpostsClient,
                success,
                listEndpointsRequest,
                listEndpointsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

class FListSharedEndpointsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3OutpostsListSharedEndpointsResult &listSharedEndpointsResult;
    ES3OutpostsError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3Outposts::Model::ListSharedEndpointsOutcomeCallable callable;

public:
    FListSharedEndpointsAction(
        Aws::S3Outposts::S3OutpostsClient *S3OutpostsClient,
        bool &success,
        FAWSS3OutpostsListSharedEndpointsRequest listSharedEndpointsRequest,
        FAWSS3OutpostsListSharedEndpointsResult &listSharedEndpointsResult,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listSharedEndpointsResult(listSharedEndpointsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3OutpostsClient->ListSharedEndpointsCallable(listSharedEndpointsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListSharedEndpointsOutcome = callable.get();

            success = awsListSharedEndpointsOutcome.IsSuccess();
                if (success) {
                    listSharedEndpointsResult.fromAWS(awsListSharedEndpointsOutcome.GetResult());
                }

                errorType = fromAWS(awsListSharedEndpointsOutcome.GetError().GetErrorType());
                errorMessage = ("ListSharedEndpoints error: " + awsListSharedEndpointsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListSharedEndpoints Request");
    }

#endif
};

#endif

void
US3OutpostsClientObject::ListSharedEndpoints(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3OutpostsListSharedEndpointsRequest listSharedEndpointsRequest,
    FAWSS3OutpostsListSharedEndpointsResult &listSharedEndpointsResult,
    ES3OutpostsError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListSharedEndpointsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListSharedEndpointsAction(this->awsS3OutpostsClient,
                success,
                listSharedEndpointsRequest,
                listSharedEndpointsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}