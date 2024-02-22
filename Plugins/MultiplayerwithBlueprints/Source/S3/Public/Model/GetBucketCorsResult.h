/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketCorsResult.h"

#endif

#include "Model/CORSRule.h"

#include "GetBucketCorsResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketCorsResult {
GENERATED_BODY()

    /**
    *  <p>A set of origins and methods (cross-origin access that you want to allow). You can add up to 100 rules to the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FCORSRule> cORSRules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketCorsResult &fromAWS(const Aws::S3::Model::GetBucketCorsResult &awsGetBucketCorsResult) {
        this->cORSRules.Empty();
        for (const Aws::S3::Model::CORSRule& elem : awsGetBucketCorsResult.GetCORSRules()) {
            this->cORSRules.Add(FCORSRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
