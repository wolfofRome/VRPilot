/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Grant.h"

#endif

#include "Model/Grantee.h"
#include "Model/Permission.h"

#include "Grant.generated.h"

USTRUCT(BlueprintType)
struct FGrant {
GENERATED_BODY()

    /**
    *  <p>The person being granted permissions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FGrantee grantee;

    /**
    *  <p>Specifies the permission given to the grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSPermission permission = EAWSPermission::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Grant toAWS() const {
        Aws::S3::Model::Grant awsGrant;

        if (!(this->grantee.IsEmpty())) {
            awsGrant.SetGrantee(this->grantee.toAWS());
        }

        switch(this->permission) {
            case EAWSPermission::FULL_CONTROL:
                awsGrant.SetPermission(Aws::S3::Model::Permission::FULL_CONTROL);
                break;
            case EAWSPermission::WRITE:
                awsGrant.SetPermission(Aws::S3::Model::Permission::WRITE);
                break;
            case EAWSPermission::WRITE_ACP:
                awsGrant.SetPermission(Aws::S3::Model::Permission::WRITE_ACP);
                break;
            case EAWSPermission::READ:
                awsGrant.SetPermission(Aws::S3::Model::Permission::READ);
                break;
            case EAWSPermission::READ_ACP:
                awsGrant.SetPermission(Aws::S3::Model::Permission::READ_ACP);
                break;
            default:
                break;
        }

        return awsGrant;
    }

    bool IsEmpty() const {
        return this->grantee.IsEmpty() && permission == EAWSPermission::NOT_SET;
    }

    FGrant &fromAWS(const Aws::S3::Model::Grant &awsGrant) {
        this->grantee.fromAWS(awsGrant.GetGrantee());

        switch(awsGrant.GetPermission()) {
            case Aws::S3::Model::Permission::NOT_SET:
                this->permission = EAWSPermission::NOT_SET;
                break;
            case Aws::S3::Model::Permission::FULL_CONTROL:
                this->permission = EAWSPermission::FULL_CONTROL;
                break;
            case Aws::S3::Model::Permission::WRITE:
                this->permission = EAWSPermission::WRITE;
                break;
            case Aws::S3::Model::Permission::WRITE_ACP:
                this->permission = EAWSPermission::WRITE_ACP;
                break;
            case Aws::S3::Model::Permission::READ:
                this->permission = EAWSPermission::READ;
                break;
            case Aws::S3::Model::Permission::READ_ACP:
                this->permission = EAWSPermission::READ_ACP;
                break;
            default:
                this->permission = EAWSPermission::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
