/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CompletedPart.h"

#endif


#include "CompletedPart.generated.h"

USTRUCT(BlueprintType)
struct FCompletedPart {
GENERATED_BODY()

    /**
    *  <p>Entity tag returned when the part was uploaded.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

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

    /**
    *  <p>Part number that identifies the part. This is a positive integer between 1 and 10,000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partNumber = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CompletedPart toAWS() const {
        Aws::S3::Model::CompletedPart awsCompletedPart;

		if (!(this->eTag.IsEmpty())) {
            awsCompletedPart.SetETag(TCHAR_TO_UTF8(*this->eTag));
        }

		if (!(this->checksumCRC32.IsEmpty())) {
            awsCompletedPart.SetChecksumCRC32(TCHAR_TO_UTF8(*this->checksumCRC32));
        }

        if (!(this->checksumCRC32C.IsEmpty())) {
            awsCompletedPart.SetChecksumCRC32C(TCHAR_TO_UTF8(*this->checksumCRC32C));
        }

        if (!(this->checksumSHA1.IsEmpty())) {
            awsCompletedPart.SetChecksumSHA1(TCHAR_TO_UTF8(*this->checksumSHA1));
        }

        if (!(this->checksumSHA256.IsEmpty())) {
            awsCompletedPart.SetChecksumSHA256(TCHAR_TO_UTF8(*this->checksumSHA256));
        }

        if (!(this->partNumber == 0)) {
            awsCompletedPart.SetPartNumber(this->partNumber);
        }

        return awsCompletedPart;
    }

    bool IsEmpty() const {
        return this->eTag.IsEmpty() && this->checksumCRC32.IsEmpty() && this->checksumCRC32C.IsEmpty() && this->checksumSHA1.IsEmpty() && this->checksumSHA256.IsEmpty() && this->partNumber == 0;
    }
#endif
};
