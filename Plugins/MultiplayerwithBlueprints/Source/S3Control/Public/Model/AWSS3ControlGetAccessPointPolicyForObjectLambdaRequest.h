/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlGetAccessPointPolicyForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointPolicyForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetAccessPointPolicyForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::GetAccessPointPolicyForObjectLambdaRequest awsGetAccessPointPolicyForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsGetAccessPointPolicyForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsGetAccessPointPolicyForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsGetAccessPointPolicyForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
