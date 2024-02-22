/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeletedObject.h"

#endif

#include "DeletedObject.generated.h"

USTRUCT(BlueprintType)
struct FDeletedObject {
GENERATED_BODY()

    /**
    *  <p>The name of the deleted object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>The version ID of the deleted object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>Specifies whether the versioned object that was permanently deleted was (true) or was not (false) a delete marker. In a simple DELETE, this header indicates whether (true) or not (false) a delete marker was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool deleteMarker = false;

    /**
    *  <p>The version ID of the delete marker created as a result of the DELETE operation. If you delete a specific object version, the value returned by this header is the version ID of the object version deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString deleteMarkerVersionId;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FDeletedObject &fromAWS(const Aws::S3::Model::DeletedObject &awsDeletedObject) {
        this->key = UTF8_TO_TCHAR(awsDeletedObject.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsDeletedObject.GetVersionId().c_str());

        this->deleteMarker = awsDeletedObject.GetDeleteMarker();

        this->deleteMarkerVersionId = UTF8_TO_TCHAR(awsDeletedObject.GetDeleteMarkerVersionId().c_str());

        return *this;
    }
#endif
};
