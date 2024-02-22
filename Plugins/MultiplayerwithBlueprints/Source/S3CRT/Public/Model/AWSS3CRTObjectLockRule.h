/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ObjectLockRule.h"

#endif

#include "Model/AWSS3CRTDefaultRetention.h"

#include "AWSS3CRTObjectLockRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObjectLockRule {
GENERATED_BODY()

    /**
    *  <p>The default Object Lock retention mode and period that you want to apply to new objects placed in the specified bucket. Bucket settings require both a mode and a period. The period can be either <code>Days</code> or <code>Years</code> but you must select one. You cannot specify <code>Days</code> and <code>Years</code> at the same time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTDefaultRetention defaultRetention;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ObjectLockRule toAWS() const {
        Aws::S3Crt::Model::ObjectLockRule awsObjectLockRule;

        if (!(this->defaultRetention.IsEmpty())) {
            awsObjectLockRule.SetDefaultRetention(this->defaultRetention.toAWS());
        }

        return awsObjectLockRule;
    }

    bool IsEmpty() const {
        return this->defaultRetention.IsEmpty();
    }

    FAWSS3CRTObjectLockRule &fromAWS(const Aws::S3Crt::Model::ObjectLockRule &awsObjectLockRule) {
        this->defaultRetention = FAWSS3CRTDefaultRetention().fromAWS(awsObjectLockRule.GetDefaultRetention());

        return *this;
    }
#endif
};
