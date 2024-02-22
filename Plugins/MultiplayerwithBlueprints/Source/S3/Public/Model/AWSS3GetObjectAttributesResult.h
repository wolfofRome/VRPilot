/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectAttributesResult.h"

#endif

#include "Model/RequestCharged.h"
#include "Model/AWSS3Checksum.h"
#include "Model/AWSS3GetObjectAttributesParts.h"
#include "Model/AWSS3StorageClass.h"

#include "AWSS3GetObjectAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3GetObjectAttributesResult {
GENERATED_BODY()

    /**
    *  <p>Specifies whether the object retrieved was (<code>true</code>) or was not (<code>false</code>) a delete marker. If <code>false</code>, this response header does not appear in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool deleteMarker = false;

    /**
    *  <p>The creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime lastModified;

    /**
    *  <p>The version ID of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString eTag;

    /**
    *  <p>The checksum or digest of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3Checksum checksum;

    /**
    *  <p>A collection of parts associated with a multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3GetObjectAttributesParts objectParts;

    /**
    *  <p>Provides the storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    *  <p>The size of the object in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 objectSize = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FAWSS3GetObjectAttributesResult &fromAWS(const Aws::S3::Model::GetObjectAttributesResult &awsGetObjectAttributesResult) {
        this->deleteMarker = awsGetObjectAttributesResult.GetDeleteMarker();

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsGetObjectAttributesResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->versionId = UTF8_TO_TCHAR(awsGetObjectAttributesResult.GetVersionId().c_str());

        switch(awsGetObjectAttributesResult.GetRequestCharged()) {
            case Aws::S3::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
            case Aws::S3::Model::RequestCharged::requester:
                this->requestCharged = EAWSRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
        }

        this->eTag = UTF8_TO_TCHAR(awsGetObjectAttributesResult.GetETag().c_str());

        this->checksum.fromAWS(awsGetObjectAttributesResult.GetChecksum());

        this->objectParts.fromAWS(awsGetObjectAttributesResult.GetObjectParts());

        switch(awsGetObjectAttributesResult.GetStorageClass()) {
            case Aws::S3::Model::StorageClass::NOT_SET:
                this->storageClass = EAWSS3StorageClass::NOT_SET;
                break;
            case Aws::S3::Model::StorageClass::STANDARD:
                this->storageClass = EAWSS3StorageClass::STANDARD;
                break;
            case Aws::S3::Model::StorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3StorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3::Model::StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3StorageClass::STANDARD_IA;
                break;
            case Aws::S3::Model::StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3StorageClass::ONEZONE_IA;
                break;
            case Aws::S3::Model::StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3StorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3::Model::StorageClass::GLACIER:
                this->storageClass = EAWSS3StorageClass::GLACIER;
                break;
            case Aws::S3::Model::StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3StorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3::Model::StorageClass::OUTPOSTS:
                this->storageClass = EAWSS3StorageClass::OUTPOSTS;
                break;
            case Aws::S3::Model::StorageClass::GLACIER_IR:
                this->storageClass = EAWSS3StorageClass::GLACIER_IR;
                break;
            default:
                this->storageClass = EAWSS3StorageClass::NOT_SET;
                break;
        }

        this->objectSize = (int64)awsGetObjectAttributesResult.GetObjectSize();

        return *this;
    }
#endif
};
