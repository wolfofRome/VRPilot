/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AnalyticsAndOperator.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTAnalyticsAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAnalyticsAndOperator {
GENERATED_BODY()

    /**
    *  <p>The prefix to use when evaluating an AND predicate: The prefix that an object must have to be included in the metrics results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>The list of tags to use when evaluating an AND predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tags;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AnalyticsAndOperator toAWS() const {
        Aws::S3Crt::Model::AnalyticsAndOperator awsAnalyticsAndOperator;

        if (!(this->prefix.IsEmpty())) {
            awsAnalyticsAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FAWSS3CRTTag& elem : this->tags) {
            awsAnalyticsAndOperator.AddTags(elem.toAWS());
        }

        return awsAnalyticsAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FAWSS3CRTAnalyticsAndOperator &fromAWS(const Aws::S3Crt::Model::AnalyticsAndOperator &awsAnalyticsAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsAnalyticsAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsAnalyticsAndOperator.GetTags()) {
            this->tags.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
