/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/SSEKMSEncryption.h"

#endif

#include "AWSS3ControlSSEKMSEncryption.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlSSEKMSEncryption {
GENERATED_BODY()

    /**
    *  <p>Specifies the ID of the Amazon Web Services Key Management Service (Amazon Web Services KMS) symmetric encryption customer managed key to use for encrypting generated manifest objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString keyId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::SSEKMSEncryption toAWS() const {
        Aws::S3Control::Model::SSEKMSEncryption awsSSEKMSEncryption;

        if (!(this->keyId.IsEmpty())) {
            awsSSEKMSEncryption.SetKeyId(TCHAR_TO_UTF8(*this->keyId));
        }

        return awsSSEKMSEncryption;
    }

    bool IsEmpty() const {
        return this->keyId.IsEmpty();
    }

    FAWSS3ControlSSEKMSEncryption &fromAWS(const Aws::S3Control::Model::SSEKMSEncryption &awsSSEKMSEncryption) {
        this->keyId = UTF8_TO_TCHAR(awsSSEKMSEncryption.GetKeyId().c_str());

        return *this;
    }
#endif
};
