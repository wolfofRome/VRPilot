/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AbortIncompleteMultipartUpload.h"

#endif

#include "AWSS3ControlAbortIncompleteMultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlAbortIncompleteMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days after which Amazon S3 aborts an incomplete multipart upload to the Outposts bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int daysAfterInitiation = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::AbortIncompleteMultipartUpload toAWS() const {
        Aws::S3Control::Model::AbortIncompleteMultipartUpload awsAbortIncompleteMultipartUpload;

        if (!(this->daysAfterInitiation == 0)) {
            awsAbortIncompleteMultipartUpload.SetDaysAfterInitiation(this->daysAfterInitiation);
        }

        return awsAbortIncompleteMultipartUpload;
    }

    bool IsEmpty() const {
        return this->daysAfterInitiation == 0;
    }

    FAWSS3ControlAbortIncompleteMultipartUpload &fromAWS(const Aws::S3Control::Model::AbortIncompleteMultipartUpload &awsAbortIncompleteMultipartUpload) {
		this->daysAfterInitiation = awsAbortIncompleteMultipartUpload.GetDaysAfterInitiation();

        return *this;
    }
#endif
};
