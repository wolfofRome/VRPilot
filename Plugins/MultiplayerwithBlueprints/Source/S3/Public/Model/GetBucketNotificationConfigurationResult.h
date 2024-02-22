/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketNotificationConfigurationResult.h"

#endif

#include "Model/TopicConfiguration.h"
#include "Model/QueueConfiguration.h"
#include "Model/LambdaFunctionConfiguration.h"
#include "Model/AWSS3EventBridgeConfiguration.h"

#include "GetBucketNotificationConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketNotificationConfigurationResult {
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
    FGetBucketNotificationConfigurationResult &fromAWS(const Aws::S3::Model::GetBucketNotificationConfigurationResult &awsGetBucketNotificationConfigurationResult) {
        this->topicConfigurations.Empty();
        for (const Aws::S3::Model::TopicConfiguration& elem : awsGetBucketNotificationConfigurationResult.GetTopicConfigurations()) {
            this->topicConfigurations.Add(FTopicConfiguration().fromAWS(elem));
        }

        this->queueConfigurations.Empty();
        for (const Aws::S3::Model::QueueConfiguration& elem : awsGetBucketNotificationConfigurationResult.GetQueueConfigurations()) {
            this->queueConfigurations.Add(FQueueConfiguration().fromAWS(elem));
        }

        this->lambdaFunctionConfigurations.Empty();
        for (const Aws::S3::Model::LambdaFunctionConfiguration& elem : awsGetBucketNotificationConfigurationResult.GetLambdaFunctionConfigurations()) {
            this->lambdaFunctionConfigurations.Add(FLambdaFunctionConfiguration().fromAWS(elem));
        }

        this->eventBridgeConfiguration.fromAWS(awsGetBucketNotificationConfigurationResult.GetEventBridgeConfiguration());

        return *this;
    }
#endif
};
