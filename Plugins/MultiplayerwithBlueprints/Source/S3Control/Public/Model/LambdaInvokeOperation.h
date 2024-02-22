/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/LambdaInvokeOperation.h"

#endif

#include "LambdaInvokeOperation.generated.h"

USTRUCT(BlueprintType)
struct FLambdaInvokeOperation {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for the AWS Lambda function that the specified job will invoke for each object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString functionArn;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::LambdaInvokeOperation toAWS() const {
        Aws::S3Control::Model::LambdaInvokeOperation awsLambdaInvokeOperation;

		if (!(this->functionArn.IsEmpty())) {
            awsLambdaInvokeOperation.SetFunctionArn(TCHAR_TO_UTF8(*this->functionArn));
        }

        return awsLambdaInvokeOperation;
    }

    bool IsEmpty() const {
        return this->functionArn.IsEmpty();
    }

    FLambdaInvokeOperation &fromAWS(const Aws::S3Control::Model::LambdaInvokeOperation &awsLambdaInvokeOperation) {
        this->functionArn = UTF8_TO_TCHAR(awsLambdaInvokeOperation.GetFunctionArn().c_str());

        return *this;
    }
#endif
};
