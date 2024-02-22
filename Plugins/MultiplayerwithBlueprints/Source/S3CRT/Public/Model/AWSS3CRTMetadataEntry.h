/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/MetadataEntry.h"

#endif

#include "AWSS3CRTMetadataEntry.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTMetadataEntry {
GENERATED_BODY()

    /**
    *  <p>Name of the Object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString name;

    /**
    *  <p>Value of the Object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString value;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::MetadataEntry toAWS() const {
        Aws::S3Crt::Model::MetadataEntry awsMetadataEntry;

        if (!(this->name.IsEmpty())) {
            awsMetadataEntry.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->value.IsEmpty())) {
            awsMetadataEntry.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsMetadataEntry;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->value.IsEmpty();
    }
#endif
};
