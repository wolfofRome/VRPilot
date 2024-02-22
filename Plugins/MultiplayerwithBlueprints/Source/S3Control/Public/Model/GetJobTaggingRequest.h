/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetJobTaggingRequest.h"

#endif

#include "GetJobTaggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetJobTaggingRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID associated with the Amazon S3 Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The ID for the Amazon S3 Batch Operations job whose tags you want to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetJobTaggingRequest toAWS() const {
        Aws::S3Control::Model::GetJobTaggingRequest awsGetJobTaggingRequest;

		if (!(this->accountId.IsEmpty())) {
            awsGetJobTaggingRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->jobId.IsEmpty())) {
            awsGetJobTaggingRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        return awsGetJobTaggingRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->jobId.IsEmpty();
    }
#endif
};
