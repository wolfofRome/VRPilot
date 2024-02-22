/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InventoryDestination.h"

#endif

#include "Model/InventoryS3BucketDestination.h"

#include "InventoryDestination.generated.h"

USTRUCT(BlueprintType)
struct FInventoryDestination {
GENERATED_BODY()

    /**
    *  <p>Contains the bucket name, file format, bucket owner (optional), and prefix (optional) where inventory results are published.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInventoryS3BucketDestination s3BucketDestination;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InventoryDestination toAWS() const {
        Aws::S3::Model::InventoryDestination awsInventoryDestination;

        if (!(this->s3BucketDestination.IsEmpty())) {
            awsInventoryDestination.SetS3BucketDestination(this->s3BucketDestination.toAWS());
        }

        return awsInventoryDestination;
    }

    bool IsEmpty() const {
        return this->s3BucketDestination.IsEmpty();
    }

    FInventoryDestination &fromAWS(const Aws::S3::Model::InventoryDestination &awsInventoryDestination) {
        this->s3BucketDestination.fromAWS(awsInventoryDestination.GetS3BucketDestination());

        return *this;
    }
#endif
};
