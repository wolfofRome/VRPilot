/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyStatusForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlGetAccessPointPolicyStatusForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaRequest {
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
    Aws::S3Control::Model::GetAccessPointPolicyStatusForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::GetAccessPointPolicyStatusForObjectLambdaRequest awsGetAccessPointPolicyStatusForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsGetAccessPointPolicyStatusForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsGetAccessPointPolicyStatusForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

		return awsGetAccessPointPolicyStatusForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
