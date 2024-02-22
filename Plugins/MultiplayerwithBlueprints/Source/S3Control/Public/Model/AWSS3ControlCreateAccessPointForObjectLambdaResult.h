/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateAccessPointForObjectLambdaResult.h"

#endif

#include "AWSS3ControlCreateAccessPointForObjectLambdaResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateAccessPointForObjectLambdaResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the ARN for the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString objectLambdaAccessPointArn;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlCreateAccessPointForObjectLambdaResult &fromAWS(const Aws::S3Control::Model::CreateAccessPointForObjectLambdaResult &awsCreateAccessPointForObjectLambdaResult) {
        this->objectLambdaAccessPointArn = UTF8_TO_TCHAR(awsCreateAccessPointForObjectLambdaResult.GetObjectLambdaAccessPointArn().c_str());

        return *this;
    }
#endif
};
