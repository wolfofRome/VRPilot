/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3Tag.h"

#endif

#include "S3ControlS3Tag.generated.h"

USTRUCT(BlueprintType)
struct FS3ControlS3Tag {
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
    Aws::S3Control::Model::S3Tag toAWS() const {
        Aws::S3Control::Model::S3Tag awsS3Tag;

		if (!(this->key.IsEmpty())) {
            awsS3Tag.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		if (!(this->value.IsEmpty())) {
            awsS3Tag.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsS3Tag;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->value.IsEmpty();
    }

    FS3ControlS3Tag &fromAWS(const Aws::S3Control::Model::S3Tag &awsS3Tag) {
        this->key = UTF8_TO_TCHAR(awsS3Tag.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsS3Tag.GetValue().c_str());

        return *this;
    }
#endif
};
