/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/VersioningConfiguration.h"

#endif

#include "Model/AWSS3ControlMFADelete.h"
#include "Model/AWSS3ControlBucketVersioningStatus.h"

#include "AWSS3ControlVersioningConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlVersioningConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies whether MFA delete is enabled or disabled in the bucket versioning configuration for the S3 on Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlMFADelete mFADelete = EAWSS3ControlMFADelete::NOT_SET;

    /**
    *  <p>Sets the versioning state of the S3 on Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlBucketVersioningStatus status = EAWSS3ControlBucketVersioningStatus::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::VersioningConfiguration toAWS() const {
        Aws::S3Control::Model::VersioningConfiguration awsVersioningConfiguration;

        switch(this->mFADelete) {
            case EAWSS3ControlMFADelete::Enabled:
                awsVersioningConfiguration.SetMFADelete(Aws::S3Control::Model::MFADelete::Enabled);
                break;
            case EAWSS3ControlMFADelete::Disabled:
                awsVersioningConfiguration.SetMFADelete(Aws::S3Control::Model::MFADelete::Disabled);
                break;
            default:
                break;
        }

        switch(this->status) {
            case EAWSS3ControlBucketVersioningStatus::Enabled:
                awsVersioningConfiguration.SetStatus(Aws::S3Control::Model::BucketVersioningStatus::Enabled);
                break;
            case EAWSS3ControlBucketVersioningStatus::Suspended:
                awsVersioningConfiguration.SetStatus(Aws::S3Control::Model::BucketVersioningStatus::Suspended);
                break;
            default:
                break;
        }

        return awsVersioningConfiguration;
    }

    bool IsEmpty() const {
        return this->mFADelete == EAWSS3ControlMFADelete::NOT_SET && this->status == EAWSS3ControlBucketVersioningStatus::NOT_SET;
    }
#endif
};
