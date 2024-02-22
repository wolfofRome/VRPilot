/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/UpdateJobStatusResult.h"

#endif

#include "Model/JobStatus.h"

#include "UpdateJobStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateJobStatusResult {
GENERATED_BODY()

    /**
    *  <p>The ID for the job whose status was updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>The current status for the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSJobStatus status = EAWSJobStatus::NOT_SET;

    /**
    *  <p>The reason that the specified job's status was updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString statusUpdateReason;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FUpdateJobStatusResult &fromAWS(const Aws::S3Control::Model::UpdateJobStatusResult &awsUpdateJobStatusResult) {
        this->jobId = UTF8_TO_TCHAR(awsUpdateJobStatusResult.GetJobId().c_str());

        switch(awsUpdateJobStatusResult.GetStatus()) {
            case Aws::S3Control::Model::JobStatus::NOT_SET:
                this->status = EAWSJobStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::JobStatus::Active:
                this->status = EAWSJobStatus::Active;
                break;
            case Aws::S3Control::Model::JobStatus::Cancelled:
                this->status = EAWSJobStatus::Cancelled;
                break;
            case Aws::S3Control::Model::JobStatus::Cancelling:
                this->status = EAWSJobStatus::Cancelling;
                break;
            case Aws::S3Control::Model::JobStatus::Complete:
                this->status = EAWSJobStatus::Complete;
                break;
            case Aws::S3Control::Model::JobStatus::Completing:
                this->status = EAWSJobStatus::Completing;
                break;
            case Aws::S3Control::Model::JobStatus::Failed:
                this->status = EAWSJobStatus::Failed;
                break;
            case Aws::S3Control::Model::JobStatus::Failing:
                this->status = EAWSJobStatus::Failing;
                break;
            case Aws::S3Control::Model::JobStatus::New:
                this->status = EAWSJobStatus::New;
                break;
            case Aws::S3Control::Model::JobStatus::Paused:
                this->status = EAWSJobStatus::Paused;
                break;
            case Aws::S3Control::Model::JobStatus::Pausing:
                this->status = EAWSJobStatus::Pausing;
                break;
            case Aws::S3Control::Model::JobStatus::Preparing:
                this->status = EAWSJobStatus::Preparing;
                break;
            case Aws::S3Control::Model::JobStatus::Ready:
                this->status = EAWSJobStatus::Ready;
                break;
            case Aws::S3Control::Model::JobStatus::Suspended:
                this->status = EAWSJobStatus::Suspended;
                break;
            default:
                this->status = EAWSJobStatus::NOT_SET;
                break;
        }

        this->statusUpdateReason = UTF8_TO_TCHAR(awsUpdateJobStatusResult.GetStatusUpdateReason().c_str());

        return *this;
    }
#endif
};
