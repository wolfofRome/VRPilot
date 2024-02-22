/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/EventBridgeConfiguration.h"

#endif

#include "AWSS3EventBridgeConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3EventBridgeConfiguration {
GENERATED_BODY()

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::EventBridgeConfiguration toAWS() const {
        Aws::S3::Model::EventBridgeConfiguration awsEventBridgeConfiguration;

        return awsEventBridgeConfiguration;
    }

    bool IsEmpty() const {
        return true;
    }

    FAWSS3EventBridgeConfiguration &fromAWS(const Aws::S3::Model::EventBridgeConfiguration &awsEventBridgeConfiguration) {
        return *this;
    }
#endif
};
