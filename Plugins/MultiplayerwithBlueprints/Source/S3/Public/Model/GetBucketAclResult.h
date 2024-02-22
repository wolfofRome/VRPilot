/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketAclResult.h"

#endif

#include "Model/Owner.h"
#include "Model/Grant.h"

#include "GetBucketAclResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketAclResult {
GENERATED_BODY()

    /**
    *  <p>Container for the bucket owner's display name and ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

    /**
    *  <p>A list of grants.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FGrant> grants;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketAclResult &fromAWS(const Aws::S3::Model::GetBucketAclResult &awsGetBucketAclResult) {
        this->owner.fromAWS(awsGetBucketAclResult.GetOwner());

        this->grants.Empty();
        for (const Aws::S3::Model::Grant& elem : awsGetBucketAclResult.GetGrants()) {
            this->grants.Add(FGrant().fromAWS(elem));
        }

        return *this;
    }
#endif
};
