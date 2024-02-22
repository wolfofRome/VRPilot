/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CreateBucketRequest.h"

#endif

#include "Model/BucketCannedACL.h"
#include "Model/CreateBucketConfiguration.h"
#include "Model/AWSS3ObjectOwnership.h"

#include "CreateBucketRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateBucketRequest {
GENERATED_BODY()

    /**
    *  <p>The canned ACL to apply to the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketCannedACL ACL = EAWSBucketCannedACL::NOT_SET;

    /**
    *  <p>The name of the bucket to create.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The configuration information for the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FCreateBucketConfiguration createBucketConfiguration;

    /**
    *  <p>Allows grantee the read, write, read ACP, and write ACP permissions on the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantFullControl;

    /**
    *  <p>Allows grantee to list the objects in the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantRead;

    /**
    *  <p>Allows grantee to read the bucket ACL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantReadACP;

    /**
    *  <p>Allows grantee to create new objects in the bucket.</p> <p>For the bucket and object owners of existing objects, also allows deletions and overwrites of those objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantWrite;

    /**
    *  <p>Allows grantee to write the ACL for the applicable bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString grantWriteACP;

    /**
    *  <p>Specifies whether you want S3 Object Lock to be enabled for the new bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool objectLockEnabledForBucket = false;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ObjectOwnership objectOwnership = EAWSS3ObjectOwnership::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CreateBucketRequest toAWS() const {
        Aws::S3::Model::CreateBucketRequest awsCreateBucketRequest;

        switch(this->ACL) {
            case EAWSBucketCannedACL::private_:
                awsCreateBucketRequest.SetACL(Aws::S3::Model::BucketCannedACL::private_);
                break;
            case EAWSBucketCannedACL::public_read:
                awsCreateBucketRequest.SetACL(Aws::S3::Model::BucketCannedACL::public_read);
                break;
            case EAWSBucketCannedACL::public_read_write:
                awsCreateBucketRequest.SetACL(Aws::S3::Model::BucketCannedACL::public_read_write);
                break;
            case EAWSBucketCannedACL::authenticated_read:
                awsCreateBucketRequest.SetACL(Aws::S3::Model::BucketCannedACL::authenticated_read);
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

        switch(this->objectOwnership) {
            case EAWSS3ObjectOwnership::BucketOwnerPreferred:
                awsCreateBucketRequest.SetObjectOwnership(Aws::S3::Model::ObjectOwnership::BucketOwnerPreferred);
                break;
            case EAWSS3ObjectOwnership::ObjectWriter:
                awsCreateBucketRequest.SetObjectOwnership(Aws::S3::Model::ObjectOwnership::ObjectWriter);
                break;
            case EAWSS3ObjectOwnership::BucketOwnerEnforced:
                awsCreateBucketRequest.SetObjectOwnership(Aws::S3::Model::ObjectOwnership::BucketOwnerEnforced);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsCreateBucketRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsCreateBucketRequest;
    }

    bool IsEmpty() const {
        return ACL == EAWSBucketCannedACL::NOT_SET && this->bucket.IsEmpty() && this->createBucketConfiguration.IsEmpty() && this->grantFullControl.IsEmpty() && this->grantRead.IsEmpty() && this->grantReadACP.IsEmpty() && this->grantWrite.IsEmpty() && this->grantWriteACP.IsEmpty() && false && this->objectOwnership == EAWSS3ObjectOwnership::NOT_SET && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
