/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/SSES3Encryption.h"

#endif

#include "AWSS3ControlSSES3Encryption.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlSSES3Encryption {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::SSES3Encryption toAWS() const {
        Aws::S3Control::Model::SSES3Encryption awsSSES3Encryption;

        return awsSSES3Encryption;
    }

    bool IsEmpty() const {
        return true;
    }

    FAWSS3ControlSSES3Encryption &fromAWS(const Aws::S3Control::Model::SSES3Encryption &awsSSES3Encryption) {
        return *this;
    }
#endif
};
