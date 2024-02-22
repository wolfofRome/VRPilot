/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/BucketLoggingStatus.h"

#endif

#include "Model/AWSS3CRTLoggingEnabled.h"

#include "AWSS3CRTBucketLoggingStatus.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTBucketLoggingStatus {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTLoggingEnabled loggingEnabled;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::BucketLoggingStatus toAWS() const {
        Aws::S3Crt::Model::BucketLoggingStatus awsBucketLoggingStatus;

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
