/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AbortIncompleteMultipartUpload.h"

#endif

#include "AWSS3CRTAbortIncompleteMultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAbortIncompleteMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days after which Amazon S3 aborts an incomplete multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int daysAfterInitiation = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AbortIncompleteMultipartUpload toAWS() const {
        Aws::S3Crt::Model::AbortIncompleteMultipartUpload awsAbortIncompleteMultipartUpload;

        if (!(this->daysAfterInitiation == 0)) {
            awsAbortIncompleteMultipartUpload.SetDaysAfterInitiation(this->daysAfterInitiation);
        }

        return awsAbortIncompleteMultipartUpload;
    }

    bool IsEmpty() const {
        return this->daysAfterInitiation == 0;
    }

    FAWSS3CRTAbortIncompleteMultipartUpload &fromAWS(const Aws::S3Crt::Model::AbortIncompleteMultipartUpload &awsAbortIncompleteMultipartUpload) {
		this->daysAfterInitiation = awsAbortIncompleteMultipartUpload.GetDaysAfterInitiation();

        return *this;
    }
#endif
};
