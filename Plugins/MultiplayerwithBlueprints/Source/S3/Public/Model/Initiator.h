/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Initiator.h"

#endif

#include "Initiator.generated.h"

USTRUCT(BlueprintType)
struct FInitiator {
GENERATED_BODY()

    /**
    *  <p>If the principal is an AWS account, it provides the Canonical User ID. If the principal is an IAM User, it provides a user ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString iD;

    /**
    *  <p>Name of the Principal.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString displayName;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FInitiator &fromAWS(const Aws::S3::Model::Initiator &awsInitiator) {
        this->iD = UTF8_TO_TCHAR(awsInitiator.GetID().c_str());

        this->displayName = UTF8_TO_TCHAR(awsInitiator.GetDisplayName().c_str());

        return *this;
    }
#endif
};
