/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/ListEndpointsResult.h"

#endif

#include "Model/AWSS3OutpostsEndpoint.h"

#include "AWSS3OutpostsListEndpointsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsListEndpointsResult {
GENERATED_BODY()

    /**
    *  <p>Returns an array of endpoints associated with AWS Outpost.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    TArray<FAWSS3OutpostsEndpoint> endpoints;

    /**
    *  <p>The next endpoint returned in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString nextToken;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    FAWSS3OutpostsListEndpointsResult &fromAWS(const Aws::S3Outposts::Model::ListEndpointsResult &awsListEndpointsResult) {
        this->endpoints.Empty();
        for (const Aws::S3Outposts::Model::Endpoint& elem : awsListEndpointsResult.GetEndpoints()) {
            this->endpoints.Add(FAWSS3OutpostsEndpoint().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListEndpointsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
