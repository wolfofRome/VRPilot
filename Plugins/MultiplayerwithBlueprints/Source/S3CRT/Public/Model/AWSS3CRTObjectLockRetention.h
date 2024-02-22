/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ObjectLockRetention.h"

#endif

#include "Model/AWSS3CRTObjectLockRetentionMode.h"

#include "AWSS3CRTObjectLockRetention.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObjectLockRetention {
GENERATED_BODY()

    /**
    *  <p>Indicates the Retention mode for the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockRetentionMode mode = EAWSS3CRTObjectLockRetentionMode::NOT_SET;

    /**
    *  <p>The date on which this Object Lock Retention will expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime retainUntilDate;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ObjectLockRetention toAWS() const {
        Aws::S3Crt::Model::ObjectLockRetention awsObjectLockRetention;

        switch(this->mode) {
            case EAWSS3CRTObjectLockRetentionMode::GOVERNANCE:
                awsObjectLockRetention.SetMode(Aws::S3Crt::Model::ObjectLockRetentionMode::GOVERNANCE);
                break;
            case EAWSS3CRTObjectLockRetentionMode::COMPLIANCE:
                awsObjectLockRetention.SetMode(Aws::S3Crt::Model::ObjectLockRetentionMode::COMPLIANCE);
                break;
            default:
                break;
        }

        if (!(this->retainUntilDate.ToUnixTimestamp() <= 0)) {
            awsObjectLockRetention.SetRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->retainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        return awsObjectLockRetention;
    }

    bool IsEmpty() const {
        return this->mode == EAWSS3CRTObjectLockRetentionMode::NOT_SET && this->retainUntilDate.ToUnixTimestamp() <= 0;
    }

    FAWSS3CRTObjectLockRetention &fromAWS(const Aws::S3Crt::Model::ObjectLockRetention &awsObjectLockRetention) {
        switch(awsObjectLockRetention.GetMode()) {
            case Aws::S3Crt::Model::ObjectLockRetentionMode::NOT_SET:
                this->mode = EAWSS3CRTObjectLockRetentionMode::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectLockRetentionMode::GOVERNANCE:
                this->mode = EAWSS3CRTObjectLockRetentionMode::GOVERNANCE;
                break;
            case Aws::S3Crt::Model::ObjectLockRetentionMode::COMPLIANCE:
                this->mode = EAWSS3CRTObjectLockRetentionMode::COMPLIANCE;
                break;
            default:
                this->mode = EAWSS3CRTObjectLockRetentionMode::NOT_SET;
                break;
        }

        this->retainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsObjectLockRetention.GetRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
