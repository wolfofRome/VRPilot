/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobListDescriptor.h"

#endif

#include "Model/OperationName.h"
#include "Model/JobStatus.h"
#include "Model/JobProgressSummary.h"

#include "JobListDescriptor.generated.h"

USTRUCT(BlueprintType)
struct FJobListDescriptor {
GENERATED_BODY()

    /**
    *  <p>The ID for the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>The user-specified description that was included in the specified job's <code>Create Job</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString description;

    /**
    *  <p>The operation that the specified job is configured to run on each object listed in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSOperationName operation = EAWSOperationName::NOT_SET;

    /**
    *  <p>The current priority for the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int priority = 0;

    /**
    *  <p>The specified job's current status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSJobStatus status = EAWSJobStatus::NOT_SET;

    /**
    *  <p>A timestamp indicating when the specified job was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationTime;

    /**
    *  <p>A timestamp indicating when the specified job terminated. A job's termination date is the date and time when it succeeded, failed, or was canceled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime terminationDate;

    /**
    *  <p>Describes the total number of tasks that the specified job has executed, the number of tasks that succeeded, and the number of tasks that failed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobProgressSummary progressSummary;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FJobListDescriptor &fromAWS(const Aws::S3Control::Model::JobListDescriptor &awsJobListDescriptor) {
        this->jobId = UTF8_TO_TCHAR(awsJobListDescriptor.GetJobId().c_str());

        this->description = UTF8_TO_TCHAR(awsJobListDescriptor.GetDescription().c_str());

        switch(awsJobListDescriptor.GetOperation()) {
            case Aws::S3Control::Model::OperationName::NOT_SET:
                this->operation = EAWSOperationName::NOT_SET;
                break;
            case Aws::S3Control::Model::OperationName::LambdaInvoke:
                this->operation = EAWSOperationName::LambdaInvoke;
                break;
            case Aws::S3Control::Model::OperationName::S3PutObjectCopy:
                this->operation = EAWSOperationName::S3PutObjectCopy;
                break;
            case Aws::S3Control::Model::OperationName::S3PutObjectAcl:
                this->operation = EAWSOperationName::S3PutObjectAcl;
                break;
            case Aws::S3Control::Model::OperationName::S3PutObjectTagging:
                this->operation = EAWSOperationName::S3PutObjectTagging;
                break;
            case Aws::S3Control::Model::OperationName::S3DeleteObjectTagging:
                this->operation = EAWSOperationName::S3DeleteObjectTagging;
                break;
            case Aws::S3Control::Model::OperationName::S3InitiateRestoreObject:
                this->operation = EAWSOperationName::S3InitiateRestoreObject;
                break;
            case Aws::S3Control::Model::OperationName::S3PutObjectLegalHold:
                this->operation = EAWSOperationName::S3PutObjectLegalHold;
                break;
            case Aws::S3Control::Model::OperationName::S3PutObjectRetention:
                this->operation = EAWSOperationName::S3PutObjectRetention;
                break;
            case Aws::S3Control::Model::OperationName::S3ReplicateObject:
                this->operation = EAWSOperationName::S3ReplicateObject;
                break;
            default:
                this->operation = EAWSOperationName::NOT_SET;
                break;
        }

		this->priority = awsJobListDescriptor.GetPriority();

        switch(awsJobListDescriptor.GetStatus()) {
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

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsJobListDescriptor.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->terminationDate = FDateTime(1970, 1, 1) + FTimespan(awsJobListDescriptor.GetTerminationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->progressSummary.fromAWS(awsJobListDescriptor.GetProgressSummary());

        return *this;
    }
#endif
};
