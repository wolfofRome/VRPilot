/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetPublicAccessBlockResult.h"

#endif

#include "Model/AWSS3CRTPublicAccessBlockConfiguration.h"

#include "AWSS3CRTGetPublicAccessBlockResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetPublicAccessBlockResult {
GENERATED_BODY()

    /**
    *  <p>The <code>PublicAccessBlock</code> configuration currently in effect for this Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTPublicAccessBlockConfiguration publicAccessBlockConfiguration;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetPublicAccessBlockResult &fromAWS(const Aws::S3Crt::Model::GetPublicAccessBlockResult &awsGetPublicAccessBlockResult) {
        this->publicAccessBlockConfiguration = FAWSS3CRTPublicAccessBlockConfiguration().fromAWS(awsGetPublicAccessBlockResult.GetPublicAccessBlockConfiguration());

        return *this;
    }
#endif
};
