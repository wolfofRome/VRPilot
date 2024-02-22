/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeletePublicAccessBlockRequest.h"

#endif

#include "S3DeletePublicAccessBlockRequest.generated.h"

USTRUCT(BlueprintType)
struct FS3DeletePublicAccessBlockRequest {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (ARN) of the bucket where you want Amazon S3 to store the results.</p>
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
    Aws::S3::Model::DeletePublicAccessBlockRequest toAWS() const {
        Aws::S3::Model::DeletePublicAccessBlockRequest awsDeletePublicAccessBlockRequest;

		if (!(this->bucket.IsEmpty())) {
            awsDeletePublicAccessBlockRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeletePublicAccessBlockRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeletePublicAccessBlockRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeletePublicAccessBlockRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
