/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/MetricsConfiguration.h"

#endif

#include "Model/MetricsFilter.h"

#include "MetricsConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FMetricsConfiguration {
GENERATED_BODY()

    /**
    *  <p>The ID used to identify the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>Specifies a metrics configuration filter. The metrics configuration will only include objects that meet the filter's criteria. A filter must be a prefix, a tag, or a conjunction (MetricsAndOperator).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FMetricsFilter filter;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::MetricsConfiguration toAWS() const {
        Aws::S3::Model::MetricsConfiguration awsMetricsConfiguration;

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

    FMetricsConfiguration &fromAWS(const Aws::S3::Model::MetricsConfiguration &awsMetricsConfiguration) {
        this->id = UTF8_TO_TCHAR(awsMetricsConfiguration.GetId().c_str());

        this->filter.fromAWS(awsMetricsConfiguration.GetFilter());

        return *this;
    }
#endif
};
