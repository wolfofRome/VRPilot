/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/MetricsFilter.h"

#endif

#include "Model/S3Tag.h"
#include "Model/MetricsAndOperator.h"

#include "MetricsFilter.generated.h"

USTRUCT(BlueprintType)
struct FMetricsFilter {
GENERATED_BODY()

    /**
    *  <p>The prefix used when evaluating a metrics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>The tag used when evaluating a metrics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Tag tag;

    /**
    *  <p>The access point ARN used when evaluating a metrics filter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString accessPointArn;

    /**
    *  <p>A conjunction (logical AND) of predicates, which is used in evaluating a metrics filter. The operator must have at least two predicates, and an object must match all of the predicates in order for the filter to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FMetricsAndOperator andOperator;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::MetricsFilter toAWS() const {
        Aws::S3::Model::MetricsFilter awsMetricsFilter;

		if (!(this->prefix.IsEmpty())) {
            awsMetricsFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsMetricsFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsMetricsFilter.SetAnd(this->andOperator.toAWS());
        }

        if (!(this->accessPointArn.IsEmpty())) {
            awsMetricsFilter.SetAccessPointArn(TCHAR_TO_UTF8(*this->accessPointArn));
        }

        return awsMetricsFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->accessPointArn.IsEmpty() && this->andOperator.IsEmpty();
    }

    FMetricsFilter &fromAWS(const Aws::S3::Model::MetricsFilter &awsMetricsFilter) {
        this->prefix = UTF8_TO_TCHAR(awsMetricsFilter.GetPrefix().c_str());

        this->tag.fromAWS(awsMetricsFilter.GetTag());

        this->accessPointArn = UTF8_TO_TCHAR(awsMetricsFilter.GetAccessPointArn().c_str());

        this->andOperator.fromAWS(awsMetricsFilter.GetAnd());

        return *this;
    }
#endif
};
