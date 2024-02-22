/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ExistingObjectReplication.h"

#endif

#include "Model/ExistingObjectReplicationStatus.h"

#include "ExistingObjectReplication.generated.h"

USTRUCT(BlueprintType)
struct FExistingObjectReplication {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSExistingObjectReplicationStatus status = EAWSExistingObjectReplicationStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ExistingObjectReplication toAWS() const {
        Aws::S3::Model::ExistingObjectReplication awsExistingObjectReplication;

        switch(this->status) {
            case EAWSExistingObjectReplicationStatus::Enabled:
                awsExistingObjectReplication.SetStatus(Aws::S3::Model::ExistingObjectReplicationStatus::Enabled);
                break;
            case EAWSExistingObjectReplicationStatus::Disabled:
                awsExistingObjectReplication.SetStatus(Aws::S3::Model::ExistingObjectReplicationStatus::Disabled);
                break;
            default:
                break;
            }

        return awsExistingObjectReplication;
    }

    bool IsEmpty() const {
        return status == EAWSExistingObjectReplicationStatus::NOT_SET;
    }

    FExistingObjectReplication &fromAWS(const Aws::S3::Model::ExistingObjectReplication &awsExistingObjectReplication) {
        switch(awsExistingObjectReplication.GetStatus()) {
            case Aws::S3::Model::ExistingObjectReplicationStatus::NOT_SET:
                this->status = EAWSExistingObjectReplicationStatus::NOT_SET;
                break;
            case Aws::S3::Model::ExistingObjectReplicationStatus::Enabled:
                this->status = EAWSExistingObjectReplicationStatus::Enabled;
                break;
            case Aws::S3::Model::ExistingObjectReplicationStatus::Disabled:
                this->status = EAWSExistingObjectReplicationStatus::Disabled;
                break;
            default:
                this->status = EAWSExistingObjectReplicationStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
