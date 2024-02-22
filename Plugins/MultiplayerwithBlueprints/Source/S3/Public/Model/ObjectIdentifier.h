/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ObjectIdentifier.h"

#endif

#include "ObjectIdentifier.generated.h"

USTRUCT(BlueprintType)
struct FObjectIdentifier {
GENERATED_BODY()

    /**
    *  <p>Key name of the object to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>VersionId for the specific version of the object to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ObjectIdentifier toAWS() const {
        Aws::S3::Model::ObjectIdentifier awsObjectIdentifier;

		if (!(this->key.IsEmpty())) {
            awsObjectIdentifier.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		if (!(this->versionId.IsEmpty())) {
            awsObjectIdentifier.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        return awsObjectIdentifier;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->versionId.IsEmpty();
    }
#endif
};
