/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutObjectTaggingResult.h"

#endif

#include "AWSS3CRTPutObjectTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutObjectTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The versionId of the object the tag-set was added to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTPutObjectTaggingResult &fromAWS(const Aws::S3Crt::Model::PutObjectTaggingResult &awsPutObjectTaggingResult) {
        this->versionId = UTF8_TO_TCHAR(awsPutObjectTaggingResult.GetVersionId().c_str());

        return *this;
    }
#endif
};
