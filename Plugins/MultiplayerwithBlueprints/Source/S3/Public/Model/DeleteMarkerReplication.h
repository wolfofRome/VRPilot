/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteMarkerReplication.h"

#endif

#include "Model/DeleteMarkerReplicationStatus.h"

#include "DeleteMarkerReplication.generated.h"

USTRUCT(BlueprintType)
struct FDeleteMarkerReplication {
GENERATED_BODY()

    /**
    *  <p>Indicates whether to replicate delete markers.</p>  <p> In the current implementation, Amazon S3 doesn't replicate the delete markers. The status must be <code>Disabled</code>. </p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSDeleteMarkerReplicationStatus status = EAWSDeleteMarkerReplicationStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::DeleteMarkerReplication toAWS() const {
        Aws::S3::Model::DeleteMarkerReplication awsDeleteMarkerReplication;

        switch(this->status) {
            case EAWSDeleteMarkerReplicationStatus::Enabled:
                awsDeleteMarkerReplication.SetStatus(Aws::S3::Model::DeleteMarkerReplicationStatus::Enabled);
                break;
            case EAWSDeleteMarkerReplicationStatus::Disabled:
                awsDeleteMarkerReplication.SetStatus(Aws::S3::Model::DeleteMarkerReplicationStatus::Disabled);
                break;
            default:
                break;
        }

        return awsDeleteMarkerReplication;
    }

    bool IsEmpty() const {
        return status == EAWSDeleteMarkerReplicationStatus::NOT_SET;
    }

    FDeleteMarkerReplication &fromAWS(const Aws::S3::Model::DeleteMarkerReplication &awsDeleteMarkerReplication) {
        switch(awsDeleteMarkerReplication.GetStatus()) {
            case Aws::S3::Model::DeleteMarkerReplicationStatus::NOT_SET:
                this->status = EAWSDeleteMarkerReplicationStatus::NOT_SET;
                break;
            case Aws::S3::Model::DeleteMarkerReplicationStatus::Enabled:
                this->status = EAWSDeleteMarkerReplicationStatus::Enabled;
                break;
            case Aws::S3::Model::DeleteMarkerReplicationStatus::Disabled:
                this->status = EAWSDeleteMarkerReplicationStatus::Disabled;
                break;
            default:
                this->status = EAWSDeleteMarkerReplicationStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
