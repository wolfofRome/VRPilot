/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/TopicConfiguration.h"

#endif

#include "Model/AWSS3CRTEvent.h"
#include "Model/AWSS3CRTNotificationConfigurationFilter.h"

#include "AWSS3CRTTopicConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTTopicConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon SNS topic to which Amazon S3 publishes a message when it detects events of the specified type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString topicArn;

    /**
    *  <p>The Amazon S3 bucket event about which to send notifications. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Supported Event Types</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<EAWSS3CRTEvent> events;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTNotificationConfigurationFilter filter;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::TopicConfiguration toAWS() const {
        Aws::S3Crt::Model::TopicConfiguration awsTopicConfiguration;

        if (!(this->id.IsEmpty())) {
            awsTopicConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->topicArn.IsEmpty())) {
            awsTopicConfiguration.SetTopicArn(TCHAR_TO_UTF8(*this->topicArn));
        }

        for (const EAWSS3CRTEvent& elem : this->events) {
		    switch(elem) {
                case EAWSS3CRTEvent::s3_ReducedRedundancyLostObject:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ReducedRedundancyLostObject);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Put:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Put);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Post:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Post);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Copy:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Copy);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_CompleteMultipartUpload:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_CompleteMultipartUpload);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved_Delete:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved_Delete);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved_DeleteMarkerCreated:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore_Post:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore_Post);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore_Completed:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore_Completed);
                    break;
                case EAWSS3CRTEvent::s3_Replication:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationFailedReplication:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationFailedReplication);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationNotTracked:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationNotTracked);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationMissedThreshold:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationMissedThreshold);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationReplicatedAfterThreshold:
                    awsTopicConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationReplicatedAfterThreshold);
                    break;
                default:
                    break;
            };
        }

        if (!(this->filter.IsEmpty())) {
            awsTopicConfiguration.SetFilter(this->filter.toAWS());
        }

        return awsTopicConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->topicArn.IsEmpty() && this->events.Num() == 0 && this->filter.IsEmpty();
    }

    FAWSS3CRTTopicConfiguration &fromAWS(const Aws::S3Crt::Model::TopicConfiguration &awsTopicConfiguration) {
        this->id = UTF8_TO_TCHAR(awsTopicConfiguration.GetId().c_str());

        this->topicArn = UTF8_TO_TCHAR(awsTopicConfiguration.GetTopicArn().c_str());

        this->events.Empty();
        for (const Aws::S3Crt::Model::Event& elem : awsTopicConfiguration.GetEvents()) {
            switch(elem) {
                case Aws::S3Crt::Model::Event::NOT_SET:
                    this->events.Add(EAWSS3CRTEvent::NOT_SET);
                    break;
                case Aws::S3Crt::Model::Event::s3_ReducedRedundancyLostObject:
                    this->events.Add(EAWSS3CRTEvent::s3_ReducedRedundancyLostObject);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectCreated:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectCreated);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectCreated_Put:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectCreated_Put);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectCreated_Post:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectCreated_Post);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectCreated_Copy:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectCreated_Copy);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectCreated_CompleteMultipartUpload:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectCreated_CompleteMultipartUpload);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectRemoved:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectRemoved);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectRemoved_Delete:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectRemoved_Delete);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectRemoved_DeleteMarkerCreated);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectRestore:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectRestore);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectRestore_Post:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectRestore_Post);
                    break;
                case Aws::S3Crt::Model::Event::s3_ObjectRestore_Completed:
                    this->events.Add(EAWSS3CRTEvent::s3_ObjectRestore_Completed);
                    break;
                case Aws::S3Crt::Model::Event::s3_Replication:
                    this->events.Add(EAWSS3CRTEvent::s3_Replication);
                    break;
                case Aws::S3Crt::Model::Event::s3_Replication_OperationFailedReplication:
                    this->events.Add(EAWSS3CRTEvent::s3_Replication_OperationFailedReplication);
                    break;
                case Aws::S3Crt::Model::Event::s3_Replication_OperationNotTracked:
                    this->events.Add(EAWSS3CRTEvent::s3_Replication_OperationNotTracked);
                    break;
                case Aws::S3Crt::Model::Event::s3_Replication_OperationMissedThreshold:
                    this->events.Add(EAWSS3CRTEvent::s3_Replication_OperationMissedThreshold);
                    break;
                case Aws::S3Crt::Model::Event::s3_Replication_OperationReplicatedAfterThreshold:
                    this->events.Add(EAWSS3CRTEvent::s3_Replication_OperationReplicatedAfterThreshold);
                    break;
                default:
                    break;
		    };
        }

        this->filter = FAWSS3CRTNotificationConfigurationFilter().fromAWS(awsTopicConfiguration.GetFilter());

        return *this;
    }
#endif
};
