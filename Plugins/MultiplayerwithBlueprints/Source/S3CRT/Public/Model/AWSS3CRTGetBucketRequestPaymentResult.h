/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketRequestPaymentResult.h"

#endif

#include "Model/AWSS3CRTPayer.h"

#include "AWSS3CRTGetBucketRequestPaymentResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketRequestPaymentResult {
GENERATED_BODY()

    /**
    *  <p>Specifies who pays for the download and request fees.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTPayer payer = EAWSS3CRTPayer::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketRequestPaymentResult &fromAWS(const Aws::S3Crt::Model::GetBucketRequestPaymentResult &awsGetBucketRequestPaymentResult) {
        switch(awsGetBucketRequestPaymentResult.GetPayer()) {
            case Aws::S3Crt::Model::Payer::NOT_SET:
                this->payer = EAWSS3CRTPayer::NOT_SET;
                break;
            case Aws::S3Crt::Model::Payer::Requester:
                this->payer = EAWSS3CRTPayer::Requester;
                break;
            case Aws::S3Crt::Model::Payer::BucketOwner:
                this->payer = EAWSS3CRTPayer::BucketOwner;
                break;
            default:
                this->payer = EAWSS3CRTPayer::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
