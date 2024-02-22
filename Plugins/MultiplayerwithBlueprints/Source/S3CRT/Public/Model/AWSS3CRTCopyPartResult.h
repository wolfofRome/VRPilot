/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CopyPartResult.h"

#endif

#include "AWSS3CRTCopyPartResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCopyPartResult {
GENERATED_BODY()

    /**
    *  <p>Entity tag of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>Date and time at which the object was uploaded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTCopyPartResult &fromAWS(const Aws::S3Crt::Model::CopyPartResult &awsCopyPartResult) {
        this->eTag = UTF8_TO_TCHAR(awsCopyPartResult.GetETag().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsCopyPartResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
