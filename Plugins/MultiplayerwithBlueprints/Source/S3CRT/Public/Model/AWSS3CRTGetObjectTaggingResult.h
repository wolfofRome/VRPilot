/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetObjectTaggingResult.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTGetObjectTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The versionId of the object for which you got the tagging information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>Contains the tag set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tagSet;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectTaggingResult &fromAWS(const Aws::S3Crt::Model::GetObjectTaggingResult &awsGetObjectTaggingResult) {
        this->versionId = UTF8_TO_TCHAR(awsGetObjectTaggingResult.GetVersionId().c_str());

        this->tagSet.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsGetObjectTaggingResult.GetTagSet()) {
            this->tagSet.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
