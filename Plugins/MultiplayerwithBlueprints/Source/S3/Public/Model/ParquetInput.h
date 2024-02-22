/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ParquetInput.h"

#endif

#include "ParquetInput.generated.h"

USTRUCT(BlueprintType)
struct FParquetInput {
GENERATED_BODY()

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ParquetInput toAWS() const {
        Aws::S3::Model::ParquetInput awsParquetInput;

        return awsParquetInput;
    }

    bool IsEmpty() const {
        return true;
    }
#endif
};
