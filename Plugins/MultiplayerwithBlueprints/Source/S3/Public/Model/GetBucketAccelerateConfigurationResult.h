/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketAccelerateConfigurationResult.h"

#endif

#include "Model/BucketAccelerateStatus.h"

#include "GetBucketAccelerateConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketAccelerateConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The accelerate configuration of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketAccelerateStatus status = EAWSBucketAccelerateStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketAccelerateConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketAccelerateConfigurationResult &awsGetBucketAccelerateConfigurationResult) {
        switch(awsGetBucketAccelerateConfigurationResult.GetStatus()) {
            case Aws::S3::Model::BucketAccelerateStatus::NOT_SET:
                this->status = EAWSBucketAccelerateStatus::NOT_SET;
                break;
            case Aws::S3::Model::BucketAccelerateStatus::Enabled:
                this->status = EAWSBucketAccelerateStatus::Enabled;
                break;
            case Aws::S3::Model::BucketAccelerateStatus::Suspended:
                this->status = EAWSBucketAccelerateStatus::Suspended;
                break;
            default:
                // @TODO: unimplemented
                this->status = EAWSBucketAccelerateStatus::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
