/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListJobsRequest.h"

#endif

#include "Model/JobStatus.h"

#include "ListJobsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListJobsRequest {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The <code>List Jobs</code> request returns jobs that match the statuses listed in this element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<EAWSJobStatus> jobStatuses;

    /**
    *  <p>A pagination token to request the next page of results. Use the token that Amazon S3 returned in the <code>NextToken</code> element of the <code>ListJobsResult</code> from the previous <code>List Jobs</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p>The maximum number of jobs that Amazon S3 will include in the <code>List Jobs</code> response. If there are more jobs than this number, the response will include a pagination token in the <code>NextToken</code> field to enable you to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int maxResults = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ListJobsRequest toAWS() const {
        Aws::S3Control::Model::ListJobsRequest awsListJobsRequest;

		if (!(this->accountId.IsEmpty())) {
            awsListJobsRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        for (const EAWSJobStatus& elem : this->jobStatuses) {
		    switch(elem) {
                case EAWSJobStatus::Active:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Active);
                    break;
                case EAWSJobStatus::Cancelled:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Cancelled);
                    break;
                case EAWSJobStatus::Cancelling:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Cancelling);
                    break;
                case EAWSJobStatus::Complete:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Complete);
                    break;
                case EAWSJobStatus::Completing:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Completing);
                    break;
                case EAWSJobStatus::Failed:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Failed);
                    break;
                case EAWSJobStatus::Failing:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Failing);
                    break;
                case EAWSJobStatus::New:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::New);
                    break;
                case EAWSJobStatus::Paused:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Paused);
                    break;
                case EAWSJobStatus::Pausing:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Pausing);
                    break;
                case EAWSJobStatus::Preparing:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Preparing);
                    break;
                case EAWSJobStatus::Ready:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Ready);
                    break;
                case EAWSJobStatus::Suspended:
                    awsListJobsRequest.AddJobStatuses(Aws::S3Control::Model::JobStatus::Suspended);
                    break;
                default:
                    break;
            };
        }

		if (!(this->nextToken.IsEmpty())) {
            awsListJobsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListJobsRequest.SetMaxResults(this->maxResults);
        }

        return awsListJobsRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->jobStatuses.Num() == 0 && this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
