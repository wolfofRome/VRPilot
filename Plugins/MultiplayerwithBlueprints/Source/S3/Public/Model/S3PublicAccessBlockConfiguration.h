/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/PublicAccessBlockConfiguration.h"

#endif

#include "S3PublicAccessBlockConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FS3PublicAccessBlockConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies whether Amazon S3 should block public access control lists (ACLs) for this bucket and objects in this bucket. Setting this element to <code>TRUE</code> causes the following behavior:</p> <ul> <li> <p>PUT Bucket acl and PUT Object acl calls fail if the specified ACL is public.</p> </li> <li> <p>PUT Object calls fail if the request includes a public ACL.</p> </li> <li> <p>PUT Bucket calls fail if the request includes a public ACL.</p> </li> </ul> <p>Enabling this setting doesn't affect existing policies or ACLs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool blockPublicAcls = false;

    /**
    *  <p>Specifies whether Amazon S3 should ignore public ACLs for this bucket and objects in this bucket. Setting this element to <code>TRUE</code> causes Amazon S3 to ignore all public ACLs on this bucket and objects in this bucket.</p> <p>Enabling this setting doesn't affect the persistence of any existing ACLs and doesn't prevent new public ACLs from being set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool ignorePublicAcls = false;

    /**
    *  <p>Specifies whether Amazon S3 should block public bucket policies for this bucket. Setting this element to <code>TRUE</code> causes Amazon S3 to reject calls to PUT Bucket policy if the specified bucket policy allows public access. </p> <p>Enabling this setting doesn't affect existing bucket policies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool blockPublicPolicy = false;

    /**
    *  <p>Specifies whether Amazon S3 should restrict public bucket policies for this bucket. Setting this element to <code>TRUE</code> restricts access to this bucket to only AWS services and authorized users within this account if the bucket has a public policy.</p> <p>Enabling this setting doesn't affect previously stored bucket policies, except that public and cross-account access within any public bucket policy, including non-public delegation to specific accounts, is blocked.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool restrictPublicBuckets = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::PublicAccessBlockConfiguration toAWS() const {
        Aws::S3::Model::PublicAccessBlockConfiguration awsPublicAccessBlockConfiguration;

        if (!(false)) {
            awsPublicAccessBlockConfiguration.SetBlockPublicAcls(this->blockPublicAcls);
        }

        if (!(false)) {
            awsPublicAccessBlockConfiguration.SetIgnorePublicAcls(this->ignorePublicAcls);
        }

        if (!(false)) {
            awsPublicAccessBlockConfiguration.SetBlockPublicPolicy(this->blockPublicPolicy);
        }

        if (!(false)) {
            awsPublicAccessBlockConfiguration.SetRestrictPublicBuckets(this->restrictPublicBuckets);
        }

        return awsPublicAccessBlockConfiguration;
    }

    bool IsEmpty() const {
        return false && false && false && false;
    }

    FS3PublicAccessBlockConfiguration &fromAWS(const Aws::S3::Model::PublicAccessBlockConfiguration &awsPublicAccessBlockConfiguration) {
        this->blockPublicAcls = awsPublicAccessBlockConfiguration.GetBlockPublicAcls();

        this->ignorePublicAcls = awsPublicAccessBlockConfiguration.GetIgnorePublicAcls();

        this->blockPublicPolicy = awsPublicAccessBlockConfiguration.GetBlockPublicPolicy();

        this->restrictPublicBuckets = awsPublicAccessBlockConfiguration.GetRestrictPublicBuckets();

        return *this;
    }
#endif
};
