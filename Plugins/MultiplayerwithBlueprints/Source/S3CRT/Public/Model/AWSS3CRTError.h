/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Error.h"

#endif

#include "AWSS3CRTError.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTError {
GENERATED_BODY()

    /**
    *  <p>The error key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>The version ID of the error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>The error code is a string that uniquely identifies an error condition. It is meant to be read and understood by programs that detect and handle errors by type. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString code;

    /**
    *  <p>The error message contains a generic description of the error condition in English. It is intended for a human audience. Simple programs display the message directly to the end user if they encounter an error condition they don't know how or don't care to handle. Sophisticated programs with more exhaustive error handling and proper internationalization are more likely to ignore the error message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString message;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTError &fromAWS(const Aws::S3Crt::Model::Error &awsError) {
        this->key = UTF8_TO_TCHAR(awsError.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsError.GetVersionId().c_str());

        this->code = UTF8_TO_TCHAR(awsError.GetCode().c_str());

        this->message = UTF8_TO_TCHAR(awsError.GetMessage().c_str());

        return *this;
    }
#endif
};
