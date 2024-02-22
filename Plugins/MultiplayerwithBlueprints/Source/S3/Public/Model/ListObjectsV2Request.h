/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListObjectsV2Request.h"

#endif

#include "Model/EncodingType.h"
#include "Model/RequestPayer.h"

#include "ListObjectsV2Request.generated.h"

USTRUCT(BlueprintType)
struct FListObjectsV2Request {
GENERATED_BODY()

    /**
    *  <p>Bucket name to list. </p> <p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation using an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>A delimiter is a character you use to group keys.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString delimiter;

    /**
    *  <p>Encoding type used by Amazon S3 to encode object keys in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSEncodingType encodingType = EAWSEncodingType::NOT_SET;

    /**
    *  <p>Sets the maximum number of keys returned in the response. By default the API returns up to 1,000 key names. The response might contain fewer keys but will never contain more.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxKeys = 0;

    /**
    *  <p>Limits the response to keys that begin with the specified prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>ContinuationToken indicates Amazon S3 that the list is being continued on this bucket with a token. ContinuationToken is obfuscated and is not a real key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

    /**
    *  <p>The owner field is not present in listV2 by default, if you want to return owner field with each key in the result then set the fetch owner field to true.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool fetchOwner = false;

    /**
    *  <p>StartAfter is where you want Amazon S3 to start listing from. Amazon S3 starts listing after this specified key. StartAfter can be any key in the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString startAfter;

    /**
    *  <p>Confirms that the requester knows that she or he will be charged for the list objects request in V2 style. Bucket owners need not specify this parameter in their requests.</p>
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
    Aws::S3::Model::ListObjectsV2Request toAWS() const {
        Aws::S3::Model::ListObjectsV2Request awsListObjectsV2Request;

		if (!(this->bucket.IsEmpty())) {
            awsListObjectsV2Request.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->delimiter.IsEmpty())) {
            awsListObjectsV2Request.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        switch(this->encodingType) {
            case EAWSEncodingType::url:
                awsListObjectsV2Request.SetEncodingType(Aws::S3::Model::EncodingType::url);
                break;
            default:
                break;
		}

        if (!(this->maxKeys == 0)) {
            awsListObjectsV2Request.SetMaxKeys(this->maxKeys);
        }

		if (!(this->prefix.IsEmpty())) {
            awsListObjectsV2Request.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

		if (!(this->continuationToken.IsEmpty())) {
            awsListObjectsV2Request.SetContinuationToken(TCHAR_TO_UTF8(*this->continuationToken));
        }

        if (!(false)) {
            awsListObjectsV2Request.SetFetchOwner(this->fetchOwner);
        }

		if (!(this->startAfter.IsEmpty())) {
            awsListObjectsV2Request.SetStartAfter(TCHAR_TO_UTF8(*this->startAfter));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsListObjectsV2Request.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
		}

		if (!(this->expectedBucketOwner.IsEmpty())) {
            awsListObjectsV2Request.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsListObjectsV2Request.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsListObjectsV2Request;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->delimiter.IsEmpty() && encodingType == EAWSEncodingType::NOT_SET && this->maxKeys == 0 && this->prefix.IsEmpty() && this->continuationToken.IsEmpty() && false && this->startAfter.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};