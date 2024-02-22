/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/StorageLensTag.h"

#endif

#include "AWSS3ControlStorageLensTag.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlStorageLensTag {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString key;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString value;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::StorageLensTag toAWS() const {
        Aws::S3Control::Model::StorageLensTag awsStorageLensTag;

        if (!(this->key.IsEmpty())) {
            awsStorageLensTag.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->value.IsEmpty())) {
            awsStorageLensTag.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsStorageLensTag;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->value.IsEmpty();
    }

    FAWSS3ControlStorageLensTag &fromAWS(const Aws::S3Control::Model::StorageLensTag &awsStorageLensTag) {
        this->key = UTF8_TO_TCHAR(awsStorageLensTag.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsStorageLensTag.GetValue().c_str());

        return *this;
    }
#endif
};
