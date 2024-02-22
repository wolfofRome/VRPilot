/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InventoryEncryption.h"

#endif

#include "Model/SSES3.h"
#include "Model/SSEKMS.h"

#include "InventoryEncryption.generated.h"

USTRUCT(BlueprintType)
struct FInventoryEncryption {
GENERATED_BODY()

    /**
    *  <p>Specifies the use of SSE-S3 to encrypt delivered inventory reports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FSSES3 SSES3;

    /**
    *  <p>Specifies the use of SSE-KMS to encrypt delivered inventory reports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FSSEKMS SSEKMS;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InventoryEncryption toAWS() const {
        Aws::S3::Model::InventoryEncryption awsInventoryEncryption;

        if (!(this->SSES3.IsEmpty())) {
            awsInventoryEncryption.SetSSES3(this->SSES3.toAWS());
        }

        if (!(this->SSEKMS.IsEmpty())) {
            awsInventoryEncryption.SetSSEKMS(this->SSEKMS.toAWS());
        }

        return awsInventoryEncryption;
    }

    bool IsEmpty() const {
        return this->SSES3.IsEmpty() && this->SSEKMS.IsEmpty();
    }

    FInventoryEncryption &fromAWS(const Aws::S3::Model::InventoryEncryption &awsInventoryEncryption) {
        this->SSES3.fromAWS(awsInventoryEncryption.GetSSES3());

        this->SSEKMS.fromAWS(awsInventoryEncryption.GetSSEKMS());

        return *this;
    }
#endif
};
