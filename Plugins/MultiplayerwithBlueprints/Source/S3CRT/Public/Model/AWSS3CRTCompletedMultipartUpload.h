/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CompletedMultipartUpload.h"

#endif

#include "Model/AWSS3CRTCompletedPart.h"

#include "AWSS3CRTCompletedMultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCompletedMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Array of CompletedPart data types.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTCompletedPart> parts;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CompletedMultipartUpload toAWS() const {
        Aws::S3Crt::Model::CompletedMultipartUpload awsCompletedMultipartUpload;

        for (const FAWSS3CRTCompletedPart& elem : this->parts) {
            awsCompletedMultipartUpload.AddParts(elem.toAWS());
        }

        return awsCompletedMultipartUpload;
    }

    bool IsEmpty() const {
        return this->parts.Num() == 0;
    }
#endif
};
