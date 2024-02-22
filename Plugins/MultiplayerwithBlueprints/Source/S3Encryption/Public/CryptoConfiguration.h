/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"
#include "Misc/CString.h"

#if WITH_S3ENCRYPTIONCLIENTSDK

#include "aws/s3-encryption/CryptoConfiguration.h"

#endif

#include "Utils/Crypto/EncryptionMaterials.h"
#include "Client/AWSClientConfiguration.h"

#include "CryptoConfiguration.generated.h"

UENUM(BlueprintType)
enum class EStorageMethod : uint8 {
    METADATA UMETA(DisplayName = "metadata"),
    INSTRUCTION_FILE UMETA(DisplayName = "instruction file"),
};

UENUM(BlueprintType)
enum class ERangeGetMode : uint8 {
    DISABLED UMETA(DisplayName = "disabled"),
    ALL UMETA(DisplayName = "all"),
};

UENUM(BlueprintType)
enum class ESecurityProfile : uint8 {
    V2 UMETA(DisplayName = "v2"),
    V2_AND_LEGACY UMETA(DisplayName = "v2 and legacy"),
};

USTRUCT(BlueprintType)
struct FCryptoConfiguration {
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption")
    ESecurityProfile profile = ESecurityProfile::V2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption")
    ERangeGetMode mode = ERangeGetMode::DISABLED;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption")
    EStorageMethod storageMethod = EStorageMethod::METADATA;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3 Encryption")
    UEncryptionMaterials* materials = nullptr;

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
public:
    Aws::S3Encryption::CryptoConfigurationV2 toAWS() const {
        if (this->materials->EncryptionMaterialsName().Equals("KMS Encryption Materials", ESearchCase::CaseSensitive)) {
            Aws::S3Encryption::CryptoConfigurationV2 awsCryptoConfigurationV2(
                        std::static_pointer_cast<Aws::S3Encryption::Materials::KMSWithContextEncryptionMaterials>(this->materials->toAWS())
                );

                switch (this->profile) {
                    case ESecurityProfile::V2:
                        awsCryptoConfigurationV2.SetSecurityProfile(Aws::S3Encryption::SecurityProfile::V2);
                        break;
                    case ESecurityProfile::V2_AND_LEGACY:
                        awsCryptoConfigurationV2.SetSecurityProfile(Aws::S3Encryption::SecurityProfile::V2_AND_LEGACY);
                        break;
                }

                switch (this->mode) {
                    case ERangeGetMode::DISABLED:
                        awsCryptoConfigurationV2.SetUnAuthenticatedRangeGet(Aws::S3Encryption::RangeGetMode::DISABLED);
                        break;
                    case ERangeGetMode::ALL:
                        awsCryptoConfigurationV2.SetUnAuthenticatedRangeGet(Aws::S3Encryption::RangeGetMode::ALL);
                        break;
                }

                switch (this->storageMethod) {
                    case EStorageMethod::METADATA:
                        awsCryptoConfigurationV2.SetStorageMethod(Aws::S3Encryption::StorageMethod::METADATA);
                        break;
                    case EStorageMethod::INSTRUCTION_FILE:
                        awsCryptoConfigurationV2.SetStorageMethod(Aws::S3Encryption::StorageMethod::INSTRUCTION_FILE);
                        break;
                }

                return awsCryptoConfigurationV2;
        } else {
            Aws::S3Encryption::CryptoConfigurationV2 awsCryptoConfigurationV2(
                        std::static_pointer_cast<Aws::S3Encryption::Materials::SimpleEncryptionMaterialsWithGCMAAD>(this->materials->toAWS())
                );

                switch (this->profile) {
                    case ESecurityProfile::V2:
                        awsCryptoConfigurationV2.SetSecurityProfile(Aws::S3Encryption::SecurityProfile::V2);
                        break;
                    case ESecurityProfile::V2_AND_LEGACY:
                        awsCryptoConfigurationV2.SetSecurityProfile(Aws::S3Encryption::SecurityProfile::V2_AND_LEGACY);
                        break;
                }

                switch (this->mode) {
                    case ERangeGetMode::DISABLED:
                        awsCryptoConfigurationV2.SetUnAuthenticatedRangeGet(Aws::S3Encryption::RangeGetMode::DISABLED);
                        break;
                    case ERangeGetMode::ALL:
                        awsCryptoConfigurationV2.SetUnAuthenticatedRangeGet(Aws::S3Encryption::RangeGetMode::ALL);
                        break;
                }

                switch (this->storageMethod) {
                    case EStorageMethod::METADATA:
                        awsCryptoConfigurationV2.SetStorageMethod(Aws::S3Encryption::StorageMethod::METADATA);
                        break;
                    case EStorageMethod::INSTRUCTION_FILE:
                        awsCryptoConfigurationV2.SetStorageMethod(Aws::S3Encryption::StorageMethod::INSTRUCTION_FILE);
                        break;
                }

                return awsCryptoConfigurationV2;
        }
    };
#endif
};
