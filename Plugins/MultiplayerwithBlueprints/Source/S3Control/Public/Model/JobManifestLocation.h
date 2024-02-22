/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobManifestLocation.h"

#endif


#include "JobManifestLocation.generated.h"

USTRUCT(BlueprintType)
struct FJobManifestLocation {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for a manifest object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString objectArn;

    /**
    *  <p>The optional version ID to identify a specific version of the manifest object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString objectVersionId;

    /**
    *  <p>The ETag for the specified manifest object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString eTag;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobManifestLocation toAWS() const {
        Aws::S3Control::Model::JobManifestLocation awsJobManifestLocation;

		if (!(this->objectArn.IsEmpty())) {
            awsJobManifestLocation.SetObjectArn(TCHAR_TO_UTF8(*this->objectArn));
        }

		if (!(this->objectVersionId.IsEmpty())) {
            awsJobManifestLocation.SetObjectVersionId(TCHAR_TO_UTF8(*this->objectVersionId));
        }

		if (!(this->eTag.IsEmpty())) {
            awsJobManifestLocation.SetETag(TCHAR_TO_UTF8(*this->eTag));
        }

        return awsJobManifestLocation;
    }

    bool IsEmpty() const {
        return this->objectArn.IsEmpty() && this->objectVersionId.IsEmpty() && this->eTag.IsEmpty();
    }

    FJobManifestLocation &fromAWS(const Aws::S3Control::Model::JobManifestLocation &awsJobManifestLocation) {
        this->objectArn = UTF8_TO_TCHAR(awsJobManifestLocation.GetObjectArn().c_str());

        this->objectVersionId = UTF8_TO_TCHAR(awsJobManifestLocation.GetObjectVersionId().c_str());

        this->eTag = UTF8_TO_TCHAR(awsJobManifestLocation.GetETag().c_str());

        return *this;
    }
#endif
};
