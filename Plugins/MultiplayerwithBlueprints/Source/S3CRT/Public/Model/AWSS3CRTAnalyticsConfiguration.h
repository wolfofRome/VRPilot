/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AnalyticsConfiguration.h"

#endif

#include "Model/AWSS3CRTAnalyticsFilter.h"
#include "Model/AWSS3CRTStorageClassAnalysis.h"

#include "AWSS3CRTAnalyticsConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAnalyticsConfiguration {
GENERATED_BODY()

    /**
    *  <p>The ID that identifies the analytics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>The filter used to describe a set of objects for analyses. A filter must have exactly one prefix, one tag, or one conjunction (AnalyticsAndOperator). If no filter is provided, all objects will be considered in any analysis.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAnalyticsFilter filter;

    /**
    *  <p> Contains data related to access patterns to be collected and made available to analyze the tradeoffs between different storage classes. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTStorageClassAnalysis storageClassAnalysis;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AnalyticsConfiguration toAWS() const {
        Aws::S3Crt::Model::AnalyticsConfiguration awsAnalyticsConfiguration;

        if (!(this->id.IsEmpty())) {
            awsAnalyticsConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->filter.IsEmpty())) {
            awsAnalyticsConfiguration.SetFilter(this->filter.toAWS());
        }

        if (!(this->storageClassAnalysis.IsEmpty())) {
            awsAnalyticsConfiguration.SetStorageClassAnalysis(this->storageClassAnalysis.toAWS());
        }

        return awsAnalyticsConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->filter.IsEmpty() && this->storageClassAnalysis.IsEmpty();
    }

    FAWSS3CRTAnalyticsConfiguration &fromAWS(const Aws::S3Crt::Model::AnalyticsConfiguration &awsAnalyticsConfiguration) {
        this->id = UTF8_TO_TCHAR(awsAnalyticsConfiguration.GetId().c_str());

        this->filter = FAWSS3CRTAnalyticsFilter().fromAWS(awsAnalyticsConfiguration.GetFilter());

        this->storageClassAnalysis = FAWSS3CRTStorageClassAnalysis().fromAWS(awsAnalyticsConfiguration.GetStorageClassAnalysis());

        return *this;
    }
#endif
};
