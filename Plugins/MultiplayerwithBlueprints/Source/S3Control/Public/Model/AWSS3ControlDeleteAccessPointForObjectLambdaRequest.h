/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteAccessPointForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlDeleteAccessPointForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteAccessPointForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified Object Lambda Access Point.</p>
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
    Aws::S3Control::Model::DeleteAccessPointForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::DeleteAccessPointForObjectLambdaRequest awsDeleteAccessPointForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsDeleteAccessPointForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->name.IsEmpty())) {
            awsDeleteAccessPointForObjectLambdaRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteAccessPointForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
