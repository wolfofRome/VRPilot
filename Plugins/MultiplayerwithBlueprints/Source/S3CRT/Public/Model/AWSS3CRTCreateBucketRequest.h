/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CreateBucketRequest.h"

#endif

#include "Model/AWSS3CRTBucketCannedACL.h"
#include "Model/AWSS3CRTCreateBucketConfiguration.h"

#include "AWSS3CRTCreateBucketRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCreateBucketRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketCannedACL aCL = EAWSS3CRTBucketCannedACL::NOT_SET;

    /**
    *  <p>The name of the bucket to create.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The configuration information for the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCreateBucketConfiguration createBucketConfiguration;

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
    *  <p>Specifies whether you want S3 Object Lock to be enabled for the new bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool objectLockEnabledForBucket = false;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CreateBucketRequest toAWS() const {
        Aws::S3Crt::Model::CreateBucketRequest awsCreateBucketRequest;

        switch(this->aCL) {
            case EAWSS3CRTBucketCannedACL::private_:
                awsCreateBucketRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::private_);
                break;
            case EAWSS3CRTBucketCannedACL::public_read:
                awsCreateBucketRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::public_read);
                break;
            case EAWSS3CRTBucketCannedACL::public_read_write:
                awsCreateBucketRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::public_read_write);
                break;
            case EAWSS3CRTBucketCannedACL::authenticated_read:
                awsCreateBucketRequest.SetACL(Aws::S3Crt::Model::BucketCannedACL::authenticated_read);
                break;
            default:
                break;
        }

        if (!(this->bucket.IsEmpty())) {
            awsCreateBucketRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->createBucketConfiguration.IsEmpty())) {
            awsCreateBucketRequest.SetCreateBucketConfiguration(this->createBucketConfiguration.toAWS());
        }

        if (!(this->grantFullControl.IsEmpty())) {
            awsCreateBucketRequest.SetGrantFullControl(TCHAR_TO_UTF8(*this->grantFullControl));
        }

        if (!(this->grantRead.IsEmpty())) {
            awsCreateBucketRequest.SetGrantRead(TCHAR_TO_UTF8(*this->grantRead));
        }

        if (!(this->grantReadACP.IsEmpty())) {
            awsCreateBucketRequest.SetGrantReadACP(TCHAR_TO_UTF8(*this->grantReadACP));
        }

        if (!(this->grantWrite.IsEmpty())) {
            awsCreateBucketRequest.SetGrantWrite(TCHAR_TO_UTF8(*this->grantWrite));
        }

        if (!(this->grantWriteACP.IsEmpty())) {
            awsCreateBucketRequest.SetGrantWriteACP(TCHAR_TO_UTF8(*this->grantWriteACP));
        }

        if (!(false)) {
            awsCreateBucketRequest.SetObjectLockEnabledForBucket(this->objectLockEnabledForBucket);
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsCreateBucketRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsCreateBucketRequest;
    }

    bool IsEmpty() const {
        return this->aCL == EAWSS3CRTBucketCannedACL::NOT_SET && this->bucket.IsEmpty() && this->createBucketConfiguration.IsEmpty() && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWrite.IsEmpty() && this->grantWriteACP.IsEmpty() && false && this->customizedAccessLogTag.Num() == 0;
    }

    
#endif
};
