/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobManifestGeneratorFilter.h"

#endif

#include "Model/AWSS3ControlReplicationStatus.h"

#include "AWSS3ControlJobManifestGeneratorFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlJobManifestGeneratorFilter {
GENERATED_BODY()

    /**
    *  <p>Include objects in the generated manifest only if they are eligible for replication according to the Replication configuration on the source bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool eligibleForReplication = false;

    /**
    *  <p>If provided, the generated manifest should include only source bucket objects that were created after this time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime createdAfter;

    /**
    *  <p>If provided, the generated manifest should include only source bucket objects that were created before this time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime createdBefore;

    /**
    *  <p>If provided, the generated manifest should include only source bucket objects that have one of the specified Replication statuses.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<EAWSS3ControlReplicationStatus> objectReplicationStatuses;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobManifestGeneratorFilter toAWS() const {
        Aws::S3Control::Model::JobManifestGeneratorFilter awsJobManifestGeneratorFilter;

        awsJobManifestGeneratorFilter.SetEligibleForReplication(this->eligibleForReplication);

        if (!(this->createdAfter.ToUnixTimestamp() <= 0)) {
            awsJobManifestGeneratorFilter.SetCreatedAfter(Aws::Utils::DateTime((int64_t)((this->createdAfter - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->createdBefore.ToUnixTimestamp() <= 0)) {
            awsJobManifestGeneratorFilter.SetCreatedBefore(Aws::Utils::DateTime((int64_t)((this->createdBefore - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        for (const EAWSS3ControlReplicationStatus& elem : this->objectReplicationStatuses) {
		    switch(elem) {
                case EAWSS3ControlReplicationStatus::COMPLETED:
                    awsJobManifestGeneratorFilter.AddObjectReplicationStatuses(Aws::S3Control::Model::ReplicationStatus::COMPLETED);
                    break;
            case EAWSS3ControlReplicationStatus::FAILED:
                    awsJobManifestGeneratorFilter.AddObjectReplicationStatuses(Aws::S3Control::Model::ReplicationStatus::FAILED);
                    break;
            case EAWSS3ControlReplicationStatus::REPLICA:
                    awsJobManifestGeneratorFilter.AddObjectReplicationStatuses(Aws::S3Control::Model::ReplicationStatus::REPLICA);
                    break;
            case EAWSS3ControlReplicationStatus::NONE:
                    awsJobManifestGeneratorFilter.AddObjectReplicationStatuses(Aws::S3Control::Model::ReplicationStatus::NONE);
                    break;
            default:
                break;
            };
        }

        return awsJobManifestGeneratorFilter;
    }

    bool IsEmpty() const {
        return false && this->createdAfter.ToUnixTimestamp() <= 0 && this->createdBefore.ToUnixTimestamp() <= 0 && this->objectReplicationStatuses.Num() == 0;
    }

    FAWSS3ControlJobManifestGeneratorFilter &fromAWS(const Aws::S3Control::Model::JobManifestGeneratorFilter &awsJobManifestGeneratorFilter) {
        this->eligibleForReplication = awsJobManifestGeneratorFilter.GetEligibleForReplication();

        this->createdAfter = FDateTime(1970, 1, 1) + FTimespan(awsJobManifestGeneratorFilter.GetCreatedAfter().Millis() * ETimespan::TicksPerMillisecond);

        this->createdBefore = FDateTime(1970, 1, 1) + FTimespan(awsJobManifestGeneratorFilter.GetCreatedBefore().Millis() * ETimespan::TicksPerMillisecond);

        this->objectReplicationStatuses.Empty();
        for (const Aws::S3Control::Model::ReplicationStatus& elem : awsJobManifestGeneratorFilter.GetObjectReplicationStatuses()) {
            switch(elem) {
                case Aws::S3Control::Model::ReplicationStatus::NOT_SET:
                    this->objectReplicationStatuses.Add(EAWSS3ControlReplicationStatus::NOT_SET);
                    break;
                case Aws::S3Control::Model::ReplicationStatus::COMPLETED:
                    this->objectReplicationStatuses.Add(EAWSS3ControlReplicationStatus::COMPLETED);
                    break;
                case Aws::S3Control::Model::ReplicationStatus::FAILED:
                    this->objectReplicationStatuses.Add(EAWSS3ControlReplicationStatus::FAILED);
                    break;
                case Aws::S3Control::Model::ReplicationStatus::REPLICA:
                    this->objectReplicationStatuses.Add(EAWSS3ControlReplicationStatus::REPLICA);
                    break;
                case Aws::S3Control::Model::ReplicationStatus::NONE:
                    this->objectReplicationStatuses.Add(EAWSS3ControlReplicationStatus::NONE);
                    break;
                default:
                    break;
		    };
        }

        return *this;
    }
#endif
};
