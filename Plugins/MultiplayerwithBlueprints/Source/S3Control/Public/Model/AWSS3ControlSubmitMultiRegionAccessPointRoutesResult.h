/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/SubmitMultiRegionAccessPointRoutesResult.h"

#endif

#include "AWSS3ControlSubmitMultiRegionAccessPointRoutesResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlSubmitMultiRegionAccessPointRoutesResult {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlSubmitMultiRegionAccessPointRoutesResult &fromAWS(const Aws::S3Control::Model::SubmitMultiRegionAccessPointRoutesResult &awsSubmitMultiRegionAccessPointRoutesResult) {
        return *this;
    }
#endif
};
