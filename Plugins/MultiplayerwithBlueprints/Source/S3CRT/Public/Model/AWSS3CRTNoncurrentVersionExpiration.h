/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/NoncurrentVersionExpiration.h"

#endif

#include "AWSS3CRTNoncurrentVersionExpiration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTNoncurrentVersionExpiration {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days an object is noncurrent before Amazon S3 can perform the associated action. For information about the noncurrent days calculations, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How Amazon S3 Calculates When an Object Became Noncurrent</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int noncurrentDays = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::NoncurrentVersionExpiration toAWS() const {
        Aws::S3Crt::Model::NoncurrentVersionExpiration awsNoncurrentVersionExpiration;

        if (!(this->noncurrentDays == 0)) {
            awsNoncurrentVersionExpiration.SetNoncurrentDays(this->noncurrentDays);
        }

        return awsNoncurrentVersionExpiration;
    }

    bool IsEmpty() const {
        return this->noncurrentDays == 0;
    }

    FAWSS3CRTNoncurrentVersionExpiration &fromAWS(const Aws::S3Crt::Model::NoncurrentVersionExpiration &awsNoncurrentVersionExpiration) {
		this->noncurrentDays = awsNoncurrentVersionExpiration.GetNoncurrentDays();

        return *this;
    }
#endif
};
