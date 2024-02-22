/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListMultipartUploadsRequest.h"

#endif

#include "Model/EncodingType.h"

#include "ListMultipartUploadsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListMultipartUploadsRequest {
GENERATED_BODY()

    /**
    *  <p>Name of the bucket to which the multipart upload was initiated. </p> <p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation using an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>Character you use to group keys.</p> <p>All keys that contain the same string between the prefix, if specified, and the first occurrence of the delimiter after the prefix are grouped under a single result element, <code>CommonPrefixes</code>. If you don't specify the prefix parameter, then the substring starts at the beginning of the key. The keys that are grouped under <code>CommonPrefixes</code> result element are not returned elsewhere in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString delimiter;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSEncodingType encodingType = EAWSEncodingType::NOT_SET;

    /**
    *  <p>Together with upload-id-marker, this parameter specifies the multipart upload after which listing should begin.</p> <p>If <code>upload-id-marker</code> is not specified, only the keys lexicographically greater than the specified <code>key-marker</code> will be included in the list.</p> <p>If <code>upload-id-marker</code> is specified, any multipart uploads for a key equal to the <code>key-marker</code> might also be included, provided those multipart uploads have upload IDs lexicographically greater than the specified <code>upload-id-marker</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString keyMarker;

    /**
    *  <p>Sets the maximum number of multipart uploads, from 1 to 1,000, to return in the response body. 1,000 is the maximum number of uploads that can be returned in a response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxUploads = 0;

    /**
    *  <p>Lists in-progress uploads only for those keys that begin with the specified prefix. You can use prefixes to separate a bucket into different grouping of keys. (You can think of using prefix to make groups in the same way you'd use a folder in a file system.)</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>Together with key-marker, specifies the multipart upload after which listing should begin. If key-marker is not specified, the upload-id-marker parameter is ignored. Otherwise, any multipart uploads for a key equal to the key-marker might be included in the list only if they have an upload ID lexicographically greater than the specified <code>upload-id-marker</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uploadIdMarker;

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
    Aws::S3::Model::ListMultipartUploadsRequest toAWS() const {
        Aws::S3::Model::ListMultipartUploadsRequest awsListMultipartUploadsRequest;

		if (!(this->bucket.IsEmpty())) {
            awsListMultipartUploadsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->delimiter.IsEmpty())) {
            awsListMultipartUploadsRequest.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        switch(this->encodingType) {
            case EAWSEncodingType::url:
                awsListMultipartUploadsRequest.SetEncodingType(Aws::S3::Model::EncodingType::url);
                break;
            default:
                break;
		}

		if (!(this->keyMarker.IsEmpty())) {
            awsListMultipartUploadsRequest.SetKeyMarker(TCHAR_TO_UTF8(*this->keyMarker));
        }

        if (!(this->maxUploads == 0)) {
            awsListMultipartUploadsRequest.SetMaxUploads(this->maxUploads);
        }

		if (!(this->prefix.IsEmpty())) {
            awsListMultipartUploadsRequest.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

		if (!(this->uploadIdMarker.IsEmpty())) {
            awsListMultipartUploadsRequest.SetUploadIdMarker(TCHAR_TO_UTF8(*this->uploadIdMarker));
        }

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListMultipartUploadsRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListMultipartUploadsRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListMultipartUploadsRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->delimiter.IsEmpty() && encodingType == EAWSEncodingType::NOT_SET && this->keyMarker.IsEmpty() && this->maxUploads == 0 && this->prefix.IsEmpty() && this->uploadIdMarker.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
