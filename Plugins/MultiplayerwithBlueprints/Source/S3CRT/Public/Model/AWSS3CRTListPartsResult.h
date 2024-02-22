/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListPartsResult.h"

#endif

#include "Model/AWSS3CRTPart.h"
#include "Model/AWSS3CRTInitiator.h"
#include "Model/AWSS3CRTOwner.h"
#include "Model/AWSS3CRTStorageClass.h"
#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTListPartsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListPartsResult {
GENERATED_BODY()

    /**
    *  <p>If the bucket has a lifecycle rule configured with an action to abort incomplete multipart uploads and the prefix in the lifecycle rule matches the object name in the request, then the response includes this header indicating when the initiated multipart upload will become eligible for abort operation. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config">Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a>.</p> <p>The response will also include the <code>x-amz-abort-rule-id</code> header that will provide the ID of the lifecycle configuration rule that defines this action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime abortDate;

    /**
    *  <p>This header is returned along with the <code>x-amz-abort-date</code> header. It identifies applicable lifecycle configuration rule that defines the action to abort incomplete multipart uploads.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString abortRuleId;

    /**
    *  <p>The name of the bucket to which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Upload ID identifying the multipart upload whose parts are being listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uploadId;

    /**
    *  <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the part-number-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partNumberMarker = 0;

    /**
    *  <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the part-number-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int nextPartNumberMarker = 0;

    /**
    *  <p>Maximum number of parts that were allowed in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int maxParts = 0;

    /**
    *  <p> Indicates whether the returned list of parts is truncated. A true value indicates that the list was truncated. A list can be truncated if the number of parts exceeds the limit returned in the MaxParts element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p> Container for elements related to a particular part. A response can contain zero or more <code>Part</code> elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTPart> parts;

    /**
    *  <p>Container element that identifies who initiated the multipart upload. If the initiator is an AWS account, this element provides the same information as the <code>Owner</code> element. If the initiator is an IAM User, this element provides the user ARN and display name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInitiator initiator;

    /**
    *  <p> Container element that identifies the object owner, after the object is created. If multipart upload is initiated by an IAM user, this element provides the parent account ID and display name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

    /**
    *  <p>Class of storage (STANDARD or REDUCED_REDUNDANCY) used to store the uploaded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClass storageClass = EAWSS3CRTStorageClass::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListPartsResult &fromAWS(const Aws::S3Crt::Model::ListPartsResult &awsListPartsResult) {
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
        for (const Aws::S3Crt::Model::Part& elem : awsListPartsResult.GetParts()) {
            this->parts.Add(FAWSS3CRTPart().fromAWS(elem));
        }

        this->initiator = FAWSS3CRTInitiator().fromAWS(awsListPartsResult.GetInitiator());

        this->owner = FAWSS3CRTOwner().fromAWS(awsListPartsResult.GetOwner());
        
        switch(awsListPartsResult.GetStorageClass()) {
            case Aws::S3Crt::Model::StorageClass::NOT_SET:
                this->storageClass = EAWSS3CRTStorageClass::NOT_SET;
                break;
            case Aws::S3Crt::Model::StorageClass::STANDARD:
                this->storageClass = EAWSS3CRTStorageClass::STANDARD;
                break;
            case Aws::S3Crt::Model::StorageClass::REDUCED_REDUNDANCY:
                this->storageClass = EAWSS3CRTStorageClass::REDUCED_REDUNDANCY;
                break;
            case Aws::S3Crt::Model::StorageClass::STANDARD_IA:
                this->storageClass = EAWSS3CRTStorageClass::STANDARD_IA;
                break;
            case Aws::S3Crt::Model::StorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3CRTStorageClass::ONEZONE_IA;
                break;
            case Aws::S3Crt::Model::StorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3CRTStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Crt::Model::StorageClass::GLACIER:
                this->storageClass = EAWSS3CRTStorageClass::GLACIER;
                break;
            case Aws::S3Crt::Model::StorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3CRTStorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3Crt::Model::StorageClass::OUTPOSTS:
                this->storageClass = EAWSS3CRTStorageClass::OUTPOSTS;
                break;
            default:
                this->storageClass = EAWSS3CRTStorageClass::NOT_SET;
                break;
        }

        switch(awsListPartsResult.GetRequestCharged()) {
            case Aws::S3Crt::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
            case Aws::S3Crt::Model::RequestCharged::requester:
                this->requestCharged = EAWSS3CRTRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
