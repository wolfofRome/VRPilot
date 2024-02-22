/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ErrorDocument.h"

#endif

#include "ErrorDocument.generated.h"

USTRUCT(BlueprintType)
struct FErrorDocument {
GENERATED_BODY()

    /**
    *  <p>The object key name to use when a 4XX class error occurs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ErrorDocument toAWS() const {
        Aws::S3::Model::ErrorDocument awsErrorDocument;

		if (!(this->key.IsEmpty())) {
            awsErrorDocument.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        return awsErrorDocument;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty();
    }

    FErrorDocument &fromAWS(const Aws::S3::Model::ErrorDocument &awsErrorDocument) {
        this->key = UTF8_TO_TCHAR(awsErrorDocument.GetKey().c_str());

        return *this;
    }
#endif
};
