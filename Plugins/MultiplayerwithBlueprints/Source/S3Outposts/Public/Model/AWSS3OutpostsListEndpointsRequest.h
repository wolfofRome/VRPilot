/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/ListEndpointsRequest.h"

#endif

#include "AWSS3OutpostsListEndpointsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsListEndpointsRequest {
GENERATED_BODY()

    /**
    *  <p>The next endpoint requested in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString nextToken;

    /**
    *  <p>The max number of endpoints that can be returned on the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    int maxResults = 0;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    Aws::S3Outposts::Model::ListEndpointsRequest toAWS() const {
        Aws::S3Outposts::Model::ListEndpointsRequest awsListEndpointsRequest;

        if (!(this->nextToken.IsEmpty())) {
            awsListEndpointsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListEndpointsRequest.SetMaxResults(this->maxResults);
        }

        return awsListEndpointsRequest;
    }

    bool IsEmpty() const {
        return this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
