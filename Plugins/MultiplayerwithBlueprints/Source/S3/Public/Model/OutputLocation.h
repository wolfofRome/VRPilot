/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/OutputLocation.h"

#endif

#include "Model/S3Location.h"

#include "OutputLocation.generated.h"

USTRUCT(BlueprintType)
struct FOutputLocation {
GENERATED_BODY()

    /**
    *  <p>Describes an S3 location that will receive the results of the restore request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Location s3;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::OutputLocation toAWS() const {
        Aws::S3::Model::OutputLocation awsOutputLocation;

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
