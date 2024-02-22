/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateAccessPointRequest.h"

#endif

#include "Model/VpcConfiguration.h"
#include "Model/S3ControlPublicAccessBlockConfiguration.h"

#include "CreateAccessPointRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateAccessPointRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the account that owns the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name you want to assign to this access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>The name of the bucket that you want to associate this access point with.</p> <p>For using this parameter with Amazon S3 on Outposts with the REST API, you must specify the name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3 on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN of the bucket accessed in the format <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>. For example, to access the bucket <code>reports</code> through outpost <code>my-outpost</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>. The value must be URL encoded. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>If you include this field, Amazon S3 restricts access to this access point to requests from the specified virtual private cloud (VPC).</p>  <p>This is required for creating an access point for Amazon S3 on Outposts buckets.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FVpcConfiguration vpcConfiguration;

    /**
    *  <p> The <code>PublicAccessBlock</code> configuration that you want to apply to the access point. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlockConfiguration;

    /**
    *  <p>The Amazon Web Services account ID associated with the S3 bucket associated with this access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucketAccountId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateAccessPointRequest toAWS() const {
        Aws::S3Control::Model::CreateAccessPointRequest awsCreateAccessPointRequest;

		if (!(this->accountId.IsEmpty())) {
            awsCreateAccessPointRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsCreateAccessPointRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

		if (!(this->bucket.IsEmpty())) {
            awsCreateAccessPointRequest.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->vpcConfiguration.IsEmpty())) {
            awsCreateAccessPointRequest.SetVpcConfiguration(this->vpcConfiguration.toAWS());
        }

        if (!(this->publicAccessBlockConfiguration.IsEmpty())) {
            awsCreateAccessPointRequest.SetPublicAccessBlockConfiguration(this->publicAccessBlockConfiguration.toAWS());
        }

		if (!(this->bucketAccountId.IsEmpty())) {
            awsCreateAccessPointRequest.SetBucketAccountId(TCHAR_TO_UTF8(*this->bucketAccountId));
        }

        return awsCreateAccessPointRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty() && this->bucket.IsEmpty() && this->vpcConfiguration.IsEmpty() && this->publicAccessBlockConfiguration.IsEmpty() && this->bucketAccountId.IsEmpty();
    }
#endif
};
