/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/LifecycleExpiration.h"

#endif

#include "AWSS3ControlLifecycleExpiration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlLifecycleExpiration {
GENERATED_BODY()

    /**
    *  <p>Indicates at what date the object is to be deleted. Should be in GMT ISO 8601 format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime date;

    /**
    *  <p>Indicates the lifetime, in days, of the objects that are subject to the rule. The value must be a non-zero positive integer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int days = 0;

    /**
    *  <p>Indicates whether Amazon S3 will remove a delete marker with no noncurrent versions. If set to true, the delete marker will be expired. If set to false, the policy takes no action. This cannot be specified with Days or Date in a Lifecycle Expiration Policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool expiredObjectDeleteMarker = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::LifecycleExpiration toAWS() const {
        Aws::S3Control::Model::LifecycleExpiration awsLifecycleExpiration;

        if (!(this->date.ToUnixTimestamp() <= 0)) {
            awsLifecycleExpiration.SetDate(Aws::Utils::DateTime((int64_t)((this->date - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->days == 0)) {
            awsLifecycleExpiration.SetDays(this->days);
        }

        if (!(false)) {
            awsLifecycleExpiration.SetExpiredObjectDeleteMarker(this->expiredObjectDeleteMarker);
        }

        return awsLifecycleExpiration;
    }

    bool IsEmpty() const {
        return this->date.ToUnixTimestamp() <= 0 && this->days == 0 && false;
    }

    FAWSS3ControlLifecycleExpiration &fromAWS(const Aws::S3Control::Model::LifecycleExpiration &awsLifecycleExpiration) {
        this->date = FDateTime(1970, 1, 1) + FTimespan(awsLifecycleExpiration.GetDate().Millis() * ETimespan::TicksPerMillisecond);

		this->days = awsLifecycleExpiration.GetDays();

        this->expiredObjectDeleteMarker = awsLifecycleExpiration.GetExpiredObjectDeleteMarker();

        return *this;
    }
#endif
};
