/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CompleteMultipartUploadRequest.h"

#endif

#include "Model/AWSS3CRTCompletedMultipartUpload.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTCompleteMultipartUploadRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCompleteMultipartUploadRequest {
GENERATED_BODY()

    /**
    *  <p>Name of the bucket to which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Object key for which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>The container for the multipart upload request information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCompletedMultipartUpload multipartUpload;

    /**
    *  <p>ID for the initiated multipart upload.</p>
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
    Aws::S3Crt::Model::CompleteMultipartUploadRequest toAWS() const {
        Aws::S3Crt::Model::CompleteMultipartUploadRequest awsCompleteMultipartUploadRequest;

        if (!(this->bucket.IsEmpty())) {
            awsCompleteMultipartUploadRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsCompleteMultipartUploadRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->multipartUpload.IsEmpty())) {
            awsCompleteMultipartUploadRequest.SetMultipartUpload(this->multipartUpload.toAWS());
        }

        if (!(this->uploadId.IsEmpty())) {
            awsCompleteMultipartUploadRequest.SetUploadId(TCHAR_TO_UTF8(*this->uploadId));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsCompleteMultipartUploadRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsCompleteMultipartUploadRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsCompleteMultipartUploadRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }
        return awsCompleteMultipartUploadRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->multipartUpload.IsEmpty() && this->uploadId.IsEmpty() && requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
