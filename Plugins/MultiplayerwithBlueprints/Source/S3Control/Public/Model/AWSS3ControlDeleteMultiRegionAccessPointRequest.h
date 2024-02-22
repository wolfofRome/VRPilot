/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteMultiRegionAccessPointRequest.h"

#endif

#include "Model/AWSS3ControlDeleteMultiRegionAccessPointInput.h"

#include "AWSS3ControlDeleteMultiRegionAccessPointRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteMultiRegionAccessPointRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the owner of the Multi-Region Access Point.</p>
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
    FAWSS3ControlDeleteMultiRegionAccessPointInput details;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DeleteMultiRegionAccessPointRequest toAWS() const {
        Aws::S3Control::Model::DeleteMultiRegionAccessPointRequest awsDeleteMultiRegionAccessPointRequest;

        if (!(this->accountId.IsEmpty())) {
            awsDeleteMultiRegionAccessPointRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->clientToken.IsEmpty())) {
            awsDeleteMultiRegionAccessPointRequest.SetClientToken(TCHAR_TO_UTF8(*this->clientToken));
        }

        if (!(this->details.IsEmpty())) {
            awsDeleteMultiRegionAccessPointRequest.SetDetails(this->details.toAWS());
        }

        return awsDeleteMultiRegionAccessPointRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->clientToken.IsEmpty() && this->details.IsEmpty();
    }
#endif
};
