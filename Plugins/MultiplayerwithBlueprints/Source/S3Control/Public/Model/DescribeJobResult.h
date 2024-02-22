/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DescribeJobResult.h"

#endif

#include "Model/JobDescriptor.h"

#include "DescribeJobResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeJobResult {
GENERATED_BODY()

    /**
    *  <p>Contains the configuration parameters and status for the job specified in the <code>Describe Job</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobDescriptor job;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:

    FDescribeJobResult &fromAWS(const Aws::S3Control::Model::DescribeJobResult &awsDescribeJobResult) {
        this->job.fromAWS(awsDescribeJobResult.GetJob());

        return *this;
    }
#endif
};
