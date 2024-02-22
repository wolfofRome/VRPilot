/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ReplicaModifications.h"

#endif

#include "Model/AWSS3ReplicaModificationsStatus.h"
#include "AWSS3ReplicaModifications.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ReplicaModifications {
GENERATED_BODY()

    /**
    *  <p>Specifies whether Amazon S3 replicates modifications on replicas.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ReplicaModificationsStatus status = EAWSS3ReplicaModificationsStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ReplicaModifications toAWS() const {
        Aws::S3::Model::ReplicaModifications awsReplicaModifications;

        switch(this->status) {
            case EAWSS3ReplicaModificationsStatus::Enabled:
                awsReplicaModifications.SetStatus(Aws::S3::Model::ReplicaModificationsStatus::Enabled);
                break;
            case EAWSS3ReplicaModificationsStatus::Disabled:
                awsReplicaModifications.SetStatus(Aws::S3::Model::ReplicaModificationsStatus::Disabled);
                break;
            default:
                break;
        }

        return awsReplicaModifications;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3ReplicaModificationsStatus::NOT_SET;
    }

    FAWSS3ReplicaModifications &fromAWS(const Aws::S3::Model::ReplicaModifications &awsReplicaModifications) {
        switch(awsReplicaModifications.GetStatus()) {
            case Aws::S3::Model::ReplicaModificationsStatus::NOT_SET:
                this->status = EAWSS3ReplicaModificationsStatus::NOT_SET;
                break;
            case Aws::S3::Model::ReplicaModificationsStatus::Enabled:
                this->status = EAWSS3ReplicaModificationsStatus::Enabled;
                break;
            case Aws::S3::Model::ReplicaModificationsStatus::Disabled:
                this->status = EAWSS3ReplicaModificationsStatus::Disabled;
                break;
            default:
                this->status = EAWSS3ReplicaModificationsStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
