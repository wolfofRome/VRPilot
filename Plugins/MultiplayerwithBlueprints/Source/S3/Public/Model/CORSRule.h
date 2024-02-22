/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CORSRule.h"

#endif

#include "CORSRule.generated.h"

USTRUCT(BlueprintType)
struct FCORSRule {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for the rule. The value cannot be longer than 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString iD;

    /**
    *  <p>Headers that are specified in the <code>Access-Control-Request-Headers</code> header. These headers are allowed in a preflight OPTIONS request. In response to any preflight OPTIONS request, Amazon S3 returns any requested headers that are allowed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FString> allowedHeaders;

    /**
    *  <p>An HTTP method that you allow the origin to execute. Valid values are <code>GET</code>, <code>PUT</code>, <code>HEAD</code>, <code>POST</code>, and <code>DELETE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FString> allowedMethods;

    /**
    *  <p>One or more origins you want customers to be able to access the bucket from.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FString> allowedOrigins;

    /**
    *  <p>One or more headers in the response that you want customers to be able to access from their applications (for example, from a JavaScript <code>XMLHttpRequest</code> object).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FString> exposeHeaders;

    /**
    *  <p>The time in seconds that your browser is to cache the preflight response for the specified resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxAgeSeconds = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CORSRule toAWS() const {
        Aws::S3::Model::CORSRule awsCORSRule;

        if (!(this->iD.IsEmpty())) {
            awsCORSRule.SetID(TCHAR_TO_UTF8(*this->iD));
        }

        for (const FString& elem : this->allowedHeaders) {
            awsCORSRule.AddAllowedHeaders(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->allowedMethods) {
            awsCORSRule.AddAllowedMethods(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->allowedOrigins) {
            awsCORSRule.AddAllowedOrigins(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->exposeHeaders) {
            awsCORSRule.AddExposeHeaders(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->maxAgeSeconds == 0)) {
            awsCORSRule.SetMaxAgeSeconds(this->maxAgeSeconds);
        }

        return awsCORSRule;
    }

    bool IsEmpty() const {
        return this->iD.IsEmpty() && this->allowedHeaders.Num() == 0 && this->allowedMethods.Num() == 0 && this->allowedOrigins.Num() == 0 && this->exposeHeaders.Num() == 0 && this->maxAgeSeconds == 0;
    }

    FCORSRule &fromAWS(const Aws::S3::Model::CORSRule &awsCORSRule) {
        this->iD = UTF8_TO_TCHAR(awsCORSRule.GetID().c_str());

        this->allowedHeaders.Empty();
        for (const Aws::String& elem : awsCORSRule.GetAllowedHeaders()) {
            this->allowedHeaders.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->allowedMethods.Empty();
        for (const Aws::String& elem : awsCORSRule.GetAllowedMethods()) {
            this->allowedMethods.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->allowedOrigins.Empty();
        for (const Aws::String& elem : awsCORSRule.GetAllowedOrigins()) {
            this->allowedOrigins.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->exposeHeaders.Empty();
        for (const Aws::String& elem : awsCORSRule.GetExposeHeaders()) {
            this->exposeHeaders.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

		this->maxAgeSeconds = awsCORSRule.GetMaxAgeSeconds();

        return *this;
    }
#endif
};
