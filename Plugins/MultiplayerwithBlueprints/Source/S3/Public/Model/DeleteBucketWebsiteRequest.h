/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteBucketWebsiteRequest.h"

#endif

#include "DeleteBucketWebsiteRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteBucketWebsiteRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name for which you want to remove the website configuration. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

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
    Aws::S3::Model::DeleteBucketWebsiteRequest toAWS() const {
        Aws::S3::Model::DeleteBucketWebsiteRequest awsDeleteBucketWebsiteRequest;

		if (!(this->bucket.IsEmpty())) {
            awsDeleteBucketWebsiteRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeleteBucketWebsiteRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteBucketWebsiteRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteBucketWebsiteRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
