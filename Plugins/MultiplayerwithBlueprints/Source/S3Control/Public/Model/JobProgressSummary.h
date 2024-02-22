/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobProgressSummary.h"

#endif

#include "Model/AWSS3ControlJobTimers.h"

#include "JobProgressSummary.generated.h"

USTRUCT(BlueprintType)
struct FJobProgressSummary {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 totalNumberOfTasks = 0;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 numberOfTasksSucceeded = 0;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 numberOfTasksFailed = 0;

    /**
    *  <p>The JobTimers attribute of a job's progress summary.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlJobTimers timers;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FJobProgressSummary &fromAWS(const Aws::S3Control::Model::JobProgressSummary &awsJobProgressSummary) {
        this->totalNumberOfTasks = (int64)awsJobProgressSummary.GetTotalNumberOfTasks();

        this->numberOfTasksSucceeded = (int64)awsJobProgressSummary.GetNumberOfTasksSucceeded();

        this->numberOfTasksFailed = (int64)awsJobProgressSummary.GetNumberOfTasksFailed();

        this->timers.fromAWS(awsJobProgressSummary.GetTimers());

        return *this;
    }
#endif
};
