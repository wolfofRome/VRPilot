/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketEncryptionResult.h"

#endif

#include "Model/AWSS3CRTServerSideEncryptionConfiguration.h"

#include "AWSS3CRTGetBucketEncryptionResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketEncryptionResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTServerSideEncryptionConfiguration serverSideEncryptionConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketEncryptionResult &fromAWS(const Aws::S3Crt::Model::GetBucketEncryptionResult &awsGetBucketEncryptionResult) {
        this->serverSideEncryptionConfiguration = FAWSS3CRTServerSideEncryptionConfiguration().fromAWS(awsGetBucketEncryptionResult.GetServerSideEncryptionConfiguration());

        return *this;
    }
#endif
};
