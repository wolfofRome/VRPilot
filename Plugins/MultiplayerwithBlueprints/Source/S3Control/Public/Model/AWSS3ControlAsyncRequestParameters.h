/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AsyncRequestParameters.h"

#endif

#include "Model/AWSS3ControlCreateMultiRegionAccessPointInput.h"
#include "Model/AWSS3ControlDeleteMultiRegionAccessPointInput.h"
#include "Model/AWSS3ControlPutMultiRegionAccessPointPolicyInput.h"

#include "AWSS3ControlAsyncRequestParameters.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAsyncRequestParameters {
GENERATED_BODY()

    /**
    *  <p>A container of the parameters for a <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateMultiRegionAccessPoint.html">CreateMultiRegionAccessPoint</a> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlCreateMultiRegionAccessPointInput createMultiRegionAccessPointRequest;

    /**
    *  <p>A container of the parameters for a <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteMultiRegionAccessPoint.html">DeleteMultiRegionAccessPoint</a> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlDeleteMultiRegionAccessPointInput deleteMultiRegionAccessPointRequest;

    /**
    *  <p>A container of the parameters for a <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutMultiRegionAccessPoint.html">PutMultiRegionAccessPoint</a> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlPutMultiRegionAccessPointPolicyInput putMultiRegionAccessPointPolicyRequest;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlAsyncRequestParameters &fromAWS(const Aws::S3Control::Model::AsyncRequestParameters &awsAsyncRequestParameters) {
        this->createMultiRegionAccessPointRequest.fromAWS(awsAsyncRequestParameters.GetCreateMultiRegionAccessPointRequest());

        this->deleteMultiRegionAccessPointRequest.fromAWS(awsAsyncRequestParameters.GetDeleteMultiRegionAccessPointRequest());

        this->putMultiRegionAccessPointPolicyRequest.fromAWS(awsAsyncRequestParameters.GetPutMultiRegionAccessPointPolicyRequest());

        return *this;
    }
#endif
};
