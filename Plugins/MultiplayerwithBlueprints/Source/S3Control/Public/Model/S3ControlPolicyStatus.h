/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PolicyStatus.h"

#endif

#include "S3ControlPolicyStatus.generated.h"

USTRUCT(BlueprintType)
struct FS3ControlPolicyStatus {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isPublic = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FS3ControlPolicyStatus &fromAWS(const Aws::S3Control::Model::PolicyStatus &awsPolicyStatus) {
        this->isPublic = awsPolicyStatus.GetIsPublic();

        return *this;
    }
#endif
};
