/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3SetObjectTaggingOperation.h"

#endif

#include "Model/S3ControlS3Tag.h"

#include "S3SetObjectTaggingOperation.generated.h"

USTRUCT(BlueprintType)
struct FS3SetObjectTaggingOperation {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tagSet;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3SetObjectTaggingOperation toAWS() const {
        Aws::S3Control::Model::S3SetObjectTaggingOperation awsS3SetObjectTaggingOperation;

        for (const FS3ControlS3Tag& elem : this->tagSet) {
            awsS3SetObjectTaggingOperation.AddTagSet(elem.toAWS());
        }

        return awsS3SetObjectTaggingOperation;
    }

    bool IsEmpty() const {
        return this->tagSet.Num() == 0;
    }

    FS3SetObjectTaggingOperation &fromAWS(const Aws::S3Control::Model::S3SetObjectTaggingOperation &awsS3SetObjectTaggingOperation) {
        this->tagSet.Empty();
        for (const Aws::S3Control::Model::S3Tag& elem : awsS3SetObjectTaggingOperation.GetTagSet()) {
            this->tagSet.Add(FS3ControlS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
