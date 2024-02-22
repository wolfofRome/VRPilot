/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/SSES3.h"

#endif

#include "AWSS3CRTSSES3.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTSSES3 {
GENERATED_BODY()

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::SSES3 toAWS() const {
        Aws::S3Crt::Model::SSES3 awsSSES3;

        return awsSSES3;
    }

    bool IsEmpty() const {
        return true;
    }

    FAWSS3CRTSSES3 &fromAWS(const Aws::S3Crt::Model::SSES3 &awsSSES3) {
        return *this;
    }
#endif
};
