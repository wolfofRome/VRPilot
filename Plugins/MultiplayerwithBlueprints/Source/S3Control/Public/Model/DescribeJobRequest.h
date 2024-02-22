/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DescribeJobRequest.h"

#endif

#include "DescribeJobRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeJobRequest {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The ID for the job whose information you want to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DescribeJobRequest toAWS() const {
        Aws::S3Control::Model::DescribeJobRequest awsDescribeJobRequest;

		if (!(this->accountId.IsEmpty())) {
            awsDescribeJobRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->jobId.IsEmpty())) {
            awsDescribeJobRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        return awsDescribeJobRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->jobId.IsEmpty();
    }
#endif
};
