/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketLocationRequest.h"

#endif

#include "GetBucketLocationRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketLocationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket for which to get the location.</p>
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
    Aws::S3::Model::GetBucketLocationRequest toAWS() const {
        Aws::S3::Model::GetBucketLocationRequest awsGetBucketLocationRequest;

		if (!(this->bucket.IsEmpty())) {
            awsGetBucketLocationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetBucketLocationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetBucketLocationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetBucketLocationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
