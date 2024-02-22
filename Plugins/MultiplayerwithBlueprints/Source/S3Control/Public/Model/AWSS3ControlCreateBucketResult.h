/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateBucketResult.h"

#endif

#include "AWSS3ControlCreateBucketResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateBucketResult {
GENERATED_BODY()

    /**
    *  <p>The location of the bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString location;

    /**
    *  <p>The Amazon Resource Name (ARN) of the bucket.</p> <p>For using this parameter with Amazon S3 on Outposts with the REST API, you must specify the name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3 on Outposts with the AWS SDK and CLI, you must specify the ARN of the bucket accessed in the format <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>. For example, to access the bucket <code>reports</code> through outpost <code>my-outpost</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>. The value must be URL encoded. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucketArn;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlCreateBucketResult &fromAWS(const Aws::S3Control::Model::CreateBucketResult &awsCreateBucketResult) {
        this->location = UTF8_TO_TCHAR(awsCreateBucketResult.GetLocation().c_str());

        this->bucketArn = UTF8_TO_TCHAR(awsCreateBucketResult.GetBucketArn().c_str());

        return *this;
    }
#endif
};
