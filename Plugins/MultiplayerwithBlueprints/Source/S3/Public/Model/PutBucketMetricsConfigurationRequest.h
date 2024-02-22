/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketMetricsConfigurationRequest.h"

#endif

#include "Model/MetricsConfiguration.h"

#include "PutBucketMetricsConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutBucketMetricsConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which the metrics configuration is set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The ID used to identify the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>Specifies the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FMetricsConfiguration metricsConfiguration;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::PutBucketMetricsConfigurationRequest toAWS() const {
        Aws::S3::Model::PutBucketMetricsConfigurationRequest awsPutBucketMetricsConfigurationRequest;

		if (!(this->bucket.IsEmpty())) {
            awsPutBucketMetricsConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->id.IsEmpty())) {
            awsPutBucketMetricsConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->metricsConfiguration.IsEmpty())) {
            awsPutBucketMetricsConfigurationRequest.SetMetricsConfiguration(this->metricsConfiguration.toAWS());
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketMetricsConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketMetricsConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketMetricsConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->metricsConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
