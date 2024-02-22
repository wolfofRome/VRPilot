/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GlacierJobParameters.h"

#endif

#include "Model/Tier.h"

#include "GlacierJobParameters.generated.h"

USTRUCT(BlueprintType)
struct FGlacierJobParameters {
GENERATED_BODY()

    /**
    *  <p>S3 Glacier retrieval tier at which the restore will be processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSTier tier = EAWSTier::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::GlacierJobParameters toAWS() const {
        Aws::S3::Model::GlacierJobParameters awsGlacierJobParameters;

        switch(this->tier) {
            case EAWSTier::Standard:
                awsGlacierJobParameters.SetTier(Aws::S3::Model::Tier::Standard);
                break;
            case EAWSTier::Bulk:
                awsGlacierJobParameters.SetTier(Aws::S3::Model::Tier::Bulk);
                break;
            case EAWSTier::Expedited:
                awsGlacierJobParameters.SetTier(Aws::S3::Model::Tier::Expedited);
                break;
            default:
                break;
        }

        return awsGlacierJobParameters;
    }

    bool IsEmpty() const {
        return tier == EAWSTier::NOT_SET;
    }
#endif
};
