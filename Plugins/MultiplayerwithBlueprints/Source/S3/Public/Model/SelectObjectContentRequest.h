/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/SelectObjectContentRequest.h"

#endif

#include "Model/ExpressionType.h"
#include "Model/RequestProgress.h"
#include "Model/InputSerialization.h"
#include "Model/OutputSerialization.h"
#include "Model/ScanRange.h"
#include "Model/SelectObjectContentHandler.h"

#include "SelectObjectContentRequest.generated.h"

USTRUCT(BlueprintType)
struct FSelectObjectContentRequest {
GENERATED_BODY()

    /**
    *  <p>The S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString bucket;

    /**
    *  <p>The object key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString key;

    /**
    *  <p>The SSE Algorithm used to encrypt the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ServerSideEncryptionCustomerKeys.html">Server-Side Encryption (Using Customer-Provided Encryption Keys</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerAlgorithm;

    /**
    *  <p>The SSE Customer Key. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ServerSideEncryptionCustomerKeys.html">Server-Side Encryption (Using Customer-Provided Encryption Keys</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKey;

    /**
    *  <p>The SSE Customer Key MD5. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ServerSideEncryptionCustomerKeys.html">Server-Side Encryption (Using Customer-Provided Encryption Keys</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString SSECustomerKeyMD5;

    /**
    *  <p>The expression that is used to query the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expression;

    /**
    *  <p>The type of the provided expression (for example, SQL).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSExpressionType expressionType = EAWSExpressionType::NOT_SET;

    /**
    *  <p>Specifies if periodic request progress information should be enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FRequestProgress requestProgress;

    /**
    *  <p>Describes the format of the data in the object that is being queried.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInputSerialization inputSerialization;

    /**
    *  <p>Describes the format of the data that you want Amazon S3 to return in response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOutputSerialization outputSerialization;

    /**
    *  <p>Specifies the byte range of the object to get the records from. A record is processed when its first byte is contained by the range. This parameter is optional, but when specified, it must not be empty. See RFC 2616, Section 14.35.1 about how to specify the start and end of the range.</p> <p> <code>ScanRange</code>may be used in the following ways:</p> <ul> <li> <p> <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;end&gt;100&lt;/end&gt;&lt;/scanrange&gt;</code> - process only the records starting between the bytes 50 and 100 (inclusive, counting from zero)</p> </li> <li> <p> <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code> - process only the records starting after the byte 50</p> </li> <li> <p> <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> - process only the records within the last 50 bytes of the file.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FScanRange scanRange;

    /**
    *  <p>The account ID of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expectedBucketOwner;

    /**
    * Underlying Event Stream Decoder.
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TMap<FString, FString> customizedAccessLogTag;

    /**
    * Underlying Event Stream Handler which is used to define callback functions.
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    USelectObjectContentHandler* handler = nullptr;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::SelectObjectContentRequest toAWS() {
        Aws::S3::Model::SelectObjectContentRequest awsSelectObjectContentRequest;

		if (!(this->bucket.IsEmpty())) {
            awsSelectObjectContentRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

		if (!(this->key.IsEmpty())) {
            awsSelectObjectContentRequest.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		if (!(this->SSECustomerAlgorithm.IsEmpty())) {
            awsSelectObjectContentRequest.SetSSECustomerAlgorithm(TCHAR_TO_UTF8(*this->SSECustomerAlgorithm));
        }

		if (!(this->SSECustomerKey.IsEmpty())) {
            awsSelectObjectContentRequest.SetSSECustomerKey(TCHAR_TO_UTF8(*this->SSECustomerKey));
        }

		if (!(this->SSECustomerKeyMD5.IsEmpty())) {
            awsSelectObjectContentRequest.SetSSECustomerKeyMD5(TCHAR_TO_UTF8(*this->SSECustomerKeyMD5));
        }

		if (!(this->expression.IsEmpty())) {
            awsSelectObjectContentRequest.SetExpression(TCHAR_TO_UTF8(*this->expression));
        }

        switch(this->expressionType) {
            case EAWSExpressionType::SQL:
                awsSelectObjectContentRequest.SetExpressionType(Aws::S3::Model::ExpressionType::SQL);
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

        if (this->handler != nullptr) {
            awsSelectObjectContentRequest.SetEventStreamHandler(this->handler->toAWS());
        }

        return awsSelectObjectContentRequest;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->SSECustomerAlgorithm.IsEmpty() && this->SSECustomerKey.IsEmpty() && this->SSECustomerKeyMD5.IsEmpty() && this->expression.IsEmpty() && expressionType == EAWSExpressionType::NOT_SET && this->requestProgress.IsEmpty() && this->inputSerialization.IsEmpty() && this->outputSerialization.IsEmpty() && this->scanRange.IsEmpty() && this->expectedBucketOwner.IsEmpty() && this->customizedAccessLogTag.Num() == 0 && this->handler == nullptr;
    }
#endif
};
