/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteObjectRequest.h"

#endif

#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTDeleteObjectRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteObjectRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name of the bucket containing the object. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Key name of the object to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>The concatenation of the authentication device's serial number, a space, and the value that is displayed on your authentication device. Required to permanently delete a versioned object if versioning is configured with MFA delete enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString mFA;

    /**
    *  <p>VersionId used to reference a specific version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>Indicates whether S3 Object Lock should bypass Governance-mode restrictions to process this operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bypassGovernanceRetention = false;

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
    Aws::S3Crt::Model::DeleteObjectRequest toAWS() const {
        Aws::S3Crt::Model::DeleteObjectRequest awsDeleteObjectRequest;

        if (!(this->bucket.IsEmpty())) {
            awsDeleteObjectRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsDeleteObjectRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->mFA.IsEmpty())) {
            awsDeleteObjectRequest.SetMFA(TCHAR_TO_UTF8(*this->mFA));
        }

        if (!(this->versionId.IsEmpty())) {
            awsDeleteObjectRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsDeleteObjectRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(false)) {
            awsDeleteObjectRequest.SetBypassGovernanceRetention(this->bypassGovernanceRetention);
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeleteObjectRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteObjectRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteObjectRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->mFA.IsEmpty() && this->versionId.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && false && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
