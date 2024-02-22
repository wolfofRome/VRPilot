/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketPolicyStatusResult.h"

#endif

#include "Model/AWSS3CRTPolicyStatus.h"

#include "AWSS3CRTGetBucketPolicyStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketPolicyStatusResult {
GENERATED_BODY()

    /**
    *  <p>The policy status for the specified bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTPolicyStatus policyStatus;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketPolicyStatusResult &fromAWS(const Aws::S3Crt::Model::GetBucketPolicyStatusResult &awsGetBucketPolicyStatusResult) {
        this->policyStatus = FAWSS3CRTPolicyStatus().fromAWS(awsGetBucketPolicyStatusResult.GetPolicyStatus());

        return *this;
    }
#endif
};
