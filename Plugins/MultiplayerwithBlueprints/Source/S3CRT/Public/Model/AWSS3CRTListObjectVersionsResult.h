/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListObjectVersionsResult.h"

#endif

#include "Model/AWSS3CRTObjectVersion.h"
#include "Model/AWSS3CRTDeleteMarkerEntry.h"
#include "Model/AWSS3CRTCommonPrefix.h"
#include "Model/AWSS3CRTEncodingType.h"

#include "AWSS3CRTListObjectVersionsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListObjectVersionsResult {
GENERATED_BODY()

    /**
    *  <p>A flag that indicates whether Amazon S3 returned all of the results that satisfied the search criteria. If your results were truncated, you can make a follow-up paginated request using the NextKeyMarker and NextVersionIdMarker response parameters as a starting place in another request to return the rest of the results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p>Marks the last key returned in a truncated response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString keyMarker;

    /**
    *  <p>Marks the last version of the key returned in a truncated response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionIdMarker;

    /**
    *  <p>When the number of responses exceeds the value of <code>MaxKeys</code>, <code>NextKeyMarker</code> specifies the first key not returned that satisfies the search criteria. Use this value for the key-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextKeyMarker;

    /**
    *  <p>When the number of responses exceeds the value of <code>MaxKeys</code>, <code>NextVersionIdMarker</code> specifies the first object version not returned that satisfies the search criteria. Use this value for the version-id-marker request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextVersionIdMarker;

    /**
    *  <p>Container for version information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTObjectVersion> versions;

    /**
    *  <p>Container for an object that is a delete marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTDeleteMarkerEntry> deleteMarkers;

    /**
    *  <p>The bucket name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString name;

    /**
    *  <p>Selects objects that start with the value supplied by this parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>The delimiter grouping the included keys. A delimiter is a character that you specify to group keys. All keys that contain the same string between the prefix and the first occurrence of the delimiter are grouped under a single result element in <code>CommonPrefixes</code>. These groups are counted as one result against the max-keys limitation. These keys are not returned elsewhere in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString delimiter;

    /**
    *  <p>Specifies the maximum number of objects to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int maxKeys = 0;

    /**
    *  <p>All of the keys rolled up into a common prefix count as a single return when calculating the number of returns.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTCommonPrefix> commonPrefixes;

    /**
    *  <p> Encoding type used by Amazon S3 to encode object key names in the XML response.</p> <p>If you specify encoding-type request parameter, Amazon S3 includes this element in the response, and returns encoded key name values in the following response elements:</p> <p> <code>KeyMarker, NextKeyMarker, Prefix, Key</code>, and <code>Delimiter</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTEncodingType encodingType = EAWSS3CRTEncodingType::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListObjectVersionsResult &fromAWS(const Aws::S3Crt::Model::ListObjectVersionsResult &awsListObjectVersionsResult) {
        this->isTruncated = awsListObjectVersionsResult.GetIsTruncated();

        this->keyMarker = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetKeyMarker().c_str());

        this->versionIdMarker = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetVersionIdMarker().c_str());

        this->nextKeyMarker = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetNextKeyMarker().c_str());

        this->nextVersionIdMarker = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetNextVersionIdMarker().c_str());

        this->versions.Empty();
        for (const Aws::S3Crt::Model::ObjectVersion& elem : awsListObjectVersionsResult.GetVersions()) {
            this->versions.Add(FAWSS3CRTObjectVersion().fromAWS(elem));
        }

        this->deleteMarkers.Empty();
        for (const Aws::S3Crt::Model::DeleteMarkerEntry& elem : awsListObjectVersionsResult.GetDeleteMarkers()) {
            this->deleteMarkers.Add(FAWSS3CRTDeleteMarkerEntry().fromAWS(elem));
        }

        this->name = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetName().c_str());

        this->prefix = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetPrefix().c_str());

        this->delimiter = UTF8_TO_TCHAR(awsListObjectVersionsResult.GetDelimiter().c_str());

		this->maxKeys = awsListObjectVersionsResult.GetMaxKeys();

        this->commonPrefixes.Empty();
        for (const Aws::S3Crt::Model::CommonPrefix& elem : awsListObjectVersionsResult.GetCommonPrefixes()) {
            this->commonPrefixes.Add(FAWSS3CRTCommonPrefix().fromAWS(elem));
        }

        switch(awsListObjectVersionsResult.GetEncodingType()) {
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
