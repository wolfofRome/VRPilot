/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CORSConfiguration.h"

#endif

#include "Model/AWSS3CRTCORSRule.h"

#include "AWSS3CRTCORSConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCORSConfiguration {
GENERATED_BODY()

    /**
    *  <p>A set of origins and methods (cross-origin access that you want to allow). You can add up to 100 rules to the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTCORSRule> cORSRules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CORSConfiguration toAWS() const {
        Aws::S3Crt::Model::CORSConfiguration awsCORSConfiguration;

        for (const FAWSS3CRTCORSRule& elem : this->cORSRules) {
            awsCORSConfiguration.AddCORSRules(elem.toAWS());
        }

        return awsCORSConfiguration;
    }

    bool IsEmpty() const {
        return this->cORSRules.Num() == 0;
    }
#endif
};
