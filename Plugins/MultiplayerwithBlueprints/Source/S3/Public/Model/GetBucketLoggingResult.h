/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketLoggingResult.h"

#endif

#include "Model/LoggingEnabled.h"

#include "GetBucketLoggingResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketLoggingResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FLoggingEnabled loggingEnabled;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketLoggingResult &fromAWS(const Aws::S3::Model::GetBucketLoggingResult &awsGetBucketLoggingResult) {
        this->loggingEnabled.fromAWS(awsGetBucketLoggingResult.GetLoggingEnabled());

        return *this;
    }
#endif
};
