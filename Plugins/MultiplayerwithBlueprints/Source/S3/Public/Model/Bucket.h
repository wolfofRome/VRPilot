/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Bucket.h"

#endif

#include "Bucket.generated.h"

USTRUCT(BlueprintType)
struct FBucket {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString name;

    /**
    *  <p>Date the bucket was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime creationDate;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FBucket &fromAWS(const Aws::S3::Model::Bucket &awsBucket) {
        this->name = UTF8_TO_TCHAR(awsBucket.GetName().c_str());

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsBucket.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
