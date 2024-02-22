/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/NoncurrentVersionExpiration.h"

#endif

#include "NoncurrentVersionExpiration.generated.h"

USTRUCT(BlueprintType)
struct FNoncurrentVersionExpiration {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days an object is noncurrent before Amazon S3 can perform the associated action. For information about the noncurrent days calculations, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How Amazon S3 Calculates When an Object Became Noncurrent</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int noncurrentDays = 0;

    /**
    *  <p>Specifies how many noncurrent versions Amazon S3 will retain. If there are this many more recent noncurrent versions, Amazon S3 will take the associated action. For more information about noncurrent versions, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intro-lifecycle-rules.html">Lifecycle configuration elements</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int newerNoncurrentVersions = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::NoncurrentVersionExpiration toAWS() const {
        Aws::S3::Model::NoncurrentVersionExpiration awsNoncurrentVersionExpiration;

        if (!(this->noncurrentDays == 0)) {
            awsNoncurrentVersionExpiration.SetNoncurrentDays(this->noncurrentDays);
        }

        if (!(this->newerNoncurrentVersions == 0)) {
            awsNoncurrentVersionExpiration.SetNewerNoncurrentVersions(this->newerNoncurrentVersions);
        }

        return awsNoncurrentVersionExpiration;
    }

    bool IsEmpty() const {
        return this->noncurrentDays == 0 && this->newerNoncurrentVersions == 0;
    }

    FNoncurrentVersionExpiration &fromAWS(const Aws::S3::Model::NoncurrentVersionExpiration &awsNoncurrentVersionExpiration) {
		this->noncurrentDays = awsNoncurrentVersionExpiration.GetNoncurrentDays();

		this->newerNoncurrentVersions = awsNoncurrentVersionExpiration.GetNewerNoncurrentVersions();

        return *this;
    }
#endif
};
