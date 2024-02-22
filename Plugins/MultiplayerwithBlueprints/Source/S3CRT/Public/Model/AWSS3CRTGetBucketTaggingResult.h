/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketTaggingResult.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTGetBucketTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketTaggingResult {
GENERATED_BODY()

    /**
    *  <p>Contains the tag set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tagSet;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketTaggingResult &fromAWS(const Aws::S3Crt::Model::GetBucketTaggingResult &awsGetBucketTaggingResult) {
        this->tagSet.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsGetBucketTaggingResult.GetTagSet()) {
            this->tagSet.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
