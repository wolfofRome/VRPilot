/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3Retention.h"

#endif

#include "Model/S3ObjectLockRetentionMode.h"

#include "S3Retention.generated.h"

USTRUCT(BlueprintType)
struct FS3Retention {
GENERATED_BODY()

    /**
    *  <p>The date when the applied Object Retention will expire on all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime retainUntilDate;

    /**
    *  <p>The Retention mode to be applied to all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ObjectLockRetentionMode mode = EAWSS3ObjectLockRetentionMode::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3Retention toAWS() const {
        Aws::S3Control::Model::S3Retention awsS3Retention;

        if (!(this->retainUntilDate.ToUnixTimestamp() <= 0)) {
            awsS3Retention.SetRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->retainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        switch(this->mode) {
            case EAWSS3ObjectLockRetentionMode::COMPLIANCE:
                awsS3Retention.SetMode(Aws::S3Control::Model::S3ObjectLockRetentionMode::COMPLIANCE);
                break;
            case EAWSS3ObjectLockRetentionMode::GOVERNANCE:
                awsS3Retention.SetMode(Aws::S3Control::Model::S3ObjectLockRetentionMode::GOVERNANCE);
                break;
            default:
                break;
        }

        return awsS3Retention;
    }

    bool IsEmpty() const {
        return retainUntilDate.ToUnixTimestamp() <= 0 && mode == EAWSS3ObjectLockRetentionMode::NOT_SET;
    }

    FS3Retention &fromAWS(const Aws::S3Control::Model::S3Retention &awsS3Retention) {
        this->retainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsS3Retention.GetRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsS3Retention.GetMode()) {
            case Aws::S3Control::Model::S3ObjectLockRetentionMode::NOT_SET:
                this->mode = EAWSS3ObjectLockRetentionMode::NOT_SET;
                break;
            case Aws::S3Control::Model::S3ObjectLockRetentionMode::COMPLIANCE:
                this->mode = EAWSS3ObjectLockRetentionMode::COMPLIANCE;
                break;
            case Aws::S3Control::Model::S3ObjectLockRetentionMode::GOVERNANCE:
                this->mode = EAWSS3ObjectLockRetentionMode::GOVERNANCE;
                break;
            default:
                this->mode = EAWSS3ObjectLockRetentionMode::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
