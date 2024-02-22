/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/RegionalBucket.h"

#endif

#include "AWSS3ControlRegionalBucket.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlRegionalBucket {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The Amazon Resource Name (ARN) for the regional bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucketArn;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool publicAccessBlockEnabled = false;

    /**
    *  <p>The creation date of the regional bucket</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationDate;

    /**
    *  <p>The AWS Outposts ID of the regional bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString outpostId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlRegionalBucket &fromAWS(const Aws::S3Control::Model::RegionalBucket &awsRegionalBucket) {
        this->bucket = UTF8_TO_TCHAR(awsRegionalBucket.GetBucket().c_str());

        this->bucketArn = UTF8_TO_TCHAR(awsRegionalBucket.GetBucketArn().c_str());

        this->publicAccessBlockEnabled = awsRegionalBucket.GetPublicAccessBlockEnabled();

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsRegionalBucket.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->outpostId = UTF8_TO_TCHAR(awsRegionalBucket.GetOutpostId().c_str());

        return *this;
    }
#endif
};
