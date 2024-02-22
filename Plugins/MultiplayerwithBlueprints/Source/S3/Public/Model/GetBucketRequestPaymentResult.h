/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketRequestPaymentResult.h"

#endif

#include "Model/Payer.h"

#include "GetBucketRequestPaymentResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketRequestPaymentResult {
GENERATED_BODY()

    /**
    *  <p>Specifies who pays for the download and request fees.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSPayer payer = EAWSPayer::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketRequestPaymentResult &fromAWS(const Aws::S3::Model::GetBucketRequestPaymentResult &awsGetBucketRequestPaymentResult) {
        switch(awsGetBucketRequestPaymentResult.GetPayer()) {
            case Aws::S3::Model::Payer::NOT_SET:
                this->payer = EAWSPayer::NOT_SET;
                break;
            case Aws::S3::Model::Payer::Requester:
                this->payer = EAWSPayer::Requester;
                break;
            case Aws::S3::Model::Payer::BucketOwner:
                this->payer = EAWSPayer::BucketOwner;
                break;
            default:
                this->payer = EAWSPayer::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
