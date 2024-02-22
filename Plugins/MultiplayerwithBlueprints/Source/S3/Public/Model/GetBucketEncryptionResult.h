/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketEncryptionResult.h"

#endif

#include "Model/ServerSideEncryptionConfiguration.h"

#include "GetBucketEncryptionResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketEncryptionResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FServerSideEncryptionConfiguration serverSideEncryptionConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketEncryptionResult &fromAWS(const Aws::S3::Model::GetBucketEncryptionResult &awsGetBucketEncryptionResult) {
        this->serverSideEncryptionConfiguration.fromAWS(awsGetBucketEncryptionResult.GetServerSideEncryptionConfiguration());

        return *this;
    }
#endif
};
