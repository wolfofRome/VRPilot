/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AnalyticsAndOperator.h"

#endif

#include "Model/S3Tag.h"

#include "AnalyticsAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsAndOperator {
GENERATED_BODY()

    /**
    *  <p>The prefix to use when evaluating an AND predicate: The prefix that an object must have to be included in the metrics results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>The list of tags to use when evaluating an AND predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Tag> tags;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AnalyticsAndOperator toAWS() const {
        Aws::S3::Model::AnalyticsAndOperator awsAnalyticsAndOperator;

		if (!(this->prefix.IsEmpty())) {
            awsAnalyticsAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FS3Tag& elem : this->tags) {
            awsAnalyticsAndOperator.AddTags(elem.toAWS());
        }

        return awsAnalyticsAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FAnalyticsAndOperator &fromAWS(const Aws::S3::Model::AnalyticsAndOperator &awsAnalyticsAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsAnalyticsAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3::Model::Tag& elem : awsAnalyticsAndOperator.GetTags()) {
            this->tags.Add(FS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
