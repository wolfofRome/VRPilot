/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectTaggingResult.h"

#endif

#include "Model/S3Tag.h"

#include "GetObjectTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The versionId of the object for which you got the tagging information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>Contains the tag set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Tag> tagSet;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectTaggingResult &fromAWS(const Aws::S3::Model::GetObjectTaggingResult &awsGetObjectTaggingResult) {
        this->versionId = UTF8_TO_TCHAR(awsGetObjectTaggingResult.GetVersionId().c_str());

        this->tagSet.Empty();
        for (const Aws::S3::Model::Tag& elem : awsGetObjectTaggingResult.GetTagSet()) {
            this->tagSet.Add(FS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
