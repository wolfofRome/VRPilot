/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketAccelerateConfigurationResult.h"

#endif

#include "Model/AWSS3CRTBucketAccelerateStatus.h"

#include "AWSS3CRTGetBucketAccelerateConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketAccelerateConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The accelerate configuration of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketAccelerateStatus status = EAWSS3CRTBucketAccelerateStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketAccelerateConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketAccelerateConfigurationResult &awsGetBucketAccelerateConfigurationResult) {
        switch(awsGetBucketAccelerateConfigurationResult.GetStatus()) {
            case Aws::S3Crt::Model::BucketAccelerateStatus::NOT_SET:
                this->status = EAWSS3CRTBucketAccelerateStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::BucketAccelerateStatus::Enabled:
                this->status = EAWSS3CRTBucketAccelerateStatus::Enabled;
                break;
            case Aws::S3Crt::Model::BucketAccelerateStatus::Suspended:
                this->status = EAWSS3CRTBucketAccelerateStatus::Suspended;
                break;
            default:
                this->status = EAWSS3CRTBucketAccelerateStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
