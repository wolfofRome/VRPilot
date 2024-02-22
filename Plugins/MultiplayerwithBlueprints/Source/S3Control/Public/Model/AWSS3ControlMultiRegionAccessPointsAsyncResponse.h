/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/MultiRegionAccessPointsAsyncResponse.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointRegionalResponse.h"

#include "AWSS3ControlMultiRegionAccessPointsAsyncResponse.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlMultiRegionAccessPointsAsyncResponse {
GENERATED_BODY()

    /**
    *  <p>A collection of status information for the different Regions that a Multi-Region Access Point supports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlMultiRegionAccessPointRegionalResponse> regions;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlMultiRegionAccessPointsAsyncResponse &fromAWS(const Aws::S3Control::Model::MultiRegionAccessPointsAsyncResponse &awsMultiRegionAccessPointsAsyncResponse) {
        this->regions.Empty();
        for (const Aws::S3Control::Model::MultiRegionAccessPointRegionalResponse& elem : awsMultiRegionAccessPointsAsyncResponse.GetRegions()) {
            this->regions.Add(FAWSS3ControlMultiRegionAccessPointRegionalResponse().fromAWS(elem));
        }

        return *this;
    }
#endif
};
