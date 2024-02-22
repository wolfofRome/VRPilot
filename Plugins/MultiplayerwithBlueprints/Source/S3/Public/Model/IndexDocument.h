/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/IndexDocument.h"

#endif

#include "IndexDocument.generated.h"

USTRUCT(BlueprintType)
struct FIndexDocument {
GENERATED_BODY()

    /**
    *  <p>A suffix that is appended to a request that is for a directory on the website endpoint (for example,if the suffix is index.html and you make a request to samplebucket/images/ the data that is returned will be for the object with the key name images/index.html) The suffix must not be empty and must not include a slash character.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString suffix;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::IndexDocument toAWS() const {
        Aws::S3::Model::IndexDocument awsIndexDocument;

		if (!(this->suffix.IsEmpty())) {
            awsIndexDocument.SetSuffix(TCHAR_TO_UTF8(*this->suffix));
        }

        return awsIndexDocument;
    }

    bool IsEmpty() const {
        return this->suffix.IsEmpty();
    }

    FIndexDocument &fromAWS(const Aws::S3::Model::IndexDocument &awsIndexDocument) {
        this->suffix = UTF8_TO_TCHAR(awsIndexDocument.GetSuffix().c_str());

        return *this;
    }
#endif
};
