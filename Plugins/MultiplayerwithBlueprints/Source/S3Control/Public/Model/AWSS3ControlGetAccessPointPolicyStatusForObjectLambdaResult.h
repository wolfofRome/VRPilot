/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyStatusForObjectLambdaResult.h"

#endif

#include "Model/S3ControlPolicyStatus.h"

#include "AWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPolicyStatus policyStatus;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult &fromAWS(const Aws::S3Control::Model::GetAccessPointPolicyStatusForObjectLambdaResult &awsGetAccessPointPolicyStatusForObjectLambdaResult) {
        this->policyStatus.fromAWS(awsGetAccessPointPolicyStatusForObjectLambdaResult.GetPolicyStatus());

        return *this;
    }
#endif
};
