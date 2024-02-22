/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutObjectTaggingRequest.h"

#endif

#include "Model/AWSS3CRTTagging.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTPutObjectTaggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutObjectTaggingRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name containing the object. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Name of the object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>The versionId of the object that the tag-set will be added to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>The MD5 hash for the request body.</p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    *  <p>Container for the <code>TagSet</code> and <code>Tag</code> elements</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTagging tagging;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expectedBucketOwner;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::PutObjectTaggingRequest toAWS() const {
        Aws::S3Crt::Model::PutObjectTaggingRequest awsPutObjectTaggingRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutObjectTaggingRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsPutObjectTaggingRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->versionId.IsEmpty())) {
            awsPutObjectTaggingRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutObjectTaggingRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->tagging.IsEmpty())) {
            awsPutObjectTaggingRequest.SetTagging(this->tagging.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutObjectTaggingRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsPutObjectTaggingRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutObjectTaggingRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutObjectTaggingRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->versionId.IsEmpty() && this->contentMD5.IsEmpty() && this->tagging.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
