/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutAccessPointPolicyRequest.h"

#endif

#include "PutAccessPointPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutAccessPointPolicyRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID for owner of the bucket associated with the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the access point that you want to associate with the specified policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>The policy that you want to apply to the specified access point. For more information about access point policies, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/access-points.html">Managing Data Access with Amazon S3 Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString policy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutAccessPointPolicyRequest toAWS() const {
        Aws::S3Control::Model::PutAccessPointPolicyRequest awsPutAccessPointPolicyRequest;

		if (!(this->accountId.IsEmpty())) {
            awsPutAccessPointPolicyRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsPutAccessPointPolicyRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

		if (!(this->policy.IsEmpty())) {
            awsPutAccessPointPolicyRequest.SetPolicy(TCHAR_TO_UTF8(*this->policy));
        }

        return awsPutAccessPointPolicyRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty() && this->policy.IsEmpty();
    }
#endif
};
