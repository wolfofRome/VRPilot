/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/LoggingEnabled.h"

#endif

#include "Model/AWSS3CRTTargetGrant.h"

#include "AWSS3CRTLoggingEnabled.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTLoggingEnabled {
GENERATED_BODY()

    /**
    *  <p>Specifies the bucket where you want Amazon S3 to store server access logs. You can have your logs delivered to any bucket that you own, including the same bucket that is being logged. You can also configure multiple buckets to deliver their logs to the same target bucket. In this case, you should choose a different <code>TargetPrefix</code> for each source bucket so that the delivered log files can be distinguished by key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString targetBucket;

    /**
    *  <p>Container for granting information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTargetGrant> targetGrants;

    /**
    *  <p>A prefix for all log object keys. If you store log files from multiple Amazon S3 buckets in a single bucket, you can use a prefix to distinguish which log files came from which bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString targetPrefix;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::LoggingEnabled toAWS() const {
        Aws::S3Crt::Model::LoggingEnabled awsLoggingEnabled;

        if (!(this->targetBucket.IsEmpty())) {
            awsLoggingEnabled.SetTargetBucket(TCHAR_TO_UTF8(*this->targetBucket));
        }

        for (const FAWSS3CRTTargetGrant& elem : this->targetGrants) {
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

    FAWSS3CRTLoggingEnabled &fromAWS(const Aws::S3Crt::Model::LoggingEnabled &awsLoggingEnabled) {
        this->targetBucket = UTF8_TO_TCHAR(awsLoggingEnabled.GetTargetBucket().c_str());

        this->targetGrants.Empty();
        for (const Aws::S3Crt::Model::TargetGrant& elem : awsLoggingEnabled.GetTargetGrants()) {
            this->targetGrants.Add(FAWSS3CRTTargetGrant().fromAWS(elem));
        }

        this->targetPrefix = UTF8_TO_TCHAR(awsLoggingEnabled.GetTargetPrefix().c_str());

        return *this;
    }
#endif
};
