/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyResult.h"

#endif

#include "GetAccessPointPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FGetAccessPointPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The access point policy associated with the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FGetAccessPointPolicyResult &fromAWS(const Aws::S3Control::Model::GetAccessPointPolicyResult &awsGetAccessPointPolicyResult) {
        this->policy = UTF8_TO_TCHAR(awsGetAccessPointPolicyResult.GetPolicy().c_str());

        return *this;
    }
#endif
};
