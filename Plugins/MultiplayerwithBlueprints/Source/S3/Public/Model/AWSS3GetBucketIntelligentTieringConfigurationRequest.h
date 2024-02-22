/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketIntelligentTieringConfigurationRequest.h"

#endif

#include "AWSS3GetBucketIntelligentTieringConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3GetBucketIntelligentTieringConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Amazon S3 bucket whose configuration you want to modify or retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The ID used to identify the S3 Intelligent-Tiering configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::GetBucketIntelligentTieringConfigurationRequest toAWS() const {
        Aws::S3::Model::GetBucketIntelligentTieringConfigurationRequest awsGetBucketIntelligentTieringConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketIntelligentTieringConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->id.IsEmpty())) {
            awsGetBucketIntelligentTieringConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketIntelligentTieringConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketIntelligentTieringConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
