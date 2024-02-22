/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketLifecycleConfigurationResult.h"

#endif

#include "Model/AWSS3ControlLifecycleRule.h"

#include "AWSS3ControlGetBucketLifecycleConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketLifecycleConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Container for the lifecycle rule of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlLifecycleRule> rules;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetBucketLifecycleConfigurationResult &fromAWS(const Aws::S3Control::Model::GetBucketLifecycleConfigurationResult &awsGetBucketLifecycleConfigurationResult) {
        this->rules.Empty();
        for (const Aws::S3Control::Model::LifecycleRule& elem : awsGetBucketLifecycleConfigurationResult.GetRules()) {
            this->rules.Add(FAWSS3ControlLifecycleRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
