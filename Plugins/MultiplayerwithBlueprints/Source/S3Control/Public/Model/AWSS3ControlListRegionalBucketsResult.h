/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListRegionalBucketsResult.h"

#endif

#include "Model/AWSS3ControlRegionalBucket.h"

#include "AWSS3ControlListRegionalBucketsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListRegionalBucketsResult {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlRegionalBucket> regionalBucketList;

    /**
    *  <p> <code>NextToken</code> is sent when <code>isTruncated</code> is true, which means there are more buckets that can be listed. The next list requests to Amazon S3 can be continued with this <code>NextToken</code>. <code>NextToken</code> is obfuscated and is not a real key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlListRegionalBucketsResult &fromAWS(const Aws::S3Control::Model::ListRegionalBucketsResult &awsListRegionalBucketsResult) {
        this->regionalBucketList.Empty();
        for (const Aws::S3Control::Model::RegionalBucket& elem : awsListRegionalBucketsResult.GetRegionalBucketList()) {
            this->regionalBucketList.Add(FAWSS3ControlRegionalBucket().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListRegionalBucketsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
