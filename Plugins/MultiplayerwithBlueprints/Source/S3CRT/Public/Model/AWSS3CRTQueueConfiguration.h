/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/QueueConfiguration.h"

#endif

#include "Model/AWSS3CRTEvent.h"
#include "Model/AWSS3CRTNotificationConfigurationFilter.h"

#include "AWSS3CRTQueueConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTQueueConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon SQS queue to which Amazon S3 publishes a message when it detects events of the specified type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString queueArn;

    /**
    *  <p>A collection of bucket events for which to send notifications</p>
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
    Aws::S3Crt::Model::QueueConfiguration toAWS() const {
        Aws::S3Crt::Model::QueueConfiguration awsQueueConfiguration;

        if (!(this->id.IsEmpty())) {
            awsQueueConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->queueArn.IsEmpty())) {
            awsQueueConfiguration.SetQueueArn(TCHAR_TO_UTF8(*this->queueArn));
        }

        for (const EAWSS3CRTEvent& elem : this->events) {
		    switch(elem) {
                case EAWSS3CRTEvent::s3_ReducedRedundancyLostObject:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ReducedRedundancyLostObject);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Put:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Put);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Post:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Post);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Copy:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Copy);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_CompleteMultipartUpload:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_CompleteMultipartUpload);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved_Delete:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved_Delete);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved_DeleteMarkerCreated:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore_Post:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore_Post);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore_Completed:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore_Completed);
                    break;
                case EAWSS3CRTEvent::s3_Replication:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationFailedReplication:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationFailedReplication);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationNotTracked:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationNotTracked);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationMissedThreshold:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationMissedThreshold);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationReplicatedAfterThreshold:
                    awsQueueConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationReplicatedAfterThreshold);
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

    FAWSS3CRTQueueConfiguration &fromAWS(const Aws::S3Crt::Model::QueueConfiguration &awsQueueConfiguration) {
        this->id = UTF8_TO_TCHAR(awsQueueConfiguration.GetId().c_str());

        this->queueArn = UTF8_TO_TCHAR(awsQueueConfiguration.GetQueueArn().c_str());

        this->events.Empty();
        for (const Aws::S3Crt::Model::Event& elem : awsQueueConfiguration.GetEvents()) {
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

        this->filter = FAWSS3CRTNotificationConfigurationFilter().fromAWS(awsQueueConfiguration.GetFilter());

        return *this;
    }
#endif
};
