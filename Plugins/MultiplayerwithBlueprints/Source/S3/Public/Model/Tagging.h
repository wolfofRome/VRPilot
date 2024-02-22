/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Tagging.h"

#endif

#include "Model/S3Tag.h"

#include "Tagging.generated.h"

USTRUCT(BlueprintType)
struct FTagging {
GENERATED_BODY()

    /**
    *  <p>A collection for a set of tags</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Tag> tagSet;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Tagging toAWS() const {
        Aws::S3::Model::Tagging awsTagging;

        for (const FS3Tag& elem : this->tagSet) {
            awsTagging.AddTagSet(elem.toAWS());
        }

        return awsTagging;
    }

    bool IsEmpty() const {
        return this->tagSet.Num() == 0;
    }
#endif
};
