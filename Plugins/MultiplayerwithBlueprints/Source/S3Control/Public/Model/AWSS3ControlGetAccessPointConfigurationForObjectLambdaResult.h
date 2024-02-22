/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointConfigurationForObjectLambdaResult.h"

#endif

#include "Model/AWSS3ControlObjectLambdaConfiguration.h"

#include "AWSS3ControlGetAccessPointConfigurationForObjectLambdaResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointConfigurationForObjectLambdaResult {
GENERATED_BODY()

    /**
    *  <p>Object Lambda Access Point configuration document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlObjectLambdaConfiguration configuration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetAccessPointConfigurationForObjectLambdaResult &fromAWS(const Aws::S3Control::Model::GetAccessPointConfigurationForObjectLambdaResult &awsGetAccessPointConfigurationForObjectLambdaResult) {
        this->configuration.fromAWS(awsGetAccessPointConfigurationForObjectLambdaResult.GetConfiguration());

        return *this;
    }
#endif
};
