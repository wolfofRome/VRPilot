/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListPartsResult.h"

#endif

#include "Model/Part.h"
#include "Model/Initiator.h"
#include "Model/Owner.h"
#include "Model/AWSS3StorageClass.h"
#include "Model/RequestCharged.h"
#include "Model/AWSS3ChecksumAlgorithm.h"

#include "ListPartsResult.generated.h"

USTRUCT(BlueprintType)
struct FListPartsResult {
GENERATED_BODY()

    /**
    *  <p>If the bucket has a lifecycle rule configured with an action to abort incomplete multipart uploads and the prefix in the lifecycle rule matches the object name in the request, then the response includes this header indicating when the initiated multipart upload will become eligible for abort operation. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config">Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a>.</p> <p>The response will also include the <code>x-amz-abort-rule-id</code> header that will provide the ID of the lifecycle configuration rule that defines this action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime abortDate;

    /**
    *  <p>This header is returned along with the <code>x-amz-abort-date</code> header. It identifies applicable lifecycle configuration rule that defines the action to abort incomplete multipart uploads.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString abortRuleId;

    /**
    *  <p>The name of the bucket to which the multipart upload was initiated. Does not return the access point ARN or access point alias if used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>Upload ID identifying the multipart upload whose parts are being listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uploadId;

    /**
    *  <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the part-number-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partNumberMarker = 0;

    /**
    *  <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the part-number-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int nextPartNumberMarker = 0;

    /**
    *  <p>Maximum number of parts that were allowed in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxParts = 0;

    /**
    *  <p> Indicates whether the returned list of parts is truncated. A true value indicates that the list was truncated. A list can be truncated if the number of parts exceeds the limit returned in the MaxParts element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p> Container for elements related to a particular part. A response can contain zero or more <code>Part</code> elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FPart> parts;

    /**
    *  <p>Container element that identifies who initiated the multipart upload. If the initiator is an Amazon Web Services account, this element provides the same information as the <code>Owner</code> element. If the initiator is an IAM User, this element provides the user ARN and display name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInitiator initiator;

    /**
    *  <p> Container element that identifies the object owner, after the object is created. If multipart upload is initiated by an IAM user, this element provides the parent account ID and display name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

    /**
    *  <p>Class of storage (STANDARD or REDUCED_REDUNDANCY) used to store the uploaded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClass storageClass = EAWSS3StorageClass::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>The algorithm that was used to create a checksum of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ChecksumAlgorithm checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListPartsResult &fromAWS(const Aws::S3::Model::ListPartsResult &awsListPartsResult) {
        this->abortDate = FDateTime(1970, 1, 1) + FTimespan(awsListPartsResult.GetAbortDate().Millis() * ETimespan::TicksPerMillisecond);

        this->abortRuleId = UTF8_TO_TCHAR(awsListPartsResult.GetAbortRuleId().c_str());

        this->bucket = UTF8_TO_TCHAR(awsListPartsResult.GetBucket().c_str());

        this->key = UTF8_TO_TCHAR(awsListPartsResult.GetKey().c_str());

        this->uploadId = UTF8_TO_TCHAR(awsListPartsResult.GetUploadId().c_str());

		this->partNumberMarker = awsListPartsResult.GetPartNumberMarker();

		this->nextPartNumberMarker = awsListPartsResult.GetNextPartNumberMarker();

		this->maxParts = awsListPartsResult.GetMaxParts();

        this->isTruncated = awsListPartsResult.GetIsTruncated();

        this->parts.Empty();
        for (const Aws::S3::Model::Part& elem : awsListPartsResult.GetParts()) {
            this->parts.Add(FPart().fromAWS(elem));
        }

        this->initiator.fromAWS(awsListPartsResult.GetInitiator());
        

        this->owner.fromAWS(awsListPartsResult.GetOwner());

        switch(awsListPartsResult.GetStorageClass()) {
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

        switch(awsListPartsResult.GetRequestCharged()) {
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

        switch(awsListPartsResult.GetChecksumAlgorithm()) {
            case Aws::S3::Model::ChecksumAlgorithm::NOT_SET:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::CRC32:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::CRC32;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::CRC32C:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::CRC32C;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::SHA1:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::SHA1;
                break;
            case Aws::S3::Model::ChecksumAlgorithm::SHA256:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::SHA256;
                break;
            default:
                this->checksumAlgorithm = EAWSS3ChecksumAlgorithm::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
