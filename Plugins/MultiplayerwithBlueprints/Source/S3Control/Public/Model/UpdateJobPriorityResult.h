/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/UpdateJobPriorityResult.h"

#endif

#include "UpdateJobPriorityResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateJobPriorityResult {
GENERATED_BODY()

    /**
    *  <p>The ID for the job whose priority Amazon S3 updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>The new priority assigned to the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int priority = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FUpdateJobPriorityResult &fromAWS(const Aws::S3Control::Model::UpdateJobPriorityResult &awsUpdateJobPriorityResult) {
        this->jobId = UTF8_TO_TCHAR(awsUpdateJobPriorityResult.GetJobId().c_str());

		this->priority = awsUpdateJobPriorityResult.GetPriority();

        return *this;
    }
#endif
};
