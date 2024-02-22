/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InventoryConfiguration.h"

#endif

#include "Model/InventoryDestination.h"
#include "Model/InventoryFilter.h"
#include "Model/InventoryIncludedObjectVersions.h"
#include "Model/InventoryOptionalField.h"
#include "Model/InventorySchedule.h"

#include "InventoryConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FInventoryConfiguration {
GENERATED_BODY()

    /**
    *  <p>Contains information about where to publish the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInventoryDestination destination;

    /**
    *  <p>Specifies whether the inventory is enabled or disabled. If set to <code>True</code>, an inventory list is generated. If set to <code>False</code>, no inventory list is generated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isEnabled = false;

    /**
    *  <p>Specifies an inventory filter. The inventory only includes objects that meet the filter's criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInventoryFilter filter;

    /**
    *  <p>The ID used to identify the inventory configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>Object versions to include in the inventory list. If set to <code>All</code>, the list includes all the object versions, which adds the version-related fields <code>VersionId</code>, <code>IsLatest</code>, and <code>DeleteMarker</code> to the list. If set to <code>Current</code>, the list does not contain these version-related fields.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSInventoryIncludedObjectVersions includedObjectVersions = EAWSInventoryIncludedObjectVersions::NOT_SET;

    /**
    *  <p>Contains the optional fields that are included in the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<EAWSInventoryOptionalField> optionalFields;

    /**
    *  <p>Specifies the schedule for generating inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInventorySchedule schedule;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InventoryConfiguration toAWS() const {
        Aws::S3::Model::InventoryConfiguration awsInventoryConfiguration;

        if (!(this->destination.IsEmpty())) {
            awsInventoryConfiguration.SetDestination(this->destination.toAWS());
        }

        if (!(false)) {
            awsInventoryConfiguration.SetIsEnabled(this->isEnabled);
        }

        if (!(this->filter.IsEmpty())) {
            awsInventoryConfiguration.SetFilter(this->filter.toAWS());
        }

		if (!(this->id.IsEmpty())) {
            awsInventoryConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        switch(this->includedObjectVersions) {
            case EAWSInventoryIncludedObjectVersions::All:
                awsInventoryConfiguration.SetIncludedObjectVersions(Aws::S3::Model::InventoryIncludedObjectVersions::All);
                break;
            case EAWSInventoryIncludedObjectVersions::Current:
                awsInventoryConfiguration.SetIncludedObjectVersions(Aws::S3::Model::InventoryIncludedObjectVersions::Current);
                break;
            default:
                break;
		}

        for (const EAWSInventoryOptionalField& elem : this->optionalFields) {
		    switch(elem) {
                case EAWSInventoryOptionalField::Size:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::Size);
                        break;
                case EAWSInventoryOptionalField::LastModifiedDate:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::LastModifiedDate);
                        break;
                case EAWSInventoryOptionalField::StorageClass:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::StorageClass);
                        break;
                case EAWSInventoryOptionalField::ETag:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::ETag);
                        break;
                case EAWSInventoryOptionalField::IsMultipartUploaded:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::IsMultipartUploaded);
                        break;
                case EAWSInventoryOptionalField::ReplicationStatus:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::ReplicationStatus);
                        break;
                case EAWSInventoryOptionalField::EncryptionStatus:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::EncryptionStatus);
                        break;
                case EAWSInventoryOptionalField::ObjectLockRetainUntilDate:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::ObjectLockRetainUntilDate);
                        break;
                case EAWSInventoryOptionalField::ObjectLockMode:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::ObjectLockMode);
                        break;
                case EAWSInventoryOptionalField::ObjectLockLegalHoldStatus:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::ObjectLockLegalHoldStatus);
                        break;
                case EAWSInventoryOptionalField::IntelligentTieringAccessTier:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::IntelligentTieringAccessTier);
                        break;
                case EAWSInventoryOptionalField::BucketKeyStatus:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::BucketKeyStatus);
                        break;
                case EAWSInventoryOptionalField::ChecksumAlgorithm:
                        awsInventoryConfiguration.AddOptionalFields(Aws::S3::Model::InventoryOptionalField::ChecksumAlgorithm);
                        break;
                default:
                    break;
            };
        }

        if (!(this->schedule.IsEmpty())) {
            awsInventoryConfiguration.SetSchedule(this->schedule.toAWS());
        }

        return awsInventoryConfiguration;
    }

    bool IsEmpty() const {
        return this->destination.IsEmpty() && false && this->filter.IsEmpty() && this->id.IsEmpty() && includedObjectVersions == EAWSInventoryIncludedObjectVersions::NOT_SET && this->optionalFields.Num() == 0 && this->schedule.IsEmpty();
    }

    FInventoryConfiguration &fromAWS(const Aws::S3::Model::InventoryConfiguration &awsInventoryConfiguration) {
        this->destination.fromAWS(awsInventoryConfiguration.GetDestination());

        this->isEnabled = awsInventoryConfiguration.GetIsEnabled();

        this->filter.fromAWS(awsInventoryConfiguration.GetFilter());

        this->id = UTF8_TO_TCHAR(awsInventoryConfiguration.GetId().c_str());

        switch(awsInventoryConfiguration.GetIncludedObjectVersions()) {
            case Aws::S3::Model::InventoryIncludedObjectVersions::NOT_SET:
                this->includedObjectVersions = EAWSInventoryIncludedObjectVersions::NOT_SET;
                break;
            case Aws::S3::Model::InventoryIncludedObjectVersions::All:
                this->includedObjectVersions = EAWSInventoryIncludedObjectVersions::All;
                break;
            case Aws::S3::Model::InventoryIncludedObjectVersions::Current:
                this->includedObjectVersions = EAWSInventoryIncludedObjectVersions::Current;
                break;
            default:
                this->includedObjectVersions = EAWSInventoryIncludedObjectVersions::NOT_SET;
                break;
        }

        this->optionalFields.Empty();
        for (const Aws::S3::Model::InventoryOptionalField& elem : awsInventoryConfiguration.GetOptionalFields()) {
            switch(elem) {
                case Aws::S3::Model::InventoryOptionalField::NOT_SET:
                    this->optionalFields.Add(EAWSInventoryOptionalField::NOT_SET);
                    break;
                case Aws::S3::Model::InventoryOptionalField::Size:
                    this->optionalFields.Add(EAWSInventoryOptionalField::Size);
                    break;
                case Aws::S3::Model::InventoryOptionalField::LastModifiedDate:
                    this->optionalFields.Add(EAWSInventoryOptionalField::LastModifiedDate);
                    break;
                case Aws::S3::Model::InventoryOptionalField::StorageClass:
                    this->optionalFields.Add(EAWSInventoryOptionalField::StorageClass);
                    break;
                case Aws::S3::Model::InventoryOptionalField::ETag:
                    this->optionalFields.Add(EAWSInventoryOptionalField::ETag);
                    break;
                case Aws::S3::Model::InventoryOptionalField::IsMultipartUploaded:
                    this->optionalFields.Add(EAWSInventoryOptionalField::IsMultipartUploaded);
                    break;
                case Aws::S3::Model::InventoryOptionalField::ReplicationStatus:
                    this->optionalFields.Add(EAWSInventoryOptionalField::ReplicationStatus);
                    break;
                case Aws::S3::Model::InventoryOptionalField::EncryptionStatus:
                    this->optionalFields.Add(EAWSInventoryOptionalField::EncryptionStatus);
                    break;
                case Aws::S3::Model::InventoryOptionalField::ObjectLockRetainUntilDate:
                    this->optionalFields.Add(EAWSInventoryOptionalField::ObjectLockRetainUntilDate);
                    break;
                case Aws::S3::Model::InventoryOptionalField::ObjectLockMode:
                    this->optionalFields.Add(EAWSInventoryOptionalField::ObjectLockMode);
                    break;
                case Aws::S3::Model::InventoryOptionalField::ObjectLockLegalHoldStatus:
                    this->optionalFields.Add(EAWSInventoryOptionalField::ObjectLockLegalHoldStatus);
                    break;
                case Aws::S3::Model::InventoryOptionalField::IntelligentTieringAccessTier:
                    this->optionalFields.Add(EAWSInventoryOptionalField::IntelligentTieringAccessTier);
                    break;
                case Aws::S3::Model::InventoryOptionalField::BucketKeyStatus:
                    this->optionalFields.Add(EAWSInventoryOptionalField::BucketKeyStatus);
                    break;
                case Aws::S3::Model::InventoryOptionalField::ChecksumAlgorithm:
                    this->optionalFields.Add(EAWSInventoryOptionalField::ChecksumAlgorithm);
                    break;
                default:
                    this->optionalFields.Add(EAWSInventoryOptionalField::NOT_SET);
                    break;
		    };
        }

        this->schedule.fromAWS(awsInventoryConfiguration.GetSchedule());

        return *this;
    }
#endif
};
