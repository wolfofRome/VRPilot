/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/MetricsAndOperator.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTMetricsAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTMetricsAndOperator {
GENERATED_BODY()

    /**
    *  <p>The prefix used when evaluating an AND predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>The list of tags used when evaluating an AND predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tags;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::MetricsAndOperator toAWS() const {
        Aws::S3Crt::Model::MetricsAndOperator awsMetricsAndOperator;

        if (!(this->prefix.IsEmpty())) {
            awsMetricsAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FAWSS3CRTTag& elem : this->tags) {
            awsMetricsAndOperator.AddTags(elem.toAWS());
        }

        return awsMetricsAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FAWSS3CRTMetricsAndOperator &fromAWS(const Aws::S3Crt::Model::MetricsAndOperator &awsMetricsAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsMetricsAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsMetricsAndOperator.GetTags()) {
            this->tags.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
