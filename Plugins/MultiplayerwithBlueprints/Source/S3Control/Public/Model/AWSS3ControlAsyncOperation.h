/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AsyncOperation.h"

#endif

#include "Model/AWSS3ControlAsyncOperationName.h"
#include "Model/AWSS3ControlAsyncRequestParameters.h"
#include "Model/AWSS3ControlAsyncResponseDetails.h"

#include "AWSS3ControlAsyncOperation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAsyncOperation {
GENERATED_BODY()

    /**
    *  <p>The time that the request was sent to the service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationTime;

    /**
    *  <p>The specific operation for the asynchronous request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlAsyncOperationName operation = EAWSS3ControlAsyncOperationName::NOT_SET;

    /**
    *  <p>The request token associated with the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString requestTokenARN;

    /**
    *  <p>The parameters associated with the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAsyncRequestParameters requestParameters;

    /**
    *  <p>The current status of the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString requestStatus;

    /**
    *  <p>The details of the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAsyncResponseDetails responseDetails;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlAsyncOperation &fromAWS(const Aws::S3Control::Model::AsyncOperation &awsAsyncOperation) {
        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsAsyncOperation.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsAsyncOperation.GetOperation()) {
            case Aws::S3Control::Model::AsyncOperationName::NOT_SET:
                this->operation = EAWSS3ControlAsyncOperationName::NOT_SET;
                break;
            case Aws::S3Control::Model::AsyncOperationName::CreateMultiRegionAccessPoint:
                this->operation = EAWSS3ControlAsyncOperationName::CreateMultiRegionAccessPoint;
                break;
            case Aws::S3Control::Model::AsyncOperationName::DeleteMultiRegionAccessPoint:
                this->operation = EAWSS3ControlAsyncOperationName::DeleteMultiRegionAccessPoint;
                break;
            case Aws::S3Control::Model::AsyncOperationName::PutMultiRegionAccessPointPolicy:
                this->operation = EAWSS3ControlAsyncOperationName::PutMultiRegionAccessPointPolicy;
                break;
            default:
                this->operation = EAWSS3ControlAsyncOperationName::NOT_SET;
                break;
        }

        this->requestTokenARN = UTF8_TO_TCHAR(awsAsyncOperation.GetRequestTokenARN().c_str());

        this->requestParameters.fromAWS(awsAsyncOperation.GetRequestParameters());

        this->requestStatus = UTF8_TO_TCHAR(awsAsyncOperation.GetRequestStatus().c_str());

        this->responseDetails.fromAWS(awsAsyncOperation.GetResponseDetails());

        return *this;
    }
#endif
};
