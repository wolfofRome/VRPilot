/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, October 2022
 */

#include "RestfulFunctionLibrary.h"

#include "RestfulGlobals.h"

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"

#include "Engine.h"

#include "LatentActions.h"

#include <string>

class FSendRestfulRequestAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSendRestfulRequestAction(
        bool &success,
        FString url,
        FString verb,
        FString content,
        TMap<FString, FString> headers,
        float timeout,
        int32 &responseCode,
        FString &data,
        TMap<FString, FString> &responseHeaders,
        const FLatentActionInfo &LatentInfo
    ) :
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
        Request->OnProcessRequestComplete().BindLambda([&success, &responseCode, &data, &responseHeaders, this](FHttpRequestPtr httpRequest, FHttpResponsePtr httpResponse, bool bConnectedSuccessfully) {
            success = httpRequest->GetStatus() == EHttpRequestStatus::Type::Succeeded;

            data = httpResponse->GetContentAsString();

            responseCode = httpResponse->GetResponseCode();

            TArray<FString> headers = httpResponse->GetAllHeaders();
            for (auto &header : headers) {
                FString Name, Value;
                if (header.Split(TEXT(": "), &Name, &Value)) {
                    responseHeaders.Add(Name, Value);
                }
            }

            completed = true;
        });

        Request->SetURL(url);
        Request->SetVerb(verb);
        Request->SetContentAsString(content);
        Request->SetTimeout(timeout);
        for (const TPair<FString, FString>& elem : headers) {
            Request->SetHeader(elem.Key, elem.Value);
        }
        Request->ProcessRequest();
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("Send Restful Request");
    }

#endif
};

void
URestfulFunctionLibrary::SendRestfulRequest (
        UObject *WorldContextObject,
        bool &success,
        FString url,
        FString verb,
        FString content,
        TMap<FString, FString> headers,
        float timeout,
        int32 &responseCode,
        FString &data,
        TMap<FString, FString> &responseHeaders,
        struct FLatentActionInfo LatentInfo
) {
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSendRestfulRequestAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSendRestfulRequestAction(
                    success,
                    url,
                    verb,
                    content,
                    headers,
                    timeout,
                    responseCode,
                    data,
                    responseHeaders,
                    LatentInfo
                )
            );
        }
    }
    return;
}

class FSendRestfulWithFileRequestAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSendRestfulWithFileRequestAction(
        bool &success,
        FString url,
        FString verb,
        FString filename,
        TMap<FString, FString> headers,
        float timeout,
        int32 &responseCode,
        FString &data,
        TMap<FString, FString> &responseHeaders,
        const FLatentActionInfo &LatentInfo
    ) :
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
        Request->OnProcessRequestComplete().BindLambda([&success, &responseCode, &data, &responseHeaders, this](FHttpRequestPtr httpRequest, FHttpResponsePtr httpResponse, bool bConnectedSuccessfully) {
            success = httpRequest->GetStatus() == EHttpRequestStatus::Type::Succeeded;

            data = httpResponse->GetContentAsString();

            responseCode = httpResponse->GetResponseCode();

            TArray<FString> headers = httpResponse->GetAllHeaders();
            for (auto &header : headers) {
                FString Name, Value;
                if (header.Split(TEXT(": "), &Name, &Value)) {
                    responseHeaders.Add(Name, Value);
                }
            }

            completed = true;
        });

        Request->SetURL(url);
        Request->SetVerb(verb);
        Request->SetContentAsStreamedFile(filename);
        Request->SetTimeout(timeout);
        for (const TPair<FString, FString>& elem : headers) {
            Request->SetHeader(elem.Key, elem.Value);
        }
        Request->ProcessRequest();
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("Send Restful with file Request");
    }

#endif
};

void
URestfulFunctionLibrary::SendRestfulWithFileRequest (
        UObject *WorldContextObject,
        bool &success,
        FString url,
        FString verb,
        FString filename,
        TMap<FString, FString> headers,
        float timeout,
        int32 &responseCode,
        FString &data,
        TMap<FString, FString> &responseHeaders,
        struct FLatentActionInfo LatentInfo
) {
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSendRestfulWithFileRequestAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSendRestfulWithFileRequestAction(
                    success,
                    url,
                    verb,
                    filename,
                    headers,
                    timeout,
                    responseCode,
                    data,
                    responseHeaders,
                    LatentInfo
                )
            );
        }
    }
    return;
}