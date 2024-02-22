/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketLifecycleConfigurationResult.h"

#endif

#include "Model/AWSS3CRTLifecycleRule.h"

#include "AWSS3CRTGetBucketLifecycleConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketLifecycleConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Container for a lifecycle rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTLifecycleRule> rules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketLifecycleConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketLifecycleConfigurationResult &awsGetBucketLifecycleConfigurationResult) {
        this->rules.Empty();
        for (const Aws::S3Crt::Model::LifecycleRule& elem : awsGetBucketLifecycleConfigurationResult.GetRules()) {
            this->rules.Add(FAWSS3CRTLifecycleRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
