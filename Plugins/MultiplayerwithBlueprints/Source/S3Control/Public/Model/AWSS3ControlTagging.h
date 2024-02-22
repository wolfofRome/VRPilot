/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/Tagging.h"

#endif

#include "Model/S3ControlS3Tag.h"

#include "AWSS3ControlTagging.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlTagging {
GENERATED_BODY()

    /**
    *  <p>A collection for a set of tags.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tagSet;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::Tagging toAWS() const {
        Aws::S3Control::Model::Tagging awsTagging;

        for (const FS3ControlS3Tag& elem : this->tagSet) {
            awsTagging.AddTagSet(elem.toAWS());
        }

        return awsTagging;
    }

    bool IsEmpty() const {
        return this->tagSet.Num() == 0;
    }
#endif
};
