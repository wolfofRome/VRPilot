/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/JSONOutput.h"

#endif

#include "AWSS3CRTJSONOutput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTJSONOutput {
GENERATED_BODY()

    /**
    *  <p>The value used to separate individual records in the output. If no value is specified, Amazon S3 uses a newline character ('\n').</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString recordDelimiter;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::JSONOutput toAWS() const {
        Aws::S3Crt::Model::JSONOutput awsJSONOutput;

        if (!(this->recordDelimiter.IsEmpty())) {
            awsJSONOutput.SetRecordDelimiter(TCHAR_TO_UTF8(*this->recordDelimiter));
        }

        return awsJSONOutput;
    }

    bool IsEmpty() const {
        return this->recordDelimiter.IsEmpty();
    }
#endif
};
