/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Stats.h"

#endif


#include "S3Stats.generated.h"

USTRUCT(BlueprintType)
struct FS3Stats {
GENERATED_BODY()

    /**
     * <p>The total number of object bytes scanned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 bytesScanned = 0;

    /**
     * <p>The total number of uncompressed object bytes processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 bytesProcessed = 0;

    /**
     * <p>The total number of bytes of records payload data returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 bytesReturned = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FS3Stats &fromAWS(const Aws::S3::Model::Stats &awsStats) {
        this->bytesScanned = (int64)awsStats.GetBytesScanned();

        this->bytesProcessed = (int64)awsStats.GetBytesProcessed();

        this->bytesReturned = (int64)awsStats.GetBytesReturned();

        return *this;
    }
#endif
};
