/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketCorsResult.h"

#endif

#include "Model/AWSS3CRTCORSRule.h"

#include "AWSS3CRTGetBucketCorsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketCorsResult {
GENERATED_BODY()

    /**
    *  <p>A set of origins and methods (cross-origin access that you want to allow). You can add up to 100 rules to the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTCORSRule> cORSRules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketCorsResult &fromAWS(const Aws::S3Crt::Model::GetBucketCorsResult &awsGetBucketCorsResult) {
        this->cORSRules.Empty();
        for (const Aws::S3Crt::Model::CORSRule& elem : awsGetBucketCorsResult.GetCORSRules()) {
            this->cORSRules.Add(FAWSS3CRTCORSRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
