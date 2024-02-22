/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobDescriptor.h"

#endif

#include "Model/JobStatus.h"
#include "Model/JobManifest.h"
#include "Model/JobOperation.h"
#include "Model/JobProgressSummary.h"
#include "Model/JobFailure.h"
#include "Model/JobReport.h"
#include "Model/AWSS3ControlJobManifestGenerator.h"
#include "Model/AWSS3ControlS3GeneratedManifestDescriptor.h"

#include "JobDescriptor.generated.h"

USTRUCT(BlueprintType)
struct FJobDescriptor {
GENERATED_BODY()

    /**
    *  <p>The ID for the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>Indicates whether confirmation is required before Amazon S3 begins running the specified job. Confirmation is required only for jobs created through the Amazon S3 console.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool confirmationRequired = false;

    /**
    *  <p>The description for this job, if one was provided in this job's <code>Create Job</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString description;

    /**
    *  <p>The Amazon Resource Name (ARN) for this job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobArn;

    /**
    *  <p>The current status of the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSJobStatus status = EAWSJobStatus::NOT_SET;

    /**
    *  <p>The configuration information for the specified job's manifest object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobManifest manifest;

    /**
    *  <p>The operation that the specified job is configured to run on the objects listed in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobOperation operation;

    /**
    *  <p>The priority of the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int priority = 0;

    /**
    *  <p>Describes the total number of tasks that the specified job has run, the number of tasks that succeeded, and the number of tasks that failed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobProgressSummary progressSummary;

    /**
    *  <p>The reason for updating the job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString statusUpdateReason;

    /**
    *  <p>If the specified job failed, this field contains information describing the failure.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FJobFailure> failureReasons;

    /**
    *  <p>Contains the configuration information for the job-completion report if you requested one in the <code>Create Job</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobReport report;

    /**
    *  <p>A timestamp indicating when this job was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationTime;

    /**
    *  <p>A timestamp indicating when this job terminated. A job's termination date is the date and time when it succeeded, failed, or was canceled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime terminationDate;

    /**
    *  <p>The Amazon Resource Name (ARN) for the Identity and Access Management (IAM) role assigned to run the tasks for this job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString roleArn;

    /**
    *  <p>The timestamp when this job was suspended, if it has been suspended.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime suspendedDate;

    /**
    *  <p>The reason why the specified job was suspended. A job is only suspended if you create it through the Amazon S3 console. When you create the job, it enters the <code>Suspended</code> state to await confirmation before running. After you confirm the job, it automatically exits the <code>Suspended</code> state.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString suspendedCause;

    /**
    *  <p>The manifest generator that was used to generate a job manifest for this job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlJobManifestGenerator manifestGenerator;

    /**
    *  <p>The attribute of the JobDescriptor containing details about the job's generated manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlS3GeneratedManifestDescriptor generatedManifestDescriptor;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FJobDescriptor &fromAWS(const Aws::S3Control::Model::JobDescriptor &awsJobDescriptor) {
        this->jobId = UTF8_TO_TCHAR(awsJobDescriptor.GetJobId().c_str());

        this->confirmationRequired = awsJobDescriptor.GetConfirmationRequired();

        this->description = UTF8_TO_TCHAR(awsJobDescriptor.GetDescription().c_str());

        this->jobArn = UTF8_TO_TCHAR(awsJobDescriptor.GetJobArn().c_str());

        switch(awsJobDescriptor.GetStatus()) {
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

        this->manifest.fromAWS(awsJobDescriptor.GetManifest());

        this->operation.fromAWS(awsJobDescriptor.GetOperation());
        
		this->priority = awsJobDescriptor.GetPriority();

		this->progressSummary.fromAWS(awsJobDescriptor.GetProgressSummary());

        this->statusUpdateReason = UTF8_TO_TCHAR(awsJobDescriptor.GetStatusUpdateReason().c_str());

        this->failureReasons.Empty();
        for (const Aws::S3Control::Model::JobFailure& elem : awsJobDescriptor.GetFailureReasons()) {
            this->failureReasons.Add(FJobFailure().fromAWS(elem));
        }

        this->report.fromAWS(awsJobDescriptor.GetReport());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsJobDescriptor.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->terminationDate = FDateTime(1970, 1, 1) + FTimespan(awsJobDescriptor.GetTerminationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->roleArn = UTF8_TO_TCHAR(awsJobDescriptor.GetRoleArn().c_str());

        this->suspendedDate = FDateTime(1970, 1, 1) + FTimespan(awsJobDescriptor.GetSuspendedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->suspendedCause = UTF8_TO_TCHAR(awsJobDescriptor.GetSuspendedCause().c_str());

        this->manifestGenerator.fromAWS(awsJobDescriptor.GetManifestGenerator());

        this->generatedManifestDescriptor.fromAWS(awsJobDescriptor.GetGeneratedManifestDescriptor());

        return *this;
    }
#endif
};
