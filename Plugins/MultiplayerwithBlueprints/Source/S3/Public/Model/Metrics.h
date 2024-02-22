/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Metrics.h"

#endif

#include "Model/MetricsStatus.h"
#include "Model/ReplicationTimeValue.h"

#include "Metrics.generated.h"

USTRUCT(BlueprintType)
struct FMetrics {
GENERATED_BODY()

    /**
    *  <p> Specifies whether the replication metrics are enabled. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSMetricsStatus status = EAWSMetricsStatus::NOT_SET;

    /**
    *  <p> A container specifying the time threshold for emitting the <code>s3:Replication:OperationMissedThreshold</code> event. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FReplicationTimeValue eventThreshold;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Metrics toAWS() const {
        Aws::S3::Model::Metrics awsMetrics;

        switch(this->status) {
            case EAWSMetricsStatus::Enabled:
                awsMetrics.SetStatus(Aws::S3::Model::MetricsStatus::Enabled);
                break;
            case EAWSMetricsStatus::Disabled:
                awsMetrics.SetStatus(Aws::S3::Model::MetricsStatus::Disabled);
                break;
            default:
                break;
        }

        if (!(this->eventThreshold.IsEmpty())) {
            awsMetrics.SetEventThreshold(this->eventThreshold.toAWS());
        }

        return awsMetrics;
    }

    bool IsEmpty() const {
        return status == EAWSMetricsStatus::NOT_SET && this->eventThreshold.IsEmpty();
    }

    FMetrics &fromAWS(const Aws::S3::Model::Metrics &awsMetrics) {
        switch(awsMetrics.GetStatus()) {
            case Aws::S3::Model::MetricsStatus::NOT_SET:
                this->status = EAWSMetricsStatus::NOT_SET;
                break;
            case Aws::S3::Model::MetricsStatus::Enabled:
                this->status = EAWSMetricsStatus::Enabled;
                break;
            case Aws::S3::Model::MetricsStatus::Disabled:
                this->status = EAWSMetricsStatus::Disabled;
                break;
            default:
                this->status = EAWSMetricsStatus::NOT_SET;
                break;
        }

        this->eventThreshold.fromAWS(awsMetrics.GetEventThreshold());

        return *this;
    }
#endif
};
