/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DefaultRetention.h"

#endif

#include "Model/ObjectLockRetentionMode.h"

#include "DefaultRetention.generated.h"

USTRUCT(BlueprintType)
struct FDefaultRetention {
GENERATED_BODY()

    /**
    *  <p>The default Object Lock retention mode you want to apply to new objects placed in the specified bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockRetentionMode mode = EAWSObjectLockRetentionMode::NOT_SET;

    /**
    *  <p>The number of days that you want to specify for the default retention period.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int days = 0;

    /**
    *  <p>The number of years that you want to specify for the default retention period.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int years = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::DefaultRetention toAWS() const {
        Aws::S3::Model::DefaultRetention awsDefaultRetention;

        switch(this->mode) {
            case EAWSObjectLockRetentionMode::GOVERNANCE:
                awsDefaultRetention.SetMode(Aws::S3::Model::ObjectLockRetentionMode::GOVERNANCE);
                break;
            case EAWSObjectLockRetentionMode::COMPLIANCE:
                awsDefaultRetention.SetMode(Aws::S3::Model::ObjectLockRetentionMode::COMPLIANCE);
                break;
            default:
                break;
        }

        if (!(this->days == 0)) {
            awsDefaultRetention.SetDays(this->days);
        }

        if (!(this->years == 0)) {
            awsDefaultRetention.SetYears(this->years);
        }

        return awsDefaultRetention;
    }

    bool IsEmpty() const {
        return mode == EAWSObjectLockRetentionMode::NOT_SET && this->days == 0 && this->years == 0;
    }

    FDefaultRetention &fromAWS(const Aws::S3::Model::DefaultRetention &awsDefaultRetention) {
        switch(awsDefaultRetention.GetMode()) {
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

		this->days = awsDefaultRetention.GetDays();

		this->years = awsDefaultRetention.GetYears();

        return *this;
    }
#endif
};
