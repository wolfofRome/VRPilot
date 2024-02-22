/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteBucketCorsRequest.h"

#endif

#include "AWSS3CRTDeleteBucketCorsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteBucketCorsRequest {
GENERATED_BODY()

    /**
    *  <p>Specifies the bucket whose <code>cors</code> configuration is being deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

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
    Aws::S3Crt::Model::DeleteBucketCorsRequest toAWS() const {
        Aws::S3Crt::Model::DeleteBucketCorsRequest awsDeleteBucketCorsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsDeleteBucketCorsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsDeleteBucketCorsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsDeleteBucketCorsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsDeleteBucketCorsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
