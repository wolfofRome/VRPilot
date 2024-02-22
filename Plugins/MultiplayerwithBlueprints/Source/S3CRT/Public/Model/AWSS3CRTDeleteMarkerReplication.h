/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteMarkerReplication.h"

#endif

#include "Model/AWSS3CRTDeleteMarkerReplicationStatus.h"

#include "AWSS3CRTDeleteMarkerReplication.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteMarkerReplication {
GENERATED_BODY()

    /**
    *  <p>Indicates whether to replicate delete markers.</p>  <p>Indicates whether to replicate delete markers.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTDeleteMarkerReplicationStatus status = EAWSS3CRTDeleteMarkerReplicationStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::DeleteMarkerReplication toAWS() const {
        Aws::S3Crt::Model::DeleteMarkerReplication awsDeleteMarkerReplication;

        switch(this->status) {
            case EAWSS3CRTDeleteMarkerReplicationStatus::Enabled:
                awsDeleteMarkerReplication.SetStatus(Aws::S3Crt::Model::DeleteMarkerReplicationStatus::Enabled);
                break;
            case EAWSS3CRTDeleteMarkerReplicationStatus::Disabled:
                awsDeleteMarkerReplication.SetStatus(Aws::S3Crt::Model::DeleteMarkerReplicationStatus::Disabled);
                break;
            default:
                break;
        }

        return awsDeleteMarkerReplication;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3CRTDeleteMarkerReplicationStatus::NOT_SET;
    }

    FAWSS3CRTDeleteMarkerReplication &fromAWS(const Aws::S3Crt::Model::DeleteMarkerReplication &awsDeleteMarkerReplication) {
        switch(awsDeleteMarkerReplication.GetStatus()) {
            case Aws::S3Crt::Model::DeleteMarkerReplicationStatus::NOT_SET:
                this->status = EAWSS3CRTDeleteMarkerReplicationStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::DeleteMarkerReplicationStatus::Enabled:
                this->status = EAWSS3CRTDeleteMarkerReplicationStatus::Enabled;
                break;
            case Aws::S3Crt::Model::DeleteMarkerReplicationStatus::Disabled:
                this->status = EAWSS3CRTDeleteMarkerReplicationStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTDeleteMarkerReplicationStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
