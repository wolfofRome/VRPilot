/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/LambdaFunctionConfiguration.h"

#endif

#include "Model/S3Event.h"
#include "Model/NotificationConfigurationFilter.h"

#include "LambdaFunctionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FLambdaFunctionConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>The Amazon Resource Name (ARN) of the AWS Lambda function that Amazon S3 invokes when the specified event type occurs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString lambdaFunctionArn;

    /**
    *  <p>The Amazon S3 bucket event for which to invoke the AWS Lambda function. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Supported Event Types</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
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
    Aws::S3::Model::LambdaFunctionConfiguration toAWS() const {
        Aws::S3::Model::LambdaFunctionConfiguration awsLambdaFunctionConfiguration;

		if (!(this->id.IsEmpty())) {
            awsLambdaFunctionConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

		if (!(this->lambdaFunctionArn.IsEmpty())) {
            awsLambdaFunctionConfiguration.SetLambdaFunctionArn(TCHAR_TO_UTF8(*this->lambdaFunctionArn));
        }

        for (const ES3Event& elem : this->events) {
		    switch(elem) {
                case ES3Event::s3_ReducedRedundancyLostObject:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ReducedRedundancyLostObject);
                        break;
                case ES3Event::s3_ObjectCreated:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated);
                        break;
                case ES3Event::s3_ObjectCreated_Put:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Put);
                        break;
                case ES3Event::s3_ObjectCreated_Post:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Post);
                        break;
                case ES3Event::s3_ObjectCreated_Copy:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_Copy);
                        break;
                case ES3Event::s3_ObjectCreated_CompleteMultipartUpload:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectCreated_CompleteMultipartUpload);
                        break;
                case ES3Event::s3_ObjectRemoved:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved);
                        break;
                case ES3Event::s3_ObjectRemoved_Delete:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved_Delete);
                        break;
                case ES3Event::s3_ObjectRemoved_DeleteMarkerCreated:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRemoved_DeleteMarkerCreated);
                        break;
                case ES3Event::s3_ObjectRestore:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore);
                        break;
                case ES3Event::s3_ObjectRestore_Post:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Post);
                        break;
                case ES3Event::s3_ObjectRestore_Completed:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Completed);
                        break;
                case ES3Event::s3_Replication:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication);
                        break;
                case ES3Event::s3_Replication_OperationFailedReplication:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationFailedReplication);
                        break;
                case ES3Event::s3_Replication_OperationNotTracked:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationNotTracked);
                        break;
                case ES3Event::s3_Replication_OperationMissedThreshold:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationMissedThreshold);
                        break;
                case ES3Event::s3_Replication_OperationReplicatedAfterThreshold:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_Replication_OperationReplicatedAfterThreshold);
                        break;
                case ES3Event::s3_ObjectRestore_Delete:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectRestore_Delete);
                        break;
                case ES3Event::s3_LifecycleTransition:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleTransition);
                        break;
                case ES3Event::s3_IntelligentTiering:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_IntelligentTiering);
                        break;
                case ES3Event::s3_ObjectAcl_Put:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectAcl_Put);
                        break;
                case ES3Event::s3_LifecycleExpiration:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration);
                        break;
                case ES3Event::s3_LifecycleExpiration_Delete:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration_Delete);
                        break;
                case ES3Event::s3_LifecycleExpiration_DeleteMarkerCreated:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_LifecycleExpiration_DeleteMarkerCreated);
                        break;
                case ES3Event::s3_ObjectTagging:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging);
                        break;
                case ES3Event::s3_ObjectTagging_Put:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging_Put);
                        break;
                case ES3Event::s3_ObjectTagging_Delete:
                        awsLambdaFunctionConfiguration.AddEvents(Aws::S3::Model::Event::s3_ObjectTagging_Delete);
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

    FLambdaFunctionConfiguration &fromAWS(const Aws::S3::Model::LambdaFunctionConfiguration &awsLambdaFunctionConfiguration) {
        this->id = UTF8_TO_TCHAR(awsLambdaFunctionConfiguration.GetId().c_str());

        this->lambdaFunctionArn = UTF8_TO_TCHAR(awsLambdaFunctionConfiguration.GetLambdaFunctionArn().c_str());

        this->events.Empty();
        for (const Aws::S3::Model::Event& elem : awsLambdaFunctionConfiguration.GetEvents()) {
            switch(elem) {
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

        this->filter.fromAWS(awsLambdaFunctionConfiguration.GetFilter());

        return *this;
    }
#endif
};
