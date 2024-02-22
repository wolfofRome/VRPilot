/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ReplicaModifications.h"

#endif

#include "Model/AWSS3CRTReplicaModificationsStatus.h"

#include "AWSS3CRTReplicaModifications.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTReplicaModifications {
GENERATED_BODY()

    /**
    *  <p>Specifies whether Amazon S3 replicates modifications on replicas.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTReplicaModificationsStatus status = EAWSS3CRTReplicaModificationsStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ReplicaModifications toAWS() const {
        Aws::S3Crt::Model::ReplicaModifications awsReplicaModifications;

        switch(this->status) {
            case EAWSS3CRTReplicaModificationsStatus::Enabled:
                awsReplicaModifications.SetStatus(Aws::S3Crt::Model::ReplicaModificationsStatus::Enabled);
                break;
            case EAWSS3CRTReplicaModificationsStatus::Disabled:
                awsReplicaModifications.SetStatus(Aws::S3Crt::Model::ReplicaModificationsStatus::Disabled);
                break;
            default:
                break;
        }

        return awsReplicaModifications;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3CRTReplicaModificationsStatus::NOT_SET;
    }

    FAWSS3CRTReplicaModifications &fromAWS(const Aws::S3Crt::Model::ReplicaModifications &awsReplicaModifications) {
        switch(awsReplicaModifications.GetStatus()) {
            case Aws::S3Crt::Model::ReplicaModificationsStatus::NOT_SET:
                this->status = EAWSS3CRTReplicaModificationsStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ReplicaModificationsStatus::Enabled:
                this->status = EAWSS3CRTReplicaModificationsStatus::Enabled;
                break;
            case Aws::S3Crt::Model::ReplicaModificationsStatus::Disabled:
                this->status = EAWSS3CRTReplicaModificationsStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTReplicaModificationsStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
