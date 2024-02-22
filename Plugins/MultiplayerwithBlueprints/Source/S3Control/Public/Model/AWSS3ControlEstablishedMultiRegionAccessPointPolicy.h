/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/EstablishedMultiRegionAccessPointPolicy.h"

#endif

#include "AWSS3ControlEstablishedMultiRegionAccessPointPolicy.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlEstablishedMultiRegionAccessPointPolicy {
GENERATED_BODY()

    /**
    *  <p>The details of the last established policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlEstablishedMultiRegionAccessPointPolicy &fromAWS(const Aws::S3Control::Model::EstablishedMultiRegionAccessPointPolicy &awsEstablishedMultiRegionAccessPointPolicy) {
        this->policy = UTF8_TO_TCHAR(awsEstablishedMultiRegionAccessPointPolicy.GetPolicy().c_str());

        return *this;
    }
#endif
};
