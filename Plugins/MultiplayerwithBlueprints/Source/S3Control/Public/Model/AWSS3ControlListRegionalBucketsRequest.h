/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListRegionalBucketsRequest.h"

#endif

#include "AWSS3ControlListRegionalBucketsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListRegionalBucketsRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int maxResults = 0;

    /**
    *  <p>The ID of the AWS Outposts.</p>  <p>This is required by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString outpostId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ListRegionalBucketsRequest toAWS() const {
        Aws::S3Control::Model::ListRegionalBucketsRequest awsListRegionalBucketsRequest;

        if (!(this->accountId.IsEmpty())) {
            awsListRegionalBucketsRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListRegionalBucketsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListRegionalBucketsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->outpostId.IsEmpty())) {
            awsListRegionalBucketsRequest.SetOutpostId(TCHAR_TO_UTF8(*this->outpostId));
        }

        return awsListRegionalBucketsRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->nextToken.IsEmpty() && this->maxResults == 0 && this->outpostId.IsEmpty();
    }
#endif
};
