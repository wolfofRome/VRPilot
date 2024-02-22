/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Progress.h"

#endif

#include "AWSS3CRTProgress.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTProgress {
GENERATED_BODY()

    /**
    *  <p>The current number of object bytes scanned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 bytesScanned = 0;

    /**
    *  <p>The current number of uncompressed object bytes processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 bytesProcessed = 0;

    /**
    *  <p>The current number of bytes of records payload data returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 bytesReturned = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTProgress &fromAWS(const Aws::S3Crt::Model::Progress &awsProgress) {
        this->bytesScanned = (int64)awsProgress.GetBytesScanned();
        
        this->bytesProcessed = (int64)awsProgress.GetBytesProcessed();
        
        this->bytesReturned = (int64)awsProgress.GetBytesReturned();

        return *this;
    }
#endif
};
