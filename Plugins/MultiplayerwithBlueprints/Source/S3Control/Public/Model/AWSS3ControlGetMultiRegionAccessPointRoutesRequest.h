/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetMultiRegionAccessPointRoutesRequest.h"

#endif

#include "AWSS3ControlGetMultiRegionAccessPointRoutesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetMultiRegionAccessPointRoutesRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the owner of the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The Multi-Region Access Point ARN.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString mrap;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetMultiRegionAccessPointRoutesRequest toAWS() const {
        Aws::S3Control::Model::GetMultiRegionAccessPointRoutesRequest awsGetMultiRegionAccessPointRoutesRequest;

		if (!(this->accountId.IsEmpty())) {
            awsGetMultiRegionAccessPointRoutesRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->mrap.IsEmpty())) {
            awsGetMultiRegionAccessPointRoutesRequest.SetMrap(TCHAR_TO_UTF8(*this->mrap));
        }

        return awsGetMultiRegionAccessPointRoutesRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->mrap.IsEmpty();
    }
#endif
};
