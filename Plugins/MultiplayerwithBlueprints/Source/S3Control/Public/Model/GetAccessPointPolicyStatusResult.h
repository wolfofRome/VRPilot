/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyStatusResult.h"

#endif

#include "Model/S3ControlPolicyStatus.h"

#include "GetAccessPointPolicyStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FGetAccessPointPolicyStatusResult {
GENERATED_BODY()

    /**
    *  <p>Indicates the current policy status of the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPolicyStatus policyStatus;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FGetAccessPointPolicyStatusResult &fromAWS(const Aws::S3Control::Model::GetAccessPointPolicyStatusResult &awsGetAccessPointPolicyStatusResult) {
        this->policyStatus.fromAWS(awsGetAccessPointPolicyStatusResult.GetPolicyStatus());

        return *this;
    }
#endif
};
