/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetStorageLensConfigurationTaggingResult.h"

#endif

#include "Model/AWSS3ControlStorageLensTag.h"

#include "AWSS3ControlGetStorageLensConfigurationTaggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetStorageLensConfigurationTaggingResult {
GENERATED_BODY()

    /**
    *  <p>The tags of S3 Storage Lens configuration requested.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlStorageLensTag> tags;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetStorageLensConfigurationTaggingResult &fromAWS(const Aws::S3Control::Model::GetStorageLensConfigurationTaggingResult &awsGetStorageLensConfigurationTaggingResult) {
        this->tags.Empty();
        for (const Aws::S3Control::Model::StorageLensTag& elem : awsGetStorageLensConfigurationTaggingResult.GetTags()) {
            this->tags.Add(FAWSS3ControlStorageLensTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
