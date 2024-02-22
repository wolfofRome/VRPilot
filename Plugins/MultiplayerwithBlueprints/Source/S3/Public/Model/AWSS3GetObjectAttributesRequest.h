/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectAttributesRequest.h"

#endif

#include "Model/RequestPayer.h"
#include "Model/AWSS3ObjectAttributes.h"

#include "AWSS3GetObjectAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3GetObjectAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the bucket that contains the object.</p> <p>When using this action with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this action with an access point through the Amazon Web Services SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using access points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When using this action with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <code> <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>. When using this action with S3 on Outposts through the Amazon Web Services SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>The version ID used to reference a specific version of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    *  <p>Sets the maximum number of parts to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxParts = 0;

    /**
    *  <p>Specifies the part after which listing should begin. Only parts with higher part numbers will be listed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partNumberMarker = 0;

    /**
    *  <p>Specifies the algorithm to use when encrypting the object (for example, AES256).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString sSECustomerKey;

    /**
    *  <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString sSECustomerKeyMD5;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestPayer requestPayer = EAWSRequestPayer::NOT_SET;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    *  <p>An XML header that specifies the fields at the root level that you want returned in the response. Fields that you do not specify are not returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<EAWSS3ObjectAttributes> objectAttributes;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::GetObjectAttributesRequest toAWS() const {
        Aws::S3::Model::GetObjectAttributesRequest awsGetObjectAttributesRequest;

        if (!(this->bucket.IsEmpty())) {
            awsGetObjectAttributesRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsGetObjectAttributesRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->versionId.IsEmpty())) {
            awsGetObjectAttributesRequest.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        if (!(this->maxParts == 0)) {
            awsGetObjectAttributesRequest.SetMaxParts(this->maxParts);
        }

        if (!(this->partNumberMarker == 0)) {
            awsGetObjectAttributesRequest.SetPartNumberMarker(this->partNumberMarker);
        }

        if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsGetObjectAttributesRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

        if (!(this->sSECustomerKey.IsEmpty())) {
            awsGetObjectAttributesRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->sSECustomerKey));
        }

        if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsGetObjectAttributesRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

        switch(this->requestPayer) {
            case EAWSRequestPayer::requester:
                awsGetObjectAttributesRequest.SetRequestPayer(Aws::S3::Model::RequestPayer::requester);
                break;
            default:
                break;
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsGetObjectAttributesRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const EAWSS3ObjectAttributes& elem : this->objectAttributes) {
		    switch(elem) {
                case EAWSS3ObjectAttributes::ETag:
                    awsGetObjectAttributesRequest.AddObjectAttributes(Aws::S3::Model::ObjectAttributes::ETag);
                    break;
                case EAWSS3ObjectAttributes::Checksum:
                    awsGetObjectAttributesRequest.AddObjectAttributes(Aws::S3::Model::ObjectAttributes::Checksum);
                    break;
                case EAWSS3ObjectAttributes::ObjectParts:
                    awsGetObjectAttributesRequest.AddObjectAttributes(Aws::S3::Model::ObjectAttributes::ObjectParts);
                    break;
                case EAWSS3ObjectAttributes::StorageClass:
                    awsGetObjectAttributesRequest.AddObjectAttributes(Aws::S3::Model::ObjectAttributes::StorageClass);
                    break;
                case EAWSS3ObjectAttributes::ObjectSize:
                    awsGetObjectAttributesRequest.AddObjectAttributes(Aws::S3::Model::ObjectAttributes::ObjectSize);
                    break;
                default:
                    break;
            };
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsGetObjectAttributesRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetObjectAttributesRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->versionId.IsEmpty() && this->maxParts == 0 && this->partNumberMarker == 0 && this->sSECustomerAlgorithm.IsEmpty() && this->sSECustomerKey.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->requestPayer == EAWSRequestPayer::NOT_SET && this->expectedBucketOwner.IsEmpty() && this->objectAttributes.Num() == 0 && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
