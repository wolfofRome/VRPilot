/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ParquetInput.h"

#endif

#include "AWSS3CRTParquetInput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTParquetInput {
GENERATED_BODY()

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ParquetInput toAWS() const {
        Aws::S3Crt::Model::ParquetInput awsParquetInput;

        return awsParquetInput;
    }

    bool IsEmpty() const {
        return true;
    }
#endif
};
