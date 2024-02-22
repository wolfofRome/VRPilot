/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetMultiRegionAccessPointResult.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointReport.h"

#include "AWSS3ControlGetMultiRegionAccessPointResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetMultiRegionAccessPointResult {
GENERATED_BODY()

    /**
    *  <p>A container element containing the details of the requested Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlMultiRegionAccessPointReport accessPoint;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetMultiRegionAccessPointResult &fromAWS(const Aws::S3Control::Model::GetMultiRegionAccessPointResult &awsGetMultiRegionAccessPointResult) {
        this->accessPoint.fromAWS(awsGetMultiRegionAccessPointResult.GetAccessPoint());

        return *this;
    }
#endif
};
