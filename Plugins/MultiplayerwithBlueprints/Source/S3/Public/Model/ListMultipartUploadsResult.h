/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListMultipartUploadsResult.h"

#endif

#include "Model/MultipartUpload.h"
#include "Model/CommonPrefix.h"
#include "Model/EncodingType.h"

#include "ListMultipartUploadsResult.generated.h"

USTRUCT(BlueprintType)
struct FListMultipartUploadsResult {
GENERATED_BODY()

    /**
    *  <p>Name of the bucket to which the multipart upload was initiated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The key at or after which the listing began.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString keyMarker;

    /**
    *  <p>Upload ID after which listing began.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uploadIdMarker;

    /**
    *  <p>When a list is truncated, this element specifies the value that should be used for the key-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextKeyMarker;

    /**
    *  <p>When a prefix is provided in the request, this field contains the specified prefix. The result contains only keys starting with the specified prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>Contains the delimiter you specified in the request. If you don't specify a delimiter in your request, this element is absent from the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString delimiter;

    /**
    *  <p>When a list is truncated, this element specifies the value that should be used for the <code>upload-id-marker</code> request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextUploadIdMarker;

    /**
    *  <p>Maximum number of multipart uploads that could have been included in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxUploads = 0;

    /**
    *  <p>Indicates whether the returned list of multipart uploads is truncated. A value of true indicates that the list was truncated. The list can be truncated if the number of multipart uploads exceeds the limit allowed or specified by max uploads.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>Container for elements related to a particular multipart upload. A response can contain zero or more <code>Upload</code> elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FMultipartUpload> uploads;

    /**
    *  <p>If you specify a delimiter in the request, then the result returns each distinct key prefix containing the delimiter in a <code>CommonPrefixes</code> element. The distinct key prefixes are returned in the <code>Prefix</code> child element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FCommonPrefix> commonPrefixes;

    /**
    *  <p>Encoding type used by Amazon S3 to encode object keys in the response.</p> <p>If you specify <code>encoding-type</code> request parameter, Amazon S3 includes this element in the response, and returns encoded key name values in the following response elements:</p> <p> <code>Delimiter</code>, <code>KeyMarker</code>, <code>Prefix</code>, <code>NextKeyMarker</code>, <code>Key</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSEncodingType encodingType = EAWSEncodingType::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListMultipartUploadsResult &fromAWS(const Aws::S3::Model::ListMultipartUploadsResult &awsListMultipartUploadsResult) {
        this->bucket = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetBucket().c_str());

        this->keyMarker = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetKeyMarker().c_str());

        this->uploadIdMarker = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetUploadIdMarker().c_str());

        this->nextKeyMarker = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetNextKeyMarker().c_str());

        this->prefix = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetPrefix().c_str());

        this->delimiter = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetDelimiter().c_str());

        this->nextUploadIdMarker = UTF8_TO_TCHAR(awsListMultipartUploadsResult.GetNextUploadIdMarker().c_str());

		this->maxUploads = awsListMultipartUploadsResult.GetMaxUploads();

        this->isTruncated = awsListMultipartUploadsResult.GetIsTruncated();

        this->uploads.Empty();
        for (const Aws::S3::Model::MultipartUpload& elem : awsListMultipartUploadsResult.GetUploads()) {
            this->uploads.Add(FMultipartUpload().fromAWS(elem));
        }

        this->commonPrefixes.Empty();
        for (const Aws::S3::Model::CommonPrefix& elem : awsListMultipartUploadsResult.GetCommonPrefixes()) {
            this->commonPrefixes.Add(FCommonPrefix().fromAWS(elem));
        }

        switch(awsListMultipartUploadsResult.GetEncodingType()) {
            case Aws::S3::Model::EncodingType::NOT_SET:
                this->encodingType = EAWSEncodingType::NOT_SET;
                break;
            case Aws::S3::Model::EncodingType::url:
                this->encodingType = EAWSEncodingType::url;
                break;
            default:
                this->encodingType = EAWSEncodingType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
