/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DescribeMultiRegionAccessPointOperationRequest.h"

#endif

#include "AWSS3ControlDescribeMultiRegionAccessPointOperationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDescribeMultiRegionAccessPointOperationRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the owner of the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The request token associated with the request you want to know about. This request token is returned as part of the response when you make an asynchronous request. You provide this token to query about the status of the asynchronous action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString requestTokenARN;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DescribeMultiRegionAccessPointOperationRequest toAWS() const {
        Aws::S3Control::Model::DescribeMultiRegionAccessPointOperationRequest awsDescribeMultiRegionAccessPointOperationRequest;

        if (!(this->accountId.IsEmpty())) {
            awsDescribeMultiRegionAccessPointOperationRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->requestTokenARN.IsEmpty())) {
            awsDescribeMultiRegionAccessPointOperationRequest.SetRequestTokenARN(TCHAR_TO_UTF8(*this->requestTokenARN));
        }

        return awsDescribeMultiRegionAccessPointOperationRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->requestTokenARN.IsEmpty();
    }
#endif
};
