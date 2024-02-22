/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobFailure.h"

#endif

#include "JobFailure.generated.h"

USTRUCT(BlueprintType)
struct FJobFailure {
GENERATED_BODY()

    /**
    *  <p>The failure code, if any, for the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString failureCode;

    /**
    *  <p>The failure reason, if any, for the specified job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString failureReason;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FJobFailure &fromAWS(const Aws::S3Control::Model::JobFailure &awsJobFailure) {
        this->failureCode = UTF8_TO_TCHAR(awsJobFailure.GetFailureCode().c_str());

        this->failureReason = UTF8_TO_TCHAR(awsJobFailure.GetFailureReason().c_str());

        return *this;
    }
#endif
};
