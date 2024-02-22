/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/MultipartUpload.h"

#endif

#include "Model/AWSS3StorageClass.h"
#include "Model/Owner.h"
#include "Model/Initiator.h"
#include "Model/AWSS3ChecksumAlgorithm.h"

#include "MultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Upload ID that identifies the multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uploadId;

    /**
    *  <p>Key of the object for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Date and time at which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime initiated;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    *  <p>Specifies the owner of the object that is part of the multipart upload. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

    /**
    *  <p>Identifies who initiated the multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInitiator initiator;

    /**
    *  <p>The algorithm that was used to create a checksum of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FMultipartUpload &fromAWS(const Aws::S3::Model::MultipartUpload &awsMultipartUpload) {
        this->uploadId = UTF8_TO_TCHAR(awsMultipartUpload.GetUploadId().c_str());

        this->key = UTF8_TO_TCHAR(awsMultipartUpload.GetKey().c_str());

        this->initiated = FDateTime(1970, 1, 1) + FTimespan(awsMultipartUpload.GetInitiated().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsMultipartUpload.GetStorageClass()) {
            case Aws::S3::Model::StorageClass::NOT_SET:
                this->storageClass = EAWSS3StorageClass::NOT_SET;
                break;
            case Aws::S3::Model::StorageClass::STANDARD:
                this->storageClass = EAWSS3StorageClass::STANDARD;
                break;
            case Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3StorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3::Model::StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3StorageClass::STANDARD_IA;
                break;
            case Aws::S3::Model::StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3StorageClass::ONEZONE_IA;
                break;
            case Aws::S3::Model::StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3StorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3::Model::StorageClass::GLACIER:
                this->storageClass = EAWSS3StorageClass::GLACIER;
                break;
            case Aws::S3::Model::StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3StorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3::Model::StorageClass::OUTPOSTS:
                this->storageClass = EAWSS3StorageClass::OUTPOSTS;
                break;
            case Aws::S3::Model::StorageClass::GLACIER_IR:
                this->storageClass = EAWSS3StorageClass::GLACIER_IR;
                break;
            default:
                this->storageClass = EAWSS3StorageClass::NOT_SET;
                break;
        }

        this->owner.fromAWS(awsMultipartUpload.GetOwner());

        this->initiator.fromAWS(awsMultipartUpload.GetInitiator());

        switch(awsMultipartUpload.GetChecksumAlgorithm()) {
            case Aws::S3::Model::ChecksumAlgorithm::NOT_SET:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::CRC32:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::CRC32;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::CRC32C:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::CRC32C;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::SHA1:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::SHA1;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::SHA256:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::SHA256;
                break;
            default:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
