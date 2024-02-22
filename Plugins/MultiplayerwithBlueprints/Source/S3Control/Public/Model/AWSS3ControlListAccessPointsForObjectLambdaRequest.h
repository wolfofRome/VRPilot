/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListAccessPointsForObjectLambdaRequest.h"

#endif

#include "AWSS3ControlListAccessPointsForObjectLambdaRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListAccessPointsForObjectLambdaRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the account that owns the specified Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>If the list has more access points than can be returned in one call to this API, this field contains a continuation token that you can provide in subsequent calls to this API to retrieve additional access points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p>The maximum number of access points that you want to include in the list. If there are more than this number of access points, then the response will include a continuation token in the <code>NextToken</code> field that you can use to retrieve the next page of access points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int maxResults = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ListAccessPointsForObjectLambdaRequest toAWS() const {
        Aws::S3Control::Model::ListAccessPointsForObjectLambdaRequest awsListAccessPointsForObjectLambdaRequest;

        if (!(this->accountId.IsEmpty())) {
            awsListAccessPointsForObjectLambdaRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListAccessPointsForObjectLambdaRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListAccessPointsForObjectLambdaRequest.SetMaxResults(this->maxResults);
        }

        return awsListAccessPointsForObjectLambdaRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
