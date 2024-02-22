/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutStorageLensConfigurationTaggingResult.h"

#endif

#include "AWSS3ControlPutStorageLensConfigurationTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutStorageLensConfigurationTaggingResult {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlPutStorageLensConfigurationTaggingResult &fromAWS(const Aws::S3Control::Model::PutStorageLensConfigurationTaggingResult &awsPutStorageLensConfigurationTaggingResult) {
        return *this;
    }
#endif
};
