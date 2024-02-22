/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/BucketLoggingStatus.h"

#endif

#include "Model/LoggingEnabled.h"

#include "BucketLoggingStatus.generated.h"

USTRUCT(BlueprintType)
struct FBucketLoggingStatus {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FLoggingEnabled loggingEnabled;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::BucketLoggingStatus toAWS() const {
        Aws::S3::Model::BucketLoggingStatus awsBucketLoggingStatus;

        if (!(this->loggingEnabled.IsEmpty())) {
            awsBucketLoggingStatus.SetLoggingEnabled(this->loggingEnabled.toAWS());
        }

        return awsBucketLoggingStatus;
    }

    bool IsEmpty() const {
        return this->loggingEnabled.IsEmpty();
    }
#endif
};
