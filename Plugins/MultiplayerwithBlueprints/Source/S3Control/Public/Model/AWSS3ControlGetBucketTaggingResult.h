/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketTaggingResult.h"

#endif

#include "Model/S3ControlS3Tag.h"

#include "AWSS3ControlGetBucketTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The tags set of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tagSet;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetBucketTaggingResult &fromAWS(const Aws::S3Control::Model::GetBucketTaggingResult &awsGetBucketTaggingResult) {
        this->tagSet.Empty();
        for (const Aws::S3Control::Model::S3Tag& elem : awsGetBucketTaggingResult.GetTagSet()) {
            this->tagSet.Add(FS3ControlS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
