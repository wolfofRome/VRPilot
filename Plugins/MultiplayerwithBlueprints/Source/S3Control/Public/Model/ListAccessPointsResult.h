/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListAccessPointsResult.h"

#endif

#include "Model/AccessPoint.h"

#include "ListAccessPointsResult.generated.h"

USTRUCT(BlueprintType)
struct FListAccessPointsResult {
GENERATED_BODY()

    /**
    *  <p>Contains identification and configuration information for one or more access points associated with the specified bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAccessPoint> accessPointList;

    /**
    *  <p>If the specified bucket has more access points than can be returned in one call to this API, then this field contains a continuation token that you can provide in subsequent calls to this API to retrieve additional access points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FListAccessPointsResult &fromAWS(const Aws::S3Control::Model::ListAccessPointsResult &awsListAccessPointsResult) {
        this->accessPointList.Empty();
        for (const Aws::S3Control::Model::AccessPoint& elem : awsListAccessPointsResult.GetAccessPointList()) {
            this->accessPointList.Add(FAccessPoint().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListAccessPointsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
