/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ObjectLockLegalHold.h"

#endif

#include "Model/ObjectLockLegalHoldStatus.h"

#include "ObjectLockLegalHold.generated.h"

USTRUCT(BlueprintType)
struct FObjectLockLegalHold {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the specified object has a Legal Hold in place.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockLegalHoldStatus status = EAWSObjectLockLegalHoldStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ObjectLockLegalHold toAWS() const {
        Aws::S3::Model::ObjectLockLegalHold awsObjectLockLegalHold;

        switch(this->status) {
            case EAWSObjectLockLegalHoldStatus::ON:
                awsObjectLockLegalHold.SetStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSObjectLockLegalHoldStatus::OFF:
                awsObjectLockLegalHold.SetStatus(Aws::S3::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
        }

        return awsObjectLockLegalHold;
    }

    bool IsEmpty() const {
        return status == EAWSObjectLockLegalHoldStatus::NOT_SET;
    }

    FObjectLockLegalHold &fromAWS(const Aws::S3::Model::ObjectLockLegalHold &awsObjectLockLegalHold) {
        switch(awsObjectLockLegalHold.GetStatus()) {
            case Aws::S3::Model::ObjectLockLegalHoldStatus::NOT_SET:
                this->status = EAWSObjectLockLegalHoldStatus::NOT_SET;
                break;
            case Aws::S3::Model::ObjectLockLegalHoldStatus::ON:
                this->status = EAWSObjectLockLegalHoldStatus::ON;
                break;
            case Aws::S3::Model::ObjectLockLegalHoldStatus::OFF:
                this->status = EAWSObjectLockLegalHoldStatus::OFF;
                break;
            default:
                this->status = EAWSObjectLockLegalHoldStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
