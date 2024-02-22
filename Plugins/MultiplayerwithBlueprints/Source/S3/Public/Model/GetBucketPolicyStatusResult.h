/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketPolicyStatusResult.h"

#endif

#include "Model/S3PolicyStatus.h"

#include "GetBucketPolicyStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketPolicyStatusResult {
GENERATED_BODY()

    /**
    *  <p>The policy status for the specified bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3PolicyStatus policyStatus;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketPolicyStatusResult &fromAWS(const Aws::S3::Model::GetBucketPolicyStatusResult &awsGetBucketPolicyStatusResult) {
        this->policyStatus.fromAWS(awsGetBucketPolicyStatusResult.GetPolicyStatus());

        return *this;
    }
#endif
};
