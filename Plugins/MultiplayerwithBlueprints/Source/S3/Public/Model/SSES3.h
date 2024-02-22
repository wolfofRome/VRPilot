/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/SSES3.h"

#endif


#include "SSES3.generated.h"

USTRUCT(BlueprintType)
struct FSSES3 {
GENERATED_BODY()

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::SSES3 toAWS() const {
        Aws::S3::Model::SSES3 awsSSES3;

        return awsSSES3;
    }

    bool IsEmpty() const {
        return true;
    }

    FSSES3 &fromAWS(const Aws::S3::Model::SSES3 &awsSSES3) {
        return *this;
    }
#endif
};
