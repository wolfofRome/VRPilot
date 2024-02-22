/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointPolicyStatusRequest.h"

#endif


#include "GetAccessPointPolicyStatusRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetAccessPointPolicyStatusRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the access point whose policy status you want to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetAccessPointPolicyStatusRequest toAWS() const {
        Aws::S3Control::Model::GetAccessPointPolicyStatusRequest awsGetAccessPointPolicyStatusRequest;

		if (!(this->accountId.IsEmpty())) {
            awsGetAccessPointPolicyStatusRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsGetAccessPointPolicyStatusRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsGetAccessPointPolicyStatusRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
