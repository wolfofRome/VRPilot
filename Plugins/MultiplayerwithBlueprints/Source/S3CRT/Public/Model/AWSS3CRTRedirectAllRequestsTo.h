/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/RedirectAllRequestsTo.h"

#endif

#include "Model/AWSS3CRTProtocol.h"

#include "AWSS3CRTRedirectAllRequestsTo.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRedirectAllRequestsTo {
GENERATED_BODY()

    /**
    *  <p>Name of the host where requests are redirected.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString hostName;

    /**
    *  <p>Protocol to use when redirecting requests. The default is the protocol that is used in the original request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTProtocol protocol = EAWSS3CRTProtocol::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::RedirectAllRequestsTo toAWS() const {
        Aws::S3Crt::Model::RedirectAllRequestsTo awsRedirectAllRequestsTo;

        if (!(this->hostName.IsEmpty())) {
            awsRedirectAllRequestsTo.SetHostName(TCHAR_TO_UTF8(*this->hostName));
        }

        switch(this->protocol) {
            case EAWSS3CRTProtocol::http:
                awsRedirectAllRequestsTo.SetProtocol(Aws::S3Crt::Model::Protocol::http);
                break;
            case EAWSS3CRTProtocol::https:
                awsRedirectAllRequestsTo.SetProtocol(Aws::S3Crt::Model::Protocol::https);
                break;
            default:
                break;
        }

        return awsRedirectAllRequestsTo;
    }

    bool IsEmpty() const {
        return this->hostName.IsEmpty() && this->protocol == EAWSS3CRTProtocol::NOT_SET;
    }

    FAWSS3CRTRedirectAllRequestsTo &fromAWS(const Aws::S3Crt::Model::RedirectAllRequestsTo &awsRedirectAllRequestsTo) {
        this->hostName = UTF8_TO_TCHAR(awsRedirectAllRequestsTo.GetHostName().c_str());

        switch(awsRedirectAllRequestsTo.GetProtocol()) {
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

        return *this;
    }
#endif
};
