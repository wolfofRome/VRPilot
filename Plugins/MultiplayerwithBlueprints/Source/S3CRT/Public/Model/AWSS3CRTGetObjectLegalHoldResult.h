/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetObjectLegalHoldResult.h"

#endif

#include "Model/AWSS3CRTObjectLockLegalHold.h"

#include "AWSS3CRTGetObjectLegalHoldResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectLegalHoldResult {
GENERATED_BODY()

    /**
    *  <p>The current Legal Hold status for the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTObjectLockLegalHold legalHold;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectLegalHoldResult &fromAWS(const Aws::S3Crt::Model::GetObjectLegalHoldResult &awsGetObjectLegalHoldResult) {
        this->legalHold = FAWSS3CRTObjectLockLegalHold().fromAWS(awsGetObjectLegalHoldResult.GetLegalHold());

        return *this;
    }
#endif
};
