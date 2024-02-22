/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AnalyticsS3BucketDestination.h"

#endif

#include "Model/AWSS3CRTAnalyticsS3ExportFileFormat.h"

#include "AWSS3CRTAnalyticsS3BucketDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAnalyticsS3BucketDestination {
GENERATED_BODY()

    /**
    *  <p>Specifies the file format used when exporting data to Amazon S3.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTAnalyticsS3ExportFileFormat format = EAWSS3CRTAnalyticsS3ExportFileFormat::NOT_SET;

    /**
    *  <p>The account ID that owns the destination S3 bucket. If no account ID is provided, the owner is not validated before exporting data.</p>  <p> Although this value is optional, we strongly recommend that you set it to help prevent problems if the destination bucket ownership changes. </p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucketAccountId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the bucket to which data is exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The prefix to use when exporting data. The prefix is prepended to all results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AnalyticsS3BucketDestination toAWS() const {
        Aws::S3Crt::Model::AnalyticsS3BucketDestination awsAnalyticsS3BucketDestination;

        switch(this->format) {
            case EAWSS3CRTAnalyticsS3ExportFileFormat::CSV:
                awsAnalyticsS3BucketDestination.SetFormat(Aws::S3Crt::Model::AnalyticsS3ExportFileFormat::CSV);
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
        return format == EAWSS3CRTAnalyticsS3ExportFileFormat::NOT_SET && this->bucketAccountId.IsEmpty() && this->bucket.IsEmpty() && this->prefix.IsEmpty();
    }

    FAWSS3CRTAnalyticsS3BucketDestination &fromAWS(const Aws::S3Crt::Model::AnalyticsS3BucketDestination &awsAnalyticsS3BucketDestination) {
        switch(awsAnalyticsS3BucketDestination.GetFormat()) {
            case Aws::S3Crt::Model::AnalyticsS3ExportFileFormat::NOT_SET:
                this->format = EAWSS3CRTAnalyticsS3ExportFileFormat::NOT_SET;
                break;
            case Aws::S3Crt::Model::AnalyticsS3ExportFileFormat::CSV:
                this->format = EAWSS3CRTAnalyticsS3ExportFileFormat::CSV;
                break;
            default:
                this->format = EAWSS3CRTAnalyticsS3ExportFileFormat::NOT_SET;
                break;
        }

        this->bucketAccountId = UTF8_TO_TCHAR(awsAnalyticsS3BucketDestination.GetBucketAccountId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsAnalyticsS3BucketDestination.GetBucket().c_str());

        this->prefix = UTF8_TO_TCHAR(awsAnalyticsS3BucketDestination.GetPrefix().c_str());

        return *this;
    }
#endif
};
