/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListBucketInventoryConfigurationsRequest.h"

#endif

#include "ListBucketInventoryConfigurationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListBucketInventoryConfigurationsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket containing the inventory configurations to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The marker used to continue an inventory configuration listing that has been truncated. Use the NextContinuationToken from a previously truncated list response to continue the listing. The continuation token is an opaque value that Amazon S3 understands.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

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
    Aws::S3::Model::ListBucketInventoryConfigurationsRequest toAWS() const {
        Aws::S3::Model::ListBucketInventoryConfigurationsRequest awsListBucketInventoryConfigurationsRequest;

		if (!(this->bucket.IsEmpty())) {
            awsListBucketInventoryConfigurationsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->continuationToken.IsEmpty())) {
            awsListBucketInventoryConfigurationsRequest.SetContinuationToken(TCHAR_TO_UTF8(*this->continuationToken));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListBucketInventoryConfigurationsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListBucketInventoryConfigurationsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListBucketInventoryConfigurationsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->continuationToken.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
