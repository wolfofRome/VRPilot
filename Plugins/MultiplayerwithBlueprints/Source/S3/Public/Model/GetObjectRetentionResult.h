/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectRetentionResult.h"

#endif

#include "Model/ObjectLockRetention.h"

#include "GetObjectRetentionResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectRetentionResult {
GENERATED_BODY()

    /**
    *  <p>The container element for an object's retention settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FObjectLockRetention retention;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectRetentionResult &fromAWS(const Aws::S3::Model::GetObjectRetentionResult &awsGetObjectRetentionResult) {
        this->retention.fromAWS(awsGetObjectRetentionResult.GetRetention());

        return *this;
    }
#endif
};
