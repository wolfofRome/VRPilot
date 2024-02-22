/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/RegionReport.h"

#endif

#include "AWSS3ControlRegionReport.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlRegionReport {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The name of the Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString region;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlRegionReport &fromAWS(const Aws::S3Control::Model::RegionReport &awsRegionReport) {
        this->bucket = UTF8_TO_TCHAR(awsRegionReport.GetBucket().c_str());

        this->region = UTF8_TO_TCHAR(awsRegionReport.GetRegion().c_str());

        return *this;
    }
#endif
};
