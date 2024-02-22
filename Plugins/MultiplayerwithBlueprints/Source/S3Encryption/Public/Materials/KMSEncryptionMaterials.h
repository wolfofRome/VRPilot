/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE

#include "aws/s3-encryption/materials/KMSEncryptionMaterials.h"

#endif

#include "Client/AWSClientConfiguration.h"
#include "Utils/Crypto/EncryptionMaterials.h"

#include "KMSEncryptionMaterials.generated.h"

/**
* Interface for symmetric encryption and decryption providers. An instance of this class is good for exactly one encryption or decryption run.
* It should not be used to encrypt or decrypt multiple messages.
*/
UCLASS(BlueprintType)
class S3ENCRYPTION_API UKMSEncryptionMaterials : public UEncryptionMaterials {
    GENERATED_BODY()

public:
    /**
     * for kms encryption material
     **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption", Meta = (ExposeOnSpawn = true))
    FString customerMasterKeyID;

    /**
     * for kms encryption material
     **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption", Meta = (ExposeOnSpawn = true))
    FAWSClientConfiguration clientConfig;

public:
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    virtual std::shared_ptr<Aws::Utils::Crypto::EncryptionMaterials> toAWS() const override {
        return Aws::MakeShared<Aws::S3Encryption::Materials::KMSWithContextEncryptionMaterials>(
                "Encryption Materials",
                TCHAR_TO_UTF8(*this->customerMasterKeyID),
                this->clientConfig.toAWS()
        );
    }
#endif

    virtual FString EncryptionMaterialsName() const override {
        return "KMS Encryption Materials";
    }
};
