/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AnalyticsConfiguration.h"

#endif

#include "Model/AnalyticsFilter.h"
#include "Model/StorageClassAnalysis.h"

#include "AnalyticsConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsConfiguration {
GENERATED_BODY()

    /**
    *  <p>The ID that identifies the analytics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>The filter used to describe a set of objects for analyses. A filter must have exactly one prefix, one tag, or one conjunction (AnalyticsAndOperator). If no filter is provided, all objects will be considered in any analysis.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAnalyticsFilter filter;

    /**
    *  <p> Contains data related to access patterns to be collected and made available to analyze the tradeoffs between different storage classes. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FStorageClassAnalysis storageClassAnalysis;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AnalyticsConfiguration toAWS() const {
        Aws::S3::Model::AnalyticsConfiguration awsAnalyticsConfiguration;

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

    FAnalyticsConfiguration &fromAWS(const Aws::S3::Model::AnalyticsConfiguration &awsAnalyticsConfiguration) {
        this->id = UTF8_TO_TCHAR(awsAnalyticsConfiguration.GetId().c_str());

        this->filter.fromAWS(awsAnalyticsConfiguration.GetFilter());

        this->storageClassAnalysis.fromAWS(awsAnalyticsConfiguration.GetStorageClassAnalysis());

        return *this;
    }
#endif
};
