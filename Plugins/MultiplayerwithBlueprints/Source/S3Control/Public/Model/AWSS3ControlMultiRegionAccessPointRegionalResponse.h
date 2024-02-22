/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/MultiRegionAccessPointRegionalResponse.h"

#endif

#include "AWSS3ControlMultiRegionAccessPointRegionalResponse.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlMultiRegionAccessPointRegionalResponse {
GENERATED_BODY()

    /**
    *  <p>The name of the Region in the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>The current status of the Multi-Region Access Point in this Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString requestStatus;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlMultiRegionAccessPointRegionalResponse &fromAWS(const Aws::S3Control::Model::MultiRegionAccessPointRegionalResponse &awsMultiRegionAccessPointRegionalResponse) {
        this->name = UTF8_TO_TCHAR(awsMultiRegionAccessPointRegionalResponse.GetName().c_str());

        this->requestStatus = UTF8_TO_TCHAR(awsMultiRegionAccessPointRegionalResponse.GetRequestStatus().c_str());

        return *this;
    }
#endif
};
