/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/BucketLifecycleConfiguration.h"

#endif

#include "Model/LifecycleRule.h"

#include "BucketLifecycleConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FBucketLifecycleConfiguration {
GENERATED_BODY()

    /**
    *  <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FLifecycleRule> rules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::BucketLifecycleConfiguration toAWS() const {
        Aws::S3::Model::BucketLifecycleConfiguration awsBucketLifecycleConfiguration;

        for (const FLifecycleRule& elem : this->rules) {
            awsBucketLifecycleConfiguration.AddRules(elem.toAWS());
        }

        return awsBucketLifecycleConfiguration;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }
#endif
};
