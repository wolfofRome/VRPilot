/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/core/utils/memory/stl/AWSStringStream.h"
#include "aws/s3/model/GetBucketPolicyResult.h"

#endif

#include "GetBucketPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The bucket policy as a JSON document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString policy;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketPolicyResult &fromAWS(const Aws::S3::Model::GetBucketPolicyResult &awsGetBucketPolicyResult) {
        Aws::StringStream memoryStream;
        std::copy(std::istreambuf_iterator<char>(awsGetBucketPolicyResult.GetPolicy()), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(memoryStream));
        const auto input = memoryStream.str();
        this->policy = input.c_str();

        return *this;
    }
#endif
};
