/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/MultiRegionAccessPointPolicyDocument.h"

#endif

#include "Model/AWSS3ControlEstablishedMultiRegionAccessPointPolicy.h"
#include "Model/AWSS3ControlProposedMultiRegionAccessPointPolicy.h"

#include "AWSS3ControlMultiRegionAccessPointPolicyDocument.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlMultiRegionAccessPointPolicyDocument {
GENERATED_BODY()

    /**
    *  <p>The last established policy for the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlEstablishedMultiRegionAccessPointPolicy established;

    /**
    *  <p>The proposed policy for the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlProposedMultiRegionAccessPointPolicy proposed;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlMultiRegionAccessPointPolicyDocument &fromAWS(const Aws::S3Control::Model::MultiRegionAccessPointPolicyDocument &awsMultiRegionAccessPointPolicyDocument) {
        this->established.fromAWS(awsMultiRegionAccessPointPolicyDocument.GetEstablished());

        this->proposed.fromAWS(awsMultiRegionAccessPointPolicyDocument.GetProposed());

        return *this;
    }
#endif
};
