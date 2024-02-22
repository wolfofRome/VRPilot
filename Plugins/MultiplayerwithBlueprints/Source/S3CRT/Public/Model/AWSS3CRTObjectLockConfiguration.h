/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ObjectLockConfiguration.h"

#endif

#include "Model/AWSS3CRTObjectLockEnabled.h"
#include "Model/AWSS3CRTObjectLockRule.h"

#include "AWSS3CRTObjectLockConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObjectLockConfiguration {
GENERATED_BODY()

    /**
    *  <p>Indicates whether this bucket has an Object Lock configuration enabled. Enable <code>ObjectLockEnabled</code> when you apply <code>ObjectLockConfiguration</code> to a bucket. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectLockEnabled objectLockEnabled = EAWSS3CRTObjectLockEnabled::NOT_SET;

    /**
    *  <p>Specifies the Object Lock rule for the specified object. Enable the this rule when you apply <code>ObjectLockConfiguration</code> to a bucket. Bucket settings require both a mode and a period. The period can be either <code>Days</code> or <code>Years</code> but you must select one. You cannot specify <code>Days</code> and <code>Years</code> at the same time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTObjectLockRule rule;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ObjectLockConfiguration toAWS() const {
        Aws::S3Crt::Model::ObjectLockConfiguration awsObjectLockConfiguration;

        switch(this->objectLockEnabled) {
            case EAWSS3CRTObjectLockEnabled::Enabled:
                awsObjectLockConfiguration.SetObjectLockEnabled(Aws::S3Crt::Model::ObjectLockEnabled::Enabled);
                break;
            default:
                break;
        }

        if (!(this->rule.IsEmpty())) {
            awsObjectLockConfiguration.SetRule(this->rule.toAWS());
        }

        return awsObjectLockConfiguration;
    }

    bool IsEmpty() const {
        return this->objectLockEnabled == EAWSS3CRTObjectLockEnabled::NOT_SET && this->rule.IsEmpty();
    }

    FAWSS3CRTObjectLockConfiguration &fromAWS(const Aws::S3Crt::Model::ObjectLockConfiguration &awsObjectLockConfiguration) {
        switch(awsObjectLockConfiguration.GetObjectLockEnabled()) {
            case Aws::S3Crt::Model::ObjectLockEnabled::NOT_SET:
                this->objectLockEnabled = EAWSS3CRTObjectLockEnabled::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectLockEnabled::Enabled:
                this->objectLockEnabled = EAWSS3CRTObjectLockEnabled::Enabled;
                break;
            default:
                this->objectLockEnabled = EAWSS3CRTObjectLockEnabled::NOT_SET;
                break;
        }

        this->rule = FAWSS3CRTObjectLockRule().fromAWS(awsObjectLockConfiguration.GetRule());

        return *this;
    }
#endif
};
