/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ObjectLockRetention.h"

#endif

#include "Model/ObjectLockRetentionMode.h"

#include "ObjectLockRetention.generated.h"

USTRUCT(BlueprintType)
struct FObjectLockRetention {
GENERATED_BODY()

    /**
    *  <p>Indicates the Retention mode for the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockRetentionMode mode = EAWSObjectLockRetentionMode::NOT_SET;

    /**
    *  <p>The date on which this Object Lock Retention will expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime retainUntilDate;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ObjectLockRetention toAWS() const {
        Aws::S3::Model::ObjectLockRetention awsObjectLockRetention;

        switch(this->mode) {
            case EAWSObjectLockRetentionMode::GOVERNANCE:
                awsObjectLockRetention.SetMode(Aws::S3::Model::ObjectLockRetentionMode::GOVERNANCE);
                break;
            case EAWSObjectLockRetentionMode::COMPLIANCE:
                awsObjectLockRetention.SetMode(Aws::S3::Model::ObjectLockRetentionMode::COMPLIANCE);
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
        return mode == EAWSObjectLockRetentionMode::NOT_SET && retainUntilDate.ToUnixTimestamp() <= 0;
    }

    FObjectLockRetention &fromAWS(const Aws::S3::Model::ObjectLockRetention &awsObjectLockRetention) {
        switch(awsObjectLockRetention.GetMode()) {
            case Aws::S3::Model::ObjectLockRetentionMode::NOT_SET:
                this->mode = EAWSObjectLockRetentionMode::NOT_SET;
                break;
            case Aws::S3::Model::ObjectLockRetentionMode::GOVERNANCE:
                this->mode = EAWSObjectLockRetentionMode::GOVERNANCE;
                break;
            case Aws::S3::Model::ObjectLockRetentionMode::COMPLIANCE:
                this->mode = EAWSObjectLockRetentionMode::COMPLIANCE;
                break;
            default:
                this->mode = EAWSObjectLockRetentionMode::NOT_SET;
                break;
        }

        this->retainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsObjectLockRetention.GetRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
