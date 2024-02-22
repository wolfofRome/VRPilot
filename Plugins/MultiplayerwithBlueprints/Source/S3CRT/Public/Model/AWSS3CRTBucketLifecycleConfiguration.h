/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/BucketLifecycleConfiguration.h"

#endif

#include "Model/AWSS3CRTLifecycleRule.h"

#include "AWSS3CRTBucketLifecycleConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTBucketLifecycleConfiguration {
GENERATED_BODY()

    /**
    *  <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTLifecycleRule> rules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::BucketLifecycleConfiguration toAWS() const {
        Aws::S3Crt::Model::BucketLifecycleConfiguration awsBucketLifecycleConfiguration;

        for (const FAWSS3CRTLifecycleRule& elem : this->rules) {
            awsBucketLifecycleConfiguration.AddRules(elem.toAWS());
        }

        return awsBucketLifecycleConfiguration;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }
#endif
};
