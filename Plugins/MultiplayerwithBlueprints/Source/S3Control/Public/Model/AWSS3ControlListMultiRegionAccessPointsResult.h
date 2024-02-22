/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListMultiRegionAccessPointsResult.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointReport.h"

#include "AWSS3ControlListMultiRegionAccessPointsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListMultiRegionAccessPointsResult {
GENERATED_BODY()

    /**
    *  <p>The list of Multi-Region Access Points associated with the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlMultiRegionAccessPointReport> accessPoints;

    /**
    *  <p>If the specified bucket has more Multi-Region Access Points than can be returned in one call to this action, this field contains a continuation token. You can use this token tin subsequent calls to this action to retrieve additional Multi-Region Access Points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlListMultiRegionAccessPointsResult &fromAWS(const Aws::S3Control::Model::ListMultiRegionAccessPointsResult &awsListMultiRegionAccessPointsResult) {
        this->accessPoints.Empty();
        for (const Aws::S3Control::Model::MultiRegionAccessPointReport& elem : awsListMultiRegionAccessPointsResult.GetAccessPoints()) {
            this->accessPoints.Add(FAWSS3ControlMultiRegionAccessPointReport().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListMultiRegionAccessPointsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
