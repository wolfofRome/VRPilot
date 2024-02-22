/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Part.h"

#endif

#include "AWSS3CRTPart.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPart {
GENERATED_BODY()

    /**
    *  <p>Part number identifying the part. This is a positive integer between 1 and 10,000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partNumber = 0;

    /**
    *  <p>Date and time at which the part was uploaded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

    /**
    *  <p>Entity tag returned when the part was uploaded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>Size in bytes of the uploaded part data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 size = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTPart &fromAWS(const Aws::S3Crt::Model::Part &awsPart) {
		this->partNumber = awsPart.GetPartNumber();

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsPart.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->eTag = UTF8_TO_TCHAR(awsPart.GetETag().c_str());

        this->size = (int64)awsPart.GetSize();

        return *this;
    }
#endif
};
