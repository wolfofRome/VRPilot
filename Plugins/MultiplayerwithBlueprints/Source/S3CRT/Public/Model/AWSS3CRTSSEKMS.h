/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/SSEKMS.h"

#endif

#include "AWSS3CRTSSEKMS.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTSSEKMS {
GENERATED_BODY()

    /**
    *  <p>Specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) to use for encrypting inventory reports.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString keyId;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::SSEKMS toAWS() const {
        Aws::S3Crt::Model::SSEKMS awsSSEKMS;

        if (!(this->keyId.IsEmpty())) {
            awsSSEKMS.SetKeyId(TCHAR_TO_UTF8(*this->keyId));
        }

        return awsSSEKMS;
    }

    bool IsEmpty() const {
        return this->keyId.IsEmpty();
    }

    FAWSS3CRTSSEKMS &fromAWS(const Aws::S3Crt::Model::SSEKMS &awsSSEKMS) {
        this->keyId = UTF8_TO_TCHAR(awsSSEKMS.GetKeyId().c_str());

        return *this;
    }
#endif
};
