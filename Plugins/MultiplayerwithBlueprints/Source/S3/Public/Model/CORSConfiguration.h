/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CORSConfiguration.h"

#endif

#include "Model/CORSRule.h"

#include "CORSConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FCORSConfiguration {
GENERATED_BODY()

    /**
    *  <p>A set of origins and methods (cross-origin access that you want to allow). You can add up to 100 rules to the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FCORSRule> cORSRules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CORSConfiguration toAWS() const {
        Aws::S3::Model::CORSConfiguration awsCORSConfiguration;

        for (const FCORSRule& elem : this->cORSRules) {
            awsCORSConfiguration.AddCORSRules(elem.toAWS());
        }

        return awsCORSConfiguration;
    }

    bool IsEmpty() const {
        return this->cORSRules.Num() == 0;
    }
#endif
};
