/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3ObjectLockLegalHold.h"

#endif

#include "Model/S3ObjectLockLegalHoldStatus.h"

#include "S3ObjectLockLegalHold.generated.h"

USTRUCT(BlueprintType)
struct FS3ObjectLockLegalHold {
GENERATED_BODY()

    /**
    *  <p>The Legal Hold status to be applied to all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ObjectLockLegalHoldStatus status = EAWSS3ObjectLockLegalHoldStatus::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3ObjectLockLegalHold toAWS() const {
        Aws::S3Control::Model::S3ObjectLockLegalHold awsS3ObjectLockLegalHold;

        switch(this->status) {
            case EAWSS3ObjectLockLegalHoldStatus::OFF:
                awsS3ObjectLockLegalHold.SetStatus(Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::OFF);
                break;
            case EAWSS3ObjectLockLegalHoldStatus::ON:
                awsS3ObjectLockLegalHold.SetStatus(Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::ON);
                break;
            default:
                break;
            }

        return awsS3ObjectLockLegalHold;
    }

    bool IsEmpty() const {
        return status == EAWSS3ObjectLockLegalHoldStatus::NOT_SET;
    }

    FS3ObjectLockLegalHold &fromAWS(const Aws::S3Control::Model::S3ObjectLockLegalHold &awsS3ObjectLockLegalHold) {
        switch(awsS3ObjectLockLegalHold.GetStatus()) {
            case Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::NOT_SET:
                this->status = EAWSS3ObjectLockLegalHoldStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::OFF:
                this->status = EAWSS3ObjectLockLegalHoldStatus::OFF;
                break;
            case Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::ON:
                this->status = EAWSS3ObjectLockLegalHoldStatus::ON;
                break;
            default:
                this->status = EAWSS3ObjectLockLegalHoldStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
