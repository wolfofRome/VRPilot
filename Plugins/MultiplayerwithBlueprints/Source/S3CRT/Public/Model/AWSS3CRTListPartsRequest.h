/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListPartsRequest.h"

#endif

#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTListPartsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListPartsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket to which the parts are being uploaded. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Sets the maximum number of parts to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int maxParts = 0;

    /**
    *  <p>Specifies the part after which listing should begin. Only parts with higher part numbers will be listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int partNumberMarker = 0;

    /**
    *  <p>Upload ID identifying the multipart upload whose parts are being listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uploadId;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ListPartsRequest toAWS() const {
        Aws::S3Crt::Model::ListPartsRequest awsListPartsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsListPartsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsListPartsRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->maxParts == 0)) {
            awsListPartsRequest.SetMaxParts(this->maxParts);
        }

        if (!(this->partNumberMarker == 0)) {
            awsListPartsRequest.SetPartNumberMarker(this->partNumberMarker);
        }

        if (!(this->uploadId.IsEmpty())) {
            awsListPartsRequest.SetUploadId(TCHAR_TO_UTF8(*this->uploadId));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsListPartsRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListPartsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListPartsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListPartsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->maxParts == 0 && this->partNumberMarker == 0 && this->uploadId.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
