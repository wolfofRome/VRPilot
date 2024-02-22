/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AnalyticsS3BucketDestination.h"

#endif

#include "Model/AnalyticsS3ExportFileFormat.h"

#include "AnalyticsS3BucketDestination.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsS3BucketDestination {
GENERATED_BODY()

    /**
    *  <p>Specifies the file format used when exporting data to Amazon S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSAnalyticsS3ExportFileFormat format = EAWSAnalyticsS3ExportFileFormat::NOT_SET;

    /**
    *  <p>The account ID that owns the destination S3 bucket. If no account ID is provided, the owner is not validated before exporting data.</p>  <p> Although this value is optional, we strongly recommend that you set it to help prevent problems if the destination bucket ownership changes. </p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucketAccountId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the bucket to which data is exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The prefix to use when exporting data. The prefix is prepended to all results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AnalyticsS3BucketDestination toAWS() const {
        Aws::S3::Model::AnalyticsS3BucketDestination awsAnalyticsS3BucketDestination;

        switch(this->format) {
            case EAWSAnalyticsS3ExportFileFormat::CSV:
                awsAnalyticsS3BucketDestination.SetFormat(Aws::S3::Model::AnalyticsS3ExportFileFormat::CSV);
                break;
            default:
                break;
        }

		if (!(this->bucketAccountId.IsEmpty())) {
            awsAnalyticsS3BucketDestination.SetBucketAccountId(TCHAR_TO_UTF8(*this->bucketAccountId));
        }

		if (!(this->bucket.IsEmpty())) {
            awsAnalyticsS3BucketDestination.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->prefix.IsEmpty())) {
            awsAnalyticsS3BucketDestination.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        return awsAnalyticsS3BucketDestination;
    }

    bool IsEmpty() const {
        return format == EAWSAnalyticsS3ExportFileFormat::NOT_SET && this->bucketAccountId.IsEmpty() && this->bucket.IsEmpty() && this->prefix.IsEmpty();
    }

    FAnalyticsS3BucketDestination &fromAWS(const Aws::S3::Model::AnalyticsS3BucketDestination &awsAnalyticsS3BucketDestination) {
        switch(awsAnalyticsS3BucketDestination.GetFormat()) {
            case Aws::S3::Model::AnalyticsS3ExportFileFormat::NOT_SET:
                this->format = EAWSAnalyticsS3ExportFileFormat::NOT_SET;
                break;
            case Aws::S3::Model::AnalyticsS3ExportFileFormat::CSV:
                this->format = EAWSAnalyticsS3ExportFileFormat::CSV;
                break;
            default:
                this->format = EAWSAnalyticsS3ExportFileFormat::NOT_SET;
                break;
        }

        this->bucketAccountId = UTF8_TO_TCHAR(awsAnalyticsS3BucketDestination.GetBucketAccountId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsAnalyticsS3BucketDestination.GetBucket().c_str());

        this->prefix = UTF8_TO_TCHAR(awsAnalyticsS3BucketDestination.GetPrefix().c_str());

        return *this;
    }
#endif
};
