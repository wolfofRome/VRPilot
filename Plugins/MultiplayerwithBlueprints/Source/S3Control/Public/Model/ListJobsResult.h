/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListJobsResult.h"

#endif

#include "Model/JobListDescriptor.h"

#include "ListJobsResult.generated.h"

USTRUCT(BlueprintType)
struct FListJobsResult {
GENERATED_BODY()

    /**
    *  <p>If the <code>List Jobs</code> request produced more than the maximum number of results, you can pass this value into a subsequent <code>List Jobs</code> request in order to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p>The list of current jobs and jobs that have ended within the last 30 days.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FJobListDescriptor> jobs;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FListJobsResult &fromAWS(const Aws::S3Control::Model::ListJobsResult &awsListJobsResult) {
        this->nextToken = UTF8_TO_TCHAR(awsListJobsResult.GetNextToken().c_str());

        this->jobs.Empty();
        for (const Aws::S3Control::Model::JobListDescriptor& elem : awsListJobsResult.GetJobs()) {
            this->jobs.Add(FJobListDescriptor().fromAWS(elem));
        }

        return *this;
    }
#endif
};
