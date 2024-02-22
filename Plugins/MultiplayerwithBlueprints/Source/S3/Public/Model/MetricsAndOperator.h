/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/MetricsAndOperator.h"

#endif

#include "Model/S3Tag.h"

#include "MetricsAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FMetricsAndOperator {
GENERATED_BODY()

    /**
    *  <p>The prefix used when evaluating an AND predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>The list of tags used when evaluating an AND predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Tag> tags;

    /**
    *  <p>The access point ARN used when evaluating an <code>AND</code> predicate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString accessPointArn;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::MetricsAndOperator toAWS() const {
        Aws::S3::Model::MetricsAndOperator awsMetricsAndOperator;

		if (!(this->prefix.IsEmpty())) {
            awsMetricsAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FS3Tag& elem : this->tags) {
            awsMetricsAndOperator.AddTags(elem.toAWS());
        }

		if (!(this->accessPointArn.IsEmpty())) {
            awsMetricsAndOperator.SetAccessPointArn(TCHAR_TO_UTF8(*this->accessPointArn));
        }

        return awsMetricsAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0 && this->accessPointArn.IsEmpty();
    }

    FMetricsAndOperator &fromAWS(const Aws::S3::Model::MetricsAndOperator &awsMetricsAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsMetricsAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3::Model::Tag& elem : awsMetricsAndOperator.GetTags()) {
            this->tags.Add(FS3Tag().fromAWS(elem));
        }

        this->accessPointArn = UTF8_TO_TCHAR(awsMetricsAndOperator.GetAccessPointArn().c_str());

        return *this;
    }
#endif
};
