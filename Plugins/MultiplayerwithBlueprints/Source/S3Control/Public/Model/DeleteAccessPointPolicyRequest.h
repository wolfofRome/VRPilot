/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteAccessPointPolicyRequest.h"

#endif

#include "DeleteAccessPointPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteAccessPointPolicyRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the access point whose policy you want to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DeleteAccessPointPolicyRequest toAWS() const {
        Aws::S3Control::Model::DeleteAccessPointPolicyRequest awsDeleteAccessPointPolicyRequest;

		if (!(this->accountId.IsEmpty())) {
            awsDeleteAccessPointPolicyRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsDeleteAccessPointPolicyRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteAccessPointPolicyRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
