/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetMultiRegionAccessPointPolicyResult.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointPolicyDocument.h"

#include "AWSS3ControlGetMultiRegionAccessPointPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetMultiRegionAccessPointPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The policy associated with the specified Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlMultiRegionAccessPointPolicyDocument policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetMultiRegionAccessPointPolicyResult &fromAWS(const Aws::S3Control::Model::GetMultiRegionAccessPointPolicyResult &awsGetMultiRegionAccessPointPolicyResult) {
        this->policy.fromAWS(awsGetMultiRegionAccessPointPolicyResult.GetPolicy());

        return *this;
    }
#endif
};
