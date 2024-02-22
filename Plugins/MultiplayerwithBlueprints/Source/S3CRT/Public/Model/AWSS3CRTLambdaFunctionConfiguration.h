/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/LambdaFunctionConfiguration.h"

#endif

#include "Model/AWSS3CRTEvent.h"
#include "Model/AWSS3CRTNotificationConfigurationFilter.h"

#include "AWSS3CRTLambdaFunctionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTLambdaFunctionConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>The Amazon Resource Name (ARN) of the AWS Lambda function that Amazon S3 invokes when the specified event type occurs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString lambdaFunctionArn;

    /**
    *  <p>The Amazon S3 bucket event for which to invoke the AWS Lambda function. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Supported Event Types</a> in the <i>Amazon S3 User Guide</i>.</p>
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
    Aws::S3Crt::Model::LambdaFunctionConfiguration toAWS() const {
        Aws::S3Crt::Model::LambdaFunctionConfiguration awsLambdaFunctionConfiguration;

        if (!(this->id.IsEmpty())) {
            awsLambdaFunctionConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->lambdaFunctionArn.IsEmpty())) {
            awsLambdaFunctionConfiguration.SetLambdaFunctionArn(TCHAR_TO_UTF8(*this->lambdaFunctionArn));
        }

        for (const EAWSS3CRTEvent& elem : this->events) {
		    switch(elem) {
                case EAWSS3CRTEvent::s3_ReducedRedundancyLostObject:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ReducedRedundancyLostObject);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Put:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Put);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Post:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Post);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_Copy:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_Copy);
                    break;
                case EAWSS3CRTEvent::s3_ObjectCreated_CompleteMultipartUpload:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectCreated_CompleteMultipartUpload);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved_Delete:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved_Delete);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRemoved_DeleteMarkerCreated:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore_Post:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore_Post);
                    break;
                case EAWSS3CRTEvent::s3_ObjectRestore_Completed:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_ObjectRestore_Completed);
                    break;
                case EAWSS3CRTEvent::s3_Replication:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationFailedReplication:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationFailedReplication);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationNotTracked:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationNotTracked);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationMissedThreshold:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationMissedThreshold);
                    break;
                case EAWSS3CRTEvent::s3_Replication_OperationReplicatedAfterThreshold:
                    awsLambdaFunctionConfiguration.AddEvents(Aws::S3Crt::Model::Event::s3_Replication_OperationReplicatedAfterThreshold);
                    break;
                default:
                    break;
            };
        }

        if (!(this->filter.IsEmpty())) {
            awsLambdaFunctionConfiguration.SetFilter(this->filter.toAWS());
        }

        return awsLambdaFunctionConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->lambdaFunctionArn.IsEmpty() && this->events.Num() == 0 && this->filter.IsEmpty();
    }

    FAWSS3CRTLambdaFunctionConfiguration &fromAWS(const Aws::S3Crt::Model::LambdaFunctionConfiguration &awsLambdaFunctionConfiguration) {
        this->id = UTF8_TO_TCHAR(awsLambdaFunctionConfiguration.GetId().c_str());

        this->lambdaFunctionArn = UTF8_TO_TCHAR(awsLambdaFunctionConfiguration.GetLambdaFunctionArn().c_str());

        this->events.Empty();
        for (const Aws::S3Crt::Model::Event& elem : awsLambdaFunctionConfiguration.GetEvents()) {
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

        this->filter = FAWSS3CRTNotificationConfigurationFilter().fromAWS(awsLambdaFunctionConfiguration.GetFilter());

        return *this;
    }
#endif
};
