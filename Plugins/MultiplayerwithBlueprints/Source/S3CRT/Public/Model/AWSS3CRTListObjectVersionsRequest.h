/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListObjectVersionsRequest.h"

#endif

#include "Model/AWSS3CRTEncodingType.h"

#include "AWSS3CRTListObjectVersionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListObjectVersionsRequest {
GENERATED_BODY()

    /**
    *  <p>The bucket name that contains the objects. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>A delimiter is a character that you specify to group keys. All keys that contain the same string between the <code>prefix</code> and the first occurrence of the delimiter are grouped under a single result element in CommonPrefixes. These groups are counted as one result against the max-keys limitation. These keys are not returned elsewhere in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString delimiter;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTEncodingType encodingType = EAWSS3CRTEncodingType::NOT_SET;

    /**
    *  <p>Specifies the key to start with when listing objects in a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString keyMarker;

    /**
    *  <p>Sets the maximum number of keys returned in the response. By default the action returns up to 1,000 key names. The response might contain fewer keys but will never contain more. If additional keys satisfy the search criteria, but were not returned because max-keys was exceeded, the response contains &lt;isTruncated&gt;true&lt;/isTruncated&gt;. To return the additional keys, see key-marker and version-id-marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int maxKeys = 0;

    /**
    *  <p>Use this parameter to select only those keys that begin with the specified prefix. You can use prefixes to separate a bucket into different groupings of keys. (You can think of using prefix to make groups in the same way you'd use a folder in a file system.) You can use prefix with delimiter to roll up numerous objects into a single result under CommonPrefixes. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>Specifies the object version you want to start listing from.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionIdMarker;

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
    Aws::S3Crt::Model::ListObjectVersionsRequest toAWS() const {
        Aws::S3Crt::Model::ListObjectVersionsRequest awsListObjectVersionsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsListObjectVersionsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->delimiter.IsEmpty())) {
            awsListObjectVersionsRequest.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        switch(this->encodingType) {
            case EAWSS3CRTEncodingType::url:
                awsListObjectVersionsRequest.SetEncodingType(Aws::S3Crt::Model::EncodingType::url);
                break;
            default:
                break;
        }

        if (!(this->keyMarker.IsEmpty())) {
            awsListObjectVersionsRequest.SetKeyMarker(TCHAR_TO_UTF8(*this->keyMarker));
        }

        if (!(this->maxKeys == 0)) {
            awsListObjectVersionsRequest.SetMaxKeys(this->maxKeys);
        }

        if (!(this->prefix.IsEmpty())) {
            awsListObjectVersionsRequest.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->versionIdMarker.IsEmpty())) {
            awsListObjectVersionsRequest.SetVersionIdMarker(TCHAR_TO_UTF8(*this->versionIdMarker));
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListObjectVersionsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListObjectVersionsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListObjectVersionsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->delimiter.IsEmpty() && this->encodingType == EAWSS3CRTEncodingType::NOT_SET && this->keyMarker.IsEmpty() && this->maxKeys == 0 && this->prefix.IsEmpty() && this->versionIdMarker.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
