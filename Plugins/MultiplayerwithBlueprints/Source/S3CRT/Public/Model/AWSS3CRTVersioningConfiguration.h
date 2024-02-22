/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/VersioningConfiguration.h"

#endif

#include "Model/AWSS3CRTMFADelete.h"
#include "Model/AWSS3CRTBucketVersioningStatus.h"

#include "AWSS3CRTVersioningConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTVersioningConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies whether MFA delete is enabled in the bucket versioning configuration. This element is only returned if the bucket has been configured with MFA delete. If the bucket has never been so configured, this element is not returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTMFADelete mFADelete = EAWSS3CRTMFADelete::NOT_SET;

    /**
    *  <p>The versioning state of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketVersioningStatus status = EAWSS3CRTBucketVersioningStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::VersioningConfiguration toAWS() const {
        Aws::S3Crt::Model::VersioningConfiguration awsVersioningConfiguration;

        switch(this->mFADelete) {
            case EAWSS3CRTMFADelete::Enabled:
                awsVersioningConfiguration.SetMFADelete(Aws::S3Crt::Model::MFADelete::Enabled);
                break;
            case EAWSS3CRTMFADelete::Disabled:
                awsVersioningConfiguration.SetMFADelete(Aws::S3Crt::Model::MFADelete::Disabled);
                break;
            default:
                break;
        }

        switch(this->status) {
            case EAWSS3CRTBucketVersioningStatus::Enabled:
                awsVersioningConfiguration.SetStatus(Aws::S3Crt::Model::BucketVersioningStatus::Enabled);
                break;
            case EAWSS3CRTBucketVersioningStatus::Suspended:
                awsVersioningConfiguration.SetStatus(Aws::S3Crt::Model::BucketVersioningStatus::Suspended);
                break;
            default:
                break;
        }

        return awsVersioningConfiguration;
    }

    bool IsEmpty() const {
        return mFADelete == EAWSS3CRTMFADelete::NOT_SET/* @TODO: check */ && status == EAWSS3CRTBucketVersioningStatus::NOT_SET/* @TODO: check */ && true;
    }

    
#endif
};
