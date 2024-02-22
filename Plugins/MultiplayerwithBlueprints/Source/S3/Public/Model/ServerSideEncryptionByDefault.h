/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ServerSideEncryptionByDefault.h"

#endif

#include "Model/ServerSideEncryption.h"

#include "ServerSideEncryptionByDefault.generated.h"

USTRUCT(BlueprintType)
struct FServerSideEncryptionByDefault {
GENERATED_BODY()

    /**
    *  <p>Server-side encryption algorithm to use for the default encryption.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSServerSideEncryption SSEAlgorithm = EAWSServerSideEncryption::NOT_SET;

    /**
    *  <p>AWS Key Management Service (KMS) customer master key ID to use for the default encryption. This parameter is allowed if and only if <code>SSEAlgorithm</code> is set to <code>aws:kms</code>.</p> <p>You can specify the key ID or the Amazon Resource Name (ARN) of the CMK. However, if you are using encryption with cross-account operations, you must use a fully qualified CMK ARN. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/bucket-encryption.html#bucket-encryption-update-bucket-policy">Using encryption for cross-account operations</a>. </p> <p> <b>For example:</b> </p> <ul> <li> <p>Key ID: <code>1234abcd-12ab-34cd-56ef-1234567890ab</code> </p> </li> <li> <p>Key ARN: <code>arn:aws:kms:us-east-2:111122223333:key/1234abcd-12ab-34cd-56ef-1234567890ab</code> </p> </li> </ul>  <p>Amazon S3 only supports symmetric CMKs and not asymmetric CMKs. For more information, see <a href="https://docs.aws.amazon.com/kms/latest/developerguide/symmetric-asymmetric.html">Using Symmetric and Asymmetric Keys</a> in the <i>AWS Key Management Service Developer Guide</i>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString kMSMasterKeyID;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ServerSideEncryptionByDefault toAWS() const {
        Aws::S3::Model::ServerSideEncryptionByDefault awsServerSideEncryptionByDefault;

        switch(this->SSEAlgorithm) {
            case EAWSServerSideEncryption::AES256:
                awsServerSideEncryptionByDefault.SetSSEAlgorithm(Aws::S3::Model::ServerSideEncryption::AES256);
                break;
            case EAWSServerSideEncryption::aws_kms:
                awsServerSideEncryptionByDefault.SetSSEAlgorithm(Aws::S3::Model::ServerSideEncryption::aws_kms);
                break;
            default:
                break;
        }

		if (!(this->kMSMasterKeyID.IsEmpty())) {
            awsServerSideEncryptionByDefault.SetKMSMasterKeyID(TCHAR_TO_UTF8(*this->kMSMasterKeyID));
        }

        return awsServerSideEncryptionByDefault;
    }

    bool IsEmpty() const {
        return SSEAlgorithm == EAWSServerSideEncryption::NOT_SET && this->kMSMasterKeyID.IsEmpty();
    }

    FServerSideEncryptionByDefault &fromAWS(const Aws::S3::Model::ServerSideEncryptionByDefault &awsServerSideEncryptionByDefault) {
        switch(awsServerSideEncryptionByDefault.GetSSEAlgorithm()) {
            case Aws::S3::Model::ServerSideEncryption::NOT_SET:
                this->SSEAlgorithm = EAWSServerSideEncryption::NOT_SET;
                break;
            case Aws::S3::Model::ServerSideEncryption::AES256:
                this->SSEAlgorithm = EAWSServerSideEncryption::AES256;
                break;
            case Aws::S3::Model::ServerSideEncryption::aws_kms:
                this->SSEAlgorithm = EAWSServerSideEncryption::aws_kms;
                break;
            default:
                this->SSEAlgorithm = EAWSServerSideEncryption::NOT_SET;
                break;
        }

        this->kMSMasterKeyID = UTF8_TO_TCHAR(awsServerSideEncryptionByDefault.GetKMSMasterKeyID().c_str());

        return *this;
    }
#endif
};