/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutBucketVersioningRequest.h"

#endif

#include "Model/AWSS3ControlVersioningConfiguration.h"

#include "AWSS3ControlPutBucketVersioningRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlPutBucketVersioningRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID of the S3 on Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The S3 on Outposts bucket to set the versioning state for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The concatenation of the authentication device's serial number, a space, and the value that is displayed on your authentication device.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString mFA;

    /**
    *  <p>The root-level tag for the <code>VersioningConfiguration</code> parameters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlVersioningConfiguration versioningConfiguration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutBucketVersioningRequest toAWS() const {
        Aws::S3Control::Model::PutBucketVersioningRequest awsPutBucketVersioningRequest;

        if (!(this->accountId.IsEmpty())) {
            awsPutBucketVersioningRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketVersioningRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->mFA.IsEmpty())) {
            awsPutBucketVersioningRequest.SetMFA(TCHAR_TO_UTF8(*this->mFA));
        }

        if (!(this->versioningConfiguration.IsEmpty())) {
            awsPutBucketVersioningRequest.SetVersioningConfiguration(this->versioningConfiguration.toAWS());
        }

        return awsPutBucketVersioningRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->bucket.IsEmpty() && this->mFA.IsEmpty() && this->versioningConfiguration.IsEmpty();
    }
#endif
};
