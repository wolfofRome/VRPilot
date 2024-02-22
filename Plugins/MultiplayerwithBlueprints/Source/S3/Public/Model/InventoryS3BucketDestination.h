/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InventoryS3BucketDestination.h"

#endif

#include "Model/InventoryFormat.h"
#include "Model/InventoryEncryption.h"

#include "InventoryS3BucketDestination.generated.h"

USTRUCT(BlueprintType)
struct FInventoryS3BucketDestination {
GENERATED_BODY()

    /**
    *  <p>The account ID that owns the destination S3 bucket. If no account ID is provided, the owner is not validated before exporting data. </p>  <p> Although this value is optional, we strongly recommend that you set it to help prevent problems if the destination bucket ownership changes. </p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString accountId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the bucket where inventory results will be published.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Specifies the output format of the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSInventoryFormat format = EAWSInventoryFormat::NOT_SET;

    /**
    *  <p>The prefix that is prepended to all inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>Contains the type of server-side encryption used to encrypt the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInventoryEncryption encryption;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InventoryS3BucketDestination toAWS() const {
        Aws::S3::Model::InventoryS3BucketDestination awsInventoryS3BucketDestination;

		if (!(this->accountId.IsEmpty())) {
            awsInventoryS3BucketDestination.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->bucket.IsEmpty())) {
            awsInventoryS3BucketDestination.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        switch(this->format) {
            case EAWSInventoryFormat::CSV:
                awsInventoryS3BucketDestination.SetFormat(Aws::S3::Model::InventoryFormat::CSV);
                break;
            case EAWSInventoryFormat::ORC:
                awsInventoryS3BucketDestination.SetFormat(Aws::S3::Model::InventoryFormat::ORC);
                break;
            case EAWSInventoryFormat::Parquet:
                awsInventoryS3BucketDestination.SetFormat(Aws::S3::Model::InventoryFormat::Parquet);
                break;
            default:
                break;
		}

		if (!(this->prefix.IsEmpty())) {
            awsInventoryS3BucketDestination.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->encryption.IsEmpty())) {
            awsInventoryS3BucketDestination.SetEncryption(this->encryption.toAWS());
        }

        return awsInventoryS3BucketDestination;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->bucket.IsEmpty() && format == EAWSInventoryFormat::NOT_SET && this->prefix.IsEmpty() && this->encryption.IsEmpty();
    }

    FInventoryS3BucketDestination &fromAWS(const Aws::S3::Model::InventoryS3BucketDestination &awsInventoryS3BucketDestination) {
        this->accountId = UTF8_TO_TCHAR(awsInventoryS3BucketDestination.GetAccountId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsInventoryS3BucketDestination.GetBucket().c_str());

        switch(awsInventoryS3BucketDestination.GetFormat()) {
            case Aws::S3::Model::InventoryFormat::NOT_SET:
                this->format = EAWSInventoryFormat::NOT_SET;
                break;
            case Aws::S3::Model::InventoryFormat::CSV:
                this->format = EAWSInventoryFormat::CSV;
                break;
            case Aws::S3::Model::InventoryFormat::ORC:
                this->format = EAWSInventoryFormat::ORC;
                break;
            case Aws::S3::Model::InventoryFormat::Parquet:
                this->format = EAWSInventoryFormat::Parquet;
                break;
            default:
                this->format = EAWSInventoryFormat::NOT_SET;
                break;
        }

        this->prefix = UTF8_TO_TCHAR(awsInventoryS3BucketDestination.GetPrefix().c_str());

        this->encryption.fromAWS(awsInventoryS3BucketDestination.GetEncryption());

        return *this;
    }
#endif
};
