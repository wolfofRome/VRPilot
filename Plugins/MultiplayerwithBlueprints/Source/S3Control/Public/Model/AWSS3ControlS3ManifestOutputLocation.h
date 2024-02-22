/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3ManifestOutputLocation.h"

#endif

#include "Model/AWSS3ControlGeneratedManifestEncryption.h"
#include "Model/AWSS3ControlGeneratedManifestFormat.h"

#include "AWSS3ControlS3ManifestOutputLocation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlS3ManifestOutputLocation {
GENERATED_BODY()

    /**
    *  <p>The Account ID that owns the bucket the generated manifest is written to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString expectedManifestBucketOwner;

    /**
    *  <p>The bucket ARN the generated manifest should be written to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>Prefix identifying one or more objects to which the manifest applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString manifestPrefix;

    /**
    *  <p>Specifies what encryption should be used when the generated manifest objects are written.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlGeneratedManifestEncryption manifestEncryption;

    /**
    *  <p>The format of the generated manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlGeneratedManifestFormat manifestFormat = EAWSS3ControlGeneratedManifestFormat::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3ManifestOutputLocation toAWS() const {
        Aws::S3Control::Model::S3ManifestOutputLocation awsS3ManifestOutputLocation;

		if (!(this->expectedManifestBucketOwner.IsEmpty())) {
            awsS3ManifestOutputLocation.SetExpectedManifestBucketOwner(TCHAR_TO_UTF8(*this->expectedManifestBucketOwner));
        }

		if (!(this->bucket.IsEmpty())) {
            awsS3ManifestOutputLocation.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->manifestPrefix.IsEmpty())) {
            awsS3ManifestOutputLocation.SetManifestPrefix(TCHAR_TO_UTF8(*this->manifestPrefix));
        }

        if (!(this->manifestEncryption.IsEmpty())) {
            awsS3ManifestOutputLocation.SetManifestEncryption(this->manifestEncryption.toAWS());
        }

        switch(this->manifestFormat) {
            case EAWSS3ControlGeneratedManifestFormat::S3InventoryReport_CSV_20211130:
                awsS3ManifestOutputLocation.SetManifestFormat(Aws::S3Control::Model::GeneratedManifestFormat::S3InventoryReport_CSV_20211130);
                break;
            default:
                break;
        }

        return awsS3ManifestOutputLocation;
    }

    bool IsEmpty() const {
        return this->expectedManifestBucketOwner.IsEmpty() && this->bucket.IsEmpty() && this->manifestPrefix.IsEmpty() && this->manifestEncryption.IsEmpty() && this->manifestFormat == EAWSS3ControlGeneratedManifestFormat::NOT_SET;
    }

    FAWSS3ControlS3ManifestOutputLocation &fromAWS(const Aws::S3Control::Model::S3ManifestOutputLocation &awsS3ManifestOutputLocation) {
        this->expectedManifestBucketOwner = UTF8_TO_TCHAR(awsS3ManifestOutputLocation.GetExpectedManifestBucketOwner().c_str());

        this->bucket = UTF8_TO_TCHAR(awsS3ManifestOutputLocation.GetBucket().c_str());

        this->manifestPrefix = UTF8_TO_TCHAR(awsS3ManifestOutputLocation.GetManifestPrefix().c_str());

        this->manifestEncryption.fromAWS(awsS3ManifestOutputLocation.GetManifestEncryption());

        switch(awsS3ManifestOutputLocation.GetManifestFormat()) {
            case Aws::S3Control::Model::GeneratedManifestFormat::NOT_SET:
                this->manifestFormat = EAWSS3ControlGeneratedManifestFormat::NOT_SET;
                break;
            case Aws::S3Control::Model::GeneratedManifestFormat::S3InventoryReport_CSV_20211130:
                this->manifestFormat = EAWSS3ControlGeneratedManifestFormat::S3InventoryReport_CSV_20211130;
                break;
            default:
                this->manifestFormat = EAWSS3ControlGeneratedManifestFormat::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
