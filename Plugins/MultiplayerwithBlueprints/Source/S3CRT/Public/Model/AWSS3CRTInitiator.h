/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Initiator.h"

#endif

#include "AWSS3CRTInitiator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInitiator {
GENERATED_BODY()

    /**
    *  <p>If the principal is an AWS account, it provides the Canonical User ID. If the principal is an IAM User, it provides a user ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString iD;

    /**
    *  <p>Name of the Principal.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString displayName;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTInitiator &fromAWS(const Aws::S3Crt::Model::Initiator &awsInitiator) {
        this->iD = UTF8_TO_TCHAR(awsInitiator.GetID().c_str());

        this->displayName = UTF8_TO_TCHAR(awsInitiator.GetDisplayName().c_str());

        return *this;
    }
#endif
};
