/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketOwnershipControlsResult.h"

#endif

#include "Model/AWSS3CRTOwnershipControls.h"

#include "AWSS3CRTGetBucketOwnershipControlsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketOwnershipControlsResult {
GENERATED_BODY()

    /**
    *  <p>The <code>OwnershipControls</code> (BucketOwnerPreferred or ObjectWriter) currently in effect for this Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwnershipControls ownershipControls;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketOwnershipControlsResult &fromAWS(const Aws::S3Crt::Model::GetBucketOwnershipControlsResult &awsGetBucketOwnershipControlsResult) {
        this->ownershipControls = FAWSS3CRTOwnershipControls().fromAWS(awsGetBucketOwnershipControlsResult.GetOwnershipControls());

        return *this;
    }
#endif
};
