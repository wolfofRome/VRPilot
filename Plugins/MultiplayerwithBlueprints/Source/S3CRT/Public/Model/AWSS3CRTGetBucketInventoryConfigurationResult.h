/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketInventoryConfigurationResult.h"

#endif

#include "Model/AWSS3CRTInventoryConfiguration.h"

#include "AWSS3CRTGetBucketInventoryConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketInventoryConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the inventory configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInventoryConfiguration inventoryConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketInventoryConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketInventoryConfigurationResult &awsGetBucketInventoryConfigurationResult) {
        this->inventoryConfiguration = FAWSS3CRTInventoryConfiguration().fromAWS(awsGetBucketInventoryConfigurationResult.GetInventoryConfiguration());

        return *this;
    }
#endif
};
