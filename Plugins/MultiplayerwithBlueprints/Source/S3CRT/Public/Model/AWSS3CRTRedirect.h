/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Redirect.h"

#endif

#include "Model/AWSS3CRTProtocol.h"

#include "AWSS3CRTRedirect.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRedirect {
GENERATED_BODY()

    /**
    *  <p>The host name to use in the redirect request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString hostName;

    /**
    *  <p>The HTTP redirect code to use on the response. Not required if one of the siblings is present.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString httpRedirectCode;

    /**
    *  <p>Protocol to use when redirecting requests. The default is the protocol that is used in the original request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTProtocol protocol = EAWSS3CRTProtocol::NOT_SET;

    /**
    *  <p>The object key prefix to use in the redirect request. For example, to redirect requests for all pages with prefix <code>docs/</code> (objects in the <code>docs/</code> folder) to <code>documents/</code>, you can set a condition block with <code>KeyPrefixEquals</code> set to <code>docs/</code> and in the Redirect set <code>ReplaceKeyPrefixWith</code> to <code>/documents</code>. Not required if one of the siblings is present. Can be present only if <code>ReplaceKeyWith</code> is not provided.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString replaceKeyPrefixWith;

    /**
    *  <p>The specific object key to use in the redirect request. For example, redirect request to <code>error.html</code>. Not required if one of the siblings is present. Can be present only if <code>ReplaceKeyPrefixWith</code> is not provided.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString replaceKeyWith;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Redirect toAWS() const {
        Aws::S3Crt::Model::Redirect awsRedirect;

        if (!(this->hostName.IsEmpty())) {
            awsRedirect.SetHostName(TCHAR_TO_UTF8(*this->hostName));
        }

        if (!(this->httpRedirectCode.IsEmpty())) {
            awsRedirect.SetHttpRedirectCode(TCHAR_TO_UTF8(*this->httpRedirectCode));
        }

        switch(this->protocol) {
            case EAWSS3CRTProtocol::http:
                awsRedirect.SetProtocol(Aws::S3Crt::Model::Protocol::http);
                break;
            case EAWSS3CRTProtocol::https:
                awsRedirect.SetProtocol(Aws::S3Crt::Model::Protocol::https);
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
        return this->hostName.IsEmpty() && this->httpRedirectCode.IsEmpty() && this->protocol == EAWSS3CRTProtocol::NOT_SET && this->replaceKeyPrefixWith.IsEmpty() && this->replaceKeyWith.IsEmpty();
    }

    FAWSS3CRTRedirect &fromAWS(const Aws::S3Crt::Model::Redirect &awsRedirect) {
        this->hostName = UTF8_TO_TCHAR(awsRedirect.GetHostName().c_str());

        this->httpRedirectCode = UTF8_TO_TCHAR(awsRedirect.GetHttpRedirectCode().c_str());

        switch(awsRedirect.GetProtocol()) {
            case Aws::S3Crt::Model::Protocol::NOT_SET:
                this->protocol = EAWSS3CRTProtocol::NOT_SET;
                break;
            case Aws::S3Crt::Model::Protocol::http:
                this->protocol = EAWSS3CRTProtocol::http;
                break;
            case Aws::S3Crt::Model::Protocol::https:
                this->protocol = EAWSS3CRTProtocol::https;
                break;
            default:
                this->protocol = EAWSS3CRTProtocol::NOT_SET;
                break;
        }

        this->replaceKeyPrefixWith = UTF8_TO_TCHAR(awsRedirect.GetReplaceKeyPrefixWith().c_str());

        this->replaceKeyWith = UTF8_TO_TCHAR(awsRedirect.GetReplaceKeyWith().c_str());

        return *this;
    }
#endif
};
