/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteJobTaggingResult.h"

#endif

#include "DeleteJobTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteJobTaggingResult {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:

    FDeleteJobTaggingResult &fromAWS(const Aws::S3Control::Model::DeleteJobTaggingResult &awsDeleteJobTaggingResult) {
        return *this;
    }
#endif
};
