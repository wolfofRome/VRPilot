/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Object.h"

#endif

#include "Model/AWSS3CRTObjectStorageClass.h"
#include "Model/AWSS3CRTOwner.h"

#include "AWSS3CRTObject.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObject {
GENERATED_BODY()

    /**
    *  <p>The name that you assign to an object. You use the object key to retrieve the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

    /**
    *  <p>The entity tag is a hash of the object. The ETag reflects changes only to the contents of an object, not its metadata. The ETag may or may not be an MD5 digest of the object data. Whether or not it is depends on how the object was created and how it is encrypted as described below:</p> <ul> <li> <p>Objects created by the PUT Object, POST Object, or Copy operation, or through the AWS Management Console, and are encrypted by SSE-S3 or plaintext, have ETags that are an MD5 digest of their object data.</p> </li> <li> <p>Objects created by the PUT Object, POST Object, or Copy operation, or through the AWS Management Console, and are encrypted by SSE-C or SSE-KMS, have ETags that are not an MD5 digest of their object data.</p> </li> <li> <p>If an object is created by either the Multipart Upload or Part Copy operation, the ETag is not an MD5 digest, regardless of the method of encryption.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>Size in bytes of the object</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 size = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectStorageClass storageClass = EAWSS3CRTObjectStorageClass::NOT_SET;

    /**
    *  <p>The owner of the object</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTObject &fromAWS(const Aws::S3Crt::Model::Object &awsObject) {
        this->key = UTF8_TO_TCHAR(awsObject.GetKey().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsObject.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->eTag = UTF8_TO_TCHAR(awsObject.GetETag().c_str());

        this->size = (int64)awsObject.GetSize();

        switch(awsObject.GetStorageClass()) {
            case Aws::S3Crt::Model::ObjectStorageClass::NOT_SET:
                this->storageClass = EAWSS3CRTObjectStorageClass::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::STANDARD:
                this->storageClass = EAWSS3CRTObjectStorageClass::STANDARD;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3CRTObjectStorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::GLACIER:
                this->storageClass = EAWSS3CRTObjectStorageClass::GLACIER;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::STANDARD_IA:
                this->storageClass = EAWSS3CRTObjectStorageClass::STANDARD_IA;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3CRTObjectStorageClass::ONEZONE_IA;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3CRTObjectStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3CRTObjectStorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3Crt::Model::ObjectStorageClass::OUTPOSTS:
                this->storageClass = EAWSS3CRTObjectStorageClass::OUTPOSTS;
                break;
            default:
                this->storageClass = EAWSS3CRTObjectStorageClass::NOT_SET;
                break;
        }

        this->owner = FAWSS3CRTOwner().fromAWS(awsObject.GetOwner());

        return *this;
    }
#endif
};
