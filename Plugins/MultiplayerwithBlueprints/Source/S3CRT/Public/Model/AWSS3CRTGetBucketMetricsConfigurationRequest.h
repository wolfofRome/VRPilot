/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketMetricsConfigurationRequest.h"

#endif

#include "AWSS3CRTGetBucketMetricsConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketMetricsConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket containing the metrics configuration to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The ID used to identify the metrics configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::GetBucketMetricsConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::GetBucketMetricsConfigurationRequest awsGetBucketMetricsConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketMetricsConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->id.IsEmpty())) {
            awsGetBucketMetricsConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetBucketMetricsConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketMetricsConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketMetricsConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
