/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListAccessPointsRequest.h"

#endif

#include "ListAccessPointsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListAccessPointsRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID for owner of the bucket whose access points you want to list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the bucket whose associated access points you want to list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>A continuation token. If a previous call to <code>ListAccessPoints</code> returned a continuation token in the <code>NextToken</code> field, then providing that value here causes Amazon S3 to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p>The maximum number of access points that you want to include in the list. If the specified bucket has more than this number of access points, then the response will include a continuation token in the <code>NextToken</code> field that you can use to retrieve the next page of access points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int maxResults = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ListAccessPointsRequest toAWS() const {
        Aws::S3Control::Model::ListAccessPointsRequest awsListAccessPointsRequest;

		if (!(this->accountId.IsEmpty())) {
            awsListAccessPointsRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->bucket.IsEmpty())) {
            awsListAccessPointsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->nextToken.IsEmpty())) {
            awsListAccessPointsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListAccessPointsRequest.SetMaxResults(this->maxResults);
        }

        return awsListAccessPointsRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->bucket.IsEmpty() && this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
