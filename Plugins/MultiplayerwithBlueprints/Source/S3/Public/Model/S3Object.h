/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Object.h"

#endif

#include "Model/AWSS3ChecksumAlgorithm.h"
#include "Model/ObjectStorageClass.h"
#include "Model/Owner.h"

#include "S3Object.generated.h"

USTRUCT(BlueprintType)
struct FS3Object {
GENERATED_BODY()

    /**
    *  <p>The name that you assign to an object. You use the object key to retrieve the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

    /**
    *  <p>The entity tag is a hash of the object. The ETag reflects changes only to the contents of an object, not its metadata. The ETag may or may not be an MD5 digest of the object data. Whether or not it is depends on how the object was created and how it is encrypted as described below:</p> <ul> <li> <p>Objects created by the PUT Object, POST Object, or Copy operation, or through the Amazon Web Services Management Console, and are encrypted by SSE-S3 or plaintext, have ETags that are an MD5 digest of their object data.</p> </li> <li> <p>Objects created by the PUT Object, POST Object, or Copy operation, or through the Amazon Web Services Management Console, and are encrypted by SSE-C or SSE-KMS, have ETags that are not an MD5 digest of their object data.</p> </li> <li> <p>If an object is created by either the Multipart Upload or Part Copy operation, the ETag is not an MD5 digest, regardless of the method of encryption. If an object is larger than 16 MB, the Amazon Web Services Management Console will upload or copy that object as a Multipart Upload, and therefore the ETag will not be an MD5 digest.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;
    
    /**
    *  <p>The algorithm that was used to create a checksum of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<EAWSS3ChecksumAlgorithm> checksumAlgorithm;
    
    /**
    *  <p>Size in bytes of the object</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 size = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectStorageClass storageClass = EAWSObjectStorageClass::NOT_SET;

    /**
    *  <p>The owner of the object</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FS3Object &fromAWS(const Aws::S3::Model::Object &awsObject) {
        this->key = UTF8_TO_TCHAR(awsObject.GetKey().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsObject.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->eTag = UTF8_TO_TCHAR(awsObject.GetETag().c_str());

        this->checksumAlgorithm.Empty();
        for (const Aws::S3::Model::ChecksumAlgorithm& elem : awsObject.GetChecksumAlgorithm()) {
            switch(elem) {
                case Aws::S3::Model::ChecksumAlgorithm::NOT_SET:
                    this->checksumAlgorithm.Add(EAWSS3ChecksumAlgorithm::NOT_SET);
                    break;
                case Aws::S3::Model::ChecksumAlgorithm::CRC32:
                    this->checksumAlgorithm.Add(EAWSS3ChecksumAlgorithm::CRC32);
                    break;
                case Aws::S3::Model::ChecksumAlgorithm::CRC32C:
                    this->checksumAlgorithm.Add(EAWSS3ChecksumAlgorithm::CRC32C);
                    break;
                case Aws::S3::Model::ChecksumAlgorithm::SHA1:
                    this->checksumAlgorithm.Add(EAWSS3ChecksumAlgorithm::SHA1);
                    break;
                case Aws::S3::Model::ChecksumAlgorithm::SHA256:
                    this->checksumAlgorithm.Add(EAWSS3ChecksumAlgorithm::SHA256);
                    break;
                default:
                    break;
		    };
        }

        this->size = (int64)awsObject.GetSize();

        switch(awsObject.GetStorageClass()) {
            case Aws::S3::Model::ObjectStorageClass::NOT_SET:
                this->storageClass = EAWSObjectStorageClass::NOT_SET;
                break;
            case Aws::S3::Model::ObjectStorageClass::STANDARD:
                this->storageClass = EAWSObjectStorageClass::STANDARD;
                break;
            case Aws::S3::Model::ObjectStorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSObjectStorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3::Model::ObjectStorageClass::GLACIER:
                this->storageClass = EAWSObjectStorageClass::GLACIER;
                break;
            case Aws::S3::Model::ObjectStorageClass::STANDARD_IA:
                this->storageClass = EAWSObjectStorageClass::STANDARD_IA;
                break;
            case Aws::S3::Model::ObjectStorageClass::ONEZONE_IA:
                this->storageClass = EAWSObjectStorageClass::ONEZONE_IA;
                break;
            case Aws::S3::Model::ObjectStorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSObjectStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3::Model::ObjectStorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSObjectStorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3::Model::ObjectStorageClass::OUTPOSTS:
                this->storageClass = EAWSObjectStorageClass::OUTPOSTS;
                break;
            case Aws::S3::Model::ObjectStorageClass::GLACIER_IR:
                this->storageClass = EAWSObjectStorageClass::GLACIER_IR;
                break;
            default:
                this->storageClass = EAWSObjectStorageClass::NOT_SET;
                break;
        }

        this->owner.fromAWS(awsObject.GetOwner());

        return *this;
    }
#endif
};
