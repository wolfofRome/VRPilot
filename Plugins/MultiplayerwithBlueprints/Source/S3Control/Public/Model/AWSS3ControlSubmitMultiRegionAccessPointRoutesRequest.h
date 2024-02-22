/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/SubmitMultiRegionAccessPointRoutesRequest.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointRoute.h"

#include "AWSS3ControlSubmitMultiRegionAccessPointRoutesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlSubmitMultiRegionAccessPointRoutesRequest {
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

    /**
    *  <p>The different routes that make up the new route configuration. Active routes return a value of <code>100</code>, and passive routes return a value of <code>0</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlMultiRegionAccessPointRoute> routeUpdates;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::SubmitMultiRegionAccessPointRoutesRequest toAWS() const {
        Aws::S3Control::Model::SubmitMultiRegionAccessPointRoutesRequest awsSubmitMultiRegionAccessPointRoutesRequest;

        if (!(this->accountId.IsEmpty())) {
            awsSubmitMultiRegionAccessPointRoutesRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->mrap.IsEmpty())) {
            awsSubmitMultiRegionAccessPointRoutesRequest.SetMrap(TCHAR_TO_UTF8(*this->mrap));
        }

        for (const FAWSS3ControlMultiRegionAccessPointRoute& elem : this->routeUpdates) {
            awsSubmitMultiRegionAccessPointRoutesRequest.AddRouteUpdates(elem.toAWS());
        }

        return awsSubmitMultiRegionAccessPointRoutesRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->mrap.IsEmpty() && this->routeUpdates.Num() == 0;
    }
#endif
};
