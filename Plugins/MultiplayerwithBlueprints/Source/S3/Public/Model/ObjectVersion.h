/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ObjectVersion.h"

#endif

#include "Model/AWSS3ChecksumAlgorithm.h"
#include "Model/ObjectVersionStorageClass.h"
#include "Model/Owner.h"

#include "ObjectVersion.generated.h"

USTRUCT(BlueprintType)
struct FObjectVersion {
GENERATED_BODY()

    /**
    *  <p>The entity tag is an MD5 hash of that version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

    /**
    *  <p>The algorithm that was used to create a checksum of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<EAWSS3ChecksumAlgorithm> checksumAlgorithm;

    /**
    *  <p>Size in bytes of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 size = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectVersionStorageClass storageClass = EAWSObjectVersionStorageClass::NOT_SET;

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

    /**
    *  <p>Specifies the owner of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FObjectVersion &fromAWS(const Aws::S3::Model::ObjectVersion &awsObjectVersion) {
        this->eTag = UTF8_TO_TCHAR(awsObjectVersion.GetETag().c_str());

        this->checksumAlgorithm.Empty();
        for (const Aws::S3::Model::ChecksumAlgorithm& elem : awsObjectVersion.GetChecksumAlgorithm()) {
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

        this->size = (int64)awsObjectVersion.GetSize();

        switch(awsObjectVersion.GetStorageClass()) {
            case Aws::S3::Model::ObjectVersionStorageClass::NOT_SET:
                this->storageClass = EAWSObjectVersionStorageClass::NOT_SET;
                break;
            case Aws::S3::Model::ObjectVersionStorageClass::STANDARD:
                this->storageClass = EAWSObjectVersionStorageClass::STANDARD;
                break;
            default:
                this->storageClass = EAWSObjectVersionStorageClass::NOT_SET;
                break;
        }

        this->key = UTF8_TO_TCHAR(awsObjectVersion.GetKey().c_str());

        this->versionId = UTF8_TO_TCHAR(awsObjectVersion.GetVersionId().c_str());

        this->isLatest = awsObjectVersion.GetIsLatest();

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsObjectVersion.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->owner.fromAWS(awsObjectVersion.GetOwner());

        return *this;
    }
#endif
};
