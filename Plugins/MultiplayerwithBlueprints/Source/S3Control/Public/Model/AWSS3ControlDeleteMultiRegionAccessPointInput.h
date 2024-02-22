/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/DeleteMultiRegionAccessPointInput.h"

#endif

#include "AWSS3ControlDeleteMultiRegionAccessPointInput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlDeleteMultiRegionAccessPointInput {
GENERATED_BODY()

    /**
    *  <p>The name of the Multi-Region Access Point associated with this request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::DeleteMultiRegionAccessPointInput toAWS() const {
        Aws::S3Control::Model::DeleteMultiRegionAccessPointInput awsDeleteMultiRegionAccessPointInput;

        if (!(this->name.IsEmpty())) {
            awsDeleteMultiRegionAccessPointInput.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteMultiRegionAccessPointInput;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty();
    }

    FAWSS3ControlDeleteMultiRegionAccessPointInput &fromAWS(const Aws::S3Control::Model::DeleteMultiRegionAccessPointInput &awsDeleteMultiRegionAccessPointInput) {
        this->name = UTF8_TO_TCHAR(awsDeleteMultiRegionAccessPointInput.GetName().c_str());

        return *this;
    }
#endif
};
