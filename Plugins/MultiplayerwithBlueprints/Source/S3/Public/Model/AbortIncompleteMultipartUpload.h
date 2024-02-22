/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AbortIncompleteMultipartUpload.h"

#endif

#include "AbortIncompleteMultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FAbortIncompleteMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days after which Amazon S3 aborts an incomplete multipart upload.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int daysAfterInitiation = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AbortIncompleteMultipartUpload toAWS() const {
        Aws::S3::Model::AbortIncompleteMultipartUpload awsAbortIncompleteMultipartUpload;

        if (!(this->daysAfterInitiation == 0)) {
            awsAbortIncompleteMultipartUpload.SetDaysAfterInitiation(this->daysAfterInitiation);
        }

        return awsAbortIncompleteMultipartUpload;
    }

    bool IsEmpty() const {
        return this->daysAfterInitiation == 0;
    }

    FAbortIncompleteMultipartUpload &fromAWS(const Aws::S3::Model::AbortIncompleteMultipartUpload &awsAbortIncompleteMultipartUpload) {
		this->daysAfterInitiation = awsAbortIncompleteMultipartUpload.GetDaysAfterInitiation();

        return *this;
    }
#endif
};
