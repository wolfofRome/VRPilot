/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Tagging.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTTagging.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTTagging {
GENERATED_BODY()

    /**
    *  <p>A collection for a set of tags</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tagSet;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Tagging toAWS() const {
        Aws::S3Crt::Model::Tagging awsTagging;

        for (const FAWSS3CRTTag& elem : this->tagSet) {
            awsTagging.AddTagSet(elem.toAWS());
        }

        return awsTagging;
    }

    bool IsEmpty() const {
        return this->tagSet.Num() == 0;
    }
#endif
};
