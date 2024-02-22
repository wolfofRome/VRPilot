/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetMultiRegionAccessPointRoutesResult.h"

#endif

#include "Model/AWSS3ControlMultiRegionAccessPointRoute.h"

#include "AWSS3ControlGetMultiRegionAccessPointRoutesResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetMultiRegionAccessPointRoutesResult {
GENERATED_BODY()

    /**
    *  <p>The Multi-Region Access Point ARN.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString mrap;

    /**
    *  <p>The different routes that make up the route configuration. Active routes return a value of <code>100</code>, and passive routes return a value of <code>0</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlMultiRegionAccessPointRoute> routes;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetMultiRegionAccessPointRoutesResult &fromAWS(const Aws::S3Control::Model::GetMultiRegionAccessPointRoutesResult &awsGetMultiRegionAccessPointRoutesResult) {
        this->mrap = UTF8_TO_TCHAR(awsGetMultiRegionAccessPointRoutesResult.GetMrap().c_str());

        this->routes.Empty();
        for (const Aws::S3Control::Model::MultiRegionAccessPointRoute& elem : awsGetMultiRegionAccessPointRoutesResult.GetRoutes()) {
            this->routes.Add(FAWSS3ControlMultiRegionAccessPointRoute().fromAWS(elem));
        }

        return *this;
    }
#endif
};
