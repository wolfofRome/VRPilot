/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/SourceSelectionCriteria.h"

#endif

#include "Model/SseKmsEncryptedObjects.h"
#include "Model/AWSS3ReplicaModifications.h"

#include "SourceSelectionCriteria.generated.h"

USTRUCT(BlueprintType)
struct FSourceSelectionCriteria {
GENERATED_BODY()

    /**
    *  <p> A container for filter information for the selection of Amazon S3 objects encrypted with AWS KMS. If you include <code>SourceSelectionCriteria</code> in the replication configuration, this element is required. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FSseKmsEncryptedObjects sseKmsEncryptedObjects;

    /**
    *  <p>A filter that you can specify for selections for modifications on replicas. Amazon S3 doesn't replicate replica modifications by default. In the latest version of replication configuration (when <code>Filter</code> is specified), you can specify this element and set the status to <code>Enabled</code> to replicate modifications on replicas. </p>  <p> If you don't specify the <code>Filter</code> element, Amazon S3 assumes that the replication configuration is the earlier version, V1. In the earlier version, this element is not allowed</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3ReplicaModifications replicaModifications;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::SourceSelectionCriteria toAWS() const {
        Aws::S3::Model::SourceSelectionCriteria awsSourceSelectionCriteria;

        if (!(this->sseKmsEncryptedObjects.IsEmpty())) {
            awsSourceSelectionCriteria.SetSseKmsEncryptedObjects(this->sseKmsEncryptedObjects.toAWS());
        }

        if (!(this->replicaModifications.IsEmpty())) {
            awsSourceSelectionCriteria.SetReplicaModifications(this->replicaModifications.toAWS());
        }

        return awsSourceSelectionCriteria;
    }

    bool IsEmpty() const {
        return this->sseKmsEncryptedObjects.IsEmpty() && this->replicaModifications.IsEmpty();
    }

    FSourceSelectionCriteria &fromAWS(const Aws::S3::Model::SourceSelectionCriteria &awsSourceSelectionCriteria) {
        this->sseKmsEncryptedObjects.fromAWS(awsSourceSelectionCriteria.GetSseKmsEncryptedObjects());

        this->replicaModifications.fromAWS(awsSourceSelectionCriteria.GetReplicaModifications());

        return *this;
    }
#endif
};
