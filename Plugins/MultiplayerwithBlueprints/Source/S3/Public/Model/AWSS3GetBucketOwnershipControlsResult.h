/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketOwnershipControlsResult.h"

#endif

#include "Model/AWSS3OwnershipControls.h"

#include "AWSS3GetBucketOwnershipControlsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3GetBucketOwnershipControlsResult {
GENERATED_BODY()

    /**
    *  <p>The <code>OwnershipControls</code> (BucketOwnerPreferred or ObjectWriter) currently in effect for this Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3OwnershipControls ownershipControls;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FAWSS3GetBucketOwnershipControlsResult &fromAWS(const Aws::S3::Model::GetBucketOwnershipControlsResult &awsGetBucketOwnershipControlsResult) {
        this->ownershipControls.fromAWS(awsGetBucketOwnershipControlsResult.GetOwnershipControls());

        return *this;
    }
#endif
};
