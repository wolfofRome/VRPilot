/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ServerSideEncryptionRule.h"

#endif

#include "Model/AWSS3CRTServerSideEncryptionByDefault.h"

#include "AWSS3CRTServerSideEncryptionRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTServerSideEncryptionRule {
GENERATED_BODY()

    /**
    *  <p>Specifies the default server-side encryption to apply to new objects in the bucket. If a PUT Object request doesn't specify any server-side encryption, this default encryption will be applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTServerSideEncryptionByDefault applyServerSideEncryptionByDefault;

    /**
    *  <p>Specifies whether Amazon S3 should use an S3 Bucket Key with server-side encryption using KMS (SSE-KMS) for new objects in the bucket. Existing objects are not affected. Setting the <code>BucketKeyEnabled</code> element to <code>true</code> causes Amazon S3 to use an S3 Bucket Key. By default, S3 Bucket Key is not enabled.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/bucket-key.html">Amazon S3 Bucket Keys</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool bucketKeyEnabled = false;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ServerSideEncryptionRule toAWS() const {
        Aws::S3Crt::Model::ServerSideEncryptionRule awsServerSideEncryptionRule;

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

    FAWSS3CRTServerSideEncryptionRule &fromAWS(const Aws::S3Crt::Model::ServerSideEncryptionRule &awsServerSideEncryptionRule) {
        this->applyServerSideEncryptionByDefault = FAWSS3CRTServerSideEncryptionByDefault().fromAWS(awsServerSideEncryptionRule.GetApplyServerSideEncryptionByDefault());

        this->bucketKeyEnabled = awsServerSideEncryptionRule.GetBucketKeyEnabled();

        return *this;
    }
#endif
};
