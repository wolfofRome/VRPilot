/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/NotificationConfigurationFilter.h"

#endif

#include "Model/S3KeyFilter.h"

#include "NotificationConfigurationFilter.generated.h"

USTRUCT(BlueprintType)
struct FNotificationConfigurationFilter {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3KeyFilter key;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::NotificationConfigurationFilter toAWS() const {
        Aws::S3::Model::NotificationConfigurationFilter awsNotificationConfigurationFilter;

        if (!(this->key.IsEmpty())) {
            awsNotificationConfigurationFilter.SetKey(this->key.toAWS());
        }

        return awsNotificationConfigurationFilter;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty();
    }

    FNotificationConfigurationFilter &fromAWS(const Aws::S3::Model::NotificationConfigurationFilter &awsNotificationConfigurationFilter) {
        this->key.fromAWS(awsNotificationConfigurationFilter.GetKey());

        return *this;
    }
#endif
};
