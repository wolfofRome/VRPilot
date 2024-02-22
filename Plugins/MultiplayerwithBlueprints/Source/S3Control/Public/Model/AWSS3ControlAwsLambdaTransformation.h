/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AwsLambdaTransformation.h"

#endif

#include "AWSS3ControlAwsLambdaTransformation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAwsLambdaTransformation {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the AWS Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString functionArn;

    /**
    *  <p>Additional JSON that provides supplemental data to the Lambda function used to transform objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString functionPayload;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::AwsLambdaTransformation toAWS() const {
        Aws::S3Control::Model::AwsLambdaTransformation awsAwsLambdaTransformation;

        if (!(this->functionArn.IsEmpty())) {
            awsAwsLambdaTransformation.SetFunctionArn(TCHAR_TO_UTF8(*this->functionArn));
        }

        if (!(this->functionPayload.IsEmpty())) {
            awsAwsLambdaTransformation.SetFunctionPayload(TCHAR_TO_UTF8(*this->functionPayload));
        }

        return awsAwsLambdaTransformation;
    }

    bool IsEmpty() const {
        return this->functionArn.IsEmpty() && this->functionPayload.IsEmpty();
    }

    FAWSS3ControlAwsLambdaTransformation &fromAWS(const Aws::S3Control::Model::AwsLambdaTransformation &awsAwsLambdaTransformation) {
        this->functionArn = UTF8_TO_TCHAR(awsAwsLambdaTransformation.GetFunctionArn().c_str());

        this->functionPayload = UTF8_TO_TCHAR(awsAwsLambdaTransformation.GetFunctionPayload().c_str());

        return *this;
    }
#endif
};
