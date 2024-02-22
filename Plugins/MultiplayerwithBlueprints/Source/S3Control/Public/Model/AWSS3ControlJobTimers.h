/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobTimers.h"

#endif

#include "AWSS3ControlJobTimers.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlJobTimers {
GENERATED_BODY()

    /**
    *  <p>Indicates the elapsed time in seconds the job has been in the Active job state.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 elapsedTimeInActiveSeconds = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlJobTimers &fromAWS(const Aws::S3Control::Model::JobTimers &awsJobTimers) {
        this->elapsedTimeInActiveSeconds = (int64)awsJobTimers.GetElapsedTimeInActiveSeconds();

        return *this;
    }
#endif
};
