/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketReplicationResult.h"

#endif

#include "Model/ReplicationConfiguration.h"

#include "GetBucketReplicationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketReplicationResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FReplicationConfiguration replicationConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketReplicationResult &fromAWS(const Aws::S3::Model::GetBucketReplicationResult &awsGetBucketReplicationResult) {
        this->replicationConfiguration.fromAWS(awsGetBucketReplicationResult.GetReplicationConfiguration());

        return *this;
    }
#endif
};
