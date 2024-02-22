/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListObjectsResult.h"

#endif

#include "Model/AWSS3CRTObject.h"
#include "Model/AWSS3CRTCommonPrefix.h"
#include "Model/AWSS3CRTEncodingType.h"

#include "AWSS3CRTListObjectsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListObjectsResult {
GENERATED_BODY()

    /**
    *  <p>A flag that indicates whether Amazon S3 returned all of the results that satisfied the search criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p>Indicates where in the bucket listing begins. Marker is included in the response if it was sent with the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString marker;

    /**
    *  <p>When response is truncated (the IsTruncated element value in the response is true), you can use the key name in this field as marker in the subsequent request to get next set of objects. Amazon S3 lists objects in alphabetical order Note: This element is returned only if you have delimiter request parameter specified. If response does not include the NextMarker and it is truncated, you can use the value of the last Key in the response as the marker in the subsequent request to get the next set of object keys.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextMarker;

    /**
    *  <p>Metadata about each object returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTObject> contents;

    /**
    *  <p>The bucket name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString name;

    /**
    *  <p>Keys that begin with the indicated prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>Causes keys that contain the same string between the prefix and the first occurrence of the delimiter to be rolled up into a single result element in the <code>CommonPrefixes</code> collection. These rolled-up keys are not returned elsewhere in the response. Each rolled-up result counts as only one return against the <code>MaxKeys</code> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString delimiter;

    /**
    *  <p>The maximum number of keys returned in the response body.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int maxKeys = 0;

    /**
    *  <p>All of the keys (up to 1,000) rolled up in a common prefix count as a single return when calculating the number of returns. </p> <p>A response can contain CommonPrefixes only if you specify a delimiter.</p> <p>CommonPrefixes contains all (if there are any) keys between Prefix and the next occurrence of the string specified by the delimiter.</p> <p> CommonPrefixes lists keys that act like subdirectories in the directory specified by Prefix.</p> <p>For example, if the prefix is notes/ and the delimiter is a slash (/) as in notes/summer/july, the common prefix is notes/summer/. All of the keys that roll up into a common prefix count as a single return when calculating the number of returns.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTCommonPrefix> commonPrefixes;

    /**
    *  <p>Encoding type used by Amazon S3 to encode object keys in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTEncodingType encodingType = EAWSS3CRTEncodingType::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListObjectsResult &fromAWS(const Aws::S3Crt::Model::ListObjectsResult &awsListObjectsResult) {
        this->isTruncated = awsListObjectsResult.GetIsTruncated();

        this->marker = UTF8_TO_TCHAR(awsListObjectsResult.GetMarker().c_str());

        this->nextMarker = UTF8_TO_TCHAR(awsListObjectsResult.GetNextMarker().c_str());

        this->contents.Empty();
        for (const Aws::S3Crt::Model::Object& elem : awsListObjectsResult.GetContents()) {
            this->contents.Add(FAWSS3CRTObject().fromAWS(elem));
        }

        this->name = UTF8_TO_TCHAR(awsListObjectsResult.GetName().c_str());

        this->prefix = UTF8_TO_TCHAR(awsListObjectsResult.GetPrefix().c_str());

        this->delimiter = UTF8_TO_TCHAR(awsListObjectsResult.GetDelimiter().c_str());

		this->maxKeys = awsListObjectsResult.GetMaxKeys();

        this->commonPrefixes.Empty();
        for (const Aws::S3Crt::Model::CommonPrefix& elem : awsListObjectsResult.GetCommonPrefixes()) {
            this->commonPrefixes.Add(FAWSS3CRTCommonPrefix().fromAWS(elem));
        }

        switch(awsListObjectsResult.GetEncodingType()) {
            case Aws::S3Crt::Model::EncodingType::NOT_SET:
                this->encodingType = EAWSS3CRTEncodingType::NOT_SET;
                break;
            case Aws::S3Crt::Model::EncodingType::url:
                this->encodingType = EAWSS3CRTEncodingType::url;
                break;
            default:
                this->encodingType = EAWSS3CRTEncodingType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
