/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/TopicConfiguration.h"

#endif

#include "Model/S3Event.h"
#include "Model/NotificationConfigurationFilter.h"

#include "TopicConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FTopicConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon SNS topic to which Amazon S3 publishes a message when it detects events of the specified type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString topicArn;

    /**
    *  <p>The Amazon S3 bucket event about which to send notifications. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Supported Event Types</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<ES3Event> events;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FNotificationConfigurationFilter filter;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::TopicConfiguration toAWS() const {
        Aws::S3::Model::TopicConfiguration awsTopicConfiguration;

		if (!(this->id.IsEmpty())) {
            awsTopicConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

		if (!(this->topicArn.IsEmpty())) {
            awsTopicConfiguration.SetTopicArn(TCHAR_TO_UTF8(*this->topicArn));
        }

        for (const ES3Event& elem : this->events) {
		    switch(elem) {
                case ES3Event::s3_ReducedRedundancyLostObject:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ReducedRedundancyLostObject);
                        break;
                case ES3Event::s3_ObjectCreated:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated);
                        break;
                case ES3Event::s3_ObjectCreated_Put:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Put);
                        break;
                case ES3Event::s3_ObjectCreated_Post:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Post);
                        break;
                case ES3Event::s3_ObjectCreated_Copy:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Copy);
                        break;
                case ES3Event::s3_ObjectCreated_CompleteMultipartUpload:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_CompleteMultipartUpload);
                        break;
                case ES3Event::s3_ObjectRemoved:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved);
                        break;
                case ES3Event::s3_ObjectRemoved_Delete:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved_Delete);
                        break;
                case ES3Event::s3_ObjectRemoved_DeleteMarkerCreated:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated);
                        break;
                case ES3Event::s3_ObjectRestore:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore);
                        break;
                case ES3Event::s3_ObjectRestore_Post:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Post);
                        break;
                case ES3Event::s3_ObjectRestore_Completed:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Completed);
                        break;
                case ES3Event::s3_Replication:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication);
                        break;
                case ES3Event::s3_Replication_OperationFailedReplication:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationFailedReplication);
                        break;
                case ES3Event::s3_Replication_OperationNotTracked:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationNotTracked);
                        break;
                case ES3Event::s3_Replication_OperationMissedThreshold:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationMissedThreshold);
                        break;
                case ES3Event::s3_Replication_OperationReplicatedAfterThreshold:
                        awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationReplicatedAfterThreshold);
                        break;
            case ES3Event::s3_ObjectRestore_Delete:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Delete);
                    break;
            case ES3Event::s3_LifecycleTransition:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleTransition);
                    break;
            case ES3Event::s3_IntelligentTiering:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_IntelligentTiering);
                    break;
            case ES3Event::s3_ObjectAcl_Put:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectAcl_Put);
                    break;
            case ES3Event::s3_LifecycleExpiration:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration);
                    break;
            case ES3Event::s3_LifecycleExpiration_Delete:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration_Delete);
                    break;
            case ES3Event::s3_LifecycleExpiration_DeleteMarkerCreated:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration_DeleteMarkerCreated);
                    break;
            case ES3Event::s3_ObjectTagging:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging);
                    break;
            case ES3Event::s3_ObjectTagging_Put:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging_Put);
                    break;
            case ES3Event::s3_ObjectTagging_Delete:
                    awsTopicConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging_Delete);
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

    FTopicConfiguration &fromAWS(const Aws::S3::Model::TopicConfiguration &awsTopicConfiguration) {
        this->id = UTF8_TO_TCHAR(awsTopicConfiguration.GetId().c_str());

        this->topicArn = UTF8_TO_TCHAR(awsTopicConfiguration.GetTopicArn().c_str());

        this->events.Empty();
        for (const Aws::S3::Model::Event& elem : awsTopicConfiguration.GetEvents()) {
            switch(elem) {
                case Aws::S3::Model::Event::NOT_SET:
                    this->events.Add(ES3Event::NOT_SET);
                    break;
                case Aws::S3::Model::Event::s3_ReducedRedundancyLostObject:
                    this->events.Add(ES3Event::s3_ReducedRedundancyLostObject);
                    break;
                case Aws::S3::Model::Event::s3_ObjectCreated:
                    this->events.Add(ES3Event::s3_ObjectCreated);
                    break;
                case Aws::S3::Model::Event::s3_ObjectCreated_Put:
                    this->events.Add(ES3Event::s3_ObjectCreated_Put);
                    break;
                case Aws::S3::Model::Event::s3_ObjectCreated_Post:
                    this->events.Add(ES3Event::s3_ObjectCreated_Post);
                    break;
                case Aws::S3::Model::Event::s3_ObjectCreated_Copy:
                    this->events.Add(ES3Event::s3_ObjectCreated_Copy);
                    break;
                case Aws::S3::Model::Event::s3_ObjectCreated_CompleteMultipartUpload:
                    this->events.Add(ES3Event::s3_ObjectCreated_CompleteMultipartUpload);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRemoved:
                    this->events.Add(ES3Event::s3_ObjectRemoved);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRemoved_Delete:
                    this->events.Add(ES3Event::s3_ObjectRemoved_Delete);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated:
                    this->events.Add(ES3Event::s3_ObjectRemoved_DeleteMarkerCreated);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRestore:
                    this->events.Add(ES3Event::s3_ObjectRestore);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRestore_Post:
                    this->events.Add(ES3Event::s3_ObjectRestore_Post);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRestore_Completed:
                    this->events.Add(ES3Event::s3_ObjectRestore_Completed);
                    break;
                case Aws::S3::Model::Event::s3_Replication:
                    this->events.Add(ES3Event::s3_Replication);
                    break;
                case Aws::S3::Model::Event::s3_Replication_OperationFailedReplication:
                    this->events.Add(ES3Event::s3_Replication_OperationFailedReplication);
                    break;
                case Aws::S3::Model::Event::s3_Replication_OperationNotTracked:
                    this->events.Add(ES3Event::s3_Replication_OperationNotTracked);
                    break;
                case Aws::S3::Model::Event::s3_Replication_OperationMissedThreshold:
                    this->events.Add(ES3Event::s3_Replication_OperationMissedThreshold);
                    break;
                case Aws::S3::Model::Event::s3_Replication_OperationReplicatedAfterThreshold:
                    this->events.Add(ES3Event::s3_Replication_OperationReplicatedAfterThreshold);
                    break;
                case Aws::S3::Model::Event::s3_ObjectRestore_Delete:
                    this->events.Add(ES3Event::s3_ObjectRestore_Delete);
                    break;
                case Aws::S3::Model::Event::s3_LifecycleTransition:
                    this->events.Add(ES3Event::s3_LifecycleTransition);
                    break;
                case Aws::S3::Model::Event::s3_IntelligentTiering:
                    this->events.Add(ES3Event::s3_IntelligentTiering);
                    break;
                case Aws::S3::Model::Event::s3_ObjectAcl_Put:
                    this->events.Add(ES3Event::s3_ObjectAcl_Put);
                    break;
                case Aws::S3::Model::Event::s3_LifecycleExpiration:
                    this->events.Add(ES3Event::s3_LifecycleExpiration);
                    break;
                case Aws::S3::Model::Event::s3_LifecycleExpiration_Delete:
                    this->events.Add(ES3Event::s3_LifecycleExpiration_Delete);
                    break;
                case Aws::S3::Model::Event::s3_LifecycleExpiration_DeleteMarkerCreated:
                    this->events.Add(ES3Event::s3_LifecycleExpiration_DeleteMarkerCreated);
                    break;
                case Aws::S3::Model::Event::s3_ObjectTagging:
                    this->events.Add(ES3Event::s3_ObjectTagging);
                    break;
                case Aws::S3::Model::Event::s3_ObjectTagging_Put:
                    this->events.Add(ES3Event::s3_ObjectTagging_Put);
                    break;
                case Aws::S3::Model::Event::s3_ObjectTagging_Delete:
                    this->events.Add(ES3Event::s3_ObjectTagging_Delete);
                    break;
                default:
                    this->events.Add(ES3Event::NOT_SET);
                    break;
		    };
        }

        this->filter.fromAWS(awsTopicConfiguration.GetFilter());

        return *this;
    }
#endif
};
