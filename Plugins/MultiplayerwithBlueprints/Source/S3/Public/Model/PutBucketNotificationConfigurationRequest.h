/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketNotificationConfigurationRequest.h"

#endif

#include "Model/NotificationConfiguration.h"

#include "PutBucketNotificationConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutBucketNotificationConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FNotificationConfiguration notificationConfiguration;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>Skips validation of Amazon SQS, Amazon SNS, and Lambda destinations. True or false value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool skipDestinationValidation = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::PutBucketNotificationConfigurationRequest toAWS() const {
        Aws::S3::Model::PutBucketNotificationConfigurationRequest awsPutBucketNotificationConfigurationRequest;

		if (!(this->bucket.IsEmpty())) {
            awsPutBucketNotificationConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->notificationConfiguration.IsEmpty())) {
            awsPutBucketNotificationConfigurationRequest.SetNotificationConfiguration(this->notificationConfiguration.toAWS());
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketNotificationConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        awsPutBucketNotificationConfigurationRequest.SetSkipDestinationValidation(this->skipDestinationValidation);

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketNotificationConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketNotificationConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->notificationConfiguration.IsEmpty() && this->expectedBucketOwner.IsEmpty() && false && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
