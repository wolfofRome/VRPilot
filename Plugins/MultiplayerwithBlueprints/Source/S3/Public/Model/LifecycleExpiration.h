/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/LifecycleExpiration.h"

#endif


#include "LifecycleExpiration.generated.h"

USTRUCT(BlueprintType)
struct FLifecycleExpiration {
GENERATED_BODY()

    /**
    *  <p>Indicates at what date the object is to be moved or deleted. Should be in GMT ISO 8601 Format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime date;

    /**
    *  <p>Indicates the lifetime, in days, of the objects that are subject to the rule. The value must be a non-zero positive integer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int days = 0;

    /**
    *  <p>Indicates whether Amazon S3 will remove a delete marker with no noncurrent versions. If set to true, the delete marker will be expired; if set to false the policy takes no action. This cannot be specified with Days or Date in a Lifecycle Expiration Policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool expiredObjectDeleteMarker = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::LifecycleExpiration toAWS() const {
        Aws::S3::Model::LifecycleExpiration awsLifecycleExpiration;

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
        return date.ToUnixTimestamp() <= 0 && this->days == 0 && false;
    }

    FLifecycleExpiration &fromAWS(const Aws::S3::Model::LifecycleExpiration &awsLifecycleExpiration) {
        this->date = FDateTime(1970, 1, 1) + FTimespan(awsLifecycleExpiration.GetDate().Millis() * ETimespan::TicksPerMillisecond);

		this->days = awsLifecycleExpiration.GetDays();

        this->expiredObjectDeleteMarker = awsLifecycleExpiration.GetExpiredObjectDeleteMarker();

        return *this;
    }
#endif
};
