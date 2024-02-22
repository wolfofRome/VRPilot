/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketsResult.h"

#endif

#include "Model/AWSS3CRTBucket.h"
#include "Model/AWSS3CRTOwner.h"

#include "AWSS3CRTListBucketsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketsResult {
GENERATED_BODY()

    /**
    *  <p>The list of buckets owned by the requestor.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTBucket> buckets;

    /**
    *  <p>The owner of the buckets listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListBucketsResult &fromAWS(const Aws::S3Crt::Model::ListBucketsResult &awsListBucketsResult) {
        this->buckets.Empty();
        for (const Aws::S3Crt::Model::Bucket& elem : awsListBucketsResult.GetBuckets()) {
            this->buckets.Add(FAWSS3CRTBucket().fromAWS(elem));
        }

        this->owner = FAWSS3CRTOwner().fromAWS(awsListBucketsResult.GetOwner());

        return *this;
    }
#endif
};
