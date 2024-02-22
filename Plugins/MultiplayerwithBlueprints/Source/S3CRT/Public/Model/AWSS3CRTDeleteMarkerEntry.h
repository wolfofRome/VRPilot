/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteMarkerEntry.h"

#endif

#include "Model/AWSS3CRTOwner.h"

#include "AWSS3CRTDeleteMarkerEntry.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteMarkerEntry {
GENERATED_BODY()

    /**
    *  <p>The account that created the delete marker.&gt;</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

    /**
    *  <p>The object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Version ID of an object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>Specifies whether the object is (true) or is not (false) the latest version of an object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isLatest = false;

    /**
    *  <p>Date and time the object was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTDeleteMarkerEntry &fromAWS(const Aws::S3Crt::Model::DeleteMarkerEntry &awsDeleteMarkerEntry) {
        this->owner = FAWSS3CRTOwner().fromAWS(awsDeleteMarkerEntry.GetOwner());

        this->key = UTF8_TO_TCHAR(awsDeleteMarkerEntry.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsDeleteMarkerEntry.GetVersionId().c_str());

        this->isLatest = awsDeleteMarkerEntry.GetIsLatest();

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsDeleteMarkerEntry.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
