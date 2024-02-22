/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketReplicationResult.h"

#endif

#include "Model/AWSS3CRTReplicationConfiguration.h"

#include "AWSS3CRTGetBucketReplicationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketReplicationResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTReplicationConfiguration replicationConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketReplicationResult &fromAWS(const Aws::S3Crt::Model::GetBucketReplicationResult &awsGetBucketReplicationResult) {
        this->replicationConfiguration = FAWSS3CRTReplicationConfiguration().fromAWS(awsGetBucketReplicationResult.GetReplicationConfiguration());

        return *this;
    }
#endif
};
