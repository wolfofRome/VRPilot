/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Metrics.h"

#endif

#include "Model/AWSS3CRTMetricsStatus.h"
#include "Model/AWSS3CRTReplicationTimeValue.h"

#include "AWSS3CRTMetrics.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTMetrics {
GENERATED_BODY()

    /**
    *  <p> Specifies whether the replication metrics are enabled. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTMetricsStatus status = EAWSS3CRTMetricsStatus::NOT_SET;

    /**
    *  <p> A container specifying the time threshold for emitting the <code>s3:Replication:OperationMissedThreshold</code> event. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTReplicationTimeValue eventThreshold;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Metrics toAWS() const {
        Aws::S3Crt::Model::Metrics awsMetrics;

        switch(this->status) {
            case EAWSS3CRTMetricsStatus::Enabled:
                awsMetrics.SetStatus(Aws::S3Crt::Model::MetricsStatus::Enabled);
                break;
            case EAWSS3CRTMetricsStatus::Disabled:
                awsMetrics.SetStatus(Aws::S3Crt::Model::MetricsStatus::Disabled);
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
        return this->status == EAWSS3CRTMetricsStatus::NOT_SET && this->eventThreshold.IsEmpty();
    }

    FAWSS3CRTMetrics &fromAWS(const Aws::S3Crt::Model::Metrics &awsMetrics) {
        switch(awsMetrics.GetStatus()) {
            case Aws::S3Crt::Model::MetricsStatus::NOT_SET:
                this->status = EAWSS3CRTMetricsStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::MetricsStatus::Enabled:
                this->status = EAWSS3CRTMetricsStatus::Enabled;
                break;
            case Aws::S3Crt::Model::MetricsStatus::Disabled:
                this->status = EAWSS3CRTMetricsStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTMetricsStatus::NOT_SET;
                break;
        }

        this->eventThreshold = FAWSS3CRTReplicationTimeValue().fromAWS(awsMetrics.GetEventThreshold());

        return *this;
    }
#endif
};
