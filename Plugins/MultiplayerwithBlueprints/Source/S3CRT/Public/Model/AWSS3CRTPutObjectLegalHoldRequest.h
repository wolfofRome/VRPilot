/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutObjectLegalHoldRequest.h"

#endif

#include "Model/AWSS3CRTObjectLockLegalHold.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTPutObjectLegalHoldRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutObjectLegalHoldRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name containing the object that you want to place a Legal Hold on. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The key name for the object that you want to place a Legal Hold on.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>Container element for the Legal Hold configuration you want to apply to the specified object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTObjectLockLegalHold legalHold;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>The version ID of the object that you want to place a Legal Hold on.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    *  <p>The MD5 hash for the request body.</p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

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
    Aws::S3Crt::Model::PutObjectLegalHoldRequest toAWS() const {
        Aws::S3Crt::Model::PutObjectLegalHoldRequest awsPutObjectLegalHoldRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->legalHold.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetLegalHold(this->legalHold.toAWS());
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsPutObjectLegalHoldRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->versionId.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutObjectLegalHoldRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutObjectLegalHoldRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutObjectLegalHoldRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->legalHold.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->versionId.IsEmpty() && this->contentMD5.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
