/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutBucketLifecycleConfigurationRequest.h"

#endif

#include "Model/AWSS3ControlLifecycleConfiguration.h"

#include "AWSS3ControlPutBucketLifecycleConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutBucketLifecycleConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the bucket for which to set the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>Container for lifecycle rules. You can add as many as 1,000 rules.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlLifecycleConfiguration lifecycleConfiguration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutBucketLifecycleConfigurationRequest toAWS() const {
        Aws::S3Control::Model::PutBucketLifecycleConfigurationRequest awsPutBucketLifecycleConfigurationRequest;

		if (!(this->accountId.IsEmpty())) {
            awsPutBucketLifecycleConfigurationRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->bucket.IsEmpty())) {
            awsPutBucketLifecycleConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->lifecycleConfiguration.IsEmpty())) {
            awsPutBucketLifecycleConfigurationRequest.SetLifecycleConfiguration(this->lifecycleConfiguration.toAWS());
        }

        return awsPutBucketLifecycleConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->bucket.IsEmpty() && this->lifecycleConfiguration.IsEmpty();
    }
#endif
};
