/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/SSEKMS.h"

#endif

#include "SSEKMS.generated.h"

USTRUCT(BlueprintType)
struct FSSEKMS {
GENERATED_BODY()

    /**
    *  <p>Specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) to use for encrypting inventory reports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString keyId;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::SSEKMS toAWS() const {
        Aws::S3::Model::SSEKMS awsSSEKMS;

		if (!(this->keyId.IsEmpty())) {
            awsSSEKMS.SetKeyId(TCHAR_TO_UTF8(*this->keyId));
        }

        return awsSSEKMS;
    }

    bool IsEmpty() const {
        return this->keyId.IsEmpty();
    }

    FSSEKMS &fromAWS(const Aws::S3::Model::SSEKMS &awsSSEKMS) {
        this->keyId = UTF8_TO_TCHAR(awsSSEKMS.GetKeyId().c_str());

        return *this;
    }
#endif
};
