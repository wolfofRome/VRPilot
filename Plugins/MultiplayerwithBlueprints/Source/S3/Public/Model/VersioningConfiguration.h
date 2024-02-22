/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/VersioningConfiguration.h"

#endif

#include "Model/MFADelete.h"
#include "Model/BucketVersioningStatus.h"

#include "VersioningConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FVersioningConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies whether MFA delete is enabled in the bucket versioning configuration. This element is only returned if the bucket has been configured with MFA delete. If the bucket has never been so configured, this element is not returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSMFADelete mFADelete = EAWSMFADelete::NOT_SET;

    /**
    *  <p>The versioning state of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketVersioningStatus status = EAWSBucketVersioningStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::VersioningConfiguration toAWS() const {
        Aws::S3::Model::VersioningConfiguration awsVersioningConfiguration;

        switch(this->mFADelete) {
            case EAWSMFADelete::Enabled:
                awsVersioningConfiguration.SetMFADelete(Aws::S3::Model::MFADelete::Enabled);
                break;
            case EAWSMFADelete::Disabled:
                awsVersioningConfiguration.SetMFADelete(Aws::S3::Model::MFADelete::Disabled);
                break;
            default:
                break;
        }

        switch(this->status) {
            case EAWSBucketVersioningStatus::Enabled:
                awsVersioningConfiguration.SetStatus(Aws::S3::Model::BucketVersioningStatus::Enabled);
                break;
            case EAWSBucketVersioningStatus::Suspended:
                awsVersioningConfiguration.SetStatus(Aws::S3::Model::BucketVersioningStatus::Suspended);
                break;
            default:
                break;
        }

        return awsVersioningConfiguration;
    }

    bool IsEmpty() const {
        return mFADelete == EAWSMFADelete::NOT_SET && status == EAWSBucketVersioningStatus::NOT_SET;
    }
#endif
};
