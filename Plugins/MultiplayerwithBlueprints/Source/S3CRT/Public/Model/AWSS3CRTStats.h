/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Stats.h"

#endif

#include "AWSS3CRTStats.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTStats {
GENERATED_BODY()

    /**
     * <p>The total number of object bytes scanned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 bytesScanned = 0;

    /**
     * <p>The total number of uncompressed object bytes processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 bytesProcessed = 0;

    /**
     * <p>The total number of bytes of records payload data returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 bytesReturned = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTStats &fromAWS(const Aws::S3Crt::Model::Stats &awsStats) {
        this->bytesScanned = (int64)awsStats.GetBytesScanned();

        this->bytesProcessed = (int64)awsStats.GetBytesProcessed();

        this->bytesReturned = (int64)awsStats.GetBytesReturned();

        return *this;
    }
#endif
};
