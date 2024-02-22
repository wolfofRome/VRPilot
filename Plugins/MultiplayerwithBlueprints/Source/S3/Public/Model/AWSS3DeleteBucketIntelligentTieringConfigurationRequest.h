/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteBucketIntelligentTieringConfigurationRequest.h"

#endif

#include "AWSS3DeleteBucketIntelligentTieringConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3DeleteBucketIntelligentTieringConfigurationRequest {
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
    Aws::S3::Model::DeleteBucketIntelligentTieringConfigurationRequest toAWS() const {
        Aws::S3::Model::DeleteBucketIntelligentTieringConfigurationRequest awsDeleteBucketIntelligentTieringConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsDeleteBucketIntelligentTieringConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->id.IsEmpty())) {
            awsDeleteBucketIntelligentTieringConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteBucketIntelligentTieringConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteBucketIntelligentTieringConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
