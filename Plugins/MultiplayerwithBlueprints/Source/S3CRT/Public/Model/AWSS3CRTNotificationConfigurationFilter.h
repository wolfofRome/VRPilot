/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/NotificationConfigurationFilter.h"

#endif

#include "Model/AWSS3CRTS3KeyFilter.h"

#include "AWSS3CRTNotificationConfigurationFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTNotificationConfigurationFilter {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTS3KeyFilter key;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::NotificationConfigurationFilter toAWS() const {
        Aws::S3Crt::Model::NotificationConfigurationFilter awsNotificationConfigurationFilter;

        if (!(this->key.IsEmpty())) {
            awsNotificationConfigurationFilter.SetKey(this->key.toAWS());
        }

        return awsNotificationConfigurationFilter;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty();
    }

    FAWSS3CRTNotificationConfigurationFilter &fromAWS(const Aws::S3Crt::Model::NotificationConfigurationFilter &awsNotificationConfigurationFilter) {
        this->key = FAWSS3CRTS3KeyFilter().fromAWS(awsNotificationConfigurationFilter.GetKey());

        return *this;
    }
#endif
};
