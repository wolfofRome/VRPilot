/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/core/utils/memory/stl/AWSStringStream.h"
#include "aws/s3-crt/model/GetBucketPolicyResult.h"

#endif

#include "AWSS3CRTGetBucketPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The bucket policy as a JSON document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString policy;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketPolicyResult &fromAWS(const Aws::S3Crt::Model::GetBucketPolicyResult &awsGetBucketPolicyResult) {
        Aws::StringStream memoryStream;
        std::copy(std::istreambuf_iterator<char>(awsGetBucketPolicyResult.GetPolicy()), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(memoryStream));
        const auto input = memoryStream.str();
        this->policy = input.c_str();

        return *this;
    }
#endif
};
