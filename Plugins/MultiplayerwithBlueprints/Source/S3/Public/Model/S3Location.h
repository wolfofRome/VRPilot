/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/S3Location.h"

#endif

#include "Model/Encryption.h"
#include "Model/ObjectCannedACL.h"
#include "Model/Grant.h"
#include "Model/Tagging.h"
#include "Model/MetadataEntry.h"
#include "Model/AWSS3StorageClass.h"

#include "S3Location.generated.h"

USTRUCT(BlueprintType)
struct FS3Location {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket where the restore results will be placed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucketName;

    /**
    *  <p>The prefix that is prepended to the restore results for this request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FEncryption encryption;

    /**
    *  <p>The canned ACL to apply to the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSObjectCannedACL cannedACL = EAWSObjectCannedACL::NOT_SET;

    /**
    *  <p>A list of grants that control access to the staged results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FGrant> accessControlList;

    /**
    *  <p>The tag-set that is applied to the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FTagging tagging;

    /**
    *  <p>A list of metadata to store with the restore results in S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FMetadataEntry> userMetadata;

    /**
    *  <p>The class of storage used to store the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::S3Location toAWS() const {
        Aws::S3::Model::S3Location awsS3Location;

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
            case EAWSObjectCannedACL::private_:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::private_);
                break;
            case EAWSObjectCannedACL::public_read:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::public_read);
                break;
            case EAWSObjectCannedACL::public_read_write:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSObjectCannedACL::authenticated_read:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSObjectCannedACL::aws_exec_read:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_read:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSObjectCannedACL::bucket_owner_full_control:
                awsS3Location.SetCannedACL(Aws::S3::Model::ObjectCannedACL::bucket_owner_full_control);
                break;
            default:
                break;
        }

        for (const FGrant& elem : this->accessControlList) {
            awsS3Location.AddAccessControlList(elem.toAWS());
        }

        if (!(this->tagging.IsEmpty())) {
            awsS3Location.SetTagging(this->tagging.toAWS());
        }

        for (const FMetadataEntry& elem : this->userMetadata) {
            awsS3Location.AddUserMetadata(elem.toAWS());
        }

        switch(this->storageClass) {
            case EAWSS3StorageClass::STANDARD:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD);
                break;
            case EAWSS3StorageClass::REDUCED_REDUNDANCY:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3StorageClass::STANDARD_IA:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3StorageClass::ONEZONE_IA:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3StorageClass::INTELLIGENT_TIERING:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3StorageClass::GLACIER:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER);
                break;
            case EAWSS3StorageClass::DEEP_ARCHIVE:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3StorageClass::OUTPOSTS:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::OUTPOSTS);
                break;
            case EAWSS3StorageClass::GLACIER_IR:
                awsS3Location.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER_IR);
                break;
            default:
                break;
        }

        return awsS3Location;
    }

    bool IsEmpty() const {
        return this->bucketName.IsEmpty() && this->prefix.IsEmpty() && this->encryption.IsEmpty() && cannedACL == EAWSObjectCannedACL::NOT_SET && this->accessControlList.Num() == 0 && this->tagging.IsEmpty() && this->userMetadata.Num() == 0 && storageClass == EAWSS3StorageClass::NOT_SET;
    }
#endif
};
