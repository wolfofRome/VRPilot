
/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE

#include "aws/s3-encryption/materials/SimpleEncryptionMaterials.h"

#endif

#include "Utils/Crypto/Cipher.h"
#include "Utils/Crypto/EncryptionMaterials.h"

#include "SimpleEncryptionMaterials.generated.h"

/**
* Interface for symmetric encryption and decryption providers. An instance of this class is good for exactly one encryption or decryption run.
* It should not be used to encrypt or decrypt multiple messages.
*/
UCLASS(BlueprintType)
class S3ENCRYPTION_API USimpleEncryptionMaterials : public UEncryptionMaterials {
    GENERATED_BODY()

public:
    /**
    * Generates a non-deterministic random symmetric key. Default (and minimum bar for security) is 256 bits.
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption", Meta = (ExposeOnSpawn = true))
    FAWSByteBuffer symmetricKey;

public:
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    virtual std::shared_ptr<Aws::Utils::Crypto::EncryptionMaterials> toAWS() const override {
        return Aws::MakeShared<Aws::S3Encryption::Materials::SimpleEncryptionMaterialsWithGCMAAD>(
                "s3-encryption",
                symmetricKey.toAWS()
        );
    }
#endif

    virtual FString EncryptionMaterialsName() const override {
        return "Simple Encryption Materials";
    }
};
