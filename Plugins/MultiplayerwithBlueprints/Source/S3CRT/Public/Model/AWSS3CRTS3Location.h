/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/S3Location.h"

#endif

#include "Model/AWSS3CRTEncryption.h"
#include "Model/AWSS3CRTObjectCannedACL.h"
#include "Model/AWSS3CRTGrant.h"
#include "Model/AWSS3CRTTagging.h"
#include "Model/AWSS3CRTMetadataEntry.h"
#include "Model/AWSS3CRTStorageClass.h"

#include "AWSS3CRTS3Location.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTS3Location {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket where the restore results will be placed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucketName;

    /**
    *  <p>The prefix that is prepended to the restore results for this request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTEncryption encryption;

    /**
    *  <p>The canned ACL to apply to the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectCannedACL cannedACL = EAWSS3CRTObjectCannedACL::NOT_SET;

    /**
    *  <p>A list of grants that control access to the staged results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTGrant> accessControlList;

    /**
    *  <p>The tag-set that is applied to the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTagging tagging;

    /**
    *  <p>A list of metadata to store with the restore results in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTMetadataEntry> userMetadata;

    /**
    *  <p>The class of storage used to store the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::S3Location toAWS() const {
        Aws::S3Crt::Model::S3Location awsS3Location;

        if (!(this->bucketName.IsEmpty())) {
            awsS3Location.SetBucketName(TCHAR_TO_UTF8(*this->bucketName));
        }

        if (!(this->prefix.IsEmpty())) {
            awsS3Location.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->encryption.IsEmpty())) {
            awsS3Location.SetEncryption(this->encryption.toAWS());
        }

        switch(this->cannedACL) {
            case EAWSS3CRTObjectCannedACL::private_:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::private_);
                break;
            case EAWSS3CRTObjectCannedACL::public_read:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::public_read);
                break;
            case EAWSS3CRTObjectCannedACL::public_read_write:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSS3CRTObjectCannedACL::authenticated_read:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSS3CRTObjectCannedACL::aws_exec_read:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_read:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_full_control:
                awsS3Location.SetCannedACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_full_control);
                break;
            default:
                break;
        }

        for (const FAWSS3CRTGrant& elem : this->accessControlList) {
            awsS3Location.AddAccessControlList(elem.toAWS());
        }

        if (!(this->tagging.IsEmpty())) {
            awsS3Location.SetTagging(this->tagging.toAWS());
        }

        for (const FAWSS3CRTMetadataEntry& elem : this->userMetadata) {
            awsS3Location.AddUserMetadata(elem.toAWS());
        }

        switch(this->storageClass) {
            case EAWSS3CRTStorageClass::STANDARD:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD);
                break;
            case EAWSS3CRTStorageClass::REDUCED_REDUNDANCY:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3CRTStorageClass::STANDARD_IA:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTStorageClass::ONEZONE_IA:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTStorageClass::INTELLIGENT_TIERING:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTStorageClass::GLACIER:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::GLACIER);
                break;
            case EAWSS3CRTStorageClass::DEEP_ARCHIVE:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3CRTStorageClass::OUTPOSTS:
                awsS3Location.SetStorageClass(Aws::S3Crt::Model::StorageClass::OUTPOSTS);
                break;
            default:
                break;
        }

        return awsS3Location;
    }

    bool IsEmpty() const {
        return this->bucketName.IsEmpty() && this->prefix.IsEmpty() && this->encryption.IsEmpty() && this->cannedACL == EAWSS3CRTObjectCannedACL::NOT_SET && this->accessControlList.Num() == 0 && this->tagging.IsEmpty() && this->userMetadata.Num() == 0 && this->storageClass == EAWSS3CRTStorageClass::NOT_SET;
    }
#endif
};
