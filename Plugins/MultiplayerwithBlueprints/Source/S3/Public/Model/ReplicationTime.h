/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ReplicationTime.h"

#endif

#include "Model/ReplicationTimeStatus.h"
#include "Model/ReplicationTimeValue.h"

#include "ReplicationTime.generated.h"

USTRUCT(BlueprintType)
struct FReplicationTime {
GENERATED_BODY()

    /**
    *  <p> Specifies whether the replication time is enabled. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSReplicationTimeStatus status = EAWSReplicationTimeStatus::NOT_SET;

    /**
    *  <p> A container specifying the time by which replication should be complete for all objects and operations on objects. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FReplicationTimeValue time;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ReplicationTime toAWS() const {
        Aws::S3::Model::ReplicationTime awsReplicationTime;

        switch(this->status) {
            case EAWSReplicationTimeStatus::Enabled:
                awsReplicationTime.SetStatus(Aws::S3::Model::ReplicationTimeStatus::Enabled);
                break;
            case EAWSReplicationTimeStatus::Disabled:
                awsReplicationTime.SetStatus(Aws::S3::Model::ReplicationTimeStatus::Disabled);
                break;
            default:
                break;
        }

        if (!(this->time.IsEmpty())) {
            awsReplicationTime.SetTime(this->time.toAWS());
        }

        return awsReplicationTime;
    }

    bool IsEmpty() const {
        return status == EAWSReplicationTimeStatus::NOT_SET && this->time.IsEmpty();
    }

    FReplicationTime &fromAWS(const Aws::S3::Model::ReplicationTime &awsReplicationTime) {
        switch(awsReplicationTime.GetStatus()) {
            case Aws::S3::Model::ReplicationTimeStatus::NOT_SET:
                this->status = EAWSReplicationTimeStatus::NOT_SET;
                break;
            case Aws::S3::Model::ReplicationTimeStatus::Enabled:
                this->status = EAWSReplicationTimeStatus::Enabled;
                break;
            case Aws::S3::Model::ReplicationTimeStatus::Disabled:
                this->status = EAWSReplicationTimeStatus::Disabled;
                break;
            default:
                this->status = EAWSReplicationTimeStatus::NOT_SET;
                break;
        }

        this->time.fromAWS(awsReplicationTime.GetTime());

        return *this;
    }
#endif
};
