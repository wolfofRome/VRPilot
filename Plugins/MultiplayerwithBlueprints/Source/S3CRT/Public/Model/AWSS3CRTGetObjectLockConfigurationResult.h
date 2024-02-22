/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetObjectLockConfigurationResult.h"

#endif

#include "Model/AWSS3CRTObjectLockConfiguration.h"

#include "AWSS3CRTGetObjectLockConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectLockConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The specified bucket's Object Lock configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTObjectLockConfiguration objectLockConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectLockConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetObjectLockConfigurationResult &awsGetObjectLockConfigurationResult) {
        this->objectLockConfiguration = FAWSS3CRTObjectLockConfiguration().fromAWS(awsGetObjectLockConfigurationResult.GetObjectLockConfiguration());

        return *this;
    }
#endif
};
