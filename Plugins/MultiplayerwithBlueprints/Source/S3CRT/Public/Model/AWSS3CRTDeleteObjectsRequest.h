/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteObjectsRequest.h"

#endif

#include "Model/AWSS3CRTDelete.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTDeleteObjectsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteObjectsRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name containing the objects to delete. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>Container for the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTDelete deleteObjects;

    /**
    *  <p>The concatenation of the authentication device's serial number, a space, and the value that is displayed on your authentication device. Required to permanently delete a versioned object if versioning is configured with MFA delete enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString mFA;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>Specifies whether you want to delete this object even if it has a Governance-type Object Lock in place. You must have sufficient permissions to perform this operation.</p>
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
    Aws::S3Crt::Model::DeleteObjectsRequest toAWS() const {
        Aws::S3Crt::Model::DeleteObjectsRequest awsDeleteObjectsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsDeleteObjectsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->deleteObjects.IsEmpty())) {
            awsDeleteObjectsRequest.SetDelete(this->deleteObjects.toAWS());
        }

        if (!(this->mFA.IsEmpty())) {
            awsDeleteObjectsRequest.SetMFA(TCHAR_TO_UTF8(*this->mFA));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsDeleteObjectsRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(false)) {
            awsDeleteObjectsRequest.SetBypassGovernanceRetention(this->bypassGovernanceRetention);
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeleteObjectsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteObjectsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteObjectsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->deleteObjects.IsEmpty() && this->mFA.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && false && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
