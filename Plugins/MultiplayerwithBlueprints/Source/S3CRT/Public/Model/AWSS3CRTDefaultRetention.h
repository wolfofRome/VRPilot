/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DefaultRetention.h"

#endif

#include "Model/AWSS3CRTObjectLockRetentionMode.h"

#include "AWSS3CRTDefaultRetention.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDefaultRetention {
GENERATED_BODY()

    /**
    *  <p>The default Object Lock retention mode you want to apply to new objects placed in the specified bucket. Must be used with either <code>Days</code> or <code>Years</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockRetentionMode mode = EAWSS3CRTObjectLockRetentionMode::NOT_SET;

    /**
    *  <p>The number of days that you want to specify for the default retention period. Must be used with <code>Mode</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int days = 0;

    /**
    *  <p>The number of years that you want to specify for the default retention period. Must be used with <code>Mode</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int years = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::DefaultRetention toAWS() const {
        Aws::S3Crt::Model::DefaultRetention awsDefaultRetention;

        switch(this->mode) {
            case EAWSS3CRTObjectLockRetentionMode::GOVERNANCE:
                awsDefaultRetention.SetMode(Aws::S3Crt::Model::ObjectLockRetentionMode::GOVERNANCE);
                break;
            case EAWSS3CRTObjectLockRetentionMode::COMPLIANCE:
                awsDefaultRetention.SetMode(Aws::S3Crt::Model::ObjectLockRetentionMode::COMPLIANCE);
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
        return this->mode == EAWSS3CRTObjectLockRetentionMode::NOT_SET && this->days == 0 && this->years == 0;
    }

    FAWSS3CRTDefaultRetention &fromAWS(const Aws::S3Crt::Model::DefaultRetention &awsDefaultRetention) {
        switch(awsDefaultRetention.GetMode()) {
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

		this->days = awsDefaultRetention.GetDays();

		this->years = awsDefaultRetention.GetYears();

        return *this;
    }
#endif
};
