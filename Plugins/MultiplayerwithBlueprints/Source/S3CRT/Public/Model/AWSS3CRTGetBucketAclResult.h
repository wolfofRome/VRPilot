/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketAclResult.h"

#endif

#include "Model/AWSS3CRTOwner.h"
#include "Model/AWSS3CRTGrant.h"

#include "AWSS3CRTGetBucketAclResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketAclResult {
GENERATED_BODY()

    /**
    *  <p>Container for the bucket owner's display name and ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

    /**
    *  <p>A list of grants.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTGrant> grants;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketAclResult &fromAWS(const Aws::S3Crt::Model::GetBucketAclResult &awsGetBucketAclResult) {
        this->owner = FAWSS3CRTOwner().fromAWS(awsGetBucketAclResult.GetOwner());

        this->grants.Empty();
        for (const Aws::S3Crt::Model::Grant& elem : awsGetBucketAclResult.GetGrants()) {
            this->grants.Add(FAWSS3CRTGrant().fromAWS(elem));
        }

        return *this;
    }
#endif
};
