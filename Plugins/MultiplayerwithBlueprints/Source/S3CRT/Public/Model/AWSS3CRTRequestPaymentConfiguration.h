/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/RequestPaymentConfiguration.h"

#endif

#include "Model/AWSS3CRTPayer.h"

#include "AWSS3CRTRequestPaymentConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRequestPaymentConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies who pays for the download and request fees.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTPayer payer = EAWSS3CRTPayer::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::RequestPaymentConfiguration toAWS() const {
        Aws::S3Crt::Model::RequestPaymentConfiguration awsRequestPaymentConfiguration;

        switch(this->payer) {
            case EAWSS3CRTPayer::Requester:
                awsRequestPaymentConfiguration.SetPayer(Aws::S3Crt::Model::Payer::Requester);
                break;
            case EAWSS3CRTPayer::BucketOwner:
                awsRequestPaymentConfiguration.SetPayer(Aws::S3Crt::Model::Payer::BucketOwner);
                break;
            default:
                break;
        }

        return awsRequestPaymentConfiguration;
    }

    bool IsEmpty() const {
        return this->payer == EAWSS3CRTPayer::NOT_SET;
    }
#endif
};
