/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteAccessPointPolicyForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlDeleteAccessPointPolicyForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteAccessPointPolicyForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the Object Lambda Access Point you want to delete the policy for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DeleteAccessPointPolicyForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::DeleteAccessPointPolicyForObjectLambdaRequest awsDeleteAccessPointPolicyForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsDeleteAccessPointPolicyForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsDeleteAccessPointPolicyForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteAccessPointPolicyForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
