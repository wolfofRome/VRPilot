/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ErrorDocument.h"

#endif

#include "AWSS3CRTErrorDocument.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTErrorDocument {
GENERATED_BODY()

    /**
    *  <p>The object key name to use when a 4XX class error occurs.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ErrorDocument toAWS() const {
        Aws::S3Crt::Model::ErrorDocument awsErrorDocument;

        if (!(this->key.IsEmpty())) {
            awsErrorDocument.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        return awsErrorDocument;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty();
    }

    FAWSS3CRTErrorDocument &fromAWS(const Aws::S3Crt::Model::ErrorDocument &awsErrorDocument) {
        this->key = UTF8_TO_TCHAR(awsErrorDocument.GetKey().c_str());

        return *this;
    }
#endif
};
