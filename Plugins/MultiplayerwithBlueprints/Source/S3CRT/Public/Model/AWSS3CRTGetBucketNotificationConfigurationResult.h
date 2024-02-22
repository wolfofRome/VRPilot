/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketNotificationConfigurationResult.h"

#endif

#include "Model/AWSS3CRTTopicConfiguration.h"
#include "Model/AWSS3CRTQueueConfiguration.h"
#include "Model/AWSS3CRTLambdaFunctionConfiguration.h"

#include "AWSS3CRTGetBucketNotificationConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketNotificationConfigurationResult {
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
    FAWSS3CRTGetBucketNotificationConfigurationResult &fromAWS(const Aws::S3Crt::Model::GetBucketNotificationConfigurationResult &awsGetBucketNotificationConfigurationResult) {
        this->topicConfigurations.Empty();
        for (const Aws::S3Crt::Model::TopicConfiguration& elem : awsGetBucketNotificationConfigurationResult.GetTopicConfigurations()) {
            this->topicConfigurations.Add(FAWSS3CRTTopicConfiguration().fromAWS(elem));
        }

        this->queueConfigurations.Empty();
        for (const Aws::S3Crt::Model::QueueConfiguration& elem : awsGetBucketNotificationConfigurationResult.GetQueueConfigurations()) {
            this->queueConfigurations.Add(FAWSS3CRTQueueConfiguration().fromAWS(elem));
        }

        this->lambdaFunctionConfigurations.Empty();
        for (const Aws::S3Crt::Model::LambdaFunctionConfiguration& elem : awsGetBucketNotificationConfigurationResult.GetLambdaFunctionConfigurations()) {
            this->lambdaFunctionConfigurations.Add(FAWSS3CRTLambdaFunctionConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
