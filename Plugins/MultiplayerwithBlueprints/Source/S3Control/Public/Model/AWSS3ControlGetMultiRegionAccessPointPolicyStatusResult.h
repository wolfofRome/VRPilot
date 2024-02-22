/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetMultiRegionAccessPointPolicyStatusResult.h"

#endif

#include "Model/S3ControlPolicyStatus.h"

#include "AWSS3ControlGetMultiRegionAccessPointPolicyStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetMultiRegionAccessPointPolicyStatusResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPolicyStatus established;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetMultiRegionAccessPointPolicyStatusResult &fromAWS(const Aws::S3Control::Model::GetMultiRegionAccessPointPolicyStatusResult &awsGetMultiRegionAccessPointPolicyStatusResult) {
        this->established.fromAWS(awsGetMultiRegionAccessPointPolicyStatusResult.GetEstablished());

        return *this;
    }
#endif
};
