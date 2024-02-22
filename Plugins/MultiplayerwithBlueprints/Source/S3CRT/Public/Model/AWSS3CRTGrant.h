/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Grant.h"

#endif

#include "Model/AWSS3CRTGrantee.h"
#include "Model/AWSS3CRTPermission.h"

#include "AWSS3CRTGrant.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGrant {
GENERATED_BODY()

    /**
    *  <p>The person being granted permissions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTGrantee grantee;

    /**
    *  <p>Specifies the permission given to the grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTPermission permission = EAWSS3CRTPermission::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Grant toAWS() const {
        Aws::S3Crt::Model::Grant awsGrant;

        if (!(this->grantee.IsEmpty())) {
            awsGrant.SetGrantee(this->grantee.toAWS());
        }

        switch(this->permission) {
            case EAWSS3CRTPermission::FULL_CONTROL:
                awsGrant.SetPermission(Aws::S3Crt::Model::Permission::FULL_CONTROL);
                break;
            case EAWSS3CRTPermission::WRITE:
                awsGrant.SetPermission(Aws::S3Crt::Model::Permission::WRITE);
                break;
            case EAWSS3CRTPermission::WRITE_ACP:
                awsGrant.SetPermission(Aws::S3Crt::Model::Permission::WRITE_ACP);
                break;
            case EAWSS3CRTPermission::READ:
                awsGrant.SetPermission(Aws::S3Crt::Model::Permission::READ);
                break;
            case EAWSS3CRTPermission::READ_ACP:
                awsGrant.SetPermission(Aws::S3Crt::Model::Permission::READ_ACP);
                break;
            default:
                break;
        }

        return awsGrant;
    }

    bool IsEmpty() const {
        return this->grantee.IsEmpty() && this->permission == EAWSS3CRTPermission::NOT_SET;
    }

    FAWSS3CRTGrant &fromAWS(const Aws::S3Crt::Model::Grant &awsGrant) {
        this->grantee = FAWSS3CRTGrantee().fromAWS(awsGrant.GetGrantee());

        switch(awsGrant.GetPermission()) {
            case Aws::S3Crt::Model::Permission::NOT_SET:
                this->permission = EAWSS3CRTPermission::NOT_SET;
                break;
            case Aws::S3Crt::Model::Permission::FULL_CONTROL:
                this->permission = EAWSS3CRTPermission::FULL_CONTROL;
                break;
            case Aws::S3Crt::Model::Permission::WRITE:
                this->permission = EAWSS3CRTPermission::WRITE;
                break;
            case Aws::S3Crt::Model::Permission::WRITE_ACP:
                this->permission = EAWSS3CRTPermission::WRITE_ACP;
                break;
            case Aws::S3Crt::Model::Permission::READ:
                this->permission = EAWSS3CRTPermission::READ;
                break;
            case Aws::S3Crt::Model::Permission::READ_ACP:
                this->permission = EAWSS3CRTPermission::READ_ACP;
                break;
            default:
                this->permission = EAWSS3CRTPermission::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
