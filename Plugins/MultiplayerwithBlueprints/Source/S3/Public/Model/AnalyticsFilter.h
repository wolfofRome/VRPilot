/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AnalyticsFilter.h"

#endif

#include "Model/S3Tag.h"
#include "Model/AnalyticsAndOperator.h"

#include "AnalyticsFilter.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsFilter {
GENERATED_BODY()

    /**
    *  <p>The prefix to use when evaluating an analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>The tag to use when evaluating an analytics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Tag tag;

    /**
    *  <p>A conjunction (logical AND) of predicates, which is used in evaluating an analytics filter. The operator must have at least two predicates.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAnalyticsAndOperator andOperator;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AnalyticsFilter toAWS() const {
        Aws::S3::Model::AnalyticsFilter awsAnalyticsFilter;

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

    FAnalyticsFilter &fromAWS(const Aws::S3::Model::AnalyticsFilter &awsAnalyticsFilter) {
        this->prefix = UTF8_TO_TCHAR(awsAnalyticsFilter.GetPrefix().c_str());

        this->tag.fromAWS(awsAnalyticsFilter.GetTag());
        
        this->andOperator.fromAWS(awsAnalyticsFilter.GetAnd());

        return *this;
    }
#endif
};
