/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CopyObjectResultDetails.h"

#endif

#include "CopyObjectResultDetails.generated.h"

USTRUCT(BlueprintType)
struct FCopyObjectResultDetails {
GENERATED_BODY()

    /**
    *  <p>Returns the ETag of the new object. The ETag reflects only changes to the contents of an object, not its metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

    /**
    *  <p>Creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

    /**
    *  <p>The base64-encoded, 32-bit CRC32 checksum of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32;

    /**
    *  <p>The base64-encoded, 32-bit CRC32C checksum of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumCRC32C;

    /**
    *  <p>The base64-encoded, 160-bit SHA-1 digest of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA1;

    /**
    *  <p>The base64-encoded, 256-bit SHA-256 digest of the object. This will only be present if it was uploaded with the object. With multipart uploads, this may not be a checksum value of the object. For more information about how checksums are calculated with multipart uploads, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html#large-object-checksums"> Checking object integrity</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString checksumSHA256;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FCopyObjectResultDetails &fromAWS(const Aws::S3::Model::CopyObjectResultDetails &awsCopyObjectResultDetails) {
        this->eTag = UTF8_TO_TCHAR(awsCopyObjectResultDetails.GetETag().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsCopyObjectResultDetails.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->checksumCRC32 = UTF8_TO_TCHAR(awsCopyObjectResultDetails.GetChecksumCRC32().c_str());

        this->checksumCRC32C = UTF8_TO_TCHAR(awsCopyObjectResultDetails.GetChecksumCRC32C().c_str());

        this->checksumSHA1 = UTF8_TO_TCHAR(awsCopyObjectResultDetails.GetChecksumSHA1().c_str());

        this->checksumSHA256 = UTF8_TO_TCHAR(awsCopyObjectResultDetails.GetChecksumSHA256().c_str());

        return *this;
    }
#endif
};
