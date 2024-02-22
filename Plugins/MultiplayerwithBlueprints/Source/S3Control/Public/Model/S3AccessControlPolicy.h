/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3AccessControlPolicy.h"

#endif

#include "Model/S3AccessControlList.h"
#include "Model/S3CannedAccessControlList.h"

#include "S3AccessControlPolicy.generated.h"

USTRUCT(BlueprintType)
struct FS3AccessControlPolicy {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3AccessControlList accessControlList;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3CannedAccessControlList cannedAccessControlList = EAWSS3CannedAccessControlList::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3AccessControlPolicy toAWS() const {
        Aws::S3Control::Model::S3AccessControlPolicy awsS3AccessControlPolicy;

        if (!(this->accessControlList.IsEmpty())) {
            awsS3AccessControlPolicy.SetAccessControlList(this->accessControlList.toAWS());
        }

        switch(this->cannedAccessControlList) {
            case EAWSS3CannedAccessControlList::private_:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::private_);
                break;
            case EAWSS3CannedAccessControlList::public_read:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::public_read);
                break;
            case EAWSS3CannedAccessControlList::public_read_write:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::public_read_write);
                break;
            case EAWSS3CannedAccessControlList::aws_exec_read:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::aws_exec_read);
                break;
            case EAWSS3CannedAccessControlList::authenticated_read:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::authenticated_read);
                break;
            case EAWSS3CannedAccessControlList::bucket_owner_read:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_read);
                break;
            case EAWSS3CannedAccessControlList::bucket_owner_full_control:
                awsS3AccessControlPolicy.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_full_control);
                break;
            default:
                break;
        }

        return awsS3AccessControlPolicy;
    }

    bool IsEmpty() const {
        return this->accessControlList.IsEmpty() && cannedAccessControlList == EAWSS3CannedAccessControlList::NOT_SET;
    }

    FS3AccessControlPolicy &fromAWS(const Aws::S3Control::Model::S3AccessControlPolicy &awsS3AccessControlPolicy) {
        this->accessControlList.fromAWS(awsS3AccessControlPolicy.GetAccessControlList());

        switch(awsS3AccessControlPolicy.GetCannedAccessControlList()) {
            case Aws::S3Control::Model::S3CannedAccessControlList::NOT_SET:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::NOT_SET;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::private_:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::private_;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::public_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::public_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::public_read_write:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::public_read_write;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::aws_exec_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::aws_exec_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::authenticated_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::authenticated_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::bucket_owner_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_full_control:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::bucket_owner_full_control;
                break;
            default:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
