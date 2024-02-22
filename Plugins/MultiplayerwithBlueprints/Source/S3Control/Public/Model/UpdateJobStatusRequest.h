/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/UpdateJobStatusRequest.h"

#endif

#include "Model/RequestedJobStatus.h"

#include "UpdateJobStatusRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateJobStatusRequest {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The ID of the job whose status you want to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>The status that you want to move the specified job to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSRequestedJobStatus requestedJobStatus = EAWSRequestedJobStatus::NOT_SET;

    /**
    *  <p>A description of the reason why you want to change the specified job's status. This field can be any string up to the maximum length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString statusUpdateReason;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::UpdateJobStatusRequest toAWS() const {
        Aws::S3Control::Model::UpdateJobStatusRequest awsUpdateJobStatusRequest;

		if (!(this->accountId.IsEmpty())) {
            awsUpdateJobStatusRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->jobId.IsEmpty())) {
            awsUpdateJobStatusRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        switch(this->requestedJobStatus) {
            case EAWSRequestedJobStatus::Cancelled:
                awsUpdateJobStatusRequest.SetRequestedJobStatus(Aws::S3Control::Model::RequestedJobStatus::Cancelled);
                break;
            case EAWSRequestedJobStatus::Ready:
                awsUpdateJobStatusRequest.SetRequestedJobStatus(Aws::S3Control::Model::RequestedJobStatus::Ready);
                break;
            default:
                break;
		}

		if (!(this->statusUpdateReason.IsEmpty())) {
            awsUpdateJobStatusRequest.SetStatusUpdateReason(TCHAR_TO_UTF8(*this->statusUpdateReason));
        }

        return awsUpdateJobStatusRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->jobId.IsEmpty() && requestedJobStatus == EAWSRequestedJobStatus::NOT_SET && this->statusUpdateReason.IsEmpty();
    }
#endif
};
