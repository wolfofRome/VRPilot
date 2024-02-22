/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3BucketDestination.h"

#endif

#include "Model/AWSS3ControlFormat.h"
#include "Model/AWSS3ControlOutputSchemaVersion.h"
#include "Model/AWSS3ControlStorageLensDataExportEncryption.h"

#include "AWSS3ControlS3BucketDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlS3BucketDestination {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlFormat format = EAWSS3ControlFormat::NOT_SET;

    /**
    *  <p>The schema version of the export file.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlOutputSchemaVersion outputSchemaVersion = EAWSS3ControlOutputSchemaVersion::NOT_SET;

    /**
    *  <p>The account ID of the owner of the S3 Storage Lens metrics export bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the bucket. This property is read-only and follows the following format: <code> arn:aws:s3:<i>us-east-1</i>:<i>example-account-id</i>:bucket/<i>your-destination-bucket-name</i> </code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString arn;

    /**
    *  <p>The prefix of the destination bucket where the metrics export will be delivered.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString prefix;

    /**
    *  <p>The container for the type encryption of the metrics exports in this bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlStorageLensDataExportEncryption encryption;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3BucketDestination toAWS() const {
        Aws::S3Control::Model::S3BucketDestination awsS3BucketDestination;

        switch(this->format) {
            case EAWSS3ControlFormat::CSV:
                awsS3BucketDestination.SetFormat(Aws::S3Control::Model::Format::CSV);
                break;
            case EAWSS3ControlFormat::Parquet:
                awsS3BucketDestination.SetFormat(Aws::S3Control::Model::Format::Parquet);
                break;
            default:
                break;
        }

        switch(this->outputSchemaVersion) {
            case EAWSS3ControlOutputSchemaVersion::V_1:
                awsS3BucketDestination.SetOutputSchemaVersion(Aws::S3Control::Model::OutputSchemaVersion::V_1);
                break;
            default:
                break;
        }

        if (!(this->accountId.IsEmpty())) {
            awsS3BucketDestination.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->arn.IsEmpty())) {
            awsS3BucketDestination.SetArn(TCHAR_TO_UTF8(*this->arn));
        }

        if (!(this->prefix.IsEmpty())) {
            awsS3BucketDestination.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->encryption.IsEmpty())) {
            awsS3BucketDestination.SetEncryption(this->encryption.toAWS());
        }

        return awsS3BucketDestination;
    }

    bool IsEmpty() const {
        return this->format == EAWSS3ControlFormat::NOT_SET && this->outputSchemaVersion == EAWSS3ControlOutputSchemaVersion::NOT_SET && this->accountId.IsEmpty() && this->arn.IsEmpty() && this->prefix.IsEmpty() && this->encryption.IsEmpty();
    }

    FAWSS3ControlS3BucketDestination &fromAWS(const Aws::S3Control::Model::S3BucketDestination &awsS3BucketDestination) {
        switch(awsS3BucketDestination.GetFormat()) {
            case Aws::S3Control::Model::Format::NOT_SET:
                this->format = EAWSS3ControlFormat::NOT_SET;
                break;
            case Aws::S3Control::Model::Format::CSV:
                this->format = EAWSS3ControlFormat::CSV;
                break;
            case Aws::S3Control::Model::Format::Parquet:
                this->format = EAWSS3ControlFormat::Parquet;
                break;
            default:
                this->format = EAWSS3ControlFormat::NOT_SET;
                break;
        }

        switch(awsS3BucketDestination.GetOutputSchemaVersion()) {
            case Aws::S3Control::Model::OutputSchemaVersion::NOT_SET:
                this->outputSchemaVersion = EAWSS3ControlOutputSchemaVersion::NOT_SET;
                break;
            case Aws::S3Control::Model::OutputSchemaVersion::V_1:
                this->outputSchemaVersion = EAWSS3ControlOutputSchemaVersion::V_1;
                break;
            default:
                this->outputSchemaVersion = EAWSS3ControlOutputSchemaVersion::NOT_SET;
                break;
        }

        this->accountId = UTF8_TO_TCHAR(awsS3BucketDestination.GetAccountId().c_str());

        this->arn = UTF8_TO_TCHAR(awsS3BucketDestination.GetArn().c_str());

        this->prefix = UTF8_TO_TCHAR(awsS3BucketDestination.GetPrefix().c_str());

        this->encryption.fromAWS(awsS3BucketDestination.GetEncryption());

        return *this;
    }
#endif
};
