/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteAccessPointRequest.h"

#endif


#include "DeleteAccessPointRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteAccessPointRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the access point you want to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DeleteAccessPointRequest toAWS() const {
        Aws::S3Control::Model::DeleteAccessPointRequest awsDeleteAccessPointRequest;

		if (!(this->accountId.IsEmpty())) {
            awsDeleteAccessPointRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsDeleteAccessPointRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteAccessPointRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
