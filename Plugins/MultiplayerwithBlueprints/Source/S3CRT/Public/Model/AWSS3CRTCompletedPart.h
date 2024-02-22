/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CompletedPart.h"

#endif

#include "AWSS3CRTCompletedPart.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCompletedPart {
GENERATED_BODY()

    /**
    *  <p>Entity tag returned when the part was uploaded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>Part number that identifies the part. This is a positive integer between 1 and 10,000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partNumber = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CompletedPart toAWS() const {
        Aws::S3Crt::Model::CompletedPart awsCompletedPart;

        if (!(this->eTag.IsEmpty())) {
            awsCompletedPart.SetETag(TCHAR_TO_UTF8(*this->eTag));
        }

        if (!(this->partNumber == 0)) {
            awsCompletedPart.SetPartNumber(this->partNumber);
        }

        return awsCompletedPart;
    }

    bool IsEmpty() const {
        return this->eTag.IsEmpty() && this->partNumber == 0 ;
    }
#endif
};
