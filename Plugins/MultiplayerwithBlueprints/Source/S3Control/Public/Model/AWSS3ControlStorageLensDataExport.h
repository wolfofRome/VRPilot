/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/StorageLensDataExport.h"

#endif

#include "Model/AWSS3ControlS3BucketDestination.h"
#include "Model/AWSS3ControlCloudWatchMetrics.h"

#include "AWSS3ControlStorageLensDataExport.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlStorageLensDataExport {
GENERATED_BODY()

    /**
    *  <p>A container for the bucket where the S3 Storage Lens metrics export will be located.</p>  <p>This bucket must be located in the same Region as the storage lens configuration. </p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlS3BucketDestination s3BucketDestination;

    /**
    *  <p>A container for enabling Amazon CloudWatch publishing for S3 Storage Lens metrics.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlCloudWatchMetrics cloudWatchMetrics;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::StorageLensDataExport toAWS() const {
        Aws::S3Control::Model::StorageLensDataExport awsStorageLensDataExport;

        if (!(this->s3BucketDestination.IsEmpty())) {
            awsStorageLensDataExport.SetS3BucketDestination(this->s3BucketDestination.toAWS());
        }

        if (!(this->cloudWatchMetrics.IsEmpty())) {
            awsStorageLensDataExport.SetCloudWatchMetrics(this->cloudWatchMetrics.toAWS());
        }

        return awsStorageLensDataExport;
    }

    bool IsEmpty() const {
        return this->s3BucketDestination.IsEmpty() && this->cloudWatchMetrics.IsEmpty();
    }

    FAWSS3ControlStorageLensDataExport &fromAWS(const Aws::S3Control::Model::StorageLensDataExport &awsStorageLensDataExport) {
        this->s3BucketDestination.fromAWS(awsStorageLensDataExport.GetS3BucketDestination());

        this->cloudWatchMetrics.fromAWS(awsStorageLensDataExport.GetCloudWatchMetrics());

        return *this;
    }
#endif
};
