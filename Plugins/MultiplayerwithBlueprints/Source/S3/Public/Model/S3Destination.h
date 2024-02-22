/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Destination.h"

#endif

#include "Model/AWSS3StorageClass.h"
#include "Model/AccessControlTranslation.h"
#include "Model/EncryptionConfiguration.h"
#include "Model/ReplicationTime.h"
#include "Model/Metrics.h"

#include "S3Destination.generated.h"

USTRUCT(BlueprintType)
struct FS3Destination {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (ARN) of the bucket where you want Amazon S3 to store the results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Destination bucket owner account ID. In a cross-account scenario, if you direct Amazon S3 to change replica ownership to the AWS account that owns the destination bucket by specifying the <code>AccessControlTranslation</code> property, this is the account ID of the destination bucket owner. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/replication-change-owner.html">Replication Additional Configuration: Changing the Replica Owner</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString account;

    /**
    *  <p> The storage class to use when replicating objects, such as S3 Standard or reduced redundancy. By default, Amazon S3 uses the storage class of the source object to create the object replica. </p> <p>For valid values, see the <code>StorageClass</code> element of the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/RESTBucketPUTreplication.html">PUT Bucket replication</a> action in the <i>Amazon Simple Storage Service API Reference</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    *  <p>Specify this only in a cross-account scenario (where source and destination bucket owners are not the same), and you want to change replica ownership to the AWS account that owns the destination bucket. If this is not specified in the replication configuration, the replicas are owned by same AWS account that owns the source object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAccessControlTranslation accessControlTranslation;

    /**
    *  <p>A container that provides information about encryption. If <code>SourceSelectionCriteria</code> is specified, you must specify this element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FEncryptionConfiguration encryptionConfiguration;

    /**
    *  <p> A container specifying S3 Replication Time Control (S3 RTC), including whether S3 RTC is enabled and the time when all objects and operations on objects must be replicated. Must be specified together with a <code>Metrics</code> block. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FReplicationTime replicationTime;

    /**
    *  <p> A container specifying replication metrics-related settings enabling metrics and Amazon S3 events for S3 Replication Time Control (S3 RTC). Must be specified together with a <code>ReplicationTime</code> block. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FMetrics metrics;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Destination toAWS() const {
        Aws::S3::Model::Destination awsDestination;

		if (!(this->bucket.IsEmpty())) {
            awsDestination.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->account.IsEmpty())) {
            awsDestination.SetAccount(TCHAR_TO_UTF8(*this->account));
        }

        switch(this->storageClass) {
            case EAWSS3StorageClass::STANDARD:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD);
                break;
            case EAWSS3StorageClass::REDUCED_REDUNDANCY:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY);
                break;
            case EAWSS3StorageClass::STANDARD_IA:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::STANDARD_IA);
                break;
            case EAWSS3StorageClass::ONEZONE_IA:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::ONEZONE_IA);
                break;
            case EAWSS3StorageClass::INTELLIGENT_TIERING:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3StorageClass::GLACIER:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER);
                break;
            case EAWSS3StorageClass::DEEP_ARCHIVE:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::DEEP_ARCHIVE);
                break;
            case EAWSS3StorageClass::OUTPOSTS:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::OUTPOSTS);
                break;
            case EAWSS3StorageClass::GLACIER_IR:
                awsDestination.SetStorageClass(Aws::S3::Model::StorageClass::GLACIER_IR);
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
        return this->bucket.IsEmpty() && this->account.IsEmpty() && storageClass == EAWSS3StorageClass::NOT_SET && this->accessControlTranslation.IsEmpty() && this->encryptionConfiguration.IsEmpty() && this->replicationTime.IsEmpty() && this->metrics.IsEmpty();
    }

    FS3Destination &fromAWS(const Aws::S3::Model::Destination &awsDestination) {
        this->bucket = UTF8_TO_TCHAR(awsDestination.GetBucket().c_str());

        this->account = UTF8_TO_TCHAR(awsDestination.GetAccount().c_str());

        switch(awsDestination.GetStorageClass()) {
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

        this->accessControlTranslation.fromAWS(awsDestination.GetAccessControlTranslation());

        this->encryptionConfiguration.fromAWS(awsDestination.GetEncryptionConfiguration());

        this->replicationTime.fromAWS(awsDestination.GetReplicationTime());

        this->metrics.fromAWS(awsDestination.GetMetrics());

        return *this;
    }
#endif
};
