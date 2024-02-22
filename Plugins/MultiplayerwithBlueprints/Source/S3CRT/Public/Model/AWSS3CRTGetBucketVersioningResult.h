/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketVersioningResult.h"

#endif

#include "Model/AWSS3CRTBucketVersioningStatus.h"
#include "Model/AWSS3CRTMFADeleteStatus.h"

#include "AWSS3CRTGetBucketVersioningResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketVersioningResult {
GENERATED_BODY()
    /**
    *  <p>The versioning state of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketVersioningStatus status = EAWSS3CRTBucketVersioningStatus::NOT_SET;
    /**
    *  <p>Specifies whether MFA delete is enabled in the bucket versioning configuration. This element is only returned if the bucket has been configured with MFA delete. If the bucket has never been so configured, this element is not returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTMFADeleteStatus mFADelete = EAWSS3CRTMFADeleteStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketVersioningResult &fromAWS(const Aws::S3Crt::Model::GetBucketVersioningResult &awsGetBucketVersioningResult) {
        switch(awsGetBucketVersioningResult.GetStatus()) {
            case Aws::S3Crt::Model::BucketVersioningStatus::NOT_SET:
                this->status = EAWSS3CRTBucketVersioningStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::BucketVersioningStatus::Enabled:
                this->status = EAWSS3CRTBucketVersioningStatus::Enabled;
                break;
            case Aws::S3Crt::Model::BucketVersioningStatus::Suspended:
                this->status = EAWSS3CRTBucketVersioningStatus::Suspended;
                break;
            default:
                this->status = EAWSS3CRTBucketVersioningStatus::NOT_SET;
                break;
        }

        switch(awsGetBucketVersioningResult.GetMFADelete()) {
            case Aws::S3Crt::Model::MFADeleteStatus::NOT_SET:
                this->mFADelete = EAWSS3CRTMFADeleteStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::MFADeleteStatus::Enabled:
                this->mFADelete = EAWSS3CRTMFADeleteStatus::Enabled;
                break;
            case Aws::S3Crt::Model::MFADeleteStatus::Disabled:
                this->mFADelete = EAWSS3CRTMFADeleteStatus::Disabled;
                break;
            default:
                this->mFADelete = EAWSS3CRTMFADeleteStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
