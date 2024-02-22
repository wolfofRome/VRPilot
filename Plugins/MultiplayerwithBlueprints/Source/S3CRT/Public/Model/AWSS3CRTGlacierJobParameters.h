/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GlacierJobParameters.h"

#endif

#include "Model/AWSS3CRTTier.h"

#include "AWSS3CRTGlacierJobParameters.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGlacierJobParameters {
GENERATED_BODY()

    /**
    *  <p>Retrieval tier at which the restore will be processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTTier tier = EAWSS3CRTTier::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::GlacierJobParameters toAWS() const {
        Aws::S3Crt::Model::GlacierJobParameters awsGlacierJobParameters;

        switch(this->tier) {
            case EAWSS3CRTTier::Standard:
                awsGlacierJobParameters.SetTier(Aws::S3Crt::Model::Tier::Standard);
                break;
            case EAWSS3CRTTier::Bulk:
                awsGlacierJobParameters.SetTier(Aws::S3Crt::Model::Tier::Bulk);
                break;
            case EAWSS3CRTTier::Expedited:
                awsGlacierJobParameters.SetTier(Aws::S3Crt::Model::Tier::Expedited);
                break;
            default:
                break;
        }

        return awsGlacierJobParameters;
    }

    bool IsEmpty() const {
        return this->tier == EAWSS3CRTTier::NOT_SET;
    }
#endif
};
