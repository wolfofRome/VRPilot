/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetObjectAclRequest.h"

#endif

#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTGetObjectAclRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectAclRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name that contains the object for which to get the ACL information. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The key of the object for which to get the ACL information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

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
    Aws::S3Crt::Model::GetObjectAclRequest toAWS() const {
        Aws::S3Crt::Model::GetObjectAclRequest awsGetObjectAclRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetObjectAclRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsGetObjectAclRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->versionId.IsEmpty())) {
            awsGetObjectAclRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsGetObjectAclRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetObjectAclRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetObjectAclRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetObjectAclRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->versionId.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
