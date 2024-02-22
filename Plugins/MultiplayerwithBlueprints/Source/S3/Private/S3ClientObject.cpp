/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "S3ClientObject.h"
#include "S3Globals.h"
#include "S3PrivatePCH.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_S3CLIENTSDK

ES3Error fromAWS(Aws::S3::S3Errors awsErrorType) {
    switch (awsErrorType) {
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
        case Aws::S3::S3Errors::INVALID_OBJECT_STATE:
            return ES3Error::INVALID_OBJECT_STATE;
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

US3ClientObject *US3ClientObject::CreateS3Object(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    US3ClientObject *S3Client = NewObject<US3ClientObject>();
    S3Client->awsS3Client = new Aws::S3::S3Client(credentials.toAWS(),
    Aws::MakeShared<Aws::S3::S3EndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return S3Client;
#endif
    return nullptr;
}

bool US3ClientObject::MultipartUploadSupported() const {
#if WITH_S3CLIENTSDK && WITH_CORE
    return this->awsS3Client->MultipartUploadSupported();
#endif
    return false;
}

FString US3ClientObject::GeneratePresignedUrl(
        const FString& bucket,
        const FString& key,
        EHttpMethod method,
        const TMap<FString, FString>& customizedHeaders,
        int64 expirationInSeconds
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    Aws::String awsBucket = TCHAR_TO_UTF8(*bucket);

    Aws::String awsKey = TCHAR_TO_UTF8(*key);

    Aws::Http::HttpMethod awsMethod = Aws::Http::HttpMethod::HTTP_GET;

    switch(method) {
        case EHttpMethod::HTTP_GET:
            awsMethod = Aws::Http::HttpMethod::HTTP_GET;
            break;
        case EHttpMethod::HTTP_POST:
            awsMethod = Aws::Http::HttpMethod::HTTP_POST;
            break;
        case EHttpMethod::HTTP_DELETE:
            awsMethod = Aws::Http::HttpMethod::HTTP_DELETE;
            break;
        case EHttpMethod::HTTP_PUT:
            awsMethod = Aws::Http::HttpMethod::HTTP_PUT;
            break;
        case EHttpMethod::HTTP_HEAD:
            awsMethod = Aws::Http::HttpMethod::HTTP_HEAD;
            break;
        case EHttpMethod::HTTP_PATCH:
            awsMethod = Aws::Http::HttpMethod::HTTP_PATCH;
            break;
    }

    Aws::Http::HeaderValueCollection awsCustomizedHeaders;

    for (const TPair<FString, FString>& elem : customizedHeaders) {
        awsCustomizedHeaders.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
    }

    long long awsExpirationInSeconds = expirationInSeconds;

    return UTF8_TO_TCHAR(this->awsS3Client->GeneratePresignedUrl(
            awsBucket,
            awsKey,
            awsMethod,
            awsCustomizedHeaders,
            awsExpirationInSeconds
            ).c_str());
#endif
    return FString();
}

FString US3ClientObject::GeneratePresignedUrlWithSSES3(
        const FString& bucket,
        const FString& key,
        EHttpMethod method,
        const TMap<FString, FString>& customizedHeaders,
        int64 expirationInSeconds
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    Aws::String awsBucket = TCHAR_TO_UTF8(*bucket);

    Aws::String awsKey = TCHAR_TO_UTF8(*key);

    Aws::Http::HttpMethod awsMethod = Aws::Http::HttpMethod::HTTP_GET;

    switch(method) {
        case EHttpMethod::HTTP_GET:
            awsMethod = Aws::Http::HttpMethod::HTTP_GET;
            break;
        case EHttpMethod::HTTP_POST:
            awsMethod = Aws::Http::HttpMethod::HTTP_POST;
            break;
        case EHttpMethod::HTTP_DELETE:
            awsMethod = Aws::Http::HttpMethod::HTTP_DELETE;
            break;
        case EHttpMethod::HTTP_PUT:
            awsMethod = Aws::Http::HttpMethod::HTTP_PUT;
            break;
        case EHttpMethod::HTTP_HEAD:
            awsMethod = Aws::Http::HttpMethod::HTTP_HEAD;
            break;
        case EHttpMethod::HTTP_PATCH:
            awsMethod = Aws::Http::HttpMethod::HTTP_PATCH;
            break;
    }

    Aws::Http::HeaderValueCollection awsCustomizedHeaders;

    for (const TPair<FString, FString>& elem : customizedHeaders) {
        awsCustomizedHeaders.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
    }

    long long awsExpirationInSeconds = expirationInSeconds;

    return UTF8_TO_TCHAR(this->awsS3Client->GeneratePresignedUrlWithSSES3(
            awsBucket,
            awsKey,
            awsMethod,
            awsCustomizedHeaders,
            awsExpirationInSeconds
            ).c_str());
#endif
    return FString();
}

FString US3ClientObject::GeneratePresignedUrlWithSSEKMS(
        const FString& bucket,
        const FString& key,
        EHttpMethod method,
        const TMap<FString, FString>& customizedHeaders,
        const FString& kmsMasterKeyId,
        int64 expirationInSeconds
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    Aws::String awsBucket = TCHAR_TO_UTF8(*bucket);

    Aws::String awsKey = TCHAR_TO_UTF8(*key);

    Aws::Http::HttpMethod awsMethod = Aws::Http::HttpMethod::HTTP_GET;

    switch(method) {
        case EHttpMethod::HTTP_GET:
            awsMethod = Aws::Http::HttpMethod::HTTP_GET;
            break;
        case EHttpMethod::HTTP_POST:
            awsMethod = Aws::Http::HttpMethod::HTTP_POST;
            break;
        case EHttpMethod::HTTP_DELETE:
            awsMethod = Aws::Http::HttpMethod::HTTP_DELETE;
            break;
        case EHttpMethod::HTTP_PUT:
            awsMethod = Aws::Http::HttpMethod::HTTP_PUT;
            break;
        case EHttpMethod::HTTP_HEAD:
            awsMethod = Aws::Http::HttpMethod::HTTP_HEAD;
            break;
        case EHttpMethod::HTTP_PATCH:
            awsMethod = Aws::Http::HttpMethod::HTTP_PATCH;
            break;
    }

    Aws::Http::HeaderValueCollection awsCustomizedHeaders;
    for (const TPair<FString, FString>& elem : customizedHeaders) {
        awsCustomizedHeaders.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
    }

    Aws::String awsKmsMasterKeyId = TCHAR_TO_UTF8(*kmsMasterKeyId);

    long long awsExpirationInSeconds = expirationInSeconds;

    return UTF8_TO_TCHAR(this->awsS3Client->GeneratePresignedUrlWithSSEKMS(
            awsBucket,
            awsKey,
            awsMethod,
            awsCustomizedHeaders,
            awsKmsMasterKeyId,
            awsExpirationInSeconds
            ).c_str());
#endif
    return FString();
}

FString US3ClientObject::GeneratePresignedUrlWithSSEC(
        const FString& bucket,
        const FString& key,
        EHttpMethod method,
        const TMap<FString, FString>& customizedHeaders,
        const FString& base64EncodedAES256Key,
        int64 expirationInSeconds
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    Aws::String awsBucket = TCHAR_TO_UTF8(*bucket);

    Aws::String awsKey = TCHAR_TO_UTF8(*key);

    Aws::Http::HttpMethod awsMethod = Aws::Http::HttpMethod::HTTP_GET;

    switch(method) {
        case EHttpMethod::HTTP_GET:
            awsMethod = Aws::Http::HttpMethod::HTTP_GET;
            break;
        case EHttpMethod::HTTP_POST:
            awsMethod = Aws::Http::HttpMethod::HTTP_POST;
            break;
        case EHttpMethod::HTTP_DELETE:
            awsMethod = Aws::Http::HttpMethod::HTTP_DELETE;
            break;
        case EHttpMethod::HTTP_PUT:
            awsMethod = Aws::Http::HttpMethod::HTTP_PUT;
            break;
        case EHttpMethod::HTTP_HEAD:
            awsMethod = Aws::Http::HttpMethod::HTTP_HEAD;
            break;
        case EHttpMethod::HTTP_PATCH:
            awsMethod = Aws::Http::HttpMethod::HTTP_PATCH;
            break;
    }

    Aws::Http::HeaderValueCollection awsCustomizedHeaders;

    for (const TPair<FString, FString>& elem : customizedHeaders) {
        awsCustomizedHeaders.emplace(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
    }

    Aws::String awsBase64EncodedAES256Key = TCHAR_TO_UTF8(*base64EncodedAES256Key);

    long long awsExpirationInSeconds = expirationInSeconds;

    return UTF8_TO_TCHAR(this->awsS3Client->GeneratePresignedUrlWithSSEC(
            awsBucket,
            awsKey,
            awsMethod,
            awsCustomizedHeaders,
            awsBase64EncodedAES256Key,
            awsExpirationInSeconds
            ).c_str());
#endif
    return FString();
}

#if WITH_S3CLIENTSDK && WITH_CORE

class FAbortMultipartUploadAction : public FPendingLatentAction {
private:
    bool &success;
    FAbortMultipartUploadResult &abortMultipartUploadResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::AbortMultipartUploadOutcomeCallable callable;

public:
    FAbortMultipartUploadAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAbortMultipartUploadRequest abortMultipartUploadRequest,
        FAbortMultipartUploadResult &abortMultipartUploadResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), abortMultipartUploadResult(abortMultipartUploadResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->AbortMultipartUploadCallable(abortMultipartUploadRequest.toAWS());
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
US3ClientObject::AbortMultipartUpload(
        UObject *WorldContextObject,
        bool &success,
        FAbortMultipartUploadRequest abortMultipartUploadRequest,
        FAbortMultipartUploadResult &abortMultipartUploadResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAbortMultipartUploadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAbortMultipartUploadAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FCompleteMultipartUploadAction : public FPendingLatentAction {
private:
    bool &success;
    FCompleteMultipartUploadResult &completeMultipartUploadResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::CompleteMultipartUploadOutcomeCallable callable;

public:
    FCompleteMultipartUploadAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FCompleteMultipartUploadRequest completeMultipartUploadRequest,
        FCompleteMultipartUploadResult &completeMultipartUploadResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), completeMultipartUploadResult(completeMultipartUploadResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->CompleteMultipartUploadCallable(completeMultipartUploadRequest.toAWS());
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
US3ClientObject::CompleteMultipartUpload(
        UObject *WorldContextObject,
        bool &success,
        FCompleteMultipartUploadRequest completeMultipartUploadRequest,
        FCompleteMultipartUploadResult &completeMultipartUploadResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCompleteMultipartUploadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCompleteMultipartUploadAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FCopyObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FCopyObjectResult &copyObjectResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::CopyObjectOutcomeCallable callable;

public:
    FCopyObjectAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FCopyObjectRequest copyObjectRequest,
        FCopyObjectResult &copyObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), copyObjectResult(copyObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->CopyObjectCallable(copyObjectRequest.toAWS());
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
US3ClientObject::CopyObject(
        UObject *WorldContextObject,
        bool &success,
        FCopyObjectRequest copyObjectRequest,
        FCopyObjectResult &copyObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCopyObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCopyObjectAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FCreateBucketAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateBucketResult &createBucketResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::CreateBucketOutcomeCallable callable;

public:
    FCreateBucketAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FCreateBucketRequest createBucketRequest,
        FCreateBucketResult &createBucketResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createBucketResult(createBucketResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->CreateBucketCallable(createBucketRequest.toAWS());
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
US3ClientObject::CreateBucket(
        UObject *WorldContextObject,
        bool &success,
        FCreateBucketRequest createBucketRequest,
        FCreateBucketResult &createBucketResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateBucketAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FCreateMultipartUploadAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateMultipartUploadResult &createMultipartUploadResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::CreateMultipartUploadOutcomeCallable callable;

public:
    FCreateMultipartUploadAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FCreateMultipartUploadRequest createMultipartUploadRequest,
        FCreateMultipartUploadResult &createMultipartUploadResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createMultipartUploadResult(createMultipartUploadResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->CreateMultipartUploadCallable(createMultipartUploadRequest.toAWS());
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
US3ClientObject::CreateMultipartUpload(
        UObject *WorldContextObject,
        bool &success,
        FCreateMultipartUploadRequest createMultipartUploadRequest,
        FCreateMultipartUploadResult &createMultipartUploadResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateMultipartUploadAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateMultipartUploadAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketOutcomeCallable callable;

public:
    FDeleteBucketAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketRequest deleteBucketRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketCallable(deleteBucketRequest.toAWS());
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
US3ClientObject::DeleteBucket(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketRequest deleteBucketRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketAnalyticsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketAnalyticsConfigurationOutcomeCallable callable;

public:
    FDeleteBucketAnalyticsConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketAnalyticsConfigurationRequest deleteBucketAnalyticsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketAnalyticsConfigurationCallable(deleteBucketAnalyticsConfigurationRequest.toAWS());
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
US3ClientObject::DeleteBucketAnalyticsConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketAnalyticsConfigurationRequest deleteBucketAnalyticsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketAnalyticsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketAnalyticsConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketCorsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketCorsOutcomeCallable callable;

public:
    FDeleteBucketCorsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketCorsRequest deleteBucketCorsRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketCorsCallable(deleteBucketCorsRequest.toAWS());
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
US3ClientObject::DeleteBucketCors(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketCorsRequest deleteBucketCorsRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketCorsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketCorsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketEncryptionAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketEncryptionOutcomeCallable callable;

public:
    FDeleteBucketEncryptionAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketEncryptionRequest deleteBucketEncryptionRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketEncryptionCallable(deleteBucketEncryptionRequest.toAWS());
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
US3ClientObject::DeleteBucketEncryption(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketEncryptionRequest deleteBucketEncryptionRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketEncryptionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketEncryptionAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketIntelligentTieringConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketIntelligentTieringConfigurationOutcomeCallable callable;

public:
    FDeleteBucketIntelligentTieringConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3DeleteBucketIntelligentTieringConfigurationRequest deleteBucketIntelligentTieringConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketIntelligentTieringConfigurationCallable(deleteBucketIntelligentTieringConfigurationRequest.toAWS());
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
US3ClientObject::DeleteBucketIntelligentTieringConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3DeleteBucketIntelligentTieringConfigurationRequest deleteBucketIntelligentTieringConfigurationRequest,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketIntelligentTieringConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketIntelligentTieringConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketInventoryConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketInventoryConfigurationOutcomeCallable callable;

public:
    FDeleteBucketInventoryConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketInventoryConfigurationRequest deleteBucketInventoryConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketInventoryConfigurationCallable(deleteBucketInventoryConfigurationRequest.toAWS());
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
US3ClientObject::DeleteBucketInventoryConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketInventoryConfigurationRequest deleteBucketInventoryConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketInventoryConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketInventoryConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketLifecycleAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketLifecycleOutcomeCallable callable;

public:
    FDeleteBucketLifecycleAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketLifecycleRequest deleteBucketLifecycleRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketLifecycleCallable(deleteBucketLifecycleRequest.toAWS());
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
US3ClientObject::DeleteBucketLifecycle(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketLifecycleRequest deleteBucketLifecycleRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketLifecycleAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketLifecycleAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketMetricsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketMetricsConfigurationOutcomeCallable callable;

public:
    FDeleteBucketMetricsConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketMetricsConfigurationRequest deleteBucketMetricsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketMetricsConfigurationCallable(deleteBucketMetricsConfigurationRequest.toAWS());
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
US3ClientObject::DeleteBucketMetricsConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketMetricsConfigurationRequest deleteBucketMetricsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketMetricsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketMetricsConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketOwnershipControlsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketOwnershipControlsOutcomeCallable callable;

public:
    FDeleteBucketOwnershipControlsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3DeleteBucketOwnershipControlsRequest deleteBucketOwnershipControlsRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketOwnershipControlsCallable(deleteBucketOwnershipControlsRequest.toAWS());
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
US3ClientObject::DeleteBucketOwnershipControls(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3DeleteBucketOwnershipControlsRequest deleteBucketOwnershipControlsRequest,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketOwnershipControlsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketOwnershipControlsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketPolicyOutcomeCallable callable;

public:
    FDeleteBucketPolicyAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketPolicyRequest deleteBucketPolicyRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketPolicyCallable(deleteBucketPolicyRequest.toAWS());
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
US3ClientObject::DeleteBucketPolicy(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketPolicyRequest deleteBucketPolicyRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketPolicyAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketReplicationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketReplicationOutcomeCallable callable;

public:
    FDeleteBucketReplicationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketReplicationRequest deleteBucketReplicationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketReplicationCallable(deleteBucketReplicationRequest.toAWS());
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
US3ClientObject::DeleteBucketReplication(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketReplicationRequest deleteBucketReplicationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketReplicationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketReplicationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketTaggingOutcomeCallable callable;

public:
    FDeleteBucketTaggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketTaggingRequest deleteBucketTaggingRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketTaggingCallable(deleteBucketTaggingRequest.toAWS());
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
US3ClientObject::DeleteBucketTagging(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketTaggingRequest deleteBucketTaggingRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketTaggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteBucketWebsiteAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteBucketWebsiteOutcomeCallable callable;

public:
    FDeleteBucketWebsiteAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteBucketWebsiteRequest deleteBucketWebsiteRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteBucketWebsiteCallable(deleteBucketWebsiteRequest.toAWS());
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
US3ClientObject::DeleteBucketWebsite(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBucketWebsiteRequest deleteBucketWebsiteRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBucketWebsiteAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBucketWebsiteAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteObjectResult &deleteObjectResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteObjectOutcomeCallable callable;

public:
    FDeleteObjectAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteObjectRequest deleteObjectRequest,
        FDeleteObjectResult &deleteObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteObjectResult(deleteObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteObjectCallable(deleteObjectRequest.toAWS());
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
US3ClientObject::DeleteObject(
        UObject *WorldContextObject,
        bool &success,
        FDeleteObjectRequest deleteObjectRequest,
        FDeleteObjectResult &deleteObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteObjectAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteObjectTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteObjectTaggingResult &deleteObjectTaggingResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteObjectTaggingOutcomeCallable callable;

public:
    FDeleteObjectTaggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteObjectTaggingRequest deleteObjectTaggingRequest,
        FDeleteObjectTaggingResult &deleteObjectTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteObjectTaggingResult(deleteObjectTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteObjectTaggingCallable(deleteObjectTaggingRequest.toAWS());
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
US3ClientObject::DeleteObjectTagging(
        UObject *WorldContextObject,
        bool &success,
        FDeleteObjectTaggingRequest deleteObjectTaggingRequest,
        FDeleteObjectTaggingResult &deleteObjectTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteObjectTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteObjectTaggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeleteObjectsAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteObjectsResult &deleteObjectsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeleteObjectsOutcomeCallable callable;

public:
    FDeleteObjectsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FDeleteObjectsRequest deleteObjectsRequest,
        FDeleteObjectsResult &deleteObjectsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteObjectsResult(deleteObjectsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeleteObjectsCallable(deleteObjectsRequest.toAWS());
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
US3ClientObject::DeleteObjects(
        UObject *WorldContextObject,
        bool &success,
        FDeleteObjectsRequest deleteObjectsRequest,
        FDeleteObjectsResult &deleteObjectsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteObjectsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteObjectsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FDeletePublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::DeletePublicAccessBlockOutcomeCallable callable;

public:
    FDeletePublicAccessBlockAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FS3DeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->DeletePublicAccessBlockCallable(deletePublicAccessBlockRequest.toAWS());
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
US3ClientObject::DeletePublicAccessBlock(
        UObject *WorldContextObject,
        bool &success,
        FS3DeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeletePublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeletePublicAccessBlockAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketAccelerateConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketAccelerateConfigurationResult &getBucketAccelerateConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketAccelerateConfigurationOutcomeCallable callable;

public:
    FGetBucketAccelerateConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketAccelerateConfigurationRequest getBucketAccelerateConfigurationRequest,
        FGetBucketAccelerateConfigurationResult &getBucketAccelerateConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketAccelerateConfigurationResult(getBucketAccelerateConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketAccelerateConfigurationCallable(getBucketAccelerateConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketAccelerateConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketAccelerateConfigurationRequest getBucketAccelerateConfigurationRequest,
        FGetBucketAccelerateConfigurationResult &getBucketAccelerateConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAccelerateConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAccelerateConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketAclAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketAclResult &getBucketAclResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketAclOutcomeCallable callable;

public:
    FGetBucketAclAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketAclRequest getBucketAclRequest,
        FGetBucketAclResult &getBucketAclResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketAclResult(getBucketAclResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketAclCallable(getBucketAclRequest.toAWS());
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
US3ClientObject::GetBucketAcl(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketAclRequest getBucketAclRequest,
        FGetBucketAclResult &getBucketAclResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAclAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketAnalyticsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketAnalyticsConfigurationResult &getBucketAnalyticsConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketAnalyticsConfigurationOutcomeCallable callable;

public:
    FGetBucketAnalyticsConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketAnalyticsConfigurationRequest getBucketAnalyticsConfigurationRequest,
        FGetBucketAnalyticsConfigurationResult &getBucketAnalyticsConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketAnalyticsConfigurationResult(getBucketAnalyticsConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketAnalyticsConfigurationCallable(getBucketAnalyticsConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketAnalyticsConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketAnalyticsConfigurationRequest getBucketAnalyticsConfigurationRequest,
        FGetBucketAnalyticsConfigurationResult &getBucketAnalyticsConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketAnalyticsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketAnalyticsConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketCorsAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketCorsResult &getBucketCorsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketCorsOutcomeCallable callable;

public:
    FGetBucketCorsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketCorsRequest getBucketCorsRequest,
        FGetBucketCorsResult &getBucketCorsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketCorsResult(getBucketCorsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketCorsCallable(getBucketCorsRequest.toAWS());
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
US3ClientObject::GetBucketCors(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketCorsRequest getBucketCorsRequest,
        FGetBucketCorsResult &getBucketCorsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketCorsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketCorsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketEncryptionAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketEncryptionResult &getBucketEncryptionResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketEncryptionOutcomeCallable callable;

public:
    FGetBucketEncryptionAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketEncryptionRequest getBucketEncryptionRequest,
        FGetBucketEncryptionResult &getBucketEncryptionResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketEncryptionResult(getBucketEncryptionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketEncryptionCallable(getBucketEncryptionRequest.toAWS());
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
US3ClientObject::GetBucketEncryption(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketEncryptionRequest getBucketEncryptionRequest,
        FGetBucketEncryptionResult &getBucketEncryptionResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketEncryptionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketEncryptionAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketIntelligentTieringConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3GetBucketIntelligentTieringConfigurationResult &getBucketIntelligentTieringConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketIntelligentTieringConfigurationOutcomeCallable callable;

public:
    FGetBucketIntelligentTieringConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3GetBucketIntelligentTieringConfigurationRequest getBucketIntelligentTieringConfigurationRequest,
        FAWSS3GetBucketIntelligentTieringConfigurationResult &getBucketIntelligentTieringConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketIntelligentTieringConfigurationResult(getBucketIntelligentTieringConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketIntelligentTieringConfigurationCallable(getBucketIntelligentTieringConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketIntelligentTieringConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3GetBucketIntelligentTieringConfigurationRequest getBucketIntelligentTieringConfigurationRequest,
    FAWSS3GetBucketIntelligentTieringConfigurationResult &getBucketIntelligentTieringConfigurationResult,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketIntelligentTieringConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketIntelligentTieringConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketInventoryConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketInventoryConfigurationResult &getBucketInventoryConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketInventoryConfigurationOutcomeCallable callable;

public:
    FGetBucketInventoryConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketInventoryConfigurationRequest getBucketInventoryConfigurationRequest,
        FGetBucketInventoryConfigurationResult &getBucketInventoryConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketInventoryConfigurationResult(getBucketInventoryConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketInventoryConfigurationCallable(getBucketInventoryConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketInventoryConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketInventoryConfigurationRequest getBucketInventoryConfigurationRequest,
        FGetBucketInventoryConfigurationResult &getBucketInventoryConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketInventoryConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketInventoryConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketLifecycleConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FGetBucketLifecycleConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
        FGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLifecycleConfigurationResult(getBucketLifecycleConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketLifecycleConfigurationCallable(getBucketLifecycleConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketLifecycleConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
        FGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLifecycleConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketLocationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketLocationResult &getBucketLocationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketLocationOutcomeCallable callable;

public:
    FGetBucketLocationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketLocationRequest getBucketLocationRequest,
        FGetBucketLocationResult &getBucketLocationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLocationResult(getBucketLocationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketLocationCallable(getBucketLocationRequest.toAWS());
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
US3ClientObject::GetBucketLocation(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketLocationRequest getBucketLocationRequest,
        FGetBucketLocationResult &getBucketLocationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLocationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLocationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketLoggingAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketLoggingResult &getBucketLoggingResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketLoggingOutcomeCallable callable;

public:
    FGetBucketLoggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketLoggingRequest getBucketLoggingRequest,
        FGetBucketLoggingResult &getBucketLoggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketLoggingResult(getBucketLoggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketLoggingCallable(getBucketLoggingRequest.toAWS());
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
US3ClientObject::GetBucketLogging(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketLoggingRequest getBucketLoggingRequest,
        FGetBucketLoggingResult &getBucketLoggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketLoggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketLoggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketMetricsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketMetricsConfigurationResult &getBucketMetricsConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketMetricsConfigurationOutcomeCallable callable;

public:
    FGetBucketMetricsConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketMetricsConfigurationRequest getBucketMetricsConfigurationRequest,
        FGetBucketMetricsConfigurationResult &getBucketMetricsConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketMetricsConfigurationResult(getBucketMetricsConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketMetricsConfigurationCallable(getBucketMetricsConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketMetricsConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketMetricsConfigurationRequest getBucketMetricsConfigurationRequest,
        FGetBucketMetricsConfigurationResult &getBucketMetricsConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketMetricsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketMetricsConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketNotificationConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketNotificationConfigurationResult &getBucketNotificationConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketNotificationConfigurationOutcomeCallable callable;

public:
    FGetBucketNotificationConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketNotificationConfigurationRequest getBucketNotificationConfigurationRequest,
        FGetBucketNotificationConfigurationResult &getBucketNotificationConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketNotificationConfigurationResult(getBucketNotificationConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketNotificationConfigurationCallable(getBucketNotificationConfigurationRequest.toAWS());
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
US3ClientObject::GetBucketNotificationConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketNotificationConfigurationRequest getBucketNotificationConfigurationRequest,
        FGetBucketNotificationConfigurationResult &getBucketNotificationConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketNotificationConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketNotificationConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketOwnershipControlsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3GetBucketOwnershipControlsResult &getBucketOwnershipControlsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketOwnershipControlsOutcomeCallable callable;

public:
    FGetBucketOwnershipControlsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3GetBucketOwnershipControlsRequest getBucketOwnershipControlsRequest,
        FAWSS3GetBucketOwnershipControlsResult &getBucketOwnershipControlsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketOwnershipControlsResult(getBucketOwnershipControlsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketOwnershipControlsCallable(getBucketOwnershipControlsRequest.toAWS());
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
US3ClientObject::GetBucketOwnershipControls(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3GetBucketOwnershipControlsRequest getBucketOwnershipControlsRequest,
    FAWSS3GetBucketOwnershipControlsResult &getBucketOwnershipControlsResult,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketOwnershipControlsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketOwnershipControlsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketPolicyResult &getBucketPolicyResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketPolicyOutcomeCallable callable;

public:
    FGetBucketPolicyAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketPolicyRequest getBucketPolicyRequest,
        FGetBucketPolicyResult &getBucketPolicyResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketPolicyResult(getBucketPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketPolicyCallable(getBucketPolicyRequest.toAWS());
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
US3ClientObject::GetBucketPolicy(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketPolicyRequest getBucketPolicyRequest,
        FGetBucketPolicyResult &getBucketPolicyResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketPolicyAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketPolicyStatusAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketPolicyStatusResult &getBucketPolicyStatusResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketPolicyStatusOutcomeCallable callable;

public:
    FGetBucketPolicyStatusAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketPolicyStatusRequest getBucketPolicyStatusRequest,
        FGetBucketPolicyStatusResult &getBucketPolicyStatusResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketPolicyStatusResult(getBucketPolicyStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketPolicyStatusCallable(getBucketPolicyStatusRequest.toAWS());
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
US3ClientObject::GetBucketPolicyStatus(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketPolicyStatusRequest getBucketPolicyStatusRequest,
        FGetBucketPolicyStatusResult &getBucketPolicyStatusResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketPolicyStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketPolicyStatusAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketReplicationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketReplicationResult &getBucketReplicationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketReplicationOutcomeCallable callable;

public:
    FGetBucketReplicationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketReplicationRequest getBucketReplicationRequest,
        FGetBucketReplicationResult &getBucketReplicationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketReplicationResult(getBucketReplicationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketReplicationCallable(getBucketReplicationRequest.toAWS());
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
US3ClientObject::GetBucketReplication(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketReplicationRequest getBucketReplicationRequest,
        FGetBucketReplicationResult &getBucketReplicationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketReplicationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketReplicationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketRequestPaymentAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketRequestPaymentResult &getBucketRequestPaymentResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketRequestPaymentOutcomeCallable callable;

public:
    FGetBucketRequestPaymentAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketRequestPaymentRequest getBucketRequestPaymentRequest,
        FGetBucketRequestPaymentResult &getBucketRequestPaymentResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketRequestPaymentResult(getBucketRequestPaymentResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketRequestPaymentCallable(getBucketRequestPaymentRequest.toAWS());
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
US3ClientObject::GetBucketRequestPayment(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketRequestPaymentRequest getBucketRequestPaymentRequest,
        FGetBucketRequestPaymentResult &getBucketRequestPaymentResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketRequestPaymentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketRequestPaymentAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketTaggingResult &getBucketTaggingResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketTaggingOutcomeCallable callable;

public:
    FGetBucketTaggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketTaggingRequest getBucketTaggingRequest,
        FGetBucketTaggingResult &getBucketTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketTaggingResult(getBucketTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketTaggingCallable(getBucketTaggingRequest.toAWS());
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
US3ClientObject::GetBucketTagging(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketTaggingRequest getBucketTaggingRequest,
        FGetBucketTaggingResult &getBucketTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketTaggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketVersioningAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketVersioningResult &getBucketVersioningResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketVersioningOutcomeCallable callable;

public:
    FGetBucketVersioningAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketVersioningRequest getBucketVersioningRequest,
        FGetBucketVersioningResult &getBucketVersioningResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketVersioningResult(getBucketVersioningResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketVersioningCallable(getBucketVersioningRequest.toAWS());
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
US3ClientObject::GetBucketVersioning(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketVersioningRequest getBucketVersioningRequest,
        FGetBucketVersioningResult &getBucketVersioningResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketVersioningAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketVersioningAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetBucketWebsiteAction : public FPendingLatentAction {
private:
    bool &success;
    FGetBucketWebsiteResult &getBucketWebsiteResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetBucketWebsiteOutcomeCallable callable;

public:
    FGetBucketWebsiteAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetBucketWebsiteRequest getBucketWebsiteRequest,
        FGetBucketWebsiteResult &getBucketWebsiteResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getBucketWebsiteResult(getBucketWebsiteResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetBucketWebsiteCallable(getBucketWebsiteRequest.toAWS());
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
US3ClientObject::GetBucketWebsite(
        UObject *WorldContextObject,
        bool &success,
        FGetBucketWebsiteRequest getBucketWebsiteRequest,
        FGetBucketWebsiteResult &getBucketWebsiteResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetBucketWebsiteAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetBucketWebsiteAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectResult &getObjectResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectOutcomeCallable callable;

public:
    FGetObjectAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectRequest getObjectRequest,
        FGetObjectResult &getObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectResult(getObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectCallable(getObjectRequest.toAWS());
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
US3ClientObject::GetObject(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectRequest getObjectRequest,
        FGetObjectResult &getObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectAclAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectAclResult &getObjectAclResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectAclOutcomeCallable callable;

public:
    FGetObjectAclAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectAclRequest getObjectAclRequest,
        FGetObjectAclResult &getObjectAclResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectAclResult(getObjectAclResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectAclCallable(getObjectAclRequest.toAWS());
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
US3ClientObject::GetObjectAcl(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectAclRequest getObjectAclRequest,
        FGetObjectAclResult &getObjectAclResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectAclAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3GetObjectAttributesResult &getObjectAttributesResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectAttributesOutcomeCallable callable;

public:
    FGetObjectAttributesAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3GetObjectAttributesRequest getObjectAttributesRequest,
        FAWSS3GetObjectAttributesResult &getObjectAttributesResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectAttributesResult(getObjectAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectAttributesCallable(getObjectAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetObjectAttributesOutcome = callable.get();

            success = awsGetObjectAttributesOutcome.IsSuccess();
                if (success) {
                    getObjectAttributesResult.fromAWS(awsGetObjectAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsGetObjectAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("GetObjectAttributes error: " + awsGetObjectAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetObjectAttributes Request");
    }

#endif
};

#endif

void
US3ClientObject::GetObjectAttributes(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3GetObjectAttributesRequest getObjectAttributesRequest,
    FAWSS3GetObjectAttributesResult &getObjectAttributesResult,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectAttributesAction(this->awsS3Client,
                success,
                getObjectAttributesRequest,
                getObjectAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectLegalHoldAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectLegalHoldResult &getObjectLegalHoldResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectLegalHoldOutcomeCallable callable;

public:
    FGetObjectLegalHoldAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectLegalHoldRequest getObjectLegalHoldRequest,
        FGetObjectLegalHoldResult &getObjectLegalHoldResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectLegalHoldResult(getObjectLegalHoldResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectLegalHoldCallable(getObjectLegalHoldRequest.toAWS());
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
US3ClientObject::GetObjectLegalHold(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectLegalHoldRequest getObjectLegalHoldRequest,
        FGetObjectLegalHoldResult &getObjectLegalHoldResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectLegalHoldAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectLegalHoldAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectLockConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectLockConfigurationResult &getObjectLockConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectLockConfigurationOutcomeCallable callable;

public:
    FGetObjectLockConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectLockConfigurationRequest getObjectLockConfigurationRequest,
        FGetObjectLockConfigurationResult &getObjectLockConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectLockConfigurationResult(getObjectLockConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectLockConfigurationCallable(getObjectLockConfigurationRequest.toAWS());
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
US3ClientObject::GetObjectLockConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectLockConfigurationRequest getObjectLockConfigurationRequest,
        FGetObjectLockConfigurationResult &getObjectLockConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectLockConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectLockConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectRetentionAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectRetentionResult &getObjectRetentionResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectRetentionOutcomeCallable callable;

public:
    FGetObjectRetentionAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectRetentionRequest getObjectRetentionRequest,
        FGetObjectRetentionResult &getObjectRetentionResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectRetentionResult(getObjectRetentionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectRetentionCallable(getObjectRetentionRequest.toAWS());
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
US3ClientObject::GetObjectRetention(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectRetentionRequest getObjectRetentionRequest,
        FGetObjectRetentionResult &getObjectRetentionResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectRetentionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectRetentionAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectTaggingResult &getObjectTaggingResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectTaggingOutcomeCallable callable;

public:
    FGetObjectTaggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectTaggingRequest getObjectTaggingRequest,
        FGetObjectTaggingResult &getObjectTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectTaggingResult(getObjectTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectTaggingCallable(getObjectTaggingRequest.toAWS());
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
US3ClientObject::GetObjectTagging(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectTaggingRequest getObjectTaggingRequest,
        FGetObjectTaggingResult &getObjectTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectTaggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetObjectTorrentAction : public FPendingLatentAction {
private:
    bool &success;
    FGetObjectTorrentResult &getObjectTorrentResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetObjectTorrentOutcomeCallable callable;

public:
    FGetObjectTorrentAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FGetObjectTorrentRequest getObjectTorrentRequest,
        FGetObjectTorrentResult &getObjectTorrentResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getObjectTorrentResult(getObjectTorrentResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetObjectTorrentCallable(getObjectTorrentRequest.toAWS());
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
US3ClientObject::GetObjectTorrent(
        UObject *WorldContextObject,
        bool &success,
        FGetObjectTorrentRequest getObjectTorrentRequest,
        FGetObjectTorrentResult &getObjectTorrentResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetObjectTorrentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetObjectTorrentAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FGetPublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    FS3GetPublicAccessBlockResult &getPublicAccessBlockResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::GetPublicAccessBlockOutcomeCallable callable;

public:
    FGetPublicAccessBlockAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FS3GetPublicAccessBlockRequest getPublicAccessBlockRequest,
        FS3GetPublicAccessBlockResult &getPublicAccessBlockResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getPublicAccessBlockResult(getPublicAccessBlockResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->GetPublicAccessBlockCallable(getPublicAccessBlockRequest.toAWS());
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
US3ClientObject::GetPublicAccessBlock(
        UObject *WorldContextObject,
        bool &success,
        FS3GetPublicAccessBlockRequest getPublicAccessBlockRequest,
        FS3GetPublicAccessBlockResult &getPublicAccessBlockResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPublicAccessBlockAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FHeadBucketAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::HeadBucketOutcomeCallable callable;

public:
    FHeadBucketAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FHeadBucketRequest headBucketRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->HeadBucketCallable(headBucketRequest.toAWS());
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
US3ClientObject::HeadBucket(
        UObject *WorldContextObject,
        bool &success,
        FHeadBucketRequest headBucketRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FHeadBucketAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FHeadBucketAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FHeadObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FHeadObjectResult &headObjectResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::HeadObjectOutcomeCallable callable;

public:
    FHeadObjectAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FHeadObjectRequest headObjectRequest,
        FHeadObjectResult &headObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), headObjectResult(headObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->HeadObjectCallable(headObjectRequest.toAWS());
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
US3ClientObject::HeadObject(
        UObject *WorldContextObject,
        bool &success,
        FHeadObjectRequest headObjectRequest,
        FHeadObjectResult &headObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FHeadObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FHeadObjectAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListBucketAnalyticsConfigurationsAction : public FPendingLatentAction {
private:
    bool &success;
    FListBucketAnalyticsConfigurationsResult &listBucketAnalyticsConfigurationsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListBucketAnalyticsConfigurationsOutcomeCallable callable;

public:
    FListBucketAnalyticsConfigurationsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListBucketAnalyticsConfigurationsRequest listBucketAnalyticsConfigurationsRequest,
        FListBucketAnalyticsConfigurationsResult &listBucketAnalyticsConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketAnalyticsConfigurationsResult(listBucketAnalyticsConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListBucketAnalyticsConfigurationsCallable(listBucketAnalyticsConfigurationsRequest.toAWS());
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
US3ClientObject::ListBucketAnalyticsConfigurations(
        UObject *WorldContextObject,
        bool &success,
        FListBucketAnalyticsConfigurationsRequest listBucketAnalyticsConfigurationsRequest,
        FListBucketAnalyticsConfigurationsResult &listBucketAnalyticsConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketAnalyticsConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketAnalyticsConfigurationsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListBucketIntelligentTieringConfigurationsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSS3ListBucketIntelligentTieringConfigurationsResult &listBucketIntelligentTieringConfigurationsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListBucketIntelligentTieringConfigurationsOutcomeCallable callable;

public:
    FListBucketIntelligentTieringConfigurationsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3ListBucketIntelligentTieringConfigurationsRequest listBucketIntelligentTieringConfigurationsRequest,
        FAWSS3ListBucketIntelligentTieringConfigurationsResult &listBucketIntelligentTieringConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketIntelligentTieringConfigurationsResult(listBucketIntelligentTieringConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListBucketIntelligentTieringConfigurationsCallable(listBucketIntelligentTieringConfigurationsRequest.toAWS());
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
US3ClientObject::ListBucketIntelligentTieringConfigurations(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3ListBucketIntelligentTieringConfigurationsRequest listBucketIntelligentTieringConfigurationsRequest,
    FAWSS3ListBucketIntelligentTieringConfigurationsResult &listBucketIntelligentTieringConfigurationsResult,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketIntelligentTieringConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketIntelligentTieringConfigurationsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListBucketInventoryConfigurationsAction : public FPendingLatentAction {
private:
    bool &success;
    FListBucketInventoryConfigurationsResult &listBucketInventoryConfigurationsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListBucketInventoryConfigurationsOutcomeCallable callable;

public:
    FListBucketInventoryConfigurationsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListBucketInventoryConfigurationsRequest listBucketInventoryConfigurationsRequest,
        FListBucketInventoryConfigurationsResult &listBucketInventoryConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketInventoryConfigurationsResult(listBucketInventoryConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListBucketInventoryConfigurationsCallable(listBucketInventoryConfigurationsRequest.toAWS());
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
US3ClientObject::ListBucketInventoryConfigurations(
        UObject *WorldContextObject,
        bool &success,
        FListBucketInventoryConfigurationsRequest listBucketInventoryConfigurationsRequest,
        FListBucketInventoryConfigurationsResult &listBucketInventoryConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketInventoryConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketInventoryConfigurationsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListBucketMetricsConfigurationsAction : public FPendingLatentAction {
private:
    bool &success;
    FListBucketMetricsConfigurationsResult &listBucketMetricsConfigurationsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListBucketMetricsConfigurationsOutcomeCallable callable;

public:
    FListBucketMetricsConfigurationsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListBucketMetricsConfigurationsRequest listBucketMetricsConfigurationsRequest,
        FListBucketMetricsConfigurationsResult &listBucketMetricsConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketMetricsConfigurationsResult(listBucketMetricsConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListBucketMetricsConfigurationsCallable(listBucketMetricsConfigurationsRequest.toAWS());
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
US3ClientObject::ListBucketMetricsConfigurations(
        UObject *WorldContextObject,
        bool &success,
        FListBucketMetricsConfigurationsRequest listBucketMetricsConfigurationsRequest,
        FListBucketMetricsConfigurationsResult &listBucketMetricsConfigurationsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketMetricsConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketMetricsConfigurationsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListBucketsAction : public FPendingLatentAction {
private:
    bool &success;
    FListBucketsResult &listBucketsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListBucketsOutcomeCallable callable;

public:
    FListBucketsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListBucketsResult &listBucketsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBucketsResult(listBucketsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListBucketsCallable();
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
US3ClientObject::ListBuckets(
        UObject *WorldContextObject,
        bool &success,
        FListBucketsResult &listBucketsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBucketsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBucketsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListMultipartUploadsAction : public FPendingLatentAction {
private:
    bool &success;
    FListMultipartUploadsResult &listMultipartUploadsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListMultipartUploadsOutcomeCallable callable;

public:
    FListMultipartUploadsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListMultipartUploadsRequest listMultipartUploadsRequest,
        FListMultipartUploadsResult &listMultipartUploadsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listMultipartUploadsResult(listMultipartUploadsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListMultipartUploadsCallable(listMultipartUploadsRequest.toAWS());
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
US3ClientObject::ListMultipartUploads(
        UObject *WorldContextObject,
        bool &success,
        FListMultipartUploadsRequest listMultipartUploadsRequest,
        FListMultipartUploadsResult &listMultipartUploadsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListMultipartUploadsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListMultipartUploadsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListObjectVersionsAction : public FPendingLatentAction {
private:
    bool &success;
    FListObjectVersionsResult &listObjectVersionsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListObjectVersionsOutcomeCallable callable;

public:
    FListObjectVersionsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListObjectVersionsRequest listObjectVersionsRequest,
        FListObjectVersionsResult &listObjectVersionsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listObjectVersionsResult(listObjectVersionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListObjectVersionsCallable(listObjectVersionsRequest.toAWS());
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
US3ClientObject::ListObjectVersions(
        UObject *WorldContextObject,
        bool &success,
        FListObjectVersionsRequest listObjectVersionsRequest,
        FListObjectVersionsResult &listObjectVersionsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListObjectVersionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListObjectVersionsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListObjectsAction : public FPendingLatentAction {
private:
    bool &success;
    FListObjectsResult &listObjectsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListObjectsOutcomeCallable callable;

public:
    FListObjectsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListObjectsRequest listObjectsRequest,
        FListObjectsResult &listObjectsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listObjectsResult(listObjectsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListObjectsCallable(listObjectsRequest.toAWS());
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
US3ClientObject::ListObjects(
        UObject *WorldContextObject,
        bool &success,
        FListObjectsRequest listObjectsRequest,
        FListObjectsResult &listObjectsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListObjectsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListObjectsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListObjectsV2Action : public FPendingLatentAction {
private:
    bool &success;
    FListObjectsV2Result &listObjectsV2Result;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListObjectsV2OutcomeCallable callable;

public:
    FListObjectsV2Action(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListObjectsV2Request listObjectsV2Request,
        FListObjectsV2Result &listObjectsV2Result,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listObjectsV2Result(listObjectsV2Result), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListObjectsV2Callable(listObjectsV2Request.toAWS());
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
US3ClientObject::ListObjectsV2(
        UObject *WorldContextObject,
        bool &success,
        FListObjectsV2Request listObjectsV2Request,
        FListObjectsV2Result &listObjectsV2Result,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListObjectsV2Action>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListObjectsV2Action(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FListPartsAction : public FPendingLatentAction {
private:
    bool &success;
    FListPartsResult &listPartsResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::ListPartsOutcomeCallable callable;

public:
    FListPartsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FListPartsRequest listPartsRequest,
        FListPartsResult &listPartsResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listPartsResult(listPartsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->ListPartsCallable(listPartsRequest.toAWS());
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
US3ClientObject::ListParts(
        UObject *WorldContextObject,
        bool &success,
        FListPartsRequest listPartsRequest,
        FListPartsResult &listPartsResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListPartsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListPartsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketAccelerateConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketAccelerateConfigurationOutcomeCallable callable;

public:
    FPutBucketAccelerateConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketAccelerateConfigurationRequest putBucketAccelerateConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketAccelerateConfigurationCallable(putBucketAccelerateConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketAccelerateConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketAccelerateConfigurationRequest putBucketAccelerateConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketAccelerateConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketAccelerateConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketAclAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketAclOutcomeCallable callable;

public:
    FPutBucketAclAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketAclRequest putBucketAclRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketAclCallable(putBucketAclRequest.toAWS());
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
US3ClientObject::PutBucketAcl(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketAclRequest putBucketAclRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketAclAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketAnalyticsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketAnalyticsConfigurationOutcomeCallable callable;

public:
    FPutBucketAnalyticsConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketAnalyticsConfigurationRequest putBucketAnalyticsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketAnalyticsConfigurationCallable(putBucketAnalyticsConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketAnalyticsConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketAnalyticsConfigurationRequest putBucketAnalyticsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketAnalyticsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketAnalyticsConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketCorsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketCorsOutcomeCallable callable;

public:
    FPutBucketCorsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketCorsRequest putBucketCorsRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketCorsCallable(putBucketCorsRequest.toAWS());
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
US3ClientObject::PutBucketCors(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketCorsRequest putBucketCorsRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketCorsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketCorsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketEncryptionAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketEncryptionOutcomeCallable callable;

public:
    FPutBucketEncryptionAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketEncryptionRequest putBucketEncryptionRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketEncryptionCallable(putBucketEncryptionRequest.toAWS());
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
US3ClientObject::PutBucketEncryption(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketEncryptionRequest putBucketEncryptionRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketEncryptionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketEncryptionAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketIntelligentTieringConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketIntelligentTieringConfigurationOutcomeCallable callable;

public:
    FPutBucketIntelligentTieringConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3PutBucketIntelligentTieringConfigurationRequest putBucketIntelligentTieringConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketIntelligentTieringConfigurationCallable(putBucketIntelligentTieringConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketIntelligentTieringConfiguration(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3PutBucketIntelligentTieringConfigurationRequest putBucketIntelligentTieringConfigurationRequest,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketIntelligentTieringConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketIntelligentTieringConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketInventoryConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketInventoryConfigurationOutcomeCallable callable;

public:
    FPutBucketInventoryConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketInventoryConfigurationRequest putBucketInventoryConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketInventoryConfigurationCallable(putBucketInventoryConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketInventoryConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketInventoryConfigurationRequest putBucketInventoryConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketInventoryConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketInventoryConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketLifecycleConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketLifecycleConfigurationOutcomeCallable callable;

public:
    FPutBucketLifecycleConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketLifecycleConfigurationCallable(putBucketLifecycleConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketLifecycleConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketLifecycleConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketLifecycleConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketLoggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketLoggingOutcomeCallable callable;

public:
    FPutBucketLoggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketLoggingRequest putBucketLoggingRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketLoggingCallable(putBucketLoggingRequest.toAWS());
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
US3ClientObject::PutBucketLogging(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketLoggingRequest putBucketLoggingRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketLoggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketLoggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketMetricsConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketMetricsConfigurationOutcomeCallable callable;

public:
    FPutBucketMetricsConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketMetricsConfigurationRequest putBucketMetricsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketMetricsConfigurationCallable(putBucketMetricsConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketMetricsConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketMetricsConfigurationRequest putBucketMetricsConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketMetricsConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketMetricsConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketNotificationConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketNotificationConfigurationOutcomeCallable callable;

public:
    FPutBucketNotificationConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketNotificationConfigurationRequest putBucketNotificationConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketNotificationConfigurationCallable(putBucketNotificationConfigurationRequest.toAWS());
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
US3ClientObject::PutBucketNotificationConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketNotificationConfigurationRequest putBucketNotificationConfigurationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketNotificationConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketNotificationConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketOwnershipControlsAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketOwnershipControlsOutcomeCallable callable;

public:
    FPutBucketOwnershipControlsAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3PutBucketOwnershipControlsRequest putBucketOwnershipControlsRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketOwnershipControlsCallable(putBucketOwnershipControlsRequest.toAWS());
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
US3ClientObject::PutBucketOwnershipControls(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3PutBucketOwnershipControlsRequest putBucketOwnershipControlsRequest,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketOwnershipControlsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketOwnershipControlsAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketPolicyOutcomeCallable callable;

public:
    FPutBucketPolicyAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketPolicyRequest putBucketPolicyRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketPolicyCallable(putBucketPolicyRequest.toAWS());
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
US3ClientObject::PutBucketPolicy(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketPolicyRequest putBucketPolicyRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketPolicyAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketReplicationAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketReplicationOutcomeCallable callable;

public:
    FPutBucketReplicationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketReplicationRequest putBucketReplicationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketReplicationCallable(putBucketReplicationRequest.toAWS());
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
US3ClientObject::PutBucketReplication(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketReplicationRequest putBucketReplicationRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketReplicationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketReplicationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketRequestPaymentAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketRequestPaymentOutcomeCallable callable;

public:
    FPutBucketRequestPaymentAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketRequestPaymentRequest putBucketRequestPaymentRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketRequestPaymentCallable(putBucketRequestPaymentRequest.toAWS());
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
US3ClientObject::PutBucketRequestPayment(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketRequestPaymentRequest putBucketRequestPaymentRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketRequestPaymentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketRequestPaymentAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketTaggingOutcomeCallable callable;

public:
    FPutBucketTaggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketTaggingRequest putBucketTaggingRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketTaggingCallable(putBucketTaggingRequest.toAWS());
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
US3ClientObject::PutBucketTagging(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketTaggingRequest putBucketTaggingRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketTaggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketVersioningAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketVersioningOutcomeCallable callable;

public:
    FPutBucketVersioningAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketVersioningRequest putBucketVersioningRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketVersioningCallable(putBucketVersioningRequest.toAWS());
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
US3ClientObject::PutBucketVersioning(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketVersioningRequest putBucketVersioningRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketVersioningAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketVersioningAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutBucketWebsiteAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutBucketWebsiteOutcomeCallable callable;

public:
    FPutBucketWebsiteAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutBucketWebsiteRequest putBucketWebsiteRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutBucketWebsiteCallable(putBucketWebsiteRequest.toAWS());
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
US3ClientObject::PutBucketWebsite(
        UObject *WorldContextObject,
        bool &success,
        FPutBucketWebsiteRequest putBucketWebsiteRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutBucketWebsiteAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutBucketWebsiteAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectResult &putObjectResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutObjectOutcomeCallable callable;

public:
    FPutObjectAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutObjectRequest putObjectRequest,
        FPutObjectResult &putObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectResult(putObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutObjectCallable(putObjectRequest.toAWS());
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
US3ClientObject::PutObject(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectRequest putObjectRequest,
        FPutObjectResult &putObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutObjectAclAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectAclResult &putObjectAclResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutObjectAclOutcomeCallable callable;

public:
    FPutObjectAclAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutObjectAclRequest putObjectAclRequest,
        FPutObjectAclResult &putObjectAclResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectAclResult(putObjectAclResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutObjectAclCallable(putObjectAclRequest.toAWS());
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
US3ClientObject::PutObjectAcl(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectAclRequest putObjectAclRequest,
        FPutObjectAclResult &putObjectAclResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectAclAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectAclAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutObjectLegalHoldAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectLegalHoldResult &putObjectLegalHoldResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutObjectLegalHoldOutcomeCallable callable;

public:
    FPutObjectLegalHoldAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutObjectLegalHoldRequest putObjectLegalHoldRequest,
        FPutObjectLegalHoldResult &putObjectLegalHoldResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectLegalHoldResult(putObjectLegalHoldResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutObjectLegalHoldCallable(putObjectLegalHoldRequest.toAWS());
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
US3ClientObject::PutObjectLegalHold(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectLegalHoldRequest putObjectLegalHoldRequest,
        FPutObjectLegalHoldResult &putObjectLegalHoldResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectLegalHoldAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectLegalHoldAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutObjectLockConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectLockConfigurationResult &putObjectLockConfigurationResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutObjectLockConfigurationOutcomeCallable callable;

public:
    FPutObjectLockConfigurationAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutObjectLockConfigurationRequest putObjectLockConfigurationRequest,
        FPutObjectLockConfigurationResult &putObjectLockConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectLockConfigurationResult(putObjectLockConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutObjectLockConfigurationCallable(putObjectLockConfigurationRequest.toAWS());
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
US3ClientObject::PutObjectLockConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectLockConfigurationRequest putObjectLockConfigurationRequest,
        FPutObjectLockConfigurationResult &putObjectLockConfigurationResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectLockConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectLockConfigurationAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutObjectRetentionAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectRetentionResult &putObjectRetentionResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutObjectRetentionOutcomeCallable callable;

public:
    FPutObjectRetentionAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutObjectRetentionRequest putObjectRetentionRequest,
        FPutObjectRetentionResult &putObjectRetentionResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectRetentionResult(putObjectRetentionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutObjectRetentionCallable(putObjectRetentionRequest.toAWS());
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
US3ClientObject::PutObjectRetention(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectRetentionRequest putObjectRetentionRequest,
        FPutObjectRetentionResult &putObjectRetentionResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectRetentionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectRetentionAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutObjectTaggingAction : public FPendingLatentAction {
private:
    bool &success;
    FPutObjectTaggingResult &putObjectTaggingResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutObjectTaggingOutcomeCallable callable;

public:
    FPutObjectTaggingAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FPutObjectTaggingRequest putObjectTaggingRequest,
        FPutObjectTaggingResult &putObjectTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putObjectTaggingResult(putObjectTaggingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutObjectTaggingCallable(putObjectTaggingRequest.toAWS());
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
US3ClientObject::PutObjectTagging(
        UObject *WorldContextObject,
        bool &success,
        FPutObjectTaggingRequest putObjectTaggingRequest,
        FPutObjectTaggingResult &putObjectTaggingResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutObjectTaggingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutObjectTaggingAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FPutPublicAccessBlockAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::PutPublicAccessBlockOutcomeCallable callable;

public:
    FPutPublicAccessBlockAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FS3PutPublicAccessBlockRequest putPublicAccessBlockRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->PutPublicAccessBlockCallable(putPublicAccessBlockRequest.toAWS());
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
US3ClientObject::PutPublicAccessBlock(
        UObject *WorldContextObject,
        bool &success,
        FS3PutPublicAccessBlockRequest putPublicAccessBlockRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutPublicAccessBlockAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutPublicAccessBlockAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FRestoreObjectAction : public FPendingLatentAction {
private:
    bool &success;
    FRestoreObjectResult &restoreObjectResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::RestoreObjectOutcomeCallable callable;

public:
    FRestoreObjectAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FRestoreObjectRequest restoreObjectRequest,
        FRestoreObjectResult &restoreObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), restoreObjectResult(restoreObjectResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->RestoreObjectCallable(restoreObjectRequest.toAWS());
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
US3ClientObject::RestoreObject(
        UObject *WorldContextObject,
        bool &success,
        FRestoreObjectRequest restoreObjectRequest,
        FRestoreObjectResult &restoreObjectResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRestoreObjectAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRestoreObjectAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FSelectObjectContentAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    Aws::S3::Model::SelectObjectContentRequest awsSelectObjectContentRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::SelectObjectContentOutcomeCallable callable;

public:
    FSelectObjectContentAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FSelectObjectContentRequest selectObjectContentRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        awsSelectObjectContentRequest = selectObjectContentRequest.toAWS();
        callable = S3Client->SelectObjectContentCallable(awsSelectObjectContentRequest);
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
US3ClientObject::SelectObjectContent(
        UObject *WorldContextObject,
        bool &success,
        FSelectObjectContentRequest selectObjectContentRequest,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSelectObjectContentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSelectObjectContentAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FUploadPartAction : public FPendingLatentAction {
private:
    bool &success;
    FUploadPartResult &uploadPartResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::UploadPartOutcomeCallable callable;

public:
    FUploadPartAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FUploadPartRequest uploadPartRequest,
        FUploadPartResult &uploadPartResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), uploadPartResult(uploadPartResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->UploadPartCallable(uploadPartRequest.toAWS());
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
US3ClientObject::UploadPart(
        UObject *WorldContextObject,
        bool &success,
        FUploadPartRequest uploadPartRequest,
        FUploadPartResult &uploadPartResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUploadPartAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUploadPartAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FUploadPartCopyAction : public FPendingLatentAction {
private:
    bool &success;
    FUploadPartCopyResult &uploadPartCopyResult;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::UploadPartCopyOutcomeCallable callable;

public:
    FUploadPartCopyAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FUploadPartCopyRequest uploadPartCopyRequest,
        FUploadPartCopyResult &uploadPartCopyResult,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), uploadPartCopyResult(uploadPartCopyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->UploadPartCopyCallable(uploadPartCopyRequest.toAWS());
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
US3ClientObject::UploadPartCopy(
        UObject *WorldContextObject,
        bool &success,
        FUploadPartCopyRequest uploadPartCopyRequest,
        FUploadPartCopyResult &uploadPartCopyResult,
        ES3Error &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUploadPartCopyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUploadPartCopyAction(this->awsS3Client,
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
#if WITH_S3CLIENTSDK && WITH_CORE

class FWriteGetObjectResponseAction : public FPendingLatentAction {
private:
    bool &success;
    ES3Error &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::S3::Model::WriteGetObjectResponseOutcomeCallable callable;

public:
    FWriteGetObjectResponseAction(
        Aws::S3::S3Client *S3Client,
        bool &success,
        FAWSS3WriteGetObjectResponseRequest writeGetObjectResponseRequest,
        ES3Error &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = S3Client->WriteGetObjectResponseCallable(writeGetObjectResponseRequest.toAWS());
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
US3ClientObject::WriteGetObjectResponse(
    UObject *WorldContextObject,
    bool &success,
    FAWSS3WriteGetObjectResponseRequest writeGetObjectResponseRequest,
    ES3Error &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_S3CLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FWriteGetObjectResponseAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FWriteGetObjectResponseAction(this->awsS3Client,
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