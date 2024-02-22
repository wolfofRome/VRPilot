/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyForObjectLambdaResult.h"

#endif

#include "AWSS3ControlGetAccessPointPolicyForObjectLambdaResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointPolicyForObjectLambdaResult {
GENERATED_BODY()

    /**
    *  <p>Object Lambda Access Point resource policy document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetAccessPointPolicyForObjectLambdaResult &fromAWS(const Aws::S3Control::Model::GetAccessPointPolicyForObjectLambdaResult &awsGetAccessPointPolicyForObjectLambdaResult) {
        this->policy = UTF8_TO_TCHAR(awsGetAccessPointPolicyForObjectLambdaResult.GetPolicy().c_str());

        return *this;
    }
#endif
};
