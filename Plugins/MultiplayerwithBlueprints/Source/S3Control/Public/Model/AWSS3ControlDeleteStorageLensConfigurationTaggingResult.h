/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteStorageLensConfigurationTaggingResult.h"

#endif

#include "AWSS3ControlDeleteStorageLensConfigurationTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteStorageLensConfigurationTaggingResult {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlDeleteStorageLensConfigurationTaggingResult &fromAWS(const Aws::S3Control::Model::DeleteStorageLensConfigurationTaggingResult &awsDeleteStorageLensConfigurationTaggingResult) {
        return *this;
    }
#endif
};
