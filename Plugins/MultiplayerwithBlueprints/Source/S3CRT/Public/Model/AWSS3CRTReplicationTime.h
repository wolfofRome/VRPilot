/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ReplicationTime.h"

#endif

#include "Model/AWSS3CRTReplicationTimeStatus.h"
#include "Model/AWSS3CRTReplicationTimeValue.h"

#include "AWSS3CRTReplicationTime.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTReplicationTime {
GENERATED_BODY()

    /**
    *  <p> Specifies whether the replication time is enabled. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTReplicationTimeStatus status = EAWSS3CRTReplicationTimeStatus::NOT_SET;

    /**
    *  <p> A container specifying the time by which replication should be complete for all objects and operations on objects. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTReplicationTimeValue time;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ReplicationTime toAWS() const {
        Aws::S3Crt::Model::ReplicationTime awsReplicationTime;

        switch(this->status) {
            case EAWSS3CRTReplicationTimeStatus::Enabled:
                awsReplicationTime.SetStatus(Aws::S3Crt::Model::ReplicationTimeStatus::Enabled);
                break;
            case EAWSS3CRTReplicationTimeStatus::Disabled:
                awsReplicationTime.SetStatus(Aws::S3Crt::Model::ReplicationTimeStatus::Disabled);
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
        return this->status == EAWSS3CRTReplicationTimeStatus::NOT_SET && this->time.IsEmpty();
    }

    FAWSS3CRTReplicationTime &fromAWS(const Aws::S3Crt::Model::ReplicationTime &awsReplicationTime) {
        switch(awsReplicationTime.GetStatus()) {
            case Aws::S3Crt::Model::ReplicationTimeStatus::NOT_SET:
                this->status = EAWSS3CRTReplicationTimeStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ReplicationTimeStatus::Enabled:
                this->status = EAWSS3CRTReplicationTimeStatus::Enabled;
                break;
            case Aws::S3Crt::Model::ReplicationTimeStatus::Disabled:
                this->status = EAWSS3CRTReplicationTimeStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTReplicationTimeStatus::NOT_SET;
                break;
        }

        this->time = FAWSS3CRTReplicationTimeValue().fromAWS(awsReplicationTime.GetTime());

        return *this;
    }
#endif
};
