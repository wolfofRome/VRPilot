/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/RequestPaymentConfiguration.h"

#endif

#include "Model/Payer.h"

#include "RequestPaymentConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FRequestPaymentConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies who pays for the download and request fees.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSPayer payer = EAWSPayer::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::RequestPaymentConfiguration toAWS() const {
        Aws::S3::Model::RequestPaymentConfiguration awsRequestPaymentConfiguration;

        switch(this->payer) {
            case EAWSPayer::Requester:
                awsRequestPaymentConfiguration.SetPayer(Aws::S3::Model::Payer::Requester);
                break;
            case EAWSPayer::BucketOwner:
                awsRequestPaymentConfiguration.SetPayer(Aws::S3::Model::Payer::BucketOwner);
                break;
            default:
                break;
        }

        return awsRequestPaymentConfiguration;
    }

    bool IsEmpty() const {
        return payer == EAWSPayer::NOT_SET;
    }
#endif
};
