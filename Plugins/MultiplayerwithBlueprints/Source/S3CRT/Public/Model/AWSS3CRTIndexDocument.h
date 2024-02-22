/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/IndexDocument.h"

#endif

#include "AWSS3CRTIndexDocument.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTIndexDocument {
GENERATED_BODY()

    /**
    *  <p>A suffix that is appended to a request that is for a directory on the website endpoint (for example,if the suffix is index.html and you make a request to samplebucket/images/ the data that is returned will be for the object with the key name images/index.html) The suffix must not be empty and must not include a slash character.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString suffix;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::IndexDocument toAWS() const {
        Aws::S3Crt::Model::IndexDocument awsIndexDocument;

        if (!(this->suffix.IsEmpty())) {
            awsIndexDocument.SetSuffix(TCHAR_TO_UTF8(*this->suffix));
        }

        return awsIndexDocument;
    }

    bool IsEmpty() const {
        return this->suffix.IsEmpty();
    }

    FAWSS3CRTIndexDocument &fromAWS(const Aws::S3Crt::Model::IndexDocument &awsIndexDocument) {
        this->suffix = UTF8_TO_TCHAR(awsIndexDocument.GetSuffix().c_str());

        return *this;
    }
#endif
};
