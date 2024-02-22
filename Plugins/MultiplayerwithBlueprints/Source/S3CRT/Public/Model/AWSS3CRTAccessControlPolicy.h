/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AccessControlPolicy.h"

#endif

#include "Model/AWSS3CRTGrant.h"
#include "Model/AWSS3CRTOwner.h"

#include "AWSS3CRTAccessControlPolicy.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAccessControlPolicy {
GENERATED_BODY()

    /**
    *  <p>A list of grants.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTGrant> grants;

    /**
    *  <p>Container for the bucket owner's display name and ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AccessControlPolicy toAWS() const {
        Aws::S3Crt::Model::AccessControlPolicy awsAccessControlPolicy;

        for (const FAWSS3CRTGrant& elem : this->grants) {
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
