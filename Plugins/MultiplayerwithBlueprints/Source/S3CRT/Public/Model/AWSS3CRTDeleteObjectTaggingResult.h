/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteObjectTaggingResult.h"

#endif

#include "AWSS3CRTDeleteObjectTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteObjectTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The versionId of the object the tag-set was removed from.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTDeleteObjectTaggingResult &fromAWS(const Aws::S3Crt::Model::DeleteObjectTaggingResult &awsDeleteObjectTaggingResult) {
        this->versionId = UTF8_TO_TCHAR(awsDeleteObjectTaggingResult.GetVersionId().c_str());

        return *this;
    }
#endif
};
