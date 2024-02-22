/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3Grant.h"

#endif

#include "Model/S3Grantee.h"
#include "Model/S3Permission.h"

#include "S3Grant.generated.h"

USTRUCT(BlueprintType)
struct FS3Grant {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3Grantee grantee;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3Permission permission = EAWSS3Permission::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3Grant toAWS() const {
        Aws::S3Control::Model::S3Grant awsS3Grant;

        if (!(this->grantee.IsEmpty())) {
            awsS3Grant.SetGrantee(this->grantee.toAWS());
        }

        switch(this->permission) {
            case EAWSS3Permission::FULL_CONTROL:
                awsS3Grant.SetPermission(Aws::S3Control::Model::S3Permission::FULL_CONTROL);
                break;
            case EAWSS3Permission::READ:
                awsS3Grant.SetPermission(Aws::S3Control::Model::S3Permission::READ);
                break;
            case EAWSS3Permission::WRITE:
                awsS3Grant.SetPermission(Aws::S3Control::Model::S3Permission::WRITE);
                break;
            case EAWSS3Permission::READ_ACP:
                awsS3Grant.SetPermission(Aws::S3Control::Model::S3Permission::READ_ACP);
                break;
            case EAWSS3Permission::WRITE_ACP:
                awsS3Grant.SetPermission(Aws::S3Control::Model::S3Permission::WRITE_ACP);
                break;
            default:
                break;
        }

        return awsS3Grant;
    }

    bool IsEmpty() const {
        return this->grantee.IsEmpty() && permission == EAWSS3Permission::NOT_SET;
    }

    FS3Grant &fromAWS(const Aws::S3Control::Model::S3Grant &awsS3Grant) {
        this->grantee.fromAWS(awsS3Grant.GetGrantee());

        switch(awsS3Grant.GetPermission()) {
            case Aws::S3Control::Model::S3Permission::NOT_SET:
                this->permission = EAWSS3Permission::NOT_SET;
                break;
            case Aws::S3Control::Model::S3Permission::FULL_CONTROL:
                this->permission = EAWSS3Permission::FULL_CONTROL;
                break;
            case Aws::S3Control::Model::S3Permission::READ:
                this->permission = EAWSS3Permission::READ;
                break;
            case Aws::S3Control::Model::S3Permission::WRITE:
                this->permission = EAWSS3Permission::WRITE;
                break;
            case Aws::S3Control::Model::S3Permission::READ_ACP:
                this->permission = EAWSS3Permission::READ_ACP;
                break;
            case Aws::S3Control::Model::S3Permission::WRITE_ACP:
                this->permission = EAWSS3Permission::WRITE_ACP;
                break;
            default:
                this->permission = EAWSS3Permission::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
