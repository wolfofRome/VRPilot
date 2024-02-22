/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/ListSharedEndpointsResult.h"

#endif

#include "Model/AWSS3OutpostsEndpoint.h"

#include "AWSS3OutpostsListSharedEndpointsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsListSharedEndpointsResult {
GENERATED_BODY()

    /**
    *  <p>The list of endpoints associated with the specified Outpost that have been shared by Amazon Web Services Resource Access Manager (RAM).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    TArray<FAWSS3OutpostsEndpoint> endpoints;

    /**
    *  <p>If the number of endpoints associated with the specified Outpost exceeds <code>MaxResults</code>, you can include this value in subsequent calls to this operation to retrieve more results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString nextToken;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    FAWSS3OutpostsListSharedEndpointsResult &fromAWS(const Aws::S3Outposts::Model::ListSharedEndpointsResult &awsListSharedEndpointsResult) {
        this->endpoints.Empty();
        for (const Aws::S3Outposts::Model::Endpoint& elem : awsListSharedEndpointsResult.GetEndpoints()) {
            this->endpoints.Add(FAWSS3OutpostsEndpoint().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListSharedEndpointsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
