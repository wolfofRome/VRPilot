/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InventoryS3BucketDestination.h"

#endif

#include "Model/AWSS3CRTInventoryFormat.h"
#include "Model/AWSS3CRTInventoryEncryption.h"

#include "AWSS3CRTInventoryS3BucketDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInventoryS3BucketDestination {
GENERATED_BODY()

    /**
    *  <p>The account ID that owns the destination S3 bucket. If no account ID is provided, the owner is not validated before exporting data. </p>  <p> Although this value is optional, we strongly recommend that you set it to help prevent problems if the destination bucket ownership changes. </p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString accountId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the bucket where inventory results will be published.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Specifies the output format of the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTInventoryFormat format = EAWSS3CRTInventoryFormat::NOT_SET;

    /**
    *  <p>The prefix that is prepended to all inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>Contains the type of server-side encryption used to encrypt the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInventoryEncryption encryption;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InventoryS3BucketDestination toAWS() const {
        Aws::S3Crt::Model::InventoryS3BucketDestination awsInventoryS3BucketDestination;

        if (!(this->accountId.IsEmpty())) {
            awsInventoryS3BucketDestination.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->bucket.IsEmpty())) {
            awsInventoryS3BucketDestination.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        switch(this->format) {
            case EAWSS3CRTInventoryFormat::CSV:
                awsInventoryS3BucketDestination.SetFormat(Aws::S3Crt::Model::InventoryFormat::CSV);
                break;
            case EAWSS3CRTInventoryFormat::ORC:
                awsInventoryS3BucketDestination.SetFormat(Aws::S3Crt::Model::InventoryFormat::ORC);
                break;
            case EAWSS3CRTInventoryFormat::Parquet:
                awsInventoryS3BucketDestination.SetFormat(Aws::S3Crt::Model::InventoryFormat::Parquet);
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
        return this->accountId.IsEmpty() && this->bucket.IsEmpty() && this->format == EAWSS3CRTInventoryFormat::NOT_SET && this->prefix.IsEmpty() && this->encryption.IsEmpty();
    }

    FAWSS3CRTInventoryS3BucketDestination &fromAWS(const Aws::S3Crt::Model::InventoryS3BucketDestination &awsInventoryS3BucketDestination) {
        this->accountId = UTF8_TO_TCHAR(awsInventoryS3BucketDestination.GetAccountId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsInventoryS3BucketDestination.GetBucket().c_str());

        switch(awsInventoryS3BucketDestination.GetFormat()) {
            case Aws::S3Crt::Model::InventoryFormat::NOT_SET:
                this->format = EAWSS3CRTInventoryFormat::NOT_SET;
                break;
            case Aws::S3Crt::Model::InventoryFormat::CSV:
                this->format = EAWSS3CRTInventoryFormat::CSV;
                break;
            case Aws::S3Crt::Model::InventoryFormat::ORC:
                this->format = EAWSS3CRTInventoryFormat::ORC;
                break;
            case Aws::S3Crt::Model::InventoryFormat::Parquet:
                this->format = EAWSS3CRTInventoryFormat::Parquet;
                break;
            default:
                this->format = EAWSS3CRTInventoryFormat::NOT_SET;
                break;
        }

        this->prefix = UTF8_TO_TCHAR(awsInventoryS3BucketDestination.GetPrefix().c_str());

        this->encryption = FAWSS3CRTInventoryEncryption().fromAWS(awsInventoryS3BucketDestination.GetEncryption());

        return *this;
    }
#endif
};
