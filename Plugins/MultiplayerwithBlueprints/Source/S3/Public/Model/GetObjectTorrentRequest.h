/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectTorrentRequest.h"

#endif

#include "Model/RequestPayer.h"

#include "GetObjectTorrentRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectTorrentRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket containing the object for which to get the torrent files.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The object key for which to get the information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::GetObjectTorrentRequest toAWS() const {
        Aws::S3::Model::GetObjectTorrentRequest awsGetObjectTorrentRequest;

		if (!(this->bucket.IsEmpty())) {
            awsGetObjectTorrentRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->key.IsEmpty())) {
            awsGetObjectTorrentRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsGetObjectTorrentRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetObjectTorrentRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

		for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetObjectTorrentRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetObjectTorrentRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
