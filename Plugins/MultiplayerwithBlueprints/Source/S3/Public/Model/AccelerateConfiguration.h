/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AccelerateConfiguration.h"

#endif

#include "Model/BucketAccelerateStatus.h"

#include "AccelerateConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAccelerateConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies the transfer acceleration status of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketAccelerateStatus status = EAWSBucketAccelerateStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AccelerateConfiguration toAWS() const {
        Aws::S3::Model::AccelerateConfiguration awsAccelerateConfiguration;

        switch(this->status) {
            case EAWSBucketAccelerateStatus::Enabled:
                awsAccelerateConfiguration.SetStatus(Aws::S3::Model::BucketAccelerateStatus::Enabled);
                break;
            case EAWSBucketAccelerateStatus::Suspended:
                awsAccelerateConfiguration.SetStatus(Aws::S3::Model::BucketAccelerateStatus::Suspended);
                break;
            default:
                break;
        }

        return awsAccelerateConfiguration;
    }

    bool IsEmpty() const {
        return status == EAWSBucketAccelerateStatus::NOT_SET;
    }
#endif
};
