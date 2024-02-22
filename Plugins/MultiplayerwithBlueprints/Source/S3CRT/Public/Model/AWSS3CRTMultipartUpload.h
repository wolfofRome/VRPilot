/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/MultipartUpload.h"

#endif

#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTOwner.h"
#include "Model/AWSS3CRTInitiator.h"

#include "AWSS3CRTMultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Upload ID that identifies the multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uploadId;

    /**
    *  <p>Key of the object for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Date and time at which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime initiated;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    *  <p>Specifies the owner of the object that is part of the multipart upload. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

    /**
    *  <p>Identifies who initiated the multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInitiator initiator;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTMultipartUpload &fromAWS(const Aws::S3Crt::Model::MultipartUpload &awsMultipartUpload) {
        this->uploadId = UTF8_TO_TCHAR(awsMultipartUpload.GetUploadId().c_str());

        this->key = UTF8_TO_TCHAR(awsMultipartUpload.GetKey().c_str());

        this->initiated = FDateTime(1970, 1, 1) + FTimespan(awsMultipartUpload.GetInitiated().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsMultipartUpload.GetStorageClass()) {
            case Aws::S3Crt::Model::StorageClass::NOT_SET:
                this->storageClass = EAWSS3CRTStorageClass::NOT_SET;
                break;
            case Aws::S3Crt::Model::StorageClass::STANDARD:
                this->storageClass = EAWSS3CRTStorageClass::STANDARD;
                break;
            case Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3CRTStorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3Crt::Model::StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3CRTStorageClass::STANDARD_IA;
                break;
            case Aws::S3Crt::Model::StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3CRTStorageClass::ONEZONE_IA;
                break;
            case Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3CRTStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Crt::Model::StorageClass::GLACIER:
                this->storageClass = EAWSS3CRTStorageClass::GLACIER;
                break;
            case Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3CRTStorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3Crt::Model::StorageClass::OUTPOSTS:
                this->storageClass = EAWSS3CRTStorageClass::OUTPOSTS;
                break;
            default:
                this->storageClass = EAWSS3CRTStorageClass::NOT_SET;
                break;
        }

        this->owner = FAWSS3CRTOwner().fromAWS(awsMultipartUpload.GetOwner());

        this->initiator = FAWSS3CRTInitiator().fromAWS(awsMultipartUpload.GetInitiator());

        return *this;
    }
#endif
};
