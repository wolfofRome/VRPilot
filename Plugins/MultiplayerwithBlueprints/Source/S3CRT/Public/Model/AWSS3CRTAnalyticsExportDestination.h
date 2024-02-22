/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AnalyticsExportDestination.h"

#endif

#include "Model/AWSS3CRTAnalyticsS3BucketDestination.h"

#include "AWSS3CRTAnalyticsExportDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAnalyticsExportDestination {
GENERATED_BODY()

    /**
    *  <p>A destination signifying output to an S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAnalyticsS3BucketDestination s3BucketDestination;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AnalyticsExportDestination toAWS() const {
        Aws::S3Crt::Model::AnalyticsExportDestination awsAnalyticsExportDestination;

        if (!(this->s3BucketDestination.IsEmpty())) {
            awsAnalyticsExportDestination.SetS3BucketDestination(this->s3BucketDestination.toAWS());
        }

        return awsAnalyticsExportDestination;
    }

    bool IsEmpty() const {
        return this->s3BucketDestination.IsEmpty();
    }

    FAWSS3CRTAnalyticsExportDestination &fromAWS(const Aws::S3Crt::Model::AnalyticsExportDestination &awsAnalyticsExportDestination) {
        this->s3BucketDestination = FAWSS3CRTAnalyticsS3BucketDestination().fromAWS(awsAnalyticsExportDestination.GetS3BucketDestination());

        return *this;
    }
#endif
};
