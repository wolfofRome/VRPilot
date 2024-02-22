/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListObjectsV2Result.h"

#endif

#include "Model/S3Object.h"
#include "Model/CommonPrefix.h"
#include "Model/EncodingType.h"

#include "ListObjectsV2Result.generated.h"

USTRUCT(BlueprintType)
struct FListObjectsV2Result {
GENERATED_BODY()

    /**
    *  <p>Set to false if all of the results were returned. Set to true if more keys are available to return. If the number of results exceeds that specified by MaxKeys, all of the results might not be returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>Metadata about each object returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Object> contents;

    /**
    *  <p>Bucket name. </p> <p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation using an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString name;

    /**
    *  <p> Keys that begin with the indicated prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>Causes keys that contain the same string between the prefix and the first occurrence of the delimiter to be rolled up into a single result element in the CommonPrefixes collection. These rolled-up keys are not returned elsewhere in the response. Each rolled-up result counts as only one return against the <code>MaxKeys</code> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString delimiter;

    /**
    *  <p>Sets the maximum number of keys returned in the response. By default the API returns up to 1,000 key names. The response might contain fewer keys but will never contain more.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxKeys = 0;

    /**
    *  <p>All of the keys rolled up into a common prefix count as a single return when calculating the number of returns.</p> <p>A response can contain <code>CommonPrefixes</code> only if you specify a delimiter.</p> <p> <code>CommonPrefixes</code> contains all (if there are any) keys between <code>Prefix</code> and the next occurrence of the string specified by a delimiter.</p> <p> <code>CommonPrefixes</code> lists keys that act like subdirectories in the directory specified by <code>Prefix</code>.</p> <p>For example, if the prefix is <code>notes/</code> and the delimiter is a slash (<code>/</code>) as in <code>notes/summer/july</code>, the common prefix is <code>notes/summer/</code>. All of the keys that roll up into a common prefix count as a single return when calculating the number of returns. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FCommonPrefix> commonPrefixes;

    /**
    *  <p>Encoding type used by Amazon S3 to encode object key names in the XML response.</p> <p>If you specify the encoding-type request parameter, Amazon S3 includes this element in the response, and returns encoded key name values in the following response elements:</p> <p> <code>Delimiter, Prefix, Key,</code> and <code>StartAfter</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSEncodingType encodingType = EAWSEncodingType::NOT_SET;

    /**
    *  <p>KeyCount is the number of keys returned with this request. KeyCount will always be less than equals to MaxKeys field. Say you ask for 50 keys, your result will include less than equals 50 keys </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int keyCount = 0;

    /**
    *  <p> If ContinuationToken was sent with the request, it is included in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

    /**
    *  <p> <code>NextContinuationToken</code> is sent when <code>isTruncated</code> is true, which means there are more keys in the bucket that can be listed. The next list requests to Amazon S3 can be continued with this <code>NextContinuationToken</code>. <code>NextContinuationToken</code> is obfuscated and is not a real key</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextContinuationToken;

    /**
    *  <p>If StartAfter was sent with the request, it is included in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString startAfter;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListObjectsV2Result &fromAWS(const Aws::S3::Model::ListObjectsV2Result &awsListObjectsV2Result) {
        this->isTruncated = awsListObjectsV2Result.GetIsTruncated();

        this->contents.Empty();
        for (const Aws::S3::Model::Object& elem : awsListObjectsV2Result.GetContents()) {
            this->contents.Add(FS3Object().fromAWS(elem));
        }

        this->name = UTF8_TO_TCHAR(awsListObjectsV2Result.GetName().c_str());

        this->prefix = UTF8_TO_TCHAR(awsListObjectsV2Result.GetPrefix().c_str());

        this->delimiter = UTF8_TO_TCHAR(awsListObjectsV2Result.GetDelimiter().c_str());

		this->maxKeys = awsListObjectsV2Result.GetMaxKeys();

        this->commonPrefixes.Empty();
        for (const Aws::S3::Model::CommonPrefix& elem : awsListObjectsV2Result.GetCommonPrefixes()) {
            this->commonPrefixes.Add(FCommonPrefix().fromAWS(elem));
        }

        switch(awsListObjectsV2Result.GetEncodingType()) {
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

		this->keyCount = awsListObjectsV2Result.GetKeyCount();

        this->continuationToken = UTF8_TO_TCHAR(awsListObjectsV2Result.GetContinuationToken().c_str());

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListObjectsV2Result.GetNextContinuationToken().c_str());

        this->startAfter = UTF8_TO_TCHAR(awsListObjectsV2Result.GetStartAfter().c_str());

        return *this;
    }
#endif
};
