/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3CopyObjectOperation.h"

#endif

#include "Model/S3CannedAccessControlList.h"
#include "Model/S3Grant.h"
#include "Model/S3MetadataDirective.h"
#include "Model/S3ObjectMetadata.h"
#include "Model/S3ControlS3Tag.h"
#include "Model/AWSS3ControlS3StorageClass.h"
#include "Model/S3ObjectLockLegalHoldStatus.h"
#include "Model/S3ObjectLockMode.h"
#include "Model/AWSS3ControlS3ChecksumAlgorithm.h"

#include "S3CopyObjectOperation.generated.h"

USTRUCT(BlueprintType)
struct FS3CopyObjectOperation {
GENERATED_BODY()

    /**
    *  <p>Specifies the destination bucket ARN for the batch copy operation. For example, to copy objects to a bucket named <code>destinationBucket</code>, set the <code>TargetResource</code> property to <code>arn:aws:s3:::destinationBucket</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString targetResource;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3CannedAccessControlList cannedAccessControlList = EAWSS3CannedAccessControlList::NOT_SET;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3Grant> accessControlGrants;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3MetadataDirective metadataDirective = EAWSS3MetadataDirective::NOT_SET;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime modifiedSinceConstraint;

    /**
    *  <p>If you don't provide this parameter, Amazon S3 copies all the metadata from the original objects. If you specify an empty set, the new objects will have no tags. Otherwise, Amazon S3 assigns the supplied tags to the new objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ObjectMetadata newObjectMetadata;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> newObjectTagging;

    /**
    *  <p>Specifies an optional metadata property for website redirects, <code>x-amz-website-redirect-location</code>. Allows webpage redirects if the object is accessed through a website endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString redirectLocation;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool requesterPays = false;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlS3StorageClass storageClass = EAWSS3ControlS3StorageClass::NOT_SET;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime unModifiedSinceConstraint;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString SSEAwsKmsKeyId;

    /**
    *  <p>Specifies the folder prefix into which you would like the objects to be copied. For example, to copy objects into a folder named <code>Folder1</code> in the destination bucket, set the TargetKeyPrefix to <code>Folder1</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString targetKeyPrefix;

    /**
    *  <p>The legal hold status to be applied to all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ObjectLockLegalHoldStatus objectLockLegalHoldStatus = EAWSS3ObjectLockLegalHoldStatus::NOT_SET;

    /**
    *  <p>The retention mode to be applied to all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ObjectLockMode objectLockMode = EAWSS3ObjectLockMode::NOT_SET;

    /**
    *  <p>The date when the applied object retention configuration expires on all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime objectLockRetainUntilDate;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption with server-side encryption using Amazon Web Services KMS (SSE-KMS). Setting this header to <code>true</code> causes Amazon S3 to use an S3 Bucket Key for object encryption with SSE-KMS.</p> <p>Specifying this header with an <i>object</i> action doesn’t affect <i>bucket-level</i> settings for S3 Bucket Key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool bucketKeyEnabled = false;

    /**
    *  <p>Indicates the algorithm you want Amazon S3 to use to create the checksum. For more information see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/CheckingObjectIntegrity.xml"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3CopyObjectOperation toAWS() const {
        Aws::S3Control::Model::S3CopyObjectOperation awsS3CopyObjectOperation;

		if (!(this->targetResource.IsEmpty())) {
            awsS3CopyObjectOperation.SetTargetResource(TCHAR_TO_UTF8(*this->targetResource));
        }

        switch(this->cannedAccessControlList) {
            case EAWSS3CannedAccessControlList::private_:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::private_);
                break;
            case EAWSS3CannedAccessControlList::public_read:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::public_read);
                break;
            case EAWSS3CannedAccessControlList::public_read_write:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::public_read_write);
                break;
            case EAWSS3CannedAccessControlList::aws_exec_read:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::aws_exec_read);
                break;
            case EAWSS3CannedAccessControlList::authenticated_read:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::authenticated_read);
                break;
            case EAWSS3CannedAccessControlList::bucket_owner_read:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_read);
                break;
            case EAWSS3CannedAccessControlList::bucket_owner_full_control:
                awsS3CopyObjectOperation.SetCannedAccessControlList(Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_full_control);
                break;
            default:
                break;
		}

        for (const FS3Grant& elem : this->accessControlGrants) {
            awsS3CopyObjectOperation.AddAccessControlGrants(elem.toAWS());
        }

        switch(this->metadataDirective) {
            case EAWSS3MetadataDirective::COPY:
                awsS3CopyObjectOperation.SetMetadataDirective(Aws::S3Control::Model::S3MetadataDirective::COPY);
                break;
            case EAWSS3MetadataDirective::REPLACE:
                awsS3CopyObjectOperation.SetMetadataDirective(Aws::S3Control::Model::S3MetadataDirective::REPLACE);
                break;
            default:
                break;
        }

        if (!(this->modifiedSinceConstraint.ToUnixTimestamp() <= 0)) {
            awsS3CopyObjectOperation.SetModifiedSinceConstraint(Aws::Utils::DateTime((int64_t)((this->modifiedSinceConstraint - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->newObjectMetadata.IsEmpty())) {
            awsS3CopyObjectOperation.SetNewObjectMetadata(this->newObjectMetadata.toAWS());
        }

        for (const FS3ControlS3Tag& elem : this->newObjectTagging) {
            awsS3CopyObjectOperation.AddNewObjectTagging(elem.toAWS());
        }

		if (!(this->redirectLocation.IsEmpty())) {
            awsS3CopyObjectOperation.SetRedirectLocation(TCHAR_TO_UTF8(*this->redirectLocation));
        }

        if (!(false)) {
            awsS3CopyObjectOperation.SetRequesterPays(this->requesterPays);
        }

        switch(this->storageClass) {
            case EAWSS3ControlS3StorageClass::STANDARD:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::STANDARD);
                break;
            case EAWSS3ControlS3StorageClass::STANDARD_IA:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::STANDARD_IA);
                break;
            case EAWSS3ControlS3StorageClass::ONEZONE_IA:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::ONEZONE_IA);
                break;
            case EAWSS3ControlS3StorageClass::GLACIER:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::GLACIER);
                break;
            case EAWSS3ControlS3StorageClass::INTELLIGENT_TIERING:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3ControlS3StorageClass::DEEP_ARCHIVE:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3ControlS3StorageClass::GLACIER_IR:
                awsS3CopyObjectOperation.SetStorageClass(Aws::S3Control::Model::S3StorageClass::GLACIER_IR);
                break;
            default:
                break;
        }

        if (!(this->unModifiedSinceConstraint.ToUnixTimestamp() <= 0)) {
            awsS3CopyObjectOperation.SetUnModifiedSinceConstraint(Aws::Utils::DateTime((int64_t)((this->unModifiedSinceConstraint - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

		if (!(this->SSEAwsKmsKeyId.IsEmpty())) {
            awsS3CopyObjectOperation.SetSSEAwsKmsKeyId(TCHAR_TO_UTF8(*this->SSEAwsKmsKeyId));
        }

		if (!(this->targetKeyPrefix.IsEmpty())) {
            awsS3CopyObjectOperation.SetTargetKeyPrefix(TCHAR_TO_UTF8(*this->targetKeyPrefix));
        }

        switch(this->objectLockLegalHoldStatus) {
            case EAWSS3ObjectLockLegalHoldStatus::OFF:
                awsS3CopyObjectOperation.SetObjectLockLegalHoldStatus(Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::OFF);
                break;
            case EAWSS3ObjectLockLegalHoldStatus::ON:
                awsS3CopyObjectOperation.SetObjectLockLegalHoldStatus(Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::ON);
                break;
            default:
                break;
		}

        switch(this->objectLockMode) {
            case EAWSS3ObjectLockMode::COMPLIANCE:
                awsS3CopyObjectOperation.SetObjectLockMode(Aws::S3Control::Model::S3ObjectLockMode::COMPLIANCE);
                break;
            case EAWSS3ObjectLockMode::GOVERNANCE:
                awsS3CopyObjectOperation.SetObjectLockMode(Aws::S3Control::Model::S3ObjectLockMode::GOVERNANCE);
                break;
            default:
                break;
		}

        if (!(this->objectLockRetainUntilDate.ToUnixTimestamp() <= 0)) {
            awsS3CopyObjectOperation.SetObjectLockRetainUntilDate(Aws::Utils::DateTime((int64_t)((this->objectLockRetainUntilDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        awsS3CopyObjectOperation.SetBucketKeyEnabled(this->bucketKeyEnabled);

        switch(this->checksumAlgorithm) {
            case EAWSS3ControlS3ChecksumAlgorithm::CRC32:
                awsS3CopyObjectOperation.SetChecksumAlgorithm(Aws::S3Control::Model::S3ChecksumAlgorithm::CRC32);
                break;
            case EAWSS3ControlS3ChecksumAlgorithm::CRC32C:
                awsS3CopyObjectOperation.SetChecksumAlgorithm(Aws::S3Control::Model::S3ChecksumAlgorithm::CRC32C);
                break;
            case EAWSS3ControlS3ChecksumAlgorithm::SHA1:
                awsS3CopyObjectOperation.SetChecksumAlgorithm(Aws::S3Control::Model::S3ChecksumAlgorithm::SHA1);
                break;
            case EAWSS3ControlS3ChecksumAlgorithm::SHA256:
                awsS3CopyObjectOperation.SetChecksumAlgorithm(Aws::S3Control::Model::S3ChecksumAlgorithm::SHA256);
                break;
            default:
                break;
        }

        return awsS3CopyObjectOperation;
    }

    bool IsEmpty() const {
        return this->targetResource.IsEmpty() && cannedAccessControlList == EAWSS3CannedAccessControlList::NOT_SET && this->accessControlGrants.Num() == 0 && metadataDirective == EAWSS3MetadataDirective::NOT_SET && modifiedSinceConstraint.ToUnixTimestamp() <= 0 && this->newObjectMetadata.IsEmpty() && this->newObjectTagging.Num() == 0 && this->redirectLocation.IsEmpty() && false && storageClass == EAWSS3ControlS3StorageClass::NOT_SET && unModifiedSinceConstraint.ToUnixTimestamp() <= 0 && this->SSEAwsKmsKeyId.IsEmpty() && this->targetKeyPrefix.IsEmpty() && objectLockLegalHoldStatus == EAWSS3ObjectLockLegalHoldStatus::NOT_SET && objectLockMode == EAWSS3ObjectLockMode::NOT_SET && objectLockRetainUntilDate.ToUnixTimestamp() <= 0 && false && this->checksumAlgorithm == EAWSS3ControlS3ChecksumAlgorithm::NOT_SET;
    }

    FS3CopyObjectOperation &fromAWS(const Aws::S3Control::Model::S3CopyObjectOperation &awsS3CopyObjectOperation) {
        this->targetResource = UTF8_TO_TCHAR(awsS3CopyObjectOperation.GetTargetResource().c_str());

        switch(awsS3CopyObjectOperation.GetCannedAccessControlList()) {
            case Aws::S3Control::Model::S3CannedAccessControlList::NOT_SET:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::NOT_SET;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::private_:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::private_;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::public_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::public_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::public_read_write:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::public_read_write;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::aws_exec_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::aws_exec_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::authenticated_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::authenticated_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_read:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::bucket_owner_read;
                break;
            case Aws::S3Control::Model::S3CannedAccessControlList::bucket_owner_full_control:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::bucket_owner_full_control;
                break;
            default:
                this->cannedAccessControlList = EAWSS3CannedAccessControlList::NOT_SET;
                break;
        }

        this->accessControlGrants.Empty();
        for (const Aws::S3Control::Model::S3Grant& elem : awsS3CopyObjectOperation.GetAccessControlGrants()) {
            this->accessControlGrants.Add(FS3Grant().fromAWS(elem));
        }

        switch(awsS3CopyObjectOperation.GetMetadataDirective()) {
            case Aws::S3Control::Model::S3MetadataDirective::NOT_SET:
                this->metadataDirective = EAWSS3MetadataDirective::NOT_SET;
                break;
            case Aws::S3Control::Model::S3MetadataDirective::COPY:
                this->metadataDirective = EAWSS3MetadataDirective::COPY;
                break;
            case Aws::S3Control::Model::S3MetadataDirective::REPLACE:
                this->metadataDirective = EAWSS3MetadataDirective::REPLACE;
                break;
            default:
                this->metadataDirective = EAWSS3MetadataDirective::NOT_SET;
                break;
        }

        this->modifiedSinceConstraint = FDateTime(1970, 1, 1) + FTimespan(awsS3CopyObjectOperation.GetModifiedSinceConstraint().Millis() * ETimespan::TicksPerMillisecond);

        this->newObjectMetadata.fromAWS(awsS3CopyObjectOperation.GetNewObjectMetadata());

        this->newObjectTagging.Empty();
        for (const Aws::S3Control::Model::S3Tag& elem : awsS3CopyObjectOperation.GetNewObjectTagging()) {
            this->newObjectTagging.Add(FS3ControlS3Tag().fromAWS(elem));
        }

        this->redirectLocation = UTF8_TO_TCHAR(awsS3CopyObjectOperation.GetRedirectLocation().c_str());

        this->requesterPays = awsS3CopyObjectOperation.GetRequesterPays();

        switch(awsS3CopyObjectOperation.GetStorageClass()) {
            case Aws::S3Control::Model::S3StorageClass::NOT_SET:
                this->storageClass = EAWSS3ControlS3StorageClass::NOT_SET;
                break;
            case Aws::S3Control::Model::S3StorageClass::STANDARD:
                this->storageClass = EAWSS3ControlS3StorageClass::STANDARD;
                break;
            case Aws::S3Control::Model::S3StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3ControlS3StorageClass::STANDARD_IA;
                break;
            case Aws::S3Control::Model::S3StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3ControlS3StorageClass::ONEZONE_IA;
                break;
            case Aws::S3Control::Model::S3StorageClass::GLACIER:
                this->storageClass = EAWSS3ControlS3StorageClass::GLACIER;
                break;
            case Aws::S3Control::Model::S3StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3ControlS3StorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Control::Model::S3StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3ControlS3StorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3Control::Model::S3StorageClass::GLACIER_IR:
                this->storageClass = EAWSS3ControlS3StorageClass::GLACIER_IR;
                break;
            default:
                this->storageClass = EAWSS3ControlS3StorageClass::NOT_SET;
                break;
        }

        this->unModifiedSinceConstraint = FDateTime(1970, 1, 1) + FTimespan(awsS3CopyObjectOperation.GetUnModifiedSinceConstraint().Millis() * ETimespan::TicksPerMillisecond);

        this->SSEAwsKmsKeyId = UTF8_TO_TCHAR(awsS3CopyObjectOperation.GetSSEAwsKmsKeyId().c_str());

        this->targetKeyPrefix = UTF8_TO_TCHAR(awsS3CopyObjectOperation.GetTargetKeyPrefix().c_str());

        switch(awsS3CopyObjectOperation.GetObjectLockLegalHoldStatus()) {
            case Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::NOT_SET:
                this->objectLockLegalHoldStatus = EAWSS3ObjectLockLegalHoldStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::OFF:
                this->objectLockLegalHoldStatus = EAWSS3ObjectLockLegalHoldStatus::OFF;
                break;
            case Aws::S3Control::Model::S3ObjectLockLegalHoldStatus::ON:
                this->objectLockLegalHoldStatus = EAWSS3ObjectLockLegalHoldStatus::ON;
                break;
            default:
                this->objectLockLegalHoldStatus = EAWSS3ObjectLockLegalHoldStatus::NOT_SET;
                break;
        }

        switch(awsS3CopyObjectOperation.GetObjectLockMode()) {
            case Aws::S3Control::Model::S3ObjectLockMode::NOT_SET:
                this->objectLockMode = EAWSS3ObjectLockMode::NOT_SET;
                break;
            case Aws::S3Control::Model::S3ObjectLockMode::COMPLIANCE:
                this->objectLockMode = EAWSS3ObjectLockMode::COMPLIANCE;
                break;
            case Aws::S3Control::Model::S3ObjectLockMode::GOVERNANCE:
                this->objectLockMode = EAWSS3ObjectLockMode::GOVERNANCE;
                break;
            default:
                this->objectLockMode = EAWSS3ObjectLockMode::NOT_SET;
                break;
        }

        this->objectLockRetainUntilDate = FDateTime(1970, 1, 1) + FTimespan(awsS3CopyObjectOperation.GetObjectLockRetainUntilDate().Millis() * ETimespan::TicksPerMillisecond);

        this->bucketKeyEnabled = awsS3CopyObjectOperation.GetBucketKeyEnabled();

        switch(awsS3CopyObjectOperation.GetChecksumAlgorithm()) {
            case Aws::S3Control::Model::S3ChecksumAlgorithm::NOT_SET:
                this->checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::NOT_SET;
                break;
            case Aws::S3Control::Model::S3ChecksumAlgorithm::CRC32:
                this->checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::CRC32;
                break;
            case Aws::S3Control::Model::S3ChecksumAlgorithm::CRC32C:
                this->checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::CRC32C;
                break;
            case Aws::S3Control::Model::S3ChecksumAlgorithm::SHA1:
                this->checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::SHA1;
                break;
            case Aws::S3Control::Model::S3ChecksumAlgorithm::SHA256:
                this->checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::SHA256;
                break;
            default:
                this->checksumAlgorithm = EAWSS3ControlS3ChecksumAlgorithm::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
