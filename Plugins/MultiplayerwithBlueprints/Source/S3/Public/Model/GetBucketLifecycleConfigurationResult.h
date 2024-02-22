/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketLifecycleConfigurationResult.h"

#endif

#include "Model/LifecycleRule.h"

#include "GetBucketLifecycleConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketLifecycleConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Container for a lifecycle rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FLifecycleRule> rules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketLifecycleConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketLifecycleConfigurationResult &awsGetBucketLifecycleConfigurationResult) {
        this->rules.Empty();
        for (const Aws::S3::Model::LifecycleRule& elem : awsGetBucketLifecycleConfigurationResult.GetRules()) {
            this->rules.Add(FLifecycleRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
