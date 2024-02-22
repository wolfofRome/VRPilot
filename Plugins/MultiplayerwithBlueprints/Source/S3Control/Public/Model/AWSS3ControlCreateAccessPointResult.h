/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateAccessPointResult.h"

#endif

#include "AWSS3ControlCreateAccessPointResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateAccessPointResult {
GENERATED_BODY()

    /**
    *  <p>The ARN of the access point.</p>  <p>This is only supported by Amazon S3 on Outposts.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accessPointArn;

    /**
    *  <p>The name or alias of the access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString alias;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlCreateAccessPointResult &fromAWS(const Aws::S3Control::Model::CreateAccessPointResult &awsCreateAccessPointResult) {
        this->accessPointArn = UTF8_TO_TCHAR(awsCreateAccessPointResult.GetAccessPointArn().c_str());

        this->alias = UTF8_TO_TCHAR(awsCreateAccessPointResult.GetAlias().c_str());

        return *this;
    }
#endif
};
