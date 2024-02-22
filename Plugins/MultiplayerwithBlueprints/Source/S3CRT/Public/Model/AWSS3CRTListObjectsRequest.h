/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListObjectsRequest.h"

#endif

#include "Model/AWSS3CRTEncodingType.h"
#include "Model/AWSS3CRTRequestPayer.h"

#include "AWSS3CRTListObjectsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListObjectsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket containing the objects.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this action using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>A delimiter is a character you use to group keys.</p>
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
    FString marker;

    /**
    *  <p>Sets the maximum number of keys returned in the response. By default the action returns up to 1,000 key names. The response might contain fewer keys but will never contain more. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int maxKeys = 0;

    /**
    *  <p>Limits the response to keys that begin with the specified prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>Confirms that the requester knows that she or he will be charged for the list objects request. Bucket owners need not specify this parameter in their requests.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestPayer requestPayer = EAWSS3CRTRequestPayer::NOT_SET;

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
    Aws::S3Crt::Model::ListObjectsRequest toAWS() const {
        Aws::S3Crt::Model::ListObjectsRequest awsListObjectsRequest;

        if (!(this->bucket.IsEmpty())) {
            awsListObjectsRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->delimiter.IsEmpty())) {
            awsListObjectsRequest.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        switch(this->encodingType) {
            case EAWSS3CRTEncodingType::url:
                awsListObjectsRequest.SetEncodingType(Aws::S3Crt::Model::EncodingType::url);
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
            case EAWSS3CRTRequestPayer::requester:
                awsListObjectsRequest.SetRequestPayer(Aws::S3Crt::Model::RequestPayer::requester);
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
        return this->bucket.IsEmpty() && this->delimiter.IsEmpty() && this->encodingType == EAWSS3CRTEncodingType::NOT_SET && this->marker.IsEmpty() && this->maxKeys == 0 && this->prefix.IsEmpty() && this->requestPayer == EAWSS3CRTRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
