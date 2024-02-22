/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/NotificationConfiguration.h"

#endif

#include "Model/AWSS3CRTTopicConfiguration.h"
#include "Model/AWSS3CRTQueueConfiguration.h"
#include "Model/AWSS3CRTLambdaFunctionConfiguration.h"

#include "AWSS3CRTNotificationConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTNotificationConfiguration {
GENERATED_BODY()

    /**
    *  <p>The topic to which notifications are sent and the events for which notifications are generated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTopicConfiguration> topicConfigurations;

    /**
    *  <p>The Amazon Simple Queue Service queues to publish messages to and the events for which to publish messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTQueueConfiguration> queueConfigurations;

    /**
    *  <p>Describes the AWS Lambda functions to invoke and the events for which to invoke them.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTLambdaFunctionConfiguration> lambdaFunctionConfigurations;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::NotificationConfiguration toAWS() const {
        Aws::S3Crt::Model::NotificationConfiguration awsNotificationConfiguration;

        for (const FAWSS3CRTTopicConfiguration& elem : this->topicConfigurations) {
            awsNotificationConfiguration.AddTopicConfigurations(elem.toAWS());
        }

        for (const FAWSS3CRTQueueConfiguration& elem : this->queueConfigurations) {
            awsNotificationConfiguration.AddQueueConfigurations(elem.toAWS());
        }

        for (const FAWSS3CRTLambdaFunctionConfiguration& elem : this->lambdaFunctionConfigurations) {
            awsNotificationConfiguration.AddLambdaFunctionConfigurations(elem.toAWS());
        }

        return awsNotificationConfiguration;
    }

    bool IsEmpty() const {
        return this->topicConfigurations.Num() == 0 && this->queueConfigurations.Num() == 0 && this->lambdaFunctionConfigurations.Num() == 0;
    }
#endif
};
