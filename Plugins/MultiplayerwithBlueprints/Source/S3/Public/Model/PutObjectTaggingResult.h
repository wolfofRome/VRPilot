/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutObjectTaggingResult.h"

#endif

#include "PutObjectTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FPutObjectTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The versionId of the object the tag-set was added to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FPutObjectTaggingResult &fromAWS(const Aws::S3::Model::PutObjectTaggingResult &awsPutObjectTaggingResult) {
        this->versionId = UTF8_TO_TCHAR(awsPutObjectTaggingResult.GetVersionId().c_str());

        return *this;
    }
#endif
};
