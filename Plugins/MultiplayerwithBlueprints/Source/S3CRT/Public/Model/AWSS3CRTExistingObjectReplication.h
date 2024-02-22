/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ExistingObjectReplication.h"

#endif

#include "Model/AWSS3CRTExistingObjectReplicationStatus.h"

#include "AWSS3CRTExistingObjectReplication.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTExistingObjectReplication {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTExistingObjectReplicationStatus status = EAWSS3CRTExistingObjectReplicationStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ExistingObjectReplication toAWS() const {
        Aws::S3Crt::Model::ExistingObjectReplication awsExistingObjectReplication;

        switch(this->status) {
            case EAWSS3CRTExistingObjectReplicationStatus::Enabled:
                awsExistingObjectReplication.SetStatus(Aws::S3Crt::Model::ExistingObjectReplicationStatus::Enabled);
                break;
            case EAWSS3CRTExistingObjectReplicationStatus::Disabled:
                awsExistingObjectReplication.SetStatus(Aws::S3Crt::Model::ExistingObjectReplicationStatus::Disabled);
                break;
            default:
                break;
        }

        return awsExistingObjectReplication;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3CRTExistingObjectReplicationStatus::NOT_SET;
    }

    FAWSS3CRTExistingObjectReplication &fromAWS(const Aws::S3Crt::Model::ExistingObjectReplication &awsExistingObjectReplication) {
        switch(awsExistingObjectReplication.GetStatus()) {
            case Aws::S3Crt::Model::ExistingObjectReplicationStatus::NOT_SET:
                this->status = EAWSS3CRTExistingObjectReplicationStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ExistingObjectReplicationStatus::Enabled:
                this->status = EAWSS3CRTExistingObjectReplicationStatus::Enabled;
                break;
            case Aws::S3Crt::Model::ExistingObjectReplicationStatus::Disabled:
                this->status = EAWSS3CRTExistingObjectReplicationStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTExistingObjectReplicationStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
