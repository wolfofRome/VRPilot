/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetPublicAccessBlockResult.h"

#endif

#include "Model/S3PublicAccessBlockConfiguration.h"

#include "S3GetPublicAccessBlockResult.generated.h"

USTRUCT(BlueprintType)
struct FS3GetPublicAccessBlockResult {
GENERATED_BODY()

    /**
    *  <p>The <code>PublicAccessBlock</code> configuration currently in effect for this Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3PublicAccessBlockConfiguration publicAccessBlockConfiguration;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FS3GetPublicAccessBlockResult &fromAWS(const Aws::S3::Model::GetPublicAccessBlockResult &awsGetPublicAccessBlockResult) {
        this->publicAccessBlockConfiguration.fromAWS(awsGetPublicAccessBlockResult.GetPublicAccessBlockConfiguration());

        return *this;
    }
#endif
};
