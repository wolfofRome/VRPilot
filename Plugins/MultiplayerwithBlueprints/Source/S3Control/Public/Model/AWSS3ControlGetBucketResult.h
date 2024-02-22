/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketResult.h"

#endif

#include "AWSS3ControlGetBucketResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketResult {
GENERATED_BODY()

    /**
    *  <p>The Outposts bucket requested.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool publicAccessBlockEnabled = false;

    /**
    *  <p>The creation date of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationDate;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetBucketResult &fromAWS(const Aws::S3Control::Model::GetBucketResult &awsGetBucketResult) {
        this->bucket = UTF8_TO_TCHAR(awsGetBucketResult.GetBucket().c_str());

        this->publicAccessBlockEnabled = awsGetBucketResult.GetPublicAccessBlockEnabled();

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsGetBucketResult.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
