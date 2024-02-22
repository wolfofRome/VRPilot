/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/MetricsConfiguration.h"

#endif

#include "Model/AWSS3CRTMetricsFilter.h"

#include "AWSS3CRTMetricsConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTMetricsConfiguration {
GENERATED_BODY()

    /**
    *  <p>The ID used to identify the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>Specifies a metrics configuration filter. The metrics configuration will only include objects that meet the filter's criteria. A filter must be a prefix, a tag, or a conjunction (MetricsAndOperator).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTMetricsFilter filter;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::MetricsConfiguration toAWS() const {
        Aws::S3Crt::Model::MetricsConfiguration awsMetricsConfiguration;

        if (!(this->id.IsEmpty())) {
            awsMetricsConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->filter.IsEmpty())) {
            awsMetricsConfiguration.SetFilter(this->filter.toAWS());
        }

        return awsMetricsConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->filter.IsEmpty();
    }

    FAWSS3CRTMetricsConfiguration &fromAWS(const Aws::S3Crt::Model::MetricsConfiguration &awsMetricsConfiguration) {
        this->id = UTF8_TO_TCHAR(awsMetricsConfiguration.GetId().c_str());

        this->filter = FAWSS3CRTMetricsFilter().fromAWS(awsMetricsConfiguration.GetFilter());

        return *this;
    }
#endif
};
