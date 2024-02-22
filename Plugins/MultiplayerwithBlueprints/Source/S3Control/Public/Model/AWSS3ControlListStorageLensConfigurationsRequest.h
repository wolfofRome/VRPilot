/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListStorageLensConfigurationsRequest.h"

#endif

#include "AWSS3ControlListStorageLensConfigurationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListStorageLensConfigurationsRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID of the requester.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>A pagination token to request the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ListStorageLensConfigurationsRequest toAWS() const {
        Aws::S3Control::Model::ListStorageLensConfigurationsRequest awsListStorageLensConfigurationsRequest;

        if (!(this->accountId.IsEmpty())) {
            awsListStorageLensConfigurationsRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListStorageLensConfigurationsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListStorageLensConfigurationsRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->nextToken.IsEmpty();
    }
#endif
};
