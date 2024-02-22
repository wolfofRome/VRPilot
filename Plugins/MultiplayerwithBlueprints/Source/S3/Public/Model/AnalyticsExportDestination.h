/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AnalyticsExportDestination.h"

#endif

#include "Model/AnalyticsS3BucketDestination.h"

#include "AnalyticsExportDestination.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsExportDestination {
GENERATED_BODY()

    /**
    *  <p>A destination signifying output to an S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAnalyticsS3BucketDestination s3BucketDestination;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AnalyticsExportDestination toAWS() const {
        Aws::S3::Model::AnalyticsExportDestination awsAnalyticsExportDestination;

        if (!(this->s3BucketDestination.IsEmpty())) {
            awsAnalyticsExportDestination.SetS3BucketDestination(this->s3BucketDestination.toAWS());
        }

        return awsAnalyticsExportDestination;
    }

    bool IsEmpty() const {
        return this->s3BucketDestination.IsEmpty();
    }

    FAnalyticsExportDestination &fromAWS(const Aws::S3::Model::AnalyticsExportDestination &awsAnalyticsExportDestination) {
        this->s3BucketDestination.fromAWS(awsAnalyticsExportDestination.GetS3BucketDestination());

        return *this;
    }
#endif
};
