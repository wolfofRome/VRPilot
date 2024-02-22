/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PolicyStatus.h"

#endif

#include "AWSS3CRTPolicyStatus.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPolicyStatus {
GENERATED_BODY()

    /**
    *  <p>The policy status for this bucket. <code>TRUE</code> indicates that this bucket is public. <code>FALSE</code> indicates that the bucket is not public.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isPublic = false;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTPolicyStatus &fromAWS(const Aws::S3Crt::Model::PolicyStatus &awsPolicyStatus) {
        this->isPublic = awsPolicyStatus.GetIsPublic();

        return *this;
    }
#endif
};
