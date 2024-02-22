/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListBucketsResult.h"

#endif

#include "Model/Bucket.h"
#include "Model/Owner.h"

#include "ListBucketsResult.generated.h"

USTRUCT(BlueprintType)
struct FListBucketsResult {
GENERATED_BODY()

    /**
    *  <p>The list of buckets owned by the requestor.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FBucket> buckets;

    /**
    *  <p>The owner of the buckets listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListBucketsResult &fromAWS(const Aws::S3::Model::ListBucketsResult &awsListBucketsResult) {
        this->buckets.Empty();
        for (const Aws::S3::Model::Bucket& elem : awsListBucketsResult.GetBuckets()) {
            this->buckets.Add(FBucket().fromAWS(elem));
        }

        this->owner.fromAWS(awsListBucketsResult.GetOwner());

        return *this;
    }
#endif
};
