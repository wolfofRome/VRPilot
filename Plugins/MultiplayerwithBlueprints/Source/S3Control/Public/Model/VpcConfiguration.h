/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/VpcConfiguration.h"

#endif

#include "VpcConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FVpcConfiguration {
GENERATED_BODY()

    /**
    *  <p>If this field is specified, this access point will only allow connections from the specified VPC ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString vpcId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::VpcConfiguration toAWS() const {
        Aws::S3Control::Model::VpcConfiguration awsVpcConfiguration;

		if (!(this->vpcId.IsEmpty())) {
            awsVpcConfiguration.SetVpcId(TCHAR_TO_UTF8(*this->vpcId));
        }

        return awsVpcConfiguration;
    }

    bool IsEmpty() const {
        return this->vpcId.IsEmpty();
    }

    FVpcConfiguration &fromAWS(const Aws::S3Control::Model::VpcConfiguration &awsVpcConfiguration) {
        this->vpcId = UTF8_TO_TCHAR(awsVpcConfiguration.GetVpcId().c_str());

        return *this;
    }
#endif
};
