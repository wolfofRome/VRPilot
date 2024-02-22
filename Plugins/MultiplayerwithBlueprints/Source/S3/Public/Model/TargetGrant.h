/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/TargetGrant.h"

#endif

#include "Model/Grantee.h"
#include "Model/BucketLogsPermission.h"

#include "TargetGrant.generated.h"

USTRUCT(BlueprintType)
struct FTargetGrant {
GENERATED_BODY()

    /**
    *  <p>Container for the person being granted permissions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FGrantee grantee;

    /**
    *  <p>Logging permissions assigned to the Grantee for the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketLogsPermission permission = EAWSBucketLogsPermission::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::TargetGrant toAWS() const {
        Aws::S3::Model::TargetGrant awsTargetGrant;

        if (!(this->grantee.IsEmpty())) {
            awsTargetGrant.SetGrantee(this->grantee.toAWS());
        }

        switch(this->permission) {
            case EAWSBucketLogsPermission::FULL_CONTROL:
                awsTargetGrant.SetPermission(Aws::S3::Model::BucketLogsPermission::FULL_CONTROL);
                break;
            case EAWSBucketLogsPermission::READ:
                awsTargetGrant.SetPermission(Aws::S3::Model::BucketLogsPermission::READ);
                break;
            case EAWSBucketLogsPermission::WRITE:
                awsTargetGrant.SetPermission(Aws::S3::Model::BucketLogsPermission::WRITE);
                break;
            default:
                break;
        }

        return awsTargetGrant;
    }

    bool IsEmpty() const {
        return this->grantee.IsEmpty() && permission == EAWSBucketLogsPermission::NOT_SET;
    }

    FTargetGrant &fromAWS(const Aws::S3::Model::TargetGrant &awsTargetGrant) {
        this->grantee.fromAWS(awsTargetGrant.GetGrantee());

        switch(awsTargetGrant.GetPermission()) {
            case Aws::S3::Model::BucketLogsPermission::NOT_SET:
                this->permission = EAWSBucketLogsPermission::NOT_SET;
                break;
            case Aws::S3::Model::BucketLogsPermission::FULL_CONTROL:
                this->permission = EAWSBucketLogsPermission::FULL_CONTROL;
                break;
            case Aws::S3::Model::BucketLogsPermission::READ:
                this->permission = EAWSBucketLogsPermission::READ;
                break;
            case Aws::S3::Model::BucketLogsPermission::WRITE:
                this->permission = EAWSBucketLogsPermission::WRITE;
                break;
            default:
                this->permission = EAWSBucketLogsPermission::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
