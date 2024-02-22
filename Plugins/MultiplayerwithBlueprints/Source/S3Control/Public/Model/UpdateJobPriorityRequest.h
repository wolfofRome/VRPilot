/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/UpdateJobPriorityRequest.h"

#endif

#include "UpdateJobPriorityRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateJobPriorityRequest {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The ID for the job whose priority you want to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>The priority you want to assign to this job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int priority = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::UpdateJobPriorityRequest toAWS() const {
        Aws::S3Control::Model::UpdateJobPriorityRequest awsUpdateJobPriorityRequest;

		if (!(this->accountId.IsEmpty())) {
            awsUpdateJobPriorityRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->jobId.IsEmpty())) {
            awsUpdateJobPriorityRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        if (!(this->priority == 0)) {
            awsUpdateJobPriorityRequest.SetPriority(this->priority);
        }

        return awsUpdateJobPriorityRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->jobId.IsEmpty() && this->priority == 0;
    }
#endif
};
