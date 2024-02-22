/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectLegalHoldResult.h"

#endif

#include "Model/ObjectLockLegalHold.h"

#include "GetObjectLegalHoldResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectLegalHoldResult {
GENERATED_BODY()

    /**
    *  <p>The current Legal Hold status for the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FObjectLockLegalHold legalHold;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectLegalHoldResult &fromAWS(const Aws::S3::Model::GetObjectLegalHoldResult &awsGetObjectLegalHoldResult) {
        this->legalHold.fromAWS(awsGetObjectLegalHoldResult.GetLegalHold());

        return *this;
    }
#endif
};
