/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ObjectLockConfiguration.h"

#endif

#include "Model/ObjectLockEnabled.h"
#include "Model/ObjectLockRule.h"

#include "ObjectLockConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FObjectLockConfiguration {
GENERATED_BODY()

    /**
    *  <p>Indicates whether this bucket has an Object Lock configuration enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectLockEnabled objectLockEnabled = EAWSObjectLockEnabled::NOT_SET;

    /**
    *  <p>The Object Lock rule in place for the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FObjectLockRule rule;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ObjectLockConfiguration toAWS() const {
        Aws::S3::Model::ObjectLockConfiguration awsObjectLockConfiguration;

        switch(this->objectLockEnabled) {
            case EAWSObjectLockEnabled::Enabled:
                awsObjectLockConfiguration.SetObjectLockEnabled(Aws::S3::Model::ObjectLockEnabled::Enabled);
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
        return objectLockEnabled == EAWSObjectLockEnabled::NOT_SET && this->rule.IsEmpty();
    }

    FObjectLockConfiguration &fromAWS(const Aws::S3::Model::ObjectLockConfiguration &awsObjectLockConfiguration) {
        switch(awsObjectLockConfiguration.GetObjectLockEnabled()) {
            case Aws::S3::Model::ObjectLockEnabled::NOT_SET:
                this->objectLockEnabled = EAWSObjectLockEnabled::NOT_SET;
                break;
            case Aws::S3::Model::ObjectLockEnabled::Enabled:
                this->objectLockEnabled = EAWSObjectLockEnabled::Enabled;
                break;
            default:
                this->objectLockEnabled = EAWSObjectLockEnabled::NOT_SET;
                break;
        }

        this->rule.fromAWS(awsObjectLockConfiguration.GetRule());

        return *this;
    }
#endif
};
