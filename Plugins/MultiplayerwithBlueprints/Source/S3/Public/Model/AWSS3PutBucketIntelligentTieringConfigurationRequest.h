/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketIntelligentTieringConfigurationRequest.h"

#endif

#include "Model/AWSS3IntelligentTieringConfiguration.h"

#include "AWSS3PutBucketIntelligentTieringConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3PutBucketIntelligentTieringConfigurationRequest {
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
    *  <p>Container for S3 Intelligent-Tiering configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3IntelligentTieringConfiguration intelligentTieringConfiguration;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::PutBucketIntelligentTieringConfigurationRequest toAWS() const {
        Aws::S3::Model::PutBucketIntelligentTieringConfigurationRequest awsPutBucketIntelligentTieringConfigurationRequest;

		if (!(this->bucket.IsEmpty())) {
            awsPutBucketIntelligentTieringConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->id.IsEmpty())) {
            awsPutBucketIntelligentTieringConfigurationRequest.SetId(TCHAR_TO_UTF8(*this->id));
        }

		if (!(this->intelligentTieringConfiguration.IsEmpty())) {
            awsPutBucketIntelligentTieringConfigurationRequest.SetIntelligentTieringConfiguration(this->intelligentTieringConfiguration.toAWS());
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketIntelligentTieringConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

		return awsPutBucketIntelligentTieringConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->id.IsEmpty() && this->intelligentTieringConfiguration.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
