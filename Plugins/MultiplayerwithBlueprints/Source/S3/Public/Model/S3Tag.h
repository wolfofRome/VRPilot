/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Tag.h"

#endif

#include "S3Tag.generated.h"

USTRUCT(BlueprintType)
struct FS3Tag {
GENERATED_BODY()

    /**
    *  <p>Name of the object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Value of the tag.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString value;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Tag toAWS() const {
        Aws::S3::Model::Tag awsTag;

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

    FS3Tag &fromAWS(const Aws::S3::Model::Tag &awsTag) {
        this->key = UTF8_TO_TCHAR(awsTag.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsTag.GetValue().c_str());

        return *this;
    }
#endif
};
