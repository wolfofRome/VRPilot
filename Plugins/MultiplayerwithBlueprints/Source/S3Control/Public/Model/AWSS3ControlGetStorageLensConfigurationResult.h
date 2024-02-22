/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetStorageLensConfigurationResult.h"

#endif

#include "Model/AWSS3ControlStorageLensConfiguration.h"

#include "AWSS3ControlGetStorageLensConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetStorageLensConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The S3 Storage Lens configuration requested.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlStorageLensConfiguration storageLensConfiguration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetStorageLensConfigurationResult &fromAWS(const Aws::S3Control::Model::GetStorageLensConfigurationResult &awsGetStorageLensConfigurationResult) {
        this->storageLensConfiguration.fromAWS(awsGetStorageLensConfigurationResult.GetStorageLensConfiguration());

        return *this;
    }
#endif
};
