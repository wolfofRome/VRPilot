/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteObjectTaggingResult.h"

#endif

#include "DeleteObjectTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteObjectTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The versionId of the object the tag-set was removed from.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FDeleteObjectTaggingResult &fromAWS(const Aws::S3::Model::DeleteObjectTaggingResult &awsDeleteObjectTaggingResult) {
        this->versionId = UTF8_TO_TCHAR(awsDeleteObjectTaggingResult.GetVersionId().c_str());

        return *this;
    }
#endif
};
