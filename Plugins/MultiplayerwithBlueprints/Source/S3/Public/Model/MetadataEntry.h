/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/MetadataEntry.h"

#endif

#include "MetadataEntry.generated.h"

USTRUCT(BlueprintType)
struct FMetadataEntry {
GENERATED_BODY()

    /**
    *  <p>Name of the Object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString name;

    /**
    *  <p>Value of the Object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString value;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::MetadataEntry toAWS() const {
        Aws::S3::Model::MetadataEntry awsMetadataEntry;

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
