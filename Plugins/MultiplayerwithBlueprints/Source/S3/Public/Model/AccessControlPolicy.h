/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AccessControlPolicy.h"

#endif

#include "Model/Grant.h"
#include "Model/Owner.h"

#include "AccessControlPolicy.generated.h"

USTRUCT(BlueprintType)
struct FAccessControlPolicy {
GENERATED_BODY()

    /**
    *  <p>A list of grants.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FGrant> grants;

    /**
    *  <p>Container for the bucket owner's display name and ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AccessControlPolicy toAWS() const {
        Aws::S3::Model::AccessControlPolicy awsAccessControlPolicy;

        for (const FGrant& elem : this->grants) {
            awsAccessControlPolicy.AddGrants(elem.toAWS());
        }

        if (!(this->owner.IsEmpty())) {
            awsAccessControlPolicy.SetOwner(this->owner.toAWS());
        }

        return awsAccessControlPolicy;
    }

    bool IsEmpty() const {
        return this->grants.Num() == 0 && this->owner.IsEmpty();
    }
#endif
};
