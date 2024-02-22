/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InventoryEncryption.h"

#endif

#include "Model/AWSS3CRTSSES3.h"
#include "Model/AWSS3CRTSSEKMS.h"

#include "AWSS3CRTInventoryEncryption.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInventoryEncryption {
GENERATED_BODY()

    /**
    *  <p>Specifies the use of SSE-S3 to encrypt delivered inventory reports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTSSES3 sSES3;

    /**
    *  <p>Specifies the use of SSE-KMS to encrypt delivered inventory reports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTSSEKMS sSEKMS;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InventoryEncryption toAWS() const {
        Aws::S3Crt::Model::InventoryEncryption awsInventoryEncryption;

        if (!(this->sSES3.IsEmpty())) {
            awsInventoryEncryption.SetSSES3(this->sSES3.toAWS());
        }

        if (!(this->sSEKMS.IsEmpty())) {
            awsInventoryEncryption.SetSSEKMS(this->sSEKMS.toAWS());
        }

        return awsInventoryEncryption;
    }

    bool IsEmpty() const {
        return this->sSES3.IsEmpty() && this->sSEKMS.IsEmpty();
    }

    FAWSS3CRTInventoryEncryption &fromAWS(const Aws::S3Crt::Model::InventoryEncryption &awsInventoryEncryption) {
        this->sSES3 = FAWSS3CRTSSES3().fromAWS(awsInventoryEncryption.GetSSES3());

        this->sSEKMS = FAWSS3CRTSSEKMS().fromAWS(awsInventoryEncryption.GetSSEKMS());

        return *this;
    }
#endif
};
