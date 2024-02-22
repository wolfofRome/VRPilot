/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/MetricsFilter.h"

#endif

#include "Model/AWSS3CRTTag.h"
#include "Model/AWSS3CRTMetricsAndOperator.h"

#include "AWSS3CRTMetricsFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTMetricsFilter {
GENERATED_BODY()

    /**
    *  <p>The prefix used when evaluating a metrics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>The tag used when evaluating a metrics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTag tag;

    /**
    *  <p>A conjunction (logical AND) of predicates, which is used in evaluating a metrics filter. The operator must have at least two predicates, and an object must match all of the predicates in order for the filter to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTMetricsAndOperator andOperator;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::MetricsFilter toAWS() const {
        Aws::S3Crt::Model::MetricsFilter awsMetricsFilter;

        if (!(this->prefix.IsEmpty())) {
            awsMetricsFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsMetricsFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsMetricsFilter.SetAnd(this->andOperator.toAWS());
        }

        return awsMetricsFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->andOperator.IsEmpty();
    }

    FAWSS3CRTMetricsFilter &fromAWS(const Aws::S3Crt::Model::MetricsFilter &awsMetricsFilter) {
        this->prefix = UTF8_TO_TCHAR(awsMetricsFilter.GetPrefix().c_str());

        this->tag = FAWSS3CRTTag().fromAWS(awsMetricsFilter.GetTag());

        this->andOperator = FAWSS3CRTMetricsAndOperator().fromAWS(awsMetricsFilter.GetAnd());

        return *this;
    }
#endif
};
