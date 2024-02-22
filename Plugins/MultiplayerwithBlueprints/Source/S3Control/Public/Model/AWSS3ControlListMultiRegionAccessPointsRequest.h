/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListMultiRegionAccessPointsRequest.h"

#endif

#include "AWSS3ControlListMultiRegionAccessPointsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListMultiRegionAccessPointsRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the owner of the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>Not currently used. Do not use this parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p>Not currently used. Do not use this parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int maxResults = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ListMultiRegionAccessPointsRequest toAWS() const {
        Aws::S3Control::Model::ListMultiRegionAccessPointsRequest awsListMultiRegionAccessPointsRequest;

        if (!(this->accountId.IsEmpty())) {
            awsListMultiRegionAccessPointsRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListMultiRegionAccessPointsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListMultiRegionAccessPointsRequest.SetMaxResults(this->maxResults);
        }

        return awsListMultiRegionAccessPointsRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
