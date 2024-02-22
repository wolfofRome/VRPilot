/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketLoggingResult.h"

#endif

#include "Model/AWSS3CRTLoggingEnabled.h"

#include "AWSS3CRTGetBucketLoggingResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketLoggingResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTLoggingEnabled loggingEnabled;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketLoggingResult &fromAWS(const Aws::S3Crt::Model::GetBucketLoggingResult &awsGetBucketLoggingResult) {
        this->loggingEnabled = FAWSS3CRTLoggingEnabled().fromAWS(awsGetBucketLoggingResult.GetLoggingEnabled());

        return *this;
    }
#endif
};
