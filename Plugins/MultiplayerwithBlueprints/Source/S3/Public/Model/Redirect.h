/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Redirect.h"

#endif

#include "Model/Protocol.h"

#include "Redirect.generated.h"

USTRUCT(BlueprintType)
struct FRedirect {
GENERATED_BODY()

    /**
    *  <p>The host name to use in the redirect request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString hostName;

    /**
    *  <p>The HTTP redirect code to use on the response. Not required if one of the siblings is present.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString httpRedirectCode;

    /**
    *  <p>Protocol to use when redirecting requests. The default is the protocol that is used in the original request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSProtocol protocol = EAWSProtocol::NOT_SET;

    /**
    *  <p>The object key prefix to use in the redirect request. For example, to redirect requests for all pages with prefix <code>docs/</code> (objects in the <code>docs/</code> folder) to <code>documents/</code>, you can set a condition block with <code>KeyPrefixEquals</code> set to <code>docs/</code> and in the Redirect set <code>ReplaceKeyPrefixWith</code> to <code>/documents</code>. Not required if one of the siblings is present. Can be present only if <code>ReplaceKeyWith</code> is not provided.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString replaceKeyPrefixWith;

    /**
    *  <p>The specific object key to use in the redirect request. For example, redirect request to <code>error.html</code>. Not required if one of the siblings is present. Can be present only if <code>ReplaceKeyPrefixWith</code> is not provided.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString replaceKeyWith;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Redirect toAWS() const {
        Aws::S3::Model::Redirect awsRedirect;

		if (!(this->hostName.IsEmpty())) {
            awsRedirect.SetHostName(TCHAR_TO_UTF8(*this->hostName));
        }

		if (!(this->httpRedirectCode.IsEmpty())) {
            awsRedirect.SetHttpRedirectCode(TCHAR_TO_UTF8(*this->httpRedirectCode));
        }

        switch(this->protocol) {
            case EAWSProtocol::http:
                awsRedirect.SetProtocol(Aws::S3::Model::Protocol::http);
                break;
            case EAWSProtocol::https:
                awsRedirect.SetProtocol(Aws::S3::Model::Protocol::https);
                break;
            default:
                break;
		}

		if (!(this->replaceKeyPrefixWith.IsEmpty())) {
            awsRedirect.SetReplaceKeyPrefixWith(TCHAR_TO_UTF8(*this->replaceKeyPrefixWith));
        }

		if (!(this->replaceKeyWith.IsEmpty())) {
            awsRedirect.SetReplaceKeyWith(TCHAR_TO_UTF8(*this->replaceKeyWith));
        }

        return awsRedirect;
    }

    bool IsEmpty() const {
        return this->hostName.IsEmpty() && this->httpRedirectCode.IsEmpty() && protocol == EAWSProtocol::NOT_SET && this->replaceKeyPrefixWith.IsEmpty() && this->replaceKeyWith.IsEmpty();
    }

    FRedirect &fromAWS(const Aws::S3::Model::Redirect &awsRedirect) {
        this->hostName = UTF8_TO_TCHAR(awsRedirect.GetHostName().c_str());

        this->httpRedirectCode = UTF8_TO_TCHAR(awsRedirect.GetHttpRedirectCode().c_str());

        switch(awsRedirect.GetProtocol()) {
            case Aws::S3::Model::Protocol::NOT_SET:
                this->protocol = EAWSProtocol::NOT_SET;
                break;
            case Aws::S3::Model::Protocol::http:
                this->protocol = EAWSProtocol::http;
                break;
            case Aws::S3::Model::Protocol::https:
                this->protocol = EAWSProtocol::https;
                break;
            default:
                this->protocol = EAWSProtocol::NOT_SET;
                break;
        }

        this->replaceKeyPrefixWith = UTF8_TO_TCHAR(awsRedirect.GetReplaceKeyPrefixWith().c_str());

        this->replaceKeyWith = UTF8_TO_TCHAR(awsRedirect.GetReplaceKeyWith().c_str());

        return *this;
    }
#endif
};
