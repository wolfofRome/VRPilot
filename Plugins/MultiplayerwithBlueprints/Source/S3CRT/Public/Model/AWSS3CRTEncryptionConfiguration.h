/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/EncryptionConfiguration.h"

#endif

#include "AWSS3CRTEncryptionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTEncryptionConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies the ID (Key ARN or Alias ARN) of the customer managed customer master key (CMK) stored in AWS Key Management Service (KMS) for the destination bucket. Amazon S3 uses this key to encrypt replica objects. Amazon S3 only supports symmetric customer managed CMKs. For more information, see <a href="https://docs.aws.amazon.com/kms/latest/developerguide/symmetric-asymmetric.html">Using Symmetric and Asymmetric Keys</a> in the <i>AWS Key Management Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString replicaKmsKeyID;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::EncryptionConfiguration toAWS() const {
        Aws::S3Crt::Model::EncryptionConfiguration awsEncryptionConfiguration;

        if (!(this->replicaKmsKeyID.IsEmpty())) {
            awsEncryptionConfiguration.SetReplicaKmsKeyID(TCHAR_TO_UTF8(*this->replicaKmsKeyID));
        }

        return awsEncryptionConfiguration;
    }

    bool IsEmpty() const {
        return this->replicaKmsKeyID.IsEmpty();
    }

    FAWSS3CRTEncryptionConfiguration &fromAWS(const Aws::S3Crt::Model::EncryptionConfiguration &awsEncryptionConfiguration) {
        this->replicaKmsKeyID = UTF8_TO_TCHAR(awsEncryptionConfiguration.GetReplicaKmsKeyID().c_str());

        return *this;
    }
#endif
};
