/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ObjectVersion.h"

#endif

#include "Model/AWSS3CRTObjectVersionStorageClass.h"
#include "Model/AWSS3CRTOwner.h"

#include "AWSS3CRTObjectVersion.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObjectVersion {
GENERATED_BODY()

    /**
    *  <p>The entity tag is an MD5 hash of that version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>Size in bytes of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 size = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectVersionStorageClass storageClass = EAWSS3CRTObjectVersionStorageClass::NOT_SET;

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

    /**
    *  <p>Specifies the owner of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTObjectVersion &fromAWS(const Aws::S3Crt::Model::ObjectVersion &awsObjectVersion) {
        this->eTag = UTF8_TO_TCHAR(awsObjectVersion.GetETag().c_str());

        this->size = (int64)awsObjectVersion.GetSize();

        switch(awsObjectVersion.GetStorageClass()) {
            case Aws::S3Crt::Model::ObjectVersionStorageClass::NOT_SET:
                this->storageClass = EAWSS3CRTObjectVersionStorageClass::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectVersionStorageClass::STANDARD:
                this->storageClass = EAWSS3CRTObjectVersionStorageClass::STANDARD;
                break;
            default:
                this->storageClass = EAWSS3CRTObjectVersionStorageClass::NOT_SET;
                break;
        }

        this->key = UTF8_TO_TCHAR(awsObjectVersion.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsObjectVersion.GetVersionId().c_str());

        this->isLatest = awsObjectVersion.GetIsLatest();

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsObjectVersion.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->owner = FAWSS3CRTOwner().fromAWS(awsObjectVersion.GetOwner());

        return *this;
    }
#endif
};
