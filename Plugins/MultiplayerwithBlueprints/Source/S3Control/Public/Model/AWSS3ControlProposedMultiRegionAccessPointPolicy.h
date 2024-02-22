/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ProposedMultiRegionAccessPointPolicy.h"

#endif

#include "AWSS3ControlProposedMultiRegionAccessPointPolicy.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlProposedMultiRegionAccessPointPolicy {
GENERATED_BODY()

    /**
    *  <p>The details of the proposed policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlProposedMultiRegionAccessPointPolicy &fromAWS(const Aws::S3Control::Model::ProposedMultiRegionAccessPointPolicy &awsProposedMultiRegionAccessPointPolicy) {
        this->policy = UTF8_TO_TCHAR(awsProposedMultiRegionAccessPointPolicy.GetPolicy().c_str());

        return *this;
    }
#endif
};
