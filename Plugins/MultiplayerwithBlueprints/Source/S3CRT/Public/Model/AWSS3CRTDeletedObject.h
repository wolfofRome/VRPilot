/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeletedObject.h"

#endif

#include "AWSS3CRTDeletedObject.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeletedObject {
GENERATED_BODY()

    /**
    *  <p>The name of the deleted object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>The version ID of the deleted object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>Specifies whether the versioned object that was permanently deleted was (true) or was not (false) a delete marker. In a simple DELETE, this header indicates whether (true) or not (false) a delete marker was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool deleteMarker = false;

    /**
    *  <p>The version ID of the delete marker created as a result of the DELETE operation. If you delete a specific object version, the value returned by this header is the version ID of the object version deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString deleteMarkerVersionId;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTDeletedObject &fromAWS(const Aws::S3Crt::Model::DeletedObject &awsDeletedObject) {
        this->key = UTF8_TO_TCHAR(awsDeletedObject.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsDeletedObject.GetVersionId().c_str());

        this->deleteMarker = awsDeletedObject.GetDeleteMarker();

        this->deleteMarkerVersionId = UTF8_TO_TCHAR(awsDeletedObject.GetDeleteMarkerVersionId().c_str());

        return *this;
    }
#endif
};
