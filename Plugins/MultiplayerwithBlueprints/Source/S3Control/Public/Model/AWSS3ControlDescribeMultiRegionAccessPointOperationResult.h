/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DescribeMultiRegionAccessPointOperationResult.h"

#endif

#include "Model/AWSS3ControlAsyncOperation.h"

#include "AWSS3ControlDescribeMultiRegionAccessPointOperationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDescribeMultiRegionAccessPointOperationResult {
GENERATED_BODY()

    /**
    *  <p>A container element containing the details of the asynchronous operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAsyncOperation asyncOperation;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlDescribeMultiRegionAccessPointOperationResult &fromAWS(const Aws::S3Control::Model::DescribeMultiRegionAccessPointOperationResult &awsDescribeMultiRegionAccessPointOperationResult) {
        this->asyncOperation.fromAWS(awsDescribeMultiRegionAccessPointOperationResult.GetAsyncOperation());

        return *this;
    }
#endif
};
