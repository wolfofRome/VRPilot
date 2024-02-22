/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/JSONOutput.h"

#endif

#include "JSONOutput.generated.h"

USTRUCT(BlueprintType)
struct FJSONOutput {
GENERATED_BODY()

    /**
    *  <p>The value used to separate individual records in the output. If no value is specified, Amazon S3 uses a newline character ('\n').</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString recordDelimiter;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::JSONOutput toAWS() const {
        Aws::S3::Model::JSONOutput awsJSONOutput;

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
