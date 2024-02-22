/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateBucketRequest.h"

#endif

#include "Model/AWSS3ControlBucketCannedACL.h"
#include "Model/AWSS3ControlCreateBucketConfiguration.h"

#include "AWSS3ControlCreateBucketRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateBucketRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlBucketCannedACL aCL = EAWSS3ControlBucketCannedACL::NOT_SET;

    /**
    *  <p>The name of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The configuration information for the bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlCreateBucketConfiguration createBucketConfiguration;

    /**
    *  <p>Allows grantee the read, write, read ACP, and write ACP permissions on the bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString grantFullControl;

    /**
    *  <p>Allows grantee to list the objects in the bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString grantRead;

    /**
    *  <p>Allows grantee to read the bucket ACL.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString grantReadACP;

    /**
    *  <p>Allows grantee to create, overwrite, and delete any object in the bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString grantWrite;

    /**
    *  <p>Allows grantee to write the ACL for the applicable bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString grantWriteACP;

    /**
    *  <p>Specifies whether you want S3 Object Lock to be enabled for the new bucket.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool objectLockEnabledForBucket = false;

    /**
    *  <p>The ID of the Outposts where the bucket is being created.</p>  <p>This is required by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString outpostId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateBucketRequest toAWS() const {
        Aws::S3Control::Model::CreateBucketRequest awsCreateBucketRequest;

        switch(this->aCL) {
            case EAWSS3ControlBucketCannedACL::private_:
                awsCreateBucketRequest.SetACL(Aws::S3Control::Model::BucketCannedACL::private_);
                break;
            case EAWSS3ControlBucketCannedACL::public_read:
                awsCreateBucketRequest.SetACL(Aws::S3Control::Model::BucketCannedACL::public_read);
                break;
            case EAWSS3ControlBucketCannedACL::public_read_write:
                awsCreateBucketRequest.SetACL(Aws::S3Control::Model::BucketCannedACL::public_read_write);
                break;
            case EAWSS3ControlBucketCannedACL::authenticated_read:
                awsCreateBucketRequest.SetACL(Aws::S3Control::Model::BucketCannedACL::authenticated_read);
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

        if (!(this->outpostId.IsEmpty())) {
            awsCreateBucketRequest.SetOutpostId(TCHAR_TO_UTF8(*this->outpostId));
        }

        return awsCreateBucketRequest;
    }

    bool IsEmpty() const {
        return this->aCL == EAWSS3ControlBucketCannedACL::NOT_SET && this->bucket.IsEmpty() && this->createBucketConfiguration.IsEmpty() && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWrite.IsEmpty() && this->grantWriteACP.IsEmpty() && false && this->outpostId.IsEmpty();
    }
#endif
};
