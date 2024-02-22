/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketTaggingResult.h"

#endif

#include "Model/S3Tag.h"

#include "GetBucketTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketTaggingResult {
GENERATED_BODY()

    /**
    *  <p>Contains the tag set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Tag> tagSet;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketTaggingResult &fromAWS(const Aws::S3::Model::GetBucketTaggingResult &awsGetBucketTaggingResult) {
        this->tagSet.Empty();
        for (const Aws::S3::Model::Tag& elem : awsGetBucketTaggingResult.GetTagSet()) {
            this->tagSet.Add(FS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
