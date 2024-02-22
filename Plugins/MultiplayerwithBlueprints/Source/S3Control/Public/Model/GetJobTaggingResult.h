/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetJobTaggingResult.h"

#endif

#include "Model/S3ControlS3Tag.h"

#include "GetJobTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FGetJobTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The set of tags associated with the Amazon S3 Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tags;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FGetJobTaggingResult &fromAWS(const Aws::S3Control::Model::GetJobTaggingResult &awsGetJobTaggingResult) {
        this->tags.Empty();
        for (const Aws::S3Control::Model::S3Tag& elem : awsGetJobTaggingResult.GetTags()) {
            this->tags.Add(FS3ControlS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
