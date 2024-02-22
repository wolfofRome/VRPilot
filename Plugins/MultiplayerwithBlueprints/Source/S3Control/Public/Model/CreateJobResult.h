/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateJobResult.h"

#endif

#include "CreateJobResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateJobResult {
GENERATED_BODY()

    /**
    *  <p>The ID for this job. Amazon S3 generates this ID automatically and returns it after a successful <code>Create Job</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FCreateJobResult &fromAWS(const Aws::S3Control::Model::CreateJobResult &awsCreateJobResult) {
        this->jobId = UTF8_TO_TCHAR(awsCreateJobResult.GetJobId().c_str());

        return *this;
    }
#endif
};
