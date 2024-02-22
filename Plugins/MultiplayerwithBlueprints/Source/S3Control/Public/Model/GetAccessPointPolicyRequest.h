/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyRequest.h"

#endif

#include "GetAccessPointPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetAccessPointPolicyRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the access point whose policy you want to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetAccessPointPolicyRequest toAWS() const {
        Aws::S3Control::Model::GetAccessPointPolicyRequest awsGetAccessPointPolicyRequest;

		if (!(this->accountId.IsEmpty())) {
            awsGetAccessPointPolicyRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsGetAccessPointPolicyRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsGetAccessPointPolicyRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
