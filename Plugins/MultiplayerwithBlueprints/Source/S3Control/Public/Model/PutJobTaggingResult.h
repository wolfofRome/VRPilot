/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutJobTaggingResult.h"

#endif

#include "PutJobTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FPutJobTaggingResult {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FPutJobTaggingResult &fromAWS(const Aws::S3Control::Model::PutJobTaggingResult &awsPutJobTaggingResult) {
        return *this;
    }
#endif
};
