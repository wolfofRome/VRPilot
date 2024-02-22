/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutAccessPointPolicyForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlPutAccessPointPolicyForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutAccessPointPolicyForObjectLambdaRequest {
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

    /**
    *  <p>Object Lambda Access Point resource policy document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutAccessPointPolicyForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::PutAccessPointPolicyForObjectLambdaRequest awsPutAccessPointPolicyForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsPutAccessPointPolicyForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsPutAccessPointPolicyForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

		if (!(this->policy.IsEmpty())) {
            awsPutAccessPointPolicyForObjectLambdaRequest.SetPolicy(TCHAR_TO_UTF8(*this->policy));
        }

		return awsPutAccessPointPolicyForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty() && this->policy.IsEmpty();
    }
#endif
};
