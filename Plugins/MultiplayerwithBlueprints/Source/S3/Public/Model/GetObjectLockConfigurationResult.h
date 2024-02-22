/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectLockConfigurationResult.h"

#endif

#include "Model/ObjectLockConfiguration.h"

#include "GetObjectLockConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectLockConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The specified bucket's Object Lock configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FObjectLockConfiguration objectLockConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectLockConfigurationResult &fromAWS(const Aws::S3::Model::GetObjectLockConfigurationResult &awsGetObjectLockConfigurationResult) {
        this->objectLockConfiguration.fromAWS(awsGetObjectLockConfigurationResult.GetObjectLockConfiguration());

        return *this;
    }
#endif
};
