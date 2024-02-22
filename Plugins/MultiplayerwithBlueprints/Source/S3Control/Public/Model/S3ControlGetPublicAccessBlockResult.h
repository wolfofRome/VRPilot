/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetPublicAccessBlockResult.h"

#endif

#include "Model/S3ControlPublicAccessBlockConfiguration.h"

#include "S3ControlGetPublicAccessBlockResult.generated.h"

USTRUCT(BlueprintType)
struct FS3ControlGetPublicAccessBlockResult {
GENERATED_BODY()

    /**
    *  <p>The <code>PublicAccessBlock</code> configuration currently in effect for this Amazon Web Services account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlockConfiguration;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FS3ControlGetPublicAccessBlockResult &fromAWS(const Aws::S3Control::Model::GetPublicAccessBlockResult &awsGetPublicAccessBlockResult) {
        this->publicAccessBlockConfiguration.fromAWS(awsGetPublicAccessBlockResult.GetPublicAccessBlockConfiguration());

        return *this;
    }
#endif
};
