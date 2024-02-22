/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/OutputLocation.h"

#endif

#include "Model/AWSS3CRTS3Location.h"

#include "AWSS3CRTOutputLocation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTOutputLocation {
GENERATED_BODY()

    /**
    *  <p>Describes an S3 location that will receive the results of the restore request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTS3Location s3;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::OutputLocation toAWS() const {
        Aws::S3Crt::Model::OutputLocation awsOutputLocation;

        if (!(this->s3.IsEmpty())) {
            awsOutputLocation.SetS3(this->s3.toAWS());
        }

        return awsOutputLocation;
    }

    bool IsEmpty() const {
        return this->s3.IsEmpty();
    }
#endif
};
