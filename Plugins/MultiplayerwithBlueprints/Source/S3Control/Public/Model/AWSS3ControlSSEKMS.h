/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/SSEKMS.h"

#endif

#include "AWSS3ControlSSEKMS.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlSSEKMS {
GENERATED_BODY()

    /**
    *  <p>A container for the ARN of the SSE-KMS encryption. This property is read-only and follows the following format: <code> arn:aws:kms:<i>us-east-1</i>:<i>example-account-id</i>:key/<i>example-9a73-4afc-8d29-8f5900cef44e</i> </code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString keyId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::SSEKMS toAWS() const {
        Aws::S3Control::Model::SSEKMS awsSSEKMS;

        if (!(this->keyId.IsEmpty())) {
            awsSSEKMS.SetKeyId(TCHAR_TO_UTF8(*this->keyId));
        }

        return awsSSEKMS;
    }

    bool IsEmpty() const {
        return this->keyId.IsEmpty();
    }

    FAWSS3ControlSSEKMS &fromAWS(const Aws::S3Control::Model::SSEKMS &awsSSEKMS) {
        this->keyId = UTF8_TO_TCHAR(awsSSEKMS.GetKeyId().c_str());

        return *this;
    }
#endif
};
