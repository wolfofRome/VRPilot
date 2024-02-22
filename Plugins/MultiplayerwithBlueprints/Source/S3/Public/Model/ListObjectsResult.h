/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListObjectsResult.h"

#endif

#include "Model/S3Object.h"
#include "Model/CommonPrefix.h"
#include "Model/EncodingType.h"

#include "ListObjectsResult.generated.h"

USTRUCT(BlueprintType)
struct FListObjectsResult {
GENERATED_BODY()

    /**
    *  <p>A flag that indicates whether Amazon S3 returned all of the results that satisfied the search criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>Indicates where in the bucket listing begins. Marker is included in the response if it was sent with the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString marker;

    /**
    *  <p>When response is truncated (the IsTruncated element value in the response is true), you can use the key name in this field as marker in the subsequent request to get next set of objects. Amazon S3 lists objects in alphabetical order Note: This element is returned only if you have delimiter request parameter specified. If response does not include the NextMarker and it is truncated, you can use the value of the last Key in the response as the marker in the subsequent request to get the next set of object keys.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextMarker;

    /**
    *  <p>Metadata about each object returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Object> contents;

    /**
    *  <p>Bucket name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString name;

    /**
    *  <p>Keys that begin with the indicated prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>Causes keys that contain the same string between the prefix and the first occurrence of the delimiter to be rolled up into a single result element in the <code>CommonPrefixes</code> collection. These rolled-up keys are not returned elsewhere in the response. Each rolled-up result counts as only one return against the <code>MaxKeys</code> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString delimiter;

    /**
    *  <p>The maximum number of keys returned in the response body.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxKeys = 0;

    /**
    *  <p>All of the keys rolled up in a common prefix count as a single return when calculating the number of returns. </p> <p>A response can contain CommonPrefixes only if you specify a delimiter.</p> <p>CommonPrefixes contains all (if there are any) keys between Prefix and the next occurrence of the string specified by the delimiter.</p> <p> CommonPrefixes lists keys that act like subdirectories in the directory specified by Prefix.</p> <p>For example, if the prefix is notes/ and the delimiter is a slash (/) as in notes/summer/july, the common prefix is notes/summer/. All of the keys that roll up into a common prefix count as a single return when calculating the number of returns.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FCommonPrefix> commonPrefixes;

    /**
    *  <p>Encoding type used by Amazon S3 to encode object keys in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSEncodingType encodingType = EAWSEncodingType::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListObjectsResult &fromAWS(const Aws::S3::Model::ListObjectsResult &awsListObjectsResult) {
        this->isTruncated = awsListObjectsResult.GetIsTruncated();

        this->marker = UTF8_TO_TCHAR(awsListObjectsResult.GetMarker().c_str());

        this->nextMarker = UTF8_TO_TCHAR(awsListObjectsResult.GetNextMarker().c_str());

        this->contents.Empty();
        for (const Aws::S3::Model::Object& elem : awsListObjectsResult.GetContents()) {
            this->contents.Add(FS3Object().fromAWS(elem));
        }

        this->name = UTF8_TO_TCHAR(awsListObjectsResult.GetName().c_str());

        this->prefix = UTF8_TO_TCHAR(awsListObjectsResult.GetPrefix().c_str());

        this->delimiter = UTF8_TO_TCHAR(awsListObjectsResult.GetDelimiter().c_str());

		this->maxKeys = awsListObjectsResult.GetMaxKeys();

        this->commonPrefixes.Empty();
        for (const Aws::S3::Model::CommonPrefix& elem : awsListObjectsResult.GetCommonPrefixes()) {
            this->commonPrefixes.Add(FCommonPrefix().fromAWS(elem));
        }

        switch(awsListObjectsResult.GetEncodingType()) {
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
