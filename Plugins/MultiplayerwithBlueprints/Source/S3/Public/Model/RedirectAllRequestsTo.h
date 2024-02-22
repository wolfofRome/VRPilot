/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/RedirectAllRequestsTo.h"

#endif

#include "Model/Protocol.h"

#include "RedirectAllRequestsTo.generated.h"

USTRUCT(BlueprintType)
struct FRedirectAllRequestsTo {
GENERATED_BODY()

    /**
    *  <p>Name of the host where requests are redirected.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString hostName;

    /**
    *  <p>Protocol to use when redirecting requests. The default is the protocol that is used in the original request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSProtocol protocol = EAWSProtocol::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::RedirectAllRequestsTo toAWS() const {
        Aws::S3::Model::RedirectAllRequestsTo awsRedirectAllRequestsTo;

		if (!(this->hostName.IsEmpty())) {
            awsRedirectAllRequestsTo.SetHostName(TCHAR_TO_UTF8(*this->hostName));
        }

        switch(this->protocol) {
            case EAWSProtocol::http:
                awsRedirectAllRequestsTo.SetProtocol(Aws::S3::Model::Protocol::http);
                break;
            case EAWSProtocol::https:
                awsRedirectAllRequestsTo.SetProtocol(Aws::S3::Model::Protocol::https);
                break;
            default:
                break;
            }

        return awsRedirectAllRequestsTo;
    }

    bool IsEmpty() const {
        return this->hostName.IsEmpty() && protocol == EAWSProtocol::NOT_SET;
    }

    FRedirectAllRequestsTo &fromAWS(const Aws::S3::Model::RedirectAllRequestsTo &awsRedirectAllRequestsTo) {
        this->hostName = UTF8_TO_TCHAR(awsRedirectAllRequestsTo.GetHostName().c_str());

        switch(awsRedirectAllRequestsTo.GetProtocol()) {
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

        return *this;
    }
#endif
};
