/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointForObjectLambdaResult.h"

#endif

#include "Model/S3ControlPublicAccessBlockConfiguration.h"

#include "AWSS3ControlGetAccessPointForObjectLambdaResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetAccessPointForObjectLambdaResult {
GENERATED_BODY()

    /**
    *  <p>The name of the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>Configuration to block all public access. This setting is turned on and can not be edited. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlockConfiguration;

    /**
    *  <p>The date and time when the specified Object Lambda Access Point was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationDate;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetAccessPointForObjectLambdaResult &fromAWS(const Aws::S3Control::Model::GetAccessPointForObjectLambdaResult &awsGetAccessPointForObjectLambdaResult) {
        this->name = UTF8_TO_TCHAR(awsGetAccessPointForObjectLambdaResult.GetName().c_str());

        this->publicAccessBlockConfiguration.fromAWS(awsGetAccessPointForObjectLambdaResult.GetPublicAccessBlockConfiguration());

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsGetAccessPointForObjectLambdaResult.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
