/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3DeleteObjectTaggingOperation.h"

#endif

#include "AWSS3ControlS3DeleteObjectTaggingOperation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlS3DeleteObjectTaggingOperation {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3DeleteObjectTaggingOperation toAWS() const {
        Aws::S3Control::Model::S3DeleteObjectTaggingOperation awsS3DeleteObjectTaggingOperation;

        return awsS3DeleteObjectTaggingOperation;
    }

    bool IsEmpty() const {
        return true;
    }

    FAWSS3ControlS3DeleteObjectTaggingOperation &fromAWS(const Aws::S3Control::Model::S3DeleteObjectTaggingOperation &awsS3DeleteObjectTaggingOperation) {
        return *this;
    }
#endif
};
