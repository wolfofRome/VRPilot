/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutBucketAclRequest.h"

#endif

#include "Model/AWSS3CRTBucketCannedACL.h"
#include "Model/AWSS3CRTAccessControlPolicy.h"

#include "AWSS3CRTPutBucketAclRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutBucketAclRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketCannedACL aCL = EAWSS3CRTBucketCannedACL::NOT_SET;

    /**
    *  <p>Contains the elements that set the ACL permissions for an object per grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAccessControlPolicy accessControlPolicy;

    /**
    *  <p>The bucket to which to apply the ACL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The base64-encoded 128-bit MD5 digest of the data. This header must be used as a message integrity check to verify that the request body was not corrupted in transit. For more information, go to <a href="http://www.ietf.org/rfc/rfc1864.txt">RFC 1864.</a> </p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString contentMD5;

    /**
    *  <p>Allows grantee the read, write, read ACP, and write ACP permissions on the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantFullControl;

    /**
    *  <p>Allows grantee to list the objects in the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantRead;

    /**
    *  <p>Allows grantee to read the bucket ACL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantReadACP;

    /**
    *  <p>Allows grantee to create, overwrite, and delete any object in the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantWrite;

    /**
    *  <p>Allows grantee to write the ACL for the applicable bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString grantWriteACP;

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
    Aws::S3Crt::Model::PutBucketAclRequest toAWS() const {
        Aws::S3Crt::Model::PutBucketAclRequest awsPutBucketAclRequest;

        switch(this->aCL) {
            case EAWSS3CRTBucketCannedACL::private_:
                awsPutBucketAclRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::private_);
                break;
            case EAWSS3CRTBucketCannedACL::public_read:
                awsPutBucketAclRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::public_read);
                break;
            case EAWSS3CRTBucketCannedACL::public_read_write:
                awsPutBucketAclRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::public_read_write);
                break;
            case EAWSS3CRTBucketCannedACL::authenticated_read:
                awsPutBucketAclRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::authenticated_read);
                break;
            default:
                break;
        }

        if (!(this->accessControlPolicy.IsEmpty())) {
            awsPutBucketAclRequest.SetAccessControlPolicy(this->accessControlPolicy.toAWS());
        }

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketAclRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketAclRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->grantFullControl.IsEmpty())) {
            awsPutBucketAclRequest.SetGrantFullControl(TCHAR_TO_UTF8(*this->grantFullControl));
        }

        if (!(this->grantRead.IsEmpty())) {
            awsPutBucketAclRequest.SetGrantRead(TCHAR_TO_UTF8(*this->grantRead));
        }

        if (!(this->grantReadACP.IsEmpty())) {
            awsPutBucketAclRequest.SetGrantReadACP(TCHAR_TO_UTF8(*this->grantReadACP));
        }

        if (!(this->grantWrite.IsEmpty())) {
            awsPutBucketAclRequest.SetGrantWrite(TCHAR_TO_UTF8(*this->grantWrite));
        }

        if (!(this->grantWriteACP.IsEmpty())) {
            awsPutBucketAclRequest.SetGrantWriteACP(TCHAR_TO_UTF8(*this->grantWriteACP));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketAclRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketAclRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketAclRequest;
    }

    bool IsEmpty() const {
        return this->aCL == EAWSS3CRTBucketCannedACL::NOT_SET && this->accessControlPolicy.IsEmpty() && this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWrite.IsEmpty() && this->grantWriteACP.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }

    
#endif
};
