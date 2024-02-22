/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Encryption.h"

#endif

#include "Model/AWSS3CRTServerSideEncryption.h"

#include "AWSS3CRTEncryption.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTEncryption {
GENERATED_BODY()

    /**
    *  <p>The server-side encryption algorithm used when storing job results in Amazon S3 (for example, AES256, aws:kms).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTServerSideEncryption encryptionType = EAWSS3CRTServerSideEncryption::NOT_SET;

    /**
    *  <p>If the encryption type is <code>aws:kms</code>, this optional value specifies the ID of the symmetric customer managed AWS KMS CMK to use for encryption of job results. Amazon S3 only supports symmetric CMKs. For more information, see <a href="https://docs.aws.amazon.com/kms/latest/developerguide/symmetric-asymmetric.html">Using Symmetric and Asymmetric Keys</a> in the <i>AWS Key Management Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString kMSKeyId;

    /**
    *  <p>If the encryption type is <code>aws:kms</code>, this optional value can be used to specify the encryption context for the restore results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString kMSContext;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Encryption toAWS() const {
        Aws::S3Crt::Model::Encryption awsEncryption;

        switch(this->encryptionType) {
            case EAWSS3CRTServerSideEncryption::AES256:
                awsEncryption.SetEncryptionType(Aws::S3Crt::Model::ServerSideEncryption::AES256);
                break;
            case EAWSS3CRTServerSideEncryption::aws_kms:
                awsEncryption.SetEncryptionType(Aws::S3Crt::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

        if (!(this->kMSKeyId.IsEmpty())) {
            awsEncryption.SetKMSKeyId(TCHAR_TO_UTF8(*this->kMSKeyId));
        }

        if (!(this->kMSContext.IsEmpty())) {
            awsEncryption.SetKMSContext(TCHAR_TO_UTF8(*this->kMSContext));
        }

        return awsEncryption;
    }

    bool IsEmpty() const {
        return this->encryptionType == EAWSS3CRTServerSideEncryption::NOT_SET && this->kMSKeyId.IsEmpty() && this->kMSContext.IsEmpty();
    }
#endif
};
