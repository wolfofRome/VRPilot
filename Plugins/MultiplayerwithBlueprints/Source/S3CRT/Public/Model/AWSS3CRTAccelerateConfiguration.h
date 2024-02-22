/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AccelerateConfiguration.h"

#endif

#include "Model/AWSS3CRTBucketAccelerateStatus.h"

#include "AWSS3CRTAccelerateConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAccelerateConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies the transfer acceleration status of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketAccelerateStatus status = EAWSS3CRTBucketAccelerateStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AccelerateConfiguration toAWS() const {
        Aws::S3Crt::Model::AccelerateConfiguration awsAccelerateConfiguration;

        switch(this->status) {
            case EAWSS3CRTBucketAccelerateStatus::Enabled:
                awsAccelerateConfiguration.SetStatus(Aws::S3Crt::Model::BucketAccelerateStatus::Enabled);
                break;
            case EAWSS3CRTBucketAccelerateStatus::Suspended:
                awsAccelerateConfiguration.SetStatus(Aws::S3Crt::Model::BucketAccelerateStatus::Suspended);
                break;
            default:
                break;
        }

        return awsAccelerateConfiguration;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3CRTBucketAccelerateStatus::NOT_SET;
    }
#endif
};
