/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketVersioningResult.h"

#endif

#include "Model/BucketVersioningStatus.h"
#include "Model/MFADeleteStatus.h"

#include "GetBucketVersioningResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketVersioningResult {
GENERATED_BODY()

    /**
    *  <p>The versioning state of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketVersioningStatus status = EAWSBucketVersioningStatus::NOT_SET;

    /**
    *  <p>Specifies whether MFA delete is enabled in the bucket versioning configuration. This element is only returned if the bucket has been configured with MFA delete. If the bucket has never been so configured, this element is not returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSMFADeleteStatus mFADelete = EAWSMFADeleteStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketVersioningResult &fromAWS(const Aws::S3::Model::GetBucketVersioningResult &awsGetBucketVersioningResult) {
        switch(awsGetBucketVersioningResult.GetStatus()) {
            case Aws::S3::Model::BucketVersioningStatus::NOT_SET:
                this->status = EAWSBucketVersioningStatus::NOT_SET;
                break;
            case Aws::S3::Model::BucketVersioningStatus::Enabled:
                this->status = EAWSBucketVersioningStatus::Enabled;
                break;
            case Aws::S3::Model::BucketVersioningStatus::Suspended:
                this->status = EAWSBucketVersioningStatus::Suspended;
                break;
            default:
                this->status = EAWSBucketVersioningStatus::NOT_SET;
                break;
        }

        switch(awsGetBucketVersioningResult.GetMFADelete()) {
            case Aws::S3::Model::MFADeleteStatus::NOT_SET:
                this->mFADelete = EAWSMFADeleteStatus::NOT_SET;
                break;
            case Aws::S3::Model::MFADeleteStatus::Enabled:
                this->mFADelete = EAWSMFADeleteStatus::Enabled;
                break;
            case Aws::S3::Model::MFADeleteStatus::Disabled:
                this->mFADelete = EAWSMFADeleteStatus::Disabled;
                break;
            default:
                this->mFADelete = EAWSMFADeleteStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
