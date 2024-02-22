/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutMultiRegionAccessPointPolicyInput.h"

#endif

#include "AWSS3ControlPutMultiRegionAccessPointPolicyInput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutMultiRegionAccessPointPolicyInput {
GENERATED_BODY()

    /**
    *  <p>The name of the Multi-Region Access Point associated with the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>The policy details for the <code>PutMultiRegionAccessPoint</code> request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutMultiRegionAccessPointPolicyInput toAWS() const {
        Aws::S3Control::Model::PutMultiRegionAccessPointPolicyInput awsPutMultiRegionAccessPointPolicyInput;

		if (!(this->name.IsEmpty())) {
            awsPutMultiRegionAccessPointPolicyInput.SetName(TCHAR_TO_UTF8(*this->name));
        }

		if (!(this->policy.IsEmpty())) {
            awsPutMultiRegionAccessPointPolicyInput.SetPolicy(TCHAR_TO_UTF8(*this->policy));
        }

        return awsPutMultiRegionAccessPointPolicyInput;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->policy.IsEmpty();
    }

    FAWSS3ControlPutMultiRegionAccessPointPolicyInput &fromAWS(const Aws::S3Control::Model::PutMultiRegionAccessPointPolicyInput &awsPutMultiRegionAccessPointPolicyInput) {
        this->name = UTF8_TO_TCHAR(awsPutMultiRegionAccessPointPolicyInput.GetName().c_str());

        this->policy = UTF8_TO_TCHAR(awsPutMultiRegionAccessPointPolicyInput.GetPolicy().c_str());

        return *this;
    }
#endif
};
