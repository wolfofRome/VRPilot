/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3SetObjectLegalHoldOperation.h"

#endif

#include "Model/S3ObjectLockLegalHold.h"

#include "S3SetObjectLegalHoldOperation.generated.h"

USTRUCT(BlueprintType)
struct FS3SetObjectLegalHoldOperation {
GENERATED_BODY()

    /**
    *  <p>The Legal Hold contains the status to be applied to all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ObjectLockLegalHold legalHold;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3SetObjectLegalHoldOperation toAWS() const {
        Aws::S3Control::Model::S3SetObjectLegalHoldOperation awsS3SetObjectLegalHoldOperation;

        if (!(this->legalHold.IsEmpty())) {
            awsS3SetObjectLegalHoldOperation.SetLegalHold(this->legalHold.toAWS());
        }

        return awsS3SetObjectLegalHoldOperation;
    }

    bool IsEmpty() const {
        return this->legalHold.IsEmpty();
    }

    FS3SetObjectLegalHoldOperation &fromAWS(const Aws::S3Control::Model::S3SetObjectLegalHoldOperation &awsS3SetObjectLegalHoldOperation) {
        this->legalHold.fromAWS(awsS3SetObjectLegalHoldOperation.GetLegalHold());

        return *this;
    }
#endif
};
