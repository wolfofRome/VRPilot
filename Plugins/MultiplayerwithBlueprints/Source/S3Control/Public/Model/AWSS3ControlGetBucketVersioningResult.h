/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketVersioningResult.h"

#endif

#include "Model/AWSS3ControlBucketVersioningStatus.h"
#include "Model/AWSS3ControlMFADeleteStatus.h"

#include "AWSS3ControlGetBucketVersioningResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketVersioningResult {
GENERATED_BODY()

    /**
    *  <p>The versioning state of the S3 on Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlBucketVersioningStatus status = EAWSS3ControlBucketVersioningStatus::NOT_SET;

    /**
    *  <p>Specifies whether MFA delete is enabled in the bucket versioning configuration. This element is returned only if the bucket has been configured with MFA delete. If MFA delete has never been configured for the bucket, this element is not returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlMFADeleteStatus mFADelete = EAWSS3ControlMFADeleteStatus::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetBucketVersioningResult &fromAWS(const Aws::S3Control::Model::GetBucketVersioningResult &awsGetBucketVersioningResult) {
        switch(awsGetBucketVersioningResult.GetStatus()) {
            case Aws::S3Control::Model::BucketVersioningStatus::NOT_SET:
                this->status = EAWSS3ControlBucketVersioningStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::BucketVersioningStatus::Enabled:
                this->status = EAWSS3ControlBucketVersioningStatus::Enabled;
                break;
            case Aws::S3Control::Model::BucketVersioningStatus::Suspended:
                this->status = EAWSS3ControlBucketVersioningStatus::Suspended;
                break;
            default:
                this->status = EAWSS3ControlBucketVersioningStatus::NOT_SET;
                break;
        }

        switch(awsGetBucketVersioningResult.GetMFADelete()) {
            case Aws::S3Control::Model::MFADeleteStatus::NOT_SET:
                this->mFADelete = EAWSS3ControlMFADeleteStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::MFADeleteStatus::Enabled:
                this->mFADelete = EAWSS3ControlMFADeleteStatus::Enabled;
                break;
            case Aws::S3Control::Model::MFADeleteStatus::Disabled:
                this->mFADelete = EAWSS3ControlMFADeleteStatus::Disabled;
                break;
            default:
                this->mFADelete = EAWSS3ControlMFADeleteStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
