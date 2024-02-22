/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutObjectAclRequest.h"

#endif

#include "Model/AWSS3CRTObjectCannedACL.h"
#include "Model/AWSS3CRTAccessControlPolicy.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTPutObjectAclRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutObjectAclRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/acl-overview.html#CannedACL">Canned ACL</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectCannedACL aCL = EAWSS3CRTObjectCannedACL::NOT_SET;

    /**
    *  <p>Contains the elements that set the ACL permissions for an object per grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAccessControlPolicy accessControlPolicy;

    /**
    *  <p>The bucket name that contains the object to which you want to attach the ACL. </p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the data. This header must be used as a message integrity check to verify that the request body was not corrupted in transit. For more information, go to <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864.&gt;</a> </p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    *  <p>Allows grantee the read, write, read ACP, and write ACP permissions on the bucket.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantFullControl;

    /**
    *  <p>Allows grantee to list the objects in the bucket.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantRead;

    /**
    *  <p>Allows grantee to read the bucket ACL.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantReadACP;

    /**
    *  <p>Allows grantee to create, overwrite, and delete any object in the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantWrite;

    /**
    *  <p>Allows grantee to write the ACL for the applicable bucket.</p> <p>This action is not supported by Amazon S3 on Outposts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantWriteACP;

    /**
    *  <p>Key for which the PUT action was initiated.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>VersionId used to reference a specific version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

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
    Aws::S3Crt::Model::PutObjectAclRequest toAWS() const {
        Aws::S3Crt::Model::PutObjectAclRequest awsPutObjectAclRequest;

        switch(this->aCL) {
            case EAWSS3CRTObjectCannedACL::private_:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::private_);
                break;
            case EAWSS3CRTObjectCannedACL::public_read:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::public_read);
                break;
            case EAWSS3CRTObjectCannedACL::public_read_write:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::public_read_write);
                break;
            case EAWSS3CRTObjectCannedACL::authenticated_read:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::authenticated_read);
                break;
            case EAWSS3CRTObjectCannedACL::aws_exec_read:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::aws_exec_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_read:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_read);
                break;
            case EAWSS3CRTObjectCannedACL::bucket_owner_full_control:
                awsPutObjectAclRequest.SetACL(Aws::S3Crt::Model::ObjectCannedACL::bucket_owner_full_control);
                break;
            default:
                break;
        }

        if (!(this->accessControlPolicy.IsEmpty())) {
            awsPutObjectAclRequest.SetAccessControlPolicy(this->accessControlPolicy.toAWS());
        }

        if (!(this->bucket.IsEmpty())) {
            awsPutObjectAclRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutObjectAclRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->grantFullControl.IsEmpty())) {
            awsPutObjectAclRequest.SetGrantFullControl(TCHAR_TO_UTF8(*this->grantFullControl));
        }

        if (!(this->grantRead.IsEmpty())) {
            awsPutObjectAclRequest.SetGrantRead(TCHAR_TO_UTF8(*this->grantRead));
        }

        if (!(this->grantReadACP.IsEmpty())) {
            awsPutObjectAclRequest.SetGrantReadACP(TCHAR_TO_UTF8(*this->grantReadACP));
        }

        if (!(this->grantWrite.IsEmpty())) {
            awsPutObjectAclRequest.SetGrantWrite(TCHAR_TO_UTF8(*this->grantWrite));
        }

        if (!(this->grantWriteACP.IsEmpty())) {
            awsPutObjectAclRequest.SetGrantWriteACP(TCHAR_TO_UTF8(*this->grantWriteACP));
        }

        if (!(this->key.IsEmpty())) {
            awsPutObjectAclRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsPutObjectAclRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->versionId.IsEmpty())) {
            awsPutObjectAclRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutObjectAclRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutObjectAclRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutObjectAclRequest;
    }

    bool IsEmpty() const {
        return this->aCL == EAWSS3CRTObjectCannedACL::NOT_SET && this->accessControlPolicy.IsEmpty() && this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWrite.IsEmpty() && this->grantWriteACP.IsEmpty() && this->key.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->versionId.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
