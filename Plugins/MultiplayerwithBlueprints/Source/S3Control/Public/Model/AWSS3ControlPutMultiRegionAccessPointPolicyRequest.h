/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutMultiRegionAccessPointPolicyRequest.h"

#endif

#include "Model/AWSS3ControlPutMultiRegionAccessPointPolicyInput.h"

#include "AWSS3ControlPutMultiRegionAccessPointPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutMultiRegionAccessPointPolicyRequest {
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
    *  <p>A container element containing the details of the policy for the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlPutMultiRegionAccessPointPolicyInput details;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutMultiRegionAccessPointPolicyRequest toAWS() const {
        Aws::S3Control::Model::PutMultiRegionAccessPointPolicyRequest awsPutMultiRegionAccessPointPolicyRequest;

        if (!(this->accountId.IsEmpty())) {
            awsPutMultiRegionAccessPointPolicyRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->clientToken.IsEmpty())) {
            awsPutMultiRegionAccessPointPolicyRequest.SetClientToken(TCHAR_TO_UTF8(*this->clientToken));
        }

        if (!(this->details.IsEmpty())) {
            awsPutMultiRegionAccessPointPolicyRequest.SetDetails(this->details.toAWS());
        }

        return awsPutMultiRegionAccessPointPolicyRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->clientToken.IsEmpty() && this->details.IsEmpty();
    }
#endif
};
