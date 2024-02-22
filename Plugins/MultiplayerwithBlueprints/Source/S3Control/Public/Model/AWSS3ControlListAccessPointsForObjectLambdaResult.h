/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListAccessPointsForObjectLambdaResult.h"

#endif

#include "Model/AWSS3ControlObjectLambdaAccessPoint.h"

#include "AWSS3ControlListAccessPointsForObjectLambdaResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListAccessPointsForObjectLambdaResult {
GENERATED_BODY()

    /**
    *  <p>Returns list of Object Lambda Access Points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlObjectLambdaAccessPoint> objectLambdaAccessPointList;

    /**
    *  <p>If the list has more access points than can be returned in one call to this API, this field contains a continuation token that you can provide in subsequent calls to this API to retrieve additional access points.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlListAccessPointsForObjectLambdaResult &fromAWS(const Aws::S3Control::Model::ListAccessPointsForObjectLambdaResult &awsListAccessPointsForObjectLambdaResult) {
        this->objectLambdaAccessPointList.Empty();
        for (const Aws::S3Control::Model::ObjectLambdaAccessPoint& elem : awsListAccessPointsForObjectLambdaResult.GetObjectLambdaAccessPointList()) {
            this->objectLambdaAccessPointList.Add(FAWSS3ControlObjectLambdaAccessPoint().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListAccessPointsForObjectLambdaResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
