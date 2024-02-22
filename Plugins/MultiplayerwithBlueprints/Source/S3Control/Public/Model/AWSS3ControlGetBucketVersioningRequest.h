/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketVersioningRequest.h"

#endif

#include "AWSS3ControlGetBucketVersioningRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketVersioningRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID of the S3 on Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The S3 on Outposts bucket to return the versioning state for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetBucketVersioningRequest toAWS() const {
        Aws::S3Control::Model::GetBucketVersioningRequest awsGetBucketVersioningRequest;

        if (!(this->accountId.IsEmpty())) {
            awsGetBucketVersioningRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketVersioningRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        return awsGetBucketVersioningRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->bucket.IsEmpty();
    }
#endif
};
