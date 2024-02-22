/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "Auth/AWSCoreCredentials.h"
#include "Client/AWSClientConfiguration.h"

#include "S3EncryptionError.h"

#include "CryptoConfiguration.h"

#include "Model/PutObjectRequest.h"
#include "Model/GetObjectRequest.h"

#include "Model/PutObjectResult.h"
#include "Model/GetObjectResult.h"

#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE

#include "aws/s3-encryption/S3EncryptionClient.h"

#endif

#include "S3EncryptionClientObject.generated.h"

/**
* S3EncryptionClientV2 enforce the secure postures for customers. See https://docs.aws.amazon.com/general/latest/gr/aws_sdk_cryptography.html
* Examples: https://github.com/awsdocs/aws-doc-sdk-examples/blob/master/cpp/example_code/s3encryption/s3Encryption.cpp
**/
UCLASS(BlueprintType)
class S3ENCRYPTION_API US3EncryptionClientObject : public UObject {
    GENERATED_BODY()

public:
#if WITH_S3ENCRYPTIONCLIENTSDK && WITH_CORE
    Aws::S3Encryption::S3EncryptionClientV2 *awsS3EncryptionClient;
#endif

    /**
    * public static US3EncryptionClientObject::CreateS3EncryptionObject
    * Creates a S3EncryptionClientObject. This function must be called first before accessing any S3Encryption client functions.
    * @param cryptoConfig [FCryptoConfiguration] .
    * @param credentials [FAWSCredentials] .
    * @param clientConfiguration [FClientConfiguration] .
    * @return [US3EncryptionClient*] Returns US3EncryptionClient*.
    **/
    UFUNCTION(BlueprintCallable, Category = "S3 Encryption Client")
    static US3EncryptionClientObject *
    CreateS3EncryptionObject(const FCryptoConfiguration &cryptoConfig, const FAWSCredentials &credentials, const FAWSClientConfiguration &clientConfiguration);

    /**
    *  Function to put an object encrypted to S3.
    * For KMS encryption materials, you can provide a context map as the KMS context for encrypting the CEK.
    * For other encryption materials, this context map must be an empty map.
    * @param putObjectRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
              meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
              Category = "S3 Encryption Client")
    void PutObject (
            UObject *WorldContextObject,
            bool &success,
            FPutObjectRequest putObjectRequest,
            TMap<FString, FString> contextMap,
            FPutObjectResult &putObjectResult,
            ES3EncryptionError &errorType,
            FString &errorMessage,
            struct FLatentActionInfo LatentInfo
    );

    /**
    *  Function to get an object decrypted from S3.
    *
    * Range gets using this method are deprecated. Please see
    * <https://docs.aws.amazon.com/general/latest/gr/aws_sdk_cryptography.html> for more information
    * @param
    * @param getObjectRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
          meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
          Category = "S3 Encryption Client")
    void GetObject (
        UObject *WorldContextObject,
        bool &success,
        FGetObjectRequest getObjectRequest,
        FGetObjectResult &getObjectResult,
        ES3EncryptionError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );

    /**
    * @return [bool] Returns .
    **/
    UFUNCTION(BlueprintCallable, Category = "S3 Encryption Client")
    bool
    MultipartUploadSupported() const;
};
