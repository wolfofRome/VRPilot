/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3ReplicateObjectOperation.h"

#endif

#include "AWSS3ControlS3ReplicateObjectOperation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlS3ReplicateObjectOperation {
GENERATED_BODY()

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3ReplicateObjectOperation toAWS() const {
        Aws::S3Control::Model::S3ReplicateObjectOperation awsS3ReplicateObjectOperation;

        return awsS3ReplicateObjectOperation;
    }

    bool IsEmpty() const {
        return true;
    }

    FAWSS3ControlS3ReplicateObjectOperation &fromAWS(const Aws::S3Control::Model::S3ReplicateObjectOperation &awsS3ReplicateObjectOperation) {
        return *this;
    }
#endif
};
