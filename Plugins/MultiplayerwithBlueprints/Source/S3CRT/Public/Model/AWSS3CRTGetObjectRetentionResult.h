/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetObjectRetentionResult.h"

#endif

#include "Model/AWSS3CRTObjectLockRetention.h"

#include "AWSS3CRTGetObjectRetentionResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectRetentionResult {
GENERATED_BODY()

    /**
    *  <p>The container element for an object's retention settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTObjectLockRetention retention;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectRetentionResult &fromAWS(const Aws::S3Crt::Model::GetObjectRetentionResult &awsGetObjectRetentionResult) {
        this->retention = FAWSS3CRTObjectLockRetention().fromAWS(awsGetObjectRetentionResult.GetRetention());

        return *this;
    }
#endif
};
