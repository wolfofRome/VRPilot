/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutMultiRegionAccessPointPolicyResult.h"

#endif

#include "AWSS3ControlPutMultiRegionAccessPointPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutMultiRegionAccessPointPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The request token associated with the request. You can use this token with <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeMultiRegionAccessPointOperation.html">DescribeMultiRegionAccessPointOperation</a> to determine the status of asynchronous requests.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString requestTokenARN;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlPutMultiRegionAccessPointPolicyResult &fromAWS(const Aws::S3Control::Model::PutMultiRegionAccessPointPolicyResult &awsPutMultiRegionAccessPointPolicyResult) {
        this->requestTokenARN = UTF8_TO_TCHAR(awsPutMultiRegionAccessPointPolicyResult.GetRequestTokenARN().c_str());

        return *this;
    }
#endif
};
