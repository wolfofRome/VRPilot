/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/ListSharedEndpointsRequest.h"

#endif

#include "AWSS3OutpostsListSharedEndpointsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsListSharedEndpointsRequest {
GENERATED_BODY()

    /**
    *  <p>If a previous response from this operation included a <code>NextToken</code> value, you can provide that value here to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString nextToken;

    /**
    *  <p>The maximum number of endpoints that will be returned in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    int maxResults = 0;

    /**
    *  <p>The ID of the Amazon Web Services Outpost.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString outpostId;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    Aws::S3Outposts::Model::ListSharedEndpointsRequest toAWS() const {
        Aws::S3Outposts::Model::ListSharedEndpointsRequest awsListSharedEndpointsRequest;

        if (!(this->nextToken.IsEmpty())) {
            awsListSharedEndpointsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListSharedEndpointsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->outpostId.IsEmpty())) {
            awsListSharedEndpointsRequest.SetOutpostId(TCHAR_TO_UTF8(*this->outpostId));
        }

        return awsListSharedEndpointsRequest;
    }

    bool IsEmpty() const {
        return this->nextToken.IsEmpty() && this->maxResults == 0 && this->outpostId.IsEmpty();
    }
#endif
};
