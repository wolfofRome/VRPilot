/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/Region.h"

#endif


#include "AWSS3ControlRegion.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlRegion {
GENERATED_BODY()

    /**
    *  <p>The name of the associated bucket for the Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::Region toAWS() const {
        Aws::S3Control::Model::Region awsRegion;
// @TODO: check
		if (!(this->bucket.IsEmpty())) {
            awsRegion.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }
        return awsRegion;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && true;
    }

    FAWSS3ControlRegion &fromAWS(const Aws::S3Control::Model::Region &awsRegion) {
// @TODO: check
        this->bucket = UTF8_TO_TCHAR(awsRegion.GetBucket().c_str());

        return *this;
    }
#endif
};
