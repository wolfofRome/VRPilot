/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Tag.h"

#endif

#include "AWSS3CRTTag.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTTag {
GENERATED_BODY()

    /**
    *  <p>Name of the object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Value of the tag.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString value;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Tag toAWS() const {
        Aws::S3Crt::Model::Tag awsTag;

        if (!(this->key.IsEmpty())) {
            awsTag.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->value.IsEmpty())) {
            awsTag.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsTag;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->value.IsEmpty();
    }

    FAWSS3CRTTag &fromAWS(const Aws::S3Crt::Model::Tag &awsTag) {
        this->key = UTF8_TO_TCHAR(awsTag.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsTag.GetValue().c_str());

        return *this;
    }
#endif
};
