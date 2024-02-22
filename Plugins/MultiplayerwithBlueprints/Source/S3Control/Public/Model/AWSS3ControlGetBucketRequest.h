/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetBucketRequest.h"

#endif

#include "AWSS3ControlGetBucketRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetBucketRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID of the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>Specifies the bucket.</p> <p>For using this parameter with Amazon S3 on Outposts with the REST API, you must specify the name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3 on Outposts with the AWS SDK and CLI, you must specify the ARN of the bucket accessed in the format <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>. For example, to access the bucket <code>reports</code> through outpost <code>my-outpost</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>. The value must be URL encoded. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetBucketRequest toAWS() const {
        Aws::S3Control::Model::GetBucketRequest awsGetBucketRequest;

        if (!(this->accountId.IsEmpty())) {
            awsGetBucketRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->bucket.IsEmpty())) {
            awsGetBucketRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        return awsGetBucketRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->bucket.IsEmpty();
    }
#endif
};
