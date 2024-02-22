/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Progress.h"

#endif

#include "Progress.generated.h"

USTRUCT(BlueprintType)
struct FProgress {
GENERATED_BODY()

    /**
    *  <p>The current number of object bytes scanned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 bytesScanned = 0;

    /**
    *  <p>The current number of uncompressed object bytes processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 bytesProcessed = 0;

    /**
    *  <p>The current number of bytes of records payload data returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 bytesReturned = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FProgress &fromAWS(const Aws::S3::Model::Progress &awsProgress) {
        this->bytesScanned = (int64)awsProgress.GetBytesScanned();
        
        this->bytesProcessed = (int64)awsProgress.GetBytesProcessed();
        
        this->bytesReturned = (int64)awsProgress.GetBytesReturned();

        return *this;
    }
#endif
};
