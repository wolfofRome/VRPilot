/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateMultiRegionAccessPointRequest.h"

#endif

#include "Model/AWSS3ControlCreateMultiRegionAccessPointInput.h"

#include "AWSS3ControlCreateMultiRegionAccessPointRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateMultiRegionAccessPointRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the owner of the Multi-Region Access Point. The owner of the Multi-Region Access Point also must own the underlying buckets.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>An idempotency token used to identify the request and guarantee that requests are unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString clientToken;

    /**
    *  <p>A container element containing details about the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlCreateMultiRegionAccessPointInput details;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateMultiRegionAccessPointRequest toAWS() const {
        Aws::S3Control::Model::CreateMultiRegionAccessPointRequest awsCreateMultiRegionAccessPointRequest;

        if (!(this->accountId.IsEmpty())) {
            awsCreateMultiRegionAccessPointRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->clientToken.IsEmpty())) {
            awsCreateMultiRegionAccessPointRequest.SetClientToken(TCHAR_TO_UTF8(*this->clientToken));
        }

        if (!(this->details.IsEmpty())) {
            awsCreateMultiRegionAccessPointRequest.SetDetails(this->details.toAWS());
        }

        return awsCreateMultiRegionAccessPointRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->clientToken.IsEmpty() && this->details.IsEmpty();
    }
#endif
};
