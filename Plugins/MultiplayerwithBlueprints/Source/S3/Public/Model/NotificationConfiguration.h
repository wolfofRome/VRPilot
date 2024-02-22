/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/NotificationConfiguration.h"

#endif

#include "Model/TopicConfiguration.h"
#include "Model/QueueConfiguration.h"
#include "Model/LambdaFunctionConfiguration.h"
#include "Model/AWSS3EventBridgeConfiguration.h"

#include "NotificationConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FNotificationConfiguration {
GENERATED_BODY()

    /**
    *  <p>The topic to which notifications are sent and the events for which notifications are generated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FTopicConfiguration> topicConfigurations;

    /**
    *  <p>The Amazon Simple Queue Service queues to publish messages to and the events for which to publish messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FQueueConfiguration> queueConfigurations;

    /**
    *  <p>Describes the Lambda functions to invoke and the events for which to invoke them.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FLambdaFunctionConfiguration> lambdaFunctionConfigurations;

    /**
    *  <p>Enables delivery of events to Amazon EventBridge.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3EventBridgeConfiguration eventBridgeConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::NotificationConfiguration toAWS() const {
        Aws::S3::Model::NotificationConfiguration awsNotificationConfiguration;

        for (const FTopicConfiguration& elem : this->topicConfigurations) {
            awsNotificationConfiguration.AddTopicConfigurations(elem.toAWS());
        }

        for (const FQueueConfiguration& elem : this->queueConfigurations) {
            awsNotificationConfiguration.AddQueueConfigurations(elem.toAWS());
        }

        for (const FLambdaFunctionConfiguration& elem : this->lambdaFunctionConfigurations) {
            awsNotificationConfiguration.AddLambdaFunctionConfigurations(elem.toAWS());
        }

        if (!(this->eventBridgeConfiguration.IsEmpty())) {
            awsNotificationConfiguration.SetEventBridgeConfiguration(this->eventBridgeConfiguration.toAWS());
        }

        return awsNotificationConfiguration;
    }

    bool IsEmpty() const {
        return this->topicConfigurations.Num() == 0 && this->queueConfigurations.Num() == 0 && this->lambdaFunctionConfigurations.Num() == 0 && this->eventBridgeConfiguration.IsEmpty();
    }
#endif
};
