/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ObjectLockRule.h"

#endif

#include "Model/DefaultRetention.h"

#include "ObjectLockRule.generated.h"

USTRUCT(BlueprintType)
struct FObjectLockRule {
GENERATED_BODY()

    /**
    *  <p>The default retention period that you want to apply to new objects placed in the specified bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDefaultRetention defaultRetention;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ObjectLockRule toAWS() const {
        Aws::S3::Model::ObjectLockRule awsObjectLockRule;

        if (!(this->defaultRetention.IsEmpty())) {
            awsObjectLockRule.SetDefaultRetention(this->defaultRetention.toAWS());
        }

        return awsObjectLockRule;
    }

    bool IsEmpty() const {
        return this->defaultRetention.IsEmpty();
    }

    FObjectLockRule &fromAWS(const Aws::S3::Model::ObjectLockRule &awsObjectLockRule) {
        this->defaultRetention.fromAWS(awsObjectLockRule.GetDefaultRetention());

        return *this;
    }
#endif
};
