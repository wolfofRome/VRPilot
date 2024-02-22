/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketPolicyResult.h"

#endif

#include "AWSS3ControlGetBucketPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The policy of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlGetBucketPolicyResult &fromAWS(const Aws::S3Control::Model::GetBucketPolicyResult &awsGetBucketPolicyResult) {
        this->policy = UTF8_TO_TCHAR(awsGetBucketPolicyResult.GetPolicy().c_str());

        return *this;
    }
#endif
};
