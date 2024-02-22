/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InventoryConfiguration.h"

#endif

#include "Model/AWSS3CRTInventoryDestination.h"
#include "Model/AWSS3CRTInventoryFilter.h"
#include "Model/AWSS3CRTInventoryIncludedObjectVersions.h"
#include "Model/AWSS3CRTInventoryOptionalField.h"
#include "Model/AWSS3CRTInventorySchedule.h"

#include "AWSS3CRTInventoryConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInventoryConfiguration {
GENERATED_BODY()

    /**
    *  <p>Contains information about where to publish the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInventoryDestination destination;

    /**
    *  <p>Specifies whether the inventory is enabled or disabled. If set to <code>True</code>, an inventory list is generated. If set to <code>False</code>, no inventory list is generated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isEnabled = false;

    /**
    *  <p>Specifies an inventory filter. The inventory only includes objects that meet the filter's criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInventoryFilter filter;

    /**
    *  <p>The ID used to identify the inventory configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>Object versions to include in the inventory list. If set to <code>All</code>, the list includes all the object versions, which adds the version-related fields <code>VersionId</code>, <code>IsLatest</code>, and <code>DeleteMarker</code> to the list. If set to <code>Current</code>, the list does not contain these version-related fields.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTInventoryIncludedObjectVersions includedObjectVersions = EAWSS3CRTInventoryIncludedObjectVersions::NOT_SET;

    /**
    *  <p>Contains the optional fields that are included in the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<EAWSS3CRTInventoryOptionalField> optionalFields;

    /**
    *  <p>Specifies the schedule for generating inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInventorySchedule schedule;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InventoryConfiguration toAWS() const {
        Aws::S3Crt::Model::InventoryConfiguration awsInventoryConfiguration;

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
            case EAWSS3CRTInventoryIncludedObjectVersions::All:
                awsInventoryConfiguration.SetIncludedObjectVersions(Aws::S3Crt::Model::InventoryIncludedObjectVersions::All);
                break;
            case EAWSS3CRTInventoryIncludedObjectVersions::Current:
                awsInventoryConfiguration.SetIncludedObjectVersions(Aws::S3Crt::Model::InventoryIncludedObjectVersions::Current);
                break;
            default:
                break;
        }

        for (const EAWSS3CRTInventoryOptionalField& elem : this->optionalFields) {
		    switch(elem) {
                case EAWSS3CRTInventoryOptionalField::Size:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::Size);
                    break;
                case EAWSS3CRTInventoryOptionalField::LastModifiedDate:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::LastModifiedDate);
                    break;
                case EAWSS3CRTInventoryOptionalField::StorageClass:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::StorageClass);
                    break;
                case EAWSS3CRTInventoryOptionalField::ETag:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::ETag);
                    break;
                case EAWSS3CRTInventoryOptionalField::IsMultipartUploaded:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::IsMultipartUploaded);
                    break;
                case EAWSS3CRTInventoryOptionalField::ReplicationStatus:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::ReplicationStatus);
                    break;
                case EAWSS3CRTInventoryOptionalField::EncryptionStatus:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::EncryptionStatus);
                    break;
                case EAWSS3CRTInventoryOptionalField::ObjectLockRetainUntilDate:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::ObjectLockRetainUntilDate);
                    break;
                case EAWSS3CRTInventoryOptionalField::ObjectLockMode:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::ObjectLockMode);
                    break;
                case EAWSS3CRTInventoryOptionalField::ObjectLockLegalHoldStatus:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::ObjectLockLegalHoldStatus);
                    break;
                case EAWSS3CRTInventoryOptionalField::IntelligentTieringAccessTier:
                    awsInventoryConfiguration.AddOptionalFields(Aws::S3Crt::Model::InventoryOptionalField::IntelligentTieringAccessTier);
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
        return this->destination.IsEmpty() && false && this->filter.IsEmpty() && this->id.IsEmpty() && this->includedObjectVersions == EAWSS3CRTInventoryIncludedObjectVersions::NOT_SET && this->optionalFields.Num() == 0 && this->schedule.IsEmpty();
    }

    FAWSS3CRTInventoryConfiguration &fromAWS(const Aws::S3Crt::Model::InventoryConfiguration &awsInventoryConfiguration) {
        this->destination = FAWSS3CRTInventoryDestination().fromAWS(awsInventoryConfiguration.GetDestination());

        this->isEnabled = awsInventoryConfiguration.GetIsEnabled();

        this->filter = FAWSS3CRTInventoryFilter().fromAWS(awsInventoryConfiguration.GetFilter());

        this->id = UTF8_TO_TCHAR(awsInventoryConfiguration.GetId().c_str());

        switch(awsInventoryConfiguration.GetIncludedObjectVersions()) {
            case Aws::S3Crt::Model::InventoryIncludedObjectVersions::NOT_SET:
                this->includedObjectVersions = EAWSS3CRTInventoryIncludedObjectVersions::NOT_SET;
                break;
            case Aws::S3Crt::Model::InventoryIncludedObjectVersions::All:
                this->includedObjectVersions = EAWSS3CRTInventoryIncludedObjectVersions::All;
                break;
            case Aws::S3Crt::Model::InventoryIncludedObjectVersions::Current:
                this->includedObjectVersions = EAWSS3CRTInventoryIncludedObjectVersions::Current;
                break;
            default:
                this->includedObjectVersions = EAWSS3CRTInventoryIncludedObjectVersions::NOT_SET;
                break;
        }

        this->optionalFields.Empty();
        for (const Aws::S3Crt::Model::InventoryOptionalField& elem : awsInventoryConfiguration.GetOptionalFields()) {
            switch(elem) {
                case Aws::S3Crt::Model::InventoryOptionalField::NOT_SET:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::NOT_SET);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::Size:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::Size);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::LastModifiedDate:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::LastModifiedDate);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::StorageClass:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::StorageClass);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::ETag:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::ETag);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::IsMultipartUploaded:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::IsMultipartUploaded);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::ReplicationStatus:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::ReplicationStatus);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::EncryptionStatus:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::EncryptionStatus);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::ObjectLockRetainUntilDate:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::ObjectLockRetainUntilDate);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::ObjectLockMode:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::ObjectLockMode);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::ObjectLockLegalHoldStatus:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::ObjectLockLegalHoldStatus);
                    break;
                case Aws::S3Crt::Model::InventoryOptionalField::IntelligentTieringAccessTier:
                    this->optionalFields.Add(EAWSS3CRTInventoryOptionalField::IntelligentTieringAccessTier);
                    break;
                default:
                    break;
		    };
        }

        this->schedule = FAWSS3CRTInventorySchedule().fromAWS(awsInventoryConfiguration.GetSchedule());

        return *this;
    }
#endif
};
