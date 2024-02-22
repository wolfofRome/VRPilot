/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InventoryDestination.h"

#endif

#include "Model/AWSS3CRTInventoryS3BucketDestination.h"

#include "AWSS3CRTInventoryDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInventoryDestination {
GENERATED_BODY()

    /**
    *  <p>Contains the bucket name, file format, bucket owner (optional), and prefix (optional) where inventory results are published.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInventoryS3BucketDestination s3BucketDestination;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InventoryDestination toAWS() const {
        Aws::S3Crt::Model::InventoryDestination awsInventoryDestination;

        if (!(this->s3BucketDestination.IsEmpty())) {
            awsInventoryDestination.SetS3BucketDestination(this->s3BucketDestination.toAWS());
        }

        return awsInventoryDestination;
    }

    bool IsEmpty() const {
        return this->s3BucketDestination.IsEmpty();
    }

    FAWSS3CRTInventoryDestination &fromAWS(const Aws::S3Crt::Model::InventoryDestination &awsInventoryDestination) {
        this->s3BucketDestination = FAWSS3CRTInventoryS3BucketDestination().fromAWS(awsInventoryDestination.GetS3BucketDestination());

        return *this;
    }
#endif
};
