/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/SelectObjectContentRequest.h"

#endif

#include "Model/AWSS3CRTExpressionType.h"
#include "Model/AWSS3CRTRequestProgress.h"
#include "Model/AWSS3CRTInputSerialization.h"
#include "Model/AWSS3CRTOutputSerialization.h"
#include "Model/AWSS3CRTScanRange.h"

#include "AWSS3CRTSelectObjectContentRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTSelectObjectContentRequest {
GENERATED_BODY()

    /**
    *  <p>The S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString bucket;

    /**
    *  <p>The object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>The SSE Algorithm used to encrypt the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ServerSideEncryptionCustomerKeys.html">Server-Side Encryption (Using Customer-Provided Encryption Keys</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerAlgorithm;

    /**
    *  <p>The SSE Customer Key. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ServerSideEncryptionCustomerKeys.html">Server-Side Encryption (Using Customer-Provided Encryption Keys</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKey;

    /**
    *  <p>The SSE Customer Key MD5. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ServerSideEncryptionCustomerKeys.html">Server-Side Encryption (Using Customer-Provided Encryption Keys</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString sSECustomerKeyMD5;

    /**
    *  <p>The expression that is used to query the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expression;

    /**
    *  <p>The type of the provided expression (for example, SQL).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTExpressionType expressionType = EAWSS3CRTExpressionType::NOT_SET;

    /**
    *  <p>Specifies if periodic request progress information should be enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTRequestProgress requestProgress;

    /**
    *  <p>Describes the format of the data in the object that is being queried.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInputSerialization inputSerialization;

    /**
    *  <p>Describes the format of the data that you want Amazon S3 to return in response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOutputSerialization outputSerialization;

    /**
    *  <p>Specifies the byte range of the object to get the records from. A record is processed when its first byte is contained by the range. This parameter is optional, but when specified, it must not be empty. See RFC 2616, Section 14.35.1 about how to specify the start and end of the range.</p> <p> <code>ScanRange</code>may be used in the following ways:</p> <ul> <li> <p> <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;end&gt;100&lt;/end&gt;&lt;/scanrange&gt;</code> - process only the records starting between the bytes 50 and 100 (inclusive, counting from zero)</p> </li> <li> <p> <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code> - process only the records starting after the byte 50</p> </li> <li> <p> <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> - process only the records within the last 50 bytes of the file.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTScanRange scanRange;

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
    Aws::S3Crt::Model::SelectObjectContentRequest toAWS() const {
        Aws::S3Crt::Model::SelectObjectContentRequest awsSelectObjectContentRequest;

        if (!(this->bucket.IsEmpty())) {
            awsSelectObjectContentRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsSelectObjectContentRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->sSECustomerAlgorithm.IsEmpty())) {
            awsSelectObjectContentRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->sSECustomerAlgorithm));
        }

        if (!(this->sSECustomerKey.IsEmpty())) {
            awsSelectObjectContentRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->sSECustomerKey));
        }

        if (!(this->sSECustomerKeyMD5.IsEmpty())) {
            awsSelectObjectContentRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->sSECustomerKeyMD5));
        }

        if (!(this->expression.IsEmpty())) {
            awsSelectObjectContentRequest.SetExpression(TCHAR_TO_UTF8(*this->expression));
        }

        switch(this->expressionType) {
            case EAWSS3CRTExpressionType::SQL:
                awsSelectObjectContentRequest.SetExpressionType(Aws::S3Crt::Model::ExpressionType::SQL);
                break;
            default:
                break;
        }

        if (!(this->requestProgress.IsEmpty())) {
            awsSelectObjectContentRequest.SetRequestProgress(this->requestProgress.toAWS());
        }

        if (!(this->inputSerialization.IsEmpty())) {
            awsSelectObjectContentRequest.SetInputSerialization(this->inputSerialization.toAWS());
        }

        if (!(this->outputSerialization.IsEmpty())) {
            awsSelectObjectContentRequest.SetOutputSerialization(this->outputSerialization.toAWS());
        }

        if (!(this->scanRange.IsEmpty())) {
            awsSelectObjectContentRequest.SetScanRange(this->scanRange.toAWS());
        }

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsSelectObjectContentRequest.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        for (const TPair<FString, FString>& elem : this->customizedAccessLogTag) {
            awsSelectObjectContentRequest.AddCustomizedAccessLogTag(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsSelectObjectContentRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->sSECustomerAlgorithm.IsEmpty() && this->sSECustomerKey.IsEmpty() && this->sSECustomerKeyMD5.IsEmpty() && this->expression.IsEmpty() && this->expressionType == EAWSS3CRTExpressionType::NOT_SET && this->requestProgress.IsEmpty() && this->inputSerialization.IsEmpty() && this->outputSerialization.IsEmpty() && this->scanRange.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0;
    }
#endif
};
