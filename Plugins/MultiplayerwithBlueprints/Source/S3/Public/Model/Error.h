/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Error.h"

#endif

#include "Error.generated.h"

USTRUCT(BlueprintType)
struct FError {
GENERATED_BODY()

    /**
    *  <p>The error key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>The version ID of the error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  The error code is a string that uniquely identifies an error condition. It is meant to be read and understood by programs that detect and handle errors by type.
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString code;

    /**
    *  <p>The error message contains a generic description of the error condition in English. It is intended for a human audience. Simple programs display the message directly to the end user if they encounter an error condition they don't know how or don't care to handle. Sophisticated programs with more exhaustive error handling and proper internationalization are more likely to ignore the error message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString message;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FError &fromAWS(const Aws::S3::Model::Error &awsError) {
        this->key = UTF8_TO_TCHAR(awsError.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsError.GetVersionId().c_str());

        this->code = UTF8_TO_TCHAR(awsError.GetCode().c_str());

        this->message = UTF8_TO_TCHAR(awsError.GetMessage().c_str());

        return *this;
    }
#endif
};
