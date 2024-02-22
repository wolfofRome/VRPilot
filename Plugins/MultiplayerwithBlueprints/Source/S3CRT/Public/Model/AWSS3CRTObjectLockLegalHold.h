/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ObjectLockLegalHold.h"

#endif

#include "Model/AWSS3CRTObjectLockLegalHoldStatus.h"

#include "AWSS3CRTObjectLockLegalHold.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObjectLockLegalHold {
GENERATED_BODY()

    /**
    *  <p>Indicates whether the specified object has a Legal Hold in place.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockLegalHoldStatus status = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ObjectLockLegalHold toAWS() const {
        Aws::S3Crt::Model::ObjectLockLegalHold awsObjectLockLegalHold;

        switch(this->status) {
            case EAWSS3CRTObjectLockLegalHoldStatus::ON:
                awsObjectLockLegalHold.SetStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::ON);
                break;
            case EAWSS3CRTObjectLockLegalHoldStatus::OFF:
                awsObjectLockLegalHold.SetStatus(Aws::S3Crt::Model::ObjectLockLegalHoldStatus::OFF);
                break;
            default:
                break;
        }

        return awsObjectLockLegalHold;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;
    }

    FAWSS3CRTObjectLockLegalHold &fromAWS(const Aws::S3Crt::Model::ObjectLockLegalHold &awsObjectLockLegalHold) {
        switch(awsObjectLockLegalHold.GetStatus()) {
            case Aws::S3Crt::Model::ObjectLockLegalHoldStatus::NOT_SET:
                this->status = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectLockLegalHoldStatus::ON:
                this->status = EAWSS3CRTObjectLockLegalHoldStatus::ON;
                break;
            case Aws::S3Crt::Model::ObjectLockLegalHoldStatus::OFF:
                this->status = EAWSS3CRTObjectLockLegalHoldStatus::OFF;
                break;
            default:
                this->status = EAWSS3CRTObjectLockLegalHoldStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
