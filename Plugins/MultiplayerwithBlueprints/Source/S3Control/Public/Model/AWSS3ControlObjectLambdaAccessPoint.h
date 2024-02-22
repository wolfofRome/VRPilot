/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ObjectLambdaAccessPoint.h"

#endif

#include "AWSS3ControlObjectLambdaAccessPoint.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlObjectLambdaAccessPoint {
GENERATED_BODY()

    /**
    *  <p>The name of the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>Specifies the ARN for the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString objectLambdaAccessPointArn;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlObjectLambdaAccessPoint &fromAWS(const Aws::S3Control::Model::ObjectLambdaAccessPoint &awsObjectLambdaAccessPoint) {
        this->name = UTF8_TO_TCHAR(awsObjectLambdaAccessPoint.GetName().c_str());

        this->objectLambdaAccessPointArn = UTF8_TO_TCHAR(awsObjectLambdaAccessPoint.GetObjectLambdaAccessPointArn().c_str());

        return *this;
    }
#endif
};
