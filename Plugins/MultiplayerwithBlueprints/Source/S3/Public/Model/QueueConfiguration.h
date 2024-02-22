/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/QueueConfiguration.h"

#endif

#include "Model/S3Event.h"
#include "Model/NotificationConfigurationFilter.h"

#include "QueueConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FQueueConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon SQS queue to which Amazon S3 publishes a message when it detects events of the specified type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString queueArn;

    /**
    *  <p>A collection of bucket events for which to send notifications</p>
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
    Aws::S3::Model::QueueConfiguration toAWS() const {
        Aws::S3::Model::QueueConfiguration awsQueueConfiguration;

		if (!(this->id.IsEmpty())) {
            awsQueueConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

		if (!(this->queueArn.IsEmpty())) {
            awsQueueConfiguration.SetQueueArn(TCHAR_TO_UTF8(*this->queueArn));
        }

        for (const ES3Event& elem : this->events) {
		    switch(elem) {
                case ES3Event::s3_ReducedRedundancyLostObject:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ReducedRedundancyLostObject);
                        break;
                case ES3Event::s3_ObjectCreated:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated);
                        break;
                case ES3Event::s3_ObjectCreated_Put:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Put);
                        break;
                case ES3Event::s3_ObjectCreated_Post:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Post);
                        break;
                case ES3Event::s3_ObjectCreated_Copy:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Copy);
                        break;
                case ES3Event::s3_ObjectCreated_CompleteMultipartUpload:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_CompleteMultipartUpload);
                        break;
                case ES3Event::s3_ObjectRemoved:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved);
                        break;
                case ES3Event::s3_ObjectRemoved_Delete:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved_Delete);
                        break;
                case ES3Event::s3_ObjectRemoved_DeleteMarkerCreated:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated);
                        break;
                case ES3Event::s3_ObjectRestore:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore);
                        break;
                case ES3Event::s3_ObjectRestore_Post:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Post);
                        break;
                case ES3Event::s3_ObjectRestore_Completed:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Completed);
                        break;
                case ES3Event::s3_Replication:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication);
                        break;
                case ES3Event::s3_Replication_OperationFailedReplication:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationFailedReplication);
                        break;
                case ES3Event::s3_Replication_OperationNotTracked:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationNotTracked);
                        break;
                case ES3Event::s3_Replication_OperationMissedThreshold:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationMissedThreshold);
                        break;
                case ES3Event::s3_Replication_OperationReplicatedAfterThreshold:
                        awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationReplicatedAfterThreshold);
                        break;
            case ES3Event::s3_ObjectRestore_Delete:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Delete);
                    break;
            case ES3Event::s3_LifecycleTransition:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleTransition);
                    break;
            case ES3Event::s3_IntelligentTiering:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_IntelligentTiering);
                    break;
            case ES3Event::s3_ObjectAcl_Put:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectAcl_Put);
                    break;
            case ES3Event::s3_LifecycleExpiration:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration);
                    break;
            case ES3Event::s3_LifecycleExpiration_Delete:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration_Delete);
                    break;
            case ES3Event::s3_LifecycleExpiration_DeleteMarkerCreated:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration_DeleteMarkerCreated);
                    break;
            case ES3Event::s3_ObjectTagging:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging);
                    break;
            case ES3Event::s3_ObjectTagging_Put:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging_Put);
                    break;
            case ES3Event::s3_ObjectTagging_Delete:
                    awsQueueConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging_Delete);
                    break;
                default:
                    break;
            };
        }

        if (!(this->filter.IsEmpty())) {
            awsQueueConfiguration.SetFilter(this->filter.toAWS());
        }

        return awsQueueConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->queueArn.IsEmpty() && this->events.Num() == 0 && this->filter.IsEmpty();
    }

    FQueueConfiguration &fromAWS(const Aws::S3::Model::QueueConfiguration &awsQueueConfiguration) {
        this->id = UTF8_TO_TCHAR(awsQueueConfiguration.GetId().c_str());

        this->queueArn = UTF8_TO_TCHAR(awsQueueConfiguration.GetQueueArn().c_str());

        this->events.Empty();
        for (const Aws::S3::Model::Event& elem : awsQueueConfiguration.GetEvents()) {
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
                    break;
		    };
        }

        this->filter.fromAWS(awsQueueConfiguration.GetFilter());

        return *this;
    }
#endif
};
