/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GeneratedManifestEncryption.h"

#endif

#include "Model/AWSS3ControlSSES3Encryption.h"
#include "Model/AWSS3ControlSSEKMSEncryption.h"

#include "AWSS3ControlGeneratedManifestEncryption.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGeneratedManifestEncryption {
GENERATED_BODY()

    /**
    *  <p>Specifies the use of SSE-S3 to encrypt generated manifest objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlSSES3Encryption sSES3;

    /**
    *  <p>Configuration details on how SSE-KMS is used to encrypt generated manifest objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlSSEKMSEncryption sSEKMS;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GeneratedManifestEncryption toAWS() const {
        Aws::S3Control::Model::GeneratedManifestEncryption awsGeneratedManifestEncryption;

        if (!(this->sSES3.IsEmpty())) {
            awsGeneratedManifestEncryption.SetSSES3(this->sSES3.toAWS());
        }

        if (!(this->sSEKMS.IsEmpty())) {
            awsGeneratedManifestEncryption.SetSSEKMS(this->sSEKMS.toAWS());
        }

        return awsGeneratedManifestEncryption;
    }

    bool IsEmpty() const {
        return this->sSES3.IsEmpty() && this->sSEKMS.IsEmpty();
    }

    FAWSS3ControlGeneratedManifestEncryption &fromAWS(const Aws::S3Control::Model::GeneratedManifestEncryption &awsGeneratedManifestEncryption) {
        this->sSES3.fromAWS(awsGeneratedManifestEncryption.GetSSES3());

        this->sSEKMS.fromAWS(awsGeneratedManifestEncryption.GetSSEKMS());

        return *this;
    }
#endif
};
