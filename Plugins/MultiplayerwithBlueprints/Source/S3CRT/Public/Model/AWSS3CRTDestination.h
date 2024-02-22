/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Destination.h"

#endif

#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTAccessControlTranslation.h"
#include "Model/AWSS3CRTEncryptionConfiguration.h"
#include "Model/AWSS3CRTReplicationTime.h"
#include "Model/AWSS3CRTMetrics.h"

#include "AWSS3CRTDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDestination {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (ARN) of the bucket where you want Amazon S3 to store the results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Destination bucket owner account ID. In a cross-account scenario, if you direct Amazon S3 to change replica ownership to the AWS account that owns the destination bucket by specifying the <code>AccessControlTranslation</code> property, this is the account ID of the destination bucket owner. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/replication-change-owner.html">Replication Additional Configuration: Changing the Replica Owner</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString account;

    /**
    *  <p> The storage class to use when replicating objects, such as S3 Standard or reduced redundancy. By default, Amazon S3 uses the storage class of the source object to create the object replica. </p> <p>For valid values, see the <code>StorageClass</code> element of the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/RESTBucketPUTreplication.html">PUT Bucket replication</a> action in the <i>Amazon Simple Storage Service API Reference</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    *  <p>Specify this only in a cross-account scenario (where source and destination bucket owners are not the same), and you want to change replica ownership to the AWS account that owns the destination bucket. If this is not specified in the replication configuration, the replicas are owned by same AWS account that owns the source object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAccessControlTranslation accessControlTranslation;

    /**
    *  <p>A container that provides information about encryption. If <code>SourceSelectionCriteria</code> is specified, you must specify this element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTEncryptionConfiguration encryptionConfiguration;

    /**
    *  <p> A container specifying S3 Replication Time Control (S3 RTC), including whether S3 RTC is enabled and the time when all objects and operations on objects must be replicated. Must be specified together with a <code>Metrics</code> block. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTReplicationTime replicationTime;

    /**
    *  <p> A container specifying replication metrics-related settings enabling replication metrics and events. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTMetrics metrics;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Destination toAWS() const {
        Aws::S3Crt::Model::Destination awsDestination;

        if (!(this->bucket.IsEmpty())) {
            awsDestination.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->account.IsEmpty())) {
            awsDestination.SetAccount(TCHAR_TO_UTF8(*this->account));
        }

        switch(this->storageClass) {
            case EAWSS3CRTStorageClass::STANDARD:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD);
                break;
            case EAWSS3CRTStorageClass::REDUCED_REDUNDANCY:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3CRTStorageClass::STANDARD_IA:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTStorageClass::ONEZONE_IA:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTStorageClass::INTELLIGENT_TIERING:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTStorageClass::GLACIER:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::GLACIER);
                break;
            case EAWSS3CRTStorageClass::DEEP_ARCHIVE:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3CRTStorageClass::OUTPOSTS:
                awsDestination.SetStorageClass(Aws::S3Crt::Model::StorageClass::OUTPOSTS);
                break;
            default:
                break;
        }

        if (!(this->accessControlTranslation.IsEmpty())) {
            awsDestination.SetAccessControlTranslation(this->accessControlTranslation.toAWS());
        }

        if (!(this->encryptionConfiguration.IsEmpty())) {
            awsDestination.SetEncryptionConfiguration(this->encryptionConfiguration.toAWS());
        }

        if (!(this->replicationTime.IsEmpty())) {
            awsDestination.SetReplicationTime(this->replicationTime.toAWS());
        }

        if (!(this->metrics.IsEmpty())) {
            awsDestination.SetMetrics(this->metrics.toAWS());
        }

        return awsDestination;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->account.IsEmpty() && this->storageClass == EAWSS3CRTStorageClass::NOT_SET && this->accessControlTranslation.IsEmpty() && this->encryptionConfiguration.IsEmpty() && this->replicationTime.IsEmpty() && this->metrics.IsEmpty();
    }

    FAWSS3CRTDestination &fromAWS(const Aws::S3Crt::Model::Destination &awsDestination) {
        this->bucket = UTF8_TO_TCHAR(awsDestination.GetBucket().c_str());

        this->account = UTF8_TO_TCHAR(awsDestination.GetAccount().c_str());

        switch(awsDestination.GetStorageClass()) {
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

        this->accessControlTranslation = FAWSS3CRTAccessControlTranslation().fromAWS(awsDestination.GetAccessControlTranslation());

        this->encryptionConfiguration = FAWSS3CRTEncryptionConfiguration().fromAWS(awsDestination.GetEncryptionConfiguration());

        this->replicationTime = FAWSS3CRTReplicationTime().fromAWS(awsDestination.GetReplicationTime());

        this->metrics = FAWSS3CRTMetrics().fromAWS(awsDestination.GetMetrics());

        return *this;
    }
#endif
};
