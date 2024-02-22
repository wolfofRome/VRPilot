/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/PutObjectLockConfigurationRequest.h"

#endif

#include "Model/AWSS3CRTObjectLockConfiguration.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTPutObjectLockConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTPutObjectLockConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket whose Object Lock configuration you want to create or replace.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The Object Lock configuration that you want to apply to the specified bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTObjectLockConfiguration objectLockConfiguration;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

    /**
    *  <p>A token to allow Object Lock to be enabled for an existing bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString token;

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
    Aws::S3Crt::Model::PutObjectLockConfigurationRequest toAWS() const {
        Aws::S3Crt::Model::PutObjectLockConfigurationRequest awsPutObjectLockConfigurationRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutObjectLockConfigurationRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->objectLockConfiguration.IsEmpty())) {
            awsPutObjectLockConfigurationRequest.SetObjectLockConfiguration(this->objectLockConfiguration.toAWS());
        }

        switch(this->requestPayer) {
            case EAWSS3CRTRequestPayer::requester:
                awsPutObjectLockConfigurationRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->token.IsEmpty())) {
            awsPutObjectLockConfigurationRequest.SetToken(TCHAR_TO_UTF8(*this->token));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutObjectLockConfigurationRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutObjectLockConfigurationRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutObjectLockConfigurationRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutObjectLockConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->objectLockConfiguration.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->token.IsEmpty() && this->contentMD5.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
