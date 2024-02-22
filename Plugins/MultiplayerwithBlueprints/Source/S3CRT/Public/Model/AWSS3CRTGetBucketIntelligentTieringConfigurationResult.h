/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketIntelligentTieringConfigurationResult.h"

#endif

#include "Model/AWSS3CRTIntelligentTieringConfiguration.h"

#include "AWSS3CRTGetBucketIntelligentTieringConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketIntelligentTieringConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Container for S3 Intelligent-Tiering configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTIntelligentTieringConfiguration intelligentTieringConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketIntelligentTieringConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketIntelligentTieringConfigurationResult &awsGetBucketIntelligentTieringConfigurationResult) {
        this->intelligentTieringConfiguration = FAWSS3CRTIntelligentTieringConfiguration().fromAWS(awsGetBucketIntelligentTieringConfigurationResult.GetIntelligentTieringConfiguration());

        return *this;
    }
#endif
};
