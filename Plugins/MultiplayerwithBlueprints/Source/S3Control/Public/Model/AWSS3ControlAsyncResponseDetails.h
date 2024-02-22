/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AsyncResponseDetails.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointsAsyncResponse.h"
#include "Model/AWSS3ControlAsyncErrorDetails.h"

#include "AWSS3ControlAsyncResponseDetails.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAsyncResponseDetails {
GENERATED_BODY()

    /**
    *  <p>The details for the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlMultiRegionAccessPointsAsyncResponse multiRegionAccessPointDetails;

    /**
    *  <p>Error details for an asynchronous request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAsyncErrorDetails errorDetails;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:

    FAWSS3ControlAsyncResponseDetails &fromAWS(const Aws::S3Control::Model::AsyncResponseDetails &awsAsyncResponseDetails) {
        this->multiRegionAccessPointDetails.fromAWS(awsAsyncResponseDetails.GetMultiRegionAccessPointDetails());

        this->errorDetails.fromAWS(awsAsyncResponseDetails.GetErrorDetails());

        return *this;
    }
#endif
};
