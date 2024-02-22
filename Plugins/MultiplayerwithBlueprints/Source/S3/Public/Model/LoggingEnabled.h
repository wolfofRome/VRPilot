/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/LoggingEnabled.h"

#endif

#include "Model/TargetGrant.h"

#include "LoggingEnabled.generated.h"

USTRUCT(BlueprintType)
struct FLoggingEnabled {
GENERATED_BODY()

    /**
    *  <p>Specifies the bucket where you want Amazon S3 to store server access logs. You can have your logs delivered to any bucket that you own, including the same bucket that is being logged. You can also configure multiple buckets to deliver their logs to the same target bucket. In this case, you should choose a different <code>TargetPrefix</code> for each source bucket so that the delivered log files can be distinguished by key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString targetBucket;

    /**
    *  <p>Container for granting information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FTargetGrant> targetGrants;

    /**
    *  <p>A prefix for all log object keys. If you store log files from multiple Amazon S3 buckets in a single bucket, you can use a prefix to distinguish which log files came from which bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString targetPrefix;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::LoggingEnabled toAWS() const {
        Aws::S3::Model::LoggingEnabled awsLoggingEnabled;

		if (!(this->targetBucket.IsEmpty())) {
            awsLoggingEnabled.SetTargetBucket(TCHAR_TO_UTF8(*this->targetBucket));
        }

        for (const FTargetGrant& elem : this->targetGrants) {
            awsLoggingEnabled.AddTargetGrants(elem.toAWS());
        }

		if (!(this->targetPrefix.IsEmpty())) {
            awsLoggingEnabled.SetTargetPrefix(TCHAR_TO_UTF8(*this->targetPrefix));
        }

        return awsLoggingEnabled;
    }

    bool IsEmpty() const {
        return this->targetBucket.IsEmpty() && this->targetGrants.Num() == 0 && this->targetPrefix.IsEmpty();
    }

    FLoggingEnabled &fromAWS(const Aws::S3::Model::LoggingEnabled &awsLoggingEnabled) {
        this->targetBucket = UTF8_TO_TCHAR(awsLoggingEnabled.GetTargetBucket().c_str());

        this->targetGrants.Empty();
        for (const Aws::S3::Model::TargetGrant& elem : awsLoggingEnabled.GetTargetGrants()) {
            this->targetGrants.Add(FTargetGrant().fromAWS(elem));
        }

        this->targetPrefix = UTF8_TO_TCHAR(awsLoggingEnabled.GetTargetPrefix().c_str());

        return *this;
    }
#endif
};
