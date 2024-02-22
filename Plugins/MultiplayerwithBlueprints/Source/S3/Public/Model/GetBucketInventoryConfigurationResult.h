/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketInventoryConfigurationResult.h"

#endif

#include "Model/InventoryConfiguration.h"

#include "GetBucketInventoryConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketInventoryConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the inventory configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInventoryConfiguration inventoryConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketInventoryConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketInventoryConfigurationResult &awsGetBucketInventoryConfigurationResult) {
        this->inventoryConfiguration.fromAWS(awsGetBucketInventoryConfigurationResult.GetInventoryConfiguration());

        return *this;
    }
#endif
};
