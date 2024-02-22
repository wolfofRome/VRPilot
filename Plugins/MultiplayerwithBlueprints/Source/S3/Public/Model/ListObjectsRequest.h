/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListObjectsRequest.h"

#endif

#include "Model/EncodingType.h"
#include "Model/RequestPayer.h"

#include "ListObjectsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListObjectsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket containing the objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>A delimiter is a character you use to group keys.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString delimiter;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSEncodingType encodingType = EAWSEncodingType::NOT_SET;

    /**
    *  <p>Specifies the key to start with when listing objects in a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString marker;

    /**
    *  <p>Sets the maximum number of keys returned in the response. By default the API returns up to 1,000 key names. The response might contain fewer keys but will never contain more. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxKeys = 0;

    /**
    *  <p>Limits the response to keys that begin with the specified prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>Confirms that the requester knows that she or he will be charged for the list objects request. Bucket owners need not specify this parameter in their requests.</p>
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
    Aws::S3::Model::ListObjectsRequest toAWS() const {
        Aws::S3::Model::ListObjectsRequest awsListObjectsRequest;

		if (!(this->bucket.IsEmpty())) {
            awsListObjectsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->delimiter.IsEmpty())) {
            awsListObjectsRequest.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        switch(this->encodingType) {
            case EAWSEncodingType::url:
                awsListObjectsRequest.SetEncodingType(Aws::S3::Model::EncodingType::url);
                break;
            default:
                break;
		}

		if (!(this->marker.IsEmpty())) {
            awsListObjectsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (!(this->maxKeys == 0)) {
            awsListObjectsRequest.SetMaxKeys(this->maxKeys);
        }

		if (!(this->prefix.IsEmpty())) {
            awsListObjectsRequest.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsListObjectsRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListObjectsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListObjectsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListObjectsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->delimiter.IsEmpty() && encodingType == EAWSEncodingType::NOT_SET && this->marker.IsEmpty() && this->maxKeys == 0 && this->prefix.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
