/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AnalyticsFilter.h"

#endif

#include "Model/AWSS3CRTTag.h"
#include "Model/AWSS3CRTAnalyticsAndOperator.h"

#include "AWSS3CRTAnalyticsFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAnalyticsFilter {
GENERATED_BODY()

    /**
    *  <p>The prefix to use when evaluating an analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>The tag to use when evaluating an analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTag tag;

    /**
    *  <p>A conjunction (logical AND) of predicates, which is used in evaluating an analytics filter. The operator must have at least two predicates.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAnalyticsAndOperator andOperator;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AnalyticsFilter toAWS() const {
        Aws::S3Crt::Model::AnalyticsFilter awsAnalyticsFilter;

        if (!(this->prefix.IsEmpty())) {
            awsAnalyticsFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsAnalyticsFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsAnalyticsFilter.SetAnd(this->andOperator.toAWS());
        }

        return awsAnalyticsFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->andOperator.IsEmpty();
    }

    FAWSS3CRTAnalyticsFilter &fromAWS(const Aws::S3Crt::Model::AnalyticsFilter &awsAnalyticsFilter) {
        this->prefix = UTF8_TO_TCHAR(awsAnalyticsFilter.GetPrefix().c_str());

        this->tag = FAWSS3CRTTag().fromAWS(awsAnalyticsFilter.GetTag());

        this->andOperator = FAWSS3CRTAnalyticsAndOperator().fromAWS(awsAnalyticsFilter.GetAnd());

        return *this;
    }
#endif
};
