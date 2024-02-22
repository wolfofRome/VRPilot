/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Bucket.h"

#endif


#include "AWSS3CRTBucket.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTBucket {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString name;

    /**
    *  <p>Date the bucket was created. This date can change when making changes to your bucket, such as editing its bucket policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime creationDate;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTBucket &fromAWS(const Aws::S3Crt::Model::Bucket &awsBucket) {
        this->name = UTF8_TO_TCHAR(awsBucket.GetName().c_str());

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsBucket.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
