/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PolicyStatus.h"

#endif

#include "S3PolicyStatus.generated.h"

USTRUCT(BlueprintType)
struct FS3PolicyStatus {
GENERATED_BODY()

    /**
    *  <p>The policy status for this bucket. <code>TRUE</code> indicates that this bucket is public. <code>FALSE</code> indicates that the bucket is not public.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isPublic = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FS3PolicyStatus &fromAWS(const Aws::S3::Model::PolicyStatus &awsPolicyStatus) {
        this->isPublic = awsPolicyStatus.GetIsPublic();

        return *this;
    }
#endif
};
