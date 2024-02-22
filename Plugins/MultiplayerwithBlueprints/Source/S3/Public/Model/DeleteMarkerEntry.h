/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteMarkerEntry.h"

#endif

#include "Model/Owner.h"

#include "DeleteMarkerEntry.generated.h"

USTRUCT(BlueprintType)
struct FDeleteMarkerEntry {
GENERATED_BODY()

    /**
    *  <p>The account that created the delete marker.&gt;</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

    /**
    *  <p>The object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Version ID of an object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>Specifies whether the object is (true) or is not (false) the latest version of an object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isLatest = false;

    /**
    *  <p>Date and time the object was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FDeleteMarkerEntry &fromAWS(const Aws::S3::Model::DeleteMarkerEntry &awsDeleteMarkerEntry) {
        this->owner.fromAWS(awsDeleteMarkerEntry.GetOwner());

        this->key = UTF8_TO_TCHAR(awsDeleteMarkerEntry.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsDeleteMarkerEntry.GetVersionId().c_str());

        this->isLatest = awsDeleteMarkerEntry.GetIsLatest();

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsDeleteMarkerEntry.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
