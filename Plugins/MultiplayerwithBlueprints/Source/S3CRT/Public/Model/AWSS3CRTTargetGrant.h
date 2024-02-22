/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/TargetGrant.h"

#endif

#include "Model/AWSS3CRTGrantee.h"
#include "Model/AWSS3CRTBucketLogsPermission.h"

#include "AWSS3CRTTargetGrant.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTTargetGrant {
GENERATED_BODY()

    /**
    *  <p>Container for the person being granted permissions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTGrantee grantee;

    /**
    *  <p>Logging permissions assigned to the grantee for the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketLogsPermission permission = EAWSS3CRTBucketLogsPermission::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::TargetGrant toAWS() const {
        Aws::S3Crt::Model::TargetGrant awsTargetGrant;

        if (!(this->grantee.IsEmpty())) {
            awsTargetGrant.SetGrantee(this->grantee.toAWS());
        }

        switch(this->permission) {
            case EAWSS3CRTBucketLogsPermission::FULL_CONTROL:
                awsTargetGrant.SetPermission(Aws::S3Crt::Model::BucketLogsPermission::FULL_CONTROL);
                break;
            case EAWSS3CRTBucketLogsPermission::READ:
                awsTargetGrant.SetPermission(Aws::S3Crt::Model::BucketLogsPermission::READ);
                break;
            case EAWSS3CRTBucketLogsPermission::WRITE:
                awsTargetGrant.SetPermission(Aws::S3Crt::Model::BucketLogsPermission::WRITE);
                break;
            default:
                break;
        }

        return awsTargetGrant;
    }

    bool IsEmpty() const {
        return this->grantee.IsEmpty() && this->permission == EAWSS3CRTBucketLogsPermission::NOT_SET;
    }

    FAWSS3CRTTargetGrant &fromAWS(const Aws::S3Crt::Model::TargetGrant &awsTargetGrant) {
        this->grantee = FAWSS3CRTGrantee().fromAWS(awsTargetGrant.GetGrantee());

        switch(awsTargetGrant.GetPermission()) {
            case Aws::S3Crt::Model::BucketLogsPermission::NOT_SET:
                this->permission = EAWSS3CRTBucketLogsPermission::NOT_SET;
                break;
            case Aws::S3Crt::Model::BucketLogsPermission::FULL_CONTROL:
                this->permission = EAWSS3CRTBucketLogsPermission::FULL_CONTROL;
                break;
            case Aws::S3Crt::Model::BucketLogsPermission::READ:
                this->permission = EAWSS3CRTBucketLogsPermission::READ;
                break;
            case Aws::S3Crt::Model::BucketLogsPermission::WRITE:
                this->permission = EAWSS3CRTBucketLogsPermission::WRITE;
                break;
            default:
                this->permission = EAWSS3CRTBucketLogsPermission::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
