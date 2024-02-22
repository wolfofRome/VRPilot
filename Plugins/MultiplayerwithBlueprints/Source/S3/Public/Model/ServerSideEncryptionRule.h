/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ServerSideEncryptionRule.h"

#endif

#include "Model/ServerSideEncryptionByDefault.h"

#include "ServerSideEncryptionRule.generated.h"

USTRUCT(BlueprintType)
struct FServerSideEncryptionRule {
GENERATED_BODY()

    /**
    *  <p>Specifies the default server-side encryption to apply to new objects in the bucket. If a PUT Object request doesn't specify any server-side encryption, this default encryption will be applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FServerSideEncryptionByDefault applyServerSideEncryptionByDefault;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key with server-side encryption using KMS (SSE-KMS) for new objects in the bucket. Existing objects are not affected. Setting the <code>BucketKeyEnabled</code> element to <code>true</code> causes Amazon S3 to use an S3 Bucket Key. By default, S3 Bucket Key is not enabled.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/bucket-key.html">Amazon S3 Bucket Keys</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool bucketKeyEnabled = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ServerSideEncryptionRule toAWS() const {
        Aws::S3::Model::ServerSideEncryptionRule awsServerSideEncryptionRule;

        if (!(this->applyServerSideEncryptionByDefault.IsEmpty())) {
            awsServerSideEncryptionRule.SetApplyServerSideEncryptionByDefault(this->applyServerSideEncryptionByDefault.toAWS());
        }
        if (!(false)) {
            awsServerSideEncryptionRule.SetBucketKeyEnabled(this->bucketKeyEnabled);
        }

        return awsServerSideEncryptionRule;
    }

    bool IsEmpty() const {
        return this->applyServerSideEncryptionByDefault.IsEmpty() && false;
    }

    FServerSideEncryptionRule &fromAWS(const Aws::S3::Model::ServerSideEncryptionRule &awsServerSideEncryptionRule) {
        this->applyServerSideEncryptionByDefault.fromAWS(awsServerSideEncryptionRule.GetApplyServerSideEncryptionByDefault());

        this->bucketKeyEnabled = awsServerSideEncryptionRule.GetBucketKeyEnabled();

        return *this;
    }
#endif
};
