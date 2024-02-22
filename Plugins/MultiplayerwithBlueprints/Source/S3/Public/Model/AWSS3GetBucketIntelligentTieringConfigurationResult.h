/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketIntelligentTieringConfigurationResult.h"

#endif

#include "Model/AWSS3IntelligentTieringConfiguration.h"

#include "AWSS3GetBucketIntelligentTieringConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3GetBucketIntelligentTieringConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Container for S3 Intelligent-Tiering configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3IntelligentTieringConfiguration intelligentTieringConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FAWSS3GetBucketIntelligentTieringConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketIntelligentTieringConfigurationResult &awsGetBucketIntelligentTieringConfigurationResult) {
        this->intelligentTieringConfiguration.fromAWS(awsGetBucketIntelligentTieringConfigurationResult.GetIntelligentTieringConfiguration());

        return *this;
    }
#endif
};
