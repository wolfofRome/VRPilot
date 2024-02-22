/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PutBucketOwnershipControlsRequest.h"

#endif

#include "Model/AWSS3OwnershipControls.h"

#include "AWSS3PutBucketOwnershipControlsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3PutBucketOwnershipControlsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Amazon S3 bucket whose <code>OwnershipControls</code> you want to set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The MD5 hash of the <code>OwnershipControls</code> request body. </p> <p>For requests made using the AWS Command Line Interface (CLI) or AWS SDKs, this field is calculated automatically.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString contentMD5;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>The <code>OwnershipControls</code> (BucketOwnerPreferred or ObjectWriter) that you want to apply to this Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3OwnershipControls ownershipControls;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::PutBucketOwnershipControlsRequest toAWS() const {
        Aws::S3::Model::PutBucketOwnershipControlsRequest awsPutBucketOwnershipControlsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsPutBucketOwnershipControlsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->contentMD5.IsEmpty())) {
            awsPutBucketOwnershipControlsRequest.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsPutBucketOwnershipControlsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        if (!(this->ownershipControls.IsEmpty())) {
            awsPutBucketOwnershipControlsRequest.SetOwnershipControls(this->ownershipControls.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsPutBucketOwnershipControlsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsPutBucketOwnershipControlsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->contentMD5.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->ownershipControls.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
