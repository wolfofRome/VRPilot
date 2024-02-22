/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ObjectLambdaContentTransformation.h"

#endif

#include "Model/AWSS3ControlAwsLambdaTransformation.h"

#include "AWSS3ControlObjectLambdaContentTransformation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlObjectLambdaContentTransformation {
GENERATED_BODY()

    /**
    *  <p>A container for an AWS Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAwsLambdaTransformation awsLambda;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ObjectLambdaContentTransformation toAWS() const {
        Aws::S3Control::Model::ObjectLambdaContentTransformation awsObjectLambdaContentTransformation;

        if (!(this->awsLambda.IsEmpty())) {
            awsObjectLambdaContentTransformation.SetAwsLambda(this->awsLambda.toAWS());
        }

        return awsObjectLambdaContentTransformation;
    }

    bool IsEmpty() const {
        return this->awsLambda.IsEmpty();
    }

    FAWSS3ControlObjectLambdaContentTransformation &fromAWS(const Aws::S3Control::Model::ObjectLambdaContentTransformation &awsObjectLambdaContentTransformation) {
        this->awsLambda.fromAWS(awsObjectLambdaContentTransformation.GetAwsLambda());

        return *this;
    }
#endif
};
