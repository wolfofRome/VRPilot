/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/LifecycleConfiguration.h"

#endif

#include "Model/AWSS3ControlLifecycleRule.h"

#include "AWSS3ControlLifecycleConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlLifecycleConfiguration {
GENERATED_BODY()
    /**
    *  <p>A lifecycle rule for individual objects in an Outposts bucket. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlLifecycleRule> rules;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::LifecycleConfiguration toAWS() const {
        Aws::S3Control::Model::LifecycleConfiguration awsLifecycleConfiguration;

        for (const FAWSS3ControlLifecycleRule& elem : this->rules) {
            awsLifecycleConfiguration.AddRules(elem.toAWS());
        }

        return awsLifecycleConfiguration;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }
#endif
};
